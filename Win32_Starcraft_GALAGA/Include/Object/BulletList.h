#pragma once
#include "../Game.h"

// 양방향 연결리스트로 관리합니다...
typedef struct _TagNode
{
	class CBullet* bullet = nullptr;
	_TagNode* pNext = nullptr;
	_TagNode* pPrev = nullptr;
}NODE, * PNODE;



class CBulletList
{
private:
	friend class CBullet;

public:
	CBulletList();
	~CBulletList();

private:
	PNODE m_pBegin;
	PNODE m_pEnd;
	int m_Count;


private:
	float m_fAttack	= 100; // 총알 공격력 


public:
	// 공격력을 반환합니다. 
	float GetAttack()
	{
		return m_fAttack;

	}
	// 공격력을 설정합니다...
	void SetAttack(float Attack)
	{
		m_fAttack = Attack;
	}
	void AddAttack()
	{
		m_fAttack += 50.0f;

	}
public:
	void Init();


public:
	// 충돌체크할 오브젝트의 위치와 사이즈를 받습니다.. 몇번 충돌 했는지를 반환합니다...
	int Collision(float fDeltatime, POSITION ObjectLT, POSITION ObjectSize);

public:
	void PushBack(POSITION playerLT, POSITION playerSize, float Speed);
	void PushBack(POSITION MonsterLT, _SIZE MonsterSize, POSITION BulletVector, float Speed);	// 리스트에 Bullet 을 추가합니다...
	void Erase(PNODE delNode = nullptr);														// 리스트내 해당 bullet 을 삭제합니다...

	void RenderAll(HDC mainhDC, HDC hdc, float fDeltaTime);										// 현재 총알 리스트를 전부 출력합니다..
	bool EraseAll();																			// 현재 총알 리스트를 전부 삭제합니다..

	void Update(float fDeltaTime);
	void Update(float fDeltaTime, _SIZE _size);

	bool Empty()
	{

		if (this == nullptr)
			return false;

		if (m_Count == 0)
			return true;
		else
			return false;

	}
	
};

