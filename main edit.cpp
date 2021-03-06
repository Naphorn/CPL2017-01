#include <windows.h>
#include <tchar.h>

// Global Variables:
HINSTANCE hInst;							// current instance
TCHAR szTitle[] = "Easywin32";				// The title bar text
TCHAR szWindowClass[] = "WinApp";			// the class name
void Marker(LONG x, LONG y, int Index, HWND hwnd);
int Index;
int HelloIndex =1 ;
char szchar[50] = { 0 };

HPEN hPen;
BOOL fDraw = FALSE; POINT ptPrevious;
COLORREF Color[] = { RGB(255,0,0),RGB(0,255,0),RGB(0,0,255),RGB(0,0,0) };

// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);


int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow)
{
	// TODO: Place code here.
	MSG msg;

	// Register Class 
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}


//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage is only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. 
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = (WNDPROC)WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HANDLE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // Store instance handle in our global variable

	hWnd = CreateWindow(szWindowClass,szTitle,WS_OVERLAPPEDWINDOW,
						CW_USEDEFAULT,0,CW_USEDEFAULT,0, NULL, NULL,
						hInstance, NULL);

		if (!hWnd)
		{
			return FALSE;
		}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rt;
	char szHello[50] = "Hello, C-Free!";

	switch (message)
	{
	case WM_LBUTTONDOWN:
		fDraw = TRUE;
		ptPrevious.x = LOWORD(lParam);
		ptPrevious.y = HIWORD(lParam);
		return 0L;

	case WM_LBUTTONUP:
		if (fDraw)
		{
			hdc = GetDC(hWnd);
			MoveToEx(hdc, ptPrevious.x, ptPrevious.y, NULL);
			LineTo(hdc, LOWORD(lParam), HIWORD(lParam));
			ReleaseDC(hWnd, hdc);
		}
		fDraw = FALSE;
		return 0L;

	case WM_MOUSEMOVE:
		if (fDraw)
		{
			hdc = GetDC(hWnd);
			MoveToEx(hdc, ptPrevious.x, ptPrevious.y, NULL);
			LineTo(hdc, ptPrevious.x = LOWORD(lParam),
				ptPrevious.y = HIWORD(lParam));
			ReleaseDC(hWnd, hdc);
		}
		return 0L;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		// TODO: Add any drawing code here...
		GetClientRect(hWnd, &rt);
		
		DrawText(hdc, szHello, strlen(szHello), &rt, DT_CENTER);
		Marker(50, 50, Index, hWnd);
		EndPaint(hWnd, &ps);
		break;

	case WM_CLOSE:

		DestroyWindow(hWnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	
	case WM_CHAR:
		hdc = GetDC(hWnd);
		szchar[HelloIndex] = (TCHAR)wParam;;
		HelloIndex++;
		TextOut(hdc, 30, 100, szchar, 10);
		ReleaseDC(hWnd, hdc);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{

		case VK_LEFT:

			// Process the LEFT ARROW key. 

			if (Index<4)
			{
				Index++;
			}
			else
			{
				Index = 0;
			}
			InvalidateRect(hWnd, NULL, TRUE);
			break;

		default : 
			break;
		}
		break;
	}
	return 0;

}

void Marker(LONG x, LONG y, int Index, HWND hwnd)
{
	HDC hdc;

	hdc = GetDC(hwnd);
	hPen = CreatePen(PS_DOT, 5, Color[Index]);
	
	SelectObject(hdc, hPen);
	MoveToEx(hdc, (int)x - 10, (int)y, (LPPOINT)NULL);
	LineTo(hdc, (int)x + 10, (int)y);
	MoveToEx(hdc, (int)x, (int)y - 10, (LPPOINT)NULL);
	LineTo(hdc, (int)x, (int)y + 10);

	DeleteObject(hPen);
	ReleaseDC(hwnd, hdc);
}

