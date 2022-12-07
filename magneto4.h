/*
 * MikroSDK - MikroE Software Development Kit
 * Copyright© 2020 MikroElektronika d.o.o.
 * 
 * Permission is hereby granted, free of charge, to any person 
 * obtaining a copy of this software and associated documentation 
 * files (the "Software"), to deal in the Software without restriction, 
 * including without limitation the rights to use, copy, modify, merge, 
 * publish, distribute, sublicense, and/or sell copies of the Software, 
 * and to permit persons to whom the Software is furnished to do so, 
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE 
 * OR OTHER DEALINGS IN THE SOFTWARE. 
 */

/*!
 * \file
 *
 * \brief This file contains API for MAGNETO 4 Click driver.
 *
 * \addtogroup magneto4 MAGNETO 4 Click Driver
 * @{
 */
// ----------------------------------------------------------------------------

#ifndef MAGNETO4_H
#define MAGNETO4_H

//#include "drv_digital_out.h"
//#include "drv_digital_in.h"
//#include "drv_spi_master.h"


// -------------------------------------------------------------- PUBLIC MACROS 
/**
 * \defgroup macros Macros
 * \{
 */

/**
 * \defgroup map_mikrobus MikroBUS
 * \{
 */

#define MAGNETO4_MAP_MIKROBUS( cfg, mikrobus )      \
   cfg.miso  = MIKROBUS( mikrobus, MIKROBUS_MISO ); \
   cfg.mosi  = MIKROBUS( mikrobus, MIKROBUS_MOSI ); \
   cfg.sck   = MIKROBUS( mikrobus, MIKROBUS_SCK );  \
   cfg.cs    = MIKROBUS( mikrobus, MIKROBUS_CS );   \
   cfg.a     = MIKROBUS( mikrobus, MIKROBUS_AN );   \
   cfg.b     = MIKROBUS( mikrobus, MIKROBUS_RST );  \
   cfg.ind = MIKROBUS( mikrobus, MIKROBUS_INT )
/** \} */

/**
 * \defgroup error_code Error Code
 * \{
 */
#define MAGNETO4_RETVAL  uint8_t

#define MAGNETO4_OK           0x00
#define MAGNETO4_INIT_ERROR   0xFF
/** \} */

/**
 * \defgroup encoder_zero Encoder zero
 * \{
 */
#define MAGNETO4_ENCODER_TO_ZERO_POSITION  0
/** \} */

/**
 * \defgroup max_mag_val Maximum magnetic fiield value
 * \{
 */
#define MAGNETO4_MAX_MAGNETIC_FIELD_VALUE  3000
/** \} */

/** \} */ // End group macro 
// --------------------------------------------------------------- PUBLIC TYPES
/**
 * \defgroup type Types
 * \{
 */

/**
 * @brief Click ctx object definition.
 */
typedef struct
{
    digital_out_t cs;

    // Input pins 

    int a_in;
    int b_in;
    int pwm_in;
    int ind_in;
    
    // Modules 

    int spi_module;
    int chip_select_module;

    // ctx variable
    
    int encoder_position;
    int a_edge;
    int b_edge;
    int state_a;
    int state_b;

} magneto4_t;

/**
 * @brief Click configuration structure definition.
 */
typedef struct
{
    // Communication gpio pins 

    int miso;
    int mosi;
    int sck;
    int cs;

    // Additional gpio pins 

    int a_gpio_pin;
    int b_gpio_pin;
    int pwm_gpio_pin;
    int ind_gpio_pin;

    // static variable 

    int spi_speed;
    int spi_mode;
    int cs_polarity;

} magneto4_cfg_t;

/**
 * @brief Click magnetic status structure definition.
 */
typedef struct
{
    int dec_val;
    int inc_val;
    int lin_val;
    int cof_val;
    int ocf_val;

} mag_status_t;

/** \} */ // End types group

// ----------------------------------------------- PUBLIC FUNCTION DECLARATIONS

/**
 * \defgroup public_function Public function
 * \{
 */
#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief Config Object Initialization function.
 *
 * @param cfg  Click configuration structure.
 *
 * @description This function initializes click configuration structure to init state.
 * @note All used pins will be set to unconnected state.
 */
void magneto4_cfg_setup ( magneto4_cfg_t *cfg );

