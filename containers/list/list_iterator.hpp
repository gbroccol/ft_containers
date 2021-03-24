/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:57:07 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/24 18:52:48 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP

#include <iostream>
#include <string>

namespace ft 
{
	template < typename T>
	struct			Node
	{
		T			data;
		Node		*pre;
		Node		*next;
	};

	// template <	class Category,              // iterator::iterator_category
	// 			class T,                     // iterator::value_type
	// 			class Distance = ptrdiff_t,  // iterator::difference_type
	// 			class Pointer = T*,          // iterator::pointer
	// 			class Reference = T&         // iterator::reference
    //       	> 	class iterator;

	template < class T >
	class iterator 
    {
		protected: // ???

			Node <T> *ptr;
			
		public: 
			
			typedef T		value_type;
			typedef T		&reference;
			typedef T		*pointer;

			/*
			** -------------------------------- CONSTRUCTOR --------------------------------
			*/

			iterator() {}
			iterator(struct Node <T> *src) {  ptr = src; }

			// iterator(const iterator &src) { *this = src; }
				
			// iterator(struct Node <T> &src) { ptr = src; }

			/*
			** -------------------------------- DESTRUCTOR --------------------------------
			*/

			~iterator() {}

			/*
			** --------------------------------- OVERLOAD ---------------------------------
			*/

			// iterator &				operator=(iterator const & rhs )
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

			bool						operator==(const iterator &x)
			{
				if (x.ptr == ptr)
					return true;
				return false;
			}
			
			bool						operator!=(const iterator &x)
			{
				if (x.ptr != ptr)
					return true;
				return false;
			}
			
			value_type					&operator*()
			{
				// if (ptr == _Tail)
				// 	return ptr->pre->data;
				return ptr->data;
			}
			
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
			
			iterator					&operator++() // ++a 
			{
				ptr = ptr->next;
				return *this;
			}

			iterator					&operator++(int) // a++ 
			{
				iterator tmp(*this);
				operator++();
				return *this;
			}
			
			iterator					&operator--()  // check
			{
				if (ptr->pre)
					ptr = ptr->pre;
				return *this;
			}

			iterator					&operator--(int)  // check
			{
				iterator tmp(*this);
				operator--();
				return *this;
			}
			
			/*
			** --------------------------------- METHODS ----------------------------------
			*/
			

			/*
			** --------------------------------- ACCESSOR ---------------------------------
			*/


			/* ************************************************************************** */
			
			// node_pointer	getnext() const { return ptr->next; }
			struct Node <T>		*getpre() const { return ptr->pre; }
			struct Node <T>		*getptr() const { return ptr; }

		private:

		protected:
		
		
			
    };

	template <class T>
	class const_iterator : public iterator <T>
	{
		public:
		const_iterator() {}
		const_iterator(struct Node <T> *list) { this->ptr = list; }
		const_iterator(const const_iterator &copy) { *this = copy; }
		const_iterator &operator=(const const_iterator &target)
		{
			this->ptr = target.ptr;
			return (*this);
		}
		~const_iterator() {}
		const T &operator*() { return (this->ptr->data); }
	};
}

#endif //CONT_ITERATOR_HPP

























// #ifndef VECTOR_ITERATOR_HPP
// #define VECTOR_ITERATOR_HPP

// #include <iostream>
// #include <string>

// namespace ft 
// {
       
	
// // 	struct			Node
// // 	{
// // 		T			data;
// // 		Node		*pre;
// // 		Node		*next;
// // 	};

// // 	// template <	class Category,              // iterator::iterator_category
// // 	// 			class T,                     // iterator::value_type
// // 	// 			class Distance = ptrdiff_t,  // iterator::difference_type
// // 	// 			class Pointer = T*,          // iterator::pointer
// // 	// 			class Reference = T&         // iterator::reference
// //     //       	> 	class iterator;

// 	template < class T >
// 	class iteratorVector 
//     {

//         // typedef T								value_type;

// 		// 	typedef Alloc							allocator_type;
// 			// typedef value_type &					reference;
// 		// 	typedef const value_type &				const_reference;
// 			// typedef value_type *					pointer;
// 			// typedef const value_type *				const_pointer;
			
// 			// typedef ft::iteratorVector <T>			iterator;
// 			// typedef ft::const_iteratorVector <T>	const_iterator;

