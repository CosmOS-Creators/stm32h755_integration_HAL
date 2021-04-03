/********************************************************************************
**                                                                             **
**                         COSMOS FILE | CREATED BY HUMAN                      **
**                                                                             **
*********************************************************************************
**                       DOXYGEN DOCUMENTATION INFORMATION                     **
*****************************************************************************//**
** @file CIL_sysTimer.c
*********************************************************************************
<!--                 CIL_sysTimer Unit Local Group Definition                 -->
*********************************************************************************	
** @defgroup Local_CIL_sysTimer Local
** @ingroup CIL_sysTimer_unit 
** @brief CIL_sysTimer locals
** @details lorem 
********************************************************************************/
/********************************************************************************
**                           START OF THE SOURCE FILE                          **
********************************************************************************/
/********************************************************************************
**                            Include Files | Start                            **
********************************************************************************/
/* CIL interfaces */
#include "CIL_sysTimer.h"

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
  * @defgroup Macros_CIL_sysTimer_c Macros
  * @ingroup Local_CIL_sysTimer
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Macros_CIL_sysTimer_c  
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
  * @defgroup Variables_CIL_sysTimer_c Variables  
  * @ingroup Local_CIL_sysTimer
  * @{    
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}  
  * Variables_CIL_sysTimer_c  
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
  * @defgroup Apis_CIL_sysTimer_c API's  
  * @ingroup Local_CIL_sysTimer
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Getters_CIL_sysTimer_c Getters  
  * @ingroup Apis_CIL_sysTimer_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}       
  * Getters_CIL_sysTimer_c
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup Setters_CIL_sysTimer_c Setters  
  * @ingroup Apis_CIL_sysTimer_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}    
  * Setters_CIL_sysTimer_c   
********************************************************************************/
/********************************************************************************
  * DOXYGEN START GROUP                                                        **
  * *************************************************************************//**
  * @addtogroup General_CIL_sysTimer_c General  
  * @ingroup Apis_CIL_sysTimer_c                                            
  * @{                                                                           
********************************************************************************/
/********************************************************************************
  * DOXYGEN STOP GROUP                                                         **
  * *************************************************************************//**
  * @}
  * General_CIL_sysTimer_c  
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
  * @fn CIL_sysTimer_setTicks(BitWidthType ticks, CosmOS_SchedulerSyncStateType schedulersSyncState)
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
__OS_FUNC_SECTION void CIL_sysTimer_setTicks(BitWidthType ticks, CosmOS_SchedulerSyncStateType schedulersSyncState)
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
