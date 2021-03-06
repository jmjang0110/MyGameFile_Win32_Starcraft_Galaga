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

// Game 구동 관련 함수들입니다. ***

void CCore::Logic()
{
	// 델타타임을 갱신한 후 얻습니다. 
	GET_SINGLE(CTimer)->Update();
	float fDeltaTime = GET_SINGLE(CTimer)->GetDeltaTime();
	// fDeltaTime_update = GET_SINGLE(CTimer)->GetTimer_Update();


	Input(fDeltaTime);			// * 입력
	Update(fDeltaTime);			// * 업데이트
	LateUpdate(fDeltaTime);		// * 업데이트 후처리 
	Collision(fDeltaTime);		// * 충돌 처리
	Render(fDeltaTime);			// * 출력


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






// Window 창 관련 함수들입니다. ***

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
	// 윈도우창 핸들
	m_hWnd = CreateWindowW(TEXT("GALAGA_STARCRAFT"), TEXT("GALAGA_STARCRAFT"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, m_hInst, nullptr);

	if (!m_hWnd)
	{
		// 윈도우 창 핸들 만들기를 실패하였습니다.
		return FALSE;
	}

	//       ** 클라이언트 영역의 크기를 맞춥니다.  **
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
		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...


		EndPaint(hWnd, &ps);
	}
	break;
	// 윈도우 종료시킬 때 들어오는 메시지
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

	// 해상도 설정
	m_tRS.iW = 600;
	m_tRS.iH = 750;

	Create();

	// 화면 DC 를 만들어준다.
	m_hDC = GetDC(m_hWnd);
	SetDoubleBufferDC();


	// 타이머를 초기화 합니다. 
	if (!CTimer::GetInst()->Init())
		return false;
	

	// 장면 관리자를 초기화 합니다. 
	if (!CSceneManager::GetInst()->Init())
		return false;

	if (!CSoundManager::GetInst()->Init())
		return false;

	return true;
}

int CCore::Run()
{
	MSG msg;

	// 기본 메시지 루프입니다
	while (m_bLoop)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

		}
		// 윈도우 데드타임일 경우
		else
		{
			// 게임구동 logic 이 구현됩니다.
			Logic();
		}
	}

	return (int)msg.wParam;
}