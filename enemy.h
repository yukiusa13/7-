#pragma once
#include "Class.h"
#define  ENEMYMAX (32)
struct EnemyData
{
	int type;   // 出現する敵のタイプ
	float time;   // 出現する時間（カウント）
	float x, y; // 敵が出現する位置
};
class ENEMY :
	public OBJ
{
private:
	static const int shot_max = 32;
	OBJ enemyshot[shot_max];//敵の弾の実態
	int enemy_type;
	float enemytimer;//敵出現用タイマー(仮)
public:
	void set_data(int type, float time, float px, float py);//敵のタイプの設定
	void shot_init(float px, float py);//弾の発射時初期化
	void shot_update();//ショットの移動処理など
	void update();//
	void dorw();
};
	void enemy_set(EnemyData* obj,ENEMY ene);



