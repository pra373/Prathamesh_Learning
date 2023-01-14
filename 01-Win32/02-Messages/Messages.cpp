#include<windows.h>

//Global funtion declerations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);  

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
	wndclass.hIconSm = LoadIcon(NULL,IDI_APPLICATION);


	RegisterClassEx(&wndclass);

	//create Window in memory
	hwnd = CreateWindow(szAppName,
		TEXT("PRATHAMESH : MyFirstWindow"),
		WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);
	ShowWindow(hwnd,SW_NORMAL);  
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
	//code
	switch (iMsg)
	{
	case WM_CREATE:
		SetScrollRange(hwnd, SB_VERT | SB_HORZ, 0, 10, TRUE);
		
		MessageBox(hwnd,TEXT("WM_CREATE message is arived"),TEXT("Message"), MB_OKCANCEL);
		break;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd,TEXT("LEFT mouse BUTTON is pressed"),TEXT("Message"), MB_OKCANCEL);
		break;
	case WM_RBUTTONDOWN:
		MessageBox(hwnd, TEXT("RIGHT mouse BUTTON is pressed"), TEXT("Message"), MB_OKCANCEL);
		break;

	case WM_KEYDOWN:
		MessageBox(hwnd,TEXT("A KEY IS PRESSED"),TEXT("Message"),MB_OK);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));

}







		
		
	






	

