/********************************************************************
* ��������: 2017/06/11	15:42:15  
* �ļ�·��: E:\code\MyProjects\ModifyHosts
* �� �� ��: FileOperate.h
* ��    ��:	������
* ��    ��: tdr1991@outlook.com
* ��    ��: v1.0.0
* ��    Ȩ: 
* ��    ��:
*********************************************************************/

#ifndef FileOperate_h
#define FileOperate_h

#include<iostream>
#include<vector>

using namespace std;

namespace unidst
{
	class CFileOperate
	{
	public:
		CFileOperate();
		~CFileOperate();

	public:
		static void FindFile(const string &path, const string &fileName, vector<string> &outPath);
		static void RemoveFile(const string &strSource, bool recursive = false);
		static int CopyFileTo(const string &strSource, const string& strDest);

	};
}


#endif