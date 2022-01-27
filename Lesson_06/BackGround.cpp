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

	//�����蔻�����������B

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
