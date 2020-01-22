#include "./GameLib/game_lib.h"
#include "./GameLib/template.h"
#include "./GameLib/input_manager.h"
#include "./GameLib/obj2d_data.h"
#include "Class.h"
#include "common.h"
#include "data.h"
#include "player.h"
#include "enemy.h"
#include "cat.h"
#include "audio.h"
using namespace GameLib;
using namespace input;

OBJ player;
OBJ shot[shotmax];
OBJ missile[missilemax];
extern Sprite* sprData[Spr_Max];
extern int game_state;

//ゲームタイマー
int game_timer;

void player_init()
{
	player.set_state(0);
	player.pos = { SCREEN_WIDTH/2,1300 };
	player.speed = {10,10};
	player.LR = RIGHT;
	for (int i = 0; i < shotmax; i++)
	{
		shot[i].exist = false;
	}
	game_timer=0;
}

void shot_init()
{
	for (int i = 0; i < shotmax; i++)
	{
		if (!shot[i].exist)
		{
			shot[i].pos = { player.pos.x,player.pos.y-50};
			shot[i].exist = true;
			break;
		}
	}
}

void shot_update()
{
	for (int i = 0; i < shotmax; i++)
	{
		if (shot[i].exist)
		{
			shot[i].pos.y -= shotspeed;
			//画面外に出たら消す
			if (shot[i].pos.y < area_up)    { shot[i].exist = false; }
			if (shot[i].pos.y > area_down)  { shot[i].exist = false; }
			if (shot[i].pos.x < area_left)  { shot[i].exist = false; }
			if (shot[i].pos.x > area_right) { shot[i].exist = false; }
		}
	}
}
int tage[missilemax/2];//ターゲットの敵ラベル保存先
extern ENEMY enemy[ENEMYMAX];
void missile_init()
{
	//2個づつペア分けする
	for (int i = 0; i < missilemax; i += 2)
	{

		if (!missile[i].exist)
		{
			missile[i].pos   = { player.pos.x+25,player.pos.y};
			missile[i+1].pos = { player.pos.x-25,player.pos.y};
			missile[i].exist   = true;
			missile[i+1].exist = true;
			for (int j = 0; j < ENEMYMAX; j++)
			{
				switch (j)
				{
				case 0:
					tage[i/2] = j;
					break;
				default:
					if (enemy[j].pos.y > enemy[tage[i/2]].pos.y&&enemy[j].exist)
					{
						tage[i/2] = j;
					}
					break;
				}
			}
			
		
			break;
		}
	}
}

void missile_update()
{
	
	for (int i = 0; i < missilemax; i+=2)
	{
		if (missile[i].exist)
		{
			missile[i].pos.y   -= missilespeed;
			//画面外に出たら消す
			if (missile[i].pos.y < area_up)       { missile[i].exist   = false; }
			if (missile[i].pos.y > area_down )    { missile[i].exist   = false; }
			if (missile[i].pos.x < area_left )    { missile[i].exist   = false; }
			if (missile[i].pos.x > area_right )   { missile[i].exist   = false; }
		}
		if (missile[i + 1].exist)
		{
			missile[i+1].pos.y -= missilespeed;
			//画面外に出たら消す
			if (missile[i+1].pos.y < area_up)    { missile[i+1].exist = false; }
			if (missile[i+1].pos.y > area_down)  { missile[i+1].exist = false; }
			if (missile[i+1].pos.x < area_left)  { missile[i+1].exist = false; }
			if (missile[i+1].pos.x > area_right) { missile[i+1].exist = false; }
		}
		//missile[i].speed = { (player.pos.x - enemy[tage[i]].pos.x) / 50,(player.pos.y - enemy[tage[i]].pos.y) / 50 };
		//missile[i+1].speed = { (player.pos.x - enemy[tage[i]].pos.x) / 50,(player.pos.y - enemy[tage[i]].pos.y) / 50 };
		//missile[i].pos -= missile[i].speed;
        //missile[i+1].pos -= missile[i+1].speed;
	}
}
int shot_timer;//弾の発射用タイマー

