#include "all.h"
#define TEST (1)
using namespace GameLib;
using namespace input;
extern int game_timer;
extern int game_state; 
extern float fadeOut;
extern Sprite* sprData[Spr_Max];
#if TEST
OBJ test;
#endif // TEST

void bg_init()
{
#if TEST
	test.pos = { 100,300 };
	test.speed.x = 25;
	test.LR = RIGHT;
#endif // TEST

}
void bg_updata()
{
#if TEST
	if (test.pos.x < 25) { test.LR = RIGHT; }                      //��ʒ[�Ő܂�Ԃ�
	if (test.pos.x > 1895) { test.LR = LEFT; }                     //��ʒ[�Ő܂�Ԃ�
	if (STATE(0)&PAD_R1&&test.speed.x<50) { test.speed.x+=0.1; }   //R��������Ă���ԉ���
	else if(test.speed.x>=25){ test.speed.x-= 0.1; }               //�͂Ȃ����Ɗ�̑��x�܂ŗ��Ƃ�
	if (STATE(0)&PAD_L1&&test.speed.x > 1) { test.speed.x-= 0.1; } //������Ă���Ԍ���
	else if (test.speed.x <= 25) { test.speed.x+= 0.1; }           //�͂Ȃ����Ɗ�̑��x�܂ŉ���
	test.pos.x += (test.speed.x*test.LR);                          //�ړ�����
#endif // TEST
}
void bg_draw()
{
	if (game_state == 1) //�Q�[��1
	{
		primitive::rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,0,0,0,1,0,0,1);
	}
#if TEST
	primitive::circle(test.pos, 50);
	primitive::rect(100, 500, 600, 100, 0, 0, 0, 0, 0,0);
	primitive::rect(100, 500, test.speed.x * 12, 100, 0, 0, 0, 1, 1, 1);
#endif // TEST

    if (game_state == 2)//�t�F�C�h�A�E�g�p�E�B���h�E
    {
        if (fadeOut > 0.0f)
        {
            primitive::rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,0, 0, 0, 0, 0, 0, fadeOut);
        }
    }  
}
