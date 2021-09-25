/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CILmemoryProtection.c
*********************************************************************************
<!--               CILmemoryProtection Unit Local Group Definition            -->
*********************************************************************************
** @defgroup Local_CILmemoryProtection Local
** @ingroup CILmemoryProtection_unit
** @brief CILmemoryProtection locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CIL interfaces */
#include "CILmemoryProtection.h"

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
  * @defgroup Macros_CILmemoryProtection_c Macros
  * @ingroup Local_CILmemoryProtection
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Macros_CILmemoryProtection_c
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
  * @defgroup Variables_CILmemoryProtection_c Variables
  * @ingroup Local_CILmemoryProtection
  * @{
********************************************************************************/
extern unsigned char _s_os_section_consts[];
extern unsigned char _e_os_section_consts[];
extern unsigned char _s_os_section_vars[];
extern unsigned char _e_os_section_vars[];
extern unsigned char _s_unprotected_section[];
extern unsigned char _e_unprotected_section[];

/* @cond S */
__SEC_START(__OS_CONSTS_SECTION_START)
/* @endcond*/
const int MultiplyDeBruijnBitPosition[32] __OS_CONSTS_SECTION
IS_INITIALIZED_TO
{
	0, 9, 1, 10, 13, 21, 2, 29, 11, 14, 16, 18, 22, 25, 3, 30,
	8, 12, 20, 28, 15, 17, 24, 7, 19, 27, 23, 6, 26, 5, 4, 31
};
/* @cond S */
__SEC_STOP(__OS_CONSTS_SECTION_STOP)
/* @endcond*/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Variables_CILmemoryProtection_c
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
  * @defgroup Apis_CILmemoryProtection_c API's
  * @ingroup Local_CILmemoryProtection
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_CILmemoryProtection_c Getters
  * @ingroup Apis_CILmemoryProtection_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Getters_CILmemoryProtection_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_CILmemoryProtection_c Setters
  * @ingroup Apis_CILmemoryProtection_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * Setters_CILmemoryProtection_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_CILmemoryProtection_c General
  * @ingroup Apis_CILmemoryProtection_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_CILmemoryProtection_c
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
  * @fn CILmemoryProtection_fastLogBase2(BitWidthType size)
  *
  * @brief Calculate fast log with base 2.
  *
  * @param[in]  BitWidthType size
  *
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE BitWidthType CILmemoryProtection_fastLogBase2(BitWidthType size)
{
    BitWidthType result;

    size |= size >> 1;
    size |= size >> 2;
    size |= size >> 4;
    size |= size >> 8;
    size |= size >> 16;

    result = MultiplyDeBruijnBitPosition[(uint32_t)(size * 0x07C4ACDDU) >> 27];

    return (result-1);
}
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn CILmemoryProtection_init(AddressType codeMemoryHighAddress,\
  *							AddressType codeMemoryLowAddress, \
  *							AddressType stackMemoryHighAddress, \
  *							AddressType stackMemoryLowAddress)
  *
  * @brief Init memory protection DEMO CODE.
  *
  * @param[in]  AddressType codeMemoryHighAddress
  * @param[in]  AddressType codeMemoryLowAddress
  * @param[in]  AddressType stackMemoryHighAddress
  * @param[in]  AddressType stackMemoryLowAddress
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void CILmemoryProtection_init(AddressType codeMemoryHighAddress,\
												AddressType codeMemoryLowAddress, \
												AddressType stackMemoryHighAddress, \
												AddressType stackMemoryLowAddress)
{
    MPU_Region_InitTypeDef MPU_InitStruct = {0};

    HAL_MPU_Disable();

    //MPU_InitStruct.Enable = MPU_REGION_ENABLE;
    //MPU_InitStruct.Number = MPU_REGION_NUMBER0;
    //MPU_InitStruct.BaseAddress = codeMemoryLowAddress;
    //MPU_InitStruct.Size = (CILmemoryProtection_fastLogBase2( (BitWidthType)( codeMemoryHighAddress - codeMemoryLowAddress )));
    //MPU_InitStruct.SubRegionDisable = 0x00;
    //MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL1;
    //MPU_InitStruct.AccessPermission = MPU_REGION_PRIV_RO_URO;
    //MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
    //MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
    //MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
    //MPU_InitStruct.IsBufferable = MPU_ACCESS_BUFFERABLE;

	//TODO: Patched cause MPU should take in count whole FLASH - functions from the routes are used from the local core flash bank which booted the os consts to RAM
	MPU_InitStruct.Enable = MPU_REGION_ENABLE;
    MPU_InitStruct.Number = MPU_REGION_NUMBER0;
    MPU_InitStruct.BaseAddress = 0x08000000;
    MPU_InitStruct.Size = MPU_REGION_SIZE_2MB;
    MPU_InitStruct.SubRegionDisable = 0x00;
    MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL1;
    MPU_InitStruct.AccessPermission = MPU_REGION_PRIV_RO_URO;
    MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
    MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
    MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
    MPU_InitStruct.IsBufferable = MPU_ACCESS_BUFFERABLE;

    HAL_MPU_ConfigRegion(&MPU_InitStruct);

    MPU_InitStruct.Enable = MPU_REGION_ENABLE;
    MPU_InitStruct.Number = MPU_REGION_NUMBER1;
    MPU_InitStruct.BaseAddress = stackMemoryLowAddress;
    MPU_InitStruct.Size = (CILmemoryProtection_fastLogBase2( (BitWidthType)( stackMemoryHighAddress - stackMemoryLowAddress )));
    MPU_InitStruct.SubRegionDisable = 0x00;
    MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL1;
    MPU_InitStruct.AccessPermission = MPU_REGION_PRIV_RW_URO;
    MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
    MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
    MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
    MPU_InitStruct.IsBufferable = MPU_ACCESS_BUFFERABLE;

    HAL_MPU_ConfigRegion(&MPU_InitStruct);

    MPU_InitStruct.Enable = MPU_REGION_ENABLE;
    MPU_InitStruct.Number = MPU_REGION_NUMBER2;
    MPU_InitStruct.BaseAddress =  (BitWidthType)_s_os_section_consts;
    MPU_InitStruct.Size = (CILmemoryProtection_fastLogBase2( (BitWidthType)( _e_os_section_consts - _s_os_section_consts )));
    MPU_InitStruct.SubRegionDisable = 0x00;
    MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL1;
    MPU_InitStruct.AccessPermission = MPU_REGION_PRIV_RO_URO;
    MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
    MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
    MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
    MPU_InitStruct.IsBufferable = MPU_ACCESS_BUFFERABLE;

    HAL_MPU_ConfigRegion(&MPU_InitStruct);

    MPU_InitStruct.Enable = MPU_REGION_ENABLE;
    MPU_InitStruct.Number = MPU_REGION_NUMBER3;
    MPU_InitStruct.BaseAddress = (BitWidthType)_s_os_section_vars;
    MPU_InitStruct.Size = (CILmemoryProtection_fastLogBase2( (BitWidthType)(_e_os_section_vars - _s_os_section_vars )));
    MPU_InitStruct.SubRegionDisable = 0x00;
    MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL1;
    MPU_InitStruct.AccessPermission = MPU_REGION_PRIV_RW_URO;
    MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
    MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
    MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
    MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;

    HAL_MPU_ConfigRegion(&MPU_InitStruct);

	MPU_InitStruct.Enable = MPU_REGION_ENABLE;
    MPU_InitStruct.Number = MPU_REGION_NUMBER4;
    MPU_InitStruct.BaseAddress = (BitWidthType)_s_unprotected_section;
    MPU_InitStruct.Size = (CILmemoryProtection_fastLogBase2( (BitWidthType)(_e_unprotected_section - _s_unprotected_section )));
    MPU_InitStruct.SubRegionDisable = 0x00;
    MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL1;
    MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
    MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;
    MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
    MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
    MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;

    HAL_MPU_ConfigRegion(&MPU_InitStruct);

    HAL_MPU_Enable(MPU_HFNMI_PRIVDEF);

	__SUPRESS_UNUSED_VAR(codeMemoryHighAddress);
	__SUPRESS_UNUSED_VAR(codeMemoryLowAddress);
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn CILmemoryProtection_setStackOverflowProtection(AddressType stackLowAddress, AddressType stackHighAddress)
  *
  * @brief Set stack overflow protection DEMO CODE.
  *
  * @param[in]  AddressType stackLowAddress
  * @param[in]  AddressType stackHighAddress
  *
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void CILmemoryProtection_setStackOverflowProtection(AddressType stackLowAddress, AddressType stackHighAddress)
{
    MPU_Region_InitTypeDef MPU_InitStruct = {0};

    HAL_MPU_Disable();

    /** Initializes and configures the Region and the memory to be protected
    */
    MPU_InitStruct.Enable = MPU_REGION_ENABLE;
    MPU_InitStruct.Number = MPU_REGION_NUMBER7;
    MPU_InitStruct.BaseAddress = (stackLowAddress);
    MPU_InitStruct.Size = (CILmemoryProtection_fastLogBase2( stackHighAddress - stackLowAddress ));
    MPU_InitStruct.SubRegionDisable = 0x00;
    MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL1;
    MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
    MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
    MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
    MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
    MPU_InitStruct.IsBufferable = MPU_ACCESS_BUFFERABLE;

    HAL_MPU_ConfigRegion(&MPU_InitStruct);
    /* Enables the MPU */
    HAL_MPU_Enable(MPU_HFNMI_PRIVDEF);
}
/* @cond S */
__SEC_STOP(__OS_FUNC_SECTION_STOP)
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn CILmemoryProtection_setProgramMemoryProtection(AddressType lowAddress, AddressType highAddress)
  *
  * @brief Set program memory protection DEMO CODE.
  *
  * @param[in]  AddressType lowAddress
  * @param[in]  AddressType highAddress
  *
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void CILmemoryProtection_setProgramMemoryProtection(AddressType lowAddress, AddressType highAddress)
{
    MPU_Region_InitTypeDef MPU_InitStruct = {0};

    HAL_MPU_Disable();

    /** Initializes and configures the Region and the memory to be protected
    */
    MPU_InitStruct.Enable = MPU_REGION_ENABLE;
    MPU_InitStruct.Number = MPU_REGION_NUMBER6;
    MPU_InitStruct.BaseAddress = (lowAddress);
    MPU_InitStruct.Size = (CILmemoryProtection_fastLogBase2( highAddress - lowAddress ));
    MPU_InitStruct.SubRegionDisable = 0x00;
    MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL1;
    MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
    MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
    MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
    MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
    MPU_InitStruct.IsBufferable = MPU_ACCESS_BUFFERABLE;

    HAL_MPU_ConfigRegion(&MPU_InitStruct);
    /* Enables the MPU */
    HAL_MPU_Enable(MPU_HFNMI_PRIVDEF);
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
