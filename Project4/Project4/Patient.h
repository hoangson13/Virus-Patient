#pragma once

#include "Virus.h"

class Patient
{
public:
	static const int DEATH = 0;
	static const int ALIVE = 1;
	Patient();
	~Patient() {};
	void InitResistance();
	void DoStart();
	void TakeMedicine(char);
	void DoDie();
	int GetState();
	bool GetHealthy();
private:
	std::list <Virus*> m_virusList;
	int m_resistance;
	int m_state;
};