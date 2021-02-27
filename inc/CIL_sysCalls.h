/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CIL_sysCalls.h
*********************************************************************************	
<!--                    CIL_sysCalls Unit Group Definition                    -->
********************************************************************************* 
** @defgroup CIL_sysCalls_unit CIL_sysCalls Unit 
** @ingroup CIL_module        
** @brief CIL_sysCalls Unit 
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
<!--                CIL_sysCalls Unit Global Group Definition                 -->
*********************************************************************************
** @defgroup Global_CIL_sysCalls Global
** @ingroup CIL_sysCalls_unit 
** @brief CIL_sysCalls globals
** @details lorem  
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __CIL_SYSCALLS_H__
#define __CIL_SYSCALLS_H__
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
#include "sysDefs.h"
#include "memoryMapping.h"

/* CIL interfaces */
#include "CIL_stdTypes.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_CIL_sysCalls_h Macros
  * @ingroup Global_CIL_sysCalls  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_CIL_sysCalls_h  
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
  * @defgroup Variables_CIL_sysCalls_h Variables  
  * @ingroup Global_CIL_sysCalls  
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_CIL_sysCalls_h  
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
  * @defgroup Apis_CIL_sysCalls_h API's 
  * @ingroup Global_CIL_sysCalls
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_CIL_sysCalls_h Getters  
  * @ingroup Apis_CIL_sysCalls_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_CIL_sysCalls_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_CIL_sysCalls_h Setters  
  * @ingroup Apis_CIL_sysCalls_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_CIL_sysCalls_h   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_CIL_sysCalls_h General  
  * @ingroup Apis_CIL_sysCalls_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn CIL_sysCalls_selector(BitWidthType *sp) 
  * 
  * @brief Selector of sysCall function.
  * 
  * @param[in] BitWidthType *sp
  * 
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void CIL_sysCalls_selector(BitWidthType *sp);

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn CIL_sysCalls_os(BitWidthType id) 
  * 
  * @brief System call handling general operating system functionalities.
  * 
  * @param[in]  BitWidthType id
  * 
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void CIL_sysCalls_os(BitWidthType id);

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * *************************************************************************//**
  * @fn CIL_sysCalls_readWrite(BitWidthType id, void * buffer, BitWidthType num) 
  * 
  * @brief System call handling read/write from/to buffers or registers.
  * 
  * @param[in]  BitWidthType id
  * @param[in]  void * buffer
  * @param[in]  BitWidthType num
  * 
  * @return BitWidthType
********************************************************************************/
__OS_FUNC_SECTION BitWidthType CIL_sysCalls_readWrite(BitWidthType id, void * buffer, BitWidthType num);
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_CIL_sysCalls_h  
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
  * @addtogroup Getters_CIL_sysCalls_h Getters  
  * @ingroup Apis_CIL_sysCalls_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_CIL_sysCalls_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_CIL_sysCalls_h Setters  
  * @ingroup Apis_CIL_sysCalls_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_CIL_sysCalls_h   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_CIL_sysCalls_h General  
  * @ingroup Apis_CIL_sysCalls_h                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_CIL_sysCalls_h  
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