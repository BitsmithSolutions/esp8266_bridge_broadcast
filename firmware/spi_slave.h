/*
  SPISlave library for esp8266

  Copyright (c) 2015 Hristo Gochkov. All rights reserved.
  This file is part of the esp8266 core for Arduino environment.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
#ifndef _HSPISLAVE_H_INCLUDED
#define _HSPISLAVE_H_INCLUDED

#include "Arduino.h"

//Start SPI SLave
void spi_slave_begin(uint8_t status_len, void * arg);

//set the status register so the master can read it
void spi_slave_set_status(uint32_t status) __attribute__((always_inline));
inline void spi_slave_set_status(uint32_t status)
{
    SPI1WS = status;
}

//set the data registers (max 32 bytes at a time)
void spi_slave_set_data(uint32_t* data) __attribute__((always_inline));
inline void spi_slave_set_data(uint32_t* data)
{
    SPI1W0 = *data++;
    SPI1W1 = *data++;
    SPI1W2 = *data++;
    SPI1W3 = *data++;
    SPI1W4 = *data++;
    SPI1W5 = *data++;
    SPI1W6 = *data++;
    SPI1W7 = *data++;
    SPI1W8 = *data++;
    SPI1W9 = *data++;
    SPI1W10 = *data++;
    SPI1W11 = *data++;
    SPI1W12 = *data++;
    SPI1W13 = *data++;
    SPI1W14 = *data++;
    SPI1W15 = *data;
}

void spi_slave_set_data8(uint8_t* data);

void spi_slave_get_data(uint32_t* data) __attribute__((always_inline));
inline void spi_slave_get_data(uint32_t* data)
{
  *data++ = SPI1W0;
  *data++ = SPI1W1;
  *data++ = SPI1W2;
  *data++ = SPI1W3;
  *data++ = SPI1W4;
  *data++ = SPI1W5;
  *data++ = SPI1W6;
  *data++ = SPI1W7;
  *data++ = SPI1W8;
  *data++ = SPI1W9;
  *data++ = SPI1W10;
  *data++ = SPI1W11;
  *data++ = SPI1W12;
  *data++ = SPI1W13;
  *data++ = SPI1W14;
  *data++ = SPI1W15;
}

//set the callbacks
void spi_slave_on_data(void (*rxd_cb)());
void spi_slave_on_data_sent(void (*txd_cb)());
void spi_slave_on_status(void (*rxs_cb)(uint32_t));
void spi_slave_on_status_sent(void (*txs_cb)(uint32_t data));

#endif
