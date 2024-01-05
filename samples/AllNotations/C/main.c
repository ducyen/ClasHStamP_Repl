#pragma warning(disable : 4996)
#define __Main_INTERNAL__
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#if defined( _MSC_VER )
#include <windows.h>
#include <wincodec.h>
#endif

int InputValue(char* pMsg);
void DisplayMsg(char* pMsg);

#include "CommonInclude.h"
#include "Model/ContextImpl.h"

int InputValue(char* pMsg) {
    char n;
    printf( "%s", pMsg );
    scanf( "%c", &n );
    char c = 0;
    while( c != '\n' ){
        scanf( "%c", &c );
    }
    return n - '0';
}

void DisplayMsg(char* pMsg) {
    printf( "%s\n", pMsg );
}

#if defined( _MSC_VER )
#define CALL(ptr, method, ...) ((ptr)->lpVtbl->method((ptr), __VA_ARGS__))

int DrawRectangle()
{
    HRESULT hr = S_OK;

    hr = CoInitialize( NULL );
    if( FAILED( hr ) ){
        printf( "Failed to initialize COM: %08X\n", hr );
        return 1;
    }

    IWICImagingFactory* m_pIWICFactory = NULL;

    // Create WIC factory
    hr = CoCreateInstance(
        &CLSID_WICImagingFactory,
        NULL,
        CLSCTX_INPROC_SERVER,
        &IID_IWICImagingFactory,
        &m_pIWICFactory
    );

    IWICBitmapDecoder *pIDecoder = NULL;
    IWICBitmapFrameDecode *pIDecoderFrame = NULL;

    hr = CALL( m_pIWICFactory, CreateDecoderFromFilename,
        L"../Image/Design/Model/ContextImpl/MainStm.png",                  // Image to be decoded
        NULL,                           // Do not prefer a particular vendor
        GENERIC_READ,                   // Desired read access to the file
        WICDecodeMetadataCacheOnDemand, // Cache metadata when needed
        &pIDecoder                      // Pointer to the decoder
    );

    // Retrieve the first bitmap frame.
    if( SUCCEEDED( hr ) ){
        hr = CALL( pIDecoder, GetFrame, 0, &pIDecoderFrame );
    }

    IWICBitmap *pIBitmap = NULL;
    IWICBitmapLock *pILock = NULL;

    // Create the bitmap from the image frame.
    if( SUCCEEDED( hr ) ){
        hr = CALL( m_pIWICFactory, CreateBitmapFromSource,
            pIDecoderFrame,          // Create a bitmap from the image frame
            WICBitmapCacheOnDemand,  // Cache bitmap pixels on first access
            &pIBitmap );              // Pointer to the bitmap
    }

    if( SUCCEEDED( hr ) ){
        UINT uiWidth = 10;
        UINT uiHeight = 10;

        hr = CALL( pIBitmap, GetSize, &uiWidth, &uiHeight );
        if( FAILED( hr ) ) return hr;

        WICRect rcLock = { 0, 0, uiWidth, uiHeight };

        // Obtain a bitmap lock for exclusive write.
        // The lock is for a 10x10 rectangle starting at the top left of the
        // bitmap.
        hr = CALL( pIBitmap, Lock, &rcLock, WICBitmapLockWrite, &pILock );

        if( SUCCEEDED( hr ) ){
            UINT cbBufferSize = 0;
            BYTE *pv = NULL;

            // Retrieve a pointer to the pixel data.
            if( SUCCEEDED( hr ) ){
                hr = CALL( pILock, GetDataPointer, &cbBufferSize, &pv );
            }

            // Pixel manipulation using the image data pointer pv.
            UINT cbStride;
            hr = CALL( pILock, GetStride, &cbStride );
            // Draw the rectangle on the destination bitmap
            for( UINT y = 10; y < 110 && y < uiHeight; y++ ){
                for( UINT x = 10; x < 110 && x < uiWidth; x++ ){
                    UINT srcIndex = y * cbStride + x * 4;
                    UINT destIndex = y * cbStride + x * 4;

                    // For simplicity, we'll just set the pixel to red (assuming 32bpp BGRA format)
                    pv[ destIndex ] = 0;       // Blue
                    pv[ destIndex + 1 ] = 0;   // Green
                    pv[ destIndex + 2 ] = 255; // Red
                    pv[ destIndex + 3 ] = 255; // Alpha
                }
            }

            // Release the bitmap lock.
            CALL( pILock, Release );

        }
    }
    if( pIDecoder ) CALL( pIDecoder, Release );
    if( pIDecoderFrame ) CALL( pIDecoderFrame, Release );

    if( SUCCEEDED( hr ) ){
        IWICStream* pStream = NULL;
        IWICBitmapEncoder* pEncoder = NULL;
        IWICBitmapFrameEncode* pFrameEncode = NULL;

        hr = CALL( m_pIWICFactory, CreateStream, &pStream );

        if( SUCCEEDED( hr ) ){
            hr = CALL( pStream, InitializeFromFilename, L"../TransImg/Design/Model/ContextImpl/MainStm.png", GENERIC_WRITE );
        }

        if( SUCCEEDED( hr ) ){
            hr = CALL( m_pIWICFactory, CreateEncoder, &GUID_ContainerFormatPng, NULL, &pEncoder );
        }

        if( SUCCEEDED( hr ) ){
            hr = CALL( pEncoder, Initialize, pStream, WICBitmapEncoderNoCache );
        }

        if( SUCCEEDED( hr ) ){
            hr = CALL( pEncoder, CreateNewFrame, &pFrameEncode, NULL );
        }

        if( SUCCEEDED( hr ) ){
            hr = CALL( pFrameEncode, Initialize, NULL );
        }

        if( SUCCEEDED( hr ) ){
            hr = CALL( pFrameEncode, WriteSource, pIBitmap, NULL );
        }

        if( SUCCEEDED( hr ) ){
            hr = CALL( pFrameEncode, Commit );
        }

        if( SUCCEEDED( hr ) ){
            hr = CALL( pEncoder, Commit );
        }
        if( pFrameEncode ) CALL( pFrameEncode, Release );
        if( pEncoder ) CALL( pEncoder, Release );
        if( pStream ) CALL( pStream, Release );
    }

    if( pIBitmap ) CALL( pIBitmap, Release );
    if( m_pIWICFactory ) CALL( m_pIWICFactory, Release );
    CoUninitialize();

}

