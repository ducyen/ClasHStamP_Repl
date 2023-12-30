package base;

import model.*;

/*
class Pseudostate<T>: TopState where T: new() {
    private static T singleInstance;
    public static new T GetInstance() {
        return singleInstance;
    }
}
*/

public abstract class Statemachine {
    public boolean       m_bIsExternTrans;
    public TopState      m_pLCAState;
    public TopState      m_pTargetState;
    public Pseudostate   m_pPseudostate;
    public TopState      m_pCurrentState;
    public Statemachine  m_pParentStm;
    public TopState      m_pSourceState;
    public Statemachine(TopState pCurrentState, TopState pPseudostate)
    {
        m_pParentStm = null;
        m_bIsExternTrans = false;
        m_pCurrentState = pCurrentState;
        m_pLCAState = TopState.GetInstance();
        m_pTargetState = TopState.GetInstance();
        m_pSourceState = TopState.GetInstance();
        m_pPseudostate = pPseudostate;
    }
    public static boolean IsIn(TopState pCompositeState, TopState pLeafState) {
        boolean bResult = pCompositeState.getClass().isAssignableFrom(pLeafState.getClass());
        return bResult;
    }
    public boolean IsIn(TopState pCompositeState) {
        boolean bResult = pCompositeState.getClass().isAssignableFrom(m_pCurrentState.getClass());
        return bResult;
    }
    public boolean IsEnterable(TopState pThisState) {
        boolean isThisNotLCA = pThisState.getClass().isAssignableFrom(m_pLCAState.getClass());
        if (!isThisNotLCA) {
            return true;
        }
        return false;
    }
    public boolean IsExitable(TopState pThisState) {
        boolean isThisLCA = IsIn(pThisState, m_pSourceState) && IsIn(pThisState, m_pTargetState);
        if (!isThisLCA) {
            return true;
        } else if (m_bIsExternTrans) {
            m_bIsExternTrans = false;
            return true;
        } else { 
            m_pLCAState = pThisState;
        }
        return false;
    }
    public boolean IsFinished() {
        return m_pCurrentState == TopState.GetInstance() && m_pCurrentState == m_pPseudostate;
    }
    public void EndTrans(Context pContext) {
        m_pCurrentState = m_pTargetState;
        m_pCurrentState.Entry(pContext, this);
    }
    public void BgnTrans(Context pContext, TopState pTargetState) {
        BgnTrans(pContext, pTargetState, pTargetState);
    }
    public void BgnTrans(Context pContext, TopState pTargetState, Pseudostate pPseudostate) {
        m_pTargetState = pTargetState;
        m_pPseudostate = pPseudostate;
        m_pCurrentState.Exit(pContext, this);
    }
    public abstract boolean DefaultTrans(Context pContext);
    public boolean EventProc(Context pContext, int nEventId, EventParams pParams){
        boolean bResult = false;
        m_pLCAState = TopState.GetInstance();
        bResult = m_pCurrentState.EventProc(pContext, this, nEventId, pParams);
        RunToCompletion(pContext);
        return bResult;
    }
    protected boolean RunToCompletion(Context pContext) {
        boolean bResult;
        do {
            m_pSourceState = m_pCurrentState;
            m_pLCAState = TopState.GetInstance();
            bResult = DefaultTrans(pContext);
        } while (bResult);
        return bResult;
    }
    public abstract boolean Reset(Context pContext, Statemachine pParentStm, Pseudostate pEntryPoint);
    public boolean Abort(Context pContext) {
        m_pSourceState = TopState.GetInstance();
        BgnTrans(pContext, TopState.GetInstance());
        EndTrans(pContext);
        return true;
    }
}
