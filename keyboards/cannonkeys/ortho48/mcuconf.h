/* Copyright 2020 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
<<<<<<< HEAD
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
=======
 * DMA priorities:
 * 0...3        Lowest...Highest.
 */

/*
 * HAL driver system settings.
 */
#define STM32_NO_INIT                       FALSE
#define STM32_HSI_ENABLED                   TRUE
#define STM32_LSI_ENABLED                   FALSE
#define STM32_HSE_ENABLED                   TRUE
#define STM32_LSE_ENABLED                   FALSE
#define STM32_SW                            STM32_SW_PLL
#define STM32_PLLSRC                        STM32_PLLSRC_HSE
#define STM32_PLLXTPRE                      STM32_PLLXTPRE_DIV1
#define STM32_PLLMUL_VALUE                  9
#define STM32_HPRE                          STM32_HPRE_DIV1
#define STM32_PPRE1                         STM32_PPRE1_DIV2
#define STM32_PPRE2                         STM32_PPRE2_DIV2
#define STM32_ADCPRE                        STM32_ADCPRE_DIV4
#define STM32_USB_CLOCK_REQUIRED            TRUE
#define STM32_USBPRE                        STM32_USBPRE_DIV1P5
#define STM32_MCOSEL                        STM32_MCOSEL_NOCLOCK
#define STM32_RTCSEL                        STM32_RTCSEL_HSEDIV
#define STM32_PVD_ENABLE                    FALSE
#define STM32_PLS                           STM32_PLS_LEV0

/*
 * ADC driver system settings.
 */
#define STM32_ADC_USE_ADC1                  FALSE
#define STM32_ADC_ADC1_DMA_PRIORITY         2
#define STM32_ADC_ADC1_IRQ_PRIORITY         6

/*
 * CAN driver system settings.
 */
#define STM32_CAN_USE_CAN1                  FALSE
#define STM32_CAN_CAN1_IRQ_PRIORITY         11

/*
 * EXT driver system settings.
 */
#define STM32_EXT_EXTI0_IRQ_PRIORITY        6
#define STM32_EXT_EXTI1_IRQ_PRIORITY        6
#define STM32_EXT_EXTI2_IRQ_PRIORITY        6
#define STM32_EXT_EXTI3_IRQ_PRIORITY        6
#define STM32_EXT_EXTI4_IRQ_PRIORITY        6
#define STM32_EXT_EXTI5_9_IRQ_PRIORITY      6
#define STM32_EXT_EXTI10_15_IRQ_PRIORITY    6
#define STM32_EXT_EXTI16_IRQ_PRIORITY       6
#define STM32_EXT_EXTI17_IRQ_PRIORITY       6
#define STM32_EXT_EXTI18_IRQ_PRIORITY       6
#define STM32_EXT_EXTI19_IRQ_PRIORITY       6

/*
 * GPT driver system settings.
 */
#define STM32_GPT_USE_TIM1                  FALSE
#define STM32_GPT_USE_TIM2                  FALSE
#define STM32_GPT_USE_TIM3                  FALSE
#define STM32_GPT_USE_TIM4                  FALSE
#define STM32_GPT_USE_TIM5                  FALSE
#define STM32_GPT_USE_TIM8                  FALSE
#define STM32_GPT_TIM1_IRQ_PRIORITY         7
#define STM32_GPT_TIM2_IRQ_PRIORITY         7
#define STM32_GPT_TIM3_IRQ_PRIORITY         7
#define STM32_GPT_TIM4_IRQ_PRIORITY         7
#define STM32_GPT_TIM5_IRQ_PRIORITY         7
#define STM32_GPT_TIM8_IRQ_PRIORITY         7

/*
 * I2C driver system settings.
 */
#define STM32_I2C_USE_I2C1                  TRUE
#define STM32_I2C_USE_I2C2                  FALSE
#define STM32_I2C_BUSY_TIMEOUT              50
#define STM32_I2C_I2C1_IRQ_PRIORITY         5
#define STM32_I2C_I2C2_IRQ_PRIORITY         5
#define STM32_I2C_I2C1_DMA_PRIORITY         3
#define STM32_I2C_I2C2_DMA_PRIORITY         3
#define STM32_I2C_DMA_ERROR_HOOK(i2cp)      osalSysHalt("DMA failure")

/*
 * ICU driver system settings.
 */
#define STM32_ICU_USE_TIM1                  FALSE
#define STM32_ICU_USE_TIM2                  FALSE
#define STM32_ICU_USE_TIM3                  FALSE
#define STM32_ICU_USE_TIM4                  FALSE
#define STM32_ICU_USE_TIM5                  FALSE
#define STM32_ICU_USE_TIM8                  FALSE
#define STM32_ICU_TIM1_IRQ_PRIORITY         7
#define STM32_ICU_TIM2_IRQ_PRIORITY         7
#define STM32_ICU_TIM3_IRQ_PRIORITY         7
#define STM32_ICU_TIM4_IRQ_PRIORITY         7
#define STM32_ICU_TIM5_IRQ_PRIORITY         7
#define STM32_ICU_TIM8_IRQ_PRIORITY         7

/*
 * PWM driver system settings.
 */
#define STM32_PWM_USE_ADVANCED              FALSE
#define STM32_PWM_USE_TIM1                  TRUE
#define STM32_PWM_USE_TIM2                  FALSE
#define STM32_PWM_USE_TIM3                  FALSE
#define STM32_PWM_USE_TIM4                  FALSE
#define STM32_PWM_USE_TIM5                  FALSE
#define STM32_PWM_USE_TIM8                  FALSE
#define STM32_PWM_TIM1_IRQ_PRIORITY         7
#define STM32_PWM_TIM2_IRQ_PRIORITY         7
#define STM32_PWM_TIM3_IRQ_PRIORITY         7
#define STM32_PWM_TIM4_IRQ_PRIORITY         7
#define STM32_PWM_TIM5_IRQ_PRIORITY         7
#define STM32_PWM_TIM8_IRQ_PRIORITY         7

/*
 * RTC driver system settings.
>>>>>>> c7c6988ef5dff46dc14b5277040494b80fa7c8e9
 */

/*
 * This file was auto-generated by:
 *    `qmk chibios-confmigrate -i keyboards/cannonkeys/ortho48/mcuconf.h -r platforms/chibios/STM32_F103_STM32DUINO/configs/mcuconf.h`
 */

#pragma once

#include_next <mcuconf.h>

#undef STM32_PWM_USE_TIM1
#define STM32_PWM_USE_TIM1 TRUE

