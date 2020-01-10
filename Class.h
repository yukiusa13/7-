#pragma once

struct COLOR
{
	float r, g, b, a;
};
class OBJ
{
private:
	int state;
	//�O�t���[���̏�ԑJ�ڂ̕ۑ���
	int Previous_state;
	//�A�j���[�V�������֘A
	int animetimer;
	int chipcou;
	int chipx;
	int chipy;
	COLOR color;
	//int switching_time;
	//������
	void chip_reset();
	//�A�j���[�V�����^�C�}�[���������邽�߂̃t���O�Ԃ��֐�
	bool timer_init(int STATE);
public:
	OBJ();
	int hp;
	void set_state(int STATE);
	int get_state();
	VECTOR2 speed;
	VECTOR2 pos;
	int LR;
	bool exist;
    //�摜�f�[�^
    //�؂�ւ�����(�t���[���P��)
    //���A�c�̃`�b�v�̌�(x,y)
    //�`�b�v�̑���
    //�`�ʈʒu(x,y)
    //�X�P�[��(x,y)
    //�摜�̊J�n�ʒu(x,y)
    //1�`�b�v�̑傫��(x,y)
    //��_(x,y)
    //�p�x
    //�F(r,g,b,a)
	void anim(GameLib::Sprite* data,
		const int time,
		int NumX, int NumY,
		int max,
		float posx, float posy,
		float sclx, float scly,
		float dataposx, float dataposy,
		float sizex, float sizey,
		float StandardX = 0.0f, float StandardY = 0.0f,
		float rad = 0.0f,
		float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f);
	//�摜�f�[�^
    //���[�V�����I����̏��
    //�؂�ւ�����(�t���[���P��)
    //���A�c�̃`�b�v�̌�(x,y)
    //�`�b�v�̑���
    //�`�ʈʒu(x,y)
    //�X�P�[��(x,y)
    //�摜�̊J�n�ʒu(x,y)
    //1�`�b�v�̑傫��(x,y)
    //��_(x,y)
    //�p�x
    //�F(r,g,b,a)
	void motion(GameLib::Sprite* data,
		int after,
		const int time,
		int NumX, int NumY,
		int max,
		float posx, float posy,
		float sclx, float scly,
		float dataposx, float dataposy,
		float sizex, float sizey,
		float StandardX = 0.0f, float StandardY = 0.0f,
		float rad = 0.0f,
		float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f);
};
//�����蔻��N���X(���̂̂��܂��t��)
class JUDGE
{
public:
	//CAT:�����蔻��
    //�����蔻�����p�̕ϐ�
	bool flg[Flg_Max];
	//��`�̓����蔻��
    //float px_a,float py_a ->�����蔻����s��2�̃I�u�W�F�N�g��1�ڂ̍���̍��W(X,Y)
    //int sx_a,int sy_a ->�����蔻����s��2�̃I�u�W�F�N�g��1�ڂ̉��Əc�̒���(X,Y)
    //float px_a,float py_a ->�����蔻����s��2�̃I�u�W�F�N�g��2�ڂ̍���̍��W(X,Y)
    //int sx_a,int sy_a ->�����蔻����s��2�̃I�u�W�F�N�g��2�ڂ̉��Əc�̒���(X,Y)
	bool rect(float px_a, float py_a, int sx_a, int sy_a,
		float px_b, float py_b, int sx_b, int sy_b);
	//�~�̓����蔻��
	//float px_a,folat py_a->�����蔻����s��2�̃I�u�W�F�N�g��1�ڂ̒��S���W(X,Y)
	//int r_a-> �����蔻����s��2�̃I�u�W�F�N�g��1�ڂ̔��a
	//float px_b,folat py_b->�����蔻����s��2�̃I�u�W�F�N�g��2�ڂ̒��S���W(X,Y)
	//int r_b-> �����蔻����s��2�̃I�u�W�F�N�g��2�ڂ̔��a
	bool circle(float px_a, float py_a, int r_a, float px_b, float py_b, int r_b);
}judge;