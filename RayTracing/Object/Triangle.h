#pragma once
#include "Object.h"
#include "../Math/Ray.h"

// https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm
class Triangle : public Object
{
public:
	Triangle(const glm::vec3& v1, const glm::vec3& v2, const glm::vec3& v3, std::unique_ptr<Material> material) :
		Object{ std::move(material) },
		m_v1{ v1 },
		m_v2{ v2 },
		m_v3{ v3 }
	{
	}

	bool Hit(const Ray& ray, float minDistance, float maxDistance, RaycastHit& hit) override;

private:
	glm::vec3 m_v1{ 0, 0, 0 };
	glm::vec3 m_v2{ 0, 0, 0 };
	glm::vec3 m_v3{ 0, 0, 0 };
};