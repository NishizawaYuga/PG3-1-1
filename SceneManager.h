#pragma once

//継承の禁止（finalを付ける）
class SceneManager final{
private:
	//コンストラクタをprivateにする
	SceneManager();
	//デストラクタもprivateにする
	~SceneManager();

public:
	//コピーコンストラクタを無効にする
	SceneManager(const SceneManager& obj) = delete;
	//代入演算子を無効にする
	SceneManager& operator=(const SceneManager& obj) = delete;

	//インスタンスにアクセスする関数
	static SceneManager* GetInstance();

	//シーンを変える関数
	void ChangeScene(int sceneNo);
};
