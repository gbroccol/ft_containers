/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_reverse_iterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:57:07 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/23 17:07:02 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_REVERSE_ITERATOR_HPP
#define LIST_REVERSE_ITERATOR_HPP

#include <iostream>
#include <string>

namespace ft 
{
	// template < typename T>
	// struct			Node
	// {
	// 	T			data;
	// 	Node		*pre;
	// 	Node		*next;
	// };

	// template <	class Category,              // iterator::iterator_category
	// 			class T,                     // iterator::value_type
	// 			class Distance = ptrdiff_t,  // iterator::difference_type
	// 			class Pointer = T*,          // iterator::pointer
	// 			class Reference = T&         // iterator::reference
    //       	> 	class iterator;

	template < class T >
	class reverse_iterator 
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

			reverse_iterator() {}
			reverse_iterator(struct Node <T> *src) {  ptr = src; }

			// reverse_iterator(const reverse_iterator &src) { *this = src; }
				
			// reverse_iterator(struct Node <T> &src) { ptr = src; }

			/*
			** -------------------------------- DESTRUCTOR --------------------------------
			*/

			~reverse_iterator() {}

			/*
			** --------------------------------- OVERLOAD ---------------------------------
			*/

			// reverse_iterator &				operator=(reverse_iterator const & rhs )
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
			
			value_type					&operator*()
			{
				// if (ptr == _Tail)
				// 	return ptr->pre->data;
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
			
			reverse_iterator					&operator++() // ++a 
			{
				ptr = ptr->next;
				return *this;
			}

			reverse_iterator					&operator++(int) // a++ 
			{
				reverse_iterator tmp(*this);
				operator++();
				return *this;
			}
			
			reverse_iterator					&operator--()  // check
			{
				if (ptr->pre)
					ptr = ptr->pre;
				return *this;
			}

			reverse_iterator					&operator--(int)  // check
			{
				reverse_iterator tmp(*this);
				operator--();
				return *this;
			}
			
			/*
			** --------------------------------- METHODS ----------------------------------
			*/
				// node_pointer	getnext() const { return ptr->next; }
				struct Node <T>		*getpre() const { return ptr->pre; }
				struct Node <T>		*getptr() const { return ptr; }
			/*
			** --------------------------------- ACCESSOR ---------------------------------
			*/

			/* ************************************************************************** */
			
    };

	template <class T>
	class const_reverse_iterator : public reverse_iterator <T>
	{
		public:
		const_reverse_iterator() {}
		const_reverse_iterator(struct Node <T> *list) { this->ptr = list; }
		const_reverse_iterator(const const_reverse_iterator &copy) { *this = copy; }
		const_reverse_iterator &operator=(const const_reverse_iterator &target)
		{
			this->ptr = target.ptr;
			return (*this);
		}
		~const_reverse_iterator() {}
		const T &operator*() { return (this->ptr->data); }
	};
}

#endif //CONT_ITERATOR_HPP