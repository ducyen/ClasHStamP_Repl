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
	        ContextImpl ctxTest = new ContextImpl( 4, "", 1, 2, 3, new List<Aggregration>(), new List<Composition>(4) );
	        int n;
	        do {
	            ctxTest.Start();
	            do {
	        	    n = Base.TopState.InputValue("Enter event number('q': quit, 'r':restart): E");
                    Base.EventParams pParams = null;
                    if (n == (int)ContextImpl._EventId.E1) {
                        pParams = new ContextImpl.E1Params() { x = ContextImpl.AnEnum.Two };
                    }
	                ctxTest.EventProc(n, pParams);
	            } while (n+'0' != 'q' && n+'0' != 'r');
	        }while (n+'0' != 'q');
        }
    }
}
