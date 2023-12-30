using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Model;

namespace CSharp
{
    class Program
    {
        static void Main(string[] args) {
	        ContextImpl ctxTest = new ContextImpl( 4, new Composition(4) );
	        int n;
	        do {
	            ctxTest.Start();
	            do {
	        	    n = Base.TopState.InputValue("Enter event number('q': quit, 'r':restart): E");
	                ctxTest.EventProc(n, null);
	            } while (n+'0' != 'q' && n+'0' != 'r');
	        }while (n+'0' != 'q');
        }
    }
}
