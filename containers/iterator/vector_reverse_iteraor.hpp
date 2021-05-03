/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reverse_iteraor.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:53:07 by gbroccol          #+#    #+#             */
/*   Updated: 2021/04/13 19:36:57 by gbroccol         ###   ########.fr       */
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

			pointer ptr;

			/*
			** -------------------------------- CONSTRUCTOR --------------------------------
			*/
				reverseIteratorVector() { this->ptr = NULL; }
				reverseIteratorVector(const reverseIteratorVector &src) { *this = src; }
				reverseIteratorVector(pointer node) { ptr = node; }
					
			/*
			** -------------------------------- DESTRUCTOR --------------------------------
			*/
				virtual ~reverseIteratorVector() {}
			/*
			** --------------------------------- OVERLOAD ---------------------------------
			*/

				reverseIteratorVector &					operator=(const reverseIteratorVector& x) {
					this->ptr = x.ptr;
					return *this;
				}

				bool									operator==(const reverseIteratorVector &x) {
					return (x.ptr == ptr) ? true : false;
				}
				
				bool									operator!=(const reverseIteratorVector &x) {
					return (x.ptr != ptr) ? true : false;
				}
				
				value_type								&operator*() {return *ptr; }
				const value_type						&operator*() const { return *ptr; }
				
				pointer									operator->() { return ptr; }
				const pointer							operator->() const { return ptr; }

				reverseIteratorVector					&operator++()
				{
					ptr--;
					return *this;
				}

				reverseIteratorVector					operator++(int)
				{
					reverseIteratorVector tmp(*this);
					operator++();
					return tmp;
				}
				
				reverseIteratorVector					&operator--()
				{
					ptr++;
					return *this;
				}

				reverseIteratorVector					operator--(int)
				{
					reverseIteratorVector tmp(*this);
					operator--();
					return tmp;
				}
	
				reverseIteratorVector operator+(const size_t &x) { return (this->ptr - x); }
				reverseIteratorVector operator-(const size_t &x) {return (this->ptr + x); }

				bool operator<(reverseIteratorVector const &other) const {
					return (this->ptr > other.ptr);
				}

				bool operator>(reverseIteratorVector const &other) const {
					return (this->ptr < other.ptr);
				}

				bool operator<=(reverseIteratorVector const &other) const {
					return (this->ptr >= other.ptr);
				}

				bool operator>=(reverseIteratorVector const &other) const {
					return (this->ptr <= other.ptr);
				}

				reverseIteratorVector operator+=(const size_t &x) { return (this->ptr = this->ptr - x); }
				reverseIteratorVector operator-=(const size_t &x) { return (this->ptr = this->ptr + x); }

				value_type &operator[](const size_t &x) { return *(ptr - x); }
				const value_type &operator[](const size_t &x) const { return *(ptr - x); }
				
    };

	template <class T>
	class const_reverseIteratorVector : public reverseIteratorVector <T>
	{
		public:
		
			typedef T		*pointer;

			const_reverseIteratorVector() { this->ptr = NULL; }

			const_reverseIteratorVector(const const_reverseIteratorVector &src) { *this = src; }
			const_reverseIteratorVector(const reverseIteratorVector <T> &src) { *this = src; }
			
			const_reverseIteratorVector(pointer node) { this->ptr = node; }
		
			const_reverseIteratorVector &operator=(const_reverseIteratorVector const &target)
			{
				this->ptr = target.ptr;
				return (*this);
			}
			const_reverseIteratorVector &operator=(reverseIteratorVector <T> const &target)
			{
				this->ptr = target.ptr;
				return (*this);
			}
			~const_reverseIteratorVector() {}
	};
}

#endif