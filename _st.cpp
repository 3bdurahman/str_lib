#include <ostream>
import _3BDU;

void STR::append(const char* c_str) _NOEXCEPT_FNPTR
{
	decltype(i) len = get_size(c_str);
	if (str)
	{
		delete[] str;
		str = new char[i + len + 1];
		copy(copied, copied + i + 1, str);
		delete[] copied;
		copied = new char[i + len + 1];
	}
	else
	{
		str = new char[len + 1];
		copied = new char[len + 1];
	}

	decltype(str) start = const_cast<decltype(str)>(c_str);
	copy(start, start + len + 1, str, true);
	copy(str, str + i + 1, copied);
}

void STR::push_back(const char c) _NOEXCEPT_FNPTR
{
	if (str)
	{
		delete[] str;
		str = new char[i + 2];
		copy(copied, copied + i + 1, str);
	}
	else str = new char[i + 2];
	str[i++] = c;
	str[i] = '\0';
}
