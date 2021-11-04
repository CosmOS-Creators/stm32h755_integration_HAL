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
#include "cosmosAssert.h"
#include "os.h"

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
  * @} */
/* Macros_CILcore_c
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
  * @} */
/* Variables_CILcore_c
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
  * @} */
/* Getters_CILcore_c
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
  * @} */
/* Setters_CILcore_c
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
  * @} */
/* General_CILcore_c
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
  * @fn CILcore_getCoreId(void)
  *
  * @details The implementation contains obtaining of CPU ID by calling the
  * HAL_GetCurrentCPUID function. If the CM7_CPUID is returned the CM7 macro
  * is returned from the function, otherwise the CM4 macro is returned.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION BitWidthType
CILcore_getCoreId( void )
{
    return ( HAL_GetCurrentCPUID() == CM7_CPUID ) ? CM7 : CM4;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILcore_setCoreVar(CosmOS_OsVariableType * osVar)
  *
  * @details The implementation contains obtaining of the core id by calling
  * function CILcore_getCoreId. To ensure correctness of the core id the number
  * of cores is obtained by calling function numberOfCores. If the core id is
  * less than number of cores the core variable is obtained by calling function
  * os_getCoreVar and its address is set to the platform register R9.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
CILcore_setCoreVar( CosmOS_OsVariableType * osVar )
{
    BitWidthType coreId, numberOfCores;

    CosmOS_CoreVariableType * coreVar;

    coreId = CILcore_getCoreId();
    numberOfCores = os_getOsNumberOfCores( osVar );

    cosmosAssert( coreId < numberOfCores );

    coreVar = os_getCoreVar( osVar, coreId );

    __asm volatile( "MOV R9,%[coreVariable]" : [coreVariable] "=r"( coreVar ) );
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
