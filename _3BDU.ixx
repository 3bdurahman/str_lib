#include <ostream>
#include <cassert>

export module _3BDU;

export class STR
{

public:
	_CONSTEXPR23 STR() _NOEXCEPT_FNPTR : i(0), str(nullptr) {}

	STR(const char*&& c_str) _NOEXCEPT_FNPTR : i(0), str(nullptr) { append(c_str); }

	STR(const char*& c_str) _NOEXCEPT_FNPTR : i(0), str(nullptr) { append(c_str); }

	STR(char*& c_str) _NOEXCEPT_FNPTR : i(0), str(nullptr) { append(c_str); }

	STR(const STR& other) _NOEXCEPT_FNPTR : i(0), str(nullptr) { append(other.str); }

	STR& operator= (const char*&& c_str)
	{
		clear();
		str = nullptr;
		append(c_str);
		return *this;
	}

	STR& operator= (const char*& c_str)
	{
		clear();
		str = nullptr;
		append(c_str);
		return *this;
	}

	STR& operator= (const STR& other) _NOEXCEPT_FNPTR
	{
		clear();
		str = nullptr;
		append(other.str);
		return *this;
	}

	_INLINE_VAR ~STR() _NOEXCEPT_FNPTR { clear(); }

	void append(const char*) _NOEXCEPT_FNPTR;

	void push_back(const char) _NOEXCEPT_FNPTR;

	_INLINE_VAR const size_t& size() _NOEXCEPT_FNPTR { return i; }

	_INLINE_VAR void clear() _NOEXCEPT_FNPTR
	{
		delete[] str;
		delete[] copied;
		i = 0;
	}

	_INLINE_VAR _CONSTEXPR23 char& operator[] (const size_t&& i) const _NOEXCEPT_FNPTR 
	{ 
		assert(str);
		if (*(str + i) == '\0')
			assert(true);
		else return *(str + i);
	}

	_INLINE_VAR _CONSTEXPR23 char& operator[] (const size_t& i) const _NOEXCEPT_FNPTR
	{
		assert(str);
		if (*(str + i) == '\0')
			assert(true);
		else return *(str + i);
	}

	STR& operator+= (const char*&& c_str) _NOEXCEPT_FNPTR 
	{ 
		append(c_str); 
		return *this;
	}

	STR& operator+= (const char*& c_str) _NOEXCEPT_FNPTR
	{
		append(c_str);
		return *this;
	}

	STR& operator+= (const char&& c) _NOEXCEPT_FNPTR 
	{ 
		push_back(c); 
		return *this;
	}

	STR& operator+= (const char& c) _NOEXCEPT_FNPTR 
	{ 
		push_back(c); 
		return *this;
	}

	STR& operator+= (const STR& other) _NOEXCEPT_FNPTR
	{ 
		append(other.str); 
		return *this;
	}

	_INLINE_VAR _CONSTEXPR23 const char& front() const _NOEXCEPT_FNPTR 
	{ 
		assert(str);
		return *str;
	}

	_INLINE_VAR _CONSTEXPR23 const char& back() const _NOEXCEPT_FNPTR 
	{ 
		assert(str);
		return *(str + i - 1);
	}

	friend std::ostream& operator<< (std::ostream& os, const STR& other) _NOEXCEPT_FNPTR
	{
		if (!other.str) return os;
		size_t j = 0;
		while (*(other.str + j) != '\0')
			os << *(other.str + j), j++;
		return os;
	}

	class iterator
	{
	public:
		_INLINE_VAR iterator(char*& str) _NOEXCEPT_FNPTR : str(str), start(str - 1) {}

		_INLINE_VAR iterator(const iterator& other) _NOEXCEPT_FNPTR : str(other.str), start(other.str - 1) {}

		_INLINE_VAR iterator() _NOEXCEPT_FNPTR : str(nullptr), start(nullptr) {}

		_INLINE_VAR char& operator* () const _NOEXCEPT_FNPTR 
		{
			assert(str);
			return *str;
		}

		_INLINE_VAR iterator& operator++ () _NOEXCEPT_FNPTR
		{
			assert(str);
			str = *(str + 1) == '\0' ? nullptr : str + 1;
			return *this;
		}

		_INLINE_VAR iterator operator++ (int) _NOEXCEPT_FNPTR
		{
			iterator temp(str);
			str = *(str + 1) != '\0' ? str + 1 : nullptr;
			return temp;
		}

