/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CILmemoryProtection.h
*********************************************************************************
<!--                 CILmemoryProtection Unit Group Definition                -->
*********************************************************************************
** @defgroup CILmemoryProtection_unit CILmemoryProtection Unit
** @ingroup CIL_module
** @brief CILmemoryProtection Unit
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
<!--            CILmemoryProtection Unit Global Group Definition              -->
*********************************************************************************
** @defgroup Global_CILmemoryProtection Global
** @ingroup CILmemoryProtection_unit
** @brief CILmemoryProtection globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __CILMEMORYPROTECTION_H__
#define __CILMEMORYPROTECTION_H__
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
  * @defgroup Macros_CILmemoryProtection_h Macros
  * @ingroup Global_CILmemoryProtection
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_CILmemoryProtection_h
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
  * @defgroup Variables_CILmemoryProtection_h Variables
  * @ingroup Global_CILmemoryProtection
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_CILmemoryProtection_h
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
  * @defgroup Apis_CILmemoryProtection_h API's
  * @ingroup Global_CILmemoryProtection
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_CILmemoryProtection_h Getters
  * @ingroup Apis_CILmemoryProtection_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_CILmemoryProtection_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_CILmemoryProtection_h Setters
  * @ingroup Apis_CILmemoryProtection_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILmemoryProtection_init(AddressType codeMemoryHighAddress,
  * AddressType codeMemoryLowAddress,
  * AddressType stackMemoryHighAddress,
  * AddressType stackMemoryLowAddress,
  * AddressType unprotectedMemoryLowAddress,
  * AddressType unprotectedMemoryHighAddress)
  *
  * @brief Memory protection initialization. DEMO
  *
  * @param[in]  codeMemoryHighAddress
  * @param[in]  codeMemoryLowAddress
  * @param[in]  stackMemoryHighAddress
  * @param[in]  unprotectedMemoryLowAddress
  * @param[in]  unprotectedMemoryHighAddress
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
CILmemoryProtection_init(
    AddressType codeMemoryHighAddress,
    AddressType codeMemoryLowAddress,
    AddressType stackMemoryHighAddress,
    AddressType stackMemoryLowAddress,
    AddressType unprotectedMemoryLowAddress,
    AddressType unprotectedMemoryHighAddress );
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILmemoryProtection_setStackOverflowProtection(AddressType
  * stackLowAddress, AddressType stackHighAddress)
  *
  * @brief Set stack overflow protection. This function cannot
  * be called from the unprivileged context directly. DEMO
  *
  * @param[in]  stackLowAddress
  * @param[in]  stackHighAddress
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
CILmemoryProtection_setStackOverflowProtection(
    AddressType stackLowAddress,
    AddressType stackHighAddress );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILmemoryProtection_setProgramMemoryProtection(AddressType lowAddress,
  * AddressType highAddress)
  *
  * @brief Set program memory protection. This function cannot
  * be called from the unprivileged context directly. DEMO
  *
  * @param[in]  lowAddress
  * @param[in]  highAddress
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
CILmemoryProtection_setProgramMemoryProtection(
    AddressType lowAddress,
    AddressType highAddress );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILmemoryProtection_setSchedulablePeripheralProtection(
  * AddressType lowAddress, AddressType highAddress)
  *
  * @brief Set schedulable peripheral protection. This function cannot
  * be called from the unprivileged context directly. DEMO
  *
  * @param[in]  lowAddress
  * @param[in]  highAddress
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
CILmemoryProtection_setSchedulablePeripheralProtection(
    AddressType lowAddress,
    AddressType highAddress );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_CILmemoryProtection_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_CILmemoryProtection_h General
  * @ingroup Apis_CILmemoryProtection_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_CILmemoryProtection_h
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
  * @addtogroup Getters_CILmemoryProtection_h Getters
  * @ingroup Apis_CILmemoryProtection_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_CILmemoryProtection_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_CILmemoryProtection_h Setters
  * @ingroup Apis_CILmemoryProtection_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_CILmemoryProtection_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_CILmemoryProtection_h General
  * @ingroup Apis_CILmemoryProtection_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_CILmemoryProtection_h
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
