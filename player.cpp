#include "all.h"
using namespace GameLib;
using namespace input;
OBJ player;
OBJ shot[32];
extern Sprite* sprData[Spr_Max];
void player_init()
{
	player.pos = { 100,300 };
	player.speed.x = 5;
	player.speed.y = 5;
	player.LR = RIGHT;
	for (int i = 0; i < 32; i++)
	{
		shot[i].exist = false;
	}
}
void shot_init()
{
	for (int i = 0; i < 32; i++)
	{
		if (!shot[i].exist)
		{
			shot[i].pos = { player.pos.x,player.pos.y-50};
			shot[i].exist = true;
			break;
		}
	}
}
#define shotspeed (15)//弾の速度
void shot_update()
{
	for (int i = 0; i < 32; i++)
	{
		if (shot[i].exist)
		{
			shot[i].pos.y -= shotspeed;
			//画面外に出たら消す
			if (shot[i].pos.y < 0)  { shot[i].exist = false; }
			if (shot[i].pos.y > 1100) { shot[i].exist = false; }
			if (shot[i].pos.x < 0)  { shot[i].exist = false; }
			if (shot[i].pos.x > 1930) { shot[i].exist = false; }
		}
	}
}
int shot_timer;//弾の発射用タイマー
#define shot_time (5)
void player_update()
{
	//移動処理
	if (STATE(0)&PAD_UP)   {player.pos.y-=player.speed.y;}
	if (STATE(0)&PAD_DOWN) {player.pos.y+=player.speed.y;}
	if (STATE(0)&PAD_LEFT) {player.pos.x-=player.speed.x;}
	if (STATE(0)&PAD_RIGHT){player.pos.x+=player.speed.x;}
	//エリア外チャック
	if (player.pos.x > 1920 - 50) { player.pos.x = 1920 - 50; }
	if (player.pos.x < 50) { player.pos.x = 50; }
	if (player.pos.y < 50) { player.pos.y = 50; }
	if (player.pos.y > 1080 - 50) { player.pos.y = 1080 - 50; }
	//acceleration(&player, 50, 25);
	//弾の発射
	if (STATE(0)&PAD_TRG3)
	{
		if(shot_timer%shot_time ==0)
		shot_init();
		shot_timer++;
	}
	else if(shot_timer!=0){ shot_timer = 0; }//タイマーのリセット
	shot_update();
}

void player_draw()
{
	sprite_render(sprData[PLAYER], player.pos.x, player.pos.y,1,1,0,0,100,100,50,50);
	for(int i=0;i<32;i++)
	if (shot[i].exist)sprite_render(sprData[SHOT], shot[i].pos.x, shot[i].pos.y,1,1,0,0,40,40,20,20);
}

void player_end()
{

}