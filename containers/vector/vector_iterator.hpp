/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:16:15 by gbroccol          #+#    #+#             */
/*   Updated: 2021/04/05 12:00:32 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include <iostream>
#include <string>

namespace ft 
{

	template < class T >
	class iteratorVector 
    {
		public: 
			
			typedef T		value_type;
			typedef T		&reference;
			typedef T		*pointer;

			/*
			** -------------------------------- CONSTRUCTOR --------------------------------
			*/

			iteratorVector() {}
			iteratorVector(pointer src) {  ptr = src; }

			// iteratorVector(const iteratorVector &src) { *this = src; }
				
			// iteratorVector(pointer &src) { ptr = src; }

			/*
			** -------------------------------- DESTRUCTOR --------------------------------
			*/

			virtual ~iteratorVector() {}

			/*
			** --------------------------------- OVERLOAD ---------------------------------
			*/

			// iteratorVector &				operator=(iteratorVector const & rhs )
			// {
			// 	this->ptr = rhs;
			// }

			bool						operator==(const iteratorVector &x)
			{
				if (x.ptr == ptr)
					return true;
				return false;
			}
			
			bool						operator!=(const iteratorVector &x)
			{
				if (x.ptr != ptr)
					return true;
				return false;
			}
			
			value_type					&operator*()
			{
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
			
			iteratorVector					&operator++() // ++a 
			{
				ptr++;
				return *this;
			}

			iteratorVector					&operator++(int) // a++ 
			{
				iteratorVector tmp(*this);
				operator++();
				return *this;
			}
			
			iteratorVector					&operator--()
			{
				ptr--;
				return *this;
			}

			iteratorVector					&operator--(int)
			{
				iteratorVector tmp(*this);
				operator--();
				return *this;
			}

			/* ************************************************************************** */
			
			// node_pointer	getnext() const { return ptr->next; }
			// pointer		*getpre() const { return ptr->pre; }
			pointer		getptr() const { return ptr; }

        protected: 

			pointer ptr;
			
    };

	template <class T>
	class const_iteratorVector : public iteratorVector <T>
	{
		public:

			typedef T		*pointer;
		
			const_iteratorVector() {}
			const_iteratorVector(pointer vector) { this->ptr = vector; }
			const_iteratorVector(const const_iteratorVector &copy) { *this = copy; }
			const_iteratorVector &operator=(const const_iteratorVector &target)
			{
				this->ptr = target.ptr;
				return (*this);
			}
			~const_iteratorVector() {}
			const T &operator*() { return (* (this->ptr)); }
	};


}

#endif