// Linker pragmas
#pragma comment(lib, "windowscodecs.lib")

#endif

void ShowEntry( char* pMsg ){
    /*
    printf( "Tokens:\n" );

    char seps[] = ",";
    char *token;

    // Establish string and get the first token:
    token = strtok( pMsg, seps ); // C4996
    // Note: strtok is deprecated; consider using strtok_s instead
    while( token != NULL ){
        // While there are tokens in "string"
        printf( " %s\n", token );

        // Get next token:
        token = strtok( NULL, seps ); // C4996
    }
    */
    DisplayMsg( pMsg );
}

void ShowExit( char* pMsg ){
    DisplayMsg( pMsg );
}

int main( void ){
    ContextImpl context = ContextImpl_Ctor( ContextImpl_Init( 
        4, "", 1, 2, 3, { 0 },
        Composition_Ctor( Composition_Init( 3 ), )
    ), );
    char n;
    do {
        ContextImpl_Start( &context );
        do {
            n = InputValue( "Enter event number('q': quit, 'r':restart): E" );
            EventParams* pParams = NULL;
            E1Params e1Params = { .x = Two };
            if (n == ContextImpl_E1) {
                pParams = &e1Params;
            }
            ContextImpl_EventProc( &context, (ContextImpl_EVENT)n, pParams);
        } while (n+'0' != 'q' && n+'0' != 'r');
    }while (n+'0' != 'q');
    return 0;
}