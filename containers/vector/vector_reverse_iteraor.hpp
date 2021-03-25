/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reverse_iteraor.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:53:07 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/25 14:24:03 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_REVERSE_ITERATOR_HPP
#define VECTOR_REVERSE_ITERATOR_HPP

#include <iostream>
#include <string>

namespace ft 
{
	template < class T >
	class reverseIteratorVector 
    {
		public: 
			
			typedef T		value_type;
			typedef T		&reference;
			typedef T		*pointer;

			/*
			** -------------------------------- CONSTRUCTOR --------------------------------
			*/

			reverseIteratorVector() {}
			reverseIteratorVector(pointer src) {  ptr = src; }

			// reverseIteratorVector(const reverseIteratorVector &src) { *this = src; }
				
			// reverseIteratorVector(pointer &src) { ptr = src; }

			/*
			** -------------------------------- DESTRUCTOR --------------------------------
			*/

			~reverseIteratorVector() {}

			/*
			** --------------------------------- OVERLOAD ---------------------------------
			*/

			// reverseIteratorVector &				operator=(reverseIteratorVector const & rhs )
			// {
			// 	this->clear();
			// // 	this->head->next = this->tail;
			// // 	this->tail->prev = this->head;
			// // 	this->length = 0;
			// // 	this->assign(x.begin(), x.end());
			// 	return *this;


			// // 	// std::cout << "hi" << std::endl;
			
			// // 	// if ( this != &rhs )
			// // 		*this = rhs;
				
			// // 	return *this;
			// }

			bool						operator==(const reverseIteratorVector &x)
			{
				if (x.ptr == ptr)
					return true;
				return false;
			}
			
			bool						operator!=(const reverseIteratorVector &x)
			{
				if (x.ptr != ptr)
					return true;
				return false;
			}
			
			value_type					&operator*()
			{
				// if (ptr == _Tail)
				// 	return ptr->pre->data;
				return *ptr;
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
			
			reverseIteratorVector					&operator++() // ++a 
			{
				ptr--;
				return *this;
			}

			reverseIteratorVector					&operator++(int) // a++ 
			{
				reverseIteratorVector tmp(*this);
				operator++();
				return *this;
			}
			
			reverseIteratorVector					&operator--()  // check
			{
				ptr++;
				return *this;
			}

			reverseIteratorVector					&operator--(int)  // check
			{
				reverseIteratorVector tmp(*this);
				operator--();
				return *this;
			}
			
			/*
			** --------------------------------- METHODS ----------------------------------
			*/
			

			/*
			** --------------------------------- ACCESSOR ---------------------------------
			*/


			/* ************************************************************************** */
			
			// node_pointer	getnext() const { return ptr->next; }
			// pointer		*getpre() const { return ptr->pre; }
			pointer		getptr() const { return ptr; }

        protected: 

			pointer ptr;
		
		
			
    };

	template <class T>
	class const_reverseIteratorVector : public reverseIteratorVector <T>
	{
		public:

			typedef T		*pointer;
		
			const_reverseIteratorVector() {}
			const_reverseIteratorVector(pointer vector) { this->ptr = vector; }
			const_reverseIteratorVector(const const_reverseIteratorVector &copy) { *this = copy; }
			const_reverseIteratorVector &operator=(const const_reverseIteratorVector &target)
			{
				this->ptr = target.ptr;
				return (*this);
			}
			~const_reverseIteratorVector() {}
			const T &operator*() { return (* (this->ptr)); }
	};

}

#endif
