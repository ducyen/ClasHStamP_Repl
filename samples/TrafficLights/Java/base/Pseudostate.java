package base;

import java.io.IOException;

public class Pseudostate {
    public static int InputValue(String pMsg) {
        System.out.print(pMsg);
        try {
        	int n = System.in.read() - 48;
        	while(System.in.read() != 10);
			return n;
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        return 1;
    }
    public static void DisplayMsg(String pMsg) {
        System.out.println(pMsg);
    }
}
