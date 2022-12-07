#pragma once

#include "../Math/MathUtils.h" 
#include "../Object/Scene.h"

class Ray;

class Camera
{
public:
	Camera(const glm::vec3& eye, const glm::vec3& target, const glm::vec3& up, float fov, float aspectRation);

	void LookAt(const glm::vec3& eye, const glm::vec3& target, const glm::vec3& up);
	Ray PointToRay(const glm::vec2& point) const;

private:
	void CalculateViewPlane();

private:
	// eye position 
	glm::vec3 m_eye{ 0, 0, 0 };

	glm::vec3 m_right{ 0, 0, 0 };
	glm::vec3 m_up{ 0, 0, 0 };
	glm::vec3 m_forward{ 0, 0, 0 };

	glm::vec3 m_lowerLeft{ 0, 0, 0 };
	glm::vec3 m_horizontal{ 0, 0, 0 };
	glm::vec3 m_vertical{ 0, 0, 0 };


	float m_fov{ 0 }; 
	float m_aspectRatio{ 0 }; 
};