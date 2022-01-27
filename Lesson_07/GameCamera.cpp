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
	Vector3 target;
	//�����_���v���C���[�̍��W�ɐݒ肷��B
	target.x = player->position.x;
	//y���W�������グ��B
	target.y = player->position.y + 100.0f;
	target.z = player->position.z;
	//�J�����̒����_��ύX����B
	g_camera3D->SetTarget(target);

	Vector3 cameraPos;
	cameraPos = target;
	//z�𒍎��_����-300�̈ʒu�ɂ���B
	cameraPos.z -= 300.0f;
	//�J�����̎��_��ύX����B
	g_camera3D->SetPosition(cameraPos);

	g_camera3D->SetFar(5000.0f);

	g_camera3D->SetNear(1.0f);
}


