#pragma once

struct position
{
	float x = 0, y = 0; 
};

class SingleTarget
{
	// Constructor 

public:

	SingleTarget()
	{

	}

	// Deconstructor

	~SingleTarget()
	{

	}

	// Data Members 

protected:

	position m_TargetPos; 

	// Member Functions 

public:

	void m_SetTarget(float targetX, float targetY)
	{
		m_TargetPos.x = targetX;
		m_TargetPos.y = targetY; 

		std::cout << "Position: (" << m_TargetPos.x << ", " << m_TargetPos.y << ")" << std::endl;
	}

	position m_GetTargetPos()
	{
		return m_TargetPos; 
	}
};