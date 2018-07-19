#pragma once

class String
{
	friend ostream&operator<<(ostream&_cout, const String&s1)
	{
		_cout << s1._pStr;
		return _cout;
	}
public:
	String(const char* pStr = "")
	{
		if (pStr == NULL)
		{
			pStr = "";
		}
		size_t len = strlen(pStr);
		_pStr = new char[len + 1];
		strcpy(_pStr, pStr);
	}
	String(const String& s) :_pStr(NULL)
	{
		String temp(s._pStr);
		swap(_pStr, temp._pStr);
	}
	String& operator=(const String& s)
	{
		if (this == &s)
			return *this;
		String temp(s);
		swap(_pStr, temp._pStr);
		return*this;
	}
	~String()
	{
		delete _pStr;
	}

	// 不能使用库函数 
	size_t Lengh()const
	{
		char*src = _pStr;
		while (*src)
		{
			src++;
		}
		return src - _pStr;
	}
	char& operator[](size_t index)
	{
		return _pStr[index];
	}
	const char& operator[](size_t index)const
	{
		return _pStr[index];
	}
	bool operator>(const String& s)
	{
		char*src1 = _pStr;
		char*src2 = s._pStr;
		while (*src1 == *src2)
		{
			src1++;
			src2++;
		}
		if (*src1 > *src2)
			return true;
		return false;
	}
	bool operator<(const String& s)
	{
		char*src1 = _pStr;
		char*src2 = s._pStr;
		while (*src1 == *src2)
		{
			src1++;
			src2++;
		}
		if (*src1 < *src2)
			return true;
		return false;
	}
	bool operator==(const String& s)
	{
		if (s.Lengh() == Lengh())
		{
			char*src1 = _pStr;
			char*src2 = s._pStr;
			while (*src1 == *src2)
			{
				if (!*src1)
					return true;
				src1++;
				src2++;
			}
		}
		return false;
	}
	bool operator!=(const String& s)
	{
		if (s.Lengh() == Lengh())
		{
			char*src1 = _pStr;
			char*src2 = s._pStr;
			while (*src1 == *src2)
			{
				if (!*src1)
					return false;
				src1++;
				src2++;
			}
		}
		return true;
	}
	void Copy(const String& s)
	{
		if (this == &s)
			return;
		String temp(s);
		swap(_pStr, temp._pStr);
	}
	bool strstr(const String& s)
	{
		char*ps1 = _pStr;
		while (*ps1)
		{
			char*temp_ps1 = ps1;
			char*ps2 = s._pStr;
			while (*temp_ps1 == *ps2&&*ps2)
			{
				temp_ps1++;
				ps2++;
			}
			if (!*ps2)
				return true;
			if (!*temp_ps1)
				return false;
			ps1++;
		}
		return false;
	}
	String& operator+=(const String&s)
	{
		size_t len = s.Lengh() + Lengh();
		char*Ps = new char[len + 1];
		char*temp = Ps;
		char*_tpstr = _pStr;
		while (*temp = *_tpstr)
		{
			temp++;
			_tpstr++;
		}
		_tpstr = s._pStr;
		while (*temp++ = *_tpstr++)
		{
		}
		delete _pStr;
		_pStr = Ps;
		return *this;
	}

private:
	char* _pStr;
};