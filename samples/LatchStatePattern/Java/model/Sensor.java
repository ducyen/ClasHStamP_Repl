/* File generated by Đức's ClasHStamP */
package model;

import java.io.*;
import java.util.*;
import model.*;
import base.*;

public  class Sensor extends Context
{
    public int getData(
    ){
    	return 0;
    } /* Sensor.getData */
    public void doLongComputationOnData(
        int _x
    ){
    } /* Sensor.doLongComputationOnData */
    public void doEvenMoreProcessing(
    ){
    } /* Sensor.doEvenMoreProcessing */
    public enum _EventId {
        evClearDataLatch,
        evDataComplete,
        evDataReady,
        evHasNewData,
        evSensorReset,
        tm_100,
        Num
    };
    static class LatchStm extends Statemachine {
        public static class LatchTop extends TopState {
            private static TopState singleInstance = new LatchTop();
            public static TopState GetInstance() { return singleInstance; }
        }
        public static class InitPt extends Pseudostate {
            private static Pseudostate singleInstance = new InitPt();
            public static Pseudostate GetInstance() { return singleInstance; }
        }
        public static class NoData extends LatchTop {
            private static TopState singleInstance = new NoData();
            public static TopState GetInstance() { return singleInstance; }
            public void Entry(Context pContext, Statemachine pStm){
                if( pStm.IsEnterable(GetInstance()) ){
                    System.out.println(GetInstance().getClass() + "entry");
                }
            }
            public boolean EventProc( Context pContext, Statemachine pStm, int nEventId, EventParams pParams ){
                boolean bResult = false;
                pStm.m_pSourceState = GetInstance();
                switch( _EventId.values()[nEventId] ){
                case evHasNewData:{
                    pStm.BgnTrans( pContext, HasNewData.GetInstance() );
                    pStm.EndTrans( pContext );
                    bResult = true;
                } break;
                default: break;
                }
                return bResult;
            }
            public void Exit(Context pContext, Statemachine pStm) {
                if (pStm.IsExitable(GetInstance())) {
                    System.out.println(GetInstance().getClass() + "exit");
                }
            }
        };
        public static class HasNewData extends LatchTop {
            private static TopState singleInstance = new HasNewData();
            public static TopState GetInstance() { return singleInstance; }
            public void Entry(Context pContext, Statemachine pStm){
                if( pStm.IsEnterable(GetInstance()) ){
                    System.out.println(GetInstance().getClass() + "entry");
                }
            }
            public boolean EventProc( Context pContext, Statemachine pStm, int nEventId, EventParams pParams ){
                boolean bResult = false;
                pStm.m_pSourceState = GetInstance();
                switch( _EventId.values()[nEventId] ){
                case evClearDataLatch:{
                    pStm.BgnTrans( pContext, NoData.GetInstance() );
                    pStm.EndTrans( pContext );
                    bResult = true;
                } break;
                default: break;
                }
                return bResult;
            }
            public void Exit(Context pContext, Statemachine pStm) {
                if (pStm.IsExitable(GetInstance())) {
                    System.out.println(GetInstance().getClass() + "exit");
                }
            }
        };
        public boolean DefaultTrans( Context pContext ){
            boolean bResult = false;
            Statemachine pStm = this;
            do {
                if (m_pCurrentState == LatchTop.GetInstance() && m_pPseudostate == LatchStm.InitPt.GetInstance()) {
                    pStm.BgnTrans( pContext, NoData.GetInstance() );
                    pStm.EndTrans( pContext );
                    bResult = true;
                } else if (m_pCurrentState != m_pPseudostate && m_pPseudostate instanceof LatchTop) {
                    pStm.BgnTrans( pContext, (TopState)m_pPseudostate );
                    pStm.EndTrans( pContext );
                } else {
                }
            } while (false);
            return bResult;
        }
        public boolean Reset(Context pContext, Statemachine pParentStm, Pseudostate pEntryPoint) {
            m_pParentStm = pParentStm;
            if (pEntryPoint == null) {
                if (IsFinished()) {
                    m_pPseudostate = InitPt.GetInstance();
                }
            } else {
                if (IsFinished()) {
                    m_pPseudostate = pEntryPoint;
                    return false;
                } else {
                    m_pPseudostate = pEntryPoint;
                }                    
            }
            if (pEntryPoint != null) {
            }
            return RunToCompletion(pContext);
        }
        public boolean EventProc(Context pContext, int nEventId, EventParams pParams){
            boolean bResult = false;
            m_pLCAState = TopState.GetInstance();
            bResult = m_pCurrentState.EventProc(pContext, this, nEventId, pParams);
            RunToCompletion(pContext);
            return bResult;
        }
        public boolean IsIn(TopState pCompositeState) {
            if (super.IsIn(pCompositeState)) { return true; }
            return false;
        }
        public boolean Abort(Context pContext) {
            m_pSourceState = LatchTop.GetInstance();
            BgnTrans(pContext, LatchTop.GetInstance());
            EndTrans(pContext);
            return true;
        }
        public boolean IsFinished() {
            return m_pCurrentState == LatchTop.GetInstance() && m_pCurrentState == m_pPseudostate;
        }
        public LatchStm(){ super(LatchTop.GetInstance(), LatchTop.GetInstance()); }
    };
    static class DepedentStm extends Statemachine {
        public static class DependentTop extends TopState {
            private static TopState singleInstance = new DependentTop();
            public static TopState GetInstance() { return singleInstance; }
        }
        LatchStm m_LatchLatchStm = new LatchStm();              
        public static class InitPt extends Pseudostate {
            private static Pseudostate singleInstance = new InitPt();
            public static Pseudostate GetInstance() { return singleInstance; }
        }
        public static class Dependent extends DependentTop {
            private static TopState singleInstance = new Dependent();
            public static TopState GetInstance() { return singleInstance; }
            public void Entry(Context pContext, Statemachine pStm){
                if( pStm.IsEnterable(GetInstance()) ){
                    System.out.println(GetInstance().getClass() + "entry");
                    ((DepedentStm)pStm).m_LatchLatchStm.Reset( pContext, pStm, null );
                }
            }
            public boolean EventProc( Context pContext, Statemachine pStm, int nEventId, EventParams pParams ){
                boolean bResult = false;
                pStm.m_pSourceState = GetInstance();
                return bResult;
            }
            public void Exit(Context pContext, Statemachine pStm) {
                if (pStm.IsExitable(GetInstance())) {
                    ((DepedentStm)pStm).m_LatchLatchStm.Abort( pContext );
                    System.out.println(GetInstance().getClass() + "exit");
                }
            }
        };
        public static class ProcessingData extends Dependent {
            private static TopState singleInstance = new ProcessingData();
            public static TopState GetInstance() { return singleInstance; }
            public void Entry(Context pContext, Statemachine pStm){
                if( pStm.IsEnterable(GetInstance()) ){
                    super.Entry( pContext, pStm );
                    System.out.println(GetInstance().getClass() + "entry");
                    DisplayMsg("doLongComputationOnData(((Sensor)pContext).x);");
                }
            }
            public boolean EventProc( Context pContext, Statemachine pStm, int nEventId, EventParams pParams ){
                boolean bResult = false;
                pStm.m_pSourceState = GetInstance();
                return bResult ? bResult : super.EventProc( pContext, pStm, nEventId, pParams );
            }
            public void Exit(Context pContext, Statemachine pStm) {
                if (pStm.IsExitable(GetInstance())) {
                    System.out.println(GetInstance().getClass() + "exit");
                    super.Exit(pContext, pStm);
                }
            }
        };
        public static class MoreProcessing extends Dependent {
            private static TopState singleInstance = new MoreProcessing();
            public static TopState GetInstance() { return singleInstance; }
            public void Entry(Context pContext, Statemachine pStm){
                if( pStm.IsEnterable(GetInstance()) ){
                    super.Entry( pContext, pStm );
                    System.out.println(GetInstance().getClass() + "entry");
                    DisplayMsg("doEvenMoreProcessing();");
                }
            }
            public boolean EventProc( Context pContext, Statemachine pStm, int nEventId, EventParams pParams ){
                boolean bResult = false;
                pStm.m_pSourceState = GetInstance();
                return bResult ? bResult : super.EventProc( pContext, pStm, nEventId, pParams );
            }
            public void Exit(Context pContext, Statemachine pStm) {
                if (pStm.IsExitable(GetInstance())) {
                    System.out.println(GetInstance().getClass() + "exit");
                    super.Exit(pContext, pStm);
                }
            }
        };
        public static class ReadyToProcessData extends Dependent {
            private static TopState singleInstance = new ReadyToProcessData();
            public static TopState GetInstance() { return singleInstance; }
            public void Entry(Context pContext, Statemachine pStm){
                if( pStm.IsEnterable(GetInstance()) ){
                    super.Entry( pContext, pStm );
                    System.out.println(GetInstance().getClass() + "entry");
                }
            }
            public boolean EventProc( Context pContext, Statemachine pStm, int nEventId, EventParams pParams ){
                boolean bResult = false;
                pStm.m_pSourceState = GetInstance();
                switch( _EventId.values()[nEventId] ){
                case tm_100:{
                    if (((Sensor)pContext).IsIn(LatchStm.HasNewData.GetInstance())) {
                        pStm.BgnTrans( pContext, ProcessingData.GetInstance() );
                        ((DepedentStm)pStm).m_LatchLatchStm.Reset(pContext, pStm, LatchStm.NoData.GetInstance());
                        pStm.EndTrans( pContext );
                        bResult = true;
                    }
                    else {
                        pStm.m_bIsExternTrans = true;
                        pStm.BgnTrans( pContext, ReadyToProcessData.GetInstance() );
                        pStm.EndTrans( pContext );
                        bResult = true;
                    }
                } break;
                default: break;
                }
                return bResult ? bResult : super.EventProc( pContext, pStm, nEventId, pParams );
            }
            public void Exit(Context pContext, Statemachine pStm) {
                if (pStm.IsExitable(GetInstance())) {
                    System.out.println(GetInstance().getClass() + "exit");
                    super.Exit(pContext, pStm);
                }
            }
        };
        public boolean DefaultTrans( Context pContext ){
            boolean bResult = false;
            Statemachine pStm = this;
            bResult |= m_LatchLatchStm.DefaultTrans( pContext );
            do {
                if (m_pCurrentState == Dependent.GetInstance() && m_pPseudostate == DepedentStm.InitPt.GetInstance()) {
                    pStm.BgnTrans( pContext, ReadyToProcessData.GetInstance() );
                    pStm.EndTrans( pContext );
                    bResult = true;
                } else if (m_pPseudostate == DepedentStm.ProcessingData.GetInstance()) {
                    pStm.BgnTrans( pContext, MoreProcessing.GetInstance() );
                    pStm.EndTrans( pContext );
                    bResult = true;
                } else if (m_pPseudostate == DepedentStm.MoreProcessing.GetInstance()) {
                    pStm.BgnTrans( pContext, ReadyToProcessData.GetInstance() );
                    pStm.EndTrans( pContext );
                    bResult = true;
                } else if (m_pCurrentState == DependentTop.GetInstance() && m_pPseudostate == DepedentStm.InitPt.GetInstance()) {
                    pStm.BgnTrans( pContext, Dependent.GetInstance(), InitPt.GetInstance() );
                    pStm.EndTrans( pContext );
                    bResult = true;
                } else if (m_pCurrentState != m_pPseudostate && m_pPseudostate instanceof DependentTop) {
                    pStm.BgnTrans( pContext, (TopState)m_pPseudostate );
                    pStm.EndTrans( pContext );
                } else {
                }
            } while (false);
            return bResult;
        }
        public boolean Reset(Context pContext, Statemachine pParentStm, Pseudostate pEntryPoint) {
            m_pParentStm = pParentStm;
            if (pEntryPoint == null) {
                if (IsFinished()) {
                    m_pPseudostate = InitPt.GetInstance();
                }
            } else {
                if (IsFinished()) {
                    m_pPseudostate = pEntryPoint;
                    return false;
                } else {
                    m_pPseudostate = pEntryPoint;
                }                    
            }
            if (pEntryPoint != null) {
                m_LatchLatchStm.Reset( pContext, this, pEntryPoint );
            }
            return RunToCompletion(pContext);
        }
        public boolean EventProc(Context pContext, int nEventId, EventParams pParams){
            boolean bResult = false;
            m_pLCAState = TopState.GetInstance();
            bResult |= m_LatchLatchStm.EventProc( pContext, nEventId, pParams );
            bResult = m_pCurrentState.EventProc(pContext, this, nEventId, pParams);
            RunToCompletion(pContext);
            return bResult;
        }
        public boolean IsIn(TopState pCompositeState) {
            if (m_LatchLatchStm.IsIn(pCompositeState)) { return true; }
            if (super.IsIn(pCompositeState)) { return true; }
            return false;
        }
        public boolean Abort(Context pContext) {
            m_pSourceState = DependentTop.GetInstance();
            BgnTrans(pContext, DependentTop.GetInstance());
            EndTrans(pContext);
            return true;
        }
        public boolean IsFinished() {
            return m_pCurrentState == DependentTop.GetInstance() && m_pCurrentState == m_pPseudostate;
        }
        public DepedentStm(){ super(DependentTop.GetInstance(), DependentTop.GetInstance()); }
    };
    static class PredicateStm extends Statemachine {
        public static class PredicateTop extends TopState {
            private static TopState singleInstance = new PredicateTop();
            public static TopState GetInstance() { return singleInstance; }
        }
        DepedentStm m_DependentDepedentStm = new DepedentStm(); 
        public static class InitPt extends Pseudostate {
            private static Pseudostate singleInstance = new InitPt();
            public static Pseudostate GetInstance() { return singleInstance; }
        }
        public static class SensorActive extends PredicateTop {
            private static TopState singleInstance = new SensorActive();
            public static TopState GetInstance() { return singleInstance; }
            public void Entry(Context pContext, Statemachine pStm){
                if( pStm.IsEnterable(GetInstance()) ){
                    System.out.println(GetInstance().getClass() + "entry");
                    ((PredicateStm)pStm).m_DependentDepedentStm.Reset( pContext, pStm, null );
                }
            }
            public boolean EventProc( Context pContext, Statemachine pStm, int nEventId, EventParams pParams ){
                boolean bResult = false;
                pStm.m_pSourceState = GetInstance();
                return bResult;
            }
            public void Exit(Context pContext, Statemachine pStm) {
                if (pStm.IsExitable(GetInstance())) {
                    ((PredicateStm)pStm).m_DependentDepedentStm.Abort( pContext );
                    System.out.println(GetInstance().getClass() + "exit");
                }
            }
        };
        public static class WaitingForData extends SensorActive {
            private static TopState singleInstance = new WaitingForData();
            public static TopState GetInstance() { return singleInstance; }
            public void Entry(Context pContext, Statemachine pStm){
                if( pStm.IsEnterable(GetInstance()) ){
                    super.Entry( pContext, pStm );
                    System.out.println(GetInstance().getClass() + "entry");
                }
            }
            public boolean EventProc( Context pContext, Statemachine pStm, int nEventId, EventParams pParams ){
                boolean bResult = false;
                pStm.m_pSourceState = GetInstance();
                switch( _EventId.values()[nEventId] ){
                case evDataReady:{
                    DisplayMsg("x = .getData();");
                    if (((Sensor)pContext).IsIn(LatchStm.NoData.GetInstance())) {
                        pStm.BgnTrans( pContext, DataReady.GetInstance() );
                        ((PredicateStm)pStm).m_DependentDepedentStm.Reset(pContext, pStm, LatchStm.HasNewData.GetInstance());
                        pStm.EndTrans( pContext );
                        bResult = true;
                    }
                    else {
                        pStm.BgnTrans( pContext, DataReady.GetInstance() );
                        pStm.EndTrans( pContext );
                        bResult = true;
                    }
                } break;
                default: break;
                }
                return bResult ? bResult : super.EventProc( pContext, pStm, nEventId, pParams );
            }
            public void Exit(Context pContext, Statemachine pStm) {
                if (pStm.IsExitable(GetInstance())) {
                    System.out.println(GetInstance().getClass() + "exit");
                    super.Exit(pContext, pStm);
                }
            }
        };
        public static class DataReady extends SensorActive {
            private static TopState singleInstance = new DataReady();
            public static TopState GetInstance() { return singleInstance; }
            public void Entry(Context pContext, Statemachine pStm){
                if( pStm.IsEnterable(GetInstance()) ){
                    super.Entry( pContext, pStm );
                    System.out.println(GetInstance().getClass() + "entry");
                }
            }
            public boolean EventProc( Context pContext, Statemachine pStm, int nEventId, EventParams pParams ){
                boolean bResult = false;
                pStm.m_pSourceState = GetInstance();
                switch( _EventId.values()[nEventId] ){
                case evDataComplete:{
                    pStm.BgnTrans( pContext, ResetingSensor.GetInstance() );
                    pStm.EndTrans( pContext );
                    bResult = true;
                } break;
                default: break;
                }
                return bResult ? bResult : super.EventProc( pContext, pStm, nEventId, pParams );
            }
            public void Exit(Context pContext, Statemachine pStm) {
                if (pStm.IsExitable(GetInstance())) {
                    System.out.println(GetInstance().getClass() + "exit");
                    super.Exit(pContext, pStm);
                }
            }
        };
        public static class ResetingSensor extends SensorActive {
            private static TopState singleInstance = new ResetingSensor();
            public static TopState GetInstance() { return singleInstance; }
            public void Entry(Context pContext, Statemachine pStm){
                if( pStm.IsEnterable(GetInstance()) ){
                    super.Entry( pContext, pStm );
                    System.out.println(GetInstance().getClass() + "entry");
                }
            }
            public boolean EventProc( Context pContext, Statemachine pStm, int nEventId, EventParams pParams ){
                boolean bResult = false;
                pStm.m_pSourceState = GetInstance();
                switch( _EventId.values()[nEventId] ){
                case evSensorReset:{
                    pStm.BgnTrans( pContext, WaitingForData.GetInstance() );
                    pStm.EndTrans( pContext );
                    bResult = true;
                } break;
                default: break;
                }
                return bResult ? bResult : super.EventProc( pContext, pStm, nEventId, pParams );
            }
            public void Exit(Context pContext, Statemachine pStm) {
                if (pStm.IsExitable(GetInstance())) {
                    System.out.println(GetInstance().getClass() + "exit");
                    super.Exit(pContext, pStm);
                }
            }
        };
        public boolean DefaultTrans( Context pContext ){
            boolean bResult = false;
            Statemachine pStm = this;
            bResult |= m_DependentDepedentStm.DefaultTrans( pContext );
            do {
                if (m_pCurrentState == SensorActive.GetInstance() && m_pPseudostate == PredicateStm.InitPt.GetInstance()) {
                    pStm.BgnTrans( pContext, WaitingForData.GetInstance() );
                    pStm.EndTrans( pContext );
                    bResult = true;
                } else if (m_pCurrentState == PredicateTop.GetInstance() && m_pPseudostate == PredicateStm.InitPt.GetInstance()) {
                    pStm.BgnTrans( pContext, SensorActive.GetInstance(), InitPt.GetInstance() );
                    pStm.EndTrans( pContext );
                    bResult = true;
                } else if (m_pCurrentState != m_pPseudostate && m_pPseudostate instanceof PredicateTop) {
                    pStm.BgnTrans( pContext, (TopState)m_pPseudostate );
                    pStm.EndTrans( pContext );
                } else {
                }
            } while (false);
            return bResult;
        }
        public boolean Reset(Context pContext, Statemachine pParentStm, Pseudostate pEntryPoint) {
            m_pParentStm = pParentStm;
            if (pEntryPoint == null) {
                if (IsFinished()) {
                    m_pPseudostate = InitPt.GetInstance();
                }
            } else {
                if (IsFinished()) {
                    m_pPseudostate = pEntryPoint;
                    return false;
                } else {
                    m_pPseudostate = pEntryPoint;
                }                    
            }
            if (pEntryPoint != null) {
                m_DependentDepedentStm.Reset( pContext, this, pEntryPoint );
            }
            return RunToCompletion(pContext);
        }
        public boolean EventProc(Context pContext, int nEventId, EventParams pParams){
            boolean bResult = false;
            m_pLCAState = TopState.GetInstance();
            bResult |= m_DependentDepedentStm.EventProc( pContext, nEventId, pParams );
            bResult = m_pCurrentState.EventProc(pContext, this, nEventId, pParams);
            RunToCompletion(pContext);
            return bResult;
        }
        public boolean IsIn(TopState pCompositeState) {
            if (m_DependentDepedentStm.IsIn(pCompositeState)) { return true; }
            if (super.IsIn(pCompositeState)) { return true; }
            return false;
        }
        public boolean Abort(Context pContext) {
            m_pSourceState = PredicateTop.GetInstance();
            BgnTrans(pContext, PredicateTop.GetInstance());
            EndTrans(pContext);
            return true;
        }
        public boolean IsFinished() {
            return m_pCurrentState == PredicateTop.GetInstance() && m_pCurrentState == m_pPseudostate;
        }
        public PredicateStm(){ super(PredicateTop.GetInstance(), PredicateTop.GetInstance()); }
    };
    public  Sensor(
        int _attribute0
    ) {
        super( _attribute0 );

        x = 0;
    }                                                                                           
    private int x;                                              
    PredicateStm mainStm = new PredicateStm();                  
    public boolean Start() {
            mainStm.Abort(this);
        return mainStm.Reset(this, null, null);
    }
    public boolean EventProc(int nEventId, EventParams pParams) {
        return mainStm.EventProc(this, nEventId, pParams);
    }
    public boolean IsIn(TopState pState) {
        return mainStm.IsIn(pState);
    }
}
