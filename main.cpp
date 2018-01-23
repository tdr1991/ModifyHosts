/********************************************************************
* 创建日期: 2017/06/11	15:44:12  
* 文件路劲: E:\code\MyProjects\ModifyHosts
* 文 件 名: main.cpp
* 作    者:	汤达荣
* 邮    箱: tdr1991@outlook.com
* 版    本: v1.0.0
* 版    权: 
* 描    述:
*********************************************************************/

#include<iostream>
#include<regex>
#include<fstream>

#include"PubInterfacesTypeDef.h"
#include"path.h"
#include"File.h"
#include"StringUtil.h"
#include"str_commfun.h"

#include"7zipExeCall.h"
#include"FileOperate.h"
#include"URLOperate.h"

using namespace std;
using namespace dm_common;
using namespace unidst;



int main(int argc,char *argv[])
{
	//解压文件，直接调用7zip程序解压
	//HINSTANCE hNewExe = ShellExecute(NULL, "open", "e:\\test7zip\\7z.exe", "x e:\\20161229040152801.rar  -pwww.22ba.com -oe:\\20161229040152801", NULL, SW_SHOW);
	//下载文件
	//URLDownloadToFile(NULL, _T("http://www.22ba.com/uploadfile/2016/1229/20161229040152801.rar"), _T("e:\\20161229040152801.rar"), NULL, NULL);	
	//CURLOperate::DownloadFile("http://www.22ba.com/article/Share867.html", "");

	string url = "http://www.22ba.com/article/Share947.html";
	//string url = "http://cyber.sci-hub.cc/MTAuMTAzOC9ucmcxMTI0/jobling2003.pdf";
	CURLOperate op(url);
	op.DownloadFile(" ");
	
	
	map<string, string> value; //   dl.xml
	op.GetHtmlAttValue("", value);

	string htmlFile = op.GetFileAbsolute();

	CURLOperate opFile(value["fileUrl"]);
	opFile.DownloadFile(" ");
	string comFileAbs = opFile.GetFileAbsolute();
	string name = Path(comFileAbs).GetFileName();
	string bname = Path(comFileAbs).GetBaseName();
	string ext = Path(comFileAbs).GetExtension();
	


	vector<string> spFile;
	CStr_CommFun::StrSplit(comFileAbs, '.', spFile);
	

	C7zipExeCall::ExtractsFiles("open",  "", comFileAbs, spFile[0], value["encrypt"]);
	//C7zipExeCall::ExtractsFiles("open",  "", "E:\\code\\CProjects\\bin\\Debug\\windows\\20161229040152801.rar", "E:\\code\\CProjects\\bin\\Debug\\windows\\20161229040152801", "www.22ba.com");

	vector<string> outPath;
	//CFileOperate cf;
	//cf.FindFile(spFile[0], "hosts", outPath);
	//需要给一个解压时间，要不然无法进行下面的查找文件操作
	Sleep(2000);

	CFileOperate::FindFile(spFile[0], "hosts", outPath);

	//CFileOperate::FindFile("E:\\code\\CProjects\\bin\\Debug\\windows\\20161229040152801", "hosts", outPath);
	string strDest = "C:\\Windows\\System32\\drivers\\etc\\";
	strDest += Path(outPath[0]).GetFileName();
	

	CFileOperate::CopyFileTo(outPath[0], strDest);

	CFileOperate::RemoveFile(htmlFile);
	CFileOperate::RemoveFile(comFileAbs, true);
	CFileOperate::RemoveFile(spFile[0], true);

	
	//vector<string> arcFiles;
	//arcFiles.push_back("E:\\test7zip\\f1.txt");
	//arcFiles.push_back("E:\\test7zip\\f2.txt");
	
	//C7zipExeCall::AchiveFiles("open",  "e:\\test7zip\\7z.exe", "E:\\test7zip\\test.7z", arcFiles, "mypw");
	
	//vector<string> outPath;
	//CFileOperate::FindFile("e:\\20161229040152801", "hosts", outPath);

	/*for(auto list:outPath) 
	{
		cout<<list<<endl;
	}*/
	//CFileOperate::RemoveFile("E:\\20161229040152801\\f4.txt", true);
	
	 //CFileOperate::CopyFileTo("E:\\20161229040152801\\GoGo Tester 2.3.9\\说明.txt", "E:\\20161229040152801\\test");


	//FindHostsFile("e:\\20161229040152801", "hosts", outPath);
	//FindHostsFile("e:\\20161229040152801");
	//CURLOperate::DownloadFile("http://www.22ba.com/uploadfile/2016/1229/20161229040152801.rar", "");
	//CURLOperate op;
	//op.DownloadFile("http://www.22ba.com/uploadfile/2016/1229/20161229040152801.rar", "e:\\20161229040152801.rar");
	return 0;
}