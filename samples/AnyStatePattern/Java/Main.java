import model.*;
import abstracts.*;
import model.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        AnyStatePtn context = new AnyStatePtn(0);
        for (int i = 0; i < (int)AnyStatePtn._EventId.values().length; i++) {
            System.out.println("Input " + i + " for " + AnyStatePtn._EventId.values()[i]);
        }
        int n;
        do {
            context.Start();
            do {
        	    n = base.TopState.InputValue("Enter event number('q': quit, 'r':restart): E");
	        	if (n < AnyStatePtn._EventId.Num.ordinal()) {
	        		context.EventProc(n, null);
	        	}
            } while (n+'0' != 'q' && n+'0' != 'r');
        }while (n+'0' != 'q');
	}

}
