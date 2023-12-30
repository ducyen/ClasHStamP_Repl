#define __Main_INTERNAL__
#include <stdio.h>

int InputValue(char* pMsg);
void DisplayMsg(char* pMsg);

#include "CommonInclude.h"
#include "AirspeedSensor.h"

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
	AirspeedSensor context = AirspeedSensor_Ctor( AirspeedSensor_Init(0) );
    for (int i = 0; i < AirspeedSensor_EVENT_NUM; i++) {
        printf("Input %u for %s\n", i, AirspeedSensorEvent_toString( i ) );
    }
	int n;
	do {
        AirspeedSensor_Start(&context);
	    do {
            n = InputValue( "Enter event number('q': quit, 'r':restart): E" );
	        AirspeedSensor_EventProc(&context, n, null);
	    } while (n+'0' != 'q' && n+'0' != 'r');
	}while (n+'0' != 'q');

    return 0;
}

