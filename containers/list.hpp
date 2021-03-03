/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:32:17 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/03 14:08:21 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONT_LIST_HPP
#define CONT_LIST_HPP

#include <iostream>
#include "list_iterator.hpp"

// #include <string>
// #include <cassert>
// #include <algorithm>


// # include <limits>
// # include <memory>
// # include <cstddef>
// # include <iostream>




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
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			// typedef value_type*				pointer;
			// typedef const value_type*		const_pointer;
			// typedef ptrdiff_t				difference_type;

			/*
			** -------------------------------- CONSTRUCTOR --------------------------------
			*/
		
			explicit list (const allocator_type& alloc = allocator_type()) : _SizeList(0), _Alloc(alloc)
			{
				this->_Head = new Node <T> ();
				this->_Tail = new Node <T> ();

				this->_Head->next = this->_Tail;
				this->_Head->pre  = this->_Tail;

				this->_Tail->next = this->_Head;
				this->_Tail->pre  = this->_Head;
				
				this->_Node = this->_Head;
			}
			
			explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _SizeList(0), _Alloc(alloc)
			{
				this->_Head = new Node <T> ();
				this->_Tail = new Node <T> ();
				
				this->_Head->next = this->_Tail;
				this->_Head->pre  = this->_Tail;

				this->_Tail->next = this->_Head;
				this->_Tail->pre  = this->_Head;

				for ( ; n; n--)
					push_back(val);
				
				this->_Node = this->_Head;
			}
			
			// template <class InputIterator>
			// list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			
			list (const list& x) : _SizeList(0), _Alloc(x._Alloc)
			{
				this->_Head = new Node <T> ();
				this->_Tail = new Node <T> ();
				
				this->_Head->next = this->_Tail;
				this->_Head->pre  = this->_Tail;

				this->_Tail->next = this->_Head;
				this->_Tail->pre  = this->_Head;
				
				this->_Node = this->_Head;

				Node <T> *tmp = x._Head->next;
				for (size_t i = 0; i < x._SizeList; i++)
				{
					push_back(tmp->data);
					tmp = tmp->next;
				}
			}
	
			/*
			** -------------------------------- DESTRUCTOR --------------------------------
			*/

			~list()
			{
				clear();
				delete _Head;
				delete _Tail;
			}

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

			iterator begin() { return (iterator (_Head->next)); }
			const_iterator begin() const { return (iterator (_Head->next)); }

			iterator end() { return (iterator (_Tail)); }
			const_iterator end() const { return (iterator (_Tail)); }

			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;

			// reverse_iterator rend();
			// const_reverse_iterator rend() const;

	/* Capacity */

			bool empty() const { return (_SizeList == 0 ? true : false); }
			size_type size() const { return _SizeList; }
			// size_type max_size() const;

	/* Element access */

			reference front() { return this->_Head->next->data; }
			const_reference front() const { return this->_Head->next->data; }

			reference back() { return this->_Tail->pre->data; }
			const_reference back() const { return this->_Tail->pre->data; }

	/* Modifiers */

			// template <class InputIterator>
			// void assign (InputIterator first, InputIterator last)
			// {
				
			// }
			void assign (size_type n, const value_type& val)
			{
				clear();
				for ( ; n; n--)
					push_back(val);
			}

			void push_front (const value_type& val)
			{
				Node <T> *tmp = new Node <T>();

				tmp->data = val;

				tmp->pre = _Head;
				tmp->next = _Head->next;

				_Head->next->pre = tmp;
				_Head->next = tmp;

				_Tail->next = tmp;

				_SizeList++;
			}
			
			void pop_front()
			{
				if (_SizeList)
				{
					Node <T> *tmp = _Head->next;

					_Head->next = tmp->next;
					tmp->next = _Head;
					
					delete tmp;
					_SizeList--;
				}	
			}

			void push_back (const value_type& val)
			{
				Node <T> *tmp = new Node <T>();

				tmp->data = val;
				
				tmp->next = _Tail;
				tmp->pre  = _Tail->pre;
				
				_Tail->pre->next = tmp;
				_Tail->pre = tmp;

				_Head->pre = tmp;
				
				_SizeList++;
			}

			void pop_back()
			{
				if (_SizeList)
				{
					Node <T> *tmp = _Tail->pre;

					_Tail->pre->pre->next =  _Tail;
					_Tail->pre = _Tail->pre->pre;
					
					delete tmp;
					_SizeList--;
				}		
			}

			iterator insert (iterator position, const value_type& val) // insert before position
			{
				Node <T> * newElem = new Node <T>();
				newElem->data = val;
				
				newElem->pre  = position.getptr()->pre;
				newElem->next = position.getptr();
				
				newElem->pre->next  = newElem;
				newElem->next->pre  = newElem;
				
				_SizeList++;
				
				return iterator(newElem);
			}
			
			void insert (iterator position, size_type n, const value_type& val)
			{
				for ( ; n > 0; n--)
					insert(position, val);
			}
			
			// template <class InputIterator>
			// void insert (iterator position, InputIterator first, InputIterator last);

			iterator erase (iterator position)
			{
				if (_SizeList > 0)
				{
					Node <T> *delElem = position.getptr();
					
					delElem->pre->next = delElem->next;
					delElem->next->pre = delElem->pre;

					position++;
					
					delete delElem;
					
					_SizeList--;
				}
				return position;
			}

			iterator erase (iterator first, iterator last)
			{
				for ( ; first != last; first++)
					erase(first);
				return first;
			}

			// void swap (list& x)
			// {
				
			// }

			// void resize (size_type n, value_type val = value_type());
			
			void clear()
			{
				while (_SizeList)
					pop_back();
			}

			void print() // delete
			{
				Node <T> *tmp = _Head->next;
				std::cout << "Data: ";
				for (size_t i = 0; i < _SizeList; i++)
				{
					std::cout << tmp->data << ", ";
				}
				std::cout << std::endl;
			}

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
			
			Node <T>		*_Node;
			Node <T>		*_Head;
			Node <T>		*_Tail;

			size_t			_SizeList;

			allocator_type	_Alloc;
			
    }; 
}

#endif //CONT_LIST_H
