#pragma once
#include "Class.h"
#define  ENEMYMAX (32)
struct EnemyData
{
	int type;   // 出現する敵のタイプ
	float app;  // 敵の出現場所
	float x, y; // 敵が出現する位置
};
class ENEMY :
	public OBJ
{
private:
	static const int shot_max = 32;
	OBJ enemyshot[shot_max];//敵の弾の実態
	int enemy_type=-1;//敵のタイプ　初期値はマイナス　
	float enemy_app;//敵の出現場所
public:
	
	void set_data(int type,float app, float px, float py);//敵のデータの設定
	void shot_init(float px, float py);//弾の発射時初期化
	void shot_update();//ショットの移動処理など
	void update();//更新処理
	void dorw();//描画処理
	void enemy0_move();//敵タイプ０の行動
	void enemy1_move();//敵タイプ１の行動
	void enemy2_move();//敵タイプ２の行動
#if debug
	void enemy_test();
#endif
};
////エネミーの初期化////
//エネミーのデータの構造体の実体
//エネミーの実体
	void enemy_set(EnemyData* obj,ENEMY ene);
	void enemy_init();//game_init書くやつ
	void enemy_update();//game_update書くやつ
	void enemy_draw();//game_draw書くやつ


#if 0
	//出現場所まで来たら存在フラグを立てる
	switch (fade)
	{
	case 0:
		enemy_app -= stage[0].speed.y;
		if (enemy_app <= 0)
		{
			exist = true;
			fade++;
		}
		break;
	case 1:
		//ここに移動処理などをを書く

		break;
	}
#endif // 0
