#pragma once
#include <string>
#include <vector>

#define MAX_COUNT 30

class CCOMPACT3Record
{
public:
	CCOMPACT3Record();
	CCOMPACT3Record(int n);
	~CCOMPACT3Record();
public:
	friend std::ostream& operator<<(std::ostream& os, const CCOMPACT3Record obj);
	int getheader(const CCOMPACT3Record* p);

public:
	double time;
	int num;
	float fvalue[MAX_COUNT];
	char sats[MAX_COUNT][4];

private:

};

class CCOMPACT3
{
public:
	CCOMPACT3();
	virtual ~CCOMPACT3();
public:
	int loadfile(std::string pfile);
	const CCOMPACT3Record* get(int i);
	int count();
	void removeAll();

private:
	std::vector<CCOMPACT3Record*> m_vRecord;
	tm m_START_TIME;
};

