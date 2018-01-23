/********************************************************************
* 创建日期: 2017/06/11	15:44:36  
* 文件路劲: E:\code\MyProjects\ModifyHosts
* 文 件 名: 7zipExeCall.h
* 作    者:	汤达荣
* 邮    箱: tdr1991@outlook.com
* 版    本: v1.0.0
* 版    权: 
* 描    述:
*********************************************************************/

#ifndef _7zipExeCall_h
#define _7zipExeCall_h

#include<iostream>
#include<vector>

using namespace std;

namespace unidst
{

	class C7zipExeCall
	{
	public:
		C7zipExeCall();
		~C7zipExeCall();

	public:
		int ExeCall(const string &operation, const string &filePath, const string &parameters);

	public:
		//解压文件
		static int ExtractsFiles(const string &operation, const string &filePath, const string &arcDir, const string &outDir, const string &password);
		//压缩文件
		static int AchiveFiles(const string &operation, const string &filePath, const string &arcName, const vector<string> arcFiles, const string &password);

	};
}

#endif