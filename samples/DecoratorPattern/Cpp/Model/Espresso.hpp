#pragma once
/* File generated by Đức's ClasHStamP */
#include "Generic/CommonInclude.h"
#include "Abstracts/Beverage.hpp"                               

class Espresso: public Beverage{
    public: virtual double cost(
    ){
        return 1.99;
    } /* Espresso.cost */
    friend class Main;
    public:  Espresso(
    ):  Beverage( "Espresso" )
    {
    }                                                                                           
};
