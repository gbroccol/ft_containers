/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:16:15 by gbroccol          #+#    #+#             */
/*   Updated: 2021/04/13 19:07:57 by gbroccol         ###   ########.fr       */
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

			pointer ptr;

			/*
			** -------------------------------- CONSTRUCTOR --------------------------------
			*/
				iteratorVector() { this->ptr = NULL; }
				iteratorVector(const iteratorVector &src) { *this = src; }
				iteratorVector(pointer node) { ptr = node; }
					
			/*
			** -------------------------------- DESTRUCTOR --------------------------------
			*/
				virtual ~iteratorVector() {}
			/*
			** --------------------------------- OVERLOAD ---------------------------------
			*/

				iteratorVector &	operator=(const iteratorVector& x) {
					this->ptr = x.ptr;
					return *this;
				}

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
				
				value_type					&operator*() {return *ptr; }
				const value_type			&operator*() const { return *ptr; }
				
				pointer						operator->() { return ptr; }
				const pointer				operator->() const { return ptr; }

				iteratorVector					&operator++()
				{
					ptr++;
					return *this;
				}

				iteratorVector					operator++(int)
				{
					iteratorVector tmp(*this);
					operator++();
					return tmp;
				}
				
				iteratorVector					&operator--()
				{
					ptr--;
					return *this;
				}

				iteratorVector					operator--(int)
				{
					iteratorVector tmp(*this);
					operator--();
					return tmp;
				}
	
				iteratorVector operator+(const size_t &x) { return (this->ptr + x); }
				iteratorVector operator-(const size_t &x) {return (this->ptr - x); }

				bool operator<(iteratorVector const &other) const {
					return (this->ptr < other.ptr);
				}

				bool operator>(iteratorVector const &other) const {
					return (this->ptr > other.ptr);
				}

				bool operator<=(iteratorVector const &other) const {
					return (this->ptr <= other.ptr);
				}

				bool operator>=(iteratorVector const &other) const {
					return (this->ptr >= other.ptr);
				}

				iteratorVector operator+=(const size_t &x) { return (this->ptr = this->ptr + x); }
				iteratorVector operator-=(const size_t &x) { return (this->ptr = this->ptr - x); }

				value_type &operator[](const size_t &x) { return *(ptr + x); }
				const value_type &operator[](const size_t &x) const { return *(ptr + x); }
				
    };

	template <class T>
	class const_iteratorVector : public iteratorVector <T>
	{
		public:
		
			typedef T		*pointer;

			const_iteratorVector() { this->ptr = NULL; }

			const_iteratorVector(const const_iteratorVector &src) { *this = src; }
			const_iteratorVector(const iteratorVector <T> &src) { *this = src; }
			
			const_iteratorVector(pointer node) { this->ptr = node; }
		
			const_iteratorVector &operator=(const_iteratorVector const &target)
			{
				this->ptr = target.ptr;
				return (*this);
			}
			const_iteratorVector &operator=(iteratorVector <T> const &target)
			{
				this->ptr = target.ptr;
				return (*this);
			}
			~const_iteratorVector() {}
	};
}

#endif
