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
	modelRender.Update();

	//Hands On 4 CharacterController�N���X�̃I�u�W�F�N�g������������B
	characterController.Init(25.0f, 75.0f, position);

	SetName("Player");
}

Player::~Player()
{

}

void Player::Update()
{
	
	//�L�����N�^�[�̈ړ��B
	Move();

	//�L�����N�^�[�̉�]�B
	Rotation();

	//�L�����N�^�[�̃A�j���[�V�����B
	Animation();

	//���f�����X�V����B
	modelRender.Update();
}

void Player::Move()
{
	moveSpeed.x = 0.0f;
	//y�͂����ł́A���������Ȃ��B
	moveSpeed.z = 0.0f;

	if (playerState == 0) {
		if (g_pad[0]->IsPress(enButtonRight))
		{
			moveSpeed.x = 4.0f;
		}
		if (g_pad[0]->IsPress(enButtonLeft))
		{
			moveSpeed.x = -4.0f;
		}
		if (g_pad[0]->IsPress(enButtonUp))
		{
			moveSpeed.z = 4.0f;
		}
		if (g_pad[0]->IsPress(enButtonDown))
		{
			moveSpeed.z = -4.0f;
		}
		//�n�ʂɒ����Ă�����B
		if (characterController.IsOnGround() == true)
		{
			//y�����̑��x��0�ɂ���B
			moveSpeed.y = 0.0f;
			//A�{�^���������ꂽ��B
			if (g_pad[0]->IsTrigger(enButtonA))
			{
				//y�����̈ړ����x���グ��B
				moveSpeed.y = 18.0f;
			}
		}
	}
	//�d�͂͏�ɔ���������B
	moveSpeed.y -= 0.4f;

	position = characterController.Execute(moveSpeed, 1.0f);

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

void Player::Animation()
{
	if (playerState == 0) {
		//A�{�^���������ꂽ��B
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			//�W�����v�A�j���[�V�������Đ�����B
			modelRender.PlayAnimation(enAnimClip_Jump);
			playerState = 1;
		}
		//�Q�[���p�b�h�̏�{�^����������Ă�����B
		else if (g_pad[0]->IsPress(enButtonUp))
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
	}
	//�W�����v����������B
	else if (playerState == 1)
	{
		//�n�ʂɒ��n������B
		if (characterController.IsOnGround() == true)
		{
			//�X�e�[�g��0�ɂ���(�W�����v���ł͂Ȃ�)�B
			playerState = 0;
		}
	}
}

void Player::Render(RenderContext& renderContext)
{
	//���f����\������B
	modelRender.Draw(renderContext);
}
