#include "stdafx.h"
#include "COMPACT3.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

CCOMPACT3Record::CCOMPACT3Record() 
{
	time=0;
	num=0;
	memset(fvalue, 0, sizeof(fvalue));
	memset(sats, 0, sizeof(sats));
};
CCOMPACT3Record::CCOMPACT3Record(int n) 
{ 
	time = 0;
	num = n; 
	memset(fvalue, 0, sizeof(fvalue));
	memset(sats, 0, sizeof(sats));
};
CCOMPACT3Record::~CCOMPACT3Record() {};
int CCOMPACT3Record::getheader(const CCOMPACT3Record* p)
{
	num = p->num;
	memcpy(sats, p->sats, sizeof(sats));
	return 0;
}

CCOMPACT3::CCOMPACT3()
{
	memset(&m_START_TIME, 0, sizeof(m_START_TIME));
	m_vRecord.clear();
}

CCOMPACT3::~CCOMPACT3()
{
	removeAll();
}

void fdelete(CCOMPACT3Record* pItem)
{
    if (pItem)
    {
        delete pItem;
        pItem = NULL;
    }
}
void CCOMPACT3::removeAll()
{
    for_each(m_vRecord.begin(),m_vRecord.end(),fdelete);
	m_vRecord.clear();
}

ostream& operator <<(ostream &os, const CCOMPACT3Record obj)
{
	os << (obj.time) << " " << (obj.num) << ",";
	for (int i = 0; i < obj.num; ++i)
	{
		os <<obj.sats[i]<< ": " << (obj.fvalue[i])<<" ";
	}

	return os;
}


int CCOMPACT3::loadfile(string pfile)
{
	std::ifstream fin(pfile, std::ios::in);

	char line[512] = { 0 };
	int count = 0;
	CCOMPACT3Record* xRecord = NULL;
	
	while (fin.getline(line, sizeof(line)))
	{
		std::stringstream word(line);
		if (count == 0)
		{
			count++;
			continue;
		}
		if (count == 1)
		{
			//START_TIME 2005  4  2 00 00  0.0000
			char h[50];
			word >> h;
			word >> m_START_TIME.tm_year;
			word >> m_START_TIME.tm_mon;
			word >> m_START_TIME.tm_mday;
			word >> m_START_TIME.tm_hour;
			word >> m_START_TIME.tm_min;
			word >> m_START_TIME.tm_sec;
			//cout << m_START_TIME << endl;
			count++;
			continue;
		}
		if (count % 2 != 0)
		{
			for (int i = 0; i < xRecord->num; ++i)
			{
				word >> (xRecord->fvalue[i]);
			}
			m_vRecord.push_back(xRecord);
		}
		else
		{
			xRecord = new CCOMPACT3Record;
			word >> (xRecord->time);
			int num = 0;
			word >> num;
			if (num != -1)
			{
				xRecord->num = num;
				//num_sat = num;
				for (int i = 0; i < num; ++i)
				{
					word >> xRecord->sats[i];
				}
			}
			else
			{
				int sz = m_vRecord.size();
				xRecord->getheader(m_vRecord.at(sz-1));//
			}
		}
		
		++count;
	}

	fin.clear();
	fin.close();
	return m_vRecord.size();
}
