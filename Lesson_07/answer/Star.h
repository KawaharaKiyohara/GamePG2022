#pragma once
class Player;
class Star : public IGameObject
{
public:
	Star();
	~Star();
	void Update();
	void Render(RenderContext& renderContext);
	ModelRender modelRender;
	//�������烁���o�ϐ��B
	//���W�B
	Vector3 position;
	//��]�B
	Quaternion rot;
	int moveCount = 0;
	Player* player;
};

