/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:32:17 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/16 20:56:32 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONT_LIST_HPP
#define CONT_LIST_HPP

#include <iterator>
#include <iostream>
#include "list_iterator.hpp"
#include "list_reverse_iterator.hpp"
#include "../extra.hpp"

namespace ft 
{
	template < class T, class Alloc = std::allocator<T> >
	class list 
    { 
		public: 
			
			typedef ft::iterator<T>					iterator;
			typedef ft::const_iterator <T>			const_iterator;

			typedef ft::reverse_iterator<T>			reverse_iterator;
			typedef ft::const_reverse_iterator <T>			const_reverse_iterator;
			
			// typedef ft::reverse_iterator<T>			reverse_iterator;
			// typedef const ft::reverse_iterator<T>	const_reverse_iterator;
			
			typedef T						value_type;
			typedef Alloc					allocator_type;
			typedef size_t					size_type;
			typedef value_type&				reference;
			// typedef const value_type&		const_reference;
			// typedef value_type*				pointer;
			// typedef const value_type*		const_pointer;
			// typedef ptrdiff_t				difference_type;

			/*
			** -------------------------------- CONSTRUCTOR --------------------------------
			*/
		
			explicit list (const allocator_type& alloc = allocator_type()) : _Alloc(alloc)
			{
				_Tail = new Node <T> ();

				_Tail->next = _Tail;
				_Tail->pre  = _Tail;
				_Tail->data = 0;
				
				_Node = _Tail;
			}
			
			explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _Alloc(alloc)
			{
				_Tail = new Node <T> ();

				_Tail->next = _Tail;
				_Tail->pre  = _Tail;
				_Tail->data = 0;
				
				for ( ; n; n--)
					push_back(val);
					
				_Node = _Tail->next;
			}
			
			template <class InputIterator>
			list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
											typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0) : _Alloc(alloc)
			{
				_Tail = new Node <T> ();
				_Tail->next = _Tail;
				_Tail->pre  = _Tail;
				_Tail->data = 0;

				for ( ; first != last; first++)
					push_back(first.getptr()->data);
				_Node = _Tail->next;
			}

			list (const list& x)
			{
				_Tail = new struct Node <T>;
				_Tail->pre  = _Tail;
				_Tail->next = _Tail;
				*this = x;
				return ;
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

			list&         operator=(const list& x)
			{
				_Tail->data = 0;
				
				struct Node <T> *list_tmp = x._Tail->next;
				if (x._Tail->data > 0)
				{
					while (list_tmp != x._Tail)
					{
						push_back(list_tmp->data);
						list_tmp = list_tmp->next;
					}
				}
				return *this;
			}
			
			/*
			** --------------------------------- METHODS ----------------------------------
			*/

	/* Iterators */

			iterator begin() { return (iterator (_Tail->next)); }
			const_iterator begin() const { return (const_iterator (_Tail->next)); }

			iterator end() { return (iterator (_Tail)); }
			const_iterator end() const { return (const_iterator (_Tail)); }

			reverse_iterator rbegin() { return (reverse_iterator (_Tail->pre)); }
			const_reverse_iterator rbegin() const { return (const_reverse_iterator (_Tail->pre)); }

			reverse_iterator rend(){ return (reverse_iterator (_Tail)); } 
			const_reverse_iterator rend() const { return (const_reverse_iterator (_Tail)); }

	/* Capacity */

			bool empty() const { return (_Tail->data == 0 ? true : false); }
			size_type size() const { return (size_t)_Tail->data; }
			size_type max_size() const { return (std::numeric_limits<size_type>::max() / (sizeof(Node <T>))); }

	/* Element access */

			reference front() { return this->_Tail->next->data; }
			// const_reference front() const { return this->_Tail->next->data; }

			reference back() { return this->_Tail->pre->data; }
			// const_reference back() const { return this->_Tail->pre->data; }

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

				
				// _Tail->data = ((int)_Tail->data + 1);
				_Tail->data++;
			}
			
			void pop_front()
			{
				if (_Tail->data) // ???
				{
					Node <T> *tmp = _Tail->next;

					_Tail->next = tmp->next;
					tmp->next = _Tail;
					
					delete tmp;
					// _SizeList--;
					_Tail->data = ((int)_Tail->data - 1);
				}	
			}


			void          push_back(const T &val)
			{
				Node <T> * tmp = new Node< T>;          
				tmp->data = val;
				
				if(_Tail->data == 0)
				{
					_Tail->next  = tmp;
					_Tail->pre  = tmp;
					tmp->next = _Tail;
					tmp->pre = _Tail;
					_Tail->data++;
					// _Tail->data = _list_size;
				}
				else
				{
					tmp->pre  = _Tail->pre;
					tmp->next = _Tail;
					_Tail->pre->next = tmp;
					_Tail->pre = tmp;
					_Tail->data++;
					// _tail_lst->data = _list_size;
				}
			}


