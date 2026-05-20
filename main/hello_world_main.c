/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"
 
#include "bsp/esp32_s3_touch_amoled_2_06.h"
#include "lvgl.h"
#include "esp_log.h"
static const char *TAG = "hello_world";

void app_main(void)
{
    esp_log_level_set(TAG, ESP_LOG_INFO);

    ESP_LOGI(TAG, "Starting BSP display...");

    /* Start display and LVGL handling provided by Waveshare BSP */
    lv_display_t *disp = bsp_display_start();
    if (disp == NULL) {
        ESP_LOGE(TAG, "bsp_display_start() failed");
        return;
    }

    /* Create a simple LVGL label with "Hello World" centered on screen. */
    if (!bsp_display_lock(1000)) {
        ESP_LOGW(TAG, "Could not lock LVGL, continuing anyway");
    }

    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello World!!!");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    bsp_display_unlock();

    ESP_LOGI(TAG, "Displayed 'Hello World' on screen.");

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
