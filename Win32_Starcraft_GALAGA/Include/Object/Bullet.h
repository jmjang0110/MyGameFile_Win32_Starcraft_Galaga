#pragma once
#include "Object.h"
class CBullet : public CObject
{
public:
    CBullet();
    ~CBullet();

private:
	friend class CPlayer;
	

private:
	float m_fSpeed;	// �Ѿ� ���ǵ�
	float m_MaxRange;// �Ѿ� �����Ÿ� 

	float m_Range;	
	

private:
	bool m_bEnable; // true �� ��� �Ѿ��� ��ȿ�մϴ�... / false �� ��� ���� 

public:
	
	bool GetEnbale()
	{
		return m_bEnable;
	}
	void SetEnalbeFalse()
	{
		m_bEnable = false;

	}
public:
	// �⺻ ���� �Լ��� �Դϴ�...
	// CObject �� ����ϴ� ��� Ŭ������ �� �����Լ��� ���������� �����Լ�(virtual)�� �����Ѵ�.

	// init �ÿ� �÷��̾��� ��ġ�� ������ ������ �޽��ϴ�. ( �Ѿ� ���� ��ġ�� ���Դϴ�... )
	virtual  bool Init(POSITION PlayerLT, _SIZE PlayerSize, float Speed);
	virtual  bool Init(POSITION MonsterLT, _SIZE MonsterSize, POSITION BulletVector, float Speed);

	virtual	void Input(float fDeltaTime, class CScene* CurScene);
	virtual	void Update(float fDeltaTime);
	virtual	void LateUpdate(float fDeltaTime);
	virtual	bool Collision(float fDeltaTime, POSITION ObjectLT, POSITION ObjectSize);
	virtual	void Render(HDC mainhDC, HDC hdc, float fDeltaTime);

};

