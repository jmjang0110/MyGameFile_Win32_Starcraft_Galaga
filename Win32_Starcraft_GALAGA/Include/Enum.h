#pragma once


// enum class �� �����ϱ� ���ؼ� �����Ǿ����ϴ�...

//  ������ �����ϱ� ���ؼ� �����Ǿ����ϴ�....
enum class OBJECT_TYPE
{
	OT_NONE,
	OT_TERRAN,
	OT_ZERG,
	OT_PROTOSS
};


// ���ݷ� �Դϴ�... 
enum class BULLET_ATTACK
{
	BA_STAGE1 = 120,
	BA_STAGE2 = 200,
	BT_STAGE3 = 300,

};

// ������ Ÿ�� �Դϴ�.... 
enum class ITEM_TYPE
{
	IT_RANDOM,
	IT_STEAMPACK,
	IT_HPUP,
	IT_INVINVIBILITY,
	IT_POWERUP

};

enum class PLAYER_TYPE
{
	PT_PLAYER,
	PT_MONSTER

};