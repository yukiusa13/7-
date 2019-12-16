#include "all.h"

struct EnemyData
{
	int type;   // 出現する敵のタイプ
	float time;   // 出現する時間（カウント）
	float x, y; // 敵が出現する位置
};
EnemyData enemy_data[]//敵情報
{
	//{敵のタイプ,敵の出現時間,初期X座標,初期Y座標},





	{-1,-1,-1,-1}//終了
};






















void ENEMY::shot_init(float px,float py)
{
	for(int i=0;i<shot_max;i++)
	{
		if (!enemyshot[i].exist)
		{
			enemyshot[i].pos = { px,py };
			enemyshot[i].exist = true;
			break;
	    }
	}
}

void ENEMY::shot_update()
{
	for (int i = 0; i <shot_max; i++)
	{
		//ここに移動処理などをを書く









		if (0)//当たり判定
		{
			enemyshot[i].exist = false;
		}

	}
}

void ENEMY::set_type(int type)
{
	enemy_type = type;
#if 0//タイプ別でHPなどを設定するならこっちも使う
	switch (type)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	}
#endif
}

void ENEMY::init(float time,float px,float py)
{
	enemytimer = time;
	pos.x = px;
	pos.y = py;
	for (int i = 0; i < shot_max; i++)
	{
		enemyshot[i].exist = false;//弾の初期化全ての存在を消す
	}
}

void ENEMY::update()
{

}

void ENEMY::dorw()
{

}
//これが実際に使う方の初期化
void ENEMY::set_data()
{
	for (int i = 0;; i++) {
		if (enemy_data[i].type == -1) { break; }
		set_type(enemy_data[i].type);
		init(enemy_data[i].time, enemy_data[i].x,enemy_data[i].y);

	}
}
