/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CILsysTimer.c
*********************************************************************************
<!--                  CILsysTimer Unit Local Group Definition                 -->
*********************************************************************************
** @defgroup Local_CILsysTimer Local
** @ingroup CILsysTimer_unit
** @brief CILsysTimer locals
** @details lorem
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CIL interfaces */
#include "CILsysTimer.h"

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
  * @defgroup Macros_CILsysTimer_c Macros
  * @ingroup Local_CILsysTimer
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Macros_CILsysTimer_c
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
  * @defgroup Variables_CILsysTimer_c Variables
  * @ingroup Local_CILsysTimer
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Variables_CILsysTimer_c
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
  * @defgroup Apis_CILsysTimer_c API's
  * @ingroup Local_CILsysTimer
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_CILsysTimer_c Getters
  * @ingroup Apis_CILsysTimer_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Getters_CILsysTimer_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_CILsysTimer_c Setters
  * @ingroup Apis_CILsysTimer_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  Setters_CILsysTimer_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_CILsysTimer_c General
  * @ingroup Apis_CILsysTimer_c
  * @{
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @} */
/*  General_CILsysTimer_c
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
  * @fn CILsysTimer_startTimer(BitWidthType ticks, BitWidthType timerTickCount)
  *
  * @details The implementation contains configuration of system timer. The load
  * value is calculated as ticks multiplied by the timerTickCount that represents
  * value that has to be loaded to the timer to set it for one tick. Then the
  * current timer value is set to zero and the timer is enabled.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
CILsysTimer_startTimer( BitWidthType ticks, BitWidthType timerTickCount )
{
    SysTick->LOAD = ( uint32_t )( ( ( ticks * timerTickCount ) ) - 1UL );
    SysTick->VAL = 0UL;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk |
                    SysTick_CTRL_ENABLE_Msk;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILsysTimer_setTicks(
  * BitWidthType ticks,
  * BitWidthType timerTickCount,
  * BitWidthType timerOffset )
  *
  * @details The implementation contains configuration of system timer. First of
  * all the timer is disabled. Then load value is calculated as ticks multiplied
  * by the timerTickCount that represents value that has to be loaded to the
  * timer to set it for one tick. From this value is subtracted the delay value
  * which represents the time we spent in the scheduling algorithm. Then the
  * current timer value is set to zero and the timer is enabled.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
CILsysTimer_setTicks(
    BitWidthType ticks,
    BitWidthType timerTickCount,
    BitWidthType timerOffset )
{
    SysTick->CTRL = 0;

    SysTick->LOAD = ( uint32_t )(
        ( ( ( ticks * timerTickCount ) - 1UL ) -
          ( ( SysTick->LOAD - SysTick->VAL ) + timerOffset ) ) );

    SysTick->VAL = 0UL;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk |
                    SysTick_CTRL_ENABLE_Msk;
}
/* @cond S */
__SEC_STOP( __OS_FUNC_SECTION_STOP )
/* @endcond*/

/********************************************************************************
  * DOXYGEN DOCUMENTATION INFORMATION                                          **
  * ****************************************************************************/
/**
  * @fn CILsysTimer_setTicksSaveOffset(
  * BitWidthType ticks,
  * BitWidthType timerTickCount,
  * AddressType * timerOffset )
  *
  * @details The implementation contains configuration of system timer. First of
  * all the timer is disabled. Then load value is calculated as ticks multiplied
  * by the timerTickCount that represents value that has to be loaded to the
  * timer to set it for one tick. From this value is subtracted the delay value
  * which represents the time we spent in the scheduling algorithm and this value
  * is also saved to the timerOffset address. Then the
  * current timer value is set to zero and the timer is enabled.
********************************************************************************/
/* @cond S */
__SEC_START( __OS_FUNC_SECTION_START )
/* @endcond*/
__OS_FUNC_SECTION void
CILsysTimer_setTicksSaveOffset(
    BitWidthType ticks,
    BitWidthType timerTickCount,
    AddressType * timerOffset )
{
    SysTick->CTRL = 0;

    *timerOffset = ( BitWidthType )( SysTick->LOAD - SysTick->VAL );

    SysTick->LOAD = ( uint32_t )(
        ( ( ( ticks * timerTickCount ) - 1UL ) - ( *timerOffset ) ) );

    SysTick->VAL = 0UL;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk |
                    SysTick_CTRL_ENABLE_Msk;
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
