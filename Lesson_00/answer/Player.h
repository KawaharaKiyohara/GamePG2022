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
};

