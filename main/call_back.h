#ifndef CALL_BACK_H_
#define CALL_BACK_H_

esp_err_t write_cb(const esp_rmaker_device_t *device, const esp_rmaker_param_t *param,
            const esp_rmaker_param_val_t val, void *priv_data, esp_rmaker_write_ctx_t *ctx);

#endif /* CALL_BACK_H_ */