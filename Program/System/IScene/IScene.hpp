#pragma once
#include <string>

class IScene
{
public:

	virtual ~IScene() = default;

	// そのシーンに入った瞬間（タイトル画面表示、ステータス初期化等）
	virtual void Initialize() = 0;

	//　ループ毎に呼ばれる（入力待ち、コマンド処理等）
	virtual void Update() = 0;

	//そのシーンを抜ける瞬間（後始末、結果表示、フラグリセット等）
	virtual void Finalize() = 0;

	//　デバッグ用
	virtual std::string GetName() const = 0;
};