#include "Core.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	srand((unsigned int)time(NULL));

	// ������ �ʱ�ȭ �մϴ�. 
	if (!CCore::GetInst()->Init(hInstance))
	{
		CCore::DestroyInst();
		return 0;
	}

	// ���� ������ �����մϴ�. 
	int iRev = CCore::GetInst()->Run();
	CCore::DestroyInst();

	return iRev;

}

