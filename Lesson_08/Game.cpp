#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "BackGround.h"
#include "GameCamera.h"
#include "Star.h"

//Hands On 3 SoundEngine�̋@�\���g�������̂ŁB
//�w�b�_�[�t�@�C�����C���N���[�h����B


Game::Game()
{
	NewGO<BackGround>(0);
	auto player = NewGO<Player>(0);
	auto gameCamera = NewGO<GameCamera>(0);
	gameCamera->player = player;

	Star* star = NewGO<Star>(0);

	//Hands On 4 SoundEngine���g���āAwave�t�@�C��(.wav)��ǂݍ��ށB

	//Hands On 5 BGM���Đ����Ă݂悤�B
	
}

Game::~Game()
{

}

void Game::Update()
{

}