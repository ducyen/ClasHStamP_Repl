import model.*;
import abstracts.*;
import model.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Sensor sensor = new Sensor(0);
        for (int i = 0; i < (int)Sensor._EventId.values().length; i++) {
            System.out.println("Input " + i + " for " + Sensor._EventId.values()[i]);
        }
        int n;
        do {
            sensor.Start();
            do {
        	    n = base.TopState.InputValue("Enter event number('q': quit, 'r':restart): E");
	        	if (n < Sensor._EventId.Num.ordinal()) {
	        		sensor.EventProc(n, null);
	        	}
            } while (n+'0' != 'q' && n+'0' != 'r');
        }while (n+'0' != 'q');
	}

}
