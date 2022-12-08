
extern "C"
#include "libaux.h"
#include <stdio.h>

static magneto4_t magneto4;
static int enc_position;
static int old_position = 255;
static int magnetic_field = 0;


void setup() {

     //_cfg_t log_cfg;
    magneto4_cfg_t cfg;

    printf("---- USB_UART Passed ----\n" );
    printf("---- Log Init Passed ----\n" );
    printf("---- Application Init ----\n" );

    //  Click initialization.

   //magneto4_cfg_setup( &cfg );
   //MAGNETO4_MAP_MIKROBUS( cfg, MIKROBUS_1 );
   //magneto4_init( &magneto4, &cfg );
   // magneto4_default_cfg ( &magneto4 );
    
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


void loop() {
  
    //  Task implementation.
    
    //magneto4_get_encoder_position( &magneto4 );
    
    enc_position = magneto4.encoder_position;

    if ( old_position != enc_position )
    {
        printf( " Encoder position : %d\n", enc_position );
        printf(" ------------------------\n" );
    }
    
    old_position = enc_position;
}