
// ��ũ�� �Լ��� �����մϴ�. 

#pragma once


#define SAFE_DELETE(p)		 if(p){ delete p; p = NULL;}
#define SAFE_DELETE_ARRAY(p) if(p) {delete[] p; p  = NULL;}
#define SAFE_RELEASE(p)	if(p)	{p->Release(); p = NULL;}

// �̱����� �����մϴ�. 
#define DECLARE_SINGLE(Type)\
private:\
	static Type* m_pInst;\
public:\
	static Type* GetInst()\
	{\
		if(!m_pInst)\
			m_pInst = new Type;\
		return m_pInst;\
	}\
	static void DestroyInst()\
	{\
		SAFE_DELETE(m_pInst);\
	}\
private:\
	Type();\
	~Type();

// �̱����� �ܺο��� �����մϴ�. 
#define DEFINITION_SINGLE(Type) Type* Type::m_pInst = NULL;
// �̱����� ����ϴ�. ( �ܺο��� ��� )
#define GET_SINGLE(Type) Type::GetInst()
// �̱����� �����մϴ�. 
#define DESTROY_SINGLE(Type) Type::DestroyInst()

#define GETRESOLUTION CCore::GetInst()->GetResolution()
