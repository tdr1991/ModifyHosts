/********************************************************************
* 创建日期: 2017/06/11	15:44:28  
* 文件路劲: E:\code\MyProjects\ModifyHosts
* 文 件 名: 7zipExeCall.cpp
* 作    者:	汤达荣
* 邮    箱: tdr1991@outlook.com
* 版    本: v1.0.0
* 版    权: 
* 描    述:
*********************************************************************/

#include<windows.h>
#include<shellapi.h>

#include"path.h"
#include"Environment.h"
#include"CommonDataSetErrorCodeDefine.h"

#include"7zipExeCall.h"

using namespace dm_common;

namespace unidst
{
	C7zipExeCall::C7zipExeCall()
	{

	}
	C7zipExeCall::~C7zipExeCall()
	{

	}	
	int C7zipExeCall::ExeCall(const string &operation, const string &filePath, const string &parameters)
	{
		if(filePath.length() > 0)
		{
			return (int)ShellExecute(NULL, operation.c_str(), filePath.c_str(), parameters.c_str(), NULL, SW_SHOW);
		}
		else
		{
			return Common_Result_Error_FileInvalid;
		}
	}
	int C7zipExeCall::ExtractsFiles(const string &operation, const string &filePath, const string &arcDir, const string &outDir, const string &password)
	{
		if(arcDir.length() > 0)
		{
			string parameters = "";
			parameters += " x ";
			parameters += arcDir;
			if(outDir.length() > 0)
			{
				parameters += " -o";
				parameters += outDir;
			}
			if(password.length() > 0)
			{
				parameters += " -p";
				parameters += password;
			}
			string exePath = filePath;
			if (! Path(exePath).IsFile())
			{
				exePath = GetCurrentModuleDir() + "7z.exe";

			}
			C7zipExeCall ec;
			return ec.ExeCall(operation, exePath, parameters);
		}
		else
		{
			return Common_Result_Error_FileInvalid;
		}
	}
	int C7zipExeCall::AchiveFiles(const string &operation, const string &filePath, const string &arcName, const vector<string> arcFiles, const string &password)
	{
		if((arcFiles.size() > 0) && (arcName.length() > 0))
		{
			string parameters = "";
			parameters += " a ";
			parameters += arcName;
			if(password.length() > 0)
			{
				parameters += " -p";
				parameters += password;
			}
			for(auto file:arcFiles) 
			{
				parameters += " ";
				parameters += file;
			}
			
			C7zipExeCall ec;
			return ec.ExeCall(operation, filePath, parameters);
		}
		else
		{
			return Common_Result_Error_FileInvalid;
		}
	}
}