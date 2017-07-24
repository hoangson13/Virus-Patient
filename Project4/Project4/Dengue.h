#pragma once
#include "Virus.h"

class Dengue : public Virus {
public:
	Dengue();
	Dengue(const Dengue &other);
	~Dengue();
	void DoBorn();
	std::list <Virus*> DoClone();
	void InitResistance();
private:
	char m_protein[4];
};