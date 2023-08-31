#include "RailCamera.h"

void RailCamera::Initialize(const Vector3& position, const Vector3& rotation) {
	// ワールドトランスフォームの初期設定
	worldTransform_.translation_ = position;

	worldTransform_.rotation_ = rotation;

	worldTransform_.scale_ = {1.0f, 1.0f, 1.0f};

	viewProjection_.Initialize();

	input_ = Input::GetInstance();
}

void RailCamera::Update() {
	worldTransform_.translation_.z += 0.03f;

	if (input_->PushKey(DIK_Q)) {
		worldTransform_.rotation_.x = 3.0f;
		worldTransform_.rotation_.z = 3.13f;

	} else {
		worldTransform_.rotation_.x = 0.0f;
		worldTransform_.rotation_.z = 0.0f;
	}

	worldTransform_.matWorld_ = MakeAffineMatrix(
	    {1.0f, 1.0f, 1.0f}, worldTransform_.rotation_, worldTransform_.translation_);

	viewProjection_.matView = Inverse(worldTransform_.matWorld_);

}
