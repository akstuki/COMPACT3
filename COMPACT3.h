#pragma once
#include <string>
#include <vector>

enum {
    e_Max_Count = 30, /* Max count of satellites in one epoch */
};

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
	float fvalue[e_Max_Count];
	char sats[e_Max_Count][4];

private:

};

class CCOMPACT3
{
public:
	CCOMPACT3();
	virtual ~CCOMPACT3();
public:
	int loadfile(std::string pfile);
	const CCOMPACT3Record* get(int i) const;
	int count() const;
	void removeAll();

private:
	std::vector<CCOMPACT3Record*> m_vRecord;
	tm m_START_TIME;
};

inline int CCOMPACT3::count() const
{
	return m_vRecord.size();
}
inline const CCOMPACT3Record* CCOMPACT3::get(int i) const
{
	return (i < count() ? m_vRecord.at(i) : NULL);
}
