/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:32:19 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/25 18:24:27 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iterator>
#include <iostream>
#include "map_iterator.hpp"
// #include "map_reverse_iterator.hpp"
#include "../extra.hpp"

namespace ft 
{
	// template < class T, class Alloc = std::allocator<T> >
    template < class Key, class T, class Compare = std::less <Key>, 
                                    class Alloc = std::allocator <std::pair <const Key,T> > >
	class map 
    { 
		public: 
            
            typedef Key                                         key_type;
            typedef T                                           mapped_type;
            typedef std::pair <const Key, T>                         value_type;
            typedef std::less <key_type>                             key_compare;
            // typedef value_comp                                  value_compare;
			typedef std::allocator <value_type>				    	allocator_type;
			typedef value_type &								reference;
			typedef const value_type &						    const_reference;
            typedef value_type *		                    	pointer;
            typedef const value_type *		                    const_pointer;
			typedef ft::iteratorMap <Key, T>					iterator; // const_iterator
			// typedef ft::iteratorMap <T>					const_iterator;
			// typedef ft::const_reverse_iterator <T>			const_reverse_iterator;
			typedef ptrdiff_t				                    difference_type;
            typedef size_t						       			size_type;

            typedef struct nodeMap <Key, T>                     nodeMap;

			/*
			** -------------------------------- CONSTRUCTOR --------------------------------
			*/

                explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
                {
                    _alloc = alloc;
                    _key = comp;
                    
                    _map            = nullptr;
                    
                    _start          = nullptr;
                    _finish         = nullptr;
                    _root           = nullptr;
                    _size           = 0;
                }

                // explicit map (const key_compare& comp = key_compare(),
                //                             const allocator_type & alloc = allocator_type());
                
                // template <class InputIterator>
                // map (InputIterator first, InputIterator last, const key_compare & comp = key_compare(),
                //                                                 const allocator_type& alloc = allocator_type());
                
                // map (const map& x);
        
			/*
			** -------------------------------- DESTRUCTOR --------------------------------
			*/

                // ~map();

			/*
			** --------------------------------- OVERLOAD ---------------------------------
			*/

                // map& operator= (const map& x);

			/*
			** --------------------------------- METHODS ----------------------------------
			*/

	/* Iterators */

                iterator begin() { return _start; }
                // const_iterator begin() const;

                iterator end() { return _finish; }
                // const_iterator end() const;

                // reverse_iterator rbegin();
                // const_reverse_iterator rbegin() const;

                // reverse_iterator rend();
                // const_reverse_iterator rend() const;

	/* Capacity */

                // bool empty() const;
                size_type size() const { return this->_size; }
                // size_type max_size() const;

	/* Element access */

                // mapped_type& operator[] (const key_type& k);

	/* Modifiers */

                std::pair <iterator, bool> insert (const value_type& val)
                {
                    _map            = new nodeMap;
                    _map->parent    = nullptr;
                    _map->more      = nullptr;
                    _map->less      = nullptr;
                    _map->data      = val;
                    _map->color     = BLACK;
                    
                    _start          = _map;
                    _finish         = _map;
                    _root           = _map;
                    _size++;

                    return std::make_pair(iterator(this->_root), true);    // 11 st              
                }
                
                iterator insert (iterator position, const value_type& val);
                
                template <class InputIterator>
                void insert (InputIterator first, InputIterator last);








// ft::pair<iterator, bool>	insert(const value_type& val) {
// 			if (this->_size == 0)
// 				return (ft::make_pair(iterator(Base::insert_root(val)), true));
// 			mapnode	*it(this->_root);
// 			while (it) {
// 				if (key_compare()(val.first, it->data.first)) {
// 					if (it->left && it->left != this->_first)
// 						it = it->left;
// 					else return ft::make_pair(iterator(Base::insert_left(it, val)), true);
// 				}
// 				else if (key_compare()(it->data.first, val.first)) {
// 					if (it->right && it->right != this->_last)
// 						it = it->right;
// 					else return ft::make_pair(iterator(Base::insert_right(it, val)), true);
// 				}
// 				else break ;
// 			}
// 			return ft::make_pair(iterator(it), false);
// 		}
// 		iterator	insert(iterator position, const value_type& val) {
// 			(void)position;
// 			return insert(val).first;
// 		}
// 		template <class InputIterator>
// 		void		insert(InputIterator first, InputIterator last, typename ft::check_type<typename ft::iterator_traits<InputIterator>::iterator_category>::type* = 0) {
// 			while (first != last) {
// 				insert(*first);
// 				++first;
// 			}
// 		}












                // void erase (iterator position);

                // size_type erase (const key_type& k);

                // void erase (iterator first, iterator last);
                
                // void swap (map& x);

                // void clear();

    /* Observers */
                
                // key_compare key_comp() const;
                
                // value_compare value_comp() const;

	/* Operations */

                // iterator find (const key_type& k);
                // const_iterator find (const key_type& k) const;

                // size_type count (const key_type& k) const;

                // iterator lower_bound (const key_type& k);
                // const_iterator lower_bound (const key_type& k) const;

                // iterator upper_bound (const key_type& k);
                // const_iterator upper_bound (const key_type& k) const;

                // pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
                // pair<iterator,iterator>             equal_range (const key_type& k);

		private:

            allocator_type  _alloc;
            key_compare     _key;

            nodeMap         *_map;
            nodeMap         *_start;
            nodeMap         *_finish;
            nodeMap         *_root ;
            size_type       _size;
			
    }; 

	/* Non-member function overloads */

}
#endif
