#pragma once
#include <list>
class Virus {
public:
	Virus();
	Virus(char *, int);
	Virus(const Virus &);
	virtual ~Virus();

	void LoadADNInformation();
	bool ReduceResistance(int medicine_resistance);
	int GetResistance();
	void SetResistance(int);

	virtual void DoBorn() = 0;
	virtual std::list <Virus*> DoClone() = 0;
	virtual void InitResistance() = 0;

private:
	const char* m_dna;
	int m_resistance;
};