#include "all.h"

extern OBJ stage;
ENEMY ememy[ENEMYMAX];//ENEMY�N���X�̎���
EnemyData enemy_data[]//�G���
{
	//{�G�̃^�C�v,�G�̏o���ꏊ,����X���W,����Y���W},




	
	{-1,-1,-1,-1}//�I��
};
#if 1
EnemyData enemy_test[]//�G���
{
	//{�G�̃^�C�v,�G�̏o���ꏊ,����X���W,����Y���W},
	{10,1000,100,-200},
	{10,1100,100,-300},
	{10,1200,100,-400},
	{10,1300,100,-500},
	{10,1400,100,-600},
	{10,1500,100,-700},
	{10,1600,100,-800},
	{10,1700,100,-900},
	{10,1800,100,-1000},
	{-1,-1,-1,-1}//�I��
};
#endif
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
		//�o���ꏊ�܂ŗ����瑶�݃t���O�𗧂Ă�
		if (enemy_app >= stage.pos.y)
		{
			exist = true;
		}
		//�����Ɉړ������Ȃǂ�������








		if (0)//�����蔻��
		{
			//�_���[�W�����Ƃ�����

			enemyshot[i].exist = false;
		}

	}
}

//�G�̃f�[�^�̐ݒ�
void ENEMY::set_data(int type,float app,float px, float py)
{
	enemy_type = type;
	enemy_app = app;
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
	ene->set_data(obj->type, obj->app,obj->x, obj->y);
}


////�^�C�v���Ƃ̍s��////
void ENEMY::enemy0_move()
{
	switch (get_state())
	{
	case 0:

		break;
	case 1:

		break;
	}
}

void ENEMY::enemy1_move()
{
	switch (get_state())
	{
	case 0:

		break;
	case 1:

		break;
	}
}

void ENEMY::enemy2_move()
{
	switch (get_state())
	{
	case 0:

		break;
	case 1:

		break;
	}
}
