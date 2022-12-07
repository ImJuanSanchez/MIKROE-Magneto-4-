/*!
 * \file 
 * \brief Magneto4 Click example
 * 
 * # Description
 * Reads and logs magnetic field strength values
 * if magnetic field strength values bigger than 3000, 
 * start magnetic linear position mode,   
 * when moving the sensor from left to right the position for 1 step is reduced.
 *
 * The demo application is composed of two sections :
 * 
 * ## Application Setup 
 * Initializes Driver init and sets start encoder position on the zero.
 * Reads and logs magnetic field strength values.
 * For starting an encoder, it is necessary that the magnetic field strength 
 * is greater than 3000.
 * 
 * ## Application Loop  
 * When moving the sensor from left to right, one step is added 
 * and when moving from right to left, the position for 1 step is reduced.
 * 
 * \author Luka Filipovic
 *
 */
// ------------------------------------------------------------------- INCLUDES

//#include "board.h"
//#include "log.h"
#include "magneto4.h"
#include <stdio.h>
// ------------------------------------------------------------------ VARIABLES

static magneto4_t magneto4;
static int enc_position;
static int old_position = 255;
static int magnetic_field = 0;

// ------------------------------------------------------ APPLICATION FUNCTIONS

void application_setup ( void )
{
    //_cfg_t log_cfg;
    magneto4_cfg_t cfg;

    printf("---- USB_UART Passed ----\n" );
    printf("---- Log Init Passed ----\n" );
    printf("---- Application Init ----\n" );

    //  Click initialization.

    magneto4_cfg_setup( &cfg );
    MAGNETO4_MAP_MIKROBUS( cfg, MIKROBUS_1 );
    magneto4_init( &magneto4, &cfg );
    
    magneto4_default_cfg ( &magneto4 );
    
    printf(" --- Please, bring the magnet close ---\n" );

    while ( magnetic_field < MAGNETO4_MAX_MAGNETIC_FIELD_VALUE )
    {
        magnetic_field = magneto4_get_magnetic_field( &magneto4 );
        printf(" Magnetic field strength : %d\n", magnetic_field );
        //Delay( 1000 );
        printf(" --- Delay 1s ---\n" );
    }
    
    //Delay( 1500 );
    printf( " --- Magnetic Linear Position ---\n" );
}





void application_loop ( void )
{
    //  Task implementation.
    
    magneto4_get_encoder_position( &magneto4 );
    
    enc_position = magneto4.encoder_position;

    if ( old_position != enc_position )
    {
        printf( " Encoder position : %d\n", enc_position );
        printf(" ------------------------\n" );
    }
    
    old_position = enc_position;
}





void main ( int argc, const char * argv[] )
{
    application_setup( );

    for ( ; ; )
    {
        application_loop( );
    }
    return 0;
}

