/********************************************************************
* ��������: 2017/06/11	15:40:36  
* �ļ�·��: E:\code\MyProjects\ModifyHosts
* �� �� ��: URLOperate.h
* ��    ��:	������
* ��    ��: tdr1991@outlook.com
* ��    ��: v1.0.0
* ��    Ȩ: 
* ��    ��:
*********************************************************************/

#ifndef URLOperate_h
#define URLOperate_h

#include<iostream>
#include<map>



using namespace std;



namespace unidst
{
	class CURLOperate
	{
	private:
		string purl;
		string fileName;
		string fileAbsolute;

	public:
		CURLOperate();
		CURLOperate(const char *url);
		CURLOperate(const string &url);
		~CURLOperate();
		
	public:
		long DownloadFile(const string &targetDir);
		//long DownloadFile(const string &url, const string &targetDir);
		
		int GetHtmlAttValue(const string &htmlPath, map<string, string> &attValue);

		string GetFileName();
		string GetFileAbsolute();

	public:
		//static long DownloadFile(const string &targetDir);
		static long DownloadFile(const string &url, const string &targetDir);

	};
}

#endif