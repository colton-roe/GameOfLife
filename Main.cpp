#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include <d2d1.h>
#include <Shobjidl.h>

#pragma comment(lib, "d2d1")
#pragma comment(lib, "Comctl32")

#include "BaseWindow.h"
#include "EditGridWindow.h"
#include "CellGrid.h"
#include "GridWindow.h"

// Must be using windows subsystem
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, _In_ PWSTR pCmdLine, _In_ INT nCmdShow)
{
    // Initialize COM
    if (CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE) != 0)
    {
        return 0;
    }

    // Creation of the main window
    GridWindow win;
    if (!win.Create(L"Game of Life", WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN))
    {
        return 0;
    }
    ShowWindow(win.Window(), nCmdShow);

    // Run the message loop
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Uninitialize COM
    CoUninitialize();

    return 0;
}

