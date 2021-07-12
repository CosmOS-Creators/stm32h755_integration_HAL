/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CILcore.c
*********************************************************************************
<!--                    CILcore Unit Local Group Definition                   -->
*********************************************************************************
** @defgroup Local_CILcore Local
** @ingroup CILcore_unit
** @brief CILcore locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CORE interfaces */
#include "os.h"
#include "cosmosAssert.h"

/* CIL interfaces */
#include "CILcore.h"

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
  * @defgroup Macros_CILcore_c Macros
  * @ingroup Local_CILcore
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Macros_CILcore_c
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
  * @defgroup Variables_CILcore_c Variables
  * @ingroup Local_CILcore
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Variables_CILcore_c
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
  * @defgroup Apis_CILcore_c API's
  * @ingroup Local_CILcore
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_CILcore_c Getters
  * @ingroup Apis_CILcore_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Getters_CILcore_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_CILcore_c Setters
  * @ingroup Apis_CILcore_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Setters_CILcore_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_CILcore_c General
  * @ingroup Apis_CILcore_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_CILcore_c
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
  * @fn CILcore_getCoreId(void)
  *
  * @brief Get core identificator.
  *
  * @param[in]  none
  *
  * @return BitWidthType
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION BitWidthType CILcore_getCoreId(void)
{
    return (HAL_GetCurrentCPUID() == CM7_CPUID) ? CORE_0_ID : CORE_1_ID;
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn CILcore_setCoreVar(CosmOS_OsVariableType * osVar)
  *
  * @brief Set core variable to the R9 platform register.
  *
  * @param[in]  CosmOS_OsVariableType * osVar
  *
  * @return void
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void CILcore_setCoreVar(CosmOS_OsVariableType * osVar)
{
    BitWidthType coreId,
                numberOfCores;

    CosmOS_CoreVariableType * coreVar;

    coreId = CILcore_getCoreId();
    numberOfCores = os_getOsNumberOfCores( osVar );

    cosmosAssert( coreId < numberOfCores );

    coreVar = os_getCoreVar( osVar, coreId );

    //must be changed, not valid for all compilers
    __asm volatile("MOV R9,%[coreVariable]" : [coreVariable] "=r" (coreVar));
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