extern float magnification;
void player_update()
{
	player.next = player.get_state() + 1;
	switch (player.get_state())
	{
	case 0:
		magnification = 0;
		player.pos.y -= player.speed.y;
		if (player.pos.y < 950)
		{
			player.set_state(player.next);
		}
		break;
	case 1:
		//移動処理
		if (STATE(0)&PAD_UP) { player.pos.y -= player.speed.y; }
		if (STATE(0)&PAD_DOWN) { player.pos.y += player.speed.y; }
		if (STATE(0)&PAD_LEFT) { player.pos.x -= player.speed.x; }
		if (STATE(0)&PAD_RIGHT) { player.pos.x += player.speed.x; }
		//エリア外チャック
		if (player.pos.x > area_right - 50) { player.pos.x = area_right - 50; }
		if (player.pos.x < area_left + 50) { player.pos.x = area_left + 50; }
		if (player.pos.y < area_up + 50) { player.pos.y = area_up + 50; }
		if (player.pos.y > area_down - 50) { player.pos.y = area_down - 50; }

		//弾の発射
		if (STATE(0)&PAD_TRG3)
		{
			//通常弾の発射
			if (shot_timer%shot_time == 0)
			{
				shot_init();
				
			}
			//ミサイルの発射
			if (shot_timer%missile_timer == 0 && shot_timer)
			{
				missile_init();
			}
			if (shot_timer % 300==0)
			{
				sound::play(gibara);
			}
			shot_timer++;
		}
		else if (shot_timer != 0) { shot_timer = 0; }//タイマーのリセット
		shot_update();
		missile_update();
		//システム//
		acceleration();
#if debug //D(KB)orY(CON)を押したら注意マークを出す
		extern bool note;
		if(STATE(0)&PAD_TRG4)
		{ 
			note=true;
		}
		else if(note)
		{
			note = false;
		}
		//レーザーの当たり判定
		//if (judge.laser(0, 300, 1200, 550, 50, player.pos, player_rad))
		//{
		//	note = true;
		//}
#endif
		game_timer++;
		break;
	}
}

