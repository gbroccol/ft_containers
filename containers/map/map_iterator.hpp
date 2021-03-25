/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:11:42 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/25 18:37:51 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include <iostream>
#include <string>

#define BLACK   1
#define RED     0

// const int RED(0);
// const int BLACK(1);

namespace ft 
{
	template < class Key, class T>
	struct			        nodeMap
	{
        std::pair <Key, T>  data;
		nodeMap		        *parent;
		nodeMap    	    	*less;
        nodeMap	    	    *more;
        bool                color;
	};

	template <class Key, class T>
	class iteratorMap 
    {
		protected: // ???

			// nodeMap <Key, T> *ptr;
            struct nodeMap <Key, T> *ptr;
			
		public: 
			
			typedef std::pair <Key, T>					value_type;
			typedef std::pair <Key, T>					&reference;
			typedef std::pair <Key, T>					*pointer;
			typedef std::ptrdiff_t 						difference_type;

			/*
			** -------------------------------- CONSTRUCTOR --------------------------------
			*/

				iteratorMap(){}
				iteratorMap(const iteratorMap &src) { *this = src; }
				iteratorMap(struct nodeMap<Key,T> &src) { ptr = src; };

				iteratorMap(struct nodeMap<Key,T> *_list) { ptr = _list; }
				
				iteratorMap &operator=( const struct nodeMap<Key,T> &x )
				{
					if (ptr != x)
					{
						ptr = x;
					}
					return ptr;
				}
				virtual ~iteratorMap() {}

			// iteratorMap() {}
			// iteratorMap(struct nodeMap <T> *src) {  ptr = src; }

			// iteratorMap(const iteratorMap &src) { *this = src; }
				
			// iteratorMap(struct nodeMap <T> &src) { ptr = src; }

			/*
			** -------------------------------- DESTRUCTOR --------------------------------
			*/

			// virtual ~iteratorMap() {}

			/*
			** --------------------------------- OVERLOAD ---------------------------------
			*/

			// iteratorMap &				operator=(iteratorMap const & rhs )
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

			// bool						operator==(const iteratorMap &x)
			// {
			// 	if (x.ptr == ptr)
			// 		return true;
			// 	return false;
			// }
			
			// bool						operator!=(const iteratorMap &x)
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
			
			// iteratorMap					&operator++() // ++a 
			// {
			// 	ptr = ptr->next;
			// 	return *this;
			// }

			// iteratorMap					&operator++(int) // a++ 
			// {
			// 	iteratorMap tmp(*this);
			// 	operator++();
			// 	return *this;
			// }
			
			// iteratorMap					&operator--()  // check
			// {
			// 	if (ptr->pre)
			// 		ptr = ptr->pre;
			// 	return *this;
			// }

			// iteratorMap					&operator--(int)  // check
			// {
			// 	iteratorMap tmp(*this);
			// 	operator--();
			// 	return *this;
			// }
			
			// nodeMap_pointer	getnext() const { return ptr->next; }
			// struct nodeMap <T>		*getpre() const { return ptr->pre; }
			// struct nodeMap <T>		*getptr() const { return ptr; }









			//-----------------------Overlodes-------------------------//
			// bool 									operator==(const iteratorMap &x)
			// {
			// 	if(ptr == x.ptr)
			// 		return(true);
			// 	return(false);
			// }
			// bool 									operator!=(const iteratorMap &x)
			// {
			// 	if(ptr != x.ptr)
			// 		return(true);
			// 	return(false);
			// }
			// value_type 								&operator*()
			// {
			// 	return (this->ptr->data);
			// }
			// const value_type 						&operator*() const
			// {
			// 	return (ptr->data);	
			// }	


			value_type &operator*()
			{
				return (ptr->data);
			}

			// std::pair<Key, T> *operator->()
			// {
			// 	return (&ptr->data);
			// }

			
			// pointer									operator->()
			// {
			// 	// return (&ptr->data);	
			// 	return (&(this->ptr->data));
			// }
			// const pointer							operator->() const
			// {
			// 	return (&ptr->data);	
			// }
			// iteratorMap							&operator++()
			// {
			// 	struct nodeMap<Key,T> tmp;
			// 	if(ptr)
			// 	{
			// 		if(ptr->more)
			// 		{
			// 			tmp = ptr->more;
			// 			while(tmp->less)
			// 				tmp = tmp->less;
			// 		}
			// 		else
			// 		{
			// 			if(ptr->less)
			// 			{
			// 				tmp = ptr->less;
			// 				while(tmp->more)
			// 					tmp = tmp->more;
			// 			}
			// 			else
			// 				return ;
			// 		}
			// 		ptr = tmp;
			// 		return (*this);
			// 	}
			// 	else
			// 		return ;
			// }
			// iteratorMap							operator++(int)
			// {
			// 	iteratorMap tmp(*this);
			// 	operator++();
			// 	return tmp;
			// }
			// iteratorMap							&operator--()
			// {
			// 	struct nodeMap<Key,T> tmp;
			// 	if(ptr)
			// 	{
			// 		if(ptr->less)
			// 		{
			// 			tmp = ptr->less;
			// 			while(tmp->more)
			// 				tmp = tmp->more;
			// 		}
			// 		else
			// 		{
			// 			if(ptr->parent)
			// 				tmp = ptr->parent;	
			// 		}
			// 		ptr = tmp;
			// 		return (*this);
			// 	}
			// 	else
			// 		return ;
			// }
			// iteratorMap							operator--(int)
			// {
			// 	iteratorMap tmp(*this);
			// 	operator--();
			// 	return tmp;
			// }
			// difference_type							operator+(iteratorMap const &other)
			// {
			// 	iteratorMap ptr;

			// 	ptr.ptr= map + n;
			// 	return (ptr);
			// }
			// difference_type						operator-(iteratorMap const &other)
			// {
			// 	return (this->ptr - other.ptr);
			// }
			// bool 									operator>(const iteratorMap &x)
			// {
			// 	return (this->ptr > x.ptr);
			// }
			// bool 									operator<(const iteratorMap &x)
			// {
			// 	return (this->ptr < x.ptr);
			// }
			// struct nodeMap<Key,T>							*getMap()
			// {
			// 	return (this->ptr);
			// }
			
    };

	// template <class T>
	// class const_iterator : public iteratorMap <T>
	// {
	// 	public:
	// 	const_iterator() {}
	// 	const_iterator(struct nodeMap <T> *list) { this->ptr = list; }
	// 	const_iterator(const const_iterator &copy) { *this = copy; }
	// 	const_iterator &operator=(const const_iterator &target)
	// 	{
	// 		this->ptr = target.ptr;
	// 		return (*this);
	// 	}
	// 	~const_iterator() {}
	// 	const T &operator*() { return (this->ptr->data); }
	// };
}

#endif