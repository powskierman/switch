#include <string.h>
#include <inttypes.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_log.h>
#include <esp_event.h>
#include <nvs_flash.h>

#include <esp_rmaker_core.h>
#include <esp_rmaker_standard_types.h>
#include <esp_rmaker_standard_params.h>
#include <esp_rmaker_standard_devices.h>
#include <esp_rmaker_schedule.h>
#include <esp_rmaker_scenes.h>
#include <esp_rmaker_console.h>
#include <esp_rmaker_ota.h>

#include <esp_rmaker_common_events.h>

#include <app_wifi.h>
#include <app_insights.h>

#include "app_priv.h"
#include "call_back.h"
#include "event_handler.h"
#include "add_node.h"
#include "add_device.h"

//static const char *TAG = "app_main";

/**
 * The function "add_device" creates a switch device, adds parameters to it, assigns a primary
 * parameter, and adds it to a node.
 * 
 * @param node The "node" parameter is of type "esp_rmaker_node_t" and represents the node to which the
 * device will be added.
 * 
 * @return a pointer to an `esp_rmaker_device_t` structure.
 */
esp_rmaker_device_t* add_device(esp_rmaker_node_t *node) {
    
    esp_rmaker_device_t *switch_device = esp_rmaker_device_create("Michel's Switch", ESP_RMAKER_DEVICE_SWITCH, NULL); /* Creates a switch device using the ESP Rainmaker library. */
    esp_rmaker_device_add_cb(switch_device, write_cb, NULL); /*Posts the device to the Rainmaker cloud*/
    esp_rmaker_device_add_param(switch_device, esp_rmaker_name_param_create(ESP_RMAKER_DEF_NAME_PARAM, "Michel's Parameter"));

    esp_rmaker_param_t *power_param = esp_rmaker_power_param_create(ESP_RMAKER_DEF_POWER_NAME, DEFAULT_POWER);
    esp_rmaker_device_add_param(switch_device, power_param);
    esp_rmaker_device_assign_primary_param(switch_device, power_param);

    esp_rmaker_node_add_device(node, switch_device);
    return switch_device;
}