#include "all.h"
using namespace GameLib;
using namespace input;
int game_state;    // 状態
int game_timer;    // タイマー
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
    game_state = 0;
    game_timer = 0;
}
void common()
{
	bg_update                                                                                                                                                                                                                                            ();
	player_update();
}
void game_update()
{
    int game_max = 3;//ゲーム画面の最大数
    switch (game_state)
    {
     case 0:
         game_state++;
         break;
     
     case 1:
		 common();
         if (TRG(0) & PAD_START)
         {
             fadeOut = 0.0f;
             game_state++;
         }
    break;
     
     case 2:
         fadeOut += 0.0167f;
         if (fadeOut >= 1.0f)
         {
             game_state++;
         }
         break;
    }
    if (game_state == game_max) 
    {
        nextScene = SCENE_TITLE;
    }
    game_timer++;
}

void game_draw()
{
    bg_draw();
	player_draw();
    ui_draw(game_state, game_score);
}

void game_end()//画像の破棄
{
	for (int i = 0; i < Spr_Max; i++)
	{
		SAFE_DELETE(sprData[i]);
	}
}



