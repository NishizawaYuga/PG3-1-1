#pragma once

//�p���̋֎~�ifinal��t����j
class SceneManager final{
private:
	//�R���X�g���N�^��private�ɂ���
	SceneManager();
	//�f�X�g���N�^��private�ɂ���
	~SceneManager();

public:
	//�R�s�[�R���X�g���N�^�𖳌��ɂ���
	SceneManager(const SceneManager& obj) = delete;
	//������Z�q�𖳌��ɂ���
	SceneManager& operator=(const SceneManager& obj) = delete;

	//�C���X�^���X�ɃA�N�Z�X����֐�
	static SceneManager* GetInstance();

	//�V�[����ς���֐�
	void ChangeScene(int sceneNo);
};
