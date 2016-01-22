#include "casetime.h"

CaseTime::CaseTime():_caseNo(-1), _startTime(""),
	_timeout(0), _stopTime("")
{
}

void CaseTime::setCaseNo(int caseNo)
{
	_caseNo = caseNo;
}

void CaseTime::setStartTime(std::string startTime)
{
	_startTime = startTime;
}

void CaseTime::setTimeout(int timeout)
{
	_timeout = timeout;
}

void CaseTime::setStopTime(std::string stopTime)
{
	if ("" != stopTime)
	{
		_stopTime = stopTime;
	}
	else 
	{
		if (_timeout > 0)
		{
			int hour = _timeout / 3600;
			int mleft = _timeout % 3600;
			int minute = mleft / 60;
			int second = mleft % 60;
			vector<int> vTime;
			StringUtil::stringToVector(_startTime, ":", vTime);
			if (vTime.size() == 3)
			{
				vTime[0] = vTime[0] + hour;
				vTime[1] = vTime[1] + minute;
				vTime[2] = vTime[2] + second;
				_stopTime = StringUtil::intToStr(vTime[0]) + ":" + StringUtil::intToStr(vTime[1])
					+ ":" + StringUtil::intToStr(vTime[2]);
			}
		}
		else
		{
			_stopTime = _startTime;
		}
	}
}

void CaseTime::show()
{
	std::string timeStr = StringUtil::intToStr(_caseNo) + "," + _startTime + "," + _stopTime;
	output.open("../cfg/casetime.csv", std::ios::app);
	output << timeStr << std::endl;
	output.close();
}