/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/05 12:12:42 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/12/03 15:50:32 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <iostream> // cout, string


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


int	main(void) {

	Array<Test>	array(5);

	array[0] = Test(0);
	array[1] = Test(1);
	array[2] = Test(2);
	array[3] = Test(3);
	array[4] = Test(4);

	Array<Test>	other_array(3);
	other_array = array;
	other_array[0] = Test(21);
	other_array[1] = Test(42);

	try
	{
		for (unsigned int i=0; i < array.size() + 1; i++) {
			std::cout << "Array 1: " << array[i] << " | Array 2: " << other_array[i] << std::endl;
		}
	}
	catch (std::out_of_range& oor) {
		std::cerr << "Error: " << oor.what() << std::endl;
	}

	return 0;
}
