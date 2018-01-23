/********************************************************************
* ��������: 2017/06/11	15:42:03  
* �ļ�·��: E:\code\MyProjects\ModifyHosts
* �� �� ��: URLOperate.cpp
* ��    ��:	������
* ��    ��: tdr1991@outlook.com
* ��    ��: v1.0.0
* ��    Ȩ: 
* ��    ��:
*********************************************************************/

#include<regex>
#include <UrlMon.h>
#pragma comment(lib, "urlmon.lib")
#include <tchar.h>

#include"path.h"
#include"BinaryStream.h"
#include"str_commfun.h"
#include"StringUtil.h"
#include"CommonDataSetErrorCodeDefine.h"
#include"Environment.h"


#include"URLOperate.h"


using namespace unidst;
using namespace dm_common;

namespace unidst
{
	CURLOperate::CURLOperate()
	{
		purl = "";
		fileName = "";
		fileAbsolute = "";
	}
	CURLOperate::CURLOperate(const char *url)
	{
		purl = url;
	}
	CURLOperate::CURLOperate(const string &url)
	{
		purl = url;
	}
	CURLOperate::~CURLOperate()
	{

	}
	long CURLOperate::DownloadFile(const string &targetDir)
	{
		if(purl.length() > 0)
		{		
			fileAbsolute = targetDir;
			if (! Path(fileAbsolute).IsDirectory())
			{
				fileAbsolute = GetCurrentModuleDir();
			}
			fileName = Path::GetFileName(purl);				
			fileAbsolute += fileName;
			return URLDownloadToFile(NULL, purl.c_str(), fileAbsolute.c_str(), NULL, NULL);
		}
		else
		{
			return ModifyHosts_Result_Error_Not_Give_URL;
		}
	}
	long CURLOperate::DownloadFile(const string &url, const string &targetDir)
	{
		//CURLOperate(url);
		CURLOperate op(url);
		return op.DownloadFile(targetDir);
	}

	int CURLOperate::GetHtmlAttValue(const string &htmlPath, map<string, string> &attValue)
	{
		BinaryReader reader;
		string fileContent;
		string htmlRoute = htmlPath;
		if (! Path(htmlPath).IsFile())
		{
			htmlRoute = fileAbsolute;
		}
		if (reader.Open(htmlRoute))
		{
			int fileSize = (int)reader.GetSize();
			if (fileSize > 0)
			{
				fileContent.resize(fileSize);
				char* buffer = &fileContent[0];
				size_t iRealReadSize;
				reader.Read((unsigned char*)buffer, fileSize, &iRealReadSize );
			}
			reader.Close();
		}
		else
		{
			return Common_Result_Error_FileInvalid;
		}
		std::string urlPatt("http(s)?://([\\w-]+\\.)+[\\w-]+(/[\\w- ./?%&=]*)?");
		urlPatt = "[[:alpha:]]*" + urlPatt + "[[:alpha:]]*";
		std::regex urlRg(urlPatt);
		for (std::sregex_iterator it(fileContent.begin(), fileContent.end(), urlRg), end; it != end; ++it)    //end��β���������regex_iterator��regex_iterator��string���͵İ汾			
		{
			if(regex_match(it->str(), regex("http://www.22ba.com/uploadfile/2017/.*")))
			{
				attValue.insert(make_pair("fileUrl", it->str()));
				break;
			}
		}
		string gbkToutf = "";
		string split1 = "";
		string split2 = "";
		StringHelper::AnsiToUtf8("��ѹ����", gbkToutf);
		StringHelper::AnsiToUtf8("��", split1);
		StringHelper::AnsiToUtf8("��", split2);	
		std::string enPatt(gbkToutf + ".*" + split2);
		std::regex enRg(enPatt);
		for (std::sregex_iterator it(fileContent.begin(), fileContent.end(), enRg), end; it != end; ++it)   //end��β���������regex_iterator��regex_iterator��string���͵İ汾		
		{	
			vector<string> str1;
			vector<string> str2;
			CStr_CommFun::StrSplit(it->str(), split1.c_str(), str1);
			CStr_CommFun::StrSplit(str1[1], split2.c_str(), str2);
			string utfTogbk = "";
			StringHelper::UTF8ToAnsi(str2[0], utfTogbk);
			attValue.insert(make_pair("encrypt", utfTogbk));
			break;
		}
		return Common_Result_Success;
	}
	string CURLOperate::GetFileName()
	{
		return fileName;
	}

	string CURLOperate::GetFileAbsolute()
	{
		return fileAbsolute;
	}
}