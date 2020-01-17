#include "./GameLib/game_lib.h"
#include "./GameLib/template.h"
#include "./GameLib/input_manager.h"
#include "./GameLib/obj2d_data.h"
#include "Class.h"
#include "common.h"
#include "data.h"
using namespace GameLib;
using namespace input;
extern int game_timer;
extern int game_state; 
extern float fadeOut;
extern Sprite* sprData[Spr_Max];
OBJ stage[2];

extern float magnification;
float note_a = 0.5;//注意の透明度
int ud;//透明度の上下
int note_timer;	//注意のタイマー
bool note_flg;//注意マークの描画フラグ
bool note;//注意関係の関数呼び出しフラグ
//注意マークの点滅処理
void note_update()
{
	if (note)
	{
		//画面を赤くする
		switch (ud)
		{
		case 0:

			if (note_timer % 5 == 0)
			{
				note_a += 0.1;
			}
			if (note_a >= 0.75)
			{
				ud = 1;
			}
			if (!note_flg)note_flg = true;
			break;
		case 1:
			if (note_timer % 5 == 0)
			{
				note_a -= 0.1;
			}
			if (note_a <= 0.2)
			{
				ud = 0;
			}
			if (note_flg)note_flg = false;
			break;
		}
		note_timer++;
	}
	else if (note_timer!=0)note_timer = 0;
}
void note_draw()
{
	if (note)
	{
		//画面を赤くする
		primitive::rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 0, 1, 0, 0, note_a);
		if (note_flg)
		{
			sprite_render(sprData[Note], SCREEN_WIDTH / 2, 200, 1, 1, 0, 0, 300, 300, 150, 150);
		}
	}
	
}
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
		sprite_render(sprData[Bg], 0, 0, 1, 1, 0, SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT);
		sprite_render(sprData[Bg], stage[0].pos.x, stage[0].pos.y,1,1, SCREEN_WIDTH,0, area_right - area_left, 1200);
		sprite_render(sprData[Bg], stage[1].pos.x, stage[1].pos.y, 1, 1, SCREEN_WIDTH, 0, area_right - area_left, 1200);
	}


    if (game_state == 2)//フェイドアウト用ウィンドウ
    {
        if (fadeOut > 0.0f)
        {
            primitive::rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,0, 0, 0, 0, 0, 0, fadeOut);
        }
    }  
}
