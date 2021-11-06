#pragma once
#include "../Game.h"

// ����� ���Ḯ��Ʈ�� �����մϴ�...
typedef struct _TagNodeItem
{
	class CItem* item = nullptr;
	_TagNodeItem* pNext = nullptr;
	_TagNodeItem* pPrev = nullptr;
}INODE, * PINODE;



class CItemList
{
private:
	friend class CItem;

public:
	CItemList();
	~CItemList();

private:
	PINODE m_pBegin;
	PINODE m_pEnd;
	int m_Count;


private:
	float m_fAttack = 100; // �Ѿ� ���ݷ� 


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
	bool Collision(float fDeltatime, POSITION ObjectLT, POSITION ObjectSize, class CPlayer* Player);

public:
	void PushBack(ITEM_TYPE itemType);

	void PushBack(ITEM_TYPE itemType,POSITION playerLT, POSITION playerSize, float Speed);
	void PushBack(ITEM_TYPE itemType, POSITION MonsterLT, _SIZE MonsterSize, POSITION BulletVector, float Speed);	// ����Ʈ�� Bullet �� �߰��մϴ�...
	void Erase(PINODE delNode = nullptr);														// ����Ʈ�� �ش� bullet �� �����մϴ�...

	void RenderAll(HDC mainhDC, HDC hdc, float fDeltaTime);										// ���� �Ѿ� ����Ʈ�� ���� ����մϴ�..
	bool EraseAll();																			// ���� �Ѿ� ����Ʈ�� ���� �����մϴ�..

	void Update(float fDeltaTime);
	bool Empty()
	{
		if (m_Count == 0)
			return true;
		else
			return false;

	}

};

