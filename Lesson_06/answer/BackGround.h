#pragma once
class BackGround : public IGameObject
{
public:
	BackGround();
	~BackGround();
	void Update();
	void Render(RenderContext& renderContext);
	ModelRender modelRender;
	//Hands On 1 �ÓI�����I�u�W�F�N�g(PhysicsStaticObject)�B
	//��ێ�������B
	PhysicsStaticObject physicsStaticObject;
};

