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
  * @}  
  * Macros_CILsysTimer_c  
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
  * @}  
  * Variables_CILsysTimer_c  
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
  * @}       
  * Getters_CILsysTimer_c
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
  * @}    
  * Setters_CILsysTimer_c   
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
  * @}
  * General_CILsysTimer_c  
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
  * @fn CILsysTimer_setTicks(BitWidthType ticks, CosmOS_SchedulerSyncStateType schedulersSyncState)
  * 
  * @brief Disable system timer DEMO CODE.
  * 
  * @param[in]  BitWidthType ticks
  * @param[in]  CosmOS_SchedulerSyncStateType schedulersSyncState
  * 
  * @return none
********************************************************************************/
/* @cond S */
__SEC_START(__OS_FUNC_SECTION_START)
/* @endcond*/
__OS_FUNC_SECTION void CILsysTimer_setTicks(BitWidthType ticks, CosmOS_SchedulerSyncStateType schedulersSyncState)
{
    if( schedulersSyncState IS_NOT_EQUAL_TO SCHEDULER_SYNC_STATE_ENUM__IN_SYNC ) 
    {
        BitWidthType delay;
        delay = SysTick->LOAD - SysTick->VAL;
        
        SysTick->LOAD  = (uint32_t)(((ticks*TICKCOUNT)-delay) - 1UL);         /* set reload register */
    }
    else
    {
        SysTick->LOAD  = (uint32_t)(((ticks*TICKCOUNT)) - 1UL);               /* set reload register */
    }

    SysTick->VAL   = 0UL;                                                     /* Load the SysTick Counter Value */
    SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                   SysTick_CTRL_TICKINT_Msk   |
                   SysTick_CTRL_ENABLE_Msk;                                   /* Enable SysTick IRQ and SysTick Timer */
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
