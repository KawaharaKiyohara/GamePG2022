#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "BackGround.h"
#include "GameCamera.h"
#include "Star.h"


#include "sound/SoundEngine.h"

Game::Game()
{
	NewGO<BackGround>(0);
	auto player = NewGO<Player>(0);
	auto gameCamera = NewGO<GameCamera>(0);
	gameCamera->player = player;

	Star* star = NewGO<Star>(0);
	
	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/shining_star.wav");

	bgm = NewGO<SoundSource>(0);
	//WaveFileBank����o�^���ꂽwave�t�@�C���̃f�[�^�������Ă���B
	bgm->Init(0);
	//true�ɂ���ƁA�������[�v����B
	bgm->Play(true);

	//Hands On 3 �摜��ǂݍ��ށB
	
	
	//Hands On 9 �\�����镶����ݒ肵�悤�B
	
}

Game::~Game()
{
	

}

void Game::Update()
{
	//Hands On 6 �摜�����ɓ������Ă݂悤�B
	

	//Hands On 7 �摜���c�ɓ������Ă݂悤�B
	

	//���K�ۑ�1 �摜������ɕ\�����Ă݂悤�B
	

	//�G�`������ɍ��W��������B


	//Hands On 4 �摜�̍X�V�����B
	
}

//Hands On 5 Render�֐���ǉ�����B
