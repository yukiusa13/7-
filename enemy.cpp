#include "all.h"

struct EnemyData
{
	int type;   // �o������G�̃^�C�v
	float time;   // �o�����鎞�ԁi�J�E���g�j
	float x, y; // �G���o������ʒu
};
EnemyData enemy_data[]//�G���
{
	//{�G�̃^�C�v,�G�̏o������,����X���W,����Y���W},





	{-1,-1,-1,-1}//�I��
};






















void ENEMY::shot_init(float px,float py)
{
	for(int i=0;i<shot_max;i++)
	{
		if (!enemyshot[i].exist)
		{
			enemyshot[i].pos = { px,py };
			enemyshot[i].exist = true;
			break;
	    }
	}
}

void ENEMY::shot_update()
{
	for (int i = 0; i <shot_max; i++)
	{
		//�����Ɉړ������Ȃǂ�������









		if (0)//�����蔻��
		{
			enemyshot[i].exist = false;
		}

	}
}

void ENEMY::set_type(int type)
{
	enemy_type = type;
#if 0//�^�C�v�ʂ�HP�Ȃǂ�ݒ肷��Ȃ炱�������g��
	switch (type)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	}
#endif
}

void ENEMY::init(float time,float px,float py)
{
	enemytimer = time;
	pos.x = px;
	pos.y = py;
	for (int i = 0; i < shot_max; i++)
	{
		enemyshot[i].exist = false;//�e�̏������S�Ă̑��݂�����
	}
}

void ENEMY::update()
{

}

void ENEMY::dorw()
{

}
//���ꂪ���ۂɎg�����̏�����
void ENEMY::set_data()
{
	for (int i = 0;; i++) {
		if (enemy_data[i].type == -1) { break; }
		set_type(enemy_data[i].type);
		init(enemy_data[i].time, enemy_data[i].x,enemy_data[i].y);

	}
}