void player_draw()
{
	player.anim(sprData[Player], 10, 4, 1, 4, player.pos.x, player.pos.y, 1, 1, 0, 0, 100, 100, 50, 50);
	//sprite_render(sprData[Player], player.pos.x, player.pos.y,1,1,0,0,100,100,50,50);
#if debug
	//当たり判定確認用のプリミティブ(円)の描画//
	primitive::circle(player.pos.x, player.pos.y, player_rad, 1, 0, 0, 0.5);
	//弾の描画
#endif // debug	
	for (int i = 0; i < shotmax; i++)
	{
		if (shot[i].exist)sprite_render(sprData[Shot], shot[i].pos.x, shot[i].pos.y, 1, 1, 0, 0, 20, 40, 10, 20);
#if debug	
		if (shot[i].exist)primitive::circle(shot[i].pos.x, shot[i].pos.y, shot_rad, 0, 0, 1, 0.5);
#endif
	}
	//ミサイルの描画
	for (int i = 0; i < missilemax; i++)
	{
		if (missile[i].exist)   sprite_render(sprData[Shot], missile[i].pos.x  , missile[i].pos.y  , 1, 1, 0, 0, 20, 40, 10, 20);
		if (missile[i+1].exist) sprite_render(sprData[Shot], missile[i+1].pos.x, missile[i+1].pos.y, 1, 1, 0, 0, 20, 40, 10, 20);
#if debug	
		if (missile[i].exist)   primitive::circle(missile[i].pos.x  , missile[i].pos.y  , shot_rad, 0, 0, 1, 0.5);
		if (missile[i+1].exist) primitive::circle(missile[i+1].pos.x, missile[i+1].pos.y, shot_rad, 0, 0, 1, 0.5);
#endif
#if(0)
		//レーザー描画
		primitive::rect(500, 300, 100, 900,0,0,0,0.5,0,0,0.05f);
		primitive::line(550, 300, 550, 1200,1);
#endif

	}
}
bool tutorialflg[4];//チュートリアル終了フラグ
int tutorialtimer[4];
void reset()
{
	for (int i = 0; i < 4; i++)
	{
		tutorialtimer[i] = 0;
		tutorialflg[i] = false;
	}
}

	
void tutorial()//チュートリアル
{
	player.next = player.get_state()+1;
	switch (player.get_state())
	{
	case 0:
		reset();
		magnification = 0;
		player.pos.y -= player.speed.y;
		if (player.pos.y < 950)
		{
			player.set_state(player.next);
		}
		break;
	case 1:
		if (STATE(0)&PAD_UP) 
		{
			
			if (tutorialtimer[0]>=30)
			{
				tutorialflg[0] = true;
			}
			tutorialtimer[0]++; 
		}
		else tutorialtimer[0] = 0;
		if (STATE(0)&PAD_DOWN)  
		{
			
			if (tutorialtimer[1] >= 30)
			{
				tutorialflg[1] = true;
			}
			tutorialtimer[1]++;
		}
		else tutorialtimer[1] = 0;
		if (STATE(0)&PAD_LEFT) 
		{
 
			if (tutorialtimer[2] >= 30)
			{
				tutorialflg[2] = true;
			}
			tutorialtimer[2]++;
		}
		else tutorialtimer[2] = 0;
		if (STATE(0)&PAD_RIGHT) 
		{
			if (tutorialtimer[3] >= 30)
			{
				tutorialflg[3] = true;
			}
			tutorialtimer[3]++;
		}
		else tutorialtimer[3] = 0;
	
		if (tutorialflg[0] && tutorialflg[1] && tutorialflg[2] && tutorialflg[3])
		{
			reset();
			player.set_state(player.next);
		}
		break;
	case 2:
	
		//弾の発射
		if (STATE(0)&PAD_TRG3)
		{
			//通常弾の発射
			if (shot_timer%shot_time == 0)
			{
				shot_init();

			}
			//ミサイルの発射
			if (shot_timer%missile_timer == 0 && shot_timer)
			{
				missile_init();
			}
			if (shot_timer % 30 == 0)
			{
				sound::play(gibara);
			}
			
			shot_timer++;
		}
		else if (shot_timer != 0) { shot_timer = 0; }//タイマーのリセット
		if (shot_timer >= 300)
		{
			tutorialflg[0] = true;
		}
		if (tutorialflg[0])
		{
			player.set_state(player.next);
		}
		break;
	case 3:
		
		acceleration();
		if(STATE(0)&PAD_L1)
		{
			tutorialtimer[1]++;
		}
		else { tutorialtimer[1]=0;}
		if (STATE(0)&PAD_R1)
		{
			tutorialtimer[2]++;
		}
		else { tutorialtimer[2]=0; }
		if (tutorialtimer[1] >= 30)
		{
			tutorialflg[1] = true;
		}
		if (tutorialtimer[2] >= 30)
		{
			tutorialflg[2] = true;
		}
		if (tutorialflg[1] && tutorialflg[2])
		{
			reset();
			player.set_state(player.next);
		}
		break;
	case 4:
		if (player.pos.x != SCREEN_WIDTH / 2)
		{
			if (player.pos.x < SCREEN_WIDTH / 2)
			{
				player.pos.x += player.speed.x;
			}
			else
			{
				player.pos.x -= player.speed.x;
			}
		}
		else { tutorialflg[0] = true; }
		if (player.pos.y != SCREEN_HEIGHT/2)
		{
			if (player.pos.y < SCREEN_HEIGHT / 2)
			{
				player.pos.y += player.speed.y;
			}
			else
			{
				player.pos.y -= player.speed.y;
			}
		}
		else { tutorialflg[1] = true; }
		if (tutorialflg[0] && tutorialflg[1])
		{
			player.set_state(player.next);
		}
		break;
	case 5:
		player.pos.y -= player.speed.y;
		if (player.pos.y <= -50)
		{
			player_init();
			
			game_state++;
		}
		break;

	}
	switch (player.get_state())
	{
		case 1:
		case 2:
			magnification = 0.5;
		case 3:
			shot_update();
			missile_update();
			if (STATE(0)&PAD_UP) { player.pos.y -= player.speed.y; }
			if (STATE(0)&PAD_DOWN) { player.pos.y += player.speed.y; }
			if (STATE(0)&PAD_LEFT) { player.pos.x -= player.speed.x; }
			if (STATE(0)&PAD_RIGHT) { player.pos.x += player.speed.x; }
			if (player.pos.x > area_right - 50) { player.pos.x = area_right - 50; }
			if (player.pos.x < area_left + 50) { player.pos.x = area_left + 50; }
			if (player.pos.y < area_up + 50) { player.pos.y = area_up + 50; }
			if (player.pos.y > area_down - 50) { player.pos.y = area_down - 50; }
		break;
		case 4:
			magnification = 0.5;
	}
	
}