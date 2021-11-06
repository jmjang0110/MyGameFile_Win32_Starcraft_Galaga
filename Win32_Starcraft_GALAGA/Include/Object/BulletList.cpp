#include "BulletList.h"
#include "Bullet.h"


CBulletList::CBulletList()
{

}

CBulletList::~CBulletList()
{
	EraseAll();
	delete m_pBegin;
	delete m_pEnd;

}


void CBulletList::Init()
{

	m_pBegin = new NODE;
	m_pEnd = new NODE;

	m_pBegin->pNext = m_pEnd;
	m_pEnd->pNext = NULL;

	m_pBegin->pPrev = NULL;
	m_pEnd->pPrev = m_pBegin;


	m_Count = 0;
}

int CBulletList::Collision(float fDeltatime, POSITION ObjectLT, POSITION ObjectSize)
{


	// �浹Ƚ��
	int CollisionCheckNum = 0;
	for (PNODE pNode = m_pBegin->pNext; pNode != m_pEnd; pNode = pNode->pNext)
	{
		if (pNode)
		{
			// �Ѿ˰� �ش� ��ü�� �浹�ߴٸ� �浹 ������ �÷��ش�...
			if (pNode->bullet->Collision(fDeltatime, ObjectLT, ObjectSize))
			{
				CollisionCheckNum += 1;
				
				PNODE delNode = pNode;
				pNode = pNode->pPrev;
				Erase(delNode);

			}
		}
	}


	return CollisionCheckNum;

}


void CBulletList::PushBack(POSITION playerLT, POSITION playerSize, float Speed)
{
	if (this == nullptr)
		int i = 0;


	PNODE NewNode = new NODE;
	POSITION BulletSize = { 18,30 };
	POSITION BulletLTPos = { playerLT.x + playerSize.x / 2 - BulletSize.x / 2, playerLT.y - BulletSize.y };

	NewNode->bullet = new CBullet;
	NewNode->bullet->Init(BulletLTPos, BulletSize, 800.0f);

	NewNode->pNext = m_pEnd;
	m_pEnd->pPrev->pNext = NewNode;

	NewNode->pPrev = m_pEnd->pPrev;
	m_pEnd->pPrev = NewNode;

	m_Count += 1;

}

void CBulletList::PushBack(POSITION MonsterLT, _SIZE MonsterSize, POSITION BulletVector, float Speed)
{
	if (this == nullptr)
		int i = 0;


	PNODE NewNode = new NODE;
	POSITION BulletSize = { MonsterSize.x,MonsterSize.y };
	POSITION BulletLTPos = { MonsterLT.x + MonsterSize.x / 2 - BulletSize.x / 2, MonsterLT.y - BulletSize.y };

	NewNode->bullet = new CBullet;
	NewNode->bullet->Init(BulletLTPos, BulletSize, BulletVector, Speed);

	NewNode->pNext = m_pEnd;
	m_pEnd->pPrev->pNext = NewNode;

	NewNode->pPrev = m_pEnd->pPrev;
	m_pEnd->pPrev = NewNode;

	m_Count += 1;
}

void CBulletList::Erase(PNODE delNode)
{
	if (delNode == nullptr || delNode == m_pEnd || delNode == m_pBegin)
		return;
	PNODE DeleteNode = delNode;

	delNode->pPrev->pNext = delNode->pNext;
	delNode->pNext->pPrev = delNode->pPrev;

	DeleteNode->bullet->~CBullet();
	delete DeleteNode;


	m_Count -= 1;

}

void CBulletList::RenderAll(HDC mainhDC, HDC hdc, float fDeltaTime)
{
	m_pBegin;
	m_pEnd;
	int i = 0;


	for (PNODE pNode = m_pBegin->pNext; pNode != m_pEnd; pNode = pNode->pNext)
	{
		if (pNode)
			pNode->bullet->Render(mainhDC, hdc, fDeltaTime);
	}

}

bool CBulletList::EraseAll()
{
	if (Empty())
		return true;

	for (PNODE pNode = m_pBegin->pNext; pNode != m_pEnd; pNode = m_pBegin->pNext)
	{
		PNODE DelNode = pNode;
		m_pBegin->pNext = DelNode->pNext;

		if (DelNode)
		{
			delete DelNode;
			m_Count -= 1;
		}

	}

	if (Empty())
		return true;
	else
		return false;


}

void CBulletList::Update(float fDeltaTime)
{
	// BulletList ������ ��� Bullet �� �Ÿ��� �̵���Ų��...
	for (PNODE pNode = m_pBegin->pNext; pNode != m_pEnd; pNode = pNode->pNext)
	{
		if(pNode->bullet)
		pNode->bullet->Update(fDeltaTime);

		if (pNode->bullet->GetEnbale() == false)
		{
			PNODE delNode = pNode;
			pNode = pNode->pPrev;
			Erase(delNode);

		}
	}

}


void CBulletList::Update(float fDeltaTime, _SIZE _size)
{
	for (PNODE pNode = m_pBegin->pNext; pNode != m_pEnd; pNode = pNode->pNext)
	{
		if (pNode->bullet) {
			pNode->bullet->SetSize(pNode->bullet->GetSize() + _size);
			pNode->bullet->SetPos(pNode->bullet->GetPos() - (_size / 2));
			pNode->bullet->Update(fDeltaTime);
		}

		if (pNode->bullet->GetEnbale() == false)
		{
			PNODE delNode = pNode;
			pNode = pNode->pPrev;
			Erase(delNode);

		}
	}
}