#include "./GameLib/game_lib.h"
#include "./GameLib/template.h"
#include "./GameLib/input_manager.h"
#include "./GameLib/obj2d_data.h"
#include "common.h"
#include "bg.h"
#include "enemy.h"
#include "player.h"
#include "ui.h"
#include "audio.h"
using namespace GameLib;
using namespace input;
int game_state;    // 状態
int game_score;
extern int nextScene;
extern float fadeOut;
extern Sprite* sprData[Spr_Max];
extern wchar_t* sprName[];


void game_init()
{
	spr_load();
	bg_init();
	player_init();
	enemy_init();
    game_state = 0;
	fadeOut = 0;
}
void common()
{
	bg_update();                                                                                                                                                                                                                                          
	player_update();
	enemy_update();
	note_update();
}
void game_update()
{
    int game_max = 5;//ゲーム画面の最大数
    switch (game_state)
    {
     case 0:
         game_state++;
         break;
	 case 1://チュートリアル
		 tutorial();
		 bg_update();
		 break;
     case 2:
		 fadeOut += 0.0167f;
		 if (fadeOut >= 1.0f)
		 {
			 fadeOut = 0;
			 game_state++;
		 }
		 break;
     case 3:
		 common();
         if (TRG(0) & PAD_START)
         {
             fadeOut = 0.0f;
             game_state++;
         }
    break;
     
     case 4:
         fadeOut += 0.0167f;
         if (fadeOut >= 1.0f)
         {
             game_state++;
         }
         break;
    }
    if (game_state >= game_max) 
    {
        nextScene = SCENE_TITLE;
    }
   
}

void game_draw()
{
		bg_draw();
	switch (game_state)
	{
	case 1:
	
		tutorialdrow();
	case 3:
		enemy_draw();
		player_draw();
		note_draw();
		
		break;


	}
	sprite_render(sprData[Bg], 0, 0, 1, 1, 0, SCREEN_HEIGHT, area_left, SCREEN_HEIGHT);
	sprite_render(sprData[Bg], area_right, 0, 1, 1, area_right, SCREEN_HEIGHT, area_left, SCREEN_HEIGHT);
	ui_draw(game_state, game_score);
		if (fadeOut > 0.0f)
		{
			primitive::rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 0, 0, 0, 0, fadeOut);
		}
	
}

void game_end()//画像の破棄
{
	for (int i = 0; i < Spr_Max; i++)
	{
		SAFE_DELETE(sprData[i]);
	}
}



