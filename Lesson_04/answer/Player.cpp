#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	//�A�j���[�V�����N���b�v�����[�h����B
	animationClips[enAnimClip_Idle].Load("Assets/animData/idle.tka");
	animationClips[enAnimClip_Idle].SetLoopFlag(true);
	animationClips[enAnimClip_Walk].Load("Assets/animData/walk.tka");
	animationClips[enAnimClip_Walk].SetLoopFlag(true);
	animationClips[enAnimClip_Jump].Load("Assets/animData/jump.tka");
	animationClips[enAnimClip_Jump].SetLoopFlag(false);
	//���f��������������B
	modelRender.Init("Assets/modelData/unityChan.tkm",animationClips,enAnimClip_Num,enModelUpAxisY);
}

Player::~Player()
{

}

void Player::Update()
{
	//Hands On 3 �X�e�[�g���g���Ă݂悤�B
	//Hands On 1 �����A�j���[�V�������Đ����Ă݂悤�B
	if (playerState == 0) {
		//�Q�[���p�b�h�̏�{�^����������Ă�����B
		if (g_pad[0]->IsPress(enButtonUp))
		{
			//�����A�j���[�V�������Đ�����B
			modelRender.PlayAnimation(enAnimClip_Walk);
		}
		//�Q�[���p�b�h�̉��{�^���������ꂽ��B
		else if (g_pad[0]->IsPress(enButtonDown))
		{
			//�����A�j���[�V�������Đ�����B
			modelRender.PlayAnimation(enAnimClip_Walk);
		}
		//�E�{�^���������ꂽ��B
		else if (g_pad[0]->IsPress(enButtonRight))
		{
			//�����A�j���[�V�������Đ�����B
			modelRender.PlayAnimation(enAnimClip_Walk);
		}
		//���{�^���������ꂽ��B
		else if (g_pad[0]->IsPress(enButtonLeft))
		{
			//�����A�j���[�V�������Đ�����B
			modelRender.PlayAnimation(enAnimClip_Walk);
		}
		//�������͂���Ă��Ȃ���΁B
		else
		{
			//�����A�j���[�V�������Đ�����B
			modelRender.PlayAnimation(enAnimClip_Idle);
		}

		//Hands On 2 �W�����v�A�j���[�V�������Đ����Ă݂悤�B
		//A�{�^���������ꂽ��B
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			//�W�����v�A�j���[�V�������Đ�����B
			modelRender.PlayAnimation(enAnimClip_Jump);
			playerState = 1;
		}
	}
	else if (playerState == 1) 
	{
		if (position.y <= 0.0f) 
		{
			//�W�����v�I���
			playerState = 0;
		}
	}



	//�L�����N�^�[�̈ړ��B
	Move();

	//�L�����N�^�[�̉�]�B
	Rotation();

	//���f�����X�V����B
	modelRender.Update();
}

void Player::Move()
{
	if (g_pad[0]->IsPress(enButtonRight))  //�������Q�[���p�b�h�̉E�{�^���������ꂽ��B
	{                                      //�L�[�{�[�h��6�L�[�B
		position.x += 5.0f;
	}

	if (g_pad[0]->IsPress(enButtonLeft))  //�������Q�[���p�b�h�̍��{�^���������ꂽ��B
	{                                     //�L�[�{�[�h��4�L�[�B
		position.x -= 5.0f;
	}

	if (g_pad[0]->IsPress(enButtonA))    //�������Q�[���p�b�h��A�{�^���������ꂽ��B
	{								     //�L�[�{�[�h��J�L�[�B
		position.y += 5.0f;
	}

	if (g_pad[0]->IsPress(enButtonUp))
	{
		position.z += 5.0f;
	}

	if (g_pad[0]->IsPress(enButtonDown))
	{
		position.z -= 5.0f;
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
	if (g_pad[0]->IsPress(enButtonRight))
	{
		rot.SetRotationDegY(90.0f);
	}

	if (g_pad[0]->IsPress(enButtonLeft))
	{
		rot.SetRotationDegY(-90.0f);
	}

	if (g_pad[0]->IsPress(enButtonUp))
	{
		rot.SetRotationDegY(0.0f);
	}

	if (g_pad[0]->IsPress(enButtonDown))
	{
		rot.SetRotationDegY(180.0f);
	}

	//��]���G�`������ɋ�����B
	modelRender.SetRotation(rot);
}

void Player::Render(RenderContext& renderContext)
{
	//���f����\������B
	modelRender.Draw(renderContext);
}
