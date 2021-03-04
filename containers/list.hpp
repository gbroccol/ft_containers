/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:32:17 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/03 19:49:40 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONT_LIST_HPP
#define CONT_LIST_HPP

#include <iostream>
#include "list_iterator.hpp"
#include "extra.hpp"

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
				_Tail = new Node <T> ();

				_Tail->next = _Tail;
				_Tail->pre  = _Tail;
				_Tail->data = 0;
				
				_Node = _Tail;
			}
			
			explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _SizeList(0), _Alloc(alloc)
			{
				_Tail = new Node <T> ();

				_Tail->next = _Tail;
				_Tail->pre  = _Tail;
				_Tail->data = 0;
				
				for ( ; n; n--)
					push_back(val);
					
				_Node = _Tail->next;
			}
			
			// template <class InputIterator>
			// list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			
			list (const list& x) : _SizeList(0), _Alloc(x._Alloc)
			{
				_Tail = new Node <T> ();
				
				_Tail->next = _Tail;
				_Tail->pre  = _Tail;
				_Tail->data = 0;
				
				_Node = _Tail->next;

				Node <T> *tmp = x._Tail->next;
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

			iterator begin() { return (iterator (_Tail->next)); }
			const_iterator begin() const { return (iterator (_Tail->next)); }

			iterator end() { return (iterator (_Tail)); }
			const_iterator end() const { return (iterator (_Tail)); }

			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;

			// reverse_iterator rend();
			// const_reverse_iterator rend() const;

	/* Capacity */

			bool empty() const { return (_SizeList == 0 ? true : false); }
			size_type size() const { return (size_t)_Tail->data; } // { return _SizeList; }
			// size_type max_size() const;

	/* Element access */

			reference front() { return this->_Tail->next->data; }
			const_reference front() const { return this->_Tail->next->data; }

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

				tmp->pre = _Tail;
				tmp->next = _Tail->next;

				_Tail->next->pre = tmp;
				_Tail->next = tmp;

				_Tail->next = tmp;

				_SizeList++;
				_Tail->data = ((int)_Tail->data + 1);
			}
			
			void pop_front()
			{
				if (_SizeList)
				{
					Node <T> *tmp = _Tail->next;

					_Tail->next = tmp->next;
					tmp->next = _Tail;
					
					delete tmp;
					_SizeList--;
					_Tail->data = ((int)_Tail->data - 1);
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

				_Tail->pre = tmp;
				
				_SizeList++;
				_Tail->data = ((int)_Tail->data + 1);
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
					_Tail->data = ((int)_Tail->data - 1);
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
				_Tail->data = ((int)_Tail->data + 1);
				
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
					_Tail->data = ((int)_Tail->data - 1);
				}
				return position;
			}

			iterator erase (iterator first, iterator last)
			{
				for ( ; first != last; first++)
					erase(first);
				return first;
			}

			void swap (list & x)
			{
				ft::itemswap(this->_Node, x._Node);
				ft::itemswap(this->_Tail, x._Tail);
				ft::itemswap(this->_SizeList, x._SizeList);
				ft::itemswap(this->_Alloc, x._Alloc);
			}

			void resize (size_type n, value_type val = value_type())
			{
				while (_SizeList < n)
					push_back(val);
				while (_SizeList > n)
					pop_back();
			}
			
			void clear()
			{
				while (_SizeList)
					pop_back();
			}

	/* Operations */

			void splice (iterator position, list& x)
			{
				splice(position, x, x.begin(), x.end());
			}
			
			void splice (iterator position, list& x, iterator i)
			{
				if (position.getptr() == i.getptr())					// ???
					return ;
				iterator next(i);
				this->splice(position, x, i, ++next);
			}
			
			void splice (iterator position, list& x, iterator first, iterator last)
			{
				/* find first and last Nodes to ADD THEM */
				Node <T> * firstNodeX = first.getptr();
				Node <T> * lastNodeX = last.getptr();

				/* change Size */
				int	diff = ft::distance(first, last);
				x._SizeList -= diff;
				this->_SizeList += diff;

				x._Tail->data -= diff;
				this->_Tail->data += diff;

				Node <T> * WhereAdd = position.getptr();
				Node <T> * lastelemx = lastNodeX->pre; // ??? tmp	

				firstNodeX->pre->next = lastNodeX;
				lastNodeX->pre = firstNodeX->pre;
				
				WhereAdd->pre->next = firstNodeX;
				firstNodeX->pre = WhereAdd->pre;


				WhereAdd->pre = lastelemx;
				lastelemx->next = WhereAdd;
			}
		
			void remove (const value_type& val)
			{
				iterator tmp = this->begin();

				Node <T> * node;
				
				for ( ; tmp != this->end(); tmp++)
				{
					node = tmp.getptr();
					if (node->data == val)
					{
						node->pre->next = node->next;
						node->next->pre = node->pre;

						_SizeList--;
						this->_Tail->data--;
					
						delete node;
					}
				}
			}

			// template <class Predicate>
			// void remove_if (Predicate pred);

			void unique()
			{
				iterator tmp = this->begin();

				Node <T> * node;

				tmp++;
				
				for ( ; tmp != this->end(); tmp++)
				{
					node = tmp.getptr();
					if (node->data == node->pre->data)
					{
						node->pre->next = node->next;
						node->next->pre = node->pre;

						_SizeList--;
						this->_Tail->data--;
					
						delete node;
					}
				}
			}

			// template <class BinaryPredicate>
			// void unique (BinaryPredicate binary_pred);

			void merge (list& x)
			{
				if (&x != this)
				{





					// iterator it = begin();
					// iterator xit = x.begin();

					// while (it != end() && xit != x.end())
					// {
					// 	while (it != end() && !comp(*xit, *it))
					// 		++it;
					// 	++xit;
					// 	this->splice(it, x, xit.getprev());
					// }
					// if (xit != x.end())
					// 	this->splice(it, x, xit, x.end());
				}
			}



					// Node <T> *whereAdd		= this->begin().getptr();		// 1

					// Node <T> *newNode		= x.begin().getptr();			// 1
					// Node <T> *newNodeEnd	= x.end().getptr(); 

					// Node <T> *tmp;

					// while (newNodeEnd->data > 0)
					// {
					// 	std::cout << "size is " << newNodeEnd->data << std::endl;

					// 	if (newNode->data <= whereAdd->data)
					// 	{
					// 		std::cout << "LET'S ADD" << std::endl;

					// 		tmp = newNode;

					// 		/* change list x */ 
					// 		newNode->pre->next = newNode->next;
					// 		newNode->next->pre = newNode->pre;

					// 		delete tmp;

					// 		// newNode->pre = whereAdd->pre;
							
					// 		// whereAdd->pre = newNode;

					// 		// // newNode->pre->next = newNode->next;
					// 		// // newNode->next = newNode->pre->next;

					// 		// newNode->next = whereAdd;

							
					// 		// this->end().getptr()->next = newNode;
						

					// 	}
					// 	// else
					// 	// {
							
					// 	// }

					// 		/* change size */
					// 		newNodeEnd->data--;
					// 		this->end().getptr()->data++;

					// 		newNode = x.begin().getptr();
					// 		whereAdd = whereAdd->next;

				// 	}
				// }
			// }

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
			Node <T>		*_Tail;

			size_t			_SizeList;

			allocator_type	_Alloc;
			
    }; 
}

#endif //CONT_LIST_H
