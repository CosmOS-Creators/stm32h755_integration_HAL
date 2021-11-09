/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CILsysCalls.h
*********************************************************************************
<!--                     CILsysCalls Unit Group Definition                    -->
*********************************************************************************
** @defgroup CILsysCalls_unit CILsysCalls Unit
** @ingroup CIL_module
** @brief CILsysCalls Unit
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
<!--                 CILsysCalls Unit Global Group Definition                 -->
*********************************************************************************
** @defgroup Global_CILsysCalls Global
** @ingroup CILsysCalls_unit
** @brief CILsysCalls globals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE HEADER FILE                          **
********************************************************************************/
#ifndef __CILSYSCALLS_H__
#define __CILSYSCALLS_H__
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
  * @defgroup Macros_CILsysCalls_h Macros
  * @ingroup Global_CILsysCalls
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_CILsysCalls_h
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
  * @defgroup Variables_CILsysCalls_h Variables
  * @ingroup Global_CILsysCalls
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_CILsysCalls_h
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
  * @defgroup Apis_CILsysCalls_h API's
  * @ingroup Global_CILsysCalls
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_CILsysCalls_h Getters
  * @ingroup Apis_CILsysCalls_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_CILsysCalls_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_CILsysCalls_h Setters
  * @ingroup Apis_CILsysCalls_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_CILsysCalls_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_CILsysCalls_h General
  * @ingroup Apis_CILsysCalls_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILsysCalls_dispatcher(AddressType *sp)
  *
  * @brief Dispatcher of sysCall function. This function cannot
  * be called from the unprivileged context directly.
  *
  * @param[in] sp pointer to the current stack address
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
CILsysCalls_dispatcher( AddressType * sp );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILsysCalls_bitWidthType_ret_void(BitWidthType id)
  *
  * @brief System call for bitWidthType args and return none.
  *
  * @param[in]  id is used during the system call dispatching
  *
  * @return none
********************************************************************************/
__OS_FUNC_SECTION void
CILsysCalls_bitWidthType_ret_void( BitWidthType id );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILsysCalls_bitWidthType_ret_bitWidthType(BitWidthType id)
  *
  * @brief System call for bitWidthType args and ret bitWidthType.
  *
  * @param[in]  id is used during the system call dispatching
  *
  * @return BitWidthType
********************************************************************************/
__OS_FUNC_SECTION BitWidthType
CILsysCalls_bitWidthType_ret_bitWidthType( BitWidthType id );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILsysCalls_bitWidthType_bitWidthType_ret_bitWidthType(BitWidthType id,
  * BitWidthType arg)
  *
  * @brief System call for bitWidthType args and ret bitWidthType.
  *
  * @param[in]  id is used during the system call dispatching
  * @param[in]  arg generic bitwidth type argument
  *
  * @return BitWidthType
********************************************************************************/
__OS_FUNC_SECTION BitWidthType
CILsysCalls_bitWidthType_bitWidthType_ret_bitWidthType(
    BitWidthType id,
    BitWidthType arg );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILsysCalls_bitWidthType_voidPtr_bitWidthType_ret_bitWidthType(
  * BitWidthType id,
  * void * ptr,
  * BitWidthType arg)
  *
  * @brief System call for voidPtr,bitWidthType args and ret bitWidthType.
  *
  * @param[in]  id is used during the system call dispatching
  * @param[in]  ptr void pointer to some address
  * @param[in]  arg generic bitwidth type argument
  *
  * @return BitWidthType
********************************************************************************/
__OS_FUNC_SECTION BitWidthType
CILsysCalls_bitWidthType_voidPtr_bitWidthType_ret_bitWidthType(
    BitWidthType id,
    void * ptr,
    BitWidthType arg );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILsysCalls_bitWidthType_voidPtr_ret_bitWidthType(BitWidthType id,
  * void * ptr)
  *
  * @brief System call for voidPtr and ret bitWidthType.
  *
  * @param[in]  id is used during the system call dispatching
  * @param[in]  ptr void pointer to some address
  *
  * @return BitWidthType
********************************************************************************/
__OS_FUNC_SECTION BitWidthType
CILsysCalls_bitWidthType_voidPtr_ret_bitWidthType( BitWidthType id, void * ptr );

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILsysCalls_bitWidthType_voidPtr_voidPtr_bitWidthType_ret_bitWidthType(
  * BitWidthType id,
  * void * ptr,
  * void * ptr1,
  * BitWidthType arg)
  *
  * @brief System call for voidPtr,voidPtr,bitWidthType args and ret
  * bitWidthType.
  *
  * @param[in]  id is used during the system call dispatching
  * @param[in]  ptr void pointer to some address
  * @param[in]  ptr1 void pointer to some address
  * @param[in]  arg generic bitwidth type argument
  *
  * @return BitWidthType
********************************************************************************/
__OS_FUNC_SECTION BitWidthType
CILsysCalls_bitWidthType_voidPtr_voidPtr_bitWidthType_ret_bitWidthType(
    BitWidthType id,
    void * ptr,
    void * ptr1,
    BitWidthType arg );
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_CILsysCalls_h
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
  * @addtogroup Getters_CILsysCalls_h Getters
  * @ingroup Apis_CILsysCalls_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_CILsysCalls_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_CILsysCalls_h Setters
  * @ingroup Apis_CILsysCalls_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_CILsysCalls_h
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_CILsysCalls_h General
  * @ingroup Apis_CILsysCalls_h
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_CILsysCalls_h
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
