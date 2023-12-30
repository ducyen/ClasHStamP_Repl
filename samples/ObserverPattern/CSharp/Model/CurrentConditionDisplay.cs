/* File generated by Đức's ClasHStamP */
using System;                                                   
using System.Collections.Generic;
using boolean = System.Boolean;
using Interfaces;
namespace Model {
    public  class CurrentConditionDisplay: ObserverIfc
    {
        public virtual void update(
            float temperature,
            float humidity,
            float pressure
        ){
    	    this.temperature = temperature;
    	    this.humidity = humidity;
    	    display();
        } /* CurrentConditionDisplay.update */

        public void display(
        ){
        	Console.WriteLine("Current condition: " + temperature + "℃ and " + humidity + "% humidity");
        } /* CurrentConditionDisplay.display */
        public  CurrentConditionDisplay(
            Subject _weatherData
        ){
            temperature = 0;
            humidity = 0;
            weatherData = _weatherData;
            weatherData.registerObserver(this);
        }                                                                                       
        private float temperature;                              
        private float humidity;                                 
        private   Subject weatherData;                          
    }
}
