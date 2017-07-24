#include"Virus.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Virus::Virus(): m_dna(nullptr),m_resistance(0){}
Virus::~Virus(){}

Virus::Virus(char*dna,int resistance) : m_dna(strcpy(new char[strlen(dna)+1],dna)),m_resistance(resistance){}
Virus::Virus(const Virus &other) :m_dna(strcpy(new char[strlen(other.m_dna) + 1], other.m_dna)), m_resistance(other.m_resistance) {}

void Virus::LoadADNInformation() {
	string line;
	ifstream myfile("ATGX.txt");
	if (myfile.is_open())
	{
		getline(myfile, line);
		m_dna = line.c_str();
		myfile.close();
	}

	else cout << "Unable to open file";
}

bool Virus::ReduceResistance(int medicine_resistance) {
	m_resistance -= medicine_resistance;
	return m_resistance <= 0;
}

int Virus::GetResistance() {
	return m_resistance;
}

void Virus::SetResistance(int m) {
	m_resistance = m;
}
