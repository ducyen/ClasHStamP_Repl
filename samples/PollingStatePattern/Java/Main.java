import model.*;
import abstracts.*;
import model.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        AirspeedSensor context = new AirspeedSensor(0);
        for (int i = 0; i < (int)AirspeedSensor._EventId.values().length; i++) {
            System.out.println("Input " + i + " for " + AirspeedSensor._EventId.values()[i]);
        }
        int n;
        do {
            context.Start();
            do {
        	    n = base.TopState.InputValue("Enter event number('q': quit, 'r':restart): E");
	        	if (n < AirspeedSensor._EventId.Num.ordinal()) {
	        		context.EventProc(n, null);
	        	}
            } while (n+'0' != 'q' && n+'0' != 'r');
        }while (n+'0' != 'q');
	}

}
