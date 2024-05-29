#include "Earth.h"

void Earth::Init()
{
	m_sp_model = std::make_shared<KdModelData>();
	m_sp_model->Load("Asset/Data/LessonData/Planets/earth.gltf");

	m_rotY = 0;
	m_devY = 0;
}

void Earth::Update()
{
	m_rotY -= 0.5f;
	if (m_devY < 0.0f) m_devY -= 360.0f;

	m_devY -= 0.5f;
	if (m_devY < 0.0f) m_devY += 360.0f;

	m_mWorld = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(m_rotY)) *
		Math::Matrix::CreateTranslation(m_distance, 0, 0) *
		Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(m_devY));

	if (!m_wp_ownerObj.expired()) m_mWorld *= Math::Matrix::CreateTranslation(m_wp_ownerObj.lock()->GetPos());
}

void Earth::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_sp_model, m_mWorld);
}
