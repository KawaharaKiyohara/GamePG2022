#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "BackGround.h"
#include "GameCamera.h"
//Hands On 1 Star�N���X�̋@�\���g�������̂ŁA�w�b�_�[�t�@�C�����C���N���[�h����B

Game::Game()
{
	NewGO<BackGround>(0);
	auto player = NewGO<Player>(0);
	auto gameCamera = NewGO<GameCamera>(0);
	gameCamera->player = player;

	//Hands On 2 Star�N���X�̃I�u�W�F�N�g���쐬�B

}

Game::~Game()
{

}

void Game::Update()
{

}