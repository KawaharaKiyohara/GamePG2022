#pragma once

//�v���C���[�N���X�B
class Player : public IGameObject
{
public:
	Player();
	~Player();
	//�X�V�����B
	void Update();
	//�`�揈���B
	void Render(RenderContext& rc);

	//�����o�ϐ��B
	ModelRender modelRender;	//���f�������_�\�B
	Vector3 position;			//���W�B
	enum EnAnimationClip {		//�A�j���[�V�����B
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Num,
	};
	AnimationClip animationClips[enAnimationClip_Num];		//�A�j���[�V�����N���b�v�B
};
