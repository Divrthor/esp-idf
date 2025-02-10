/*
 * SPDX-FileCopyrightText: 2022-2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <stdbool.h>
#include "esp_err.h"
#include "soc/clk_tree_defs.h"
#include "soc/soc_caps.h"
#include "soc/io_mux_reg.h"
#include "hal/gpio_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#if SOC_LP_IO_CLOCK_IS_INDEPENDENT
typedef struct {
    uint8_t rtc_io_enabled_cnt[MAX_RTC_GPIO_NUM];
    uint32_t rtc_io_using_mask;
} rtc_io_status_t;

/**
 * Enable/Disable LP_IO peripheral clock.
 * @param gpio_num GPIO number
 * @param enable   true to enable the clock / false to disable the clock
 */
void io_mux_enable_lp_io_clock(gpio_num_t gpio_num, bool enable);

/**
 * Force disable one LP_IO to clock dependency
 * @param gpio_num GPIO number
 */
void io_mux_force_disable_lp_io_clock(gpio_num_t gpio_num);
#endif

#ifdef __cplusplus
}
#endif
