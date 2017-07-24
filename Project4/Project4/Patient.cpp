#include "Patient.h"
#include "Flu.h"
#include "Dengue.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Patient::Patient() {
	int totalV=0;
	DoStart();
	InitResistance();
	std::cout << "Patient resistance " << m_resistance << std::endl;
	for (auto& i : m_virusList) {
		totalV += i->GetResistance();
	}
	std::cout << "Total virus current resistance " << totalV << std::endl;
	std::cout << "Total number virus " << m_virusList.size() << std::endl;
	std::cout << "==================================" << std::endl;
	m_state = ALIVE;
}

void Patient::DoStart() {

	int n = rand() % 11 + 10;
	for (int i = 0; i < n; i++)
		m_virusList.push_back(rand() % 2 ? (Virus*)new Flu : new Dengue);
}

void Patient::TakeMedicine(char medicine_take) {
	int totalV = 0;
	bool isActive = 1;
	std::list<Virus*> delVirus;
/*
	std::list<Virus*>::iterator i = m_virusList.begin();
	while (i != m_virusList.end())
	{
		if (medicine_take == '1') isActive = (*i)->ReduceResistance(rand() % 60 + 1);
		if (!isActive)
		{
			i = m_virusList.erase(i);
		}
		else
		{
			std::list <Virus*> nlist = (*i)->DoClone();
			for (auto& j : nlist) {
				m_virusList.push_front(j);
			}
			i++;
		}
	}

*/
	for (auto i : m_virusList) {
		if (medicine_take == '1') isActive = i->ReduceResistance(rand() % 60 + 1);
		if (!isActive)
		{
			delVirus.push_back(i);
		}
		else
		{
			std::list <Virus*> nlist = i->DoClone();
			for (auto j : nlist) {
				m_virusList.push_front(j);
			}
		}
	}

	for (auto i : delVirus) {
		m_virusList.remove(i);
	}

	for (auto& i : m_virusList) {
		if(i->GetResistance()>0) totalV += i->GetResistance();
	}
	if (totalV >= m_resistance) DoDie();

	std::cout << "==================================" << std::endl;
}

int Patient::GetState() {
	return m_state;
}

bool Patient::GetHealthy()
{
	int totalV=0;
	for (auto& i : m_virusList) {
		if (i->GetResistance()>0) totalV += i->GetResistance();
	}
	return totalV==0;
}

void Patient::DoDie() {
	m_virusList.clear();
	m_state = DEATH;
}

void Patient::InitResistance() {
	m_resistance = rand() % 8001 + 1000;
}