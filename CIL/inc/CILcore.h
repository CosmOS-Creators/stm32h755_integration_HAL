/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CILcore.h
*********************************************************************************
<!--                       CILcore Unit Group Definition                      -->
*********************************************************************************
** @defgroup CILcore_unit CILcore Unit
** @ingroup CIL_module
** @brief CILcore Unit
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
<!--                   CILcore Unit Global Group Definition                   -->
*********************************************************************************
** @defgroup Global_CILcore Global
** @ingroup CILcore_unit
** @brief CILcore globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __CILCORE_H__
#define __CILCORE_H__
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
  * @defgroup Macros_CILcore_h Macros
  * @ingroup Global_CILcore
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_CILcore_h
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
  * @defgroup Variables_CILcore_h Variables
  * @ingroup Global_CILcore
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_CILcore_h
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
  * @defgroup Apis_CILcore_h API's
  * @ingroup Global_CILcore
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_CILcore_h Getters
  * @ingroup Apis_CILcore_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILcore_getCoreId(void)
  *
  * @brief Get core identifier. This function is provided
  * as a CosmOS API system call mapped with the routes and cannot be called from
  * the unprivileged context directly. DEMO
  *
  * @param[in]  none
  *
  * @return BitWidthType
********************************************************************************/
__OS_FUNC_SECTION BitWidthType
CILcore_getCoreId( void );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_CILcore_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_CILcore_h Setters
  * @ingroup Apis_CILcore_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILcore_setCoreCfg(CosmOS_OsConfigurationType * os)
  *
  * @brief Set core configuration to the R9 platform register.
  * This function cannot be called from the unprivileged context directly.
  *
  * @param[in]  os configuration pointer
  *
  * @return void
********************************************************************************/
__OS_FUNC_SECTION void
CILcore_setCoreCfg( CosmOS_OsConfigurationType * os );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_CILcore_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_CILcore_h General
  * @ingroup Apis_CILcore_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_CILcore_h
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
  * @addtogroup Getters_CILcore_h Getters
  * @ingroup Apis_CILcore_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILcore_getCoreCfg(void)
  *
  * @brief Get coreVar. DEMO
  *
  * @param[in]  none
  *
  * @return CosmOS_CoreConfigurationType *
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_CoreConfigurationType *
CILcore_getCoreCfg( void )
{
    BitWidthType result;
    __asm volatile( "MOV %[resultVariable], R9"
                    : [resultVariable] "=r"( result ) );
    return (CosmOS_CoreConfigurationType *)result;
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_CILcore_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_CILcore_h Setters
  * @ingroup Apis_CILcore_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_CILcore_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_CILcore_h General
  * @ingroup Apis_CILcore_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILcore_isInPrivilegedMode(void)
  *
  * @brief Is core in privileged mode. DEMO
  *
  * @param[in]  none
  *
  * @return CosmOS_BooleanType
********************************************************************************/
__STATIC_FORCEINLINE CosmOS_BooleanType
CILcore_isInPrivilegedMode( void )
{
    return (
        ( __get_IPSR() __OR IS_NOT( __get_CONTROL() & CONTROL_nPRIV_Msk ) )
            ? True
            : False );
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILcore_reset(void)
  *
  * @brief This function causes system reset. DEMO
  *
  * @param[in]  none
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
CILcore_systemReset( void )
{
    NVIC_SystemReset();
}

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILcore_triggerEvent(void)
  *
  * @brief This function triggers event for every cpu in multicore system. DEMO
  *
  * @param[in]  none
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void
CILcore_triggerEvent( void )
{
    __asm volatile( "SEV" );
}
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_CILcore_h
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
