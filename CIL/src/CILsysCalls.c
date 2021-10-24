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
  * @brief Selector of sysCall function DEMO CODE.
  *
  * @param[in] AddressType *sp
  *
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
CILsysCalls_dispatcher( AddressType * sp )
{
    BitWidthType returnValue, entityId;

    CosmOS_GenericVoidType sysCall;
    CosmOS_OsVariableType * osVar;
    CosmOS_RoutesConfigurationType * routeVar;

    uint8_t * pc = (uint8_t *)( sp[6] );

    pc -= 2;

    osVar = os_getOsVar();

    uint8_t sysCallId = *pc;

    routeVar = os_getOsRoutes( osVar );

    sysCall = route_getRoutesFunc( routeVar, sp[0] );
    entityId = route_getRoutesEntityId( routeVar, sp[0] );

    switch ( sysCallId )
    {
        case 0:
        {
            ( (CosmOS_Generic_bitWidthType_ret_void)sysCall )( entityId );
            break;
        }

        case 1:
        {
            returnValue =
                ( (CosmOS_Generic_bitWidthType_ret_bitWidthType)sysCall )(
                    entityId );
            break;
        }

        case 2:
        {
            returnValue =
                ( (CosmOS_Generic_bitWidthType_bitWidthType_ret_bitWidthType)
                      sysCall )( entityId, (BitWidthType)sp[1] );
            break;
        }

        case 3:
        {
            returnValue = ( (
                CosmOS_Generic_bitWidthType_voidPtr_bitWidthType_ret_bitWidthType)
                                sysCall )( entityId, (void *)sp[1], sp[2] );
            break;
        }

        case 4:
        {
            returnValue = ( (
                CosmOS_Generic_bitWidthType_voidPtr_ret_bitWidthType)sysCall )(
                entityId, (void *)sp[1] );
            break;
        }

        default:
        {
            /* PANIC */
            break;
        }
    }

    sp[0] = returnValue;
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
  * @brief System call handling general operating system functionalities.
  *
  * @param[in]  BitWidthType id
  *
  * @return none
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
  * @brief System call for bitWidthType args and ret bitWidthType.
  *
  * @param[in]  BitWidthType id
  *
  * @return BitWidthType
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
  * @brief System call for bitWidthType args and ret bitWidthType.
  *
  * @param[in]  BitWidthType id
  * @param[in]  BitWidthType arg
  *
  * @return BitWidthType
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
  * @brief System call for voidPtr,bitWidthType args and ret bitWidthType.
  *
  * @param[in]  BitWidthType id
  * @param[in]  void * ptr
  * @param[in]  BitWidthType arg
  *
  * @return BitWidthType
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
  * @brief System call for voidPtr and ret bitWidthType.
  *
  * @param[in]  BitWidthType id
  * @param[in]  void * ptr
  *
  * @return BitWidthType
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
**                        Function Definitions | Stop                          **
********************************************************************************/
/********************************************************************************
**                           END OF THE SOURCE FILE                            **
********************************************************************************/