		_INLINE_VAR iterator& operator-- () _NOEXCEPT_FNPTR
		{
			str = str - 1 == start ? nullptr : str - 1;
			return *this;
		}

		_INLINE_VAR iterator& operator-- (int) _NOEXCEPT_FNPTR
		{
			iterator temp(str);
			str = str - 1 == start ? nullptr : str - 1;
			return temp;
		}

		_INLINE_VAR iterator& operator+ (const long long&& n) _NOEXCEPT_FNPTR
		{
			assert(str);
			n >= 0 ? (str = *(str + n) != '\0' ? str + n : nullptr) : (str = str + n == start ? nullptr : str + n);
			return *this;
		}

		_INLINE_VAR iterator& operator+ (const long long& n) _NOEXCEPT_FNPTR
		{
			assert(str);
			n >= 0 ? (str = *(str + n) != '\0' ? str + n : nullptr) : (str = str + n == start ? nullptr : str + n);
			return *this;
		}

		_INLINE_VAR iterator& operator-(const long long&& n) _NOEXCEPT_FNPTR
		{
			assert(str);
			n >= 0 ? (str = str - n == start ? nullptr : str - n) : (str = *(str - n) != '\0' ? str - n : nullptr);
			return *this;
		}

		_INLINE_VAR iterator& operator- (const long long& n) _NOEXCEPT_FNPTR
		{
			assert(str);
			n >= 0 ? (str = str - n == start ? nullptr : str - n) : (str = *(str - n) != '\0' ? str - n : nullptr);
			return *this;
		}

		_INLINE_VAR iterator& operator+= (const long long& n) _NOEXCEPT_FNPTR
		{
			assert(str);
			n >= 0 ? (str = *(str + n) != '\0' ? str + n : nullptr) : (str = str + n == start ? nullptr : str + n);
			return *this;
		}

		_INLINE_VAR iterator& operator+= (const long long&& n) _NOEXCEPT_FNPTR
		{
			assert(str);
			n >= 0 ? (str = *(str + n) != '\0' ? str + n : nullptr) : (str = str + n == start ? nullptr : str + n);
			return *this;
		}

		_INLINE_VAR iterator& operator-= (const long long&& n) _NOEXCEPT_FNPTR
		{
			assert(str);
			n >= 0 ? (str = str - n == start ? nullptr : str - n) : (str = *(str - n) != '\0' ? str - n : nullptr);
			return *this;
		}

		_INLINE_VAR iterator& operator-= (const long long& n) _NOEXCEPT_FNPTR
		{
			assert(str);
			n >= 0 ? (str = str - n == start ? nullptr : str - n) : (str = *(str - n) != '\0' ? str - n : nullptr);
			return *this;
		}

		_INLINE_VAR bool operator!= (const iterator& other) const _NOEXCEPT_FNPTR { return str != other.str; }
		_INLINE_VAR bool operator== (const iterator& other) const _NOEXCEPT_FNPTR { return str == other.str; }
		_INLINE_VAR bool operator<= (const iterator& other) const _NOEXCEPT_FNPTR { return str <= other.str; }
		_INLINE_VAR bool operator>= (const iterator& other) const _NOEXCEPT_FNPTR { return str >= other.str; }
		_INLINE_VAR bool operator< (const iterator& other) const _NOEXCEPT_FNPTR { return str < other.str; }
		_INLINE_VAR bool operator> (const iterator& other) const _NOEXCEPT_FNPTR { return str > other.str; }


	private:
		char* str, *start;
	};

	_INLINE_VAR iterator begin() _NOEXCEPT_FNPTR { return iterator(str); }

	_INLINE_VAR iterator end() _NOEXCEPT_FNPTR { return iterator(); }

private:

	_INLINE_VAR _CONSTEXPR23 size_t get_size(const char*& c_str) const _NOEXCEPT_FNPTR
	{
		decltype(i) j = 0;
		while (*(c_str + j) != '\0')
			j++;
		return j;
	}

	_INLINE_VAR _CONSTEXPR23 void copy(char* start, char* end, char* other, const bool app = false) _NOEXCEPT_FNPTR
	{
		for (; start != end; start++, app ? other : other++)
			app ? *(other + (*start != '\0' ? i++ : i)) = *start : *other = *start;
	}

	char* str, *copied;
	size_t i;
};
