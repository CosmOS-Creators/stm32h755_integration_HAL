/********************************************************************************
**                                                                             **
**                       GENERATED FILE BY COSMOS CustomBox                    **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CIL_boot.c
*********************************************************************************
<!--                   CIL_boot Unit Local Group Definition                   -->
*********************************************************************************	
** @defgroup Local_CIL_boot Local
** @ingroup CIL_boot_unit 
** @brief CIL_boot locals
** @details lorem 
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CIL interfaces */
#include "CIL_boot.h"
#include "CIL_core.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_CIL_boot_c Macros
  * @ingroup Local_CIL_boot
  * @{    
********************************************************************************/
#define BOOT_ARGS_NUM    (BitWidthType)3
#define SECTION_NUM_OS    (BitWidthType)2
#define SECTION_NUM_CORE_0    (BitWidthType)2
#define SECTION_NUM_CORE_1    (BitWidthType)2
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_CIL_boot_c  
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
  * @defgroup Variables_CIL_boot_c Variables  
  * @ingroup Local_CIL_boot
  * @{    
********************************************************************************/
extern unsigned char _s_os_section_consts[];
extern unsigned char _s_os_section_vars[];
extern unsigned char _s_program_default_CM7_section_init[];
extern unsigned char _s_program_blinking_led_CM7_section_init[];
extern unsigned char _s_program_default_CM4_section_init[];
extern unsigned char _s_program_blinking_led_CM4_section_init[];
extern unsigned char _e_os_section_consts[];
extern unsigned char _e_os_section_vars[];
extern unsigned char _e_program_default_CM7_section_init[];
extern unsigned char _e_program_blinking_led_CM7_section_init[];
extern unsigned char _e_program_default_CM4_section_init[];
extern unsigned char _e_program_blinking_led_CM4_section_init[];
extern unsigned char _flash_os_section_consts_start[];
extern unsigned char _flash_os_section_vars_start[];
extern unsigned char _flash_program_default_CM7_section_init[];
extern unsigned char _flash_program_blinking_led_CM7_section_init[];
extern unsigned char _flash_program_default_CM4_section_init[];
extern unsigned char _flash_program_blinking_led_CM4_section_init[];



unsigned char * const pogramSectionsCore0[SECTION_NUM_CORE_0][BOOT_ARGS_NUM]
IS_INITIALIZED_TO
{
		{
        _s_program_default_CM7_section_init,
        _e_program_default_CM7_section_init,
        _flash_program_default_CM7_section_init,
    },
		{
        _s_program_blinking_led_CM7_section_init,
        _e_program_blinking_led_CM7_section_init,
        _flash_program_blinking_led_CM7_section_init,
    },
};
unsigned char * const pogramSectionsCore1[SECTION_NUM_CORE_1][BOOT_ARGS_NUM]
IS_INITIALIZED_TO
{
		{
        _s_program_default_CM4_section_init,
        _e_program_default_CM4_section_init,
        _flash_program_default_CM4_section_init,
    },
		{
        _s_program_blinking_led_CM4_section_init,
        _e_program_blinking_led_CM4_section_init,
        _flash_program_blinking_led_CM4_section_init,
    },
};
unsigned char * const osSections[SECTION_NUM_OS][BOOT_ARGS_NUM]
IS_INITIALIZED_TO
{
    {
        _s_os_section_consts,
        _e_os_section_consts,
        _flash_os_section_consts_start,
    },
    {
        _s_os_section_vars,
        _e_os_section_vars,
        _flash_os_section_vars_start,
    },
};
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_CIL_boot_c  
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
  * @defgroup Apis_CIL_boot_c API's  
  * @ingroup Local_CIL_boot
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_CIL_boot_c Getters  
  * @ingroup Apis_CIL_boot_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_CIL_boot_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_CIL_boot_c Setters  
  * @ingroup Apis_CIL_boot_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_CIL_boot_c   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_CIL_boot_c General  
  * @ingroup Apis_CIL_boot_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_CIL_boot_c  
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
  * @fn CIL_boot_section( unsigned char * sectionStart, unsigned char * sectionEnd, unsigned char * sectionStartInFlash)
  * 
  * @brief Boot of the section.
  * 
  * @param[in]  unsigned char * sectionStart
  * @param[in]  unsigned char * sectionEnd
  * @param[in]  unsigned char * sectionStartInFlash
  * 
  * @return none
********************************************************************************/
__STATIC_FORCEINLINE void CIL_boot_section( unsigned char * sectionStart, unsigned char * sectionEnd, unsigned char * sectionStartInFlash)
{
    BitWidthType size = (BitWidthType)(sectionEnd - sectionStart);

	  unsigned char *pDst = sectionStart;
	  unsigned char *pSrc = sectionStartInFlash;

	  for ( BitWidthType i = 0; i < (size * sizeof(BitWidthType)); i++ )
    {
	  	  *pDst++=*pSrc++;
    }
}
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn CIL_boot_bootOs(void)
  * 
  * @brief Boot of operating system.
  * 
  * @param[in]  none
  * 
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void CIL_boot_bootOs(void)
{
    BitWidthType coreId;


    coreId = CIL_core_getCoreId();

    if (coreId IS_EQUAL_TO CORE_0_ID)
    {
        for (BitWidthType i=0; i < SECTION_NUM_CORE_0; i++)
        {
            CIL_boot_section(pogramSectionsCore0[i][0],pogramSectionsCore0[i][1],pogramSectionsCore0[i][2]);
        }
        
    }
    if (coreId IS_EQUAL_TO CORE_1_ID)
    {
        for (BitWidthType i=0; i < SECTION_NUM_CORE_1; i++)
        {
            CIL_boot_section(pogramSectionsCore1[i][0],pogramSectionsCore1[i][1],pogramSectionsCore1[i][2]);
        }
        for (BitWidthType i=0; i < SECTION_NUM_OS; i++)
        {
            CIL_boot_section(osSections[i][0],osSections[i][1],osSections[i][2]);
        } 
        
    }
    
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