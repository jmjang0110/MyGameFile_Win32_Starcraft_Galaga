#pragma once
#include "../Game.h"
#include "Object.h"


enum class Monster_type : int // ���͵��� Ÿ��
{
	Wraith = 10001,
	Valkyrie = 10002,
	Battlecruiser = 10003,
	Dropship = 10004,
	Vessel = 10005,

	Mutalisk = 20001,
	Devourer = 20002,
	Queen = 20003,
	Scourge = 20004,

	Scout = 30001,
	Corsair = 30002,
	Carrier = 30003,
	Arbiter = 30004,

	BOSS_ONE = 40001,
	BOSS_TWO = 40002,
	BOSS_THREE = 40003
};

enum class Pattern {  // ���� �з��� �ڷ���, �̸��� ���ٸ� �ǹ̰� ���� ���°� ���� ��ü ����
	SIN,
	SIN2,
	SIN3,
	SIN4,
	SIN5,
	SIN6,
	NONE,
	SIN7
	
};

enum class MONSTER_STATE {
	DONDESTORY,
	NOMAL,
	WAIT,
	DESTORY
};

class CMonster : public  CObject
{
	// CSceneManager ���� CPlayer�� private ���� ������ �⺻ �����ڿ� �����ϱ� ���ؼ� ���� �Ǿ����ϴ�...
	friend class CSceneManager;
public:

	CMonster();
	CMonster(const CMonster& player);
	virtual ~CMonster();

protected:
	Pattern		mPattern; // ���� �з��� ���� ����
	int			bias = 1;
	float		t_speed = 0.1; // �ӵ�
	bool		d_triger = true; // ����� ���Ͽ��� ����ϴ� ������ȯ Ʈ����
	int			count; // ���� ������ ������Ʈ�� ���� ī��Ʈ
	int			t_count;
	int			d_count;
	float		ceta; // 1���� ���� ��ȯ�ÿ� ������ �����ϱ� ���� ����
	float		c_det;
	int			fire_delay;
	int			fire_rate;
	float		B_speed = 300.0f;
	MONSTER_STATE m_state = MONSTER_STATE::DONDESTORY;
	float		LastFireTime = NULL;
	float		TracterBimSize = 0;


protected:
	bool		m_bDie = false;
	bool		m_PlayExplodeSound =false;
	CImage		m_Explode_img;

	POINT		m_Explode_img_LT;
	POINT		m_Explode_img_Size;
	int			m_Explode_img_Count = 0;
	bool		m_Explode_img_RenderEnd = false;


public:
	bool GetIsDie()
	{
		return m_bDie;
	}
	POSITION GetMonsterLT()
	{
		return CObject::m_tLTPos;
	}
	POSITION GetMonsterSize()
	{
		return CObject::m_tSize;

	}
	void RenderExplode(HDC mainhDC, HDC hdc, float fDeltaTime);
	void PlayExplodeSound();


public:
	void Run(HDC mainhDC, HDC hdc, float fDeltaTime);


public:
	// �⺻ ���� �Լ��� �Դϴ�...
	// CObject �� ����ϴ� ��� Ŭ������ �� �����Լ��� ���������� �����Լ�(virtual)�� �����Ѵ�.
	virtual  bool Init(POSITION LTpos, const Pattern& pattern, const Monster_type& type, POSITION Vector, int StageNum);

	virtual	void Input(float fDeltaTime);
	virtual	void Update(float fDeltaTime);
	virtual	void LateUpdate(float fDeltaTime);
	virtual	bool Collision(float fDeltaTime, POSITION ObjectLT, POSITION ObjectSize);
	virtual	void Render(HDC mainhDC, HDC hdc, float fDeltaTime);

	bool Collision(float fDeltaTime, class CBulletList* player_BulletList);


	MONSTER_STATE GetState() {
		return m_state;
	}

	int GetFireDelay() {
		return fire_delay;
	}

	void CreateBullet(class CBulletList** _bulletList);

};

