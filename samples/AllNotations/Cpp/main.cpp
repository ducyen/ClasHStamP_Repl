#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#if defined(_MSC_VER)
#include <Windows.h>
#include <gdiplus.h>
#endif

int InputValue(char* pMsg);
void DisplayMsg(char* pMsg);

#include "Generic/Statemachine.h"  /* @todo Duc */
#include "Model/Context.hpp"
#include "Model/ContextImpl.hpp"

int InputValue(char* pMsg) {
    char n;
    std::cout << pMsg;
    std::cin  >> n;
    return n - '0';
}

void DisplayMsg(char* pMsg) {
    std::cout << pMsg << std::endl;
}

#if defined(_MSC_VER)
#pragma comment(lib, "gdiplus.lib")

using namespace Gdiplus;

int GetEncoderClsid(const WCHAR* mimeType, CLSID* clsid);

int DrawRectangle()
{
    // Initialize GDI+
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;

    if (GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr) == Ok) {
        // Load the input PNG file
        const WCHAR* inputFilePath = L"../Image/Design/Model/ContextImpl/MainStm.png";
        Bitmap inputBitmap(inputFilePath, FALSE);

        if (inputBitmap.GetLastStatus() != Ok)
        {
            std::cerr << "Error loading the input PNG file." << std::endl;
            GdiplusShutdown(gdiplusToken);
            return 1;
        }

        // Get image dimensions
        int width = inputBitmap.GetWidth();
        int height = inputBitmap.GetHeight();

        Graphics graphics(&inputBitmap);

        // Create a Pen object to draw a rectangle
        Pen pen(Color(255, 0, 0, 255), 5); // Red color with a width of 5 pixels

        // Draw a rectangle on the bitmap
        graphics.DrawRectangle(&pen, 50, 50, 200, 100); // X, Y, Width, Height

        // Save the flipped image to a PNG file
        const WCHAR* outputFilePath = L"../TransImg/Design/Model/ContextImpl/MainStm.png";
        CLSID pngClsid;
        GetEncoderClsid(L"image/png", &pngClsid);
        inputBitmap.Save(outputFilePath, &pngClsid, nullptr);
    }

    // Shutdown GDI+
    GdiplusShutdown(gdiplusToken);

    std::cout << "Image flipped and saved successfully." << std::endl;

    return 0;
}

// Function to get the encoder CLSID for the specified MIME type
int GetEncoderClsid(const WCHAR* mimeType, CLSID* clsid)
{
    UINT num = 0; // number of image encoders
    UINT size = 0; // size of the image encoder array in bytes

    GetImageEncodersSize(&num, &size);
    if (size == 0)
        return -1;

    ImageCodecInfo* imageCodecInfo = (ImageCodecInfo*)(malloc(size));
    if (imageCodecInfo == nullptr)
        return -1;

    GetImageEncoders(num, size, imageCodecInfo);

    for (UINT i = 0; i < num; ++i)
    {
        if (wcscmp(imageCodecInfo[i].MimeType, mimeType) == 0)
        {
            *clsid = imageCodecInfo[i].Clsid;
            free(imageCodecInfo);
            return i;
        }
    }

    free(imageCodecInfo);
    return -1;
}
#endif

int main() {
    std::vector<Composition*> compositions;
    ContextImpl ctxTest( 4, "", 1, 2, 3, compositions );
    int n;
    do {
        ctxTest.Start();
        do {
            n = InputValue( "Enter event number('q': quit, 'r':restart): E" );

            EventParams* pParams = nullptr;
            ContextImpl::E1Params e1Params;
            e1Params.x = ContextImpl::AnEnum::Two;
            if (n == ContextImpl::_EventId::E1) {
                pParams = &e1Params;
            }

            ctxTest.EventProc((EventId)n, pParams);
        } while (n+'0' != 'q' && n+'0' != 'r');
    }while (n+'0' != 'q');

}