#pragma once

class Player;
class GameCamera;


//Game�V�[�����Ǘ�����N���X�B
class Game : public IGameObject
{
public:
	Game();
	~Game();
	//�X�V�����B
	void Update();

	Player* player;			//�v���C���[�B
	GameCamera* gameCamera;			//�Q�[���J�����B
	
};

