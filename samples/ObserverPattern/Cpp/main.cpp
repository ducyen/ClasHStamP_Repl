#include <iostream>
#include <cassert>
#include <string>

int InputValue(char* pMsg);
void DisplayMsg(char* pMsg);

#include "Generic/Statemachine.h"
#include "Model/WeatherData.hpp"
#include "Model/CurrentConditionDisplay.hpp"


int InputValue(String pMsg) {
    char n;
    std::cout << pMsg;
    std::cin  >> n;
    return n - '0';
}

void DisplayMsg(String pMsg) {
    std::cout << pMsg << std::endl;
}

int main() {
	// TODO Auto-generated method stub
	WeatherData weatherData;
		
	CurrentConditionDisplay currentDisplay(&weatherData);
		
	weatherData.setMeasurements(27, 65, 30.4f);
	weatherData.setMeasurements(28, 70, 29.2f);
	weatherData.setMeasurements(26, 90, 29.2f);


    return 0;

}
