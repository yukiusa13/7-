#ifndef INCLUDED_COMMON
#define INCLUDED_COMMON

#define SAFE_DELETE(x)  if(x){delete x;x=NULL;}    
#define ToRadian(x)     DirectX::XMConvertToRadians(x) 
#define SCREEN_WIDTH    (1920)   // ��ʂ̕�
#define SCREEN_HEIGHT   (1080)   // ��ʂ̍���
#define SCENE_TITLE     (0)
#define SCENE_GAME      (1)
////�s���\�͈͂̐ݒ�p////
#define area_up    (0)
#define	area_down  (1080)
#define	area_left  (0)
#define	area_right (1920)


////���E/////
#define LEFT  (-1)
#define RIGHT (1)
//�f�o�b�N���[�h�ł̂ݎ��s���邽�߂�
#define debug (1)
void spr_load();//�摜�ǂݍ��݊֐�
//// �X�v���C�g�p ////
enum 
{
	bg = 0,
	number,
	SHOT,
	PLAYER,
	Spr_Max
};
////�~���[�W�b�N�p////
enum 
{
	bgm1 = 0,
	Music_Max
};
////�����蔻��p////
enum
{
	pl_en = 0,
	Flg_Max
};

#endif// ! INCLUDED_COMMON
