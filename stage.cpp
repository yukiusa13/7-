#include "./GameLib/game_lib.h"
#include "./GameLib/template.h"
#include "./GameLib/input_manager.h"
#include "./GameLib/obj2d_data.h"

#include "Class.h"
int fadostate;
extern bool tutorialflg[2];
void player_init();
void enemy_init();
int stagenum;
extern int game_state;

void stagechange(OBJ *obj)
{
	switch (fadostate)
	{
	case 0:
		if (obj->pos.x != SCREEN_WIDTH / 2)
		{
			if (obj->pos.x < SCREEN_WIDTH / 2)
			{
				obj->pos.x += obj->speed.x;
			}
			else
			{
				obj->pos.x -= obj->speed.x;
			}
		}
		else { tutorialflg[0] = true; }
		if (obj->pos.y != SCREEN_HEIGHT / 2)
		{
			if (obj->pos.y < SCREEN_HEIGHT / 2)
			{
				obj->pos.y += obj->speed.y;
			}
			else
			{
				obj->pos.y -= obj->speed.y;
			}
		}
		else { tutorialflg[1] = true; }
		if (tutorialflg[0] && tutorialflg[1])
		{
			obj->speed.y = -10;
			fadostate++;
		}
		break;
	case 1:
		obj->speed.y += 0.5;
		obj->pos.y -= obj->speed.y;
		//画面外に出た時の処理
		if (obj->pos.y <= -50)
		{
			//ステージがまだのっこってるなら
			if ((stagenum + 1) < 1)
			{
				player_init();
				enemy_init();
				stagenum++;
			}
			else { game_state++; }

			break;
		}

	}
}