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
	//���f�����X�V����B
	modelRender.Update();
}

void Player::Render(RenderContext& renderContext)
{
	//���f����\������B
	modelRender.Draw(renderContext);
}
