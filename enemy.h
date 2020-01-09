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
	int enemy_type=-1;//�G�̃^�C�v�@�����l�̓}�C�i�X�@
	float enemytimer;//�G�o���p�^�C�}�[(��)
public:
	
	void set_data(int type, float time, float px, float py);//�G�̃f�[�^�̐ݒ�
	void shot_init(float px, float py);//�e�̔��ˎ�������
	void shot_update();//�V���b�g�̈ړ������Ȃ�
	void update();//�X�V����
	void dorw();//�`�揈��
	void enemy0_move();//�G�^�C�v�O�̍s��
	void enemy1_move();//�G�^�C�v�P�̍s��
	void enemy2_move();//�G�^�C�v�Q�̍s��
};
////�G�l�~�[�̏�����////
//�G�l�~�[�̃f�[�^�̍\���̂̎���
//�G�l�~�[�̎���
	void enemy_set(EnemyData* obj,ENEMY ene);
////�����x�̌v�Z////
//���x��ς���OBJ�̎���
//�ō����x
//�Œᑬ�x
//��̑��x����ō����x�A�Œᑬ�x�܂ł̎��Ԉ����Ȃ���0.5�b
	void acceleration(ENEMY* obj, const float max, const float min, const float flametimer = 30);


