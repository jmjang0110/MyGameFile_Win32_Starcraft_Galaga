#include "Core.h"
#include "Core/Timer.h"
#include "Scene/SceneManager.h"
#include "Sound/SoundManager.h"

DEFINITION_SINGLE(CCore)
bool CCore::m_bLoop = true;

CCore::CCore()
{

}


CCore::~CCore()
{

	DESTROY_SINGLE(CSoundManager);
	DESTROY_SINGLE(CSceneManager);
	DESTROY_SINGLE(CTimer);

	ReleaseDC(m_hWnd, m_hDC);
}

// Game ���� ���� �Լ����Դϴ�. ***

void CCore::Logic()
{
	// ��ŸŸ���� ������ �� ����ϴ�. 
	GET_SINGLE(CTimer)->Update();
	float fDeltaTime = GET_SINGLE(CTimer)->GetDeltaTime();
	// fDeltaTime_update = GET_SINGLE(CTimer)->GetTimer_Update();


	Input(fDeltaTime);			// * �Է�
	Update(fDeltaTime);			// * ������Ʈ
	LateUpdate(fDeltaTime);		// * ������Ʈ ��ó�� 
	Collision(fDeltaTime);		// * �浹 ó��
	Render(fDeltaTime);			// * ���


}

void CCore::Input(float fDeltaTime)
{
	CSceneManager::GetInst()->Input(fDeltaTime);


}

int CCore::Update(float fDeltaTime)
{
	CSceneManager::GetInst()->Update(fDeltaTime);

	return 0;
}

int CCore::LateUpdate(float fDeltaTime)
{
	CSceneManager::GetInst()->LateUpdate(fDeltaTime);

	return 0;
}

void CCore::Collision(float fDeltaTime)
{
	CSceneManager::GetInst()->Collision(fDeltaTime);

}

void CCore::Render(float fDeltaTime)
{

	CSceneManager::GetInst()->Render(m_hDC,m_hMemDC,fDeltaTime);

}






// Window â ���� �Լ����Դϴ�. ***

ATOM CCore::MyRegisterClass()
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = CCore::WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = m_hInst;
	wcex.hIcon = LoadIcon(m_hInst, MAKEINTRESOURCE(NULL));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;//MAKEINTRESOURCEW(IDC_GAMEASSORTRAK04PEEKMESSAGEKEY);
	wcex.lpszClassName = TEXT("GALAGA_STARCRAFT");
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(NULL));

	return RegisterClassExW(&wcex);
}

BOOL CCore::Create()
{
	// ������â �ڵ�
	m_hWnd = CreateWindowW(TEXT("GALAGA_STARCRAFT"), TEXT("GALAGA_STARCRAFT"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, m_hInst, nullptr);

	if (!m_hWnd)
	{
		// ������ â �ڵ� ����⸦ �����Ͽ����ϴ�.
		return FALSE;
	}

	//       ** Ŭ���̾�Ʈ ������ ũ�⸦ ����ϴ�.  **
	RECT rc = { 0,0,m_tRS.iW,m_tRS.iH };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
	SetWindowPos(m_hWnd, HWND_TOPMOST, 0, 0, rc.right - rc.left,
		rc.bottom - rc.top, SWP_NOMOVE | SWP_NOZORDER);

	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);

	return TRUE;
}

LRESULT CCore::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...


		EndPaint(hWnd, &ps);
	}
	break;
	// ������ �����ų �� ������ �޽���
	case WM_DESTROY:
		m_bLoop = false;
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

bool CCore::Init(HINSTANCE hInst)
{
	this->m_hInst = hInst;
	MyRegisterClass();

	// �ػ� ����
	m_tRS.iW = 600;
	m_tRS.iH = 750;

	Create();

	// ȭ�� DC �� ������ش�.
	m_hDC = GetDC(m_hWnd);
	SetDoubleBufferDC();


	// Ÿ�̸Ӹ� �ʱ�ȭ �մϴ�. 
	if (!CTimer::GetInst()->Init())
		return false;
	

	// ��� �����ڸ� �ʱ�ȭ �մϴ�. 
	if (!CSceneManager::GetInst()->Init())
		return false;

	if (!CSoundManager::GetInst()->Init())
		return false;

	return true;
}

int CCore::Run()
{
	MSG msg;

	// �⺻ �޽��� �����Դϴ�
	while (m_bLoop)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

		}
		// ������ ����Ÿ���� ���
		else
		{
			// ���ӱ��� logic �� �����˴ϴ�.
			Logic();
		}
	}

	return (int)msg.wParam;
}