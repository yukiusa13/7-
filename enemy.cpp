#include "all.h"


ENEMY ememy[ENEMYMAX];//ENEMYクラスの実体
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
			//ダメージ処理とか書く

			enemyshot[i].exist = false;
		}

	}
}

void ENEMY::set_data(int type, float time, float px, float py)
{
	enemy_type = type;
	enemytimer = time;
	pos.x = px;
	pos.y = py;
	for (int i = 0; i < shot_max; i++)
	{
		enemyshot[i].exist = false;//弾の初期化全ての存在を消す
	}
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



void ENEMY::update()
{
	switch (enemy_type)
	{
	case 0:enemy0_move();
		break;
	case 1:enemy1_move();
		break;
	case 2:enemy2_move();
		break;
	}
}

void ENEMY::dorw()
{
	if (ENEMY::exist)//存在しているものだけ描画
		{

		}

}
//これが実際に使う方の初期化
void enemy_set(EnemyData* obj, ENEMY* ene)
{
	ene->set_data(obj->type, obj->time, obj->x, obj->y);
}

////タイプごとの行動////
void ENEMY::enemy0_move()
{

}

void ENEMY::enemy1_move()
{

}

void ENEMY::enemy2_move()
{

}
