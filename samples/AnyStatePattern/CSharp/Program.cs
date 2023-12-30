using System;
using Model;

namespace CSharp
{
    class Program
    {
        static AnyStatePtn context = new AnyStatePtn(0);
        static void Main(string[] args) {
            for (int i = 0; i < (int)AnyStatePtn._EventId.AnyStatePtnEventNum; i++) {
                Console.WriteLine("Input " + i + " for " + (AnyStatePtn._EventId)i);
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
