﻿#pragma once

class Earth : public KdGameObject
{
public:

	Earth() { Init(); }
	~Earth() override {}

	void Init() override;
	void Update() override;
	void DrawLit() override;

	void SetOwnerObj(std::shared_ptr<KdGameObject> _sp_ownerObj) { m_wp_ownerObj = _sp_ownerObj; }

private:

	std::shared_ptr<KdModelData> m_sp_model = nullptr;

	float m_rotY;
	float m_devY;

	const float m_distance = 10.0f;

	std::weak_ptr<KdGameObject> m_wp_ownerObj;

};