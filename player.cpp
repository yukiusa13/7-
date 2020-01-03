#include "all.h"
using namespace GameLib;
using namespace input;
OBJ player;
#define shotmax (32)
OBJ shot[shotmax];
#define missilemax (16)
OBJ  missile[missilemax];
extern Sprite* sprData[Spr_Max];
void player_init()
{
	player.pos = { 100,300 };
	player.speed.x = 5;
	player.speed.y = 5;
	player.LR = RIGHT;
	for (int i = 0; i < shotmax; i++)
	{
		shot[i].exist = false;
	}
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
#define shotspeed (15)//弾の速度
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
			break;
		}
	}
}
#define missilespeed (30)//ミサイルの速度
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
	if (player.pos.x > area_right - 50)   { player.pos.x = area_right - 50; }
	if (player.pos.x < area_left + 50)    { player.pos.x = area_left + 50;  }
	if (player.pos.y < area_up + 50)      { player.pos.y = area_up + 50;    }
	if (player.pos.y > area_down - 50)    { player.pos.y = area_down - 50;  }
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
	//ミサイルの発射
	if (TRG(0)&PAD_TRG1)
	{
		missile_init();
	}
	missile_update();
}

void player_draw()
{
	
	sprite_render(sprData[PLAYER], player.pos.x, player.pos.y,1,1,0,0,100,100,50,50);
#if debug
	//当たり判定確認用のプリミティブ(円)の描画//
	primitive::circle(player.pos.x, player.pos.y, 50, 1, 0, 0, 0.5);
	//弾の描画
#endif // debug	
	for (int i = 0; i < shotmax; i++)
	{
		if (shot[i].exist)sprite_render(sprData[SHOT], shot[i].pos.x, shot[i].pos.y, 1, 1, 0, 0, 40, 40, 20, 20);
#if debug	
		if (shot[i].exist)primitive::circle(shot[i].pos.x, shot[i].pos.y, 20, 0, 0, 1, 0.5);
#endif
	}
	//ミサイルの描画
	for (int i = 0; i < missilemax; i++)
	{
		if (missile[i].exist)   sprite_render(sprData[SHOT], missile[i].pos.x  , missile[i].pos.y  , 1, 1, 40, 0, 40, 40, 20, 20);
		if (missile[i+1].exist) sprite_render(sprData[SHOT], missile[i+1].pos.x, missile[i+1].pos.y, 1, 1, 40, 0, 40, 40, 20, 20);
#if debug	
		if (missile[i].exist)   primitive::circle(missile[i].pos.x  , missile[i].pos.y  , 20, 0, 0, 1, 0.5);
		if (missile[i+1].exist) primitive::circle(missile[i+1].pos.x, missile[i+1].pos.y, 20, 0, 0, 1, 0.5);
#endif
	}
}

void player_end()
{

}