#include "Bullet.h"

CBullet::CBullet()
{
}

CBullet::~CBullet()
{
	CObject::~CObject();
}

bool CBullet::Init(POSITION PlayerLT, _SIZE PlayerSize, float Speed)
{
	// �÷��̾� ��ġ �������� �Ѿ��� ��ġ�� �ʱ�ȭ �մϴ�... 
	POSITION PlayerVector = { 0 ,  -1 };

	// ȭ���� �ƴ϶� �̹��� (png ���Ͽ����� �̹��� �Դϴ�... ���� �� )
	POSITION BulletimgSize = { 8,15 };
	POSITION BulletimgLT = { 84,42 }; //  �̹��� ���Ͽ����� x y  ��ǥ�Դϴ�...

	m_fSpeed = Speed;
	m_bEnable = true;
	m_MaxRange = 700.0f;
	m_Range = 0.0f;



	CObject::Init(L"../Bin/Terran_img/Wraith.png", PlayerLT, PlayerVector,
		PlayerSize, 1000.0f, BulletimgSize, BulletimgLT, PLAYER_TYPE::PT_MONSTER);

	return true;
}

bool CBullet::Init(POSITION MonsterLT, _SIZE MonsterSize, POSITION BulletVector, float Speed)
{
	POSITION BulletimgSize = { 16,16 };
	POSITION BulletimgLT = { 167,297 }; //  �̹��� ���Ͽ����� x y  ��ǥ�Դϴ�...

	m_fSpeed = Speed;
	m_bEnable = true;
	m_MaxRange = 1000.0f;
	m_Range = 0.0f;



	CObject::Init(L"../Bin/Item_img/Bullets.png", MonsterLT, BulletVector,
		MonsterSize, 1000.0f, BulletimgSize, BulletimgLT, PLAYER_TYPE::PT_MONSTER);

	return false;
}

void CBullet::Input(float fDeltaTime, CScene* CurScene)
{
}

void CBullet::Update(float fDeltaTime)
{

	CObject::SetPos(CObject::GetPos() + ((CObject::GetVector() * fDeltaTime) * m_fSpeed));

	m_Range += fDeltaTime * m_fSpeed;

	if (m_Range >= m_MaxRange)
		SetEnalbeFalse();

}

void CBullet::LateUpdate(float fDeltaTime)
{
}


bool CBullet::Collision(float fDeltaTime, POSITION ObjectLT, POSITION ObjectSize)
{
	return CObject::Collision(fDeltaTime, ObjectLT, ObjectSize);

}

void CBullet::Render(HDC mainhDC, HDC hdc, float fDeltaTime)
{
	CObject::Render(mainhDC, hdc, fDeltaTime);

}


