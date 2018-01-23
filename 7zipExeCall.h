/********************************************************************
* ��������: 2017/06/11	15:44:36  
* �ļ�·��: E:\code\MyProjects\ModifyHosts
* �� �� ��: 7zipExeCall.h
* ��    ��:	������
* ��    ��: tdr1991@outlook.com
* ��    ��: v1.0.0
* ��    Ȩ: 
* ��    ��:
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
		//��ѹ�ļ�
		static int ExtractsFiles(const string &operation, const string &filePath, const string &arcDir, const string &outDir, const string &password);
		//ѹ���ļ�
		static int AchiveFiles(const string &operation, const string &filePath, const string &arcName, const vector<string> arcFiles, const string &password);

	};
}

#endif