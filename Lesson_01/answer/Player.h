#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	void Update();
	void Render(RenderContext& renderContext);
	//�������烁���o�ϐ�
	ModelRender modelRender;
	//Hands On 1 ���W�f�[�^��ǉ�����B
	Vector3 position;
};

