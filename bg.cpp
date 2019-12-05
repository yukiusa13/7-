#include "all.h"
#define TEST (1)
using namespace GameLib;
using namespace input;
extern int game_timer;
extern int game_state; 
extern float fadeOut;
extern Sprite* sprData[Spr_Max];
#if TEST
OBJ test[2];
float tp_x;
float tp_y;
int r;
#endif // TEST

void bg_init()
{
#if TEST
	tp_x = 100;
	tp_y = 100;
	r = 0;
#endif // TEST

}
void bg_updata()
{
#if TEST
	if (STATE(0)&PAD_UP)    { tp_y -= 10; }
	if (STATE(0)&PAD_DOWN)  { tp_y += 10; }
	if (STATE(0)&PAD_RIGHT) { tp_x += 10; }
	if (STATE(0)&PAD_LEFT)  { tp_x -= 10; }
	if (Judg_circle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 100, 
		tp_x, tp_y, 100)) { r = 1; }
	else
	{
		r = 0;
	}
#endif // TEST
}
void bg_draw()
{
	if (game_state == 1) //ゲーム1
	{
		primitive::rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,0,0,0,1,0,0,1);
	}
#if TEST
	primitive::circle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,100,0,1,1,1);
	primitive::circle(tp_x, tp_y, 100,0,r,0,1);
	test[0].anim(sprData[number], 60, 5, 2, 10, 480, SCREEN_HEIGHT / 2,1,1,0,0,NUMBER_WIDTH,NUMBER_HEIGHT);
	test[1].anim(sprData[number], 60*10, 5, 2, 10, 480*3, SCREEN_HEIGHT / 2, 1, 1, 0, 0, NUMBER_WIDTH, NUMBER_HEIGHT);
#endif // TEST

    if (game_state == 2)//フェイドアウト用ウィンドウ
    {
        if (fadeOut > 0.0f)
        {
            primitive::rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,0, 0, 0, 0, 0, 0, fadeOut);
        }
    }  
}
