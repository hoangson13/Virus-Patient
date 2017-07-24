#include "Dengue.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Dengue::Dengue() {
	DoBorn();
	InitResistance();
}

Dengue::Dengue(const Dengue &other) :Virus(other) {
	strcpy(m_protein, other.m_protein);
}

Dengue::~Dengue() {}

void Dengue::DoBorn() {
	LoadADNInformation();
	int r = rand() % 3;
	if (r == 0) {
		std::string str = "NS3";
		strcpy(m_protein, str.c_str());
	}
	else if (r == 1) {
		std::string str = "NS5";
		strcpy(m_protein, str.c_str());
	}
	else {
		std::string str = "E";
		strcpy(m_protein, str.c_str());
	}
}

std::list <Virus*> Dengue::DoClone() {
	std::list <Virus*> vlist;
	Virus *n = new Dengue;
	vlist.push_back(n);
	vlist.push_back(n);
	return vlist;
}

void Dengue::InitResistance() {
	if (strcmp("NS3", m_protein) == 0) SetResistance(rand() % 10 + 1);
	else if (strcmp("NS5", m_protein) == 0) SetResistance(rand() % 10 + 11);
	else SetResistance(rand() % 10 + 21);
}