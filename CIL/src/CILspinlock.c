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
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Macros_CILspinlock
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
  * @}
  * Variables_CILspinlock
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
  * @}
  * Getters_CILspinlock_c
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
  * @}
  * Setters_CILspinlock_c
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
  * @}
  * General_CILspinlock_c
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn CILspinlock_getSpinlock(AddressType * spinlockPointer)
  *
  * @brief Get spinlock DEMO CODE.
  *
  * @param[in]  AddressType * spinlockPointer
  *
  * @return CosmOS_SpinlockStateType
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SpinlockStateType CILspinlock_getSpinlock(AddressType * spinlockPointer)
{
    CosmOS_SpinlockStateType spinlockState;

	__asm volatile("MOV R1, #0x1");
    __asm volatile("tryLock:");
	__asm volatile("LDREXH R3, [R0]");
	__asm volatile("CMP R3, #0");
	__asm volatile("ITT EQ");
	__asm volatile("STREXHEQ R3, R1, [R0]");
	__asm volatile("CMPEQ R3, #0");
	__asm volatile("ITE EQ");
	__asm volatile("MOVEQ R1, #0x2");
	__asm volatile("BNE tryLock");
    __asm volatile("MOV %[value], R1":  [value] "=r" (spinlockState) );

    return spinlockState;
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn CILspinlock_trySpinlock(AddressType * spinlockPointer)
  *
  * @brief Try to get spinlock DEMO CODE.
  *
  * @param[in]  BitWidthType id
  *
  * @return CosmOS_SpinlockStateType
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SpinlockStateType CILspinlock_trySpinlock(AddressType * spinlockPointer)
{
    CosmOS_SpinlockStateType spinlockState;

	__asm volatile("MOV R1, #0x1");
	__asm volatile("LDREXH R3, [R0]");
	__asm volatile("CMP R3, #0");
	__asm volatile("ITT EQ");
	__asm volatile("STREXHEQ R3, R1, [R0]");
	__asm volatile("CMPEQ R3, #0");
	__asm volatile("ITE NE");
	__asm volatile("MOVNE R1, #0x1");
	__asm volatile("MOVEQ R1, #0x2");
	__asm volatile("MOV %[value], R1":  [value] "=r" (spinlockState) );

    return spinlockState;
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn CILspinlock_releaseSpinlock(AddressType * spinlockPointer)
  *
  * @brief Release spinlock DEMO CODE.
  *
  * @param[in]  AddressType * spinlockPointer
  *
  * @return CosmOS_SpinlockStateType
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION CosmOS_SpinlockStateType CILspinlock_releaseSpinlock(AddressType * spinlockPointer)
{
    CosmOS_SpinlockStateType spinlockState;

	__asm volatile("MOV R1, #0x0");
    __asm volatile("tryUnlock:");
	__asm volatile("LDREXH R3, [R0]");
	__asm volatile("CMP R3, #1");
	__asm volatile("ITT EQ");
	__asm volatile("STREXHEQ R3, R1, [R0]");
	__asm volatile("CMPEQ R3, #0");
	__asm volatile("IT NE");
	__asm volatile("BNE tryUnlock");
    __asm volatile("MOV %[value], R1":  [value] "=r" (spinlockState) );

    return spinlockState;
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
