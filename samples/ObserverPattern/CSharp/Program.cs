using System;
using Model;

namespace CSharp
{
    class Program
    {
        static void Main(string[] args) {
		    WeatherData weatherData = new WeatherData();
		
		    CurrentConditionDisplay currentDisplay = new CurrentConditionDisplay(weatherData);
		
		    weatherData.setMeasurements(27, 65, 30.4f);
		    weatherData.setMeasurements(28, 70, 29.2f);
		    weatherData.setMeasurements(26, 90, 29.2f);
        }
    }
}
