#ifndef INCLUDED_CAT
#define INCLUDED_CAT

////加速度の計算////
//const float max-> 最高倍率(引数なし->２)
//const float min-> 最低倍率(引数なし->0.5)
//const float flametimer->基準の倍率から最高倍率、最低倍率になるまでの時間(引数なし->30)
void acceleration(const float max=2.0f, const float min=0.5f, const int flametimer=30);
#endif // !INCLUDED_CAR
