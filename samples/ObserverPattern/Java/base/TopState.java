package base;

import model.*;

public class TopState extends Pseudostate {
    private static TopState singleInstance = new TopState();
    public static TopState GetInstance() {
        return singleInstance;
    }
    public void Entry(Context pContext, Statemachine pStm) { return; }
    public void Exit(Context pContext, Statemachine pStm) { return; }
    public boolean EventProc(Context pContext, Statemachine pStm, int nEventId, EventParams pParams) { return false; }

}
