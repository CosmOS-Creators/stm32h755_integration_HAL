/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CILmutex.c
*********************************************************************************
<!--                   CILmutex Unit Local Group Definition                   -->
*********************************************************************************
** @defgroup Local_CILmutex Local
** @ingroup CILmutex_unit
** @brief CILmutex locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CIL interfaces */
#include "CILmutex.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_CILmutex
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
  * @defgroup Variables_CILmutex Variables
  * @ingroup Local_CILmutex
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_CILmutex
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
  * @defgroup Apis_CILmutex_c API's
  * @ingroup Local_CILmutex
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_CILmutex_c Getters
  * @ingroup Apis_CILmutex_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_CILmutex_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_CILmutex_c Setters
  * @ingroup Apis_CILmutex_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_CILmutex_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_CILmutex_c General
  * @ingroup Apis_CILmutex_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_CILmutex_c
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
  * @fn CILmutex_tryMutex(AddressType * mutexPointer)
  *
  * @details The implementation contains disabling interrupts before any other
  * instructions are executed. Then the value 1 is loaded to the register R1.
  * The R0 register as it has argument 1 role in the procedure call standard
  * holds address of the mutex and the value from this address is then loaded to
  * the R3 register to compare it with value 0. If the mutex is free (value in
  * its address is 0) the value 1 is stored to the mutex address and state
  * MUTEX_STATE_ENUM__SUCCESSFULLY_LOCKED to the register R1, otherwise the
  * state stored to R1 is MUTEX_STATE_ENUM__OCCUPIED. The mutexState is then
  * loaded with the R1 value. After this point interrupts are enabled again and
  * the mutexState is returned from the function.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_MutexStateType
CILmutex_tryMutex( AddressType * mutexPointer )
{
    CosmOS_MutexStateType mutexState;

    __asm volatile( "cpsid i" : : : "memory" );
    __asm volatile( "MOV R1, #0x1" );
    __asm volatile( "LDR R3, [R0]" );
    __asm volatile( "CMP R3, #0" );
    __asm volatile( "ITTE EQ" );
    __asm volatile( "STREQ R1, [R0]" );
    __asm volatile( "MOVEQ R1, #0x2" );
    __asm volatile( "MOVNE R1, #0x1" );
    __asm volatile( "MOV %[value], R1" : [value] "=r"( mutexState ) );
    __asm volatile( "cpsie i" : : : "memory" );

    /* THIS CODE CAN BE USED IF THE GLOBAL MONITOR IS IMPLEMENTED */
    //__asm volatile("MOV R1, #0x1");
    //__asm volatile("LDREXH R3, [R0]");
    //__asm volatile("CMP R3, #0");
    //__asm volatile("ITT EQ");
    //__asm volatile("STREXHEQ R3, R1, [R0]");
    //__asm volatile("CMPEQ R3, #0");
    //__asm volatile("ITE NE");
    //__asm volatile("MOVNE R1, #0x1");
    //__asm volatile("MOVEQ R1, #0x2");
    //__asm volatile("MOV %[value], R1":  [value] "=r" (mutexState) );

    __SUPRESS_UNUSED_VAR( mutexPointer );
    return mutexState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILmutex_releaseMutex(AddressType * mutexPointer)
  *
  * @details The implementation contains disabling interrupts before any other
  * instructions are executed. Then the value 0 is loaded to the register R1.
  * The R0 register as it has argument 1 role in the procedure call standard
  * holds address of the mutex. The R1 value is then stored to the mutex address.
  * The mutexState is then loaded with the R1 value. After this point interrupts
  * are enabled again and the mutexState is returned from the function.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_MutexStateType
CILmutex_releaseMutex( AddressType * mutexPointer )
{
    CosmOS_MutexStateType mutexState;

    __asm volatile( "cpsid i" : : : "memory" );
    __asm volatile( "MOV R1, #0x0" );
    __asm volatile( "STR R1, [R0]" );
    __asm volatile( "MOV %[value], R1" : [value] "=r"( mutexState ) );
    __asm volatile( "cpsie i" : : : "memory" );

    /* THIS CODE CAN BE USED IF THE GLOBAL MONITOR IS IMPLEMENTED */
    //__asm volatile("MOV R1, #0x0");
    //__asm volatile("tryUnlock:");
    //__asm volatile("LDREXH R3, [R0]");
    //__asm volatile("CMP R3, #1");
    //__asm volatile("ITTE EQ");
    //__asm volatile("STREXHEQ R3, R1, [R0]");
    //__asm volatile("CMPEQ R3, #0");
    //__asm volatile("BNE released");
    //__asm volatile("IT NE");
    //__asm volatile("BNE tryUnlock");
    //__asm volatile("released:");
    //__asm volatile("MOV %[value], R1":  [value] "=r" (mutexState) );

    __SUPRESS_UNUSED_VAR( mutexPointer );
    return mutexState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
