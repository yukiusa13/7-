#pragma once
#include "Class.h"
#define  ENEMYMAX (32)
struct EnemyData
{
	int type;   // �o������G�̃^�C�v
	float app;  // �G�̏o���ꏊ
	float x, y; // �G���o������ʒu
};
class ENEMY :
	public OBJ
{
private:
	static const int shot_max = 32;
	OBJ enemyshot[shot_max];//�G�̒e�̎���
	int enemy_type=-1;//�G�̃^�C�v�@�����l�̓}�C�i�X�@
	float enemy_app;//�G�̏o���ꏊ
public:
	
	void set_data(int type,float app, float px, float py);//�G�̃f�[�^�̐ݒ�
	void shot_init(float px, float py);//�e�̔��ˎ�������
	void shot_update();//�V���b�g�̈ړ������Ȃ�
	void update();//�X�V����
	void dorw();//�`�揈��
	void enemy0_move();//�G�^�C�v�O�̍s��
	void enemy1_move();//�G�^�C�v�P�̍s��
	void enemy2_move();//�G�^�C�v�Q�̍s��
#if debug
	void enemy_test();
#endif
};
////�G�l�~�[�̏�����////
//�G�l�~�[�̃f�[�^�̍\���̂̎���
//�G�l�~�[�̎���
	void enemy_set(EnemyData* obj,ENEMY ene);
	void enemy_init();//game_init�������
	void enemy_update();//game_update�������
	void enemy_draw();//game_draw�������


#if 0
	//�o���ꏊ�܂ŗ����瑶�݃t���O�𗧂Ă�
	switch (fade)
	{
	case 0:
		enemy_app -= stage[0].speed.y;
		if (enemy_app <= 0)
		{
			exist = true;
			fade++;
		}
		break;
	case 1:
		//�����Ɉړ������Ȃǂ�������

		break;
	}
#endif // 0
