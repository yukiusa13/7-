#ifndef INCLUDED_OBJ2D
#define INCLUDED_OBJ2D

//��`�̓����蔻��
//float px_a,float py_a ->�����蔻����s��2�̃I�u�W�F�N�g��1�ڂ̍���̍��W(X,Y)
//int sx_a,int sy_a ->�����蔻����s��2�̃I�u�W�F�N�g��1�ڂ̉��Əc�̒���(X,Y)
//float px_a,float py_a ->�����蔻����s��2�̃I�u�W�F�N�g��2�ڂ̍���̍��W(X,Y)
//int sx_a,int sy_a ->�����蔻����s��2�̃I�u�W�F�N�g��2�ڂ̉��Əc�̒���(X,Y)
bool Judg_rect(float px_a, float py_a, int sx_a, int sy_a,
	    float px_b, float py_b, int sx_b, int sy_b);
//�~�̓����蔻��
//float px_a,folat py_a->�����蔻����s��2�̃I�u�W�F�N�g��1�ڂ̒��S���W(X,Y)
//int r_a-> �����蔻����s��2�̃I�u�W�F�N�g��1�ڂ̔��a
//float px_b,folat py_b->�����蔻����s��2�̃I�u�W�F�N�g��2�ڂ̒��S���W(X,Y)
//int r_b-> �����蔻����s��2�̃I�u�W�F�N�g��2�ڂ̔��a
bool Judg_circle(float px_a, float py_a, int r_a, float px_b, float py_b, int r_b);


#endif // !INCLUDED_OBJ2D
