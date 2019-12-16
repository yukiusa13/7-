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
	if (test.pos.x < 25) { test.LR = RIGHT; }                      //画面端で折り返し
	if (test.pos.x > 1895) { test.LR = LEFT; }                     //画面端で折り返し
	if (STATE(0)&PAD_R1&&test.speed.x<50) { test.speed.x+=0.1; }   //Rが押されている間加速
	else if(test.speed.x>=25){ test.speed.x-= 0.1; }               //はなされると基準の速度まで落とす
	if (STATE(0)&PAD_L1&&test.speed.x > 1) { test.speed.x-= 0.1; } //押されている間減速
	else if (test.speed.x <= 25) { test.speed.x+= 0.1; }           //はなされると基準の速度まで加速
	test.pos.x += (test.speed.x*test.LR);                          //移動処理
#endif // TEST
}
void bg_draw()
{
	if (game_state == 1) //ゲーム1
	{
		primitive::rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,0,0,0,1,0,0,1);
	}
#if TEST
	primitive::circle(test.pos, 50);
	primitive::rect(100, 500, 600, 100, 0, 0, 0, 0, 0,0);
	primitive::rect(100, 500, test.speed.x * 12, 100, 0, 0, 0, 1, 1, 1);
#endif // TEST

    if (game_state == 2)//フェイドアウト用ウィンドウ
    {
        if (fadeOut > 0.0f)
        {
            primitive::rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,0, 0, 0, 0, 0, 0, fadeOut);
        }
    }  
}
