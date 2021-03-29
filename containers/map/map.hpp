/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:32:19 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/29 21:02:23 by gbroccol         ###   ########.fr       */
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

                    _TNULL           = new nodeMap;
                    _TNULL->parent    = nullptr;
                    _TNULL->right      = nullptr;
                    _TNULL->left      = nullptr;
                    _TNULL->color     = LAST;
                    // _TNULL->data.first = 999;
                    // _TNULL->data.second = 999;
                    
                }
                
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

                iterator end() { return _finish->right; } // _TNULL
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
                    if (_size == 0)
                        return (createFirstNode(val));
                    
                    nodeMap	*whereAdd = whereAddNode(val);

                    
                    
                    if (whereAdd->data.first == val.first)
                        return std::make_pair(iterator(this->_root), false); // rewrite
                    else
                    {
                        nodeMap	*newNode = new nodeMap;
                        newNode->color   = RED;
                        newNode->data    = val;
                        newNode->parent  = whereAdd;
                        newNode->right   = nullptr;
                        newNode->left    = nullptr;
                        
                        if (whereAdd->data.first > val.first)
                        {
                            whereAdd->left = newNode;
                            if (newNode->data.first < _start->data.first)
                                _start = newNode;

                            // std::cout << "NEW VALUE [" << std::setw(3) << newNode->data.first << "]     " << std::setw(4) << newNode->data.first << "   <   " << whereAdd->data.first  << std::endl;
                        }
                        else if (whereAdd->data.first < val.first)
                        {
                            if (whereAdd->right == _TNULL)
                            {
                                
                                newNode->right = _TNULL;
                                _TNULL->parent = newNode;
                            }
                            whereAdd->right = newNode;
                            if (newNode->data.first > _finish->data.first)
                            {
                                
                                _finish = newNode;
                            }
                            // std::cout << "NEW VALUE [" << std::setw(3) << newNode->data.first << "]     " << std::setw(4) << newNode->data.first  << "   >   " << whereAdd->data.first << std::endl;
                        }
                        _size++;
                        // repaint(newNode);
                        // rotation();
                    }
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





                // void printHelper(NodePtr root, string indent, bool last) {
                //     if (root != TNULL)
                //     {
                //         cout << indent;
                //         if (last)
                //         {
                //             cout << "R----";
                //             indent += "   ";
                //         }
                //         else
                //         {
                //             cout << "L----";
                //             indent += "|  ";
                //         }

                //         string sColor = root->color ? "RED" : "BLACK";
                //         cout << root->data << "(" << sColor << ")" << endl;
                //         printHelper(root->left, indent, false);
                //         printHelper(root->right, indent, true);
                //     }
                // }

                // void printTree()
                // {
                //     if (root)
                //     {
                //         printHelper(this->root, "", true);
                //     }
                // }



















        
             


        

		private:

            allocator_type  _alloc;
            key_compare     _key;

            nodeMap         *_map;
            nodeMap         *_start;
            nodeMap         *_finish;
            nodeMap         *_root ;
            size_type       _size;

            nodeMap         *_TNULL;



                std::pair <iterator, bool> createFirstNode (const value_type& val)
                {
                    _map            = new nodeMap;
                    
                    _map->parent    = nullptr;
                    _map->right      = _TNULL;
                    _map->left      = nullptr;
                    
                    _map->data      = val;
                    _map->color     = BLACK;
                    
                    _start          = _map;
                    _finish         = _map;
                    _root           = _map;
                    _size++;

                    _TNULL->parent    = _map;
                    return std::make_pair(iterator(this->_root), true);    // 11 st              
                }

                nodeMap	* whereAddNode (const value_type& value)
                {
                    int flag = 1;
                    nodeMap	*whereAdd = _root;

                    while (flag)
                    {
                        flag = 0;
                        for ( ; whereAdd->data.first > value.first && whereAdd->left != NULL; flag++)
                            whereAdd = whereAdd->left;
                        
                        for ( ; whereAdd->data.first < value.first && whereAdd->right != NULL; flag++)
                            whereAdd = whereAdd->right;
                    }

                    // std::cout << "----->>>>   " << whereAdd->data.first << std::endl;
                    
                    if (whereAdd == _TNULL)
                    {
                        whereAdd = _TNULL->parent;
                    }
                    return (whereAdd);
                }

                void        repaint(nodeMap * newNode)
                {
                   


                    
                    iterator newNodeIt = begin();
                    while (newNodeIt != end())
                    {
                        if (newNodeIt.getptr()->data.first == newNode->data.first)
                            break;
                        newNodeIt++;
                    }
                    // iterator tmp = newNodeIt;

                    std::cout << "find sega -> " << newNodeIt.getptr()->data.first << std::endl;
                    std::cout << "find sega -> " << newNodeIt.getptr()->parent->data.first << std::endl;
                    
                    
                    int previous = RED;
                    newNodeIt++;

                    std::cout << "find sega -> " << newNodeIt.getptr()->data.first << std::endl;
                    // std::cout << "find sega -> " << newNodeIt.getptr()->parent->data.first << std::endl;


                    // std::cout << "****************" << std::endl;
                    while (newNodeIt != this->end())
                    {
                        // std::cout << "****************" << std::endl;
                        
                        // std::cout << previous << std::endl;
                        
                        
                        if (previous == RED && newNodeIt.getptr()->color == RED)
                        {
                            // std::cout << "------- 1 --------" << std::endl;
                            newNodeIt.getptr()->color = BLACK;
                            previous = BLACK;
                        }
                        else if (previous == BLACK && newNodeIt.getptr()->color == BLACK)
                        {
                            // std::cout << "------- 2 --------" << std::endl;
                            newNodeIt.getptr()->color = RED;
                            previous = RED;
                        }
                        else
                        {
                            // std::cout << "------- 3 --------" << std::endl;
                            previous = newNodeIt.getptr()->color;
                        }
                        
                        // std::cout << "^^^^^^^^^^^^^^^^" << std::endl;
                        newNodeIt++;
                    }

                    

                    
                    // newNodeIt = tmp;
                    // while (newNodeIt != this->end())
                    // {
                    //     if (previous == RED && newNodeIt.getptr()->color == RED)
                    //     {
                    //         newNodeIt.getptr()->color = BLACK;
                    //         previous = BLACK;
                    //     }
                    //     else if (previous == BLACK && newNodeIt.getptr()->color == BLACK)
                    //     {
                    //         newNodeIt.getptr()->color = RED;
                    //         previous = RED;
                    //     }
                    //     else
                    //         previous = newNodeIt.getptr()->color;
                    //     newNodeIt++;
                    // }
                    _root->color = BLACK;
                }
			
    }; 

	/* Non-member function overloads */

}
#endif