/**
 * @brief Initialization function.
 * @param magneto4 Click object.
 * @param cfg Click configuration structure.
 * 
 * @description This function initializes all necessary pins and peripherals used for this click.
 */
MAGNETO4_RETVAL magneto4_init ( magneto4_t *ctx, magneto4_cfg_t *cfg );

/**
 * @brief Click Default Configuration function.
 *
 * @param ctx  Click object.
 *
 * @description This function executes default configuration for Magneto4 click.
 * @note Set start encoder position to zero position and
 * first read of magnetic field strength. 
 */
//void magneto4_default_cfg ( magneto4_t *ctx );

/**
 * @brief Generic transfer function.
 *
 * @param ctx          Click object.
 * @param wr_buf       Write data buffer
 * @param wr_len       Number of byte in write data buffer
 * @param rd_buf       Read data buffer
 * @param rd_len       Number of byte in read data buffer
 *
 * @description Generic SPI transfer, for sending and receiving packages
 */
//void magneto4_generic_transfer 
( 
   // magneto4_t *ctx, 
   // uint8_t *rd_buf, 
   // uint16_t rd_len 
);

/**
 * @brief Get A ( AN ) pin status.
 * 
 * @param ctx          Click object.
 * 
 * @return A pin state:
 * <pre>
 * - 0 : low;
 * - 1 : high;
 *</pre>
 * 
 * @description Functions for get A ( AN ) pin status.
 */
//int magneto4_get_out_a ( magneto4_t *ctx );

/**
 * @brief Get B ( RST ) pin status.
 * 
 * @param ctx          Click object.
 * 
 * @return B pin state:
 * <pre>
 * - 0 : low;
 * - 1 : high;
 *</pre>
 * 
 * @description Functions for get B ( RST ) pin status. 
 */
//int magneto4_get_out_b ( magneto4_t *ctx );

/**
 * @brief Get IND ( interrupt ) pin status.
 * 
 * @param ctx          Click object.
 * 
 * @return IND pin state:
 * <pre>
 * - 0 : low;
 * - 1 : high;
 *</pre>
 * 
 * @description Functions for get IND ( interrupt ) pin status. 
 */
//int magneto4_get_index ( magneto4_t *ctx );

/**
 * @brief Measurement function
 *
 * @param ctx          Click object.
 * 
 * @return 24-bit read data form SPI.
 *
 * @description This function reading 24-bit data from the SPI.
 */
//int magneto4_start_measurement ( magneto4_t *ctx );

/**
 * @brief Measurement Field
 * 
 * @param ctx          Click object.
 *
 * @return 12-bit data ( magnetic field strength ).
 *
 * @description This function measure magnetic field strength.
 * Use this function to detect the presence of a magnet.
 */
int magneto4_get_magnetic_field ( magneto4_t *ctx );

/**
 * @brief Get Magnetic measurement status
 * 
 * @param ctx          Click object.
 * @param mag_status   Structure that contains status information.
 * 
 * @return 8-bit magnetic status data.
 * 
 * @description This function gets magnetic measurement status data. 
 */
int magneto4_get_magnetic_status ( magneto4_t *ctx, mag_status_t *mag_status );

/**
 * @brief Encoder direction
 *
 * @param ctx          Click object.
 * 
 * @return direction
 * <pre>
 * - 0 : no movement;
 * - 1 : right to left direction;
 * - 2 : left to right direction;
 * </pre>
 *
 * @description This function gives you information on the direction of the magnet movement.
 */
//int magneto4_get_encoder_direction ( magneto4_t *ctx, mag_status_t *mag_status );

/**
 * @brief Encoder position
 * 
 * @param ctx          Click object.
 *
 * @return 32-bit signed magnetics linear position of the sensor
 * 
 * @description This function get encoder position.
 */
void magneto4_get_encoder_position ( magneto4_t *ctx );

/**
 * @brief Set start encoder position
 *
 * @param ctx          Click object.
 * @param encoder_pos  Start encoder position.
 *
 * @description Use this function to set the start position of the encoder.
 * If this function is not called - the start position encoder will be 0.
 */
//void magneto4_set_start_position ( magneto4_t *ctx, int32_t encoder_pos );

#ifdef __cplusplus
}
#endif
#endif  // _MAGNETO4_H_

/** \} */ // End public_function group
/// \}    // End click Driver group  
/*! @} */
// ------------------------------------------------------------------------- END
