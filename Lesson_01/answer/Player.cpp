#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	//���f��������������B
	modelRender.Init("Assets/modelData/unityChan.tkm");
}

Player::~Player()
{

}

void Player::Update()
{
	//Hands On 2 �v���C���[�𓮂����Ă݂悤�B
	position.x = position.x + 1.0f;

	//���K�ۑ� 1 �v���C���[�����ɓ������Ă݂悤�B
	position.z = position.z + 1.0f;

	//Hands On 3 ���W���G�`������ɋ�����B
	modelRender.SetPosition(position);

	//���f�����X�V����B
	modelRender.Update();
}

void Player::Render(RenderContext& renderContext)
{
	//���f����\������B
	modelRender.Draw(renderContext);
}
