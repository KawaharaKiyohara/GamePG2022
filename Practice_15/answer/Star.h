#pragma once

//���N���X�B
class Star : public IGameObject
{
public:
	Star();
	~Star();
	//�X�V�����B
	void Update();
	//�`�揈���B
	void Render(RenderContext& rc);
	//�ړ������B
	void Move();

	//�����o�ϐ��B
	ModelRender modelRender;	//���f�������_�\�B
	Vector3 position;		//���W�B
	int moveState;		//��Ɉړ������Ɉړ����B
	Vector3 firstPosition;		//�ŏ��̍��W�B
};

