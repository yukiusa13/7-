#include "all.h"
using namespace GameLib;
using namespace input;

OBJ player;
OBJ shot[shotmax];
OBJ missile[missilemax];
extern Sprite* sprData[Spr_Max];


//�Q�[���^�C�}�[
int game_timer;

void player_init()
{
	player.fade = 0;
	player.pos = { SCREEN_WIDTH/2,1300 };
	player.speed = {10,10};
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
#define shotspeed (15)//�e�̑��x
void shot_update()
{
	for (int i = 0; i < shotmax; i++)
	{
		if (shot[i].exist)
		{
			shot[i].pos.y -= shotspeed;
			//��ʊO�ɏo�������
			if (shot[i].pos.y < area_up)    { shot[i].exist = false; }
			if (shot[i].pos.y > area_down)  { shot[i].exist = false; }
			if (shot[i].pos.x < area_left)  { shot[i].exist = false; }
			if (shot[i].pos.x > area_right) { shot[i].exist = false; }
		}
	}
}
int tage[missilemax/2];//�^�[�Q�b�g�̓G���x���ۑ���
extern ENEMY enemy[ENEMYMAX];
void missile_init()
{
	//2�Ây�A��������
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
#define missilespeed (30)//�~�T�C���̑��x
void missile_update()
{
	
	for (int i = 0; i < missilemax; i+=2)
	{
		if (missile[i].exist)
		{
			missile[i].pos.y   -= missilespeed;
			//��ʊO�ɏo�������
			if (missile[i].pos.y < area_up)       { missile[i].exist   = false; }
			if (missile[i].pos.y > area_down )    { missile[i].exist   = false; }
			if (missile[i].pos.x < area_left )    { missile[i].exist   = false; }
			if (missile[i].pos.x > area_right )   { missile[i].exist   = false; }
		}
		if (missile[i + 1].exist)
		{
			missile[i+1].pos.y -= missilespeed;
			//��ʊO�ɏo�������
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
int shot_timer;//�e�̔��˗p�^�C�}�[
#define shot_time (5)//�ʏ�e�̔��ˊԊu
#define missile_timer (60)//�~�T�C���̔��ˊԊu
extern float magnification;
void player_update()
{
	switch (player.fade)
	{
	case 0:
		magnification = 0;
		player.pos.y -= player.speed.y;
		if (player.pos.y < 950)
		{
			player.fade++;
		}
		break;
	case 1:
		//�ړ�����
		if (STATE(0)&PAD_UP) { player.pos.y -= player.speed.y; }
		if (STATE(0)&PAD_DOWN) { player.pos.y += player.speed.y; }
		if (STATE(0)&PAD_LEFT) { player.pos.x -= player.speed.x; }
		if (STATE(0)&PAD_RIGHT) { player.pos.x += player.speed.x; }
		//�G���A�O�`���b�N
		if (player.pos.x > area_right - 50) { player.pos.x = area_right - 50; }
		if (player.pos.x < area_left + 50) { player.pos.x = area_left + 50; }
		if (player.pos.y < area_up + 50) { player.pos.y = area_up + 50; }
		if (player.pos.y > area_down - 50) { player.pos.y = area_down - 50; }

		//�e�̔���
		if (STATE(0)&PAD_TRG3)
		{
			//�ʏ�e�̔���
			if (shot_timer%shot_time == 0)
			{
				shot_init();
				
			}
			//�~�T�C���̔���
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
		else if (shot_timer != 0) { shot_timer = 0; }//�^�C�}�[�̃��Z�b�g
		shot_update();
		missile_update();
		//�V�X�e��//
		acceleration();
		game_timer++;
		break;
	}
}

void player_draw()
{
	
	sprite_render(sprData[PLAYER], player.pos.x, player.pos.y,1,1,0,0,100,100,50,50);
#if debug
	//�����蔻��m�F�p�̃v���~�e�B�u(�~)�̕`��//
	primitive::circle(player.pos.x, player.pos.y, 50, 1, 0, 0, 0.5);
	//�e�̕`��
#endif // debug	
	for (int i = 0; i < shotmax; i++)
	{
		if (shot[i].exist)sprite_render(sprData[SHOT], shot[i].pos.x, shot[i].pos.y, 1, 1, 0, 0, 40, 40, 20, 20);
#if debug	
		if (shot[i].exist)primitive::circle(shot[i].pos.x, shot[i].pos.y, 20, 0, 0, 1, 0.5);
#endif
	}
	//�~�T�C���̕`��
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