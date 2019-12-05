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


#endif // !INCLUDED_OBJ2D
