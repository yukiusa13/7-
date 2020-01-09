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
	int enemy_type=-1;//敵のタイプ　初期値はマイナス　
	float enemytimer;//敵出現用タイマー(仮)
public:
	
	void set_data(int type, float time, float px, float py);//敵のデータの設定
	void shot_init(float px, float py);//弾の発射時初期化
	void shot_update();//ショットの移動処理など
	void update();//更新処理
	void dorw();//描画処理
	void enemy0_move();//敵タイプ０の行動
	void enemy1_move();//敵タイプ１の行動
	void enemy2_move();//敵タイプ２の行動
};
////エネミーの初期化////
//エネミーのデータの構造体の実体
//エネミーの実体
	void enemy_set(EnemyData* obj,ENEMY ene);
////加速度の計算////
//速度を変えるOBJの実体
//最高速度
//最低速度
//基準の速度から最高速度、最低速度までの時間引数なしは0.5秒
	void acceleration(ENEMY* obj, const float max, const float min, const float flametimer = 30);


