#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{
	modelRender.Init("Assets/modelData/city/city.tkm");

	Quaternion rot;
	rot.SetRotationDegY(180.0f);
	modelRender.SetRotation(rot);
	modelRender.Update();
	//Hands On 2 PhysicsStaticObject�̏������B
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
	//�����蔻�����������B
	PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
}

BackGround::~BackGround()
{
	
}

void BackGround::Update()
{
	modelRender.Update();
}

void BackGround::Render(RenderContext& renderContext)
{
	modelRender.Draw(renderContext);
}
