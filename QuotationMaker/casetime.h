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
	void show();  ///格式化写入文件
private:
	int _caseNo;
	std::string _startTime;
	std::string _stopTime;
	int _timeout;  ///从startTime到stopTime的时间差，单位：秒
	std::ofstream output;
};

#endif