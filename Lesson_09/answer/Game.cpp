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
	spriteRender.Init("Assets/sprite/unitychan.dds", 512.0f, 512.0f);
	
	//Hands On 9 �\�����镶����ݒ肵�悤�B
	//������ݒ肷��B
	fontRender.SetText(L"Hellow World!");
	//�\��������W��ݒ肷��B
	fontRender.SetPosition({-600.0f,100.0f,0.0f});
	//�\������F��ݒ肷��B
	fontRender.SetColor(g_vec4White);
}

Game::~Game()
{
	

}

void Game::Update()
{
	//Hands On 6 �摜�����ɓ������Ă݂悤�B
	//X�{�^���������ꂽ��B
	if (g_pad[0]->IsPress(enButtonX))
	{
		//�摜���E�Ɉړ�������B
		position.x += 1.0f;
	}
	//Y�{�^���������ꂽ��B
	if (g_pad[0]->IsPress(enButtonY))
	{
		//�摜�����Ɉړ�������B
		position.x -= 1.0f;
	}

	//Hands On 7 �摜���c�ɓ������Ă݂悤�B
	//A�{�^���������ꂽ��B
	if (g_pad[0]->IsPress(enButtonA))
	{
		//�摜����Ɉړ�������B
		position.y += 1.0f;
	}
	//B�{�^���������ꂽ��B
	if (g_pad[0]->IsPress(enButtonB))
	{
		//�摜�����Ɉړ�������B
		position.y -= 1.0f;
	}

	//���K�ۑ�1 �摜������ɕ\�����Ă݂悤�B
	position.x = -640.0f;
	position.y = 360.0f;

	//�G�`������ɍ��W��������B
	spriteRender.SetPosition(position);

	//Hands On 4 �摜�̍X�V�����B
	spriteRender.Update();
}

//Hands On 5 Render�֐���ǉ�����B
void Game::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
	fontRender.Draw(rc);
}