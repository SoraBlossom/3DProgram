#pragma once

class Sun : public KdGameObject
{
public:

	Sun() { Init(); }
	~Sun() override {}

	void Init() override;
	void Update() override;
	void DrawLit() override;

private:

	std::shared_ptr<KdModelData> m_sp_model = nullptr;

	float m_rotY;

};