#pragma once
#include "Monster.h"

class Boss : public CMonster
{
	// CSceneManager ���� CPlayer�� private ���� ������ �⺻ �����ڿ� �����ϱ� ���ؼ� ���� �Ǿ����ϴ�...
	friend class CSceneManager;


public:

	Boss();
	Boss(const Boss& player);
	virtual ~Boss();

private:
	class CBulletList* m_bulletList;
	int pattern_count;
	Pattern b_pattern = Pattern::NONE;
	POSITION b_vector = { 0,1 };
	float accum_ceta = 0;
	bool is_reverseCeta = false;



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
	virtual  bool Init(POSITION LTpos, const Monster_type& type, POSITION Vector, int stageNum);

	virtual	void Input(float fDeltaTime);
	virtual	void Update(float fDeltaTime);
	virtual	void LateUpdate(float fDeltaTime);
	virtual	bool Collision(float fDeltaTime,class CBulletList* player_BulletList);
	virtual	void Render(HDC mainhDC, HDC hdc, float fDeltaTime);

	virtual void CreateBullet(Pattern _pattern);

};
