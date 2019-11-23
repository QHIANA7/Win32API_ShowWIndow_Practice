//#pragma comment (linker, "/subsystem:windows") //subsysem�� console�̳� windows�Ŀ� ���� �ܼ����α׷�/API ���α׷��� �¿�ȴ�.
#include <windows.h>
#include <tchar.h>
//

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd) // ù��° ���ڴ� �ν��Ͻ�, �ι�° ���ڴ� ���� ���α׷��� �ν��Ͻ�(�������Ⱦ���, ȣȯ���� ��������)
			//����	DBCS�� WinMain		UNICODE�� wWinMain	���� ���� ġȯ�ȴ�.
{
	//1�ܰ� : ������ Ŭ���� ����
	WNDCLASSEX wcex;	//�̰͵� ���� ����ü��.		DBCS�� WNDCLASSEXA		UNICODE�� WNDCLASSEXW	�� ���� ġȯ�ȴ�.

	wcex.cbSize = sizeof(WNDCLASSEX);	//����ü ũ�Ⱚ ���� Ŭ������ sizeof ���� ����� �����ϸ� �ȴ�.
	wcex.style = CS_HREDRAW | CS_VREDRAW;	//�������� ��Ÿ�� : ���⿡�� �ֿ��� CS_V/HREDRAW (ȭ�� ũ�� ����� ������ �ٽñ׸��� ���)�� ����
	wcex.lpfnWndProc = DefWindowProc; //<<================ //�����쿡 �ִ� �⺻ ���ν���, ��� �޽����� ����� ���۵ȴ�. â �̵�, �ּ�ȭ, ũ�������� ��ɵ��� ������
						//���밪�̴�. DBCS�� DefWindowProcA		UNICODE��	DefWindowProcW	�� ���� ġȯ�ȴ�.	DefWindowProc�� �⺻���� â�� ����� �����Ѵ�.
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInst;		//<<================	//���� WNDCLASSEX�� ���� �ν��Ͻ� �ڵ鰪 �����̴�. ��� WinMain�Ű������� ù���� �Ѱ��ش�.

	//�ý��ۿ� ��ϵ� �ڿ� ���
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);  //ù������ NULL�� �ý��ۿ� ��ϵȰ� ���ڴٴ°�. ���� �ڱⰡ ������� �ִٸ� WinMain�� Hinstance���ڸ� ����ϸ� �ȴ�. Cursor�� ����
	wcex.hCursor = LoadCursor(NULL, IDC_CROSS);
	wcex.hbrBackground = (HBRUSH)GetStockObject(HOLLOW_BRUSH);	//�̰͵� �̸� ���ǵ� ���� �ִ�. WHITE_BRUSH���� ������ ����
	//===========================================================

	wcex.lpszMenuName = 0;
	wcex.lpszClassName = TEXT("First");	//<<================	//�̸��� �����ؾ��Ѵ�. ��ҹ��� ���� ����	�ؽ�Ʈ�� �������� �Է��ؾ��Ѵ� : TEXT(���ڿ�) ���.
	wcex.hIconSm = 0;

	//<<=== ǥ�ð� �ǵ���� �� �κ� �������� �Ű澲�� �ʾƵ���


	//2�ܰ� : ������ Ŭ���� ���

	RegisterClassEx(&wcex);	//�굵 ���� �Լ���. DBCS�� RegisterClassEXA		UNICODE�� RegisterClassEXW	�� ���� ġȯ�ȴ�.	�����ϴ� ���� �����ߴ� ������ Ŭ������ �޴����� ��ϵȴ�.
	//��� �갡 ATOM���� ��ȯ�ϴµ� �̰ɷ� �����Ҷ� ���������� ��� lpszClassName�� �����.


	//3�ܰ� : ������ ����
	HWND hwnd = CreateWindow(TEXT("First"), TEXT("ù��° ����"), //�굵 ���� �Լ���. DBCS�� CreateClassEXA		UNICODE�� CreateClassEXW	�� ���� ġȯ�ȴ�.
		WS_OVERLAPPEDWINDOW &~ WS_CAPTION &~ WS_MAXIMIZEBOX, 
		0, 0, 400, 400, 
		NULL, NULL, hInst, NULL);	//�߰��� hInstance�� XP���ķ� ���õȴ�. ȣȯ���� ���� �ִ´�.

	//4�ܰ� : ���

	ShowWindow(hwnd, SW_SHOW);	//ù��° �Ű������� ����ϰ� ������ ������ �ڵ�, �ι�° �Ű������� ��� �������������� ���Ѵ�. ���������� ���ǵ�����
	MoveWindow(hwnd, 200, 200, 500, 500, false);
	
	MessageBox(0, TEXT("Hello,API"), TEXT("First"), MB_ABORTRETRYIGNORE);	//�굵 ���� �Լ���. DBCS�� MessageBoxA		UNICODE�� MessageBoxW	�� ���� ġȯ�ȴ�.
	return 0;
}