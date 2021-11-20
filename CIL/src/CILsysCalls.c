/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CILsysCalls.c
*********************************************************************************
<!--                  CILsysCalls Unit Local Group Definition                 -->
*********************************************************************************
** @defgroup Local_CILsysCalls Local
** @ingroup CILsysCalls_unit
** @brief CILsysCalls locals
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
#include "route.h"
#include "routeCfg.h"
#include "sysCalls.h"

/* CIL interfaces */
#include "CILsysCalls.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_CILsysCalls_c Macros
  * @ingroup Local_CILsysCalls
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_CILsysCalls_c
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
  * @defgroup Variables_CILsysCalls_c Variables
  * @ingroup Local_CILsysCalls
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_CILsysCalls_c
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
  * @defgroup Apis_CILsysCalls_c API's
  * @ingroup Local_CILsysCalls
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_CILsysCalls_c Getters
  * @ingroup Apis_CILsysCalls_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_CILsysCalls_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_CILsysCalls_c Setters
  * @ingroup Apis_CILsysCalls_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_CILsysCalls_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_CILsysCalls_c General
  * @ingroup Apis_CILsysCalls_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_CILsysCalls_c
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
  * @fn CILsysCalls_dispatcher(AddressType *sp)
  *
  * @details The implementation contains retrieving of the program counter value
  * based on the stack pointer address. Then the system call identifier is
  * extracted out of the memory by decrementing the program counter. After this
  * point the os variable is obtained by calling function os_getOsCfg and then
  * used in function os_getOsRoutes to get route variable. From the route
  * variable is extracted sysCall function pointer based on the R0 register value
  * as it has argument 1 role in the procedure call standard by calling
  * function route_getRoutesFunc and the entity identifier by calling the
  * function route_getRoutesEntityId. Then sysCalls_dispatcher is called and
  * returned result is saved into the R0 position on the stack.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
