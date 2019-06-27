/**
  *@file atmel_start_abstract.h
  *@brief Abstraction header for Atmel MCUs using the Atmel Start framework
  *@author Jason Berger
  *@date 2/18/2019
  */

#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <freertos/semphr.h>

#include <esp_log.h>


//Delay Abstraction
#define MRT_DELAY_MS(ms) vTaskDelay(ms)

//Uart Abstraction
// typedef struct io_descriptor* mrt_uart_handle_t;
// #define MRT_UART_TX(handle, data, len, timeout) io_write(handle, data, len)
// #define MRT_UART_RX(handle, data, len, timeout) io_read(handle, data, len)

//GPIO Abstraction
// typedef uint8_t mrt_gpio_t;
// typedef enum gpio_port mrt_gpio_port_t;
// #define MRT_GPIO_WRITE(pin,val) gpio_set_pin_level(pin,val)
// #define MRT_GPIO_READ(pin) gpio_get_pin_level(pin)
// #define MRT_GPIO_PORT_WRITE(port, mask, val) gpio_set_port_level(port, mask, val)
// #define MRT_GPIO_PORT_READ(port) gpio_get_port_level(port)

//I2C Abstraction
//typedef io_descriptor* mrt_i2c_handle_t;
//typedef int32_t mrt_i2c_status_t;
//#define MRT_I2C_MASTER_TRANSMIT(handle ,addr,data,len, stop, timeout)
//#define MRT_I2C_MASTER_RECEIVE(handle ,addr, data, len, stop, timeout)
//#define MRT_I2C_MEM_WRITE(handle, addr, mem_addr, mem_size, data, len, timeout ) i2c_m_sync_cmd_write(handle, mem_addr, data, len)
//#define MRT_I2C_MEM_READ(handle, addr, mem_addr, mem_size, data, len, timeout ) i2c_m_sync_cmd_read(handle, mem_addr, data, len)


//SPI Abstraction
//typedef struct io_descriptor* mrt_spi_handle_t;
//typedef int32_t mrt_spi_status_t;
//mrt_spi_status_t MRT_SPI_TRANSFER(mrt_spi_handle_t handle , uint8_t* x, uint8_t* rx , len, timeout);
//#define MRT_SPI_TRANSFER(handle ,tx, rx ,len, timeout)  io_write(handle, tx, len)
//#define MRT_SPI_TRANSMIT(handle, tx, len, timeout) io_write(handle, tx, len)
//#define MRT_SPI_RECIEVE(handle, tx, len, timeout) spi_m_sync_transfer(handle, &((struct spi_xfer){tx,tx,len}))


//Mutex Abstraction
#define MRT_MUTEX_TYPE SemaphoreHandle_t
#define MRT_MUTEX_CREATE(m) (m) = xSemaphoreCreateMutex()
#define MRT_MUTEX_LOCK(m) xSemaphoreTake((m), portMAX_DELAY)
#define MRT_MUTEX_UNLOCK(m) xSemaphoreGive((m))
#define MRT_MUTEX_DELETE(m) vSemaphoreDelete((m))



//printf
#define MRT_PRINTF(f_, ...) printf((f_), __VA_ARGS__)
