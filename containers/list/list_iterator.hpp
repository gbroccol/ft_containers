/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:57:07 by gbroccol          #+#    #+#             */
/*   Updated: 2021/04/13 16:09:08 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP

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
	
	template < class T >
	class iterator 
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
				iterator() : ptr(NULL) { }
				iterator(const iterator &src) { *this = src; }
				iterator(const node_pointer node) : ptr(node) {}
			/*
			** -------------------------------- DESTRUCTOR --------------------------------
			*/
				virtual ~iterator() {}
			/*
			** --------------------------------- OVERLOAD ---------------------------------
			*/
				iterator &	operator=(const iterator& x) {
					this->ptr = x.ptr;
					return *this;
				}

				bool						operator==(const iterator &x)
				{
					if (x.ptr == ptr)
						return true;
					return false;
				}
				
				bool						operator!=(const iterator &x)
				{
					if (x.ptr != ptr)
						return true;
					return false;
				}
				
				value_type					&operator*() { return ptr->data; }
				const value_type			&operator*() const { return ptr->data; }
				
				pointer						operator->() { return &ptr->data; }
				const pointer				operator->() const { return &ptr->data; }

				iterator					&operator++()
				{
					ptr = ptr->next;
					return *this;
				}

				iterator					operator++(int)
				{
					iterator tmp(*this);
					operator++();
					return tmp;
				}
				
				iterator					&operator--()
				{
					if (ptr->pre)
						ptr = ptr->pre;
					return *this;
				}

				iterator					operator--(int)
				{
					iterator tmp(*this);
					operator--();
					return tmp;
				}
			
    };

	template <class T>
	class const_iterator : public iterator <T>
	{
		public:

			const_iterator() { this->ptr = NULL; }
			const_iterator(const const_iterator &src) { *this = src; }
			const_iterator(const iterator <T> &src) { *this = src; }
			const_iterator(Node <T> * node) { this->ptr = node; }
		
			const_iterator &operator=(const_iterator const &target)
			{
				this->ptr = target.ptr;
				return (*this);
			}
			const_iterator &operator=(iterator <T> const &target)
			{
				this->ptr = target.ptr;
				return (*this);
			}
			~const_iterator() {}
	};
}

#endif //CONT_ITERATOR_HPP
