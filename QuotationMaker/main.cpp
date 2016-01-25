#include "cases.h"

HANDLE  g_hEvent = NULL; //�¼��ź�

HANDLE g_hFile;  //�첽д����־

DWORD g_dwWritenSize = 0;

void main()
{
	while (true)
	{
		system("linux2win.bat");
		fstream file;
		file.open("start.txt");
		if (file) 
		{
			///�ļ��Ѿ�����,ɾ��
			file.close();			
			remove("start.txt");
			break;
		}
	}
	std::ofstream output("../cfg/casetime.csv", std::ios::out);
	output << "caseno, starttime, stoptime" << std::endl;
	output.close();
	g_hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	g_hFile = CreateFile(TEXT("../cfg/trading_log.txt"), 
		GENERIC_WRITE, 
		FILE_SHARE_READ, 
		NULL, 
		OPEN_ALWAYS,  //�ļ�������򿪣����������½�
		FILE_ATTRIBUTE_NORMAL, 
		NULL);
	SetFilePointer(g_hFile, 0, NULL, FILE_END);  //ָ���ļ�ĩβ
	Cases *cases = new Cases();
	cases->run();
	FlushFileBuffers(g_hFile);
	CloseHandle(g_hEvent);
	CloseHandle(g_hFile);
	system("win2linux.bat");
	system("pause");
}
