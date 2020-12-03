/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/05 10:57:26 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/12/03 15:39:45 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // cout

class	Test {
public:
	Test(int n=0) : n(n) {}
	~Test() {}

	bool	operator<(Test const& rhs) const { return this->n < rhs.n; }
	bool	operator<=(Test const& rhs) const { return this->n <= rhs.n; }
	bool	operator>(Test const& rhs) const { return this->n > rhs.n; }
	bool	operator>=(Test const& rhs) const { return this->n >= rhs.n; }
	bool	operator==(Test const& rhs) const { return this->n == rhs.n; }
	bool	operator!=(Test const& rhs) const { return this->n != rhs.n; }

	int n;
};

std::ostream&	operator<<(std::ostream& o, const Test& i) {
	return o << "Test(" << i.n << ")";
}


template <typename T>
void	swap(T& x, T& y) {
	T tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
inline const T&	min(const T& x, const T& y) {
	return (x < y ? x : y);
}

template <typename T>
inline const T&	max(const T& x, const T& y) {
	return (x > y ? x : y);
}

int	main(void) {

	// Test 	A(21), B(42);
	// int		A = 21, B = 42;
	// float	A = 21.2121f, B = 42.4242f;
	std::string	A = "Hello", B = "Hellooooooo";

	std::cout << "A: " << A << " | B: " << B << std::endl;
	::swap(A, B);
	std::cout << "A: " << A << " | B: " << B << std::endl;

	std::cout << "min(A, B): " << ::min(A, B) << std::endl;
	std::cout << "max(A, B): " << ::max(A, B) << std::endl;

	return 0;
}
