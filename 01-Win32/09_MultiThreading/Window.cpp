#include<windows.h>
#include<tchar.h>

//Global funtion declerations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); 
DWORD WINAPI ThreadProcOne(LPVOID);
DWORD WINAPI ThreadProcTwo(LPVOID); 

//Global Variable declarations

//Entry point function

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//local variable declarations
	WNDCLASSEX wndclass; //initialize windowclass
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyWindow");

	//code
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName; 
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);

	//create Window in memory
	hwnd = CreateWindow(szAppName,
		TEXT("PRATHAMESH : MyFirstWindow"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);
	ShowWindow(hwnd, iCmdShow);  
	UpdateWindow(hwnd);

	//message loop

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}

	return((int)msg.wParam);}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static HANDLE hThread1 = NULL;
	static HANDLE hThread2 = NULL; 
	//code
	switch (iMsg)
	{
	case WM_CREATE:

		hThread1 = CreateThread(NULL, 0 , (LPTHREAD_START_ROUTINE)ThreadProcOne, (LPVOID)hwnd , 0 , NULL);

		//here there should be error checking for Hthread1. 

		hThread2= CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProcTwo, (LPVOID)hwnd, 0 , NULL);

		//here there should be error checking for Hthread2.
		break;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd, TEXT("I AM THREAD NUMBER 4"), TEXT("Message"), MB_OKCANCEL);
		break;
	case WM_DESTROY:
		CloseHandle(hThread1);
		CloseHandle(hThread2);

		PostQuitMessage(0);
		break;
	default:
		break;
	
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

DWORD WINAPI ThreadProcOne(LPVOID param)
{
	//function defination started;
	//Variable Declarations

	HDC hdc = NULL;
	TCHAR str[255];
	long i ;

	// code (important logic) 

	hdc = GetDC((HWND)param);
	SetBkColor(hdc, RGB(0, 0, 0));
	SetTextColor(hdc, RGB(0, 255, 0));

	for (i = 0; i < 2147483648; i++)
	{
		wsprintf(str, TEXT("Incrementing order: = %ld"), i);
		TextOut(hdc, 5, 5, str, (int)_tcslen(str));
	}

	ReleaseDC((HWND)param, hdc);

	return 0;



	
}

DWORD WINAPI ThreadProcTwo(LPVOID param)
{
	//function defination started;
	//Variable Declarations

	HDC hdc = NULL;
	TCHAR str[255];
	long i;

	// code (important logic) 

	hdc = GetDC((HWND)param);
	SetBkColor(hdc, RGB(0, 0, 0));
	SetTextColor(hdc, RGB(255, 0, 0));

	for (i =2147483647; i>=0 ; i--)
	{
		wsprintf(str, TEXT("decrementing ordeer : = %ld"), i);
		TextOut(hdc, 5, 25 , str, (int)_tcslen(str));
	}

	ReleaseDC((HWND)param, hdc);

	return 0;




}














		
		
	






	