CILsysCalls_dispatcher( AddressType * sp )
{
    BitWidthType entityId;

    CosmOS_GenericVoidType sysCall;
    CosmOS_OsConfigurationType * osCfg;
    CosmOS_RoutesConfigurationType * routeVar;

    uint8_t * pc = (uint8_t *)( sp[6] );

    pc -= 2;

    osCfg = os_getOsCfg();

    uint8_t sysCallId = *pc;

    routeVar = os_getOsRoutes( osCfg );

    sysCall = route_getRoutesFunc( routeVar, sp[0] );
    entityId = route_getRoutesEntityId( routeVar, sp[0] );

    sp[0] = sysCalls_dispatcher( sysCallId, entityId, sysCall, sp );
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILsysCalls_bitWidthType_ret_void(BitWidthType id)
  *
  * @details The implementation contains supervisor call instruction that causes
  * the exception. The supervisor call number is later retrieved in the system
  * call dispatcher that uses it to call the correct system call. In this case
  * is this number is 0.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
CILsysCalls_bitWidthType_ret_void( BitWidthType id )
{
    __asm volatile( "SVC #0" );

    __SUPRESS_UNUSED_VAR( id );
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILsysCalls_bitWidthType_ret_bitWidthType(BitWidthType id)
  *
  * @details The implementation contains supervisor call instruction that causes
  * the exception. The supervisor call number is later retrieved in the system
  * call dispatcher that uses it to call the correct system call. In this case
  * is this number is 1. The R0 register as it has argument 1 role in the
  * procedure call is used to extract the result of the system call and stored
  * it to the returnValue which is then returned from the function.
********************************************************************************/
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION BitWidthType
CILsysCalls_bitWidthType_ret_bitWidthType( BitWidthType id )
{
    BitWidthType returnValue;

    __asm volatile( "SVC #1" );
    __asm volatile( "MOV %0, R0" : "=r"( returnValue ):: );

    __SUPRESS_UNUSED_VAR( id );
    return returnValue;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILsysCalls_bitWidthType_bitWidthType_ret_bitWidthType(BitWidthType id,
  * BitWidthType arg)
  *
  * @details The implementation contains supervisor call instruction that causes
  * the exception. The supervisor call number is later retrieved in the system
  * call dispatcher that uses it to call the correct system call. In this case
  * is this number is 2. The R0 register as it has argument 1 role in the
  * procedure call is used to extract the result of the system call and stored
  * it to the returnValue which is then returned from the function.
********************************************************************************/
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION BitWidthType
CILsysCalls_bitWidthType_bitWidthType_ret_bitWidthType(
    BitWidthType id,
    BitWidthType arg )
{
    BitWidthType returnValue;

    __asm volatile( "SVC #2" );
    __asm volatile( "MOV %0, R0" : "=r"( returnValue ):: );

    __SUPRESS_UNUSED_VAR( id );
    __SUPRESS_UNUSED_VAR( arg );
    return returnValue;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILsysCalls_bitWidthType_voidPtr_bitWidthType_ret_bitWidthType(
  * BitWidthType id,
  * void * ptr,
  * BitWidthType arg)
  *
  * @details The implementation contains supervisor call instruction that causes
  * the exception. The supervisor call number is later retrieved in the system
  * call dispatcher that uses it to call the correct system call. In this case
  * is this number is 3. The R0 register as it has argument 1 role in the
  * procedure call is used to extract the result of the system call and stored
  * it to the returnValue which is then returned from the function.
********************************************************************************/
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION BitWidthType
CILsysCalls_bitWidthType_voidPtr_bitWidthType_ret_bitWidthType(
    BitWidthType id,
    void * ptr,
    BitWidthType arg )
{
    BitWidthType returnValue;

    __asm volatile( "SVC #3" );
    __asm volatile( "MOV %0, R0" : "=r"( returnValue ):: );

    __SUPRESS_UNUSED_VAR( id );
    __SUPRESS_UNUSED_VAR( ptr );
    __SUPRESS_UNUSED_VAR( arg );
    return returnValue;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILsysCalls_bitWidthType_voidPtr_ret_bitWidthType(BitWidthType id,
  * void * ptr)
  *
  * @details The implementation contains supervisor call instruction that causes
  * the exception. The supervisor call number is later retrieved in the system
  * call dispatcher that uses it to call the correct system call. In this case
  * is this number is 4. The R0 register as it has argument 1 role in the
  * procedure call is used to extract the result of the system call and stored
  * it to the returnValue which is then returned from the function.
********************************************************************************/
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION BitWidthType
CILsysCalls_bitWidthType_voidPtr_ret_bitWidthType( BitWidthType id, void * ptr )
{
    BitWidthType returnValue;

    __asm volatile( "SVC #4" );
    __asm volatile( "MOV %0, R0" : "=r"( returnValue ):: );

    __SUPRESS_UNUSED_VAR( id );
    __SUPRESS_UNUSED_VAR( ptr );
    return returnValue;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

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
  * @details The implementation contains supervisor call instruction that causes
  * the exception. The supervisor call number is later retrieved in the system
  * call dispatcher that uses it to call the correct system call. In this case
  * is this number is 5. The R0 register as it has argument 1 role in the
  * procedure call is used to extract the result of the system call and stored
  * it to the returnValue which is then returned from the function.
********************************************************************************/
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION BitWidthType
CILsysCalls_bitWidthType_voidPtr_voidPtr_bitWidthType_ret_bitWidthType(
    BitWidthType id,
    void * ptr,
    void * ptr1,
    BitWidthType arg )
{
    BitWidthType returnValue;

    __asm volatile( "SVC #5" );
    __asm volatile( "MOV %0, R0" : "=r"( returnValue ):: );

    __SUPRESS_UNUSED_VAR( id );
    __SUPRESS_UNUSED_VAR( ptr );
    __SUPRESS_UNUSED_VAR( ptr1 );
    __SUPRESS_UNUSED_VAR( arg );
    return returnValue;
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
