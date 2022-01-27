#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "BackGround.h"
#include "GameCamera.h"
#include "Star.h"

//Hands On 3 SoundEngine�̋@�\���g�������̂ŁB
//�w�b�_�[�t�@�C�����C���N���[�h����B
#include "sound/SoundEngine.h"

Game::Game()
{
	NewGO<BackGround>(0);
	auto player = NewGO<Player>(0);
	auto gameCamera = NewGO<GameCamera>(0);
	gameCamera->player = player;

	Star* star = NewGO<Star>(0);

	//Hands On 4 SoundEngine���g���āAwave�t�@�C��(.wav)��ǂݍ��ށB
	//0�͓ǂݍ���wav�t�@�C���̂����ԍ��B
	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/shining_star.wav");

	//Hands On 5 BGM���Đ����Ă݂悤�B
	//SoundSouce�̃I�u�W�F�N�g���쐬����B
	bgm = NewGO<SoundSource>(0);
	//WaveFileBank����o�^���ꂽwave�t�@�C���̃f�[�^�������Ă���B
	bgm->Init(0);
	//true�ɂ���ƁA�������[�v����B
	bgm->Play(true);
}

Game::~Game()
{

}

void Game::Update()
{

}