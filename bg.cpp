#include "all.h"

using namespace GameLib;
using namespace input;
extern int game_timer;
extern int game_state; 
extern float fadeOut;
extern Sprite* sprData[Spr_Max];
OBJ stage;

void bg_init()
{

}
void bg_update()
{

}
void bg_draw()
{
	if (game_state == 1) //�Q�[��1
	{
		primitive::rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,0,0,0,1,1,1,1);
	}


    if (game_state == 2)//�t�F�C�h�A�E�g�p�E�B���h�E
    {
        if (fadeOut > 0.0f)
        {
            primitive::rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,0, 0, 0, 0, 0, 0, fadeOut);
        }
    }  
}
