/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:11:15 by gbroccol          #+#    #+#             */
/*   Updated: 2021/05/20 17:21:42 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONT_VECTOR_HPP
#define CONT_VECTOR_HPP

#include <iterator>
#include <iostream>
#include "iterator/vector_iterator.hpp"
#include "iterator/vector_reverse_iteraor.hpp"
#include "extra.hpp"
#include "allocator.hpp"

namespace ft 
{
	template < class T, class Alloc = ft::allocator<T> >
	class vector 
    { 
		public: 

			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef value_type &									reference;
			typedef const value_type &								const_reference;
			typedef value_type *									pointer;
			typedef const value_type *								const_pointer;
			typedef ft::iteratorVector <T>							iterator;
			typedef ft::const_iteratorVector <T>					const_iterator;
			typedef ft::reverseIteratorVector<T>					reverse_iterator;
			typedef ft::const_reverseIteratorVector <T>				const_reverse_iterator;
			typedef size_t											size_type;
			typedef	ptrdiff_t										difference_type;
			
			/*
			** -------------------------------- CONSTRUCTOR --------------------------------
			*/
				explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc)
				{
					_size = 0;
					_capacity = 0;
					_vector = _alloc.allocate(1); // allocate for tail
				}
				
				explicit vector (size_type n, const value_type& val = value_type(),
									const allocator_type& alloc = allocator_type()) : _alloc(alloc)
				{
					_size = n;
					_capacity = n;
					_vector = _alloc.allocate(n + 1); // + 1 for tail

					pointer tmp = _vector;
					
					for (size_t i = 0; i < n; i++)
						_alloc.construct(tmp++, val);
				}

				template <class InputIterator>
				vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
												typename ft::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0) : _alloc(alloc)
				{
					_size = ft::distance_my(first, last);
					_capacity = _size;
					_vector = _alloc.allocate(_size + 1);

					pointer tmp = _vector;

					for ( ; first != last; first++)
						_alloc.construct(tmp++, *first);

					for (int i = 0; first != last; first++)	
						_vector[i++] = *first;
				}

				vector (const vector& x) : _alloc(x._alloc), _size(0), _capacity(0), _vector(0)
				{
					*this = x;
				}
			/*
			** -------------------------------- DESTRUCTOR --------------------------------
			*/
				~vector() 
				{
					_alloc.deallocate(_vector, _capacity + 1);
				}
			/*
			** --------------------------------- OVERLOAD ---------------------------------
			*/
				vector& operator= (const vector& x)
				{
					clear();
					_size = x._size;
					_capacity = x._capacity;
					_vector = _alloc.allocate(_capacity + 1);

					pointer tmp = _vector;

					for (size_t i = 0; i < _size; i++)
						_alloc.construct(tmp++, x._vector[i]);
					return *this;
				}
			/*
			** --------------------------------- METHODS ----------------------------------
			*/

		/* Iterators */

				iterator begin() { return (iterator (this->_vector)); }
				const_iterator begin() const { return (const_iterator (this->_vector)); }

				iterator end() {return (iterator (&(this->_vector[this->_size])));} ;
				const_iterator end() const {return (const_iterator (&(this->_vector[this->_size])));} ;

				reverse_iterator rbegin() {return (reverse_iterator (&(this->_vector[this->_size - 1])));} ;
				const_reverse_iterator rbegin() const {return (const_reverse_iterator (&(this->_vector[this->_size - 1])));} ;
				
				reverse_iterator rend() { return (reverse_iterator (&(this->_vector[-1])));} ;
				const_reverse_iterator rend() const  { return (const_reverse_iterator (&(this->_vector[-1])));} ;

		/* Capacity */
		
			size_type size() const { return _size; }

			size_type max_size() const { return (std::numeric_limits<size_type>::max() / (sizeof(T))); }
			
			void resize (size_type n, value_type val = value_type())
			{
				while (_capacity < n)
				{
					if (_capacity == 0)
						reserve(1);
					else
						reserve(_capacity * 2);
				}
				
				pointer tmp = _vector + _size;

				for (size_type i = (_size); i < n; i++ )
					_alloc.construct(tmp++, val);
				_size = n;
			}

			size_type capacity() const  { return _capacity; }

			bool empty() const { return (_size == 0 ? true : false); }
			
			void reserve (size_type n)
			{
				if (n <= _capacity)
					return;
					
				pointer tmp = _alloc.allocate(n);
				pointer tmp2 = tmp;
				
				for (size_t i = 0; i < _size; i++)
					_alloc.construct(tmp2++, _vector[i]);
				
				if (_capacity)
					_alloc.deallocate(_vector, _capacity);
					
				_vector = tmp;
				_capacity = n;
			}

		/* Element access */

			reference operator[] (size_type n) { return _vector[n]; }
			const_reference operator[] (size_type n) const { return _vector[n]; }

			reference at (size_type n)
			{
				if (this->size() == 0 || n >= this->size())
					throw std::out_of_range ("out_of_range");
				return (reference)_vector[n];
			}
			const_reference at (size_type n) const
			{
				if (this->size() == 0 || n >= this->size())
					throw std::out_of_range ("out_of_range");
				return (const_reference)_vector[n];
			}

			reference front() { return (reference)_vector[0]; }
			const_reference front() const { return (const_reference)_vector[0]; }

			reference back() { return (reference)_vector[_size - 1]; }
			const_reference back() const { return (const_reference)_vector[_size - 1]; }

		/* Modifiers */
		
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
										typename ft::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
			{
				// if (checkin(begin(), end(), first) || checkin(begin(), end(), last))
				// 	return ;

				clear();
				for ( ; first != last; first++)
					push_back(*first);
			}
			
			void assign (size_type n, const value_type& val)
			{
				clear();
				resize(n, val);
			}

			void push_back (const value_type& val)
			{
				if (_capacity < _size + 1)
					resize((_size + 1), val);
				else
				{
					pointer tmp = _vector + _size;
					_alloc.construct(tmp, val);
					_size++;
				}
			}

			void pop_back() { _size--; }

			iterator insert (iterator position, const value_type& val)
			{
				pointer tmp;
				pointer posVector = position.ptr;
				int 	sum = _capacity + 1;

				if (sum < (int)(_size + 1 + 1))
					sum = sum * 2;
				tmp = _alloc.allocate(sum); // + 1 for tail
				
				size_t  i = 0;
				pointer tmp2 = tmp;
					
				for ( ; &_vector[i] != posVector; i++)
					_alloc.construct(tmp2++, _vector[i]);
						
				_alloc.construct(tmp2, val);

				tmp2++;
				int rem = i;
					
				for ( ; i != _size; i++)
					_alloc.construct(tmp2++, _vector[i]);

				_alloc.deallocate(_vector, sum);
				_capacity = sum -1;
					
				_vector = tmp;
				_size++;
					
				return iterator(&_vector[rem]);
				}
				
			void insert (iterator position, size_type n, const value_type& val)
			{
				pointer tmp;
				pointer posVector = position.ptr;
				int 	sum = _capacity + 1;

				if (sum < (int)(_size + n + 1))
				{
					while (sum < (int)(_size + n + 1))
						sum = sum * 2;
					tmp = _alloc.allocate(sum); // + 1 for tail
				}
				else
					tmp = _alloc.allocate(sum); // + 1 for tail
				
				size_t i = 0;
				
				for ( ; &_vector[i] != &posVector[0]; i++)
					_alloc.construct(&(tmp[i]), _vector[i]);

				for (size_t j = 0; j < n; j++)
					_alloc.construct(&(tmp[i + j]), val);

				for ( ; i != _size; i++)
					_alloc.construct(&(tmp[i + n]), _vector[i]);

				_alloc.deallocate(_vector, _capacity + 1);
				_capacity = sum - 1;
					
				_vector = tmp;
				_size += n;
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
													typename ft::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
			{
				pointer tmp = NULL;
				pointer posVector = position.ptr; // указатель на вектор
				size_t sum = _capacity + 1;

				int n = distance_my(first, last);
				
				if (sum < (_size + n + 1))
				{
					while (sum < (_size + n + 1))
						sum = sum * 2;
					tmp = _alloc.allocate(sum); // + 1 for tail
				}
				else
					tmp = _alloc.allocate(sum); // + 1 for tail

				size_t i = 0;
				for ( ; &_vector[i] != &posVector[0]; i++)
					_alloc.construct(&(tmp[i]), _vector[i]);

				for (size_t j = 0; first != last; j++)
				{
					_alloc.construct(&(tmp[i + j]), *(first));
					first++;
				}
				for ( ; i != _size; i++)
					_alloc.construct(&(tmp[i + n]), _vector[i]);

				_alloc.deallocate(_vector, _capacity + 1);
				_capacity = sum - 1;
					
				_vector = tmp;
				_size += n;
			}

			iterator erase (iterator position)
			{
				pointer posVector = position.ptr;
				
				size_t i = 0;
				while (&_vector[i] != &posVector[0] && i < _size)
					i++;
				
				if (i == _size)
					return iterator(&_vector[0]);

				int rem = i;
				
				while (i + 1 < _size)
				{
					_vector[i] = _vector[i + 1];
					i++;
				}
				_size--;
				
				return iterator(&_vector[rem]);
			}
			
			iterator erase (iterator first, iterator last)
			{
				pointer posVector = first.ptr;
				int dist = distance_my(first, last);
				
				size_t i = 0;
				while (&_vector[i] != &posVector[0] && i < _size)
					i++;
				
				if (i == _size)
					return iterator(&_vector[0]);

				int rem = i;
				
				while (i + dist < _size)
				{
					_vector[i] = _vector[i + dist];
					i++;
				}
					
				_size -= dist;
				return iterator(&_vector[rem]);
			}

			void swap (vector& x)
			{
				ft::itemswap(this->_alloc, x._alloc);
				ft::itemswap(this->_size, x._size);
				ft::itemswap(this->_capacity, x._capacity);
				ft::itemswap(this->_vector, x._vector);
			}

			void clear() { _size = 0; }

			private:
				
				allocator_type		_alloc;
				size_type			_size;
				size_type			_capacity;
				pointer 			_vector;

    };
	
	/* Non-member function overloads */
	
			template <class T, class Alloc>
			bool operator== (const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs)
			{
				if (lhs.size() == rhs.size())
				{
					ft::const_iteratorVector <T> it1 = lhs.begin();
					ft::const_iteratorVector <T> it2 = rhs.begin();
					
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
			bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
				return !(lhs == rhs);
			}
			
			template <class T, class Alloc>
			bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
				ft::const_iteratorVector <T> first1 = lhs.begin();
				ft::const_iteratorVector <T> first2 = rhs.begin();

				ft::const_iteratorVector <T> last1 = lhs.end();
				ft::const_iteratorVector <T> last2 = rhs.end();
				
				while (first1 != last1)
				{
					if (first2==last2 || *first2<*first1) return false;
					else if (*first1 < *first2) return true;
					++first1; ++first2;
				}
				return (first2!=last2);
			}
			
			template <class T, class Alloc>
			bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
				return (lhs == rhs || lhs < rhs);
			}
			
			template <class T, class Alloc>
			bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
				return (rhs < lhs);
			}
			
			template <class T, class Alloc>
			bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
				return (lhs == rhs || lhs > rhs);
			}

			template <class T, class Alloc>
			void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y); }
}

#endif
