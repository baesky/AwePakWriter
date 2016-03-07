#include <Awesomium\DataPak.h>
#include <iostream>

using namespace std;
using namespace Awesomium;

WebString InputDir;
WebString OutputDir;
WebString IgnoreList;
unsigned short FileNumber;

#define GETCMDTOKEN(Dir, Token, Param, offset)											\
{																						\
	if (Token.find(Param) != string::npos)												\
	{																					\
		string TmpStr;																	\
		TmpStr = Token.substr(offset, Token.length() - offset);							\
		Dir = WebString::CreateFromUTF8(TmpStr.c_str(), TmpStr.length());				\
	}																					\
}												

int main(int argc, char* argv[])
{
	if (argc < 1)
	{
		cout << "welcome using Awesomium Pak Writer." << endl;
		cout << "-output: The full file-path to the output PAK file (filename should end with .pak)." << endl;
		cout << "-Input: The path to the input directory." << endl;
		cout << "-IgnoreList: A list of file extensions to ignore (comma-separated list, eg \".cpp, .mp4, .mp3\")." << endl;
		return 0;
	}
	else
	{
		for (int idx = 0; idx < argc; ++idx)
		{
			cout << argv[idx] << endl;
		}
	}

	for (int idx = 0; idx < argc; ++idx)
	{
		string Token(argv[idx]);
		string TmpStr;

		GETCMDTOKEN(OutputDir, Token, "-Output", 8);
		GETCMDTOKEN(InputDir, Token, "-Input", 7);
		GETCMDTOKEN(IgnoreList, Token, "-IgnoreList", 12);

	}

	if (WriteDataPak(OutputDir, InputDir, IgnoreList, FileNumber))
	{
		cout << "Pak file Num: " << FileNumber << endl;
	}
	else
	{
		cout << "Write PAK failed!" << endl;
	}

	cin.get();

	return 0;
}