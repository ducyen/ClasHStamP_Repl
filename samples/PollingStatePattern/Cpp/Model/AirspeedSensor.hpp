#pragma once
/* File generated by Đức's ClasHStamP */
#include "Generic/CommonInclude.h"
#include "Model/Context.hpp"                                    
#include "Generic/Statemachine.h"

class AirspeedSensor: public Context{
    public: enum _EventId {
        evDataReady,
        evDisablePolling,
        evEnablePolling,
        evFinish,
        evStart,
        evStop,
        tm_POLLTIME,
        evNum
    };
    const std::string EventId_toString( _EventId value );
    friend class Main;
    class PollingRegionStm: public Statemachine {
    public:
        class PollingRegionTop: public TopState{ using TThisState = PollingRegionTop;
            public: static TopState* GetInstance() { static TThisState singleInstance; return &singleInstance; }
        };
        class InitialPseudostate0: public Pseudostate<InitialPseudostate0>{};
        class NotAcquiring: public PollingRegionTop { using TThisState = NotAcquiring; using TSuperState = PollingRegionTop;
            public: static TopState* GetInstance() { static TThisState singleInstance; return &singleInstance; }
            virtual void Entry( Context* pContext, Statemachine* pStm ){
                if( pStm->IsEnterable<TThisState>() ){
                    std::cout << typeid(this).name() << " entry\n";
                }
            }
            virtual bool EventProc( Context* pContext, Statemachine* pStm, EventId nEventId, EventParams* pParams ){
                bool bResult = false;
                pStm->m_pSourceState = TThisState::GetInstance();
                switch( nEventId ){
                case evEnablePolling:{
                    pStm->BgnTrans( pContext, WaitingToAcquire::GetInstance() );
                    pStm->EndTrans( pContext );
                    bResult = true;
                } break;
                default: break;
                }
                return bResult;
            }
            virtual void Exit(Context* pContext, Statemachine* pStm) {
                if (pStm->IsExitable<TThisState>()) {
                    std::cout << typeid(this).name() << " exit\n";
                }
            }
        };
        class WaitingToAcquire: public PollingRegionTop { using TThisState = WaitingToAcquire; using TSuperState = PollingRegionTop;
            public: static TopState* GetInstance() { static TThisState singleInstance; return &singleInstance; }
            virtual void Entry( Context* pContext, Statemachine* pStm ){
                if( pStm->IsEnterable<TThisState>() ){
                    std::cout << typeid(this).name() << " entry\n";
                }
            }
            virtual bool EventProc( Context* pContext, Statemachine* pStm, EventId nEventId, EventParams* pParams ){
                bool bResult = false;
                pStm->m_pSourceState = TThisState::GetInstance();
                switch( nEventId ){
                case evDisablePolling:{
                    pStm->BgnTrans( pContext, NotAcquiring::GetInstance() );
                    pStm->EndTrans( pContext );
                    bResult = true;
                } break;
                case tm_POLLTIME:{
                    if (((AirspeedSensor*)pContext)->IsIn<AirspeedSensorStm::Idle>()) {
                        pStm->m_bIsExternTrans = true;
                        pStm->BgnTrans( pContext, WaitingToAcquire::GetInstance() );
                        pStm->m_pParentStm->m_pPseudostate = AirspeedSensorStm::CrunchingData::GetInstance();
                        pStm->EndTrans( pContext );
                        bResult = true;
                    }
                    else {
                        pStm->m_bIsExternTrans = true;
                        pStm->BgnTrans( pContext, WaitingToAcquire::GetInstance() );
                        pStm->EndTrans( pContext );
                        bResult = true;
                    }
                } break;
                default: break;
                }
                return bResult;
            }
            virtual void Exit(Context* pContext, Statemachine* pStm) {
                if (pStm->IsExitable<TThisState>()) {
                    std::cout << typeid(this).name() << " exit\n";
                }
            }
        };
        virtual bool DefaultTrans( Context* pContext ){
            bool bResult = false;
            Statemachine* pStm = this;
            do {
                if (m_pCurrentState == PollingRegionTop::GetInstance() && m_pPseudostate == PollingRegionStm::InitialPseudostate0::GetInstance()) {
                    pStm->BgnTrans( pContext, NotAcquiring::GetInstance() );
                    pStm->EndTrans( pContext );
                    bResult = true;
                } else if (m_pCurrentState != m_pPseudostate && dynamic_cast<PollingRegionTop*>(m_pPseudostate) != NULL) {
                    pStm->BgnTrans( pContext, dynamic_cast<TopState*>(m_pPseudostate) );
                    pStm->EndTrans( pContext );
                    bResult = true;
                } else {
                }
            } while (false);
            return bResult;
        }
        virtual bool Reset(Context* pContext, Statemachine* pParentStm, StateBase* pEntryPoint) {
            m_pParentStm = pParentStm;
            if (pEntryPoint == null) {
                if (IsFinished()) {
                    m_pPseudostate = InitialPseudostate0::GetInstance();
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
        virtual bool EventProc(Context* pContext, int nEventId, EventParams* pParams){
            bool bResult = false;
            m_pLCAState = TopState::GetInstance();
            bResult = m_pCurrentState->EventProc(pContext, this, nEventId, pParams);
            RunToCompletion(pContext);
            return bResult;
        }
        template<class TCompositeState = TopState>
        bool IsInRecur() {
            if (IsIn<TCompositeState>()) { return true; }
            return false;
        }
        virtual bool Abort(Context* pContext) {
            m_pSourceState = PollingRegionTop::GetInstance();
            BgnTrans(pContext, PollingRegionTop::GetInstance());
            EndTrans(pContext);
            return true;
        }
        virtual bool IsFinished() {
            return m_pCurrentState == PollingRegionTop::GetInstance() && m_pCurrentState == m_pPseudostate;
        }
        PollingRegionStm(): Statemachine(PollingRegionTop::GetInstance(), PollingRegionTop::GetInstance()) {}
    };
    class AirspeedSensorStm: public Statemachine {
    public:
        class AirspeedSensorTop: public TopState{ using TThisState = AirspeedSensorTop;
            public: static TopState* GetInstance() { static TThisState singleInstance; return &singleInstance; }
        };
        PollingRegionStm m_PollingRegionPollingRegionStm;       
        class InitPt1: public Pseudostate<InitPt1>{};
        class InitialPseudostate1: public Pseudostate<InitialPseudostate1>{};
        class DataHandlingRegion: public AirspeedSensorTop { using TThisState = DataHandlingRegion; using TSuperState = AirspeedSensorTop;
            public: static TopState* GetInstance() { static TThisState singleInstance; return &singleInstance; }
            virtual void Entry( Context* pContext, Statemachine* pStm ){
                if( pStm->IsEnterable<TThisState>() ){
                    std::cout << typeid(this).name() << " entry\n";
                    ((AirspeedSensorStm*)pStm)->m_PollingRegionPollingRegionStm.Reset( pContext, pStm, nullptr );
                }
            }
            virtual bool EventProc( Context* pContext, Statemachine* pStm, EventId nEventId, EventParams* pParams ){
                bool bResult = false;
                pStm->m_pSourceState = TThisState::GetInstance();
                return bResult;
            }
            virtual void Exit(Context* pContext, Statemachine* pStm) {
                if (pStm->IsExitable<TThisState>()) {
                    ((AirspeedSensorStm*)pStm)->m_PollingRegionPollingRegionStm.Abort( pContext );
                    std::cout << typeid(this).name() << " exit\n";
                }
            }
        };
        class Inactive: public DataHandlingRegion { using TThisState = Inactive; using TSuperState = DataHandlingRegion;
            public: static TopState* GetInstance() { static TThisState singleInstance; return &singleInstance; }
            virtual void Entry( Context* pContext, Statemachine* pStm ){
                if( pStm->IsEnterable<TThisState>() ){
                    TSuperState::Entry( pContext, pStm );
                    std::cout << typeid(this).name() << " entry\n";
                }
            }
            virtual bool EventProc( Context* pContext, Statemachine* pStm, EventId nEventId, EventParams* pParams ){
                bool bResult = false;
                pStm->m_pSourceState = TThisState::GetInstance();
                switch( nEventId ){
                case evStart:{
                    if (((AirspeedSensor*)pContext)->IsIn<PollingRegionStm::NotAcquiring>()) {
                        pStm->BgnTrans( pContext, Active::GetInstance(), InitialPseudostate1::GetInstance() );
                        ((AirspeedSensorStm*)pStm)->m_PollingRegionPollingRegionStm.Reset(pContext, pStm, PollingRegionStm::WaitingToAcquire::GetInstance());
                        pStm->EndTrans( pContext );
                        bResult = true;
                    }
                    else {
                        pStm->BgnTrans( pContext, Active::GetInstance(), InitialPseudostate1::GetInstance() );
                        pStm->EndTrans( pContext );
                        bResult = true;
                    }
                } break;
                default: break;
                }
                return bResult ? bResult : TSuperState::EventProc( pContext, pStm, nEventId, pParams );
            }
            virtual void Exit(Context* pContext, Statemachine* pStm) {
                if (pStm->IsExitable<TThisState>()) {
                    std::cout << typeid(this).name() << " exit\n";
                    TSuperState::Exit(pContext, pStm);
                }
            }
        };
        class Active: public DataHandlingRegion { using TThisState = Active; using TSuperState = DataHandlingRegion;
            public: static TopState* GetInstance() { static TThisState singleInstance; return &singleInstance; }
            virtual void Entry( Context* pContext, Statemachine* pStm ){
                if( pStm->IsEnterable<TThisState>() ){
                    TSuperState::Entry( pContext, pStm );
                    std::cout << typeid(this).name() << " entry\n";
                }
            }
            virtual bool EventProc( Context* pContext, Statemachine* pStm, EventId nEventId, EventParams* pParams ){
                bool bResult = false;
                pStm->m_pSourceState = TThisState::GetInstance();
                switch( nEventId ){
                case evStop:{
                    if (((AirspeedSensor*)pContext)->IsIn<PollingRegionStm::WaitingToAcquire>()) {
                        pStm->BgnTrans( pContext, Inactive::GetInstance() );
                        ((AirspeedSensorStm*)pStm)->m_PollingRegionPollingRegionStm.Reset(pContext, pStm, PollingRegionStm::NotAcquiring::GetInstance());
                        pStm->EndTrans( pContext );
                        bResult = true;
                    }
                    else {
                        pStm->BgnTrans( pContext, Inactive::GetInstance() );
                        pStm->EndTrans( pContext );
                        bResult = true;
                    }
                } break;
                default: break;
                }
                return bResult ? bResult : TSuperState::EventProc( pContext, pStm, nEventId, pParams );
            }
            virtual void Exit(Context* pContext, Statemachine* pStm) {
                if (pStm->IsExitable<TThisState>()) {
                    std::cout << typeid(this).name() << " exit\n";
                    TSuperState::Exit(pContext, pStm);
                }
            }
        };
        class Idle: public Active { using TThisState = Idle; using TSuperState = Active;
            public: static TopState* GetInstance() { static TThisState singleInstance; return &singleInstance; }
            virtual void Entry( Context* pContext, Statemachine* pStm ){
                if( pStm->IsEnterable<TThisState>() ){
                    TSuperState::Entry( pContext, pStm );
                    std::cout << typeid(this).name() << " entry\n";
                }
            }
            virtual bool EventProc( Context* pContext, Statemachine* pStm, EventId nEventId, EventParams* pParams ){
                bool bResult = false;
                pStm->m_pSourceState = TThisState::GetInstance();
                switch( nEventId ){
                case evDataReady:{
                    pStm->BgnTrans( pContext, CrunchingData::GetInstance() );
                    pStm->EndTrans( pContext );
                    bResult = true;
                } break;
                default: break;
                }
                return bResult ? bResult : TSuperState::EventProc( pContext, pStm, nEventId, pParams );
            }
            virtual void Exit(Context* pContext, Statemachine* pStm) {
                if (pStm->IsExitable<TThisState>()) {
                    std::cout << typeid(this).name() << " exit\n";
                    TSuperState::Exit(pContext, pStm);
                }
            }
        };
        class CrunchingData: public Active { using TThisState = CrunchingData; using TSuperState = Active;
            public: static TopState* GetInstance() { static TThisState singleInstance; return &singleInstance; }
            virtual void Entry( Context* pContext, Statemachine* pStm ){
                if( pStm->IsEnterable<TThisState>() ){
                    TSuperState::Entry( pContext, pStm );
                    std::cout << typeid(this).name() << " entry\n";
                }
            }
            virtual bool EventProc( Context* pContext, Statemachine* pStm, EventId nEventId, EventParams* pParams ){
                bool bResult = false;
                pStm->m_pSourceState = TThisState::GetInstance();
                switch( nEventId ){
                case evFinish:{
                    pStm->BgnTrans( pContext, Idle::GetInstance() );
                    pStm->EndTrans( pContext );
                    bResult = true;
                } break;
                default: break;
                }
                return bResult ? bResult : TSuperState::EventProc( pContext, pStm, nEventId, pParams );
            }
            virtual void Exit(Context* pContext, Statemachine* pStm) {
                if (pStm->IsExitable<TThisState>()) {
                    std::cout << typeid(this).name() << " exit\n";
                    TSuperState::Exit(pContext, pStm);
                }
            }
        };
        virtual bool DefaultTrans( Context* pContext ){
            bool bResult = false;
            Statemachine* pStm = this;
            bResult |= m_PollingRegionPollingRegionStm.DefaultTrans( pContext );
            do {
                if (m_pCurrentState == AirspeedSensorTop::GetInstance() && m_pPseudostate == AirspeedSensorStm::InitPt1::GetInstance()) {
                    pStm->BgnTrans( pContext, DataHandlingRegion::GetInstance(), InitPt1::GetInstance() );
                    pStm->EndTrans( pContext );
                    bResult = true;
                } else if (m_pCurrentState == Active::GetInstance() && m_pPseudostate == AirspeedSensorStm::InitialPseudostate1::GetInstance()) {
                    pStm->BgnTrans( pContext, Idle::GetInstance() );
                    pStm->EndTrans( pContext );
                    bResult = true;
                } else if (m_pCurrentState == DataHandlingRegion::GetInstance() && m_pPseudostate == AirspeedSensorStm::InitPt1::GetInstance()) {
                    pStm->BgnTrans( pContext, Inactive::GetInstance() );
                    pStm->EndTrans( pContext );
                    bResult = true;
                } else if (m_pCurrentState != m_pPseudostate && dynamic_cast<AirspeedSensorTop*>(m_pPseudostate) != NULL) {
                    pStm->BgnTrans( pContext, dynamic_cast<TopState*>(m_pPseudostate) );
                    pStm->EndTrans( pContext );
                    bResult = true;
                } else {
                }
            } while (false);
            return bResult;
        }
        virtual bool Reset(Context* pContext, Statemachine* pParentStm, StateBase* pEntryPoint) {
            m_pParentStm = pParentStm;
            if (pEntryPoint == null) {
                if (IsFinished()) {
                    m_pPseudostate = InitPt1::GetInstance();
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
        virtual bool EventProc(Context* pContext, int nEventId, EventParams* pParams){
            bool bResult = false;
            m_pLCAState = TopState::GetInstance();
            bResult |= m_PollingRegionPollingRegionStm.EventProc( pContext, nEventId, pParams );
            bResult = m_pCurrentState->EventProc(pContext, this, nEventId, pParams);
            RunToCompletion(pContext);
            return bResult;
        }
        template<class TCompositeState = TopState>
        bool IsInRecur() {
            if (m_PollingRegionPollingRegionStm.IsInRecur<TCompositeState>()) { return true; }
            if (IsIn<TCompositeState>()) { return true; }
            return false;
        }
        virtual bool Abort(Context* pContext) {
            m_pSourceState = AirspeedSensorTop::GetInstance();
            BgnTrans(pContext, AirspeedSensorTop::GetInstance());
            EndTrans(pContext);
            return true;
        }
        virtual bool IsFinished() {
            return m_pCurrentState == AirspeedSensorTop::GetInstance() && m_pCurrentState == m_pPseudostate;
        }
        AirspeedSensorStm(): Statemachine(AirspeedSensorTop::GetInstance(), AirspeedSensorTop::GetInstance()) {}
    };
    public:  AirspeedSensor(
        int _attribute0
    ):  Context( _attribute0 )
    {
    }                                                                                           
    AirspeedSensorStm mainStm;                                  
public:
    bool Start() {
        mainStm.Abort(this);
        return mainStm.Reset(this, nullptr, nullptr);
    }
    bool EventProc(EventId nEventId, EventParams* pParams) {
        return mainStm.EventProc(this, nEventId, pParams);
    }
    template<class TState>
    bool IsIn() {
        return mainStm.IsInRecur<TState>();
    }
};
