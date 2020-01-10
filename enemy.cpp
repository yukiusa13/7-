#include "all.h"

extern OBJ stage;
ENEMY ememy[ENEMYMAX];//ENEMYクラスの実体
EnemyData enemy_data[]//敵情報
{
	//{敵のタイプ,敵の出現場所,初期X座標,初期Y座標},




	
	{-1,-1,-1,-1}//終了
};
#if 1
EnemyData enemy_test[]//敵情報
{
	//{敵のタイプ,敵の出現場所,初期X座標,初期Y座標},
	{10,1000,100,-200},
	{10,1100,100,-300},
	{10,1200,100,-400},
	{10,1300,100,-500},
	{10,1400,100,-600},
	{10,1500,100,-700},
	{10,1600,100,-800},
	{10,1700,100,-900},
	{10,1800,100,-1000},
	{-1,-1,-1,-1}//終了
};
#endif
//弾の発射時初期化
void ENEMY::shot_init(float px,float py)
{
	for(int i=0;i<shot_max;i++)
	{
		if (!enemyshot[i].exist)
		{
			//弾の発射地点の設定
			enemyshot[i].pos = { px,py };
			enemyshot[i].exist = true;
			break;
	    }
	}
}

//ショットの移動処理など

void ENEMY::shot_update()
{
	for (int i = 0; i <shot_max; i++)
	{
		//出現場所まで来たら存在フラグを立てる
		if (enemy_app >= stage.pos.y)
		{
			exist = true;
		}
		//ここに移動処理などをを書く








		if (0)//当たり判定
		{
			//ダメージ処理とか書く

			enemyshot[i].exist = false;
		}

	}
}

//敵のデータの設定
void ENEMY::set_data(int type,float app,float px, float py)
{
	enemy_type = type;
	enemy_app = app;
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


//更新処理
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

//描画処理
void ENEMY::dorw()
{
	if (ENEMY::exist)//存在しているものだけ描画
	{

	}

}
//これが実際に使う方の初期化
void enemy_set(EnemyData* obj, ENEMY* ene)
{
	ene->set_data(obj->type, obj->app,obj->x, obj->y);
}


////タイプごとの行動////
void ENEMY::enemy0_move()
{
	switch (get_state())
	{
	case 0:

		break;
	case 1:

		break;
	}
}

void ENEMY::enemy1_move()
{
	switch (get_state())
	{
	case 0:

		break;
	case 1:

		break;
	}
}

void ENEMY::enemy2_move()
{
	switch (get_state())
	{
	case 0:

		break;
	case 1:

		break;
	}
}
