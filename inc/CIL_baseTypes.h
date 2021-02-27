/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CIL_baseTypes.h                                      
*********************************************************************************	
<!--                   CIL_baseTypes Unit Group Definition                    -->
********************************************************************************* 
** @defgroup CIL_baseTypes_unit CIL_baseTypes Unit 
** @ingroup CosmOSTypes_module        
** @brief CIL_baseTypes Unit 
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
<!--                 CIL_baseTypes Unit Global Group Definition               -->
*********************************************************************************	
** @defgroup Global_CIL_baseTypes Global
** @ingroup CIL_baseTypes_unit 
** @brief CIL_baseTypes globals
** @details lorem 
********************************************************************************/ 
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __CIL_BASETYPES_H__
#define __CIL_BASETYPES_H__
/********************************************************************************
**                         START OF C++ SUPPORT SECTION                        **
********************************************************************************/
#ifdef __cplusplus
 extern "C" {
#endif
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* STANDARD interfaces */
#include <stdint.h>
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_CIL_baseTypes_h Macros
  * @ingroup Global_CIL_baseTypes  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_CIL_baseTypes_h  
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Stop                           **
********************************************************************************/
/********************************************************************************
**                              Typedefs | Start                               **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Typedefs_CIL_baseTypesCfg_h Typedefs
  * @ingroup Global_CIL_baseTypes  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  BitWidthType based on processor register bit width type, please define
  * your processor registers bit width type with ARCH_NBIT
********************************************************************************/
#ifdef ARCH_8BIT
    typedef unsigned char         BitWidthType;
    #define FORCE_ENUM            0xFF
    #define REACHED_BARRIER       0xAA
#elif ARCH_16BIT
    typedef unsigned short        BitWidthType;
    #define FORCE_ENUM            0xFFFF
    #define REACHED_BARRIER       0xAAAA
#elif ARCH_32BIT
    typedef unsigned int          BitWidthType;
    #define FORCE_ENUM            0xFFFFFFFF
    #define REACHED_BARRIER       0xAAAAAAAA
#elif ARCH_64BIT
    typedef unsigned long long    BitWidthType;
    #define FORCE_ENUM            0xFFFFFFFFFFFFFFFF
    #define REACHED_BARRIER       0xAAAAAAAAAAAAAAAA
#else
    #error "Please specify the BitWidth for your microprocessor! (ARCH_NBIT) => N = 8,16,32,64"
#endif

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @brief  AddressType based on addressable memory with ADDR_NBIT
********************************************************************************/
#ifdef ADDR_8BIT
    typedef unsigned char         AddressType;
#elif ADDR_16BIT
    typedef unsigned short        AddressType;
#elif ADDR_32BIT
    typedef unsigned int          AddressType;
#elif ADDR_64BIT
    typedef unsigned long long    AddressType;
#else
    #error "Please specify the AddressType for your microprocessor! (ADDR_NBIT) => N = 8,16,32,64"
#endif
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Typedefs_CIL_baseTypes_h  
********************************************************************************/
/********************************************************************************
**                              Typedefs | Stop                                **
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