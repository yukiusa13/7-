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
	//もし、前フレームと状態が違うのであれば初期化するフラグを立てる
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
//画像データ
//切り替え時間(フレーム単位)
//横、縦のチップの個数(x,y)
//チップの総数
//描写位置(x,y)
//スケール(x,y)
//画像の開始位置(x,y)
//1チップの大きさ(x,y)
//基準点(x,y)
//角度
//色(r,g,b,a)
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
//画像データ
//モーション終了後の状態
//切り替え時間(フレーム単位)
//横、縦のチップの個数(x,y)
//チップの総数
//描写位置(x,y)
//スケール(x,y)
//画像の開始位置(x,y)
//1チップの大きさ(x,y)
//基準点(x,y)
//角度
//色(r,g,b,a)
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



