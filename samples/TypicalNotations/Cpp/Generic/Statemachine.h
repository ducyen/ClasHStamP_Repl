#pragma once
#include <iostream>
#include <cassert>

class Context;
union EventParams{};
using EventId = int;

class Statemachine;

class StateBase { 
    virtual void dummy() {};
};

template < typename T >
class Pseudostate: public StateBase {
public:
    static T* GetInstance() {
        static T singleInstance;
        return &singleInstance;
    }
};

class TopState : public Pseudostate<TopState> {
public:
    virtual void Entry(Context* pContext, Statemachine* pStm) { return; }
    virtual void Exit(Context* pContext, Statemachine* pStm) { return; }
    virtual bool EventProc(Context* pContext, Statemachine* pStm, int nEventId, EventParams* pParams) { return false; }
};

class Statemachine {
public:
    bool          m_bIsExternTrans;
    TopState*     m_pLCAState;
    TopState*     m_pTargetState;
    StateBase*    m_pPseudostate;
    TopState*     m_pCurrentState;
    Statemachine* m_pParentStm;
    TopState*     m_pSourceState;

public:
    Statemachine(TopState* pCurrentState, TopState* pPseudostate):
        m_pParentStm(nullptr),
        m_bIsExternTrans(false),
        m_pCurrentState(pCurrentState),
        m_pLCAState(TopState::GetInstance()),
        m_pTargetState(TopState::GetInstance()),
        m_pSourceState(TopState::GetInstance()),
        m_pPseudostate(pPseudostate)
    {
    }
    template<class TCompositeState = TopState>
    static bool IsIn(StateBase* pLeafState) {
        bool bResult = dynamic_cast<TCompositeState*>(pLeafState) != nullptr;
        return bResult;
    }
    template<class TCompositeState = TopState>
    bool IsIn() {
        bool bResult = dynamic_cast<TCompositeState*>(m_pCurrentState) != nullptr;
        return bResult;
    }
    template<class TThisState = TopState>
    bool IsEnterable() {
        bool isThisLCA = IsIn<TThisState>(m_pLCAState);
        if (!isThisLCA) {
            return true;
        }
        return false;
    }
    template<class TThisState = TopState>
    bool IsExitable() {
        bool isThisLCA = IsIn<TThisState>(m_pSourceState) && IsIn<TThisState>(m_pTargetState);
        if (!isThisLCA) {
            return true;
        } else if (m_bIsExternTrans) {
            m_bIsExternTrans = false;
            return true;
        } else { 
            m_pLCAState = TThisState::GetInstance();
        }
        return false;
    }
    bool IsFinished() {
        return m_pCurrentState == TopState::GetInstance() && m_pCurrentState == m_pPseudostate;
    }
    void EndTrans(Context* pContext) {
        m_pCurrentState = m_pTargetState;
        m_pCurrentState->Entry(pContext, this);
    }
    void BgnTrans(Context* pContext, TopState* pTargetState) {
        BgnTrans(pContext, pTargetState, pTargetState);
    }
    void BgnTrans(Context* pContext, TopState* pTargetState, StateBase* pPseudostate) {
        m_pTargetState = pTargetState;
        m_pPseudostate = pPseudostate;
        m_pCurrentState->Exit(pContext, this);
    }
    virtual bool DefaultTrans(Context* pContext) = 0;
    virtual bool EventProc(Context* pContext, int nEventId, EventParams* pParams){
        bool bResult = false;
        m_pLCAState = TopState::GetInstance();
        bResult = m_pCurrentState->EventProc(pContext, this, nEventId, pParams);
        RunToCompletion(pContext);
        return bResult;
    }
    bool RunToCompletion(Context* pContext) {
        bool bResult;
        do {
            m_pSourceState = m_pCurrentState;
            m_pLCAState = TopState::GetInstance();
            bResult = DefaultTrans(pContext);
        } while (bResult);
        return bResult;
    }
    virtual bool Reset(Context* pContext, Statemachine* pParentStm, StateBase* pEntryPoint) = 0;
    bool Abort(Context* pContext) {
        m_pSourceState = TopState::GetInstance();
        BgnTrans(pContext, TopState::GetInstance());
        EndTrans(pContext);
        return true;
    }
};

template <typename T, typename C> class property {
        T value;
        C* m_pContext;
    protected:
        property(C* pContext): m_pContext(pContext) {}
    public:
        T & operator = (const T &i) {
            return value = i;
        }
        // This template class member function template serves the purpose to make
        // typing more strict. Assignment to this is only possible with exact identical
        // types.
        template <typename T2> T2 & operator = (const T2 &i) {
            T2 &guard = value;
            throw guard; // Never reached.
        }

        // Implicit conversion back to T. 
        operator T const & () const {
            return value;
        }
};
