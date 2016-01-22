#pragma once
#ifndef _CASE_TIME_H_
#define _CASE_TIME_H_
#include <fstream>
#include "../utility/stringutil.h"

class CaseTime
{
public:
	CaseTime();
	void setCaseNo(int caseNo);
	void setTimeout(int timeout);
	void setStartTime(std::string startTime);
	void setStopTime(std::string stopTime);
	void show();  ///��ʽ��д���ļ�
private:
	int _caseNo;
	std::string _startTime;
	std::string _stopTime;
	int _timeout;  ///��startTime��stopTime��ʱ����λ����
	std::ofstream output;
};

#endif