/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:32:17 by gbroccol          #+#    #+#             */
/*   Updated: 2021/04/14 17:14:33 by gbroccol         ###   ########.fr       */
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

			typedef T										value_type;
			typedef Alloc									allocator_type;
			typedef size_t									size_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef ft::iterator<T>							iterator;
			typedef ft::const_iterator <T>					const_iterator;
			typedef ft::reverse_iterator<T>					reverse_iterator;
			typedef ft::const_reverse_iterator <T>			const_reverse_iterator;

			/*
			** -------------------------------- CONSTRUCTOR --------------------------------
			*/
		
			explicit list (const allocator_type& alloc = allocator_type()) : _Alloc(alloc)
			{
				_Tail = new Node <T> ();

				_Tail->next = _Tail;
				_Tail->pre  = _Tail;
				_size = 0;
				_Node = _Tail;
			}
			
			explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _Alloc(alloc)
			{
				_Tail = new Node <T> ();

				_Tail->next = _Tail;
				_Tail->pre  = _Tail;

				_size = 0;

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
				_size = 0;
				for ( ; first != last; first++)
					push_back(first.ptr->data);
				_Node = _Tail->next;
			}

			list (const list& x)
			{
				_Tail = new struct Node <T>;
				_Tail->pre  = _Tail;
				_Tail->next = _Tail;
				_size = 0;
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
				if (this->size() > 0)
					clear();
				
				struct Node <T> *list_tmp = x._Tail->next;
				if (x.size() > 0)
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

			bool empty() const
			{
				return (size() == 0 ? true : false);
			}
			
			size_type size() const
			{
				return _size;
			}
			size_type max_size() const
			{
				return (std::numeric_limits<size_type>::max() / (sizeof(Node <T>)));
			}

	/* Element access */

			reference front() { return this->_Tail->next->data; }
			const_reference front() const { return this->_Tail->next->data; }

			reference back() { return this->_Tail->pre->data; }
			const_reference back() const { return this->_Tail->pre->data; }

	/* Modifiers */

			template <class InputIterator>
 			void assign (InputIterator first, InputIterator last,
						typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
			{
				clear();
				for ( ; first != last; first++)
					push_back(*first);
			}
			
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

				_size++;
			}
			
			void pop_front()
			{
				Node <T> *tmp = _Tail->next;
				if(size() == 1)
				{
					_Tail->next = _Tail;
					_Tail->pre = _Tail;
				}
				else
				{
					_Tail->next = tmp->next;
					tmp->next->pre = _Tail;
				}
				delete tmp;

				_size--;
			}

			void push_back(const T &val)
			{
				Node <T> * tmp = new Node< T>;          
				tmp->data = val;
				
				if(size() == 0)
				{
					_Tail->next  = tmp;
					_Tail->pre  = tmp;
					tmp->next = _Tail;
					tmp->pre = _Tail;
				}
				else
				{
					tmp->pre  = _Tail->pre;
					tmp->next = _Tail;
					_Tail->pre->next = tmp;
					_Tail->pre = tmp;
				}
				_size++;
			}

			void pop_back()
			{
				Node <T> *tmp  = _Tail->pre;
				if (size() == 1)
                {
                    _Tail->pre = _Tail;
                    _Tail->next = _Tail;
                }
                else
                {
                    _Tail->pre = _Tail->pre->pre;
                    _Tail->pre->next =_Tail;
                }
				delete tmp;
				_size--;
			}

			iterator insert (iterator position, const value_type& val) // insert before position
			{
				Node <T> * newElem = new Node <T>();
				newElem->data = val;
				
				newElem->pre  = position.ptr->pre;
				newElem->next = position.ptr;
				
				newElem->pre->next  = newElem;
				newElem->next->pre  = newElem;
				_size++;
				return iterator(newElem);
			}
		
			void insert (iterator position, size_type n, const value_type& val)
			{
				for ( ; n > 0; n--)
					insert(position, val);
			}

			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last,
						typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
			{
				for ( ; first != last; first++)
					insert(position, first.ptr->data);
			}

			iterator erase (iterator position)
			{
				if (size() > 0)
				{
					Node <T> *delElem = position.ptr;
					
					delElem->pre->next = delElem->next;
					delElem->next->pre = delElem->pre;
					position++;
					delete delElem;
					_size--;
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
				ft::itemswap(this->_size, x._size);
			}

			void resize (size_type n, value_type val = value_type())
			{
				while (size() < n)
					push_back(val);
				while (size() > n)
					pop_back();
			}
			
			void clear()
			{
				while (size() > 0)
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
					
				Node <T> * firstNodeX = first.ptr;
				Node <T> * lastNodeX = last.ptr;

				int	diff = ft::distance(first, last);

				x._size -= diff;
				_size += diff;

				Node <T> * WhereAdd = position.ptr;
				Node <T> * lastelemx = lastNodeX->pre;

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
					node = tmp.ptr;
					if (node->data == val)
					{
						node->pre->next = node->next;
						node->next->pre = node->pre;
						_size--;
						delete node;
					}
				}
			}

			template <class Predicate>
			void remove_if (Predicate pred)
			{
				iterator tmp = begin();
				
				while (tmp != end())
				{
					if (pred(*tmp) == true)
						tmp = erase(tmp);
					else
						tmp++;
				}
			}

			void unique()
			{
				iterator tmp = this->begin();

				Node <T> * node;

				tmp++;
				
				for ( ; tmp != this->end(); tmp++)
				{
					node = tmp.ptr;
					if (node->data == node->pre->data)
					{
						node->pre->next = node->next;
						node->next->pre = node->pre;
						_size--;
						delete node;
					}
				}
			}

			template <class BinaryPredicate>
			void unique (BinaryPredicate binary_pred)
			{
				iterator it = begin();
				it++;
				while (it != end())
				{
					if (binary_pred(*it, it.ptr->pre->data))
						it = erase(it);
					else
						it++;
				}
			}
			
			void merge (list& x)
			{
				if (&x == this)
					return ;

				iterator it = begin();
				iterator itx = x.begin();

				while (it != end() && itx != x.end())
				{
					while (itx != x.end() && *it > *itx)
					{
						insert(it, itx.ptr->data);
						itx++;
					}
					it++;
				}
				if (itx != x.end())
					this->splice(end(), x, itx, x.end());
				x.clear();
			}

			template <class Compare>
			void merge (list& x, Compare comp)
			{
				if (&x == this)
					return ;

				iterator it = begin();
				iterator itx = x.begin();

				while (it != end() && itx != x.end())
				{
					while (itx != x.end() && comp(*itx, *it))
					{
						insert(it, itx.ptr->data);
						itx++;
					}
					it++;
				}
				if (itx != x.end())
				{
					this->splice(end(), x, itx, x.end());
				}
				x.clear();
			}

			void sort()
			{
				iterator itEnd = end();
				itEnd--;
				quickSort(begin(), itEnd);

				// iterator it = begin();
				// it++;
				
				// while (it != end())
				// {
				// 	if (*it < it.ptr->pre->data)
				// 	{
				// 		ft::itemswap(it.ptr->data, it.ptr->pre->data);
				// 		it = begin();
				// 	}
				// 	it++;
				// }
			}
			
			template <class Compare>
			void sort (Compare comp)
			{
				iterator it = begin();
				it++;
				
				while (it != end())
				{
					if (comp(*it, it.ptr->pre->data))
					{
						ft::itemswap(it.ptr->data, it.ptr->pre->data);
						it = begin();
					}
					it++;
				}
			}

			void reverse()
			{
				iterator itBegin = begin();
				iterator itEnd = end();

				while (itBegin != itEnd)
				{
					ft::itemswap(itBegin.ptr->data, itEnd.ptr->pre->data);
					
					itBegin++;
					if (itBegin == itEnd)
						break ;
						
					itEnd--;
					if (itBegin == itEnd)
						break ;

				}
			}

		private:
			
			Node <T>		*_Node;
			Node <T>		*_Tail;
			allocator_type	_Alloc;

			size_t			_size;

			void quickSort(iterator min, iterator max)
			{
				iterator i = min;
				iterator j = max;
				iterator middle = min;
				size_t len = 0;

				for ( ; middle != j; middle++)
					len++;
				len = len / 2;
				
				middle = min;
				for (size_t ind = 0; ind < len; ind++)
					middle++;
	
				while (i.ptr <= j.ptr)
				{
					while (*i < *middle)
						i++;
					while (*j > *middle)
						j--;		
					
					if (i.ptr <= j.ptr)
					{
						ft::itemswap(i.ptr->data, j.ptr->data);
						i++;
						j--;
					}
				}
				if (j.ptr > min.ptr)
					quickSort(min, j);
				if (i.ptr < max.ptr)
					quickSort(i, max);
			}
			
    }; 

			/* Non-member function overloads */
			
			template <class T, class Alloc>
			bool operator== (const ft::list <T, Alloc> & lhs, const ft::list <T, Alloc> & rhs)
			{
				if (lhs.size() == rhs.size())
				{
					iterator <T> it1 = lhs.begin();
					iterator <T> it2 = rhs.begin();
					
					while (it1 != lhs.end())
					{
						if (*it1 != *it2)
							return false;
						it1++;
						it2++;
					}
					return true;
				}
				return false;
			}

			template <class T, class Alloc>
			bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
			{
				return !(lhs == rhs);
			}

			template <class T, class Alloc>
			bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
			{
				if (lhs.size() == 0)
					return true;
				else if (rhs.size() == 0)
					return false;
				else if (lhs.size() < rhs.size())
					return true;
				else
				{
					iterator <T> it1 = lhs.begin();
					iterator <T> it2 = rhs.begin();
						
					while (it1 != lhs.end() && it2 != rhs.end())
					{
						if (*it1 < *it2)
							return true;
						else if (*it1 > *it2)
							return false;
						it1++;
						it2++;
					}
				}
				return false;
			}

			template <class T, class Alloc>
			bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
			{
				if (lhs.size() == 0)
					return false;
				else if (rhs.size() == 0)
					return true;
				else if (lhs.size() > rhs.size())
					return false;
				else
				{
					iterator <T> it1 = lhs.begin();
					iterator <T> it2 = rhs.begin();
						
					while (it1 != lhs.end() && it2 != rhs.end())
					{
						if (*it1 > *it2)
							return true;
						else if (*it1 < *it2)
							return false;
						it1++;
						it2++;
					}
				}
				return false;
			}

			template <class T, class Alloc>
			bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) 
			{
				return (lhs == rhs || lhs < rhs);
			}

			template <class T, class Alloc>
			bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
			{
				return (lhs == rhs || lhs > rhs);
			}

			template <class T, class Alloc>
			void swap (list<T, Alloc> & x, list<T, Alloc> & y) { x.swap(y); }
}

#endif //CONT_LIST_H
