/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reverse_iterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:25:08 by gbroccol          #+#    #+#             */
/*   Updated: 2021/04/03 13:12:02 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_REVERSE_ITERATOR_HPP
#define MAP_REVERSE_ITERATOR_HPP

#include <iostream>
#include <string>

#define BLACK   1
#define RED     0

#define LAST    2
#define FIRST   3

// const int RED(0);
// const int BLACK(1);

namespace ft 
{
	template <class Key, class T>
	class map_reverse_iterator 
    {
		protected:

			nodeMap <Key, T> *ptr;
			
		public: 
			
			typedef std::pair <Key, T>					value_type;
			typedef std::pair <Key, T>					&reference;
			typedef std::pair <Key, T>					*pointer;
			typedef std::ptrdiff_t 						difference_type;

			/*
			** -------------------------------- CONSTRUCTOR --------------------------------
			*/

				map_reverse_iterator(){}
				map_reverse_iterator(const map_reverse_iterator &src) { *this = src; }
				map_reverse_iterator(struct nodeMap<Key,T> &src) { ptr = src; };

				map_reverse_iterator(struct nodeMap<Key,T> *_list) { ptr = _list; }
				
				map_reverse_iterator &operator=( const struct nodeMap<Key,T> &x )
				{
					if (ptr != x)
					{
						ptr = x;
					}
					return ptr;
				}
				virtual ~map_reverse_iterator() {}

			// map_reverse_iterator() {}
			// map_reverse_iterator(struct nodeMap <T> *src) {  ptr = src; }

			// map_reverse_iterator(const map_reverse_iterator &src) { *this = src; }
				
			// map_reverse_iterator(struct nodeMap <T> &src) { ptr = src; }

			/*
			** -------------------------------- DESTRUCTOR --------------------------------
			*/

			// virtual ~map_reverse_iterator() {}

			/*
			** --------------------------------- OVERLOAD ---------------------------------
			*/

			// map_reverse_iterator &				operator=(map_reverse_iterator const & rhs )
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

			// bool						operator==(const map_reverse_iterator &x)
			// {
			// 	if (x.ptr == ptr)
			// 		return true;
			// 	return false;
			// }
			
			// bool						operator!=(const map_reverse_iterator &x)
			// {
			// 	if (x.ptr != ptr)
			// 		return true;
			// 	return false;
			// }
			
			// value_type					&operator*()
			// {
			// 	// if (ptr == _Tail)
			// 	// 	return ptr->pre->data;
			// 	return ptr->data;
			// }
			
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
			
			// map_reverse_iterator					&operator++() // ++a 
			// {
			// 	ptr = ptr->next;
			// 	return *this;
			// }

			// map_reverse_iterator					&operator++(int) // a++ 
			// {
			// 	map_reverse_iterator tmp(*this);
			// 	operator++();
			// 	return *this;
			// }
			
			// map_reverse_iterator					&operator--()  // check
			// {
			// 	if (ptr->pre)
			// 		ptr = ptr->pre;
			// 	return *this;
			// }

			// map_reverse_iterator					&operator--(int)  // check
			// {
			// 	map_reverse_iterator tmp(*this);
			// 	operator--();
			// 	return *this;
			// }
			
			// nodeMap_pointer	getnext() const { return ptr->next; }
			// struct nodeMap <T>		*getpre() const { return ptr->pre; }
			// struct nodeMap <T>		*getptr() const { return ptr; }









			//-----------------------Overlodes-------------------------//
			// bool 									operator==(const map_reverse_iterator &x)
			// {
			// 	if(ptr == x.ptr)
			// 		return(true);
			// 	return(false);
			// }
			
			bool 									operator!=(const map_reverse_iterator &x)
			{
				if (ptr != x.ptr)
					return(true);
				return(false);
			}

			
			value_type 								&operator*()
			{
				return (this->ptr->data);
			}
			// const value_type 						&operator*() const
			// {
			// 	return (ptr->data);	
			// }	


			// value_type &operator*()
			// {
			// 	return (ptr->data);
			// }

			// std::pair<Key, T> *operator->()
			// {
			// 	return (&ptr->data);
			// }

			
			pointer									operator->()
			{
				return (&(this->ptr->data));
			}
			// const pointer							operator->() const
			// {
			// 	return (&ptr->data);	
			// }


			// map_reverse_iterator	operator++(int)
			// {
			// 	map_reverse_iterator	out(*this);
			// 	this->ptr = ptr->getnext();
			// 	return out;
			// }
			
			// map_reverse_iterator&	operator++()
			// {
			// 	this->ptr = ptr->getnext();
			// 	return *this;
			// }

			// node*   getnext() 
			// {
			// 	node* it(this);

			// 	if (it->right) {
			// 		it = it->right;
			// 		while (it->left)
			// 			it = it->left;
			// 	}
			// 	else {
			// 		node *tmp = it;
			// 		it = it->parent;
			// 		while (it->left != tmp) { //it->data <= this->data)
			// 			tmp = it;
			// 			it = it->parent;
			// 		}
			// 	}
			// 	return (it);
        	// }
			
			map_reverse_iterator							&operator++()
			{
				nodeMap <Key, T> * it = ptr;
				
				if (it->color == LAST) // extra
				{
					it = it->parent;
				}
				else if (it->left) // case 1
				{
					it = it->left;
					while (it->right)
						it = it->right;
				}
				else if (it->parent && it->data.first > it->parent->data.first) // case 2
				{
					it = it->parent;
				}
				else if (it->parent && it->parent->parent) // case 3
				{
					while (it->parent && it->data.first < it->parent->data.first)
						it = it->parent;
					it = it->parent;
				}
				else // if (it->left == nullptr) // case 4
					it = it->left;
				this->ptr = it;
				return (*this);
			}
			
			map_reverse_iterator							operator++(int)
			{
				map_reverse_iterator tmp(*this);
				operator++();
				return tmp;
			}

			map_reverse_iterator							&operator--()
			{				
				nodeMap <Key, T> * it = ptr;

				if (it->color == FIRST)
					it = it->parent;
				else if (it->right)  // case 1
				{
					it = it->right;
					while (it->left)
						it = it->left;
				}
				else if (it->parent && it->data.first < it->parent->data.first)  // case 2
					it = it->parent;
				else if (it->parent && it->parent->parent) // case 3
				{
					while (it->parent && it->data.first > it->parent->data.first)
						it = it->parent;
					it = it->parent;
				}
				else // if (it->right == nullptr) // case 4
					it = it->right;
				this->ptr = it;
				return (*this);
			}
			
			map_reverse_iterator							operator--(int)
			{
				map_reverse_iterator tmp(*this);
				operator--();
				return tmp;
			}

			std::string getColor() const
            {
				if (this->ptr->color == BLACK)
					return ("\x1b[34;1m");
				else if (this->ptr->color == LAST)
					return ("\x1b[33;1m");
				else
					return ("\x1b[31;1m");
            }

			// node_pointer	getnext() const { return ptr->next; }
			// struct Node <T>		*getpre() const { return ptr->pre; }
			nodeMap <Key, T> 		*getptr() const { return this->ptr; }
			
    };

	template < class Key, class T>
	class const_reverse_iterator_map : public map_reverse_iterator <Key, T>
	{
		public:
		const_reverse_iterator_map() {}
		const_reverse_iterator_map(struct nodeMap <Key, T> *list) { this->ptr = list; }
		const_reverse_iterator_map(const const_reverse_iterator_map &copy) { *this = copy; }
		const_reverse_iterator_map &operator=(const const_reverse_iterator_map &target)
		{
			this->ptr = target.ptr;
			return (*this);
		}
		~const_reverse_iterator_map() {}
		const T &operator*() { return (this->ptr->data); }
	};

}

#endif