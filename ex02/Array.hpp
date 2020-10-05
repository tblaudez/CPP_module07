/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/05 11:51:55 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/05 12:23:42 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <stdexcept>


template <typename T>
class Array {

public:

	Array(unsigned int n=0) : _size(n), _array(new T[this->_size]()) {}
	Array(Array const& src) : _array(NULL) { *this = src; }
	Array& operator=(Array const& rhs) {

		if (this != &rhs) {
			delete[] this->_array;
			this->_array = new T[rhs._size]();
			for (int i=0; i<rhs._size; i++) {
				this->_array[i] = rhs._array[i];
			}
			this->_size = rhs._size;
		}

		return *this;
	}

	T&	operator[](unsigned int i) {

		if (i >= this->_size) {
			throw std::out_of_range("Index is out of array range");
		}

		return this->_array[i];
	}

	unsigned int	size() const { return this->_size; }
	~Array() { delete[] this->_array; }

private:

	unsigned int	_size;
	T*				_array;

};
