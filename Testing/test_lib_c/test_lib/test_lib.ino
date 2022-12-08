#include "libaux.h"
#include <stdio.h>

static magneto4_t magneto4;
static int enc_position;
static int old_position = 255;
static int magnetic_field = 0;
int senor_value = 0;


void setup() {

    printf("USB UART Passed\n");
    delay(1000);
    printf("Application Started\n");
    delay(1000);

   //Click initialization.
   //MAGNETO4_MAP_MIKROBUS( cfg, MIKROBUS_1 );
   //magneto4_init( &magneto4, &cfg );

    printf(" --- Por favor acerque el sensor ---\n" );
    printf(" Ingrese un posible valor de sensor 0-3000 \n" );
    scanf("%i, &sensor_value\n");
    
    magnetic_field = "sensor_value";

    while ( magnetic_field < MAGNETO4_MAX_MAGNETIC_FIELD_VALUE )
    {
      
        printf(" La fuerza del campo magnetico es: %d\n", magnetic_field );
        delay( 1000 );
        printf(" --- Delay 1s ---\n" );
    }
    
    delay( 1500 );
    printf( " --- Encoder inicializado ---\n" );
}


void loop() {
    
    //magneto4_get_encoder_position( &magneto4 );
    
    enc_position = magneto4.encoder_position;

    if ( old_position != enc_position )
    {
        printf( " Encoder position : %d\n", enc_position );
        printf(" ------------------------\n" );
    }
    
    old_position = enc_position;
}