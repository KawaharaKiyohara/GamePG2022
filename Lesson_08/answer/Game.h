#pragma once

//Hands On 1 SoundSource���g�������̂Ńt�@�C�����C���N���[�h����B
#include "sound/SoundSource.h"

class Player;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();

	Player* player;
	//Hands On 2 SoundSource��ǉ����悤�B
	SoundSource* bgm;
};
