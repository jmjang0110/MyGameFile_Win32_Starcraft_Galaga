#pragma once
#include "../Game.h"

class CScene
{
private:
	CScene();
	~CScene();
private:
	friend class CSceneManager;

private:
	class CItemList* m_ItemList;


private:
	list<class CMonster*>* m_MonsterList; // ������ ���� ����
	class CBulletList* Monster_BulletList;

	class CTractor* m_Tractor = nullptr;
	class Boss* m_boss = nullptr;
	class CPlayer* m_Player;		 // �÷��̾� ���� 

private:
	CImage				  m_BackImage;	 // ��� �̹���
	bool				  m_bEnable;	 // ȭ�� Ȱ��ȭ üũ ���� 

	double				  m_MaxDistance; // ���������� ���� ����Ÿ� ���� 
	double				  m_Distance;	 // ���� �÷��̾ ������ �Ÿ�

private:

	POSITION			  m_imgLT;		 // �̹��� ���� �������� ����� �̹����� ������
	POSITION			  m_imgSize;
	POSITION			  m_imgRenderLT;
	POSITION			  m_imgRenderSize;


	// Screen Slide 
	POSITION			  m_imgLT2;		 // ������ 2 ( ������ ���� ������ �� )
	POSITION			  m_imgSize2;
	POSITION			  m_imgRenderLT2;
	POSITION			 m_imgRenderSize2;

	bool				  m_bSlide;		//  ȭ�鿡�� ������ 2�� �̿��� ���� �����̵� �ؾ��� �� ���� üũ
	bool				  m_bEndScene;	 // �ش� ���� ������� �˸��� ����

	int I_MspawnDelay = 2000;			// ���� ���� ���� ���� �����󵵰� �������ϴ�..
	int I_MspawnCount = 0;

	int m_StageNum = 0;
	int TractorCount_Render = 0;

public:

	void imgLT_Move(float fDeltaTime); //����� ���� �̹����� �������� �̵���ŵ�ϴ�. ( �÷��̾ ����Ű�� ������ �� )
	void imgLT_Move_Auto(float fDeltaTime); // ���� �̹����� �������� �̵���ŵ�ϴ�. ( ȭ���� �ڵ����� �����Դϴ�. )


public:
	// ��� �̹��� ,�÷��̾� , ���� ���� 
	bool Init(const WCHAR* imgBackText, class CPlayer* player, long long  MaxDistance, bool enable, int stageNum);

public:
	// list�� �� ���͸� �߰��մϴ�. 
	void AddObject(class CMonster* pMonster);


public:
	void	Input(float fDeltaTime, class CScene* NextScene);
	int		Update(float fDeltaTime);
	int		LateUpdate(float fDeltaTime);
	void	Collision(float fDeltaTime);
	void	Render(HDC mainhDC, HDC hDC, float fDeltaTime);




public:
	// Cscene ȭ���� Ȱ��ȭ ���θ� ��ȯ�մϴ�.  
	bool GetEnable()
	{
		return m_bEnable;
	}

	void SetEnable(bool enable)
	{
		m_bEnable = enable;

	}


	int GetCurSceneMaxDistance()
	{
		return m_MaxDistance;

	}
	void UpdateMaxDistance(double distance, CScene* NextScene);



};

