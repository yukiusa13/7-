#include "all.h"
using namespace GameLib;
extern int game_timer;
extern int game_state;
extern Sprite* sprData[Spr_Max];
#if debug
extern OBJ test;
#endif
extern int game_timer;
void ui_draw(int state, int score)
{
    switch (state)
    {
    case 0:
        break;
    case 1:
#if debug//テスト用のタイマー
		dispScore(game_timer/60, 200, 0, 0.5, 6);
#endif
		break;
    }
   }
 void dispScore(int sc, float xpos, float ypos, float scale, int keta)
   {
        while (keta--)
        {
            int num = sc % 10;
            float texPosX = num % 5 * (float)NUMBER_WIDTH;
            float texPosY = num / 5 * (float)NUMBER_HEIGHT;
            sprite_render(sprData[number], xpos, ypos, scale, scale,
                texPosX, texPosY,
                NUMBER_WIDTH, NUMBER_HEIGHT,
                0, 0,
                0, 0, 0, 0);
            xpos -= NUMBER_WIDTH * scale;
            sc /= 10;
        }
    }
