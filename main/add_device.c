#include add_device.h

void add_device {
/* Create a Switch device.
     * You can optionally use the helper API esp_rmaker_switch_device_create() to
     * avoid writing code for adding the name and power parameters.
     */
    switch_device = esp_rmaker_device_create("Switch", ESP_RMAKER_DEVICE_SWITCH, NULL);

    /* Add the write callback for the device. We aren't registering any read callback yet as
     * it is for future use.
     */
    esp_rmaker_device_add_cb(switch_device, write_cb, NULL);

    /* Add the standard name parameter (type: esp.param.name), which allows setting a persistent,
     * user friendly custom name from the phone apps. All devices are recommended to have this
     * parameter.
     */
    esp_rmaker_device_add_param(switch_device, esp_rmaker_name_param_create(ESP_RMAKER_DEF_NAME_PARAM, "Switch"));

    /* Add the standard power parameter (type: esp.param.power), which adds a boolean param
     * with a toggle switch ui-type.
     */
    esp_rmaker_param_t *power_param = esp_rmaker_power_param_create(ESP_RMAKER_DEF_POWER_NAME, DEFAULT_POWER);
    esp_rmaker_device_add_param(switch_device, power_param);

    /* Assign the power parameter as the primary, so that it can be controlled from the
     * home screen of the phone apps.
     */
    esp_rmaker_device_assign_primary_param(switch_device, power_param);

    /* Add this switch device to the node */
    esp_rmaker_node_add_device(node, switch_device);
}