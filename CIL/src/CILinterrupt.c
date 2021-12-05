/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CILinterrupt.c
*********************************************************************************
<!--                 CILinterrupt Unit Local Group Definition                 -->
*********************************************************************************
** @defgroup Local_CILinterrupt Local
** @ingroup CILinterrupt_unit
** @brief CILinterrupt locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "core.h"
#include "cosmosApiInternal.h"
#include "os.h"
#include "osEvent.h"
#include "scheduler.h"

/* CIL interfaces */
#include "CILcore.h"
#include "CILinterrupt.h"

/* HAL interfaces */
#include "stm32h7xx_hal.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_CILinterrupt_c Macros
  * @ingroup Local_CILinterrupt
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_CILinterrupt_c
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Stop                           **
********************************************************************************/
/********************************************************************************
**                              Variables | Start                              **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Variables_CILinterrupt_c Variables
  * @ingroup Local_CILinterrupt
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_CILinterrupt_c
********************************************************************************/
/********************************************************************************
**                              Variables | Stop                               **
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Start                         **
********************************************************************************/
/********************************************************************************
  * DOXYGEN DEF GROUP                                                          **
  * *************************************************************************//**
  * @defgroup Apis_CILinterrupt_c API's
  * @ingroup Local_CILinterrupt
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_CILinterrupt_c Getters
  * @ingroup Apis_CILinterrupt_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_CILinterrupt_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_CILinterrupt_c Setters
  * @ingroup Apis_CILinterrupt_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_CILinterrupt_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_CILinterrupt_c General
  * @ingroup Apis_CILinterrupt_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_CILinterrupt_c
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn PendSV_Handler(void)
  *
  * @details The implementation contains disabling interrupts before any other
  * instructions are executed. Then the process stack pointer is moved to the
  * R0 register as it has argument 1 role in the procedure call standard, which
  * is then later used inside the scheduler_scheduleNextInstance function. Then
  * the instance type is loaded from the core configuration stored in platform
  * register and checked if the current schedulable is task or thread. If it is
  * task the context save is skipped. Then the EXC_RETURN[4] bit is tested and
  * if it is set the Z flag is 0, this means that the FPU instruction was not
  * used during the task/thread execution as it is referenced in the
  * Cortex-M4(F) Lazy Stacking and Context Switching - Application Note 298
  * https://developer.arm.com/documentation/dai0298/a/.
  * If the FPU instruction was used the context of the FPU is saved. Then the
  * standard context registers are stored except the platform register R9. After
  * this point the scheduler_scheduleNextInstance is called to schedule next
  * schedulable and set the system timer. Instruction barrier is implemented
  * after the function call. Function itself returns in R0 register as it has
  * result 1 role in the procedure call standard next schedulable process stack
  * pointer. This value is then used to restore the standard context registers
  * except the platform register R9. Then the EXC_RETURN[4] bit is tested and if
  * it is set the Z flag is 0, this means that the FPU instruction was not used
  * during the task/thread execution as it is referenced in the Cortex-M4(F) Lazy
  * Stacking and Context Switching - Application Note 298
  * https://developer.arm.com/documentation/dai0298/a/. If the FPU instruction
  * was used the context of the FPU is restored. Then the PSP is set to the
  * value of the R0 register. After this point interrupts
  * are enabled again. In the end the scheduler reschedule state is set to
  * RESCHEDULE_TRIGGER_STATE_ENUM__SYSTEM andAnother instruction barrier is
  * implemented. After this point the branch and exchange instruction is called
  * based on the value of the R14 register.
********************************************************************************/
__NAKED void
PendSV_Handler( void )
{
    __asm volatile( "cpsid i" : : : "memory" );

    __asm volatile( "MRS R0,PSP" );
    __asm volatile( "ISB" );

    __asm volatile( "LDR R2, [R9]" );
    __asm volatile( "LDR R3, [R2]" );
    __asm volatile( "LDR R2, [R3, #8]" );
    __asm volatile( "TST R2, #1" );
    __asm volatile( "IT EQ" );
    __asm volatile( "BEQ skipSaveContext" );

    __asm volatile( "saveContext:" );
    __asm volatile( "TST R14, #16" );
    __asm volatile( "IT EQ" );
    __asm volatile( "VSTMDBEQ R0!,{S16-S31}" );
    __asm volatile( "STMDB R0!,{R4-R8,R10,R11,R14}" );

    __asm volatile( "skipSaveContext:" );
    __asm volatile( "BL scheduler_scheduleNextInstance" );
    __asm volatile( "ISB" );
    __asm volatile( "LDMIA R0!,{R4-R8,R10,R11,R14}" );

    __asm volatile( "TST R14, #16" );
    __asm volatile( "IT EQ" );
    __asm volatile( "VLDMIAEQ R0!,{S16-S31}" );
    __asm volatile( "MSR PSP,R0" );

    __asm volatile( "cpsie i" : : : "memory" );

    __asm volatile( "LDR R2, [R9, #12]" );
    __asm volatile( "LDR R3, [R2]" );
    __asm volatile( "MOV R2, #0" );
    __asm volatile( "STR R2, [R3]" );

    __asm volatile( "ISB" );
    __asm volatile( "BX R14" );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn SysTick_Handler(void)
  *
  * @details The implementation contains scheduler_timerISRCallback function
  * call.
********************************************************************************/
void
SysTick_Handler( void )
{
    scheduler_timerISRCallback();
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn SVC_Handler(void)
  *
  * @details The implementation contains testing of the EXC_RETURN[2] bit and if
  * it is set the Z flag is 0, this means the processor is currently in the
  * thread mode and the process stack pointer is stored into the R0 register,
  * otherwise the main stack pointer is stored to the R0 as it has argument 1
  * role in the procedure call standard. Then the CILsysCalls_dispatcher
  * function is called.
********************************************************************************/
__NAKED void
SVC_Handler( void )
{
    __asm volatile( "TST LR, #4" );
    __asm volatile( "ITE EQ" );
    __asm volatile( "MRSEQ R0, MSP" );
    __asm volatile( "MRSNE R0, PSP" );
    __asm volatile( "B CILsysCalls_dispatcher" );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CM7_SEV_IRQHandler(void)
  *
  * @details The implementation contains logic to check if the operating system
  * is already running on the specific core. If yes then the event dispatch
  * function can be called, otherwised there is no action.
********************************************************************************/
void
CM7_SEV_IRQHandler( void )
{
    BitWidthType coreId;
    CosmOS_OsStateType osState;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_CoreConfigurationType * coreCfg;

    CosmOS_BooleanType coreInPrivilegedMode;

    coreInPrivilegedMode = CILcore_isInPrivilegedMode();

    if ( coreInPrivilegedMode )
    {
        coreId = CILcore_getCoreId();
    }
    else
    {
        coreId = cosmosApiInternal_CILcore_getCoreId();
    }
    osCfg = os_getOsCfg();
    coreCfg = os_getCoreCfg( osCfg, coreId );
    osState = core_getCoreOsState( coreCfg );

    if ( osState IS_EQUAL_TO OS_STATE_ENUM__STARTED )
    {
        osEvent_dispatchEvent();
    }
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CM4_SEV_IRQHandler(void)
  *
  * @details The implementation contains logic to check if the operating system
  * is already running on the specific core. If yes then the event dispatch
  * function can be called, otherwised there is no action.
********************************************************************************/
void
CM4_SEV_IRQHandler( void )
{
    BitWidthType coreId;
    CosmOS_OsStateType osState;

    CosmOS_OsConfigurationType * osCfg;
    CosmOS_CoreConfigurationType * coreCfg;

    CosmOS_BooleanType coreInPrivilegedMode;

    coreInPrivilegedMode = CILcore_isInPrivilegedMode();

    if ( coreInPrivilegedMode )
    {
        coreId = CILcore_getCoreId();
    }
    else
    {
        coreId = cosmosApiInternal_CILcore_getCoreId();
    }
    osCfg = os_getOsCfg();
    coreCfg = os_getCoreCfg( osCfg, coreId );
    osState = core_getCoreOsState( coreCfg );

    if ( osState IS_EQUAL_TO OS_STATE_ENUM__STARTED )
    {
        osEvent_dispatchEvent();
    }
}
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
