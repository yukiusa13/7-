#pragma once

struct COLOR
{
	float r, g, b, a;
};
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
	COLOR color;
	//int switching_time;
	//初期化
	void chip_reset();
	//アニメーションタイマー初期化するためのフラグ返す関数
	bool timer_init(int STATE);
public:
	OBJ();
	int hp;
	void set_state(int STATE);
	int get_state();
	VECTOR2 speed;
	VECTOR2 pos;
	int LR;
	bool exist;
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
//当たり判定クラス(実体のおまけ付き)
class JUDGE
{
public:
	//CAT:当たり判定
    //当たり判定代入用の変数
	bool flg[Flg_Max];
	//矩形の当たり判定
    //float px_a,float py_a ->当たり判定を行う2つのオブジェクトの1つ目の左上の座標(X,Y)
    //int sx_a,int sy_a ->当たり判定を行う2つのオブジェクトの1つ目の横と縦の長さ(X,Y)
    //float px_a,float py_a ->当たり判定を行う2つのオブジェクトの2つ目の左上の座標(X,Y)
    //int sx_a,int sy_a ->当たり判定を行う2つのオブジェクトの2つ目の横と縦の長さ(X,Y)
	bool rect(float px_a, float py_a, int sx_a, int sy_a,
		float px_b, float py_b, int sx_b, int sy_b);
	//円の当たり判定
	//float px_a,folat py_a->当たり判定を行う2つのオブジェクトの1つ目の中心座標(X,Y)
	//int r_a-> 当たり判定を行う2つのオブジェクトの1つ目の半径
	//float px_b,folat py_b->当たり判定を行う2つのオブジェクトの2つ目の中心座標(X,Y)
	//int r_b-> 当たり判定を行う2つのオブジェクトの2つ目の半径
	bool circle(float px_a, float py_a, int r_a, float px_b, float py_b, int r_b);
}judge;