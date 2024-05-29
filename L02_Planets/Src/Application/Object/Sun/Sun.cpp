#include "Sun.h"

void Sun::Init()
{
	m_sp_model = std::make_shared<KdModelData>();
	m_sp_model->Load("Asset/Data/LessonData/Planets/sun.gltf");

	m_rotY = 0;
}

void Sun::Update()
{
	m_rotY += 1.0f;

	if (m_rotY > 360.0f) m_rotY -= 360.0f;

	m_mWorld = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(m_rotY));
}

void Sun::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_sp_model, m_mWorld);
}
