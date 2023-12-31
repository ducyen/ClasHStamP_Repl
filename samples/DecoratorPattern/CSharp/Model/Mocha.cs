/* File generated by Đức's ClasHStamP */
using System;                                                   
using System.Collections.Generic;
using boolean = System.Boolean;
using Abstracts;
namespace Model {
    public  class Mocha: CondimentDecorator
    {
        public override double cost(
        ){
            return .20 + beverage.cost();
        } /* Mocha.cost */

        public override String description {
            get{ return beverage.description + ", Mocha"; }

        }
        public  Mocha(
            Beverage _beverage
        ):  base( _beverage )
        {
        }                                                                                       
    }
}
