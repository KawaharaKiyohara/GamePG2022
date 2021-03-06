#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{
	modelRender.Init("Assets/modelData/city/city.tkm");

	Quaternion rot;
	rot.SetRotationDegY(180.0f);
	modelRender.SetRotation(rot);
	modelRender.Update();
	//Hands On 2 PhysicsStaticObjectの初期化。
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
	//当たり判定を可視化する。
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
