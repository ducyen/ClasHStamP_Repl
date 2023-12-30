using System;
using Model;

namespace CSharp
{
    class Program
    {
        static AirspeedSensor context = new AirspeedSensor(0);
        static void Main(string[] args) {
            for (int i = 0; i < (int)AirspeedSensor._EventId.AirspeedSensorEventNum; i++) {
                Console.WriteLine("Input " + i + " for " + (AirspeedSensor._EventId)i);
            }
	        int n;
	        do {
	            context.Start();
	            do {
	        	    n = Base.TopState.InputValue("Enter event number('q': quit, 'r':restart): E");
	                context.EventProc(n, null);
	            } while (n+'0' != 'q' && n+'0' != 'r');
	        }while (n+'0' != 'q');
        }
    }
}
