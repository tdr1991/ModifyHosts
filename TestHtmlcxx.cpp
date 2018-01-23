#include "ParserDom.h"
#include <iostream>
#include<regex>

#include"BinaryStream.h"
#include"StringUtil.h"
#include"str_commfun.h"

using namespace std;
using namespace dm_common;
using namespace unidst;

int test2(int args, char* argv[])
{
	
	htmlcxx::HTML::ParserDom parserHtml;
	string fileContent;
	string htmlPath = "e:\\Share867.html";
	BinaryReader reader;
	if (reader.Open(htmlPath))
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
 
    std::string pattern("http(s)?://([\\w-]+\\.)+[\\w-]+(/[\\w- ./?%&=]*)?");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    std::regex r(pattern);
    for (std::sregex_iterator it(fileContent.begin(), fileContent.end(), r), end;     //end是尾后迭代器，regex_iterator是regex_iterator的string类型的版本
        it != end;
        ++it)
    {
		if(regex_match(it->str(), regex("http://www.22ba.com/uploadfile/2016/.*")))
		{
			std::cout << it->str() << std::endl;
			break;
		}
        //std::cout << it->str() << std::endl;
    }
	string gbktoutf = "";
	string ch = "";
	string ch2 = "";
	StringHelper::AnsiToUtf8("解压密码", gbktoutf);

	StringHelper::AnsiToUtf8("）", ch);
	StringHelper::AnsiToUtf8("：", ch2);
	std::string patt(gbktoutf + ".*" + ch);
    std::regex rs(patt);
    for (std::sregex_iterator it(fileContent.begin(), fileContent.end(), rs), end;     //end是尾后迭代器，regex_iterator是regex_iterator的string类型的版本
        it != end;
        ++it)
    {	
		vector<string> str1;
		vector<string> str2;
		CStr_CommFun::StrSplit(it->str(), ch2.c_str(), str1);
		CStr_CommFun::StrSplit(str1[1], ch.c_str(), str2);
		string utftogbk = "";
		StringHelper::UTF8ToAnsi(str2[0], utftogbk);

		StringHelper::Split(it->str(), ch2, str1);
		StringHelper::Split(str1[1], ch, str2);
		std::cout << str2[0] << std::endl;
		
		//string utftogbk = "";
		//StringHelper::UTF8ToAnsi(it->str(), utftogbk);
		

		
        //std::cout << it->str() << std::endl;
    }
	/*
	tree<htmlcxx::HTML::Node> dom = parserHtml.parseTree(fileContent);
	tree<htmlcxx::HTML::Node>::iterator it = dom.begin();
	tree<htmlcxx::HTML::Node>::iterator end = dom.end();
	for (; it != end; it++)
	{
		std::string strText;
		if (it->isComment())
			continue ;

		if (it->isTag())
		{
			it->parseAttributes();
			if(it->tagName() == "meta")
			{
				std::string liText = it->text();
				std::cout<<liText<<std::endl;
			}
		}
	}
	*/

	return 0;
}