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
	

	//���K�ۑ� 1 �v���C���[�����ɓ������Ă݂悤�B


	//Hands On 3 ���W���G�`������ɋ�����B


	//���f�����X�V����B
	modelRender.Update();
}

void Player::Render(RenderContext& renderContext)
{
	//���f����\������B
	modelRender.Draw(renderContext);
}
