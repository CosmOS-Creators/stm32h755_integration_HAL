/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CILstack.c
*********************************************************************************
<!--                    CILstack Unit Local Group Definition                  -->
*********************************************************************************
** @defgroup Local_CILstack Local
** @ingroup CILstack_unit
** @brief CILstack locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CIL interfaces */
#include "CILstack.h"
/********************************************************************************
**                            Include Files | Stop                             **
********************************************************************************/
/********************************************************************************
**                          Macro Definitions | Start                          **
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @defgroup Macros_CILstack_c Macros
  * @ingroup Local_CILstack
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_CILstack_c
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
  * @defgroup Variables_CILstack_c Variables
  * @ingroup Local_CILstack
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_CILstack_c
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
  * @defgroup Apis_CILstack_c API's
  * @ingroup Local_CILstack
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_CILstack_c Getters
  * @ingroup Apis_CILstack_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_CILstack_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_CILstack_c Setters
  * @ingroup Apis_CILstack_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_CILstack_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_CILstack_c General
  * @ingroup Apis_CILstack_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_CILstack_c
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
  * @fn CILstack_stackInit(AddressType stackLowAddress,
  * AddressType stackHighAddress,
  * AddressType handlerAddress)
  *
  * @details The implementation contains stack initialization by placing the
  * context type at the stackHighAddress - context type size and initializing
  * all standard context registers loaded from the stack. Then is the stack
  * pointer address represented by the lowest address of the context type
  * structure returned from the function.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION StackPointerType
CILstack_stackInit(
    AddressType stackLowAddress,
    AddressType stackHighAddress,
    AddressType handlerAddress )
{
    CosmOS_ContextType * stack =
        (CosmOS_ContextType *)( stackHighAddress - (AddressType)sizeof( CosmOS_ContextType ) );

    stack->XPSR = 0x01000000;
    stack->PC = handlerAddress;
    stack->LR = 0xFFFFFFFD;
    stack->R12 = 0;
    stack->R3 = 0;
    stack->R2 = 0;
    stack->R1 = 0;
    stack->R0 = 0;
    stack->R14 = 0xFFFFFFFD;
    stack->R11 = 0;
    stack->R10 = 0;
    stack->R8 = 0;
    stack->R7 = 0;
    stack->R6 = 0;
    stack->R5 = 0;
    stack->R4 = 0;

    __SUPRESS_UNUSED_VAR( stackLowAddress );
    return ( StackPointerType )( &( stack->R4 ) );
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILstack_setStackPointer(BitWidthType address)
  *
  * @details The implementation contains load multiple registers instruction to
  * restore the standard context registers. After this point the process stack
  * pointer is set to the value stored in the R0 register as it has argument 1
  * role in the procedure call standard thus it holds the address argument value.
  * Then the thread mode bit is set inside the control register and instruction
  * barrier is implemented afterwards. After this point the branch and exchange
  * instruction is called based on the value of the R14 register.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION __NAKED void
CILstack_setStackPointer( AddressType address )
{
    __asm volatile( "LDMIA R0!,{R4-R8,R10,R11,R14}" );
    __asm volatile( "MSR PSP,R0" );
    __asm volatile( "MOV R0, #0x3" );
    __asm volatile( "MSR CONTROL, R0" );
    __asm volatile( "ISB" );
    __asm volatile( "BX R14" );

    __SUPRESS_UNUSED_VAR( address );
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
