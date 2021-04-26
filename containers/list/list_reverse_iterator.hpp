/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_reverse_iterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:57:07 by gbroccol          #+#    #+#             */
/*   Updated: 2021/04/26 15:07:51 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_REVERSE_ITERATOR_HPP
#define LIST_REVERSE_ITERATOR_HPP

#include <iostream>
#include <string>

namespace ft 
{
	template < class T >
	class reverse_iterator 
    {
		public: 
			
			typedef T				value_type;
			typedef T &				reference;
			typedef T *				pointer;
			
			typedef Node <T> *		node_pointer;
			typedef Node <T> &		node_reference;

			Node <T> *			ptr;

			/*
			** -------------------------------- CONSTRUCTOR --------------------------------
			*/
				reverse_iterator() : ptr(NULL) { }
				reverse_iterator(const reverse_iterator &src) { *this = src; }
				reverse_iterator(const node_pointer node) : ptr(node) {}
			/*
			** -------------------------------- DESTRUCTOR --------------------------------
			*/
				virtual ~reverse_iterator() {}
			/*
			** --------------------------------- OVERLOAD ---------------------------------
			*/
				reverse_iterator &	operator=(const reverse_iterator& x) {
					this->ptr = x.ptr;
					return *this;
				}

				bool						operator==(const reverse_iterator &x)
				{
					if (x.ptr == ptr)
						return true;
					return false;
				}
				
				bool						operator!=(const reverse_iterator &x)
				{
					if (x.ptr != ptr)
						return true;
					return false;
				}
				
				value_type					&operator*() { return ptr->data; }
				const value_type			&operator*() const { return ptr->data; }
				
				pointer						operator->() { return &ptr->data; }
				const pointer				operator->() const { return &ptr->data; }

				reverse_iterator					&operator++()
				{
					if (ptr->pre)
						ptr = ptr->pre;
					return *this;
				}

				reverse_iterator					operator++(int)
				{
					reverse_iterator tmp(*this);
					operator++();
					return tmp;
				}
				
				reverse_iterator					&operator--()
				{
					ptr = ptr->next;
					return *this;
				}

				reverse_iterator					operator--(int)
				{
					reverse_iterator tmp(*this);
					operator--();
					return tmp;
				}
			
    };

	template <class T>
	class const_reverse_iterator : public reverse_iterator <T>
	{
		public:

			const_reverse_iterator() { this->ptr = NULL; }
			const_reverse_iterator(const const_reverse_iterator &src) { *this = src; }
			const_reverse_iterator(const reverse_iterator <T> &src) { *this = src; }
			const_reverse_iterator(Node <T> * node) { this->ptr = node; }
		
			const_reverse_iterator &operator=(const_reverse_iterator const &target)
			{
				this->ptr = target.ptr;
				return (*this);
			}
			const_reverse_iterator &operator=(reverse_iterator <T> const &target)
			{
				this->ptr = target.ptr;
				return (*this);
			}
			~const_reverse_iterator() {}
	};
}

#endif