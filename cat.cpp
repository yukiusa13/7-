#include "./GameLib/game_lib.h"
#include "./GameLib/template.h"
#include "./GameLib/input_manager.h"
#include "./GameLib/obj2d_data.h"


using namespace GameLib;
using namespace input;

////�����x�̌v�Z////
float magnification;//�{��
void acceleration(const float max, const float min,const int flametimer)
{
	float max_min=(max-min);
	if (STATE(0)&PAD_R1&&magnification < max) { magnification += max_min / flametimer; }    //R��������Ă���ԉ���
	else if (magnification >= max_min / 2) { magnification -= max_min / flametimer; }       //�͂Ȃ����Ɗ�̑��x�܂ŗ��Ƃ�
	if (STATE(0)&PAD_L1&&magnification > min) { magnification -= max_min / flametimer; }    //������Ă���Ԍ���
	else if (magnification <= max_min / 2) { magnification += max_min / flametimer; }       //�͂Ȃ����Ɗ�̑��x�܂ŉ���
}

