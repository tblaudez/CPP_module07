/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/05 11:37:21 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/05 11:50:01 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void	print(T x) {

	std::cout << x << std::endl;
}

template <typename T>
void	iter(T* array, int size, void (*f)(T)) {

	for (int i=0; i<size; i++) {
		(*f)(array[i]);
	}
}

int	main(void) {

	int			int_array[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	float		float_array[8] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f};

	iter<int>(int_array, 8, &print<int>);
	iter<float>(float_array, 8, &print<float>);
	return 0;
}
