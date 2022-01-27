#include "stdafx.h"
#include "Star.h"
#include "Player.h"

//Hands On 6 SoundEngine��SoundSource�̋@�\���g�������̂ŁB
//�w�b�_�[�t�@�C�����C���N���[�h����B


Star::Star()
{
	//TODO ���f���������ւ���B
	modelRender.Init("Assets/modelData/star.tkm");
	//���f����ǂݍ��ށB
	//�v���C���[�̃I�u�W�F�N�g�����������Ă���B
	player = FindGO<Player>("Player");

	//Hands On 7 ���ʉ���wave�t�@�C����ǂݍ��ށB
	
}

Star::~Star()
{

}

void Star::Update()
{
	//��]�����Z����B
	rot.AddRotationY(0.01f);
	//�G�`������ɉ�]��������B
	modelRender.SetRotation(rot);

	//moveCount��0�̎��B
	if (moveCount == 0)
	{
		//��Ɉړ�����B
		position.y += 1.0f;
	}
	//moveCount��1�̎��B
	else if (moveCount == 1)
	{
		//���Ɉړ�����B
		position.y -= 1.0f;
	}

	//y���W��100.0f�𒴂�����B
	if (position.y >= 100.0f)
	{
		//moveCount��1�ɂ���(���Ɉړ�����悤�ɂ���)�B
		moveCount = 1;
	}
	//y���W��-100.0f��艺�ɂȂ�����B
	else if (position.y <= -100.0f)
	{
		//moveCount��0�ɂ���(��Ɉړ�����悤�ɂ���)�B
		moveCount = 0;
	}
	//�G�`������ɍ��W��������B
	modelRender.SetPosition(position);

	//�G�`������̍X�V�����B
	modelRender.Update();

	//�v���C���[���灙�Ɍ������x�N�g�������߂�B
	Vector3 diff = position - player->position;
	//�v���C���[�Ɓ��̋�����70.0f��菬����������B
	if (diff.Length() <= 70.0f)
	{
		//Hands On 8 ���ʉ����Đ����悤�B
	

		//���g(��)���폜����B
		DeleteGO(this);
	}
}

void Star::Render(RenderContext& renderContext)
{
	//����`�悷��B
	modelRender.Draw(renderContext);
}