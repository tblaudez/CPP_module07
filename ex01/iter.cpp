/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/05 11:37:21 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/12/03 15:45:34 by tblaudez      ########   odam.nl         */
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
inline void	print(const T& x) {
	std::cout << x << std::endl;
}

template <typename T>
void	iter(T* array, int size, void (*f)(const T&)) {

	for (int i=0; i < size; i++) {
		(*f)(array[i]);
	}
}

int	main(void) {

	int			int_array[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	float		float_array[8] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f};
	Test		test_array[8] = {Test(1), Test(2), Test(3), Test(4), Test(5), Test(6), Test(7), Test(8)};
	std::string	string_array[8] = {"Hello", "World", "Nice", "To", "Meet", "You", "In", "Here"};

	::iter(int_array, 8, print);
	::iter(float_array, 8, print);
	::iter(test_array, 8, print);
	::iter(string_array, 8, print);

	return 0;
}
