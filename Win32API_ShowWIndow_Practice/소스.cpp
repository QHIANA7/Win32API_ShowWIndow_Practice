//#pragma comment (linker, "/subsystem:windows") //subsysem이 console이냐 windows냐에 따라서 콘솔프로그램/API 프로그램이 좌우된다.
#include <windows.h>
#include <tchar.h>
//

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd) // 첫번째 인자는 인스턴스, 두번째 인자는 이전 프로그램의 인스턴스(지금은안쓴다, 호환성을 위한인자)
			//범용	DBCS는 WinMain		UNICODE는 wWinMain	으로 각각 치환된다.
{
	//1단계 : 윈도우 클래스 생성
	WNDCLASSEX wcex;	//이것도 범용 구조체다.		DBCS는 WNDCLASSEXA		UNICODE는 WNDCLASSEXW	로 각각 치환된다.

	wcex.cbSize = sizeof(WNDCLASSEX);	//구조체 크기값 현재 클래스의 sizeof 연산 결과를 대입하면 된다.
	wcex.style = CS_HREDRAW | CS_VREDRAW;	//윈도우의 스타일 : 여기에선 주요한 CS_V/HREDRAW (화면 크기 변경시 윈도우 다시그리는 기능)를 삽입
	wcex.lpfnWndProc = DefWindowProc; //<<================ //윈도우에 있는 기본 프로시저, 모든 메시지는 여기로 전송된다. 창 이동, 최소화, 크기조절의 기능등을 담은것
						//범용값이다. DBCS는 DefWindowProcA		UNICODE는	DefWindowProcW	로 각각 치환된다.	DefWindowProc은 기본적인 창의 기능을 수행한다.
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInst;		//<<================	//현재 WNDCLASSEX를 담을 인스턴스 핸들값 설정이다. 대게 WinMain매개변수의 첫값을 넘겨준다.

	//시스템에 등록된 자원 사용
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);  //첫인자의 NULL은 시스템에 등록된걸 쓰겠다는것. 만약 자기가 만든것이 있다면 WinMain의 Hinstance인자를 사용하면 된다. Cursor도 동일
	wcex.hCursor = LoadCursor(NULL, IDC_CROSS);
	wcex.hbrBackground = (HBRUSH)GetStockObject(HOLLOW_BRUSH);	//이것도 미리 정의된 것이 있다. WHITE_BRUSH말고도 여러개 존재
	//===========================================================

	wcex.lpszMenuName = 0;
	wcex.lpszClassName = TEXT("First");	//<<================	//이름은 고유해야한다. 대소문자 구분 안함	텍스트는 범용으로 입력해야한다 : TEXT(문자열) 사용.
	wcex.hIconSm = 0;

	//<<=== 표시가 건드려야 할 부분 나머지는 신경쓰지 않아도됨


	//2단계 : 윈도우 클래스 등록

	RegisterClassEx(&wcex);	//얘도 범용 함수다. DBCS는 RegisterClassEXA		UNICODE는 RegisterClassEXW	로 각각 치환된다.	실행하는 순간 생성했던 윈도우 클래스가 메뉴같이 등록된다.
	//사실 얘가 ATOM값을 반환하는데 이걸로 생성할때 쓸수있지만 대게 lpszClassName을 사용함.


	//3단계 : 윈도우 생성
	HWND hwnd = CreateWindow(TEXT("First"), TEXT("첫번째 예제"), //얘도 범용 함수다. DBCS는 CreateClassEXA		UNICODE는 CreateClassEXW	로 각각 치환된다.
		WS_OVERLAPPEDWINDOW &~ WS_CAPTION &~ WS_MAXIMIZEBOX, 
		0, 0, 400, 400, 
		NULL, NULL, hInst, NULL);	//중간의 hInstance는 XP이후로 무시된다. 호환성을 위해 넣는다.

	//4단계 : 출력

	ShowWindow(hwnd, SW_SHOW);	//첫번째 매개변수는 등록하고 생성한 윈도우 핸들, 두번째 매개변수는 어떻게 보여질것인지를 정한다. 여러가지가 정의되있음
	MoveWindow(hwnd, 200, 200, 500, 500, false);
	
	MessageBox(0, TEXT("Hello,API"), TEXT("First"), MB_ABORTRETRYIGNORE);	//얘도 범용 함수다. DBCS는 MessageBoxA		UNICODE는 MessageBoxW	로 각각 치환된다.
	return 0;
}