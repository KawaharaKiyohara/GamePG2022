#pragma once

//Hands On 1 SoundSourceを使いたいのでファイルをインクルードする。
#include "sound/SoundSource.h"

class Player;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();

	Player* player;
	//Hands On 2 SoundSourceを追加しよう。
	SoundSource* bgm;
};

