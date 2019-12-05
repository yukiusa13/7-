#include "all.h"
using namespace GameLib;
//CAT:“–‚½‚è”»’è
////“–‚½‚è”»’è‘ã“ü—p‚Ì•Ï”////
bool judgflg[Flg_Max];
////‹éŒ`‚Ì“–‚½‚è”»’è////
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
////‰~‚Ì“–‚½‚è”»’è////
bool Judg_circle(float px_a,float py_a,int r_a,float px_b,float py_b,int r_b)
{
	float xa_b = ((px_a - px_b)*(px_a - px_b));
	float ya_b = ((py_a - py_b)*(py_a - py_b));
	float ra_b = ((r_a + r_b)*(r_a + r_b));
	if (ra_b <= (xa_b + ya_b)) { return true; }
	else { return false; }
}


