using System;
using Model;
using Abstracts;

namespace CSharp
{
    class Program
    {
        static void Main(string[] args) {
            Beverage beverage = new Espresso();
            Console.WriteLine(beverage.description + " $" + beverage.cost());

            Beverage beverage2 = new DarkRoast();
            beverage2 = new Mocha(beverage2);
            beverage2 = new Mocha(beverage2);
            beverage2 = new Whip(beverage2);
            Console.WriteLine(beverage2.description + " $" + beverage2.cost());

            Beverage beverage3 = new HouseBlend();
            beverage3 = new Soy(beverage3);
            beverage3 = new Mocha(beverage3);
            beverage3 = new Whip(beverage3);
            Console.WriteLine(beverage3.description + " $" + beverage3.cost());
        }
    }
}
