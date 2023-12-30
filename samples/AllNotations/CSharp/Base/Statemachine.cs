using System;
using Model;

namespace Base {
    public class EventParams {
        int nEventId;
    }

    public class Pseudostate {
        public static int InputValue(string pMsg) {
            Console.Write(pMsg);
            return Console.ReadLine()[0] - '0';
        }
        public static void DisplayMsg(string pMsg) {
            Console.WriteLine(pMsg);
        }
    };

    public class Pseudostate<T>: Pseudostate where T: new() {
        private static T singleInstance = new T();
        public static T GetInstance() {
            return singleInstance;
        }
    };

    public class TopState: Pseudostate<TopState> {
        public virtual void Entry(Context pContext, Statemachine pStm) { return; }
        public virtual void Exit(Context pContext, Statemachine pStm) { return; }
        public virtual bool EventProc(Context pContext, Statemachine pStm, int nEventId, EventParams pParams) { return false; }
    };

    public abstract class Statemachine {
        public bool          m_bIsExternTrans;
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
        public static bool IsIn(TopState pCompositeState, TopState pLeafState) {
            bool bResult = pCompositeState.GetType().IsAssignableFrom(pLeafState.GetType());
            return bResult;
        }
        public virtual bool IsIn(TopState pCompositeState) {
            bool bResult = pCompositeState.GetType().IsAssignableFrom(m_pCurrentState.GetType());
            return bResult;
        }
        public bool IsEnterable(TopState pThisState) {
            bool isThisNotLCA = pThisState.GetType().IsAssignableFrom(m_pLCAState.GetType());
            if (!isThisNotLCA) {
                return true;
            }
            return false;
        }
        public bool IsExitable(TopState pThisState) {
            bool isThisLCA = IsIn(pThisState, m_pSourceState) && IsIn(pThisState, m_pTargetState);
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
        public virtual bool IsFinished() {
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
        public abstract bool DefaultTrans(Context pContext);
        public virtual bool EventProc(Context pContext, int nEventId, EventParams pParams){
            bool bResult = false;
            m_pLCAState = TopState.GetInstance();
            bResult = m_pCurrentState.EventProc(pContext, this, nEventId, pParams);
            RunToCompletion(pContext);
            return bResult;
        }
        protected bool RunToCompletion(Context pContext) {
            bool bResult;
            do {
                m_pSourceState = m_pCurrentState;
                m_pLCAState = TopState.GetInstance();
                bResult = DefaultTrans(pContext);
            } while (bResult);
            return bResult;
        }
        public abstract bool Reset(Context pContext, Statemachine pParentStm, Pseudostate pEntryPoint);
        public virtual bool Abort(Context pContext) {
            m_pSourceState = TopState.GetInstance();
            BgnTrans(pContext, TopState.GetInstance());
            EndTrans(pContext);
            return true;
        }
    };
}
