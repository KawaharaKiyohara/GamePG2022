#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "GameCamera.h"

Game::Game()
{
	//�v���C���[�̃I�u�W�F�N�g�����B
	player = NewGO<Player>(0, "player");

	//�Q�[���J�����̃I�u�W�F�N�g�����B
	gameCamera = NewGO<GameCamera>(0, "gamecamera");

}

Game::~Game()
{
	
}

//�X�V�����B
void Game::Update()
{
	
}