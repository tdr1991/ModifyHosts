/********************************************************************
* ��������: 2017/06/11	15:44:00  
* �ļ�·��: E:\code\MyProjects\ModifyHosts
* �� �� ��: FileOperate.cpp
* ��    ��:	������
* ��    ��: tdr1991@outlook.com
* ��    ��: v1.0.0
* ��    Ȩ: 
* ��    ��:
*********************************************************************/

#include<fstream>

#include"PubInterfacesTypeDef.h"
#include"path.h"
#include"File.h"
#include"StringUtil.h"
#include"CommonDataSetErrorCodeDefine.h"

#include"FileOperate.h"


using namespace dm_common;
using namespace std;

namespace unidst
{
	CFileOperate::CFileOperate()
	{

	}

	CFileOperate::~CFileOperate()
	{

	}
	void CFileOperate::FindFile(const string &path, const string &fileName, vector<string> &outPath)
	{
		File file(path);
		char buffer[MAX_PATH + 2];
		char *p = buffer;
		const char *src;
		char *end = &buffer[MAX_PATH];
		/* Copy directory name to buffer */
		src = path.c_str();
		while (p < end  &&  *src != '\0') 
		{
			*p++ = *src++;
		}
		*p = '\0';
		/* Open directory stream */
		if (file.IsDirectory()) 
		{
			vector<string> fileList;
			//��ȡĿ¼���ļ��б�
			file.List(fileList);
			/* Print all files and directories within the directory */
			for(auto list:fileList) 
			{
				char *q = p;
				char c;
				/* Get final character of directory name */
				if (buffer < q) 
				{
					c = q[-1];
				} 
				else 
				{
					c = ':';
				}
				/* Append directory separator if not already there */
				/*if (c != ':'  &&  c != '/'  &&  c != '\\') 
				{
					*q++ = '/';
				}*/
				//���ĩβû�д��̷ָ�����·���ָ��������·���ָ���
				char cTemp1 = *CS_DriveDelim;
				if (c != cTemp1  &&  c != CS_PathDelim) 
				{
					*q++ = CS_PathDelim;
				}
				/* Append file name */
				src = list.c_str();
				while (q < end  &&  *src != '\0') 
				{
					*q++ = *src++;
				}
				*q = '\0';
				/* Decide what to do with the directory entry */
				if(File::File(buffer).IsFile())
				/* Output file name with directory */
				{
					//cout<<buffer<<endl;
					if(StringHelper::Compare(Path::GetFileName(buffer), fileName) == 0)
					{
						outPath.push_back(buffer);
						//exit(1);
					}
				}				
				/* Scan sub-directory recursively */
				else if (File::File(buffer).IsDirectory()) 
				{
					FindFile(buffer, fileName, outPath);
				}
			}
		}
		else 
		{
			/* Could not open directory */
			cout<<"Cannot open directory"<<path<<endl;
		}
	}

	void CFileOperate::RemoveFile(const string &strSource, bool recursive)
	{
		File::Remove(strSource, recursive);
	}
	int CFileOperate::CopyFileTo(const string &strSource, const string& strDest)
	{
		ifstream in;
		ofstream out;
		in.open(strSource, ios::binary);
		if (in.fail())
		{
			return Common_Result_Error_FileInvalid;
		}
		out.open(strDest,ios::binary);
		if (out.fail())
		{
			return Common_Result_Error_FileInvalid;
		}		
		out<<in.rdbuf();
		out.close();
		in.close();
		return Common_Result_Success;
	}

	
}