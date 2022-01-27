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

}

Player::~Player()
{

}

void Player::Update()
{
	//Hands On 6 �L�����N�^�[�̈ړ����x�����������悤�B
	
	//Hands On 8 �L�����N�^�[�𓮂����Ă݂悤�B

		//Hands On 9 �L�����N�^�[���W�����v�����āA�d�͂������悤�B

	//Hands On 7 CharacterController���g���āA�L�����N�^�[���ړ�������B


	//���W���G�`������ɋ�����B
	modelRender.SetPosition(position);

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
	else if (playerState == 1)
	{
		//Hands On 10 �X�e�[�g��n�ʂɒ��n������ύX����悤�ɂ��Ă݂悤�B
		if (position.y <= 0.0f)
		{
			//�W�����v�I���
			playerState = 0;
		}
	}

	//�L�����N�^�[�̉�]�B
	Rotation();

	//���f�����X�V����B
	modelRender.Update();
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
