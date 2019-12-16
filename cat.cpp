#include "all.h"
using namespace GameLib;
using namespace input;
//CAT:当たり判定
////当たり判定代入用の変数////
bool judgflg[Flg_Max];
////矩形の当たり判定////
bool Judg_rect(float px_a,float py_a,int sx_a,int sy_a, float px_b, float py_b, int sx_b, int sy_b)
{
		bool jflg[2];
		float px_c, py_c, px_d, py_d;
	    px_c = (px_a + sx_a), py_c = (py_a + sy_a), px_d = (px_b + sx_b), py_d = (py_b + sy_b);
		if (px_a <= px_b || px_a <= px_d) { if (px_c >= px_b || px_c >= px_d) { jflg[0] = true; } }
		else if (px_b <= px_a || px_b <= px_c) { if (px_d >= px_a || px_d >= px_c) { jflg[0] = true; } }
		else { jflg[0] = false; }
		if (py_a <= py_b || py_a <= py_d) { if (py_c >= py_b || py_c >= py_d) { jflg[1] = true; } }
		else if (py_b <= py_a || py_b <= py_c) { if (py_d >= py_a || py_d >= py_c) { jflg[1] = true; } }
		else { jflg[1] = false; }
		if (jflg[0] == true && jflg[1] == true) { return true; }
		else { return false; }
}
////円の当たり判定////
bool Judg_circle(float px_a,float py_a,int r_a,float px_b,float py_b,int r_b)
{
	float xa_b = ((px_a - px_b)*(px_a - px_b));
	float ya_b = ((py_a - py_b)*(py_a - py_b));
	float ra_b = ((r_a + r_b)*(r_a + r_b));
	if (ra_b <= (xa_b + ya_b)) { return true; }
	else { return false; }
}
void acceleration(OBJ* obj, const float max, const float min, const float flametimer = 30);
void acceleration(ENEMY* obj, const float max, const float min, const float flametimer = 30);
////加速度の計算////
void acceleration(OBJ* obj, const float max, const float min,const float flametimer)
{
	float max_min=(max-min);
	if (STATE(0)&PAD_R1&&obj->speed.x < max) { obj->speed.x += max_min / flametimer; }    //Rが押されている間加速
	else if (obj->speed.x >= max_min / 2) { obj->speed.x -= max_min / flametimer; }               //はなされると基準の速度まで落とす
	if (STATE(0)&PAD_L1&&obj->speed.x > min) { obj->speed.x -= max_min / flametimer; }     //押されている間減速
	else if (obj->speed.x <= max_min / 2) { obj->speed.x += max_min / flametimer; }               //はなされると基準の速度まで加速
}
void acceleration(ENEMY* obj, const float max, const float min, const float flametimer)
{
	float max_min = (max - min);
	if (STATE(0)&PAD_R1&&obj->speed.x < max) { obj->speed.x += max_min / flametimer; }    //Rが押されている間加速
	else if (obj->speed.x >= max_min / 2) { obj->speed.x -= max_min / flametimer; }               //はなされると基準の速度まで落とす
	if (STATE(0)&PAD_L1&&obj->speed.x > min) { obj->speed.x -= max_min / flametimer; }     //押されている間減速
	else if (obj->speed.x <= max_min / 2) { obj->speed.x += max_min / flametimer; }               //はなされると基準の速度まで加速
}
