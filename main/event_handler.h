#ifndef EVENT_HANDLER_H_
#define EVENT_HANDLER_H_

void event_handler(void* arg, esp_event_base_t event_base,
                          int32_t event_id, void* event_data);
                          
#endif /* EVENT_HANDLER_H_ */