#include "stdafx.h"
#include "GameCamera.h"
#include "Player.h"

GameCamera::GameCamera()
{
	g_camera3D->SetNear(250.0f);
	g_camera3D->SetFar(900.0f);
}

GameCamera::~GameCamera()
{

}

void GameCamera::Update()
{
	//Hands On 1 �����_��ݒ肷��B
	Vector3 target;
	//�����_���v���C���[�̍��W�ɐݒ肷��B
	target.x = player->position.x;
	//y���W�������グ��B
	target.y = player->position.y + 100.0f;
	target.z = player->position.z;
	//�J�����̒����_��ύX����B
	g_camera3D->SetTarget(target);

	//Hands On 2 ���_��ݒ肷��B
	Vector3 cameraPos;
	cameraPos = target;
	//z�𒍎��_����-300�̈ʒu�ɂ���B
	cameraPos.z -= 300.0f;
	//�J�����̎��_��ύX����B
	g_camera3D->SetPosition(cameraPos);

	//Hands On 3 �ߕ��ʂ�ݒ肷��B
	g_camera3D->SetFar(5000.0f);

	//Hands On 4 �����ʂ�ݒ肷��B
	g_camera3D->SetNear(1.0f);

	//Hands On 5 ��p��ύX����B
	//�J�����̉�p�������Ă���B
	float angle = g_camera3D->GetViewAngle();
	//X�{�^���������ꂽ��B
	if (g_pad[0]->IsPress(enButtonX))
	{
		//��p�����Z����B
		angle += 0.05f;
	}
	if (g_pad[0]->IsPress(enButtonY))
	{
		//��p�����Z����B
		angle -= 0.05f;
	}
	g_camera3D->SetViewAngle(angle);
}


