#pragma once

#include "Virus.h"

class Patient
{
public:
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