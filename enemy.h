#pragma once
#include "Class.h"
class ENEMY :
	public OBJ
{
private:
	static const int shot_max = 32;
	OBJ enemyshot[shot_max];//�G�̒e�̎���
	int enemy_type;
	float enemytimer;//�G�o���p�^�C�}�[(��)
	void set_type(int type);//�G�̃^�C�v�̐ݒ�
	void init(float time, float px, float py);//�o�����ԁA�����ʒu�̐ݒ�
public:

	void shot_init(float px, float py);//�e�̔��ˎ�������
	void shot_update();//�V���b�g�̈ړ������Ȃ�
	void update();//
	void dorw();
	void set_data();
};



