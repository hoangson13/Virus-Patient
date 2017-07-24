#pragma once
#include "Virus.h"

class Flu : public Virus {
public:
	static const int BLUE = 0x0000ff;
	static const int RED = 0xff0000;
	Flu();
	Flu(const Flu &other);
	~Flu();
	void DoBorn();
	std::list <Virus*> DoClone();
	void InitResistance();
private:
	int m_color;
};