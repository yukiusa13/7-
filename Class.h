#pragma once
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
	//int switching_time;
	//������
	void class_init();
	//�A�j���[�V�����^�C�}�[���������邽�߂̃t���O�Ԃ��֐�
	bool timer_init(int STATE);
public:
	OBJ();
	void set_state(int STATE);
	int get_state();
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

