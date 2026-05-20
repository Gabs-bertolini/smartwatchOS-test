# ESP32-S3 AMOLED Unit Tests

Primeiro projeto funcional no ESP32-S3-Touch-AMOLED-2.06 usando ESP-IDF + LVGL.

O objetivo deste repositório foi simplesmente conseguir:
- compilar corretamente
- inicializar o display AMOLED
- integrar a BSP da Waveshare
- configurar LVGL
- exibir um "Hello World" na tela
- futuramente adicionando features até completar uma "OS" totalmente funcional

## Hardware

- Board: Waveshare ESP32-S3-Touch-AMOLED-2.06
- MCU: ESP32-S3
- Display driver: CO5300
- Touch driver: FT3168

## Stack utilizada

- ESP-IDF
- LVGL
- Waveshare BSP

## Problemas encontrados

### Dependências quebradas
Tive vários problemas de compatibilidade entre:
- ESP-IDF
- componentes da Waveshare
- LVGL
- toolchain

### Flash acidental do firmware original
Durante os testes sobrescrevi parcialmente o firmware original do smartwatch.
Consegui recuperar restaurando um backup completo da flash usando `esptool`.

### Display não inicializava
O display AMOLED utiliza QSPI e não SPI convencional.
Foi necessário utilizar a BSP oficial da Waveshare para inicialização correta.

## Comandos úteis

### Backup da flash

```bash
esptool --chip esp32s3 read_flash 0 0x2000000 backup.bin