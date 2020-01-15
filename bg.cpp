#include "all.h"

using namespace GameLib;
using namespace input;
extern int game_timer;
extern int game_state; 
extern float fadeOut;
extern Sprite* sprData[Spr_Max];
OBJ stage[2];
#define stage_speed (10)
extern float magnification;
void bg_init()
{
	stage[0].pos = { area_left ,area_up };
	stage[0].speed.y = stage_speed;
	stage[1].pos = { area_left ,area_down };
	stage[1].speed.y = stage_speed;
}
void bg_update()
{
	stage[0].pos += stage[0].speed*magnification;
	stage[1].pos += stage[1].speed*magnification;
	if (stage[0].pos.y>=area_down) { stage[0].pos.y = -area_down; }
	if (stage[1].pos.y>=area_down) { stage[1].pos.y = -area_down; }
}
void bg_draw()
{
	if (game_state == 1) //ゲーム1
	{
		primitive::rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 0, 1, 1, 1, 1);
		primitive::rect(stage[0].pos.x, stage[0].pos.y, area_right - area_left, area_down - area_up ,
			            0,0 , 0,0, 1, 0);
		primitive::rect(stage[1].pos.x, stage[1].pos.y, area_right - area_left, area_down - area_up,
			            0, 0, 0, 1, 1, 0);
	}


    if (game_state == 2)//フェイドアウト用ウィンドウ
    {
        if (fadeOut > 0.0f)
        {
            primitive::rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,0, 0, 0, 0, 0, 0, fadeOut);
        }
    }  
}
