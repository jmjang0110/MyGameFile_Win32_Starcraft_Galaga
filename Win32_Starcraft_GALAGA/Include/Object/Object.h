#pragma once
#include	"../Game.h"
//**    ���ǻ���   ** 
/*
	->		CObject�� ����ϴ� class �� �Ҹ��ڴ� virtual �� �����ؾ� �մϴ�..,

	->		Input / Update / LateUpdate / Collision / Render / Init �� 
			obj Ŭ������ ����ϴ� ��� Ŭ������ �������� �־�� �� �Լ��� �Դϴ�.
			�� �Լ��鵵 virtual �� �����ϱ�� ����մϴ�...

*/
class CObject
{
private:
	friend class CPlayer;


protected:
	CObject();
	CObject(const CObject& obj); 
	virtual ~CObject();					//  �Ҹ��ڸ� �����Լ��� �����մϴ�..

private:
	CImage*		m_img_Back;				//  �̹���
	POSITION	m_img_Size;				//  �̹��� ( png )���� ����� ������ 
	POSITION	m_img_LT;				//  �̹��� ( png )���� ����� ��ġ 


protected:
	POSITION	m_tLTPos;				//  ȭ�鿡 ��ġ�� Left top ���� ��ġ
	POSITION	m_tVector;				//  Object �� ������ ����
	_SIZE		m_tSize;				//  obj �� ũ�� 

	bool		m_bLife;				//  obj �� ���翩��
	float		m_fHP;					//  Object �� HP 

private:
	WCHAR*		m_imgText;


private:
	OBJECT_TYPE m_MyType;			// ���������� ���ؼ� ������ enum class �� ����մϴ�...




public:
	// �⺻ ���� �Լ��� �Դϴ�...
	// CObject �� ����ϴ� ��� Ŭ������ �� �����Լ��� ���������� �����Լ�(virtual)�� �����Ѵ�.

	// init ( �̹��� ���� ��� , ȭ�鿡 ����� ������Ʈ ��ġ , ������Ʈ ���� , ������Ʈ ������ , ������Ʈ HP , png ���Ͽ����� ������ , png ���Ͽ����� ��ġ ) 
	virtual  bool Init(const WCHAR* imgText, POSITION LTpos, POSITION Vector, _SIZE Size, float HP, POSITION imgSize, POSITION imgLT, PLAYER_TYPE obType);

	virtual	void Input(float fDeltaTime);
	virtual	void Update(float fDeltaTime);
	virtual	void LateUpdate(float fDeltaTime);
	virtual	bool Collision(float fDeltaTime, POSITION ObjectLT, POSITION ObjectSize);
	virtual	void Render(HDC mainhDC, HDC hdc, float fDeltaTime);

public:

	void Changeimg(const WCHAR* imgText,POSITION imgSize , POSITION imgLT);


	// �ܺο��� ������Ʈ ���¸� Ȯ���� �� ����ϴ� �Լ��� �Դϴ�...
	POSITION GetPos() const;
	POSITION GetVector() const;
	_SIZE	 GetSize() const;

	bool	 GetLife() const;
	float	 GetHP() const;

public:
	// �ܺο��� ������Ʈ ���¸� ������ �� ����ϴ� �Լ��� �Դϴ�...
	void SetPos(const POSITION& tPos);
	void SetVector(const POSITION& tVector);
	void SetSize(const _SIZE tSize);

	void SetLife(const bool bLife);
	void SetHP(const float fHP);


};

