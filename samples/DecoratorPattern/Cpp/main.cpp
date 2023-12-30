#include <iostream>
#include <cassert>
#include <string>

int InputValue(char* pMsg);
void DisplayMsg(char* pMsg);

#include "Generic/Statemachine.h"
#include "Model/DarkRoast.hpp"
#include "Model/Espresso.hpp"
#include "Model/HouseBlend.hpp"
#include "Model/Mocha.hpp"
#include "Model/Soy.hpp"
#include "Model/Whip.hpp"

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
    Beverage *beverage = new Espresso();
    std::cout << (String)beverage->m_description << " $" << beverage->cost() << std::endl;
    
    Beverage *beverage2 = new DarkRoast();
    beverage2 = new Mocha(beverage2);
    beverage2 = new Mocha(beverage2);
    beverage2 = new Whip(beverage2);
    std::cout << (String)beverage2->m_description << " $" << beverage2->cost() << std::endl;
    
    Beverage *beverage3 = new HouseBlend();
    beverage3 = new Soy(beverage3);
    beverage3 = new Mocha(beverage3);
    beverage3 = new Whip(beverage3);
    std::cout << (String)beverage3->m_description << " $" << beverage3->cost() << std::endl;
    
    delete beverage;
    delete beverage2;
    delete beverage3;

    return 0;

}
