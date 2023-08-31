#pragma once
#include "Input.h"
#include "ImGuiManager.h"
#include "Matrix.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

class RailCamera {
public:
	void Initialize(const Vector3& position, const Vector3& rotation);

	void Update();

	const ViewProjection& GetViewProjection() { return viewProjection_; }

	const WorldTransform& GetWorldTransform() { return worldTransform_; }

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// ビュープロジェクション
	ViewProjection viewProjection_;

	Input* input_ = nullptr;
};
