- The key classes are:

- `add_device` - Creates and configures an `esp_rmaker_device_t` switch device and adds it to a node.
- `add_node` - Initializes an `esp_rmaker_node_t` Rainmaker node.
- `app_driver` - Handles button input and LED output. Accesses `esp_rmaker_param_t` and `esp_rmaker_device_t`.
- `app_main` - Brings together the other classes by initializing WiFi, registering events, and calling `add_node` and `add_device`.
```mermaid
classDiagram
class add_device {
  +esp_rmaker_device_t* add_device(esp_rmaker_node_t *node)
}

class add_node {
  +esp_rmaker_node_t* add_node()
}

class app_driver {
  -g_power_state
  +app_driver_init()
  +app_driver_set_state(bool state)
  +app_driver_get_state() 
}

class app_main {
  -TAG
  -write_cb()
  -switch_device
  +app_main()
}

add_device --> esp_rmaker_device_t
add_device ..> esp_rmaker_node_t

add_node --> esp_rmaker_node_t

app_driver ..> esp_rmaker_param_t
app_driver ..> esp_rmaker_device_t

app_main ..> add_device
app_main ..> add_node
app_main ..> app_driver
```