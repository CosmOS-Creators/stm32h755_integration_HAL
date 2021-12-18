/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CILspinlock.h
*********************************************************************************
<!--                     CILspinlock Unit Group Definition                    -->
*********************************************************************************
** @defgroup CILspinlock_unit CILspinlock Unit
** @ingroup CIL_module
** @brief CILspinlock Unit
** @details lorem
*********************************************************************************
<!--                           Version Information                            -->
*********************************************************************************
** @version 1.0.0
** @date 1.8.2020
** @author https://github.com/PavolKostolansky
*********************************************************************************
<!--                          Warnings and License                            -->
*********************************************************************************
** @warning Modifying code can lead to unexpected behaviour of the whole system
** @copyright MIT License
*********************************************************************************
<!--                 CILspinlock Unit Global Group Definition                 -->
*********************************************************************************
** @defgroup Global_CILspinlock Global
** @ingroup CILspinlock_unit
** @brief CILspinlock globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __CILSPINLOCK_H__
#define __CILSPINLOCK_H__
/********************************************************************************
**                         START OF C++ SUPPORT SECTION                        **
********************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "memoryMapping.h"
#include "sysDefs.h"

/* CIL interfaces */
#include "CILstdTypes.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_CILspinlock_h Macros
  * @ingroup Global_CILspinlock
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_CILspinlock_h
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
  * @defgroup Variables_CILspinlock_h Variables
  * @ingroup Global_CILspinlock
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_CILspinlock_h
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
  * @defgroup Apis_CILspinlock_h API's
  * @ingroup Global_CILspinlock
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_CILspinlock_h Getters
  * @ingroup Apis_CILspinlock_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_CILspinlock_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_CILspinlock_h Setters
  * @ingroup Apis_CILspinlock_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_CILspinlock_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_CILspinlock_h General
  * @ingroup Apis_CILspinlock_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILspinlock_trySpinlock(AddressType * spinlockPointer,
  * BitWidthType spinlockId,
  * BitWidthType schedulableId )
  *
  * @brief Try to get spinlock. This function cannot
  * be called from the unprivileged context directly. DEMO
  *
  * @param[in]  spinlockPointer pointer to the spinlock variable that stores
  * spinlock value
  * @param[in]  spinlockId
  * @param[in]  schedulableId
  *
  * @return CosmOS_SpinlockStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_SpinlockStateType
CILspinlock_trySpinlock(
    AddressType * spinlockPointer,
    BitWidthType spinlockId,
    BitWidthType schedulableId );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILspinlock_releaseSpinlock(AddressType * spinlockPointer,
  * BitWidthType spinlockId,
  * BitWidthType schedulableId )
  *
  * @brief Release spinlock. This function cannot
  * be called from the unprivileged context directly. DEMO
  *
  * @param[in]  spinlockPointer pointer to the spinlock variable that stores
  * spinlock value
  * @param[in]  spinlockId
  * @param[in]  schedulableId
  *
  * @return CosmOS_SpinlockStateType
********************************************************************************/
__OS_FUNC_SECTION CosmOS_SpinlockStateType
CILspinlock_releaseSpinlock(
    AddressType * spinlockPointer,
    BitWidthType spinlockId,
    BitWidthType schedulableId );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_CILspinlock_h
********************************************************************************/
/********************************************************************************
**                         Function Prototypes | Stop                          **
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Start                         **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_CILspinlock_h Getters
  * @ingroup Apis_CILspinlock_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_CILspinlock_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_CILspinlock_h Setters
  * @ingroup Apis_CILspinlock_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_CILspinlock_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_CILspinlock_h General
  * @ingroup Apis_CILspinlock_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_CILspinlock_h
********************************************************************************/
/********************************************************************************
**                        Function Definitions | Stop                          **
********************************************************************************/
#ifdef __cplusplus
}
#endif
/********************************************************************************
**                         END OF C++ SUPPORT SECTION                          **
********************************************************************************/
#endif
/********************************************************************************
**                           END OF THE HEADER FILE                            **
********************************************************************************/
