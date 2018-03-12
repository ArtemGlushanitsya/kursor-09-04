// Kursor 09/08/2017


//prog 1
/*
#include <iostream>
f
class abc;

class def
{
public:
	int f(const abc&);
};

class abc
{
public:
	abc(void) : i{}
	{
		std::cout << "abc()" << i << std::endl;
	}

	explicit abc(const int i): i(i)
	{
		std::cout << "abc(" << i << ")" << std::endl;
	}

	explicit abc(const abc&) = delete;
	abc& operator=(const abc&) = default;
	~abc(void) = default;


	void print(void) const
	{
		std::cout << i << std::endl;
	}


private:
	int i;

	friend class def;
};

int main(void)
{
	const abc x(1234567);
	def y;
	std::cout << y.f(x) << std::endl;
}

int def::f(const abc& z)
{
	return z.i;
}
*/

//prog 2(1)
/*
#include <string>
#include <iostream>

class abc
{
public:
	abc(void) : i{}
	{
		std::cout << "abc()" << i << std::endl;
	}

	explicit abc(const int i) : i(i)
	{
		std::cout << "abc(" << i << ")" << std::endl;
	}

	explicit abc(const abc&) = default;
	abc& operator=(const abc&) = default;
	~abc(void) = default;


	void print(void) const
	{
		std::cout << i << std::endl;
	}


private:
	int i;
};

int main(void)
{
	const std::string s("ijklmnop");
	std::string t("abcdefgh");
	t += s;
	std::cout << t << std::endl;
}
*/

//prog 2(2)

/*
#include <cstring>
#include <iostream>

class abc
{
public:
	abc(void) : p(nullptr)
	{
		std::cout << "abc(): " << std::endl;
	}

	explicit abc(const char* s) : p(new char[strlen(s) + sizeof(char)]{})
	{
		strcpy(p, s);
		std::cout << "abc(" << p << ")" << std::endl;
	}

	explicit abc(const abc& x) : p(new char[strlen(x.p) + sizeof(char)]{})
	{
		strcpy(p, x.p);
		std::cout << "abc(" << p << ")" << std::endl;
	}

	
	abc& operator=(const abc&) = default;

	~abc(void)
	{
		std::cout << "~abc(): " << p << std::endl;
		delete[] p;
	}


	void print(void) const
	{
		std::cout << p << std::endl;
	}


private:
	char* p;
};

int main(void)
{
	const abc s("abcdefgh");
	s.print();
	const abc t(s);
	t.print();
}*/

//prog 2(3)
/*
#include <cstring>
#include <iostream>

class abc
{
public:
	abc(void) : p(nullptr)
	{
		std::cout << "abc(): " << std::endl;
	}

	explicit abc(const char* s) : p(new char[strlen(s) + sizeof(char)]{})
	{
		strcpy(p, s);
		std::cout << "abc(" << p << ")" << std::endl;
	}

	explicit abc(const abc& x) : p(new char[strlen(x.p) + sizeof(char)]{})
	{
		strcpy(p, x.p);
		std::cout << "abc(" << p << ")" << std::endl;
	}


	~abc(void)
	{
		std::cout << "~abc(): " << p << std::endl;
		delete[] p;
	}

	const abc& operator=(const abc& x)
	{
		std::cout << "abc::operator = (" << x.p << ")" << std::endl;
		delete[] p;
		p = new char[strlen(x.p) + sizeof(char)]{};
		strcpy(p, x.p);
		return *this;
	}


	void print(void) const
	{
		std::cout << p << std::endl;
	}


private:
	char* p;
};

int main(void)
{
	const abc s("abcdefgh");
	s.print();
	abc t, u;
	t = u = s;
	t.print();
	u.print();
}*/

//prog 2(4)

#include <cstring>
#include <iostream>

class abc
{
public:
	abc(void) : p(nullptr)
	{
		std::cout << "abc(): " << std::endl;
	}

	abc(const char* s) : p(new char[strlen(s) + sizeof(char)]{})
	{
		strcpy(p, s);
		std::cout << "abc(" << (p ? p : "") << ")" << std::endl;
	}

	abc(const abc& x) : p(new char[strlen(x.p) + sizeof(char)]{})
	{
		strcpy(p, x.p);
		std::cout << "abc(" << (p ? p : "") << ")" << std::endl;
	}

	abc(abc&& x) : p(x.p)
	{
		x.p = nullptr;
		std::cout << "abc(&& " << (p ? p : "") << ")" << std::endl;
	}

	~abc(void)
	{
		std::cout << "~abc(): " << (p ? p : "") << std::endl;
		delete[] p;
	}

	const abc& operator=(const abc& x)
	{
		std::cout << "abc::operator = (" << (x.p ? x.p : "") << ")" << std::endl;
		delete[] p;
		p = new char[strlen(x.p) + sizeof(char)]{};
		strcpy(p, x.p);
		return *this;
	}

	const abc& operator=(abc&& x)
	{
		std::cout << "abc::operator = (&& " << (x.p ? x.p : "") << ")" << std::endl;
		delete[] p;
		p = x.p;
		x.p = nullptr;
		return *this;
	}

	void print(void) const
	{
		std::cout << p << std::endl;
	}

private:
	char* p;
};

abc f(abc& x)
{
	return x;
}

int main(void)
{
	abc s("abcdefgh");
	s.print();
	abc t;
	t = f(s);
	t.print();
}