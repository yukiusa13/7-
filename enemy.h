#pragma once
#include "Class.h"
class ENEMY :
	public OBJ
{
private:
	static const int shot_max = 32;
	OBJ enemyshot[shot_max];//敵の弾の実態
	int enemy_type;
	float enemytimer;//敵出現用タイマー(仮)
	void set_type(int type);//敵のタイプの設定
	void init(float time, float px, float py);//出現時間、初期位置の設定
public:

	void shot_init(float px, float py);//弾の発射時初期化
	void shot_update();//ショットの移動処理など
	void update();//
	void dorw();
	void set_data();
};



