/* File generated by Đức's ClasHStamP */
#define __AirspeedSensor_INTERNAL__
#include "CommonInclude.h"
#include "AirspeedSensor.h"
const TCHAR* AirspeedSensorEvent_toString( AirspeedSensor_EVENT value ){
    switch( value ){
    case AirspeedSensor_evDataReady: return _T( "evDataReady" );
    case AirspeedSensor_evDisablePolling: return _T( "evDisablePolling" );
    case AirspeedSensor_evEnablePolling: return _T( "evEnablePolling" );
    case AirspeedSensor_evFinish: return _T( "evFinish" );
    case AirspeedSensor_evStart: return _T( "evStart" );
    case AirspeedSensor_evStop: return _T( "evStop" );
    case AirspeedSensor_tm_POLLTIME: return _T( "tm_POLLTIME" );
    default: return _T( "AirspeedSensor_UNKNOWN" );
    }
}
static void PollingRegionStm_BgnTrans( AirspeedSensor *pPollingRegionTop, PollingRegionStm* pStm, UINT32 targetState, UINT32 initState );
static void PollingRegionStm_EndTrans( AirspeedSensor *pPollingRegionTop, PollingRegionStm* pStm );
static BOOL PollingRegionStm_Reset( AirspeedSensor* pPollingRegionTop, PollingRegionStm* pStm, HdStateMachine* pParentStm, UINT32 nEntryPoint );
static BOOL PollingRegionStm_Abort( AirspeedSensor* pPollingRegionTop, PollingRegionStm* pStm );
static BOOL PollingRegionStm_EventProc( AirspeedSensor* pPollingRegionTop, PollingRegionStm* pStm, AirspeedSensor_EVENT nEventId, void* pEventParams );
static BOOL PollingRegionStm_RunToCompletion( AirspeedSensor* pPollingRegionTop, PollingRegionStm* pStm );
static void PollingRegionStm_NotAcquiring_Entry( AirspeedSensor* pAirspeedSensor, PollingRegionStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, PollingRegionStm_NotAcquiring ) ){
        printf( "%s\n", __FUNCTION__ );
    }
}
static BOOL PollingRegionStm_NotAcquiring_EventProc( AirspeedSensor* pAirspeedSensor, PollingRegionStm* pStm, AirspeedSensor_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = PollingRegionStm_NotAcquiring;
    switch( nEventId ){
    case AirspeedSensor_evEnablePolling:{
        PollingRegionStm_BgnTrans( pAirspeedSensor, pStm, PollingRegionStm_WaitingToAcquire, STATE_UNDEF );
        PollingRegionStm_EndTrans( pAirspeedSensor, pStm );
        bResult = TRUE;
    } break;
    default: break;
    }
    return bResult;
}
static void PollingRegionStm_NotAcquiring_Exit( AirspeedSensor* pAirspeedSensor, PollingRegionStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, PollingRegionStm_NotAcquiring ) ){ 
        printf( "%s\n", __FUNCTION__ );
    }
}
static void PollingRegionStm_WaitingToAcquire_Entry( AirspeedSensor* pAirspeedSensor, PollingRegionStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, PollingRegionStm_WaitingToAcquire ) ){
        printf( "%s\n", __FUNCTION__ );
    }
}
static BOOL PollingRegionStm_WaitingToAcquire_EventProc( AirspeedSensor* pAirspeedSensor, PollingRegionStm* pStm, AirspeedSensor_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = PollingRegionStm_WaitingToAcquire;
    switch( nEventId ){
    case AirspeedSensor_evDisablePolling:{
        PollingRegionStm_BgnTrans( pAirspeedSensor, pStm, PollingRegionStm_NotAcquiring, STATE_UNDEF );
        PollingRegionStm_EndTrans( pAirspeedSensor, pStm );
        bResult = TRUE;
    } break;
    case AirspeedSensor_tm_POLLTIME:{
        if (AirspeedSensor_IsIn( pAirspeedSensor, AirspeedSensorStm_Idle )) {
            pStm->base.bIsExternTrans = TRUE;
            PollingRegionStm_BgnTrans( pAirspeedSensor, pStm, PollingRegionStm_WaitingToAcquire, STATE_UNDEF );
            pStm->base.pParentStm->nPseudostate = AirspeedSensorStm_CrunchingData;
            PollingRegionStm_EndTrans( pAirspeedSensor, pStm );
            bResult = TRUE;
        }
        else {
            pStm->base.bIsExternTrans = TRUE;
            PollingRegionStm_BgnTrans( pAirspeedSensor, pStm, PollingRegionStm_WaitingToAcquire, STATE_UNDEF );
            PollingRegionStm_EndTrans( pAirspeedSensor, pStm );
            bResult = TRUE;
        }
    } break;
    default: break;
    }
    return bResult;
}
static void PollingRegionStm_WaitingToAcquire_Exit( AirspeedSensor* pAirspeedSensor, PollingRegionStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, PollingRegionStm_WaitingToAcquire ) ){ 
        printf( "%s\n", __FUNCTION__ );
    }
}
static void PollingRegionStm_EndTrans( AirspeedSensor *pAirspeedSensor, PollingRegionStm* pStm ){
    pStm->base.nCurrentState = pStm->base.nTargetState;
    pStm->base.bIsExternTrans = FALSE;
    switch( pStm->base.nCurrentState ){
    case PollingRegionStm_NotAcquiring:PollingRegionStm_NotAcquiring_Entry( pAirspeedSensor, pStm ); break;
    case PollingRegionStm_WaitingToAcquire:PollingRegionStm_WaitingToAcquire_Entry( pAirspeedSensor, pStm ); break;
    default: break;
    }
}
static void PollingRegionStm_BgnTrans( AirspeedSensor *pAirspeedSensor, PollingRegionStm* pStm, UINT32 targetState, UINT32 initState ){
    pStm->base.nTargetState = targetState;
    pStm->base.nPseudostate = targetState;
    if( initState ){
        pStm->base.nPseudostate = initState;
    }
    switch( pStm->base.nCurrentState ){
    case PollingRegionStm_NotAcquiring:PollingRegionStm_NotAcquiring_Exit( pAirspeedSensor, pStm ); break;
    case PollingRegionStm_WaitingToAcquire:PollingRegionStm_WaitingToAcquire_Exit( pAirspeedSensor, pStm ); break;
    default: break;
    }
}
static BOOL PollingRegionStm_StateDefaultTrans( AirspeedSensor* pAirspeedSensor, PollingRegionStm* pStm ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = pStm->base.nCurrentState;
    pStm->base.nLCAState = STATE_UNDEF;
    do{   if( pStm->base.nCurrentState == PollingRegionStm_PollingRegionTop && pStm->base.nPseudostate == PollingRegionStm_InitialPseudostate0 ){
        PollingRegionStm_BgnTrans( pAirspeedSensor, pStm, PollingRegionStm_NotAcquiring, STATE_UNDEF );
        PollingRegionStm_EndTrans( pAirspeedSensor, pStm );
        bResult = TRUE;
    }else if( pStm->base.nCurrentState != pStm->base.nPseudostate && IS_IN(pStm->base.nPseudostate, PollingRegionStm_PollingRegionTop) ){
        PollingRegionStm_BgnTrans( pAirspeedSensor, pStm, pStm->base.nPseudostate, STATE_UNDEF );
        PollingRegionStm_EndTrans( pAirspeedSensor, pStm );
        bResult = TRUE;
    }else{
    }   }while( FALSE );
    return bResult;
}
static BOOL PollingRegionStm_RunToCompletion( AirspeedSensor* pAirspeedSensor, PollingRegionStm* pStm ){
    BOOL bResult;
    do{
        bResult = PollingRegionStm_StateDefaultTrans( pAirspeedSensor, pStm );
    } while ( bResult );
    return bResult;
}
static BOOL PollingRegionStm_Reset( AirspeedSensor* pAirspeedSensor, PollingRegionStm* pStm, HdStateMachine* pParentStm, UINT32 nEntryPoint ) {
    pStm->base.pParentStm = pParentStm;
    if( nEntryPoint == NULL ){
        if( PollingRegionStm_IsFinished( &pStm->base ) ){
            pStm->base.nPseudostate = PollingRegionStm_InitialPseudostate0;
        }
    }else{
        if( PollingRegionStm_IsFinished( &pStm->base ) ){
            pStm->base.nPseudostate = nEntryPoint;
            return FALSE;
        }else{
            pStm->base.nPseudostate = nEntryPoint;
        }
    }
    if( nEntryPoint != STATE_UNDEF && nEntryPoint <= STATE_TOP ){
    }
    return PollingRegionStm_RunToCompletion( pAirspeedSensor, pStm );
}
static BOOL PollingRegionStm_EventProc( AirspeedSensor* pAirspeedSensor, PollingRegionStm* pStm, AirspeedSensor_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nLCAState = STATE_UNDEF;
    switch( pStm->base.nCurrentState ){
    case PollingRegionStm_NotAcquiring:         bResult |= PollingRegionStm_NotAcquiring_EventProc( pAirspeedSensor, pStm, nEventId, pEventParams ); break;
    case PollingRegionStm_WaitingToAcquire:     bResult |= PollingRegionStm_WaitingToAcquire_EventProc( pAirspeedSensor, pStm, nEventId, pEventParams ); break;
    default: break;
    }
    PollingRegionStm_RunToCompletion( pAirspeedSensor, pStm );
    return bResult;
}
static BOOL PollingRegionStm_IsIn( PollingRegionStm* pStm, UINT32 nCompositeState ) {
    if( IS_IN( pStm->base.nCurrentState, nCompositeState ) ){ return TRUE; }
    return FALSE;
}
static BOOL PollingRegionStm_Abort( AirspeedSensor* pAirspeedSensor, PollingRegionStm* pStm ) {
    pStm->base.nSourceState = PollingRegionStm_PollingRegionTop;
    PollingRegionStm_BgnTrans( pAirspeedSensor, pStm, PollingRegionStm_PollingRegionTop, STATE_UNDEF );
    PollingRegionStm_EndTrans( pAirspeedSensor, pStm );
    return TRUE;
}
int PollingRegionStm_IsFinished(PollingRegionStm* pPollingRegionStm){
    return pPollingRegionStm->base.nCurrentState == PollingRegionStm_PollingRegionTop && pPollingRegionStm->base.nCurrentState == pPollingRegionStm->base.nPseudostate;
}
static void AirspeedSensorStm_BgnTrans( AirspeedSensor *pAirspeedSensorTop, AirspeedSensorStm* pStm, UINT32 targetState, UINT32 initState );
static void AirspeedSensorStm_EndTrans( AirspeedSensor *pAirspeedSensorTop, AirspeedSensorStm* pStm );
static BOOL AirspeedSensorStm_Reset( AirspeedSensor* pAirspeedSensorTop, AirspeedSensorStm* pStm, HdStateMachine* pParentStm, UINT32 nEntryPoint );
static BOOL AirspeedSensorStm_Abort( AirspeedSensor* pAirspeedSensorTop, AirspeedSensorStm* pStm );
static BOOL AirspeedSensorStm_EventProc( AirspeedSensor* pAirspeedSensorTop, AirspeedSensorStm* pStm, AirspeedSensor_EVENT nEventId, void* pEventParams );
static BOOL AirspeedSensorStm_RunToCompletion( AirspeedSensor* pAirspeedSensorTop, AirspeedSensorStm* pStm );
static void AirspeedSensorStm_DataHandlingRegion_Entry( AirspeedSensor* pAirspeedSensor, AirspeedSensorStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, AirspeedSensorStm_DataHandlingRegion ) ){
        printf( "%s\n", __FUNCTION__ );
        PollingRegionStm_Reset( pAirspeedSensor, &pStm->PollingRegionPollingRegionStm, &pStm->base, STATE_UNDEF );
    }
}
static BOOL AirspeedSensorStm_DataHandlingRegion_EventProc( AirspeedSensor* pAirspeedSensor, AirspeedSensorStm* pStm, AirspeedSensor_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = AirspeedSensorStm_DataHandlingRegion;
    return bResult;
}
static void AirspeedSensorStm_DataHandlingRegion_Exit( AirspeedSensor* pAirspeedSensor, AirspeedSensorStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, AirspeedSensorStm_DataHandlingRegion ) ){ 
        PollingRegionStm_Abort( pAirspeedSensor, &pStm->PollingRegionPollingRegionStm );
        printf( "%s\n", __FUNCTION__ );
    }
}
static void AirspeedSensorStm_Inactive_Entry( AirspeedSensor* pAirspeedSensor, AirspeedSensorStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, AirspeedSensorStm_Inactive ) ){
        AirspeedSensorStm_DataHandlingRegion_Entry( pAirspeedSensor, pStm );
        printf( "%s\n", __FUNCTION__ );
    }
}
static BOOL AirspeedSensorStm_Inactive_EventProc( AirspeedSensor* pAirspeedSensor, AirspeedSensorStm* pStm, AirspeedSensor_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = AirspeedSensorStm_Inactive;
    switch( nEventId ){
    case AirspeedSensor_evStart:{
        if (AirspeedSensor_IsIn( pAirspeedSensor, PollingRegionStm_NotAcquiring )) {
            AirspeedSensorStm_BgnTrans( pAirspeedSensor, pStm, AirspeedSensorStm_Active, AirspeedSensorStm_InitialPseudostate1 );
            PollingRegionStm_Reset( pAirspeedSensor, &pStm->PollingRegionPollingRegionStm, &pStm->base, PollingRegionStm_WaitingToAcquire );
            AirspeedSensorStm_EndTrans( pAirspeedSensor, pStm );
            bResult = TRUE;
        }
        else {
            AirspeedSensorStm_BgnTrans( pAirspeedSensor, pStm, AirspeedSensorStm_Active, AirspeedSensorStm_InitialPseudostate1 );
            AirspeedSensorStm_EndTrans( pAirspeedSensor, pStm );
            bResult = TRUE;
        }
    } break;
    default: break;
    }
    return bResult ? bResult : AirspeedSensorStm_DataHandlingRegion_EventProc( pAirspeedSensor, pStm, nEventId, pEventParams );
}
static void AirspeedSensorStm_Inactive_Exit( AirspeedSensor* pAirspeedSensor, AirspeedSensorStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, AirspeedSensorStm_Inactive ) ){ 
        printf( "%s\n", __FUNCTION__ );
        AirspeedSensorStm_DataHandlingRegion_Exit( pAirspeedSensor, pStm );
    }
}
static void AirspeedSensorStm_Active_Entry( AirspeedSensor* pAirspeedSensor, AirspeedSensorStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, AirspeedSensorStm_Active ) ){
        AirspeedSensorStm_DataHandlingRegion_Entry( pAirspeedSensor, pStm );
        printf( "%s\n", __FUNCTION__ );
    }
}
static BOOL AirspeedSensorStm_Active_EventProc( AirspeedSensor* pAirspeedSensor, AirspeedSensorStm* pStm, AirspeedSensor_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = AirspeedSensorStm_Active;
    switch( nEventId ){
    case AirspeedSensor_evStop:{
        if (AirspeedSensor_IsIn( pAirspeedSensor, PollingRegionStm_WaitingToAcquire )) {
            AirspeedSensorStm_BgnTrans( pAirspeedSensor, pStm, AirspeedSensorStm_Inactive, STATE_UNDEF );
            PollingRegionStm_Reset( pAirspeedSensor, &pStm->PollingRegionPollingRegionStm, &pStm->base, PollingRegionStm_NotAcquiring );
            AirspeedSensorStm_EndTrans( pAirspeedSensor, pStm );
            bResult = TRUE;
        }
        else {
            AirspeedSensorStm_BgnTrans( pAirspeedSensor, pStm, AirspeedSensorStm_Inactive, STATE_UNDEF );
            AirspeedSensorStm_EndTrans( pAirspeedSensor, pStm );
            bResult = TRUE;
        }
    } break;
    default: break;
    }
    return bResult ? bResult : AirspeedSensorStm_DataHandlingRegion_EventProc( pAirspeedSensor, pStm, nEventId, pEventParams );
}
static void AirspeedSensorStm_Active_Exit( AirspeedSensor* pAirspeedSensor, AirspeedSensorStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, AirspeedSensorStm_Active ) ){ 
        printf( "%s\n", __FUNCTION__ );
        AirspeedSensorStm_DataHandlingRegion_Exit( pAirspeedSensor, pStm );
    }
}
static void AirspeedSensorStm_Idle_Entry( AirspeedSensor* pAirspeedSensor, AirspeedSensorStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, AirspeedSensorStm_Idle ) ){
        AirspeedSensorStm_Active_Entry( pAirspeedSensor, pStm );
        printf( "%s\n", __FUNCTION__ );
    }
}
static BOOL AirspeedSensorStm_Idle_EventProc( AirspeedSensor* pAirspeedSensor, AirspeedSensorStm* pStm, AirspeedSensor_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = AirspeedSensorStm_Idle;
    switch( nEventId ){
    case AirspeedSensor_evDataReady:{
        AirspeedSensorStm_BgnTrans( pAirspeedSensor, pStm, AirspeedSensorStm_CrunchingData, STATE_UNDEF );
        AirspeedSensorStm_EndTrans( pAirspeedSensor, pStm );
        bResult = TRUE;
    } break;
    default: break;
    }
    return bResult ? bResult : AirspeedSensorStm_Active_EventProc( pAirspeedSensor, pStm, nEventId, pEventParams );
}
static void AirspeedSensorStm_Idle_Exit( AirspeedSensor* pAirspeedSensor, AirspeedSensorStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, AirspeedSensorStm_Idle ) ){ 
        printf( "%s\n", __FUNCTION__ );
        AirspeedSensorStm_Active_Exit( pAirspeedSensor, pStm );
    }
}
static void AirspeedSensorStm_CrunchingData_Entry( AirspeedSensor* pAirspeedSensor, AirspeedSensorStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, AirspeedSensorStm_CrunchingData ) ){
        AirspeedSensorStm_Active_Entry( pAirspeedSensor, pStm );
        printf( "%s\n", __FUNCTION__ );
    }
}
static BOOL AirspeedSensorStm_CrunchingData_EventProc( AirspeedSensor* pAirspeedSensor, AirspeedSensorStm* pStm, AirspeedSensor_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = AirspeedSensorStm_CrunchingData;
    switch( nEventId ){
    case AirspeedSensor_evFinish:{
        AirspeedSensorStm_BgnTrans( pAirspeedSensor, pStm, AirspeedSensorStm_Idle, STATE_UNDEF );
        AirspeedSensorStm_EndTrans( pAirspeedSensor, pStm );
        bResult = TRUE;
    } break;
    default: break;
    }
    return bResult ? bResult : AirspeedSensorStm_Active_EventProc( pAirspeedSensor, pStm, nEventId, pEventParams );
}
static void AirspeedSensorStm_CrunchingData_Exit( AirspeedSensor* pAirspeedSensor, AirspeedSensorStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, AirspeedSensorStm_CrunchingData ) ){ 
        printf( "%s\n", __FUNCTION__ );
        AirspeedSensorStm_Active_Exit( pAirspeedSensor, pStm );
    }
}
static void AirspeedSensorStm_EndTrans( AirspeedSensor *pAirspeedSensor, AirspeedSensorStm* pStm ){
    pStm->base.nCurrentState = pStm->base.nTargetState;
    pStm->base.bIsExternTrans = FALSE;
    switch( pStm->base.nCurrentState ){
    case AirspeedSensorStm_DataHandlingRegion:AirspeedSensorStm_DataHandlingRegion_Entry( pAirspeedSensor, pStm ); break;
    case AirspeedSensorStm_Inactive:AirspeedSensorStm_Inactive_Entry( pAirspeedSensor, pStm ); break;
    case AirspeedSensorStm_Active:AirspeedSensorStm_Active_Entry( pAirspeedSensor, pStm ); break;
    case AirspeedSensorStm_Idle:AirspeedSensorStm_Idle_Entry( pAirspeedSensor, pStm ); break;
    case AirspeedSensorStm_CrunchingData:AirspeedSensorStm_CrunchingData_Entry( pAirspeedSensor, pStm ); break;
    default: break;
    }
}
static void AirspeedSensorStm_BgnTrans( AirspeedSensor *pAirspeedSensor, AirspeedSensorStm* pStm, UINT32 targetState, UINT32 initState ){
    pStm->base.nTargetState = targetState;
    pStm->base.nPseudostate = targetState;
    if( initState ){
        pStm->base.nPseudostate = initState;
    }
    switch( pStm->base.nCurrentState ){
    case AirspeedSensorStm_DataHandlingRegion:AirspeedSensorStm_DataHandlingRegion_Exit( pAirspeedSensor, pStm ); break;
    case AirspeedSensorStm_Inactive:AirspeedSensorStm_Inactive_Exit( pAirspeedSensor, pStm ); break;
    case AirspeedSensorStm_Active:AirspeedSensorStm_Active_Exit( pAirspeedSensor, pStm ); break;
    case AirspeedSensorStm_Idle:AirspeedSensorStm_Idle_Exit( pAirspeedSensor, pStm ); break;
    case AirspeedSensorStm_CrunchingData:AirspeedSensorStm_CrunchingData_Exit( pAirspeedSensor, pStm ); break;
    default: break;
    }
}
static BOOL AirspeedSensorStm_StateDefaultTrans( AirspeedSensor* pAirspeedSensor, AirspeedSensorStm* pStm ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = pStm->base.nCurrentState;
    pStm->base.nLCAState = STATE_UNDEF;
    bResult |= PollingRegionStm_StateDefaultTrans( pAirspeedSensor, &pStm->PollingRegionPollingRegionStm );
    do{   if( pStm->base.nCurrentState == AirspeedSensorStm_AirspeedSensorTop && pStm->base.nPseudostate == AirspeedSensorStm_InitPt1 ){
        AirspeedSensorStm_BgnTrans( pAirspeedSensor, pStm, AirspeedSensorStm_DataHandlingRegion, AirspeedSensorStm_InitPt1 );
        AirspeedSensorStm_EndTrans( pAirspeedSensor, pStm );
        bResult = TRUE;
    }else if( pStm->base.nCurrentState == AirspeedSensorStm_Active && pStm->base.nPseudostate == AirspeedSensorStm_InitialPseudostate1 ){
        AirspeedSensorStm_BgnTrans( pAirspeedSensor, pStm, AirspeedSensorStm_Idle, STATE_UNDEF );
        AirspeedSensorStm_EndTrans( pAirspeedSensor, pStm );
        bResult = TRUE;
    }else if( pStm->base.nCurrentState == AirspeedSensorStm_DataHandlingRegion && pStm->base.nPseudostate == AirspeedSensorStm_InitPt1 ){
        AirspeedSensorStm_BgnTrans( pAirspeedSensor, pStm, AirspeedSensorStm_Inactive, STATE_UNDEF );
        AirspeedSensorStm_EndTrans( pAirspeedSensor, pStm );
        bResult = TRUE;
    }else if( pStm->base.nCurrentState != pStm->base.nPseudostate && IS_IN(pStm->base.nPseudostate, AirspeedSensorStm_AirspeedSensorTop) ){
        AirspeedSensorStm_BgnTrans( pAirspeedSensor, pStm, pStm->base.nPseudostate, STATE_UNDEF );
        AirspeedSensorStm_EndTrans( pAirspeedSensor, pStm );
        bResult = TRUE;
    }else{
    }   }while( FALSE );
    return bResult;
}
static BOOL AirspeedSensorStm_RunToCompletion( AirspeedSensor* pAirspeedSensor, AirspeedSensorStm* pStm ){
    BOOL bResult;
    do{
        bResult = AirspeedSensorStm_StateDefaultTrans( pAirspeedSensor, pStm );
    } while ( bResult );
    return bResult;
}
static BOOL AirspeedSensorStm_Reset( AirspeedSensor* pAirspeedSensor, AirspeedSensorStm* pStm, HdStateMachine* pParentStm, UINT32 nEntryPoint ) {
    pStm->base.pParentStm = pParentStm;
    if( nEntryPoint == NULL ){
        if( AirspeedSensorStm_IsFinished( &pStm->base ) ){
            pStm->base.nPseudostate = AirspeedSensorStm_InitPt1;
        }
    }else{
        if( AirspeedSensorStm_IsFinished( &pStm->base ) ){
            pStm->base.nPseudostate = nEntryPoint;
            return FALSE;
        }else{
            pStm->base.nPseudostate = nEntryPoint;
        }
    }
    if( nEntryPoint != STATE_UNDEF && nEntryPoint <= STATE_TOP ){
        PollingRegionStm_Reset( pAirspeedSensor, &pStm->PollingRegionPollingRegionStm, &pStm->base, nEntryPoint );
    }
    return AirspeedSensorStm_RunToCompletion( pAirspeedSensor, pStm );
}
static BOOL AirspeedSensorStm_EventProc( AirspeedSensor* pAirspeedSensor, AirspeedSensorStm* pStm, AirspeedSensor_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nLCAState = STATE_UNDEF;
    bResult |= PollingRegionStm_EventProc( pAirspeedSensor, &pStm->PollingRegionPollingRegionStm, nEventId, pEventParams );
    switch( pStm->base.nCurrentState ){
    case AirspeedSensorStm_DataHandlingRegion:  bResult |= AirspeedSensorStm_DataHandlingRegion_EventProc( pAirspeedSensor, pStm, nEventId, pEventParams ); break;
    case AirspeedSensorStm_Inactive:            bResult |= AirspeedSensorStm_Inactive_EventProc( pAirspeedSensor, pStm, nEventId, pEventParams ); break;
    case AirspeedSensorStm_Active:              bResult |= AirspeedSensorStm_Active_EventProc( pAirspeedSensor, pStm, nEventId, pEventParams ); break;
    case AirspeedSensorStm_Idle:                bResult |= AirspeedSensorStm_Idle_EventProc( pAirspeedSensor, pStm, nEventId, pEventParams ); break;
    case AirspeedSensorStm_CrunchingData:       bResult |= AirspeedSensorStm_CrunchingData_EventProc( pAirspeedSensor, pStm, nEventId, pEventParams ); break;
    default: break;
    }
    AirspeedSensorStm_RunToCompletion( pAirspeedSensor, pStm );
    return bResult;
}
static BOOL AirspeedSensorStm_IsIn( AirspeedSensorStm* pStm, UINT32 nCompositeState ) {
    if( PollingRegionStm_IsIn( &pStm->PollingRegionPollingRegionStm, nCompositeState ) ){ return TRUE; }
    if( IS_IN( pStm->base.nCurrentState, nCompositeState ) ){ return TRUE; }
    return FALSE;
}
static BOOL AirspeedSensorStm_Abort( AirspeedSensor* pAirspeedSensor, AirspeedSensorStm* pStm ) {
    pStm->base.nSourceState = AirspeedSensorStm_AirspeedSensorTop;
    AirspeedSensorStm_BgnTrans( pAirspeedSensor, pStm, AirspeedSensorStm_AirspeedSensorTop, STATE_UNDEF );
    AirspeedSensorStm_EndTrans( pAirspeedSensor, pStm );
    return TRUE;
}
int AirspeedSensorStm_IsFinished(AirspeedSensorStm* pAirspeedSensorStm){
    return pAirspeedSensorStm->base.nCurrentState == AirspeedSensorStm_AirspeedSensorTop && pAirspeedSensorStm->base.nCurrentState == pAirspeedSensorStm->base.nPseudostate;
}
Context* AirspeedSensor_Copy( AirspeedSensor* pAirspeedSensor, const AirspeedSensor* pSource ){
    Context_Copy( ( Context* )pAirspeedSensor, ( Context* )pSource );
    return ( Context* )pAirspeedSensor;
}
BOOL AirspeedSensor_EventProc( AirspeedSensor* pAirspeedSensor, AirspeedSensor_EVENT nEventId, void* pEventParams ){
    return AirspeedSensorStm_EventProc( pAirspeedSensor, &pAirspeedSensor->mainStm, nEventId, pEventParams );
}
BOOL AirspeedSensor_Start( AirspeedSensor* pAirspeedSensor ){
    AirspeedSensorStm_Abort( pAirspeedSensor, &pAirspeedSensor->mainStm );
    return AirspeedSensorStm_Reset( pAirspeedSensor, &pAirspeedSensor->mainStm, NULL, STATE_UNDEF );
}
BOOL AirspeedSensor_IsIn( AirspeedSensor* pAirspeedSensor, UINT32 nState ){
    return AirspeedSensorStm_IsIn( &pAirspeedSensor->mainStm, nState );
}
