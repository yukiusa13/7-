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

//�Q�[���^�C�}�[
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
	for (int i = 0; i < missilemax; i++)
	{
		missile[i].exist = false;
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
#if debug //D(KB)orY(CON)���������璍�Ӄ}�[�N���o��
		extern bool note;
		if(STATE(0)&PAD_TRG4)
		{ 
			note=true;
		}
		else if(note)
		{
			note = false;
		}
		//���[�U�[�̓����蔻��
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
	//�����蔻��m�F�p�̃v���~�e�B�u(�~)�̕`��//
	primitive::circle(player.pos.x, player.pos.y, player_rad, 1, 0, 0, 0.5);
	//�e�̕`��
#endif // debug	
	for (int i = 0; i < shotmax; i++)
	{
		if (shot[i].exist)sprite_render(sprData[Shot], shot[i].pos.x, shot[i].pos.y, 1, 1, 0, 0, 20, 40, 10, 20);
#if debug	
		if (shot[i].exist)primitive::circle(shot[i].pos.x, shot[i].pos.y, shot_rad, 0, 0, 1, 0.5);
#endif
	}
	//�~�T�C���̕`��
	for (int i = 0; i < missilemax; i++)
	{
		if (missile[i].exist)   sprite_render(sprData[Shot], missile[i].pos.x  , missile[i].pos.y  , 1, 1, 0, 0, 20, 40, 10, 20);
		if (missile[i+1].exist) sprite_render(sprData[Shot], missile[i+1].pos.x, missile[i+1].pos.y, 1, 1, 0, 0, 20, 40, 10, 20);
#if debug	
		if (missile[i].exist)   primitive::circle(missile[i].pos.x  , missile[i].pos.y  , shot_rad, 0, 0, 1, 0.5);
		if (missile[i+1].exist) primitive::circle(missile[i+1].pos.x, missile[i+1].pos.y, shot_rad, 0, 0, 1, 0.5);
#endif
#if(0)
		//���[�U�[�`��
		primitive::rect(500, 300, 100, 900,0,0,0,0.5,0,0,0.05f);
		primitive::line(550, 300, 550, 1200,1);
#endif

	}
}
bool tutorialflg[2];//�`���[�g���A���I���t���O
int tutorialtimer[3];
void reset()
{
	for (int i = 0; i < 2; i++)
	{
		tutorialtimer[i] = 0;
		tutorialflg[i] = false;
	}
	tutorialtimer[2] = 0;
}
VECTOR2 uipos;

	
void tutorial()//�`���[�g���A��
{
	uipos = {player.pos.x-100,player.pos.y-150};
	player.next = player.get_state()+1;
	switch (player.get_state())
	{
	case 0://�t�F�C�h�C��
		reset();
		magnification = 0;
		player.pos.y -= player.speed.y;
		if (player.pos.y < 950)
		{
			player.set_state(player.next);
		}
		break;
	case 1://�ړ�
		if (STATE(0)&PAD_UP)
		{
			tutorialtimer[0]++;
		}
		else if (STATE(0)&PAD_DOWN)
		{
			tutorialtimer[0]++;
		}
		else if (STATE(0)&PAD_LEFT)
		{
			tutorialtimer[0]++;
		}
		else if (STATE(0)&PAD_RIGHT)
		{
			tutorialtimer[0]++;
		}
		if (tutorialtimer[0] >= 180)
		{
			tutorialflg[0] = true;
		}
		if (tutorialflg[0])
		{
			tutorialtimer[0]=180;
			tutorialtimer[1]++;
			if (tutorialtimer[1] >= 60)
			{
				reset();
				player.set_state(player.next);
			}
		}
		break;
	case 2://�V���b�g
	
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
			if (shot_timer % 30 == 0)
			{
				sound::play(gibara);
			}
			tutorialtimer[0]++;
			shot_timer++;
		}
		else if (shot_timer != 0) { shot_timer = 0; }//�^�C�}�[�̃��Z�b�g
		if (tutorialtimer[0] >= 120)
		{
			tutorialflg[0] = true;
		}
		
			if (tutorialflg[0])
			{
				tutorialtimer[0] =120;
				tutorialtimer[1]++;
				if (tutorialtimer[1] >= 60)
				{
					reset();
					player.set_state(player.next);
				}
			}
			
		break;
	case 3://��������
		
		acceleration();
		if(STATE(0)&PAD_L1)
		{
			tutorialtimer[1]++;
		}
		
		if (STATE(0)&PAD_R1)
		{
			tutorialtimer[0]++;
		}
		
		if (tutorialtimer[1] >= 90)
		{
			tutorialtimer[1] = 90;
			tutorialflg[1] = true;
		}
		if (tutorialtimer[0] >= 90)
		{
			tutorialtimer[0] = 90;
			tutorialflg[0] = true;
		}
		if (tutorialflg[1] && tutorialflg[1])
		{

			tutorialtimer[2]++;
			if (tutorialtimer[2] >= 60)
			{
				reset();
				player.set_state(player.next);
			}
		}
		break;
	case 4://�t�F�C�h�A�E�g�O����
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
			player.speed.y = -10;
			player.set_state(player.next);
		}
		break;
	case 5://�t�F�C�h�A�E�g
		player.speed.y += 0.5;
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
	shot_update();
	missile_update();
}
void tutorialdrow()
{
	switch (player.get_state())
	{
	case 1:
		player.anim(sprData[Tutorial],30, 4, 1, 4, uipos.x-10, uipos.y, 0.6, 0.6, 0, 0, 100, 100);
		sprite_render(sprData[Tutorial], uipos.x + 55, uipos.y, 0.6, 0.6, 0, 340, 200, 85);
		sprite_render(sprData[Tutorial], uipos.x + 150, uipos.y, 1, 1, 60*(tutorialtimer[0]/12), 280, 60, 60);
		break;
	case 2:
		player.anim(sprData[Tutorial], 60, 2, 1, 2, uipos.x, uipos.y, 0.8,0.8, 0, 200, 80, 80);
		sprite_render(sprData[Tutorial], uipos.x + 70, uipos.y+10, 0.8, 0.8, 0, 540, 200, 85);
		sprite_render(sprData[Tutorial], uipos.x + 160, uipos.y, 1, 1, 60 * (tutorialtimer[0] / 8), 280, 60, 60);
		break;
	case 3:
		player.anim(sprData[Tutorial], 60, 2, 1, 2, uipos.x-10, uipos.y, 1, 1, 0, 100, 80, 100);
		sprite_render(sprData[Tutorial], uipos.x + 70, uipos.y + 0, 0.8,0.8, 0, 424, 200, 115);
		sprite_render(sprData[Tutorial], uipos.x + 180, uipos.y, 0.8, 0.8, 60 * (tutorialtimer[1] / 6), 280, 60, 60);
		sprite_render(sprData[Tutorial], uipos.x + 180, uipos.y+50, 0.8, 0.8, 60 * (tutorialtimer[0] / 6), 280, 60, 60);
		break;
	}
}
#if 0
�`���[�g���A���Z�b�g
�ړ��{�^���@x100_y100
LB�{�^���@x150_y80
RB�{�^��  x200_y80
X�{�^���@x280_y80
�Q�[�W�@x340_y60
�ړ��t�H���g�@x424_y158
�����t�H���g�@x482_y108
�����t�H���g�@x540_y108
�ˌ��t�H���g�@x598_y108

�e�Z�b�g
x40_y22

�G�Z�b�g
x74_y74
#endif