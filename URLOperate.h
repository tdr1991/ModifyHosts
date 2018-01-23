/********************************************************************
* 创建日期: 2017/06/11	15:40:36  
* 文件路劲: E:\code\MyProjects\ModifyHosts
* 文 件 名: URLOperate.h
* 作    者:	汤达荣
* 邮    箱: tdr1991@outlook.com
* 版    本: v1.0.0
* 版    权: 
* 描    述:
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