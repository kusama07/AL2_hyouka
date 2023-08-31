﻿#include "Skydome.h"
#include <cassert>

void Skydome::Initialize(Model* model) {
	assert(model);

	model_ = model;
	worldTransform_.Initialize();
	worldTransform_.scale_ = {200, 200, 200};
}

void Skydome::Update() { worldTransform_.UpdateMatrix(); }

void Skydome::Draw(ViewProjection viewProjection) { model_->Draw(worldTransform_, viewProjection); }
