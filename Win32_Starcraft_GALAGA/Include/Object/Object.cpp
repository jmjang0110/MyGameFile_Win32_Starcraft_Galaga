#include "Object.h"
#include "../Object/Player.h"
#include "../Scene/SceneManager.h"
#include "../Scene/Scene.h"



CObject::CObject()
{
}

CObject::CObject(const CObject& obj)
{
	*this = obj;

}

CObject::~CObject()
{ 

	//m_img_Back.Destroy();

	if (m_imgText != nullptr) {
		delete[] m_imgText;
		m_imgText = nullptr;
	}

}

void CObject::Changeimg(const WCHAR* imgText, POSITION imgSize, POSITION imgLT)
{
	/*if (m_img_Back)
		m_img_Back.Destroy();

	
	m_img_Back.Load(imgText);*/

	m_img_Back = CSceneManager::GetInst()->GetCimage(imgText);
	m_img_Back->SetTransparentColor(RGB(255, 255, 255));


	if (m_imgText)
		delete[]m_imgText;

	m_imgText = new WCHAR[lstrlen(imgText)];
	StringCchCopyW(m_imgText, lstrlen(imgText), imgText);

	m_img_Size = imgSize;
	m_img_LT = imgLT;


}

POSITION CObject::GetPos() const
{

	return m_tLTPos;
}

POSITION CObject::GetVector() const
{
	return m_tVector;
}

_SIZE CObject::GetSize() const
{
	return m_tSize;
}

bool CObject::GetLife() const
{
	return m_bLife;
}

float CObject::GetHP() const
{
	return m_fHP;
}

void CObject::SetPos(const POSITION& tPos)
{
	m_tLTPos = tPos;

}

void CObject::SetVector(const POSITION& tVector)
{
	m_tVector = tVector;

}

void CObject::SetSize(const _SIZE tSize)
{
	m_tSize = tSize;

}

void CObject::SetLife(const bool bLife)
{
	m_bLife = bLife;

}

void CObject::SetHP(const float fHP)
{
	m_fHP = fHP;

}



// init ( �̹��� ���� ��� , ȭ�鿡 ����� ������Ʈ ��ġ , ������Ʈ ���� , ������Ʈ ������ , ������Ʈ HP , png ���Ͽ����� ������ , png ���Ͽ����� ��ġ ) 
bool CObject::Init(const WCHAR* imgText, POSITION LTpos, POSITION Vector, _SIZE Size, float HP, POSITION imgSize, POSITION imgLT, PLAYER_TYPE obType)
{


	//m_img_Back.Load(imgText);
	if (m_img_Back == NULL)
	{
		m_img_Back = CSceneManager::GetInst()->GetCimage(imgText);
		if(m_img_Back)
		m_img_Back->SetTransparentColor(RGB(255, 255, 255));

	}
		if (wcscmp(imgText, L"../Bin/Zerg_img/Devourer.png") == 0 && obType == PLAYER_TYPE::PT_PLAYER)
		{
			if (m_img_Back)
			m_img_Back->SetTransparentColor(RGB(0, 0, 0));
		}


	

	m_imgText = new WCHAR[lstrlen(imgText)];
	StringCchCopyW(m_imgText, lstrlen(imgText), imgText);

	m_tLTPos = LTpos;
	m_tVector = Vector;
	m_tSize = Size; 
	m_fHP = HP;
	m_bLife = true;


	m_img_Size = imgSize;
	m_img_LT = imgLT;



	return true;
}

void CObject::Input(float fDeltaTime)
{
}

void CObject::Update(float fDeltaTime)
{

}

void CObject::LateUpdate(float fDeltaTime)
{
}

bool CObject::Collision(float fDeltaTime, POSITION ObjectLT, POSITION ObjectSize)
{
	RECT mypos = { m_tLTPos.x, m_tLTPos.y, m_tLTPos.x + m_tSize.x ,m_tLTPos.y + m_tSize.y };
	RECT CollisionPos = { ObjectLT.x + (ObjectSize.x / 4 ), ObjectLT.y , ObjectLT.x + ObjectSize.x - (ObjectSize.x / 4), ObjectLT.y + ObjectSize.y - (ObjectSize.y / 4) };
	RECT rcTemp;

	return IntersectRect(&rcTemp ,&mypos, &CollisionPos);

}

void CObject::Render(HDC mainhDC, HDC hdc, float fDeltaTime)
{

	if (m_img_Back)
	{
		m_img_Back->Draw(hdc, m_tLTPos.x, m_tLTPos.y, m_tSize.x, m_tSize.y,
			m_img_LT.x, m_img_LT.y, m_img_Size.x, m_img_Size.y);

	}
	
}
