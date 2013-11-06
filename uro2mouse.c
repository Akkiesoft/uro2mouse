/* --------------------------------------------------
	 うろうろマウス Ver2.0
	 			(c) 2002-2004 あっきぃソフト
   -------------------------------------------------- */

#include <windows.h>
#include <stdlib.h>

#define ID_SOFTNAME "うろうろマウス Ver2.0"
#define ID_END 1000

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
char szClassNme[] = ID_SOFTNAME;
int cnt = 0, mode;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG msg;
	WNDCLASS myProg;

	if (!hPreInst) {
		myProg.style			=CS_HREDRAW | CS_VREDRAW;
		myProg.lpfnWndProc		=WndProc;
		myProg.cbClsExtra		=0;
		myProg.cbWndExtra		=0;
		myProg.hInstance		=hInstance;
		myProg.hIcon			=NULL;
		myProg.hCursor			=NULL;
		myProg.hbrBackground	=GetStockObject(0);
		myProg.lpszMenuName		=NULL;
		myProg.lpszClassName	=ID_SOFTNAME;
		if (!RegisterClass(&myProg))
			return FALSE;
	}
	hWnd = CreateWindow(szClassNme, ID_SOFTNAME,
		WS_POPUP, 20, 20, 100, 48, NULL, NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HINSTANCE hInst = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);

	switch (msg) {
		case WM_CREATE:
			HWND hButton1 = CreateWindow(
				"BUTTON", "おわり", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
				0, 0, 100, 48,
				hWnd, (HMENU)ID_END, hInst, NULL);
			srand((unsigned)GetTickCount());
			SetTimer(hWnd, 1, 100, NULL);
			break;

		case WM_COMMAND:
			if (LOWORD(wParam) == ID_END)
				PostQuitMessage(0);
			break;

		case WM_TIMER:
			if (cnt == 0)
				mode = rand() % 4;
			POINT pos;
			GetCursorPos(&pos);
			switch (mode) {
				case 0:
					pos.y += 5;
					break;
				case 1:
					pos.x += 5;
					break;
				case 2:
					pos.y -= 5;
					break;
				case 3:
					pos.x -= 5;
			}
			SetCursorPos(pos.x, pos.y);
			SetTimer(hWnd, 1, 100, NULL);
			cnt++;
			if (cnt > 1)
				cnt = 0;
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		default:
			return(DefWindowProc(hWnd, msg, wParam, lParam));
	}

	return (0L);
}
