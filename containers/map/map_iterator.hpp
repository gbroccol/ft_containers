/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:11:42 by gbroccol          #+#    #+#             */
/*   Updated: 2021/04/13 18:05:21 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include <iostream>
#include <string>

#define BLACK   1
#define RED     0

#define FIRST	3
#define LAST    2

// const int RED(0);
// const int BLACK(1);

namespace ft 
{
	template < class Key, class T>
	struct			        nodeMap
	{
        std::pair <Key, T>  data;
		nodeMap		        *parent;
		nodeMap    	    	*left;
        nodeMap	    	    *right;
		
        int                color;
	};

	template <class Key, class T>
	class iteratorMap 
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
				iteratorMap() { ptr = NULL; }
				iteratorMap(const iteratorMap &src) { *this = src; }
				iteratorMap(const node_pointer _list) { ptr = _list; }
			/*
			** -------------------------------- DESTRUCTOR --------------------------------
			*/
				virtual ~iteratorMap() {}
			/*
			** --------------------------------- OVERLOAD ---------------------------------
			*/
				iteratorMap					&operator=( const struct nodeMap <Key, T> &x )
				{
					this->ptr = x.ptr;
					return *this;
				}
				
				bool						operator==(const iteratorMap &x)
				{
					if (x.ptr == ptr)
						return true;
					return false;
				}
			
				bool						operator!=(const iteratorMap &x)
				{
					if (x.ptr != ptr)
						return true;
					return false;
				}

				value_type 					&operator*() { return (this->ptr->data); }
				const value_type 			&operator*() const { return (this->ptr->data); }
			
				pointer						operator->() { return &ptr->data; }
				const pointer				operator->() const { return &ptr->data; }
			
				iteratorMap					&operator++()
				{
					nodeMap <Key, T> * it = ptr;

					if (it->right)
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
				iteratorMap					operator++(int)
				{
					iteratorMap tmp(*this);
					operator++();
					return tmp;
				}

				iteratorMap					&operator--()
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
				iteratorMap					operator--(int)
				{
					iteratorMap tmp(*this);
					operator--();
					return tmp;
				}

				// struct nodeMap <T>		*getptr() const { return ptr; }
    };

	template < class Key, class T>
	class const_iterator_map : public iteratorMap <Key, T>
	{
		public:

			const_iterator_map() { this->ptr = NULL; }
			
			const_iterator_map(const const_iterator_map &src) { *this = src; }
			const_iterator_map(const iteratorMap <Key, T> &src) { *this = src; }
			const_iterator_map(nodeMap <Key, T> * node) { this->ptr = node; }
		
			const_iterator_map &operator=(const_iterator_map const &target)
			{
				this->ptr = target.ptr;
				return (*this);
			}
			const_iterator_map &operator=(iteratorMap <Key, T> const &target)
			{
				this->ptr = target.ptr;
				return (*this);
			}
			~const_iterator_map() {}
	};

}

#endif