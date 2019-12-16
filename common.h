#ifndef INCLUDED_COMMON
#define INCLUDED_COMMON

#define SAFE_DELETE(x)  if(x){delete x;x=NULL;}    
#define ToRadian(x)     DirectX::XMConvertToRadians(x) 
#define SCREEN_WIDTH    (1920)   // 画面の幅
#define SCREEN_HEIGHT   (1080)   // 画面の高さ
#define SCENE_TITLE     (0)
#define SCENE_GAME      (1)
////左右/////
#define LEFT  (-1)
#define RIGHT (1)
void spr_load();//画像読み込み関数
//// スプライト用 ////
enum 
{
	bg = 0,
	number,
	Spr_Max
};
////ミュージック用////
enum 
{
	bgm1 = 0,
	Music_Max
};
////当たり判定用////
enum
{
	pl_en = 0,
	Flg_Max
};

#endif// ! INCLUDED_COMMON
