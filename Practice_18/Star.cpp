#include "stdafx.h"
#include "Star.h"
#include "Player.h"

Star::Star()
{
	//���̃��f����ǂݍ��ށB
	modelRender.Init("Assets/modelData/star.tkm");

	player = FindGO<Player>("player");
}

Star::~Star()
{

}

void Star::Update()
{
	//�ړ������B
	Move();

	//��]�����B
	Rotation();

	//�G�`������̍X�V�����B
	modelRender.Update();

	//�v���C���[���灙�Ɍ������x�N�g�����v�Z�B
	Vector3 diff = player->position - position;
	//�x�N�g���̒�����120.0f��菬����������B
	if (diff.Length() <= 120.0f)
	{
		player->starCount += 1;

		//���g���폜����B
		DeleteGO(this);
	}
}

void Star::Move()
{
	//moveState��0�̎��B
	if (moveState == 0)
	{
		//��Ɉړ�����B
		position.y += 1.0f;
	}
	//moveState��1�̎��B
	else if (moveState == 1)
	{
		//���Ɉړ�����B
		position.y -= 1.0f;
	}

	//y���W���������Wy+100.0f�𒴂�����B
	if (position.y >= firstPosition.y + 100.0f)
	{
		//moveState��1�ɂ���(���Ɉړ�����悤�ɂ���)�B
		moveState= 1;
	}
	//y���W���������W-100.0f��艺�ɂȂ�����B
	else if (position.y <= firstPosition.y - 100.0f)
	{
		//moveState��0�ɂ���(��Ɉړ�����悤�ɂ���)�B
		moveState = 0;
	}

	//�G�`������ɍ��W��������B
	modelRender.SetPosition(position);
}

//��]�����B
void Star::Rotation()
{
	//��]�����Z����B
	rotation.AddRotationDegY(2.0f);

	//�G�`������ɉ�]��������B
	modelRender.SetRotation(rotation);
}

void Star::Render(RenderContext& rc)
{
	//����`�悷��B
	modelRender.Draw(rc);
}