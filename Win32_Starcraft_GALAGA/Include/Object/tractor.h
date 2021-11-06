#pragma once
#include "Monster.h"

class CTractor : public CMonster
{
	// CSceneManager ���� CPlayer�� private ���� ������ �⺻ �����ڿ� �����ϱ� ���ؼ� ���� �Ǿ����ϴ�...
	friend class CSceneManager;
public:

	CTractor();
	CTractor(const CTractor& player);
	virtual ~CTractor();

private:
	CBulletList* m_bulletList;
	float LastFireTime = NULL;
	float LastUpdateTime = NULL;
	_SIZE DetBulletSize = { 0.5f,0 };


public:
	class CBulletList* GetMyBulletList()
	{

		if (this == nullptr)
			int i = 0;

		if (m_bulletList)
			return m_bulletList;
		else
			return nullptr;
	}
	void RenderExplode(HDC mainhDC, HDC hdc, float fDeltaTime);
	void PlayExplodeSound();




public:
	// �⺻ ���� �Լ��� �Դϴ�...
	// CObject �� ����ϴ� ��� Ŭ������ �� �����Լ��� ���������� �����Լ�(virtual)�� �����Ѵ�.
	virtual  bool Init(POSITION LTpos, const Pattern& pattern, const Monster_type& type, POSITION Vector, int StageNum);

	virtual	void Input(float fDeltaTime);
	virtual	void Update(float fDeltaTime);
	virtual	void LateUpdate(float fDeltaTime);
	virtual	bool Collision(float fDeltaTime, CBulletList* player_BulletList);
	virtual	void Render(HDC mainhDC, HDC hdc, float fDeltaTime);

	void CreateBullet();

};