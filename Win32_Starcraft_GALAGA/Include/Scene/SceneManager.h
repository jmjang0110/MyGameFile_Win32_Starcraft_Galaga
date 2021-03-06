#pragma once
#include "../Game.h"

class CSceneManager
{
private:
	friend class CPlayer;


public:
	// 싱글톤으로 선언합니다.
	DECLARE_SINGLE(CSceneManager);

private:
	class CScene* m_Scene_Begin;		// 게임 시작
	class CScene* m_Scene_Stage1;		// STAGE 1
	class CScene* m_Scene_stage2;		// STAGE 2 
	class CScene* m_Scene_stage3;		// STAGE 3
	class CScene* m_Scene_End;			// 게임 끝 

	class CScene* m_Scene_StageClear;	// 게임 중간 전환 
	class CScene* m_Scene_End1;
	class CScene* m_Scene_End2;
	class CScene* m_Scene_End3;

	int m_StageClearCount = 0;
	int NextStageNum = 0;

	CImage images[31];
	WCHAR m_img_Text[20][50];

	
private:

	list<class CMonster*> m_MonsterList; // 출현할 몬스터 정보


private:
	class CPlayer* m_Player;

public:

	bool Init();


public:
	void Input(float fDeltaTime);
	int Update(float fDeltaTime);
	int LateUpdate(float fDeltaTime);
	void Collision(float fDeltaTime);
	void Render(HDC mainhDC, HDC hDC, float fDeltaTime);

	CPlayer* GetPlayer();

	list<CMonster*>* GetMonsterList() {
		return &m_MonsterList;
	}

	// 몬스터 정보 List 를 전부 삭제합니다. 
	void DeleteAllMonster()
	{
		m_MonsterList.clear();
	}

	void DeleteMonster(CMonster* it)
	{
		m_MonsterList.remove(it);
	}

	CImage* GetCimage(const WCHAR* imgText)
	{
		for (int i = 0; i < 19; i++)
		{
			if (wcscmp(imgText, m_img_Text[i]) == 0)
			{
				return &images[i];
				break;

			}
		}
		return nullptr;
 	}

};

