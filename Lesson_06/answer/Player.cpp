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
}

Player::~Player()
{

}

void Player::Update()
{
	//Hands On 6 �L�����N�^�[�̈ړ����x�����������悤�B
	moveSpeed.x = 0.0f;
	//y�͂����ł́A���������Ȃ��B
	moveSpeed.z = 0.0f;

	//Hands On 9 �L�����N�^�[�𓮂����Ă݂悤�B
	if (playerState == 0) {
		if (g_pad[0]->IsPress(enButtonRight))
		{
			moveSpeed.x = 7.0f;
		}
		if (g_pad[0]->IsPress(enButtonLeft))
		{
			moveSpeed.x = -7.0f;
		}
		if (g_pad[0]->IsPress(enButtonUp))
		{
			moveSpeed.z = 7.0f;
		}
		if (g_pad[0]->IsPress(enButtonDown))
		{
			moveSpeed.z = -7.0f;
		}
		//Hands On 9 �L�����N�^�[���W�����v�����āA�d�͂������悤�B
		//�n�ʂɒ����Ă�����B
		if (characterController.IsOnGround() == true)
		{
			//y�����̑��x��0�ɂ���B
			moveSpeed.y = 0.0f;
			//A�{�^���������ꂽ��B
			if (g_pad[0]->IsTrigger(enButtonA))
			{
				//y�����̈ړ����x���グ��B
				moveSpeed.y = 20.0f;
			}
		}
	}
	//�d�͂͏�ɔ���������B
	moveSpeed.y -= 1.0f;

	//Hands On 7 CharacterController���g���āA�L�����N�^�[���ړ�������B
	position = characterController.Execute(moveSpeed, 1.0f);

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
		//�u/*�v�ŃR�����g�A�E�g����B
		/*if (position.y <= 0.0f)
		{
			//�W�����v�I���
			playerState = 0;
		}*/
		if (characterController.IsOnGround() == true)
		{
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
