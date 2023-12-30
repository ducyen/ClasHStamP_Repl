#define __Main_INTERNAL__
#include <stdio.h>

int InputValue(char* pMsg);
void DisplayMsg(char* pMsg);

#include "CommonInclude.h"
#include "Sensor.h"

int InputValue(char* pMsg) {
    char n;
    printf( pMsg );
    scanf_s( "%c", &n );
    char c = 0;
    while( c != '\n' ){
        scanf_s( "%c", &c );
    }
    return n - '0';
}

void DisplayMsg(char* pMsg) {
    printf( "%s\n", pMsg );
}

int main( void ){
	Sensor sensor = Sensor_Ctor( Sensor_Init(0) );
    for (int i = 0; i < Sensor_EVENT_NUM; i++) {
        printf("Input %u for %s\n", i, SensorEvent_toString( i ) );
    }
	int n;
	do {
        Sensor_Start(&sensor);
	    do {
            n = InputValue( "Enter event number('q': quit, 'r':restart): E" );
	        Sensor_EventProc(&sensor, n, null);
	    } while (n+'0' != 'q' && n+'0' != 'r');
	}while (n+'0' != 'q');

    return 0;
}

