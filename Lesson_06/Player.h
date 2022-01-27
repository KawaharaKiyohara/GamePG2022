#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	void Update();
	void Render(RenderContext& renderContext);
	void Rotation();
	//�������烁���o�ϐ�
	enum EnAnimationClip {
		enAnimClip_Idle,
		enAnimClip_Walk,
		enAnimClip_Jump,
		enAnimClip_Num,
	};
	ModelRender modelRender;
	Vector3 position;
	Quaternion rot;
	AnimationClip animationClips[enAnimClip_Num];
	int playerState;
	//Hands On 3 CharacterController�N���X�̃I�u�W�F�N�g���B
	//Player�N���X�ɕێ�������B

	//Hands On 5 �ړ����x��ǉ�����B

};

