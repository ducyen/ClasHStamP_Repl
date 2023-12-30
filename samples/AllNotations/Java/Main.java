import java.util.ArrayList;

import model.*;
import base.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
	    ContextImpl ctxTest = new ContextImpl( 4, "", 1, 2, 3, new ArrayList<Aggregration>(), new ArrayList<Composition>() );
	    int n;
	    do {
	        ctxTest.Start();
	        do {
	        	n = base.TopState.InputValue("Enter event number('q': quit, 'r':restart): E");
	        	if (n < ContextImpl._EventId.Num.ordinal()) {
        			EventParams pParams = null;
	        		if (n == ContextImpl._EventId.E1.ordinal()) {
	        			pParams = new ContextImpl.E1Params() {
	        				{
	        					x = ContextImpl.AnEnum.Two;
	        				}
	        			};
	        		}
	        		ctxTest.EventProc(n, pParams);
	        	}
	        } while (n+'0' != 'q' && n+'0' != 'r');
	    }while (n+'0' != 'q');
	}

}
