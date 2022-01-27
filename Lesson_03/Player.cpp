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

	Rotation();

	//Hands On 3 �L�����N�^�[����]���������悤�B

	//�L�����N�^�[�̈ړ��B
	Move();

	//���f�����X�V����B
	modelRender.Update();
}

void Player::Move()
{
	if (g_pad[0]->IsPress(enButtonRight))  //�������Q�[���p�b�h�̉E�{�^���������ꂽ��B
	{                                      //�L�[�{�[�h��6�L�[�B
		position.x += 10.0f;
	}

	if (g_pad[0]->IsPress(enButtonLeft))  //�������Q�[���p�b�h�̍��{�^���������ꂽ��B
	{                                     //�L�[�{�[�h��4�L�[�B
		position.x -= 10.0f;
	}

	if (g_pad[0]->IsPress(enButtonA))    //�������Q�[���p�b�h��A�{�^���������ꂽ��B
	{								     //�L�[�{�[�h��J�L�[�B
		position.y += 5.0f;
	}

	if (g_pad[0]->IsPress(enButtonUp))
	{
		position.z += 10.0f;
	}

	if (g_pad[0]->IsPress(enButtonDown))
	{
		position.z -= 10.0f;
	}

	position.y -= 0.5f;
	if (position.y <= 0.0f)
	{
		position.y = 0.0f;
	}

	//���W���G�`������ɋ�����B
	modelRender.SetPosition(position);
}

void Player::Rotation()
{
	//Hands On 1 �L�����N�^�[���E�Ɍ������Ă݂悤�B

	//Question 1 �L�����N�^�[�����Ɍ������Ă݂悤�B

	//Question 2 �L�����N�^�[�����Ɍ������Ă݂悤�B

	//Question 3 �L�����N�^�[����O�Ɍ������Ă݂悤�B

	//Hands On 2 �L�����N�^�[���E�Ɍ������悤�B

	//Question 4 �p�b�h�̍��{�^���������ꂽ��A�L�����N�^�[�����������悤�ɂ��Ă݂悤�B

	//Question 5 �p�b�h�̏�{�^���������ꂽ��A�L�����N�^�[�����������悤�ɂ��Ă݂悤�B

	//Question 6 �p�b�h�̉��{�^���������ꂽ��A�L�����N�^�[�����������悤�ɂ��Ă݂悤�B

	//��]���G�`������ɋ�����B
}

void Player::Render(RenderContext& renderContext)
{
	//���f����\������B
	modelRender.Draw(renderContext);
}