			// void push_back (const value_type& val)
			// {
			// 	Node <T> *tmp = new Node <T>();

			// 	tmp->data = val;
				
			// 	tmp->next = _Tail;
			// 	tmp->pre  = _Tail->pre;
				
			// 	_Tail->pre->next = tmp;
			// 	_Tail->pre = tmp;

			// 	_Tail->pre = tmp;
				
			// 	// _SizeList++;
			// 	_Tail->data = ((int)_Tail->data + 1);
			// }

			void pop_back()
			{
				if (_Tail->data)
				{
					Node <T> *tmp = _Tail->pre;

					_Tail->pre->pre->next =  _Tail;
					_Tail->pre = _Tail->pre->pre;
					
					delete tmp;
					// _SizeList--;
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
				
				// _SizeList++;
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
			// void insert (iterator position, iterator first, iterator last);

			iterator erase (iterator position)
			{
				if (_Tail->data)
				{
					Node <T> *delElem = position.getptr();
					
					delElem->pre->next = delElem->next;
					delElem->next->pre = delElem->pre;

					position++;
					
					delete delElem;
					
					// _SizeList--;
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
				ft::itemswap(this->_Alloc, x._Alloc);
			}

			void resize (size_type n, value_type val = value_type())
			{
				while (_Tail->data < (T)n)
					push_back(val);
				while (_Tail->data > (T)n)
					pop_back();
			}
			
			void clear()
			{
				while (_Tail->data)
					pop_back();
			}

	/* Operations */

			void splice (iterator position, list& x)
			{
				splice(position, x, x.begin(), x.end());
			}
			
			void splice (iterator position, list& x, iterator i)
			{
				iterator next(i);
				this->splice(position, x, i, ++next);
			}
			
			void splice (iterator position, list& x, iterator first, iterator last)
			{
				if (checkin(x.begin(), x.end(), first) == false)
					return ;
					
				/* find first and last Nodes to ADD THEM */
				Node <T> * firstNodeX = first.getptr();
				Node <T> * lastNodeX = last.getptr();

				/* change Size */
				int	diff = ft::distance(first, last);
				x._Tail->data -= diff;
				this->_Tail->data += diff;
				// x._SizeList -= diff;
				// this->_SizeList += diff;

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

						this->_Tail->data--;
					
						delete node;
					}
				}
			}

			// template <class BinaryPredicate>
			// void unique (BinaryPredicate binary_pred);

			void merge (list& x)
			{
				if (&x == this)
					return ;
				
				iterator it = begin();
				iterator itx = x.begin();
					
				while (it != end() && itx != x.end())
				{
					// std::cout << "1" << std::endl;
					while (itx != x.end() && *it > *itx)
					{
						itx++;
						// std::cout << "2" << std::endl;
					}
					// std::cout << "------------------>>>>>>>>>>" << *it << std::endl;
					this->splice(it, x, x.begin(), itx);
					it++;
				}
				it = end();
				if (itx != x.end())
				{
					this->splice(it, x, x.begin(), x.end());
				}
				
				// std::cout << "1. Size = " << x._Tail->data << "2. Size = " << _Tail->data << std::endl;
				
				this->_Tail->data += x._Tail->data;
				x._Tail->data = 0;
				// std::cout << "end" << std::endl;
			}

			// template <class Compare>
			// void merge (list& x, Compare comp);

			void	swap(Node <T> *first, Node <T> *second)
			{

				// std::cout << "01. first " << first->data << " second " << second->data << std::endl;
				
				if (first == second)
					return ;
				
				Node <T> *tmp = first;

				std::cout << "tmp data " << tmp->data << std::endl;
				std::cout << "first data " << first->data << std::endl;
				std::cout << "second data " << second->data << std::endl;
				
					first->next = second->next;
					first->pre = second;

					tmp->pre->next = second;
					
					second->next->pre = first;

					second->next = first;
					second->pre = tmp->pre;
			}

			void sort()
			{
				iterator it = begin();
				it++;
				
				while (it != end())
				{

					std::cout << "pre - " << it.getpre()->data << " next - " << *it << std::endl;

					// getchar();
					
					if (*it < it.getpre()->data)
					{
						// std::cout << "01. first " << first->data << " second " << second->data << std::endl;

						
						this->swap(it.getpre(), it.getptr());
						// ft::itemswap(it.getptr()->data, it.getpre()->data); // swap nodes
						it = begin();
						// std::cout << "Begin " << it.getptr()->data << std::endl;
					}
					it++;
				}
			}
			
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
			allocator_type	_Alloc;
			
    }; 
}

#endif //CONT_LIST_H
