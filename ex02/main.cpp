/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/05 12:12:42 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/05 12:25:18 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <iostream>


int	main(void) {


	Array<float> tmp(9);
	Array<float> array(tmp);

	array[3] = 21.21f;
	array[5] = 42.42f;
	array[7] = 84.84f;

	try
	{
		for (int i=0; i<array.size() + 1; i++) {
			std::cout << array[i] << std::endl;
		}
	}
	catch (std::out_of_range& oor) {
		std::cerr << "Error: " << oor.what() << std::endl;
	}


	return 0;
}
