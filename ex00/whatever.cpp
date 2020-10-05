/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/05 10:57:26 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/05 11:35:38 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void	swap(T& x, T& y) {

	T tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T const&	min(T const& x, T const& y) {

	return (x < y ? x : y);
}

template <typename T>
T const&	max(T const& x, T const& y) {

	return (x > y ? x : y);
}

class Test {
public:
	Test(int x) : x(x) {}
	~Test() {}

	bool	operator<(Test const& rhs) const { return (this->x < rhs.x); }
	bool	operator>(Test const& rhs) const { return !(this->x < rhs.x); }
	bool	operator==(Test const& rhs) const { return (this->x == rhs.x); }

	int x;
};


int	main2(void) {

	std::cout << std::boolalpha;
	{
		std::cout << "---------- Swap ----------" << std::endl;
		{
			int foo = 42, bar = 21;
			std::cout << "foo<int>: " << foo << " | bar<int>: " << bar << std::endl;
			::swap<int>(foo, bar);
			std::cout << "foo<int>: " << foo << " | bar<int>: " << bar << std::endl;
		}
		{
			float foo = 42.42f, bar = 21.21f;
			std::cout << "foo<float>: " << foo << "f | bar<float>: " << bar << "f" << std::endl;
			::swap<float>(foo, bar);
			std::cout << "foo<float>: " << foo << "f | bar<float>: " << bar << "f" << std::endl;
		}
		{
			bool foo = true, bar = false;
			std::cout << "foo<bool>: " << foo << " | bar<bool>: " << bar << std::endl;
			::swap<bool>(foo, bar);
			std::cout << "foo<bool>: " << foo << " | bar<bool>: " << bar << std::endl;
		}
		{
			Test foo(42), bar(21);
			std::cout << "foo<Test>: " << foo.x << " | bar<Test>: " << bar.x << std::endl;
			::swap<Test>(foo, bar);
			std::cout << "foo<Test>: " << foo.x << " | bar<Test>: " << bar.x << std::endl;
		}
	}

	{
		std::cout << "---------- max ----------" << std::endl;
		{
			int foo = 42, bar = 21;
			std::cout << "::max<int>(42, 21): " << ::max<int>(foo, bar) << std::endl;
		}
		{
			float foo = 42.42f, bar = 21.21f;
			std::cout << "::max<float>(42.42f, 21.21f): " << ::max<float>(foo, bar) << "f" << std::endl;
		}
		{
			bool foo = false, bar = true;
			std::cout << "::max<bool>(false, true): " << ::max<bool>(foo, bar) << std::endl;
		}
		{
			double foo = 42.0, bar = 42.0;
			std::cout << "&bar = " << &bar << std::endl;
			std::cout << "&(::max<double>(42.0, 42.0)): " << &(::max<double>(foo, bar)) << std::endl;
		}
		{
			Test foo(42), bar(21);
			std::cout << "::max<Test>(foo(42), bar(21)): " << ::max<Test>(foo, bar).x << std::endl;
		}
	}

	{
		std::cout << "---------- min ----------" << std::endl;
		{
			int foo = 42, bar = 21;
			std::cout << "::min<int>(42, 21): " << ::min<int>(foo, bar) << std::endl;
		}
		{
			float foo = 42.42f, bar = 21.21f;
			std::cout << "::min<float>(42.42f, 21.21f): " << ::min<float>(foo, bar) << "f" << std::endl;
		}
		{
			bool foo = false, bar = true;
			std::cout << "::min<bool>(false, true): " << ::min<bool>(foo, bar) << std::endl;
		}
		{
			double foo = 42.0, bar = 42.0;
			std::cout << "&bar = " << &bar << std::endl;
			std::cout << "&(::min<double>(42.0, 42.0)): " << &(::min<double>(foo, bar)) << std::endl;
		}
		{
			Test foo(42), bar(21);
			std::cout << "::min<Test>(foo(42), bar(21)): " << ::min<Test>(foo, bar).x << std::endl;
		}
	}

	return 0;
}


int main(void) {
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}
