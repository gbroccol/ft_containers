/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:11:15 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/25 14:22:22 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONT_VECTOR_HPP
#define CONT_VECTOR_HPP

// # include <memory>
// # include <cstddef>
// # include "RandomAccessIterator.hpp"
// # include "ReverseIterator.hpp"
// # include "Traits.hpp"
// # include "Extra.hpp"
// # include <stdexcept>
// #include <iostream>






#include <iterator>
#include <iostream>
#include "vector_iterator.hpp"
#include "vector_reverse_iteraor.hpp"
#include "../extra.hpp"

namespace ft 
{
	template < class T, class Alloc = std::allocator<T> >
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
			typedef ft::const_reverseIteratorVector <T>			const_reverse_iterator;
			
			typedef size_t							size_type;
			


			/*
			** -------------------------------- CONSTRUCTOR --------------------------------
			*/

			explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc)
			{
				_size = 0;
				_capacity = 0;
				_vector = 0;
			}
			
			explicit vector (size_type n, const value_type& val = value_type(),
                				const allocator_type& alloc = allocator_type()) : _alloc(alloc)
			{
				_size = n;
				_capacity = n;
				_vector = _alloc.allocate(n);
				
				for (size_t i = 0; i < n; i++)
					_vector[i] = val;
			}

			template <class InputIterator>
         	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
											typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0) : _alloc(alloc)
			{
				_size = ft::distance(first, last);
				_capacity = _size;
				_vector = _alloc.allocate(_size);

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
				// delete _vector
			}

			/*
			** --------------------------------- OVERLOAD ---------------------------------
			*/

			vector& operator= (const vector& x)
			{
				clear();
				_size = x._size;
				_capacity = x._capacity;
				_vector = _alloc.allocate(_capacity);

				for (size_t i = 0; i < _size; i++)
					_vector[i] = x._vector[i];
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

			reverse_iterator rbegin() {return (reverse_iterator (&(this->_vector[this->_size])));} ;
			const_reverse_iterator rbegin() const {return (const_reverse_iterator (&(this->_vector[this->_size])));} ;
			
			reverse_iterator rend() { return (reverse_iterator (this->_vector)); }
			const_reverse_iterator rend() const  { return (const_reverse_iterator (this->_vector)); }

	/* Capacity */
	
		size_type size() const { return _size; }
		// size_type max_size() const;
		// void resize (size_type n, value_type val = value_type());
		// size_type capacity() const;
		// bool empty() const;
		// void reserve (size_type n);

	/* Element access */

		// reference operator[] (size_type n);
		// const_reference operator[] (size_type n) const;

		// reference at (size_type n);
		// const_reference at (size_type n) const;

		// reference front();
		// const_reference front() const;

		// reference back();
		// const_reference back() const;

	/* Modifiers */

			// template <class InputIterator>
			// void assign (InputIterator first, InputIterator last);
			// void assign (size_type n, const value_type& val);

			// void push_back (const value_type& val);

			// void pop_back();

			// iterator insert (iterator position, const value_type& val);
			// void insert (iterator position, size_type n, const value_type& val);

			// template <class InputIterator>
			// void insert (iterator position, InputIterator first, InputIterator last);

			// iterator erase (iterator position);
			// iterator erase (iterator first, iterator last);

			// void swap (vector& x);

			void clear()
			{
				if (this->_size == 0)
					return;
				_alloc.deallocate(_vector, _capacity);
				_size = 0;
				_capacity = 0;
				_vector = _alloc.allocate(1);
			}
			
	/* Operations */


		private:
			
			allocator_type		_alloc;
			size_type			_size;
			size_type			_capacity;
			
			pointer 			_vector;
			// pointer				_start;
			// pointer				_end;

    }; 

			/* Non-member function overloads */
			
}

#endif //CONT_VECTOR_H
