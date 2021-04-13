/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reverse_iterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:25:08 by gbroccol          #+#    #+#             */
/*   Updated: 2021/04/13 18:05:51 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_REVERSE_ITERATOR_HPP
#define MAP_REVERSE_ITERATOR_HPP

#include <iostream>
#include <string>

#define BLACK   1
#define RED     0
#define LAST    2
#define FIRST	3

// const int RED(0);
// const int BLACK(1);

namespace ft 
{
	template <class Key, class T>
	class map_reverse_iterator 
    {
		public: 
			
			typedef std::pair <Key, T>					value_type;
			typedef std::pair <Key, T>					&reference;
			typedef std::pair <Key, T>					*pointer;
			typedef std::ptrdiff_t 						difference_type;

			typedef nodeMap <Key,T> *					node_pointer;
			
			nodeMap <Key, T> *ptr;

			/*
			** -------------------------------- CONSTRUCTOR --------------------------------
			*/
				map_reverse_iterator() { ptr = NULL; }
				map_reverse_iterator(const map_reverse_iterator &src) { *this = src; }
				map_reverse_iterator(const node_pointer _list) { ptr = _list; }
			/*
			** -------------------------------- DESTRUCTOR --------------------------------
			*/
				virtual ~map_reverse_iterator() {}
			/*
			** --------------------------------- OVERLOAD ---------------------------------
			*/
				map_reverse_iterator			&operator=( const struct nodeMap <Key, T> &x )
				{
					this->ptr = x.ptr;
					return *this;
				}
				
				bool							operator==(const map_reverse_iterator &x) {
					return (x.ptr == ptr) ? true : false;
				}
			
				bool							operator!=(const map_reverse_iterator &x) {
					return (x.ptr != ptr) ? true : false;
				}

				value_type 						&operator*() { return (this->ptr->data); }
				const value_type 				&operator*() const { return (this->ptr->data); }
			
				pointer							operator->() { return &ptr->data; }
				const pointer					operator->() const { return &ptr->data; }
			
				map_reverse_iterator			&operator++()
				{
					nodeMap <Key, T> * it = ptr;
					
					if (it->color == LAST)
					{
						if (it->parent)
							it = it->parent;
					}
					else if (it->left)
					{
						it = it->left;
						while (it->right)
							it = it->right;
					}
					else if (it->parent && it->data.first > it->parent->data.first)
					{
						it = it->parent;
					}
					else if (it->parent && it->parent->parent)
					{
						while (it->parent && it->data.first < it->parent->data.first)
							it = it->parent;
						it = it->parent;
					}
					else
						it = it->left;
					this->ptr = it;
					return (*this);
				}
				map_reverse_iterator			operator++(int)
				{
					map_reverse_iterator tmp(*this);
					operator++();
					return tmp;
				}

				map_reverse_iterator			&operator--()
				{
					nodeMap <Key, T> * it = ptr;

					if (it->color == FIRST)
					{
						if (it->parent)
							it = it->parent;
					}
					else if (it->right)
					{
						it = it->right;
						while (it->left)
							it = it->left;
					}
					else if (it->parent && it->data.first < it->parent->data.first) 
						it = it->parent;
					else if (it->parent && it->parent->parent)
					{
						while (it->parent && it->data.first > it->parent->data.first)
							it = it->parent;
						it = it->parent;
					}
					else
						it = it->right;
					this->ptr = it;
					return (*this);
				}
				map_reverse_iterator			operator--(int)
				{
					map_reverse_iterator tmp(*this);
					operator--();
					return tmp;
				}

				// struct nodeMap <T>		*getptr() const { return ptr; }
    };

	template < class Key, class T>
	class const_reverse_iterator_map : public map_reverse_iterator <Key, T>
	{
		public:

			const_reverse_iterator_map() { this->ptr = NULL; }
			
			const_reverse_iterator_map(const const_reverse_iterator_map &src) { *this = src; }
			const_reverse_iterator_map(const map_reverse_iterator <Key, T> &src) { *this = src; }
			const_reverse_iterator_map(nodeMap <Key, T> * node) { this->ptr = node; }
		
			const_reverse_iterator_map &operator=(const_reverse_iterator_map const &target)
			{
				this->ptr = target.ptr;
				return (*this);
			}
			const_reverse_iterator_map &operator=(map_reverse_iterator <Key, T> const &target)
			{
				this->ptr = target.ptr;
				return (*this);
			}
			~const_reverse_iterator_map() {}
	};

}

#endif
