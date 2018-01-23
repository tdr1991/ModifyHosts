/********************************************************************
* 创建日期: 2017/06/11	15:42:15  
* 文件路劲: E:\code\MyProjects\ModifyHosts
* 文 件 名: FileOperate.h
* 作    者:	汤达荣
* 邮    箱: tdr1991@outlook.com
* 版    本: v1.0.0
* 版    权: 
* 描    述:
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