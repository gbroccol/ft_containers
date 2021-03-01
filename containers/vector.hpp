/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:11:15 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/01 14:13:31 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONT_VECTOR_HPP
#define CONT_VECTOR_HPP

#include <iostream>
// #include <string>
// #include <cassert>
// #include <algorithm>

// void push(int data): This function takes one element and inserts it at the last. Amortized time complexity is O(1). 
// void push(int data, int index): It inserts data at the specified index. Time complexity is O(1). 
// int get(int index): It is used to get the element at the specified index. Time complexity is O(1). 
// void pop(): It deletes the last element. Time complexity is O(1). 
// int size(): It returns the size of the vector i.e, number of elements in the vector. Time complexity is O(1). 
// int getcapacity(): It returns the capacity of the vector. Time complexity is O(1). 
// void print(): It is used to print array elements. Time complexity is O(N), where N is the size of the vector. 

namespace ft 
{
    template <typename T>
	class vector 
    { 
		public: 

			/*
			** -------------------------------- CONSTRUCTOR --------------------------------
			*/

			vector() {}
	
			/*
			** -------------------------------- DESTRUCTOR --------------------------------
			*/

			~vector() {}

			/*
			** --------------------------------- OVERLOAD ---------------------------------
			*/

			// Vector &				Vector::operator=( Vector const & rhs )
			// {
			// 	//if ( this != &rhs )
			// 	//{
			// 		//this->_value = rhs.getValue();
			// 	//}
			// 	return *this;
			// }

			// std::ostream &			operator<<( std::ostream & o, Vector const & i )
			// {
			// 	//o << "Value = " << i.getValue();
			// 	return o;
			// }


			/*
			** --------------------------------- METHODS ----------------------------------
			*/


			/*
			** --------------------------------- ACCESSOR ---------------------------------
			*/


			/* ************************************************************************** */





			// typedef T * iterator;
			// Vector(unsigned int size);
			// Vector(unsigned int size, const T & initial);
			// Vector(const Vector<T> & v);      
			// ~vector();

			// unsigned int capacity() const;
			unsigned int size() const { return (1); }
			// bool empty() const;
			// iterator begin();
			// iterator end();
			// T & front();
			// T & back();
			// void push_back(const T & value); 
			// void pop_back();  

			// void reserve(unsigned int capacity);   
			// void resize(unsigned int size);   

			// T & operator[](unsigned int index);  
			// Vector<T> & operator=(const Vector<T> &);
			// void clear();

		private: 
			
			// unsigned int my_size;
			// unsigned int my_capacity;
			// T * buffer;
    }; 
}

#endif //CONT_VECTOR_H



// template<class T>
// Vector<T>::Vector()
// {
//     my_capacity = 0;
//     my_size = 0;
//     buffer = 0;
// }

// template<class T>
// Vector<T>::Vector(const Vector<T> & v)
// {
//     my_size = v.my_size;
//     my_capacity = v.my_capacity;
//     buffer = new T[my_size];  
//     for (int i = 0; i < my_size; i++)
//         buffer[i] = v.buffer[i];  
// }

// template<class T>
// Vector<T>::Vector(unsigned int size)
// {
//     my_capacity = size;
//     my_size = size;
//     buffer = new T[size];
// }

// template<class T>
// Vector<T>::Vector(unsigned int size, const T & initial)
// {
//     my_size-size;
//     my_capacity = size;
//     buffer = new T [size];
//     for (int i = 0; i < size; i++)
//         buffer[i] = initial;
        // // T(); // надо?
// }

// template<class T>
// Vector<T> & Vector<T>::operator = (const Vector<T> & v)
// {
//     delete[ ] buffer;
//     my_size = v.my_size;
//     my_capacity = v.my_capacity;
//     buffer = new T [my_size];
//     for (int i = 0; i < my_size; i++)
//         buffer[i] = v.buffer[i];
//     return *this;
// }

// template<class T>
// typename Vector<T>::iterator Vector<T>::begin()
// {
//     return buffer;
// }

// template<class T>
// typename Vector<T>::iterator Vector<T>::end()
// {
//     return buffer + size();
// }

// template<class T>
// T& Vector<T>::Vector<T>::front()
// {
//     return buffer[0];
// }

// template<class T>
// T& Vector<T>::Vector<T>::back()
// {
//     return buffer[size - 1];
// }

// template<class T>
// void Vector<T>::push_back(const T & v)
// {
//     if (my_size >= my_capacity)
//     reserve(my_capacity +5);
//     buffer [my_size++] = v;
// }

// template<class T>
// void Vector<T>::pop_back()
// {
//     my_size--;
// }

// template<class T>
// void Vector<T>::reserve(unsigned int capacity)
// {
//     if(buffer == 0)
//     {
//         my_size = 0;
//         my_capacity = 0;
//     }    
//     T * Newbuffer = new T [capacity];
//     //assert(Newbuffer);
//     unsigned int l_Size = capacity < my_size ? capacity : my_size;
//     //copy (buffer, buffer + l_Size, Newbuffer);

//     for (unsigned int i = 0; i < l_Size; i++)
//         Newbuffer[i] = buffer[i];

//     my_capacity = capacity;
//     delete[] buffer;
//     buffer = Newbuffer;
// }

// template<class T>
// unsigned int Vector<T>::size()const//
// {
//     return my_size;
// }

// template<class T>
// void Vector<T>::resize(unsigned int size)
// {
//     reserve(size);
//     size = size;
// }

// template<class T>
// T& Vector<T>::operator[](unsigned int index)
// {
//     return buffer[index];
// }  

// template<class T>
// unsigned int Vector<T>::capacity()const
// {
//     return my_capacity;
// }

// template<class T>
// Vector<T>::~Vector()
// {
//     delete[]buffer;
// }