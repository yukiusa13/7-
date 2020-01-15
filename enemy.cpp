#include "all.h"
using namespace GameLib;

extern OBJ stage[2];
ENEMY enemy[ENEMYMAX];//ENEMYクラスの実体
extern float magnification;
EnemyData enemy_data[]//敵情報
{
	//{敵のタイプ,敵の出現場所,初期X座標,初期Y座標},




	
	{-1,-1,-1,-1}//終了
};
#if debug
EnemyData enemy_test[]//敵情報
{
	//{敵のタイプ,敵の出現場所,初期X座標,初期Y座標},
	{10,0   ,1920/2,-2 },
	{10,1000,1920/2,-3 },
	{10,2000,1920/2,-4 },
	{10,3000,1920/2,-5 },
	{10,4000,1920/2,-6 },
	{10,5000,1920/2,-7 },
	{10,6000,1920/2,-8 },
	{10,7000,1920/2,-9 },
	{10,8000,1920/2,-10},
	{-1,-1  ,-1     ,-1}//終了
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
#if debug
	case 10:
		enemy_test();
		break;
#endif
	}
}

//描画処理
void ENEMY::dorw()
{
	if (ENEMY::exist)//存在しているものだけ描画
	{
#if debug
		//当たり判定確認用のプリミティブ(円)の描画//
		primitive::circle(pos.x,pos.y, 50, 1, 0, 0, 1);
#endif
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
		enemy_app -= stage[0].speed.y*magnification;
		if (enemy_app <= 0)
		{
			exist = true;
			set_state(next);
		}
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
		enemy_app -= stage[0].speed.y*magnification;
		if (enemy_app <= 0)
		{
			exist = true;
			set_state(next);
		}
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
		enemy_app -= stage[0].speed.y*magnification;
		if (enemy_app <= 0)
		{
			exist = true;
			set_state(next);
		}
		break;
	case 1:

		break;
	}
}

#if debug
void ENEMY::enemy_test()
{
	next = get_state() + 1;
	switch (get_state())
	{
	case 0:
		speed = { 0,5 };
		enemy_app -= stage[0].speed.y*magnification;
		if (enemy_app <= 0)
		{
			exist = true;
		    set_state(next);
		}
		break;
	case 1:
		pos += speed* magnification;

		break;
	case 2:
		break;
	}
}
#endif
void enemy_init()
{
#if debug
	for (int i = 0;ENEMYMAX;i++)
	{
		if (enemy_test[i].app==-1) {break;}//終了フラグで終わる
		enemy_set(&enemy_test[i], &enemy[i]);
	}
#endif
#if 0
	switch (ステージ番号)
	{
	case 0:
		for (int i = 0;; i++)
		{
			if (enemy_test[i].app==-1) { break; }//終了フラグで終わる
			enemy_set(&enemy_test[i], &ememy[i]);
		}
		break;
	}
#endif // 0

}
extern OBJ player;
extern OBJ shot[shotmax];
extern OBJ missile[missilemax];
void enemy_update()
{
#if debug
	for (int i = 0; ENEMYMAX; i++)
	{
		if (enemy_test[i].app==-1) { break; }//終了フラグで終わる
		for(int j=0;j<shotmax;j++)//プレイヤーの弾との当たり判定
		{
			jugde_flg[pls_en] = judge.circle(shot[j].pos.x, shot[j].pos.y, 50, enemy[i].pos.x, enemy[i].pos.y, 50);
			if (jugde_flg[pls_en]&&shot[j].exist&&enemy[i].exist)
			{
				shot[j].exist = false;
				enemy[i].exist = false;
			}
		}
		for (int j = 0; j < missilemax; j++)
		{
			jugde_flg[pls_en] = judge.circle(missile[j].pos.x, missile[j].pos.y, 50, enemy[i].pos.x, enemy[i].pos.y, 50);
			if (jugde_flg[pls_en] && missile[j].exist&&enemy[i].exist)
			{
				missile[j].exist = false;
				enemy[i].exist = false;
			}
		}
	   jugde_flg[pl_en]= judge.circle(player.pos.x, player.pos.y, 50,enemy[i].pos.x,enemy[i].pos.y,50);
		enemy[i].update();
		if(jugde_flg[pl_en])
		{
			enemy[i].exist = false;
		}
	}
#endif
#if 0
		switch (ステージ番号)
		{
		case 0:
			for (int i = 0;; i++)
			{
				if (enemy_data[i].app==-1) { break; }//終了フラグで終わる
				enemy[i].update();
			}
			break;
		}
#endif // 0


}
void enemy_draw()
{
#if debug
	for (int i = 0; ENEMYMAX; i++)
	{
		if (enemy_test[i].app == -1) { break; }
		enemy[i].dorw();
	}
#endif // debug

}