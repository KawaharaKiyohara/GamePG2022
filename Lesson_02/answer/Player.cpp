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
	if (g_pad[0]->IsPress(enButtonRight))  //�������Q�[���p�b�h�̉E�{�^���������ꂽ��B
	{                                      //�L�[�{�[�h��6�L�[�B
		position.x += 10.0f;
	}

	if (g_pad[0]->IsPress(enButtonLeft))  //�������Q�[���p�b�h�̍��{�^���������ꂽ��B
	{                                     //�L�[�{�[�h��4�L�[�B
		position.x -= 10.0f;
	}

	//Hands On 2 �L�����N�^�[�𕡐����Ă݂悤�B
	if (g_pad[0]->IsPress(enButtonSelect)) //�������Q�[���p�b�h��A�{�^���������ꂽ��B
	{                                      //�L�[�{�[�h�̃X�y�[�X�L�[�B
		NewGO<Player>(0);
	}

	//Hands On 3 �L�����N�^�[���W�����v�����Ă݂悤�B
	if (g_pad[0]->IsPress(enButtonA))    //�������Q�[���p�b�h��A�{�^���������ꂽ��B
	{								     //�L�[�{�[�h��J�L�[�B
		position.y += 5.0f;
	}

	//���K�ۑ� 1 �Q�[���p�b�h�̏�{�^���������ꂽ�牜�ɁB
	//���{�^���������ꂽ���O�ɃL�����N�^�[�������悤�ɂ��悤�B
	if (g_pad[0]->IsPress(enButtonUp))
	{
		position.z += 10.0f;
	}

	if (g_pad[0]->IsPress(enButtonDown))
	{
		position.z -= 10.0f;
	}

	//Hands On 4 �d�͂������Ă݂悤�B
	position.y -= 0.5f;

	//Hands On 5 �L�����N�^�[��y���W�𐧌����Ă݂悤�B
	if (position.y <= 0.0f)
	{
		position.y = 0.0f;
	}

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
