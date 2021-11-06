#pragma once
#include "../Game.h"


class CSoundManager
{

public:
// �̱������� �����մϴ�...
	DECLARE_SINGLE(CSoundManager);

private:
	FMOD_SYSTEM			* soundSystem;

	FMOD_SOUND			* bgmSound_stage1;
	FMOD_SOUND			* bgmSound_stage2;
	FMOD_SOUND			* bgmSound_stage3;

	FMOD_SOUND			* bgmSound_StageClear;
	FMOD_SOUND			* bgmSound_MainMenu;
	FMOD_SOUND			* bgmSound_End;

	FMOD_SOUND			* bgmSound_Boss1;
	FMOD_SOUND			* bgmSound_Boss2;
	FMOD_SOUND			* bgmSound_Boss3;


	FMOD_CHANNEL		* bgmChannel;
	
private:

	FMOD_CHANNEL		* effectChannel;
	FMOD_SOUND			* effectSound_WraithGood;
	FMOD_SOUND			* effectSound_Explode1;
private:

	FMOD_CHANNEL		* m_Explode_Sound_Channel[10];







public:
	bool Init();

	// ������ �ش罺�������� ���ڷ� �ް� �ش��ϴ� ����  ���
	bool playSound(OBJECT_TYPE obType, int stageNum);		// �ش� ������ ��������� �����մϴ�...
	bool stopSound();										// ��������� ������ŵ�ϴ�..
	bool PlaySound_Bossbgm(int stage);


public:
	bool playSound_Effect();
	bool playSound_Effect_Explode();




};

