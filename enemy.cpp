#include "all.h"


ENEMY ememy[ENEMYMAX];//ENEMY�N���X�̎���
EnemyData enemy_data[]//�G���
{
	//{�G�̃^�C�v,�G�̏o������,����X���W,����Y���W},




	
	{-1,-1,-1,-1}//�I��
};

//�e�̔��ˎ�������
void ENEMY::shot_init(float px,float py)
{
	for(int i=0;i<shot_max;i++)
	{
		if (!enemyshot[i].exist)
		{
			//�e�̔��˒n�_�̐ݒ�
			enemyshot[i].pos = { px,py };
			enemyshot[i].exist = true;
			break;
	    }
	}
}

//�V���b�g�̈ړ������Ȃ�
void ENEMY::shot_update()
{
	for (int i = 0; i <shot_max; i++)
	{
		//�����Ɉړ������Ȃǂ�������









		if (0)//�����蔻��
		{
			//�_���[�W�����Ƃ�����

			enemyshot[i].exist = false;
		}

	}
}

//�G�̃f�[�^�̐ݒ�
void ENEMY::set_data(int type, float time, float px, float py)
{
	enemy_type = type;
	enemytimer = time;
	pos.x = px;
	pos.y = py;
	for (int i = 0; i < shot_max; i++)
	{
		enemyshot[i].exist = false;//�e�̏������S�Ă̑��݂�����
	}
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


//�X�V����
void ENEMY::update()
{
	switch (enemy_type)
	{
	case 0:enemy0_move();
		break;
	case 1:enemy1_move();
		break;
	case 2:enemy2_move();
		break;
	}
}

//�`�揈��
void ENEMY::dorw()
{
	if (ENEMY::exist)//���݂��Ă�����̂����`��
		{

		}

}
//���ꂪ���ۂɎg�����̏�����
void enemy_set(EnemyData* obj, ENEMY* ene)
{
	ene->set_data(obj->type, obj->time, obj->x, obj->y);
}

////�^�C�v���Ƃ̍s��////
void ENEMY::enemy0_move()
{

}

void ENEMY::enemy1_move()
{

}

void ENEMY::enemy2_move()
{

}
