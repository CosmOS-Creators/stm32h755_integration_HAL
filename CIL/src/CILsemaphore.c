/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CILsemaphore.c
*********************************************************************************
<!--                  CILsemaphore Unit Local Group Definition                 -->
*********************************************************************************
** @defgroup Local_CILsemaphore Local
** @ingroup CILsemaphore_unit
** @brief CILsemaphore locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CIL interfaces */
#include "CILsemaphore.h"

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
  * @defgroup Macros_CILsemaphore Macros
  * @ingroup Local_CILsemaphore
  * @{
********************************************************************************/
#if USE_MULTI_CORE_SHARED_CODE IS_EQUAL_TO 0U AND STM32H755xx
#error \
    "Please define USE_MULTI_CORE_SHARED_CODE to ensure correct compilation of HAL libraries"
#endif

// #if SPINLOCK_NUM > 16
// #error \
//     "Please reduce number of spinlocks, the current hardware can only handle 16 spinlocks"
// #endif

// #if SCHEDULABLE_NUM > 256
// #error \
//     "Please reduce number of schedulables, the current hardware can only handle 256 schedulables"
// #endif

//SEMAPHORE_OFFSET divides the HSEM to two parts, one for spinlocks and one for the semaphores
#define SEMAPHORE_OFFSET (BitWidthType)16
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_CILsemaphore
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
  * @defgroup Variables_CILsemaphore Variables
  * @ingroup Local_CILsemaphore
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_CILsemaphore
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
  * @defgroup Apis_CILsemaphore_c API's
  * @ingroup Local_CILsemaphore
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_CILsemaphore_c Getters
  * @ingroup Apis_CILsemaphore_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_CILsemaphore_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_CILsemaphore_c Setters
  * @ingroup Apis_CILsemaphore_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_CILsemaphore_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_CILsemaphore_c General
  * @ingroup Apis_CILsemaphore_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_CILsemaphore_c
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
  * @fn CILsemaphore_trySemaphore(AddressType * semaphorePointer,
  * BitWidthType semaphoreId,
  * BitWidthType schedulableId )
  *
  * @details The implementation contains function HAL_HSEM_Take call intended
  * to take hardware semaphore based on the semaphore identifier
  * and schedulable unique identifier. If the hsemTakeStatus is equal to the
  * the value 1 is loaded to the semaphore address and semaphoreState is set to the
  * SEMAPHORE_STATE_ENUM__SUCCESSFULLY_LOCKED. Otherwise is semaphoreState set to
  * the SEMAPHORE_STATE_ENUM__OCCUPIED. In the end is the semaphoreState returned
  * from the function.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SemaphoreStateType
CILsemaphore_trySemaphore(
    AddressType * semaphorePointer,
    BitWidthType semaphoreId,
    BitWidthType schedulableId )
{
    CosmOS_SemaphoreStateType semaphoreState;

    HAL_StatusTypeDef hsemTakeStatus;

    hsemTakeStatus =
        HAL_HSEM_Take( semaphoreId + SEMAPHORE_OFFSET, schedulableId );
    if ( hsemTakeStatus IS_EQUAL_TO HAL_OK )
    {
        *semaphorePointer = 1;
        semaphoreState = SEMAPHORE_STATE_ENUM__SUCCESSFULLY_LOCKED;
    }
    else
    {
        __SUPRESS_UNUSED_VAR( semaphorePointer );
        semaphoreState = SEMAPHORE_STATE_ENUM__OCCUPIED;
    }

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
    //__asm volatile("MOV %[value], R1":  [value] "=r" (semaphoreState) );
    //__SUPRESS_UNUSED_VAR(semaphorePointer);

    return semaphoreState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILsemaphore_releaseSemaphore(AddressType * semaphorePointer,
  * BitWidthType semaphoreId,
  * BitWidthType schedulableId )
  *
  * @details The implementation contains function HAL_HSEM_Release call intended
  * to release hardware semaphore based on the semaphore identifier
  * and schedulable unique identifier. Then the value 0 is loaded to the semaphore
  * address and semaphoreState is set to the  SEMAPHORE_STATE_ENUM__RELEASED and
  * returned from the function.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SemaphoreStateType
CILsemaphore_releaseSemaphore(
    AddressType * semaphorePointer,
    BitWidthType semaphoreId,
    BitWidthType schedulableId )
{
    CosmOS_SemaphoreStateType semaphoreState;

    HAL_HSEM_Release( semaphoreId + SEMAPHORE_OFFSET, schedulableId );

    *semaphorePointer = 0;
    semaphoreState = SEMAPHORE_STATE_ENUM__RELEASED;

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
    //__asm volatile("MOV %[value], R1":  [value] "=r" (semaphoreState) );
    //__SUPRESS_UNUSED_VAR(semaphorePointer);

    return semaphoreState;
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
