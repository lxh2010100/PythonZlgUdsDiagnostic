#ifndef _UTILITY_H_
#define _UTILITY_H_
#include <string>
#include <vector>
using namespace std;

class Utility
{
public:
	//cstring转string
	static string W2AEx( LPCTSTR wzsStr )
	{
		string strRet;
		wstring strTemp = wstring(wzsStr);
		int nLength = WideCharToMultiByte(CP_ACP, 0, strTemp.data(), strTemp.length(), NULL, 0, NULL, NULL);
		char* pAnsi = NULL;
		if (nLength > 0)
		{
			pAnsi = new char[nLength+1];
		}
		if (pAnsi)
		{
			WideCharToMultiByte(CP_ACP,0, strTemp.data(), strTemp.length(), pAnsi, nLength, NULL, NULL);
			pAnsi[nLength]=0;
			strRet = string(pAnsi);
			delete[] pAnsi;
		}
		return strRet;
	}
	//对src根据xx进行拆分
	static size_t split(vector<string>& dst, const string& src, char xx)
	{
		if (src.empty()) return 0;
		size_t count = 0;
		size_t len = src.length();
		size_t found, last_index = 0;
		string temp;
		while ((found = src.find(xx, last_index)) != (size_t)-1) {
			temp = src.substr(last_index, found - last_index);
			if (!temp.empty())
			{
				dst.push_back(temp);
				++count;
			}
			last_index = found + 1;
		}
		if (last_index < len)
		{
			temp = src.substr(last_index, found - last_index);
			if (!temp.empty())
			{
				dst.push_back(temp);
				++count;
			}
		}
		return count;
	}
	//对src根据xx进行拆分, base是进制,10:十进制, 16:16进制
	static size_t split(BYTE* dst, size_t max_len, const string& src, char xx, int base)
	{
		if (0 == max_len || NULL == dst || src.empty()) return 0;
		vector<string> items;
		size_t count = split(items, src, xx);
		if (count > 0)
		{
			count = count > max_len ? max_len : count;
			for (size_t i = 0; i < count; ++i)
			{
				dst[i] = (BYTE)strtoul(items[i].data(), 0, base);
			}
		}
		return count;
	}
};

#endif