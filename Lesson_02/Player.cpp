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
	//Hands On 1 �L�����N�^�[�����E�ɓ������Ă݂悤�B

	//Hands On 2 �L�����N�^�[�𕡐����Ă݂悤�B
	
	//Hands On 3 �L�����N�^�[���W�����v�����Ă݂悤�B
	
	//���K�ۑ� 1 �Q�[���p�b�h�̏�{�^���������ꂽ�牜�ɁB
	//���{�^���������ꂽ���O�ɃL�����N�^�[�������悤�ɂ��悤�B
	//��{�^����enButtonUp�A���{�^����enButtonDown�ł��B
	
	//Hands On 4 �d�͂������Ă݂悤�B

	//Hands On 5 �L�����N�^�[��y���W�𐧌����Ă݂悤�B


	//���W���G�`������ɋ�����B
	modelRender.SetPosition(position);

	//���f�����X�V����B
	modelRender.Update();
}

void Player::Render(RenderContext& renderContext)
{
	//���f����\������B
	modelRender.Draw(renderContext);
}
