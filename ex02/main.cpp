/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/05 12:12:42 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 16:30:01 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <iostream> // cout, string


int	main(void) {

	Array<float>	array(5);

	array[0] = 0.0f;
	array[1] = 1.1f;
	array[2] = 2.2f;
	array[3] = 3.3f;
	array[4] = 4.4f;

	Array<float>	array2(array);
	array2[2] = 42.4242424242f;
	array2[4] = 21.2121212121f;

	try
	{
		for (unsigned int i=0; i < array.size() + 1; i++) {
			std::cout << array[i] << " | " << array2[i] << std::endl;
		}
	}
	catch (std::out_of_range& oor) {
		std::cerr << "Error: " << oor.what() << std::endl;
	}



	return 0;
}
