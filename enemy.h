#pragma once
#include "Class.h"
#define  ENEMYMAX (32)
struct EnemyData
{
	int type;   // �o������G�̃^�C�v
	float time;   // �o�����鎞�ԁi�J�E���g�j
	float x, y; // �G���o������ʒu
};
class ENEMY :
	public OBJ
{
private:
	static const int shot_max = 32;
	OBJ enemyshot[shot_max];//�G�̒e�̎���
	int enemy_type;
	float enemytimer;//�G�o���p�^�C�}�[(��)
public:
	void set_data(int type, float time, float px, float py);//�G�̃^�C�v�̐ݒ�
	void shot_init(float px, float py);//�e�̔��ˎ�������
	void shot_update();//�V���b�g�̈ړ������Ȃ�
	void update();//
	void dorw();
};
	void enemy_set(EnemyData* obj,ENEMY ene);



