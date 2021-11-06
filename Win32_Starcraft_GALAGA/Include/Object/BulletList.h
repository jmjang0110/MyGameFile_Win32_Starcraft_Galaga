#pragma once
#include "../Game.h"

// ����� ���Ḯ��Ʈ�� �����մϴ�...
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
	float m_fAttack	= 100; // �Ѿ� ���ݷ� 


public:
	// ���ݷ��� ��ȯ�մϴ�. 
	float GetAttack()
	{
		return m_fAttack;

	}
	// ���ݷ��� �����մϴ�...
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
	// �浹üũ�� ������Ʈ�� ��ġ�� ����� �޽��ϴ�.. ��� �浹 �ߴ����� ��ȯ�մϴ�...
	int Collision(float fDeltatime, POSITION ObjectLT, POSITION ObjectSize);

public:
	void PushBack(POSITION playerLT, POSITION playerSize, float Speed);
	void PushBack(POSITION MonsterLT, _SIZE MonsterSize, POSITION BulletVector, float Speed);	// ����Ʈ�� Bullet �� �߰��մϴ�...
	void Erase(PNODE delNode = nullptr);														// ����Ʈ�� �ش� bullet �� �����մϴ�...

	void RenderAll(HDC mainhDC, HDC hdc, float fDeltaTime);										// ���� �Ѿ� ����Ʈ�� ���� ����մϴ�..
	bool EraseAll();																			// ���� �Ѿ� ����Ʈ�� ���� �����մϴ�..

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

