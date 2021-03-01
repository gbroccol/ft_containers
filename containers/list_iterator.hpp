/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:57:07 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/01 20:46:54 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include <string>

namespace ft 
{
	
	template < typename T>
	struct			Node
	{
		T			data;
		Node		*pre;
		Node		*next;
	};

	// template <	class Category,              // iterator::iterator_category
	// 			class T,                     // iterator::value_type
	// 			class Distance = ptrdiff_t,  // iterator::difference_type
	// 			class Pointer = T*,          // iterator::pointer
	// 			class Reference = T&         // iterator::reference
    //       	> 	class iterator;

	template < class T >
	class iterator 
    {
		protected: // ???

			Node <T> *ptr;
			
		public: 
			
			typedef T		value_type;
			typedef T		&reference;
			typedef T		*pointer;

			/*
			** -------------------------------- CONSTRUCTOR --------------------------------
			*/

			// iterator() {}

			iterator(struct Node <T> *src) {  ptr = src; }

			// iterator(const iterator &src) { *this = src; }
				
			// iterator(struct Node <T> &src) { ptr = src; }

			/*
			** -------------------------------- DESTRUCTOR --------------------------------
			*/

			~iterator() {}

			/*
			** --------------------------------- OVERLOAD ---------------------------------
			*/

			// iterator &				operator=(iterator const & rhs )
			// {
			// 	if ( this != &rhs )
			// 		*this = rhs;
			// 	return *this;
			// }

			// bool						operator==(const iterator &x)
			// {
			// 	if (x.ptr == ptr)
			// 		return true;
			// 	return false;
			// }
			
			// bool						operator!=(const iterator &x)
			// {
			// 	if (x.ptr != ptr)
			// 		return true;
			// 	return false;
			// }
			
			value_type					&operator*()
			{
				return ptr->data;
			}
			
			// const value_type			&operator*() const
			// {
			// 	return ptr->data;
			// }
			
			// pointer						operator->()
			// {
			// 	return &ptr->data;
			// }
			
			// const pointer				operator->() const
			// {
			// 	return &ptr->data;
			// }
			
			// iterator					&operator++() // check
			// {
			// 	ptr++;
			// 	return *this;
			// }

			// iterator					&operator++(int) // check
			// {
			// 	iterator tmp(*this);
			// 	operator++();
			// 	return tmp;
			// }
			
			// iterator					&operator--()  // check
			// {
			// 	ptr--;
			// 	return *this;
			// }

			// iterator					&operator--(int)  // check
			// {
			// 	iterator tmp(*this);
			// 	operator--();
			// 	return tmp;
			// }
			

			/*
			** --------------------------------- METHODS ----------------------------------
			*/


			/*
			** --------------------------------- ACCESSOR ---------------------------------
			*/


			/* ************************************************************************** */

		private: 
		
			// previous
			// next

			// Node <T> ptr;
			
			
    }; 
}

#endif //CONT_ITERATOR_HPP