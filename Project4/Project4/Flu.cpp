#include"Flu.h"

Flu::Flu() {
	DoBorn();
	InitResistance();
}

Flu::Flu(const Flu &other) : Virus(other), m_color(other.m_color) {}

Flu::~Flu() {}

void Flu::DoBorn() {
	LoadADNInformation();
	int r = rand() % 2;
	if (r == 0) m_color = BLUE;
	else m_color = RED;
}

std::list <Virus*> Flu::DoClone() {
	std::list <Virus*> vlist;
	vlist.push_back(new Flu(*this));
	return vlist;
}

void Flu::InitResistance() {
	if (m_color == BLUE) SetResistance(rand() % 11 + 10);
	else SetResistance(rand() % 6 + 10);
}
