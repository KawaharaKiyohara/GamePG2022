#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	//�A�j���[�V�����N���b�v�����[�h����B
	animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	//���j�e�B�����̃��f����ǂݍ��ށB
	modelRender.Init("Assets/modelData/unityChan.tkm", animationClips, enAnimationClip_Num, enModelUpAxisY);

}

Player::~Player()
{

}

//�X�V�����B
void Player::Update()
{

	//�G�`������̍X�V�����B
	modelRender.Update();
}

//�`�揈���B
void Player::Render(RenderContext& rc)
{
	//���j�e�B������`�悷��B
	modelRender.Draw(rc);
}