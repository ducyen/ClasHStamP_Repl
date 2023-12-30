/* File generated by Đức's ClasHStamP */
package model;

import java.io.*;
import java.util.*;
import model.*;
import base.*;

public  class AirspeedSensor extends Context
{
    public enum _EventId {
        evDataReady,
        evDisablePolling,
        evEnablePolling,
        evFinish,
        evStart,
        evStop,
        tm_POLLTIME,
        Num
    };
    static class PollingRegionStm extends Statemachine {
        public static class PollingRegionTop extends TopState {
            private static TopState singleInstance = new PollingRegionTop();
            public static TopState GetInstance() { return singleInstance; }
        }
        public static class InitialPseudostate0 extends Pseudostate {
            private static Pseudostate singleInstance = new InitialPseudostate0();
            public static Pseudostate GetInstance() { return singleInstance; }
        }
        public static class NotAcquiring extends PollingRegionTop {
            private static TopState singleInstance = new NotAcquiring();
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
                case evEnablePolling:{
                    pStm.BgnTrans( pContext, WaitingToAcquire.GetInstance() );
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
        public static class WaitingToAcquire extends PollingRegionTop {
            private static TopState singleInstance = new WaitingToAcquire();
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
                case evDisablePolling:{
                    pStm.BgnTrans( pContext, NotAcquiring.GetInstance() );
                    pStm.EndTrans( pContext );
                    bResult = true;
                } break;
                case tm_POLLTIME:{
                    if (((AirspeedSensor)pContext).IsIn(AirspeedSensorStm.Idle.GetInstance())) {
                        pStm.m_bIsExternTrans = true;
                        pStm.BgnTrans( pContext, WaitingToAcquire.GetInstance() );
                        pStm.m_pParentStm.m_pPseudostate = AirspeedSensorStm.CrunchingData.GetInstance();
                        pStm.EndTrans( pContext );
                        bResult = true;
                    }
                    else {
                        pStm.m_bIsExternTrans = true;
                        pStm.BgnTrans( pContext, WaitingToAcquire.GetInstance() );
                        pStm.EndTrans( pContext );
                        bResult = true;
                    }
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
                if (m_pCurrentState == PollingRegionTop.GetInstance() && m_pPseudostate == PollingRegionStm.InitialPseudostate0.GetInstance()) {
                    pStm.BgnTrans( pContext, NotAcquiring.GetInstance() );
                    pStm.EndTrans( pContext );
                    bResult = true;
                } else if (m_pCurrentState != m_pPseudostate && m_pPseudostate instanceof PollingRegionTop) {
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
                    m_pPseudostate = InitialPseudostate0.GetInstance();
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
            m_pSourceState = PollingRegionTop.GetInstance();
            BgnTrans(pContext, PollingRegionTop.GetInstance());
            EndTrans(pContext);
            return true;
        }
        public boolean IsFinished() {
            return m_pCurrentState == PollingRegionTop.GetInstance() && m_pCurrentState == m_pPseudostate;
        }
        public PollingRegionStm(){ super(PollingRegionTop.GetInstance(), PollingRegionTop.GetInstance()); }
    };
    static class AirspeedSensorStm extends Statemachine {
        public static class AirspeedSensorTop extends TopState {
            private static TopState singleInstance = new AirspeedSensorTop();
            public static TopState GetInstance() { return singleInstance; }
        }
        PollingRegionStm m_PollingRegionPollingRegionStm = new PollingRegionStm();
        public static class InitPt1 extends Pseudostate {
            private static Pseudostate singleInstance = new InitPt1();
            public static Pseudostate GetInstance() { return singleInstance; }
        }
        public static class InitialPseudostate1 extends Pseudostate {
            private static Pseudostate singleInstance = new InitialPseudostate1();
            public static Pseudostate GetInstance() { return singleInstance; }
        }
        public static class DataHandlingRegion extends AirspeedSensorTop {
            private static TopState singleInstance = new DataHandlingRegion();
            public static TopState GetInstance() { return singleInstance; }
            public void Entry(Context pContext, Statemachine pStm){
                if( pStm.IsEnterable(GetInstance()) ){
                    System.out.println(GetInstance().getClass() + "entry");
                    ((AirspeedSensorStm)pStm).m_PollingRegionPollingRegionStm.Reset( pContext, pStm, null );
                }
            }
            public boolean EventProc( Context pContext, Statemachine pStm, int nEventId, EventParams pParams ){
                boolean bResult = false;
                pStm.m_pSourceState = GetInstance();
                return bResult;
            }
            public void Exit(Context pContext, Statemachine pStm) {
                if (pStm.IsExitable(GetInstance())) {
                    ((AirspeedSensorStm)pStm).m_PollingRegionPollingRegionStm.Abort( pContext );
                    System.out.println(GetInstance().getClass() + "exit");
                }
            }
        };
        public static class Inactive extends DataHandlingRegion {
            private static TopState singleInstance = new Inactive();
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
                case evStart:{
                    if (((AirspeedSensor)pContext).IsIn(PollingRegionStm.NotAcquiring.GetInstance())) {
                        pStm.BgnTrans( pContext, Active.GetInstance(), InitialPseudostate1.GetInstance() );
                        ((AirspeedSensorStm)pStm).m_PollingRegionPollingRegionStm.Reset(pContext, pStm, PollingRegionStm.WaitingToAcquire.GetInstance());
                        pStm.EndTrans( pContext );
                        bResult = true;
                    }
                    else {
                        pStm.BgnTrans( pContext, Active.GetInstance(), InitialPseudostate1.GetInstance() );
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
        public static class Active extends DataHandlingRegion {
            private static TopState singleInstance = new Active();
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
                case evStop:{
                    if (((AirspeedSensor)pContext).IsIn(PollingRegionStm.WaitingToAcquire.GetInstance())) {
                        pStm.BgnTrans( pContext, Inactive.GetInstance() );
                        ((AirspeedSensorStm)pStm).m_PollingRegionPollingRegionStm.Reset(pContext, pStm, PollingRegionStm.NotAcquiring.GetInstance());
                        pStm.EndTrans( pContext );
                        bResult = true;
                    }
                    else {
                        pStm.BgnTrans( pContext, Inactive.GetInstance() );
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
        public static class Idle extends Active {
            private static TopState singleInstance = new Idle();
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
                    pStm.BgnTrans( pContext, CrunchingData.GetInstance() );
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
        public static class CrunchingData extends Active {
            private static TopState singleInstance = new CrunchingData();
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
                case evFinish:{
                    pStm.BgnTrans( pContext, Idle.GetInstance() );
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
            bResult |= m_PollingRegionPollingRegionStm.DefaultTrans( pContext );
            do {
                if (m_pCurrentState == AirspeedSensorTop.GetInstance() && m_pPseudostate == AirspeedSensorStm.InitPt1.GetInstance()) {
                    pStm.BgnTrans( pContext, DataHandlingRegion.GetInstance(), InitPt1.GetInstance() );
                    pStm.EndTrans( pContext );
                    bResult = true;
                } else if (m_pCurrentState == Active.GetInstance() && m_pPseudostate == AirspeedSensorStm.InitialPseudostate1.GetInstance()) {
                    pStm.BgnTrans( pContext, Idle.GetInstance() );
                    pStm.EndTrans( pContext );
                    bResult = true;
                } else if (m_pCurrentState == DataHandlingRegion.GetInstance() && m_pPseudostate == AirspeedSensorStm.InitPt1.GetInstance()) {
                    pStm.BgnTrans( pContext, Inactive.GetInstance() );
                    pStm.EndTrans( pContext );
                    bResult = true;
                } else if (m_pCurrentState != m_pPseudostate && m_pPseudostate instanceof AirspeedSensorTop) {
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
                    m_pPseudostate = InitPt1.GetInstance();
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
                m_PollingRegionPollingRegionStm.Reset( pContext, this, pEntryPoint );
            }
            return RunToCompletion(pContext);
        }
        public boolean EventProc(Context pContext, int nEventId, EventParams pParams){
            boolean bResult = false;
            m_pLCAState = TopState.GetInstance();
            bResult |= m_PollingRegionPollingRegionStm.EventProc( pContext, nEventId, pParams );
            bResult = m_pCurrentState.EventProc(pContext, this, nEventId, pParams);
            RunToCompletion(pContext);
            return bResult;
        }
        public boolean IsIn(TopState pCompositeState) {
            if (m_PollingRegionPollingRegionStm.IsIn(pCompositeState)) { return true; }
            if (super.IsIn(pCompositeState)) { return true; }
            return false;
        }
        public boolean Abort(Context pContext) {
            m_pSourceState = AirspeedSensorTop.GetInstance();
            BgnTrans(pContext, AirspeedSensorTop.GetInstance());
            EndTrans(pContext);
            return true;
        }
        public boolean IsFinished() {
            return m_pCurrentState == AirspeedSensorTop.GetInstance() && m_pCurrentState == m_pPseudostate;
        }
        public AirspeedSensorStm(){ super(AirspeedSensorTop.GetInstance(), AirspeedSensorTop.GetInstance()); }
    };
    public  AirspeedSensor(
        int _attribute0
    ) {
        super( _attribute0 );

    }                                                                                           
    AirspeedSensorStm mainStm = new AirspeedSensorStm();        
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
