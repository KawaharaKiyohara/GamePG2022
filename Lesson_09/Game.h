#pragma once
#include "sound/SoundSource.h"

class Player;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();
	//Hands On 1 Render�֐���ǉ�����B

	//�������烁���o�ϐ��B
	Player* player;
	SoundSource* bgm;
	//Hands On 2 SpriteRender�ƍ��W��ǉ�����B

	//Hands On 8 FontRender��ǉ�����B
	
};

