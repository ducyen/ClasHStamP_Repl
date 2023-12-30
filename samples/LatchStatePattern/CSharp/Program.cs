using System;
using Model;

namespace CSharp
{
    class Program
    {
        static Sensor sensor = new Sensor(0);
        static void Main(string[] args) {
            for (int i = 0; i < (int)Sensor._EventId.SensorEventNum; i++) {
                Console.WriteLine("Input " + i + " for " + (Sensor._EventId)i);
            }
	        int n;
	        do {
	            sensor.Start();
	            do {
	        	    n = Base.TopState.InputValue("Enter event number('q': quit, 'r':restart): E");
	                sensor.EventProc(n, null);
	            } while (n+'0' != 'q' && n+'0' != 'r');
	        }while (n+'0' != 'q');
        }
    }
}
