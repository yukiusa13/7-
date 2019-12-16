#include "all.h"
using namespace GameLib;

void OBJ::chip_reset()
{
	chipcou =1;
	chipx = 0;
	chipy = 0;
}
OBJ::OBJ()
{
	OBJ::Previous_state=-1;
}
void OBJ::set_state(int STATE)
{
	OBJ::state = STATE;
}
int OBJ::get_state()
{
	return OBJ::state;
}
bool OBJ::timer_init(int STATE)
{
	//�����A�O�t���[���Ə�Ԃ��Ⴄ�̂ł���Ώ���������t���O�𗧂Ă�
	if(OBJ::Previous_state != STATE){
		Previous_state = STATE;
		return true;
	}
	else
	{
		Previous_state = STATE;
	    return false;
	}
}
//�摜�f�[�^
//�؂�ւ�����(�t���[���P��)
//���A�c�̃`�b�v�̌�(x,y)
//�`�b�v�̑���
//�`�ʈʒu(x,y)
//�X�P�[��(x,y)
//�摜�̊J�n�ʒu(x,y)
//1�`�b�v�̑傫��(x,y)
//��_(x,y)
//�p�x
//�F(r,g,b,a)
void OBJ::anim(
	Sprite* data,                             
	const int time,                                 
	int NumX, int NumY,                       
	int max,                                  
	float posx, float posy,                   
	float sclx, float scly,                   
	float dataposx, float dataposy,           
	float sizex, float sizey,                 
	float StandardX, float StandardY,         
	float rad,                                
	float r, float g, float b, float a        
)
{
	//OBJ::switching_time = time;
	if(timer_init(OBJ::state))
	{
		OBJ::animetimer = 0;
	}
	if (OBJ::animetimer <= 0)
	{
		OBJ::chip_reset();
	}
	if (animetimer != 0 && animetimer%time == 0)
	{
		OBJ::chipx++;
		OBJ::chipcou++;
		if (OBJ::chipx >= NumX)
		{
			OBJ::chipx = 0;
			OBJ::chipy++;
		}
		if (chipy >= NumY)
		{
			chipy = 0;
		}
		if (NumX*NumY != max && OBJ::chipcou > max)
		{
			chipcou = 1;
			chipx = chipy = 0;
		}
	}
	sprite_render
	(
		data,
		posx, posy,
		sclx, scly,
		dataposx + (sizex*chipx), dataposy + (sizey*chipy),
		sizex, sizey,
		StandardX, StandardY,
		rad,
		r, g, b, a
	);
	OBJ::animetimer++;
}
//�摜�f�[�^
//���[�V�����I����̏��
//�؂�ւ�����(�t���[���P��)
//���A�c�̃`�b�v�̌�(x,y)
//�`�b�v�̑���
//�`�ʈʒu(x,y)
//�X�P�[��(x,y)
//�摜�̊J�n�ʒu(x,y)
//1�`�b�v�̑傫��(x,y)
//��_(x,y)
//�p�x
//�F(r,g,b,a)
void OBJ::motion(
	Sprite * data,                               
	int after,                                   
	const int time,
	int NumX, int NumY, 						 
	int max, 									  
	float posx, float posy, 					  
	float sclx, float scly, 					  
	float dataposx, float dataposy, 			  
	float sizex, float sizey, 					  
	float StandardX, float StandardY, 			  
	float rad, 									  
	float r, float g, float b, float a)			  
{												  
	//OBJ::switching_time = time;
	if (timer_init(OBJ::state))
	{
		OBJ::animetimer = 0;
	}
	if (OBJ::animetimer <= 0)
	{											  
		OBJ::chip_reset();
	}
	if (animetimer != 0 && animetimer%time == 0)
	{
		chipx++;
		chipcou++;
		if (chipx >= NumX)
		{
			chipx = 0;
			chipy++;
		}
		if (chipy >= NumY)
		{
			chipy = 0;
		}
		if (chipcou > max)
		{
			OBJ::state=after;
		}
	}
	sprite_render
	(
		data,
		posx, posy,
		sclx, scly,
		dataposx + (sizex*chipx), dataposy + (sizey*chipy),
		sizex, sizey,
		StandardX, StandardY,
		rad,
		r, g, b, a
	);
	OBJ::animetimer++;
}



