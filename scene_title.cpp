#include "./GameLib/game_lib.h"
#include "./GameLib/template.h"
#include "./GameLib/input_manager.h"
#include "./GameLib/obj2d_data.h"
#include "audio.h"
#include "common.h"
using namespace GameLib;
using namespace input;
int title_state;      // ���
int title_timer;      // �^�C�}�[
float fadeOut;        // �t�F�C�h�A�E�g
extern int nextScene; //�V�[���ڍs�p
//CAT:�摜�ǂݍ���
Sprite* sprData[Spr_Max];
wchar_t* sprName[] =
{
	L"./Data/Images/bg.png",
	L"./Data/Images/number.png",
	L"./Data/Images/shot.png",
	L"./Data/Images/player.png",
	L"./Data/Images/note.png",
	L"./Data/Images/enemy.png",
	L"./Data/Images/boss.png",
	L"./Data/Images/tutorial.png",
};
void spr_load()
{
	for (int i = 0; i < Spr_Max; i++)
	{
		sprite_load(&sprData[i], sprName[i]);
	}
}
void title_init()
{
	spr_load();
    title_state = 0;
    title_timer = 0;
}

void title_update()
{
    int title_max=3;//�^�C�g����ʂ̍ő吔
    switch (title_state)
    {
    case 0:
		music::play(0, true);
        title_state++;
        break;
    case 1:
        if (TRG(0) & PAD_START)
        {
            fadeOut=0.0f;
            title_state++;
        }
        break;
    case 2:
        fadeOut += 0.0167f;
        if (fadeOut >= 1.0f)
        {  title_state++; }
        break;
    }
    if (title_state == title_max) 
    { nextScene = SCENE_GAME; }
    title_timer++;
   }

void title_draw()
{
    if (title_state == 1) //�^�C�g��1
    {
		sprite_render(sprData[Bg], 0, 0, 1, 1, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    }
    if (title_state == 2) //�t�F�C�h�A�E�g
    {
        if (fadeOut > 0.0f) 
        {
            primitive::rect (0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,0, 0, 0, 0, 0, 0, fadeOut);
        }
    }
}

void title_end()
{
	music::unload(0);
	for (int i = 0; i < Spr_Max; i++)
	{
		SAFE_DELETE(sprData[i]);
	}
}



