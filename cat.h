#ifndef INCLUDED_OBJ2D
#define INCLUDED_OBJ2D

//矩形の当たり判定
//float px_a,float py_a ->当たり判定を行う2つのオブジェクトの1つ目の左上の座標(X,Y)
//int sx_a,int sy_a ->当たり判定を行う2つのオブジェクトの1つ目の横と縦の長さ(X,Y)
//float px_a,float py_a ->当たり判定を行う2つのオブジェクトの2つ目の左上の座標(X,Y)
//int sx_a,int sy_a ->当たり判定を行う2つのオブジェクトの2つ目の横と縦の長さ(X,Y)
bool Judg_rect(float px_a, float py_a, int sx_a, int sy_a,
	    float px_b, float py_b, int sx_b, int sy_b);
//円の当たり判定
//float px_a,folat py_a->当たり判定を行う2つのオブジェクトの1つ目の中心座標(X,Y)
//int r_a-> 当たり判定を行う2つのオブジェクトの1つ目の半径
//float px_b,folat py_b->当たり判定を行う2つのオブジェクトの2つ目の中心座標(X,Y)
//int r_b-> 当たり判定を行う2つのオブジェクトの2つ目の半径
bool Judg_circle(float px_a, float py_a, int r_a, float px_b, float py_b, int r_b);
////加速度の計算////
//OBJクラスの実体又はその派生クラスの実体
//const float max-> 最高速度
//const float min-> 最低速度
//const float flametimer->基準の速度から最高速、最低速になるまでの時間
void acceleration(OBJ* obj, const float max, const float min, const float flametimer = 30);
void acceleration(ENEMY* obj, const float max, const float min, const float flametimer = 30);
#endif // !INCLUDED_OBJ2D
