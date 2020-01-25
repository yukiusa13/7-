#include "./GameLib/game_lib.h"
#include "./GameLib/template.h"
#include "./GameLib/input_manager.h"
#include "./GameLib/obj2d_data.h"


using namespace GameLib;
using namespace input;

////加速度の計算////
float magnification;//倍率
void acceleration(const float max, const float min,const int flametimer)
{
	float max_min=(max-min);
	if (STATE(0)&PAD_R1&&magnification < max) { magnification += max_min / flametimer; }    //Rが押されている間加速
	else if (magnification >= max_min / 2) { magnification -= max_min / flametimer; }       //はなされると基準の速度まで落とす
	if (STATE(0)&PAD_L1&&magnification > min) { magnification -= max_min / flametimer; }    //押されている間減速
	else if (magnification <= max_min / 2) { magnification += max_min / flametimer; }       //はなされると基準の速度まで加速
}

