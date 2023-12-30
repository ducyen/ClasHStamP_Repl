#include <iostream>
#include <cassert>
#include <string>

int InputValue(char* pMsg);
void DisplayMsg(char* pMsg);

#include "Generic/Statemachine.h"
#include "Model/AirspeedSensor.hpp"


int _InputValue(String pMsg) {
    char n;
    std::cout << pMsg;
    std::cin  >> n;
    return n - '0';
}

void _DisplayMsg(String pMsg) {
    std::cout << pMsg << std::endl;
}

int main() {
	// TODO Auto-generated method stub
	AirspeedSensor context(0);
    for (int i = 0; i < (int)AirspeedSensor::_EventId::evNum; i++) {
        std::cout << "Input " << i << " for " << context.EventId_toString((AirspeedSensor::_EventId)i) << std::endl;
    }
	int n;
	do {
	    context.Start();
	    do {
	        n = InputValue((String)"Enter event number('q': quit, 'r':restart): E");
	        context.EventProc(n, null);
	    } while (n+'0' != 'q' && n+'0' != 'r');
	}while (n+'0' != 'q');

    return 0;

}
