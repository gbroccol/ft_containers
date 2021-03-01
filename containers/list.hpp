/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:32:17 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/01 20:45:14 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONT_LIST_HPP
#define CONT_LIST_HPP

#include <iostream>
#include "list_iterator.hpp"

// #include <string>
// #include <cassert>
// #include <algorithm>

namespace ft 
{
	template < class T, class Alloc = std::allocator<T> >
	class list 
    { 
		public: 
			
			typedef ft::iterator<T>					iterator;
			typedef const ft::iterator<T>			const_iterator;
			
			// typedef ft::reverse_iterator<T>			reverse_iterator;
			// typedef const ft::reverse_iterator<T>	const_reverse_iterator;
			
			typedef T						value_type;
			typedef Alloc					allocator_type;
			typedef size_t					size_type;
			// typedef value_type&				reference;
			// typedef const value_type&		const_reference;
			// typedef value_type*				pointer;
			// typedef const value_type*		const_pointer;
			// typedef ptrdiff_t				difference_type;
  
			// typedef T 
			// typedef Alloc allocator_type;
			// typedef size_t size_type;

			/*
			** -------------------------------- CONSTRUCTOR --------------------------------
			*/
		
			explicit list (const allocator_type& alloc = allocator_type()) : _sizeList(0)
			{
				_alloc = alloc;
				
				_node = NULL;
				_start = NULL;
				_finish = NULL;
			}
			
			// explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			
			// template <class InputIterator>
			// list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			
			// list (const list& x);
	
			/*
			** -------------------------------- DESTRUCTOR --------------------------------
			*/

			~list() {}

			/*
			** --------------------------------- OVERLOAD ---------------------------------
			*/

			// list &				operator=( const list & rhs )
			// {
			// 	//if ( this != &rhs )
			// 	//{
			// 		//this->_value = rhs.getValue();
			// 	//}
			// 	return *this;
			// }


			/*
			** --------------------------------- METHODS ----------------------------------
			*/

			/* Iterators */

			iterator begin() { return (iterator (_start)); }
			// const_iterator begin() const;

			iterator end() { return (iterator (_finish)); }
			// const_iterator end() const;

			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;

			// reverse_iterator rend();
			// const_reverse_iterator rend() const;

			/* Capacity */

			// bool empty() const { return (_sizeList == 0 ? true : false); }
			size_type size() const { return _sizeList; }
			// size_type max_size() const;

			/* Element access */

			// reference front();
			// const_reference front() const;

			// reference back();
			// const_reference back() const;

			/* Modifiers */

			// template <class InputIterator>
			// void assign (InputIterator first, InputIterator last);
			// void assign (size_type n, const value_type& val);

			void push_front (const value_type& val)
			{
				if (_sizeList == 0)
				{
					_node = new Node <T> ();
					_node->data = val;
					_node->next = NULL;
					_node->pre = NULL;

					_sizeList++;

					_start = _node;
					_finish = _node;
				}
				else
				{
					Node <T> * tmp = new Node <T> ();
					_node->pre = tmp;
					
					tmp->data = val;
					tmp->next = _start;
					tmp->pre = NULL;

					_start = tmp;

					_sizeList++;
				}
			}
			
			// void pop_front();

			void push_back (const value_type& val)
			{
				if (_sizeList == 0)
				{
					_node = new Node <T> ();
					_node->data = val;
					_node->next = NULL;
					_node->pre = NULL;

					_sizeList++;

					_start = _node;
					_finish = _node;
				}
				else
				{
					Node <T> * tmp = new Node <T> ();
					
					tmp->data = val;
					tmp->next = NULL;
					tmp->pre = _finish;

					_finish = tmp;
					_sizeList++;
				}
			}

			// void pop_back();

			// iterator insert (iterator position, const value_type& val);
			// void insert (iterator position, size_type n, const value_type& val);
			// template <class InputIterator>
			// void insert (iterator position, InputIterator first, InputIterator last);

			// iterator erase (iterator position);
			// iterator erase (iterator first, iterator last);

			// void swap (list& x);

			// void resize (size_type n, value_type val = value_type());
			
			// void clear();

			/* Operations */

			// void splice (iterator position, list& x);
			// void splice (iterator position, list& x, iterator i);
			// void splice (iterator position, list& x, iterator first, iterator last);

			// void remove (const value_type& val);

			// template <class Predicate>
			// void remove_if (Predicate pred);

			// void unique();
			// template <class BinaryPredicate>
			// void unique (BinaryPredicate binary_pred);

			// void merge (list& x);
			// template <class Compare>
			// void merge (list& x, Compare comp);

			// void sort();
			// template <class Compare>
			// void sort (Compare comp);

			// void reverse();

			/* Observers */

			// allocator_type get_allocator() const;

			/* Non-member function overloads */
		

			/*
			** --------------------------------- ACCESSOR ---------------------------------
			*/



		private:
			
			Node <T>		*_node;
			Node <T>		*_start;
			Node <T>		*_finish;

			size_t			_sizeList;

			allocator_type	_alloc;
			
    }; 
}

#endif //CONT_LIST_H
