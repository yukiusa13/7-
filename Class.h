#pragma once
class OBJ
{
private:
	int state;
	//前フレームの状態遷移の保存先
	int Previous_state;
	//アニメーション情報関連
	int animetimer;
	int chipcou;
	int chipx;
	int chipy;
	//int switching_time;
	//初期化
	void class_init();
	//アニメーションタイマー初期化するためのフラグ返す関数
	bool timer_init(int STATE);
public:
	OBJ();
	void set_state(int STATE);
	int get_state();
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
	void anim(GameLib::Sprite* data,
		const int time,
		int NumX, int NumY,
		int max,
		float posx, float posy,
		float sclx, float scly,
		float dataposx, float dataposy,
		float sizex, float sizey,
		float StandardX = 0.0f, float StandardY = 0.0f,
		float rad = 0.0f,
		float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f);
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
	void motion(GameLib::Sprite* data,
		int after,
		const int time,
		int NumX, int NumY,
		int max,
		float posx, float posy,
		float sclx, float scly,
		float dataposx, float dataposy,
		float sizex, float sizey,
		float StandardX = 0.0f, float StandardY = 0.0f,
		float rad = 0.0f,
		float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f);
};

