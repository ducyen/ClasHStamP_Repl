#define __Main_INTERNAL__
#include <stdio.h>
#include <string.h>
#include "CommonInclude.h"

#include "WeatherData.h"
#include "CurrentConditionDisplay.h"


String StrCat( String dest, char* src ){
    strcat(dest->buf, src);
    return dest;
}

int main(){
    #if 1
    WeatherData weatherData = WeatherData_Ctor( WeatherData_Init(
        { P(
            ( ObserverIfc* )&CurrentConditionDisplay_Ctor( CurrentConditionDisplay_Init( ( Subject* )&weatherData ), ),
            ( ObserverIfc* )&CurrentConditionDisplay_Ctor( CurrentConditionDisplay_Init( ( Subject* )&weatherData ), )
        ) }
    ), );
    #else
    WeatherData weatherData = ( WeatherData ){  
		.vTbl = &gWeatherDataVtbl, 
		.temperature = 0, 
		.humidity = 0, 
		.pressure = 0, 
		.observers = { 
			( Observer* )&( CurrentConditionDisplay ){ 
				.vTbl = &gCurrentConditionDisplayVtbl, 
				.temperature = 0, 
				.humidity = 0, 
				.weatherData = ( Subject* )&weatherData,
			} 
		},
	};
    #endif

	WeatherData_setMeasurements( &weatherData, 27, 65, 30.4f);
	WeatherData_setMeasurements( &weatherData, 28, 70, 29.2f);
	WeatherData_setMeasurements( &weatherData, 26, 90, 29.2f);


    return 0;
}
