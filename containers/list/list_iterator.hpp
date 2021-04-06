/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:57:07 by gbroccol          #+#    #+#             */
/*   Updated: 2021/04/06 20:24:59 by gbroccol         ###   ########.fr       */
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

			iterator() {}
			iterator(struct Node <T> *src) {  ptr = src; }

			// iterator(const iterator &src) { *this = src; }
				
			// iterator(struct Node <T> &src) { ptr = src; }

			/*
			** -------------------------------- DESTRUCTOR --------------------------------
			*/

			virtual ~iterator() {}

			/*
			** --------------------------------- OVERLOAD ---------------------------------
			*/

			// iterator &				operator=(iterator const & rhs )
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
			
			iterator					&operator++() // ++a 
			{
				ptr = ptr->next;
				return *this;
			}

			iterator					operator++(int) // a++ 
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
			
			/*
			** --------------------------------- METHODS ----------------------------------
			*/
			

			/*
			** --------------------------------- ACCESSOR ---------------------------------
			*/


			/* ************************************************************************** */
			
			// node_pointer	getnext() const { return ptr->next; }
			struct Node <T>		*getpre() const { return ptr->pre; }
			struct Node <T>		*getptr() const { return ptr; }

		private:

		protected:
		
		
			
    };

	template <class T>
	class const_iterator : public iterator <T>
	{
		public:
		const_iterator() {}
		const_iterator(struct Node <T> *list) { this->ptr = list; }
		const_iterator(const const_iterator &copy) { *this = copy; }
		const_iterator &operator=(const const_iterator &target)
		{
			this->ptr = target.ptr;
			return (*this);
		}
		~const_iterator() {}
		const T &operator*() { return (this->ptr->data); }
	};
}

#endif //CONT_ITERATOR_HPP