// 			// typedef ft::reverse_iterator<T>			reverse_iterator;
// 			// typedef ft::const_reverse_iterator <T>			const_reverse_iterator;
        
// 		private: // ???

// 			T * ptr;
            
// 		public: 
			
// 			typedef T		value_type;
// 			typedef T		&reference;
// 			typedef T		*pointer;




            

// // 			/*
// // 			** -------------------------------- CONSTRUCTOR --------------------------------
// // 			*/

// 			iteratorVector() {}
// 			// iteratorVector(struct Node <T> *src) {  ptr = src; }

// // 			// iteratorVector(const iteratorVector &src) { *this = src; }
				
// // 			// iteratorVector(struct Node <T> &src) { ptr = src; }

// // 			/*
// // 			** -------------------------------- DESTRUCTOR --------------------------------
// // 			*/

// // 			~iteratorVector() {}

// // 			/*
// // 			** --------------------------------- OVERLOAD ---------------------------------
// // 			*/

// // 			// iteratorVector &				operator=(iteratorVector const & rhs )
// // 			// {
// // 			// 	this->clear();
// // 			// // 	this->head->next = this->tail;
// // 			// // 	this->tail->prev = this->head;
// // 			// // 	this->length = 0;
// // 			// // 	this->assign(x.begin(), x.end());
// // 			// 	return *this;


// // 			// // 	// std::cout << "hi" << std::endl;
			
// // 			// // 	// if ( this != &rhs )
// // 			// // 		*this = rhs;
				
// // 			// // 	return *this;
// // 			// }

// // 			bool						operator==(const iteratorVector &x)
// // 			{
// // 				if (x.ptr == ptr)
// // 					return true;
// // 				return false;
// // 			}
			
// // 			bool						operator!=(const iteratorVector &x)
// // 			{
// // 				if (x.ptr != ptr)
// // 					return true;
// // 				return false;
// // 			}
			
// 			value_type					&operator*()
// 			{
// 				// if (ptr == _Tail)
// 				// 	return ptr->pre->data;
// 				return ptr[0];
// 			}
			
// // 			// const value_type			&operator*() const
// // 			// {
// // 			// 	return ptr->data;
// // 			// }
			
// // 			// pointer						operator->()
// // 			// {
// // 			// 	return &ptr->data;
// // 			// }
			
// // 			// const pointer				operator->() const
// // 			// {
// // 			// 	return &ptr->data;
// // 			// }
			
// 			iteratorVector					&operator++() // ++a 
// 			{
// 				this->ptr++;
// 				return *this;
// 			}

// 			iteratorVector					&operator++(int) // a++ 
// 			{
// 				iteratorVector tmp(*this);
// 				operator++();
// 				return *this;
// 			}
			
// // 			iteratorVector					&operator--()  // check
// // 			{
// // 				if (ptr->pre)
// // 					ptr = ptr->pre;
// // 				return *this;
// // 			}

// // 			iteratorVector					&operator--(int)  // check
// // 			{
// // 				iteratorVector tmp(*this);
// // 				operator--();
// // 				return *this;
// // 			}
			
// // 			/*
// // 			** --------------------------------- METHODS ----------------------------------
// // 			*/
			

// // 			/*
// // 			** --------------------------------- ACCESSOR ---------------------------------
// // 			*/


// // 			/* ************************************************************************** */
			
// // 			// node_pointer	getnext() const { return ptr->next; }
// // 			struct Node <T>		*getpre() const { return ptr->pre; }
// // 			struct Node <T>		*getptr() const { return ptr; }

//     };

// // 	template <class T>
// // 	class const_iteratorVector : public iteratorVector <T>
// // 	{
// // 		public:
// // 		const_iteratorVector() {}
// // 		const_iteratorVector(struct Node <T> *list) { this->ptr = list; }
// // 		const_iteratorVector(const const_iteratorVector &copy) { *this = copy; }
// // 		const_iteratorVector &operator=(const const_iteratorVector &target)
// // 		{
// // 			this->ptr = target.ptr;
// // 			return (*this);
// // 		}
// // 		~const_iteratorVector() {}
// // 		const T &operator*() { return (this->ptr->data); }
// // 	};
// }

// #endif