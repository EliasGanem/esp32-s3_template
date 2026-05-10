#include "driver/gpio.h"
#include "esp_flash.h"
#include "esp_heap_caps.h"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>

// Ajustá este número según el LED de tu placa (suele ser el 2 o el 15)
#define BLINK_GPIO GPIO_NUM_2

void app_main(void) {
  printf("\n--- Test de Hardware ESP32-S3-16-R8 ---\n");

  // 1. Verificar Flash
  uint32_t flash_size;
  if (esp_flash_get_size(NULL, &flash_size) == ESP_OK) {
    printf("Tamaño de Flash: %lu MB\n", flash_size / (1024 * 1024));
  }

  // 2. Verificar PSRAM (Memoria Externa de 8MB)
  size_t psram_total = heap_caps_get_total_size(MALLOC_CAP_SPIRAM);
  size_t psram_free = heap_caps_get_free_size(MALLOC_CAP_SPIRAM);
  printf("PSRAM Total: %d bytes (~%d MB)\n", psram_total,
         psram_total / (1024 * 1024));
  printf("PSRAM Libre: %d bytes\n", psram_free);

  // 3. Configurar GPIO para el Blink
  gpio_reset_pin(BLINK_GPIO);
  gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

  while (1) {
    printf("Blink! Memoria interna libre: %lu bytes\n",
           esp_get_free_heap_size());

    gpio_set_level(BLINK_GPIO, 1);
    vTaskDelay(pdMS_TO_TICKS(1000));

    gpio_set_level(BLINK_GPIO, 0);
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}