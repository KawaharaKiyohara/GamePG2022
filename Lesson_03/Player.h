#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	void Update();
	void Render(RenderContext& renderContext);
	void Move();
	void Rotation();
	//�������烁���o�ϐ�
	ModelRender modelRender;
	Vector3 position;
	//�N�H�[�^�j�I���B
};

