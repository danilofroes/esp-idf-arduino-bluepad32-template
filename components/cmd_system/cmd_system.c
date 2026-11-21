/* Console example — various system commands

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include "cmd_system.h"

#include <ctype.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <argtable3/argtable3.h>
#include <driver/rtc_io.h>
#include <driver/uart.h>
#include <driver/gpio.h>
#include <esp_chip_info.h>
#include <esp_console.h>
#include <esp_flash.h>
#include <esp_log.h>
#include <esp_sleep.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "sdkconfig.h"

void register_system(void) {
    register_system_common();

#if SOC_LIGHT_SLEEP_SUPPORTED
    register_system_light_sleep();
#endif

#if SOC_DEEP_SLEEP_SUPPORTED
    register_system_deep_sleep();
#endif
}
