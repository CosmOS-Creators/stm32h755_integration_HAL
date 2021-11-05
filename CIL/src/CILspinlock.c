/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CILspinlock.c
*********************************************************************************
<!--                  CILspinlock Unit Local Group Definition                 -->
*********************************************************************************
** @defgroup Local_CILspinlock Local
** @ingroup CILspinlock_unit
** @brief CILspinlock locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CIL interfaces */
#include "CILspinlock.h"

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
  * @defgroup Macros_CILspinlock Macros
  * @ingroup Local_CILspinlock
  * @{
********************************************************************************/
#if USE_MULTI_CORE_SHARED_CODE IS_EQUAL_TO 0U AND STM32H755xx
#error \
    "Please define USE_MULTI_CORE_SHARED_CODE to ensure correct compilation of HAL libraries"
#endif
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_CILspinlock
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
  * @defgroup Variables_CILspinlock Variables
  * @ingroup Local_CILspinlock
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_CILspinlock
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
  * @defgroup Apis_CILspinlock_c API's
  * @ingroup Local_CILspinlock
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_CILspinlock_c Getters
  * @ingroup Apis_CILspinlock_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_CILspinlock_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_CILspinlock_c Setters
  * @ingroup Apis_CILspinlock_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_CILspinlock_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_CILspinlock_c General
  * @ingroup Apis_CILspinlock_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_CILspinlock_c
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
  * @fn CILspinlock_getSpinlock(AddressType * spinlockPointer,
  * BitWidthType spinlockId,
  * BitWidthType schedulableId )
  *
  * @details The implementation contains do-while loop that calls function
  * HAL_HSEM_Take to take hardware semaphore based on the spinlock identifier
  * and schedulable unique identifier till hsemTakeStatus is not HAL_OK. Then
  * the value 1 is loaded to the spinlock address and spinlockState is set to the
  * SPINLOCK_STATE_ENUM__SUCCESSFULLY_LOCKED and returned from the function.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SpinlockStateType
CILspinlock_getSpinlock(
    AddressType * spinlockPointer,
    BitWidthType spinlockId,
    BitWidthType schedulableId )
{
    CosmOS_SpinlockStateType spinlockState;

    HAL_StatusTypeDef hsemTakeStatus;

    do
    {
        hsemTakeStatus = HAL_HSEM_Take( spinlockId, schedulableId );
    } while ( hsemTakeStatus IS_NOT_EQUAL_TO HAL_OK );

    *spinlockPointer = 1;
    spinlockState = SPINLOCK_STATE_ENUM__SUCCESSFULLY_LOCKED;

    /* THIS CODE CAN BE USED IF THE GLOBAL MONITOR IS IMPLEMENTED */
    //__asm volatile("MOV R1, #0x1");
    //__asm volatile("tryLock:");
    //__asm volatile("LDREXH R3, [R0]");
    //__asm volatile("CMP R3, #0");
    //__asm volatile("ITT EQ");
    //__asm volatile("STREXHEQ R3, R1, [R0]");
    //__asm volatile("CMPEQ R3, #0");
    //__asm volatile("ITE EQ");
    //__asm volatile("MOVEQ R1, #0x2");
    //__asm volatile("BNE tryLock");
    //__asm volatile("MOV %[value], R1":  [value] "=r" (spinlockState) );
    //__SUPRESS_UNUSED_VAR(spinlockPointer);

    return spinlockState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILspinlock_trySpinlock(AddressType * spinlockPointer,
  * BitWidthType spinlockId,
  * BitWidthType schedulableId )
  *
  * @details The implementation contains function HAL_HSEM_Take call intended
  * to take hardware semaphore based on the spinlock identifier
  * and schedulable unique identifier. If the hsemTakeStatus is equal to the
  * the value 1 is loaded to the spinlock address and spinlockState is set to the
  * SPINLOCK_STATE_ENUM__SUCCESSFULLY_LOCKED. Otherwise is spinlockState set to
  * the SPINLOCK_STATE_ENUM__OCCUPIED. In the end is the spinlockState returned
  * from the function.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SpinlockStateType
CILspinlock_trySpinlock(
    AddressType * spinlockPointer,
    BitWidthType spinlockId,
    BitWidthType schedulableId )
{
    CosmOS_SpinlockStateType spinlockState;

    HAL_StatusTypeDef hsemTakeStatus;

    hsemTakeStatus = HAL_HSEM_Take( spinlockId, schedulableId );
    if ( hsemTakeStatus IS_EQUAL_TO HAL_OK )
    {
        *spinlockPointer = 1;
        spinlockState = SPINLOCK_STATE_ENUM__SUCCESSFULLY_LOCKED;
    }
    else
    {
        __SUPRESS_UNUSED_VAR( spinlockPointer );
        spinlockState = SPINLOCK_STATE_ENUM__OCCUPIED;
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
    //__asm volatile("MOV %[value], R1":  [value] "=r" (spinlockState) );
    //__SUPRESS_UNUSED_VAR(spinlockPointer);

    return spinlockState;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILspinlock_releaseSpinlock(AddressType * spinlockPointer,
  * BitWidthType spinlockId,
  * BitWidthType schedulableId )
  *
  * @details The implementation contains function HAL_HSEM_Release call intended
  * to release hardware semaphore based on the spinlock identifier
  * and schedulable unique identifier. Then the value 0 is loaded to the spinlock
  * address and spinlockState is set to the  SPINLOCK_STATE_ENUM__RELEASED and
  * returned from the function.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SpinlockStateType
CILspinlock_releaseSpinlock(
    AddressType * spinlockPointer,
    BitWidthType spinlockId,
    BitWidthType schedulableId )
{
    CosmOS_SpinlockStateType spinlockState;

    HAL_HSEM_Release( spinlockId, schedulableId );

    *spinlockPointer = 0;
    spinlockState = SPINLOCK_STATE_ENUM__RELEASED;

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
    //__asm volatile("MOV %[value], R1":  [value] "=r" (spinlockState) );
    //__SUPRESS_UNUSED_VAR(spinlockPointer);

    return spinlockState;
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
