/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:32:19 by gbroccol          #+#    #+#             */
/*   Updated: 2021/05/04 12:45:35 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iterator>
#include <iostream>
#include "iterator/map_iterator.hpp"
#include "iterator/map_reverse_iterator.hpp"
#include "extra.hpp"
#include "allocator.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>,
			  class Alloc = ft::allocator<std::pair<const Key, T> > >
	class map
	{
	public:
	
		typedef Key										key_type;
		typedef T 										mapped_type;
		typedef std::pair<const Key, T> 				value_type;
		typedef std::less<key_type> 					key_compare;
		typedef Alloc					 				allocator_type;
		typedef value_type &							reference;
		typedef const value_type &						const_reference;
		typedef value_type *							pointer;
		typedef const value_type *						const_pointer;
		typedef ft::iteratorMap<Key, T> 				iterator;
		typedef ft::const_iterator_map <Key, T> 		const_iterator;
		typedef ft::map_reverse_iterator <Key, T> 		reverse_iterator;
		typedef ft::const_reverse_iterator_map <Key, T> const_reverse_iterator;
		typedef ptrdiff_t 								difference_type;
		typedef size_t 									size_type;

		typedef struct nodeMap<Key, T> 					nodeMap;
		
		class value_compare
		{
			friend class map;
			
			protected:
				Compare com;
				value_compare (Compare c) : com(c) {}

			public:
			typedef bool result;
			typedef value_type firstArg;
			typedef value_type secondArg;

			bool operator() (const value_type& lhs, const value_type& rhs) const
			{
				return com(lhs.first, rhs.first);
			}
		};

		/*
		** -------------------------------- CONSTRUCTOR --------------------------------
		*/

			explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
			{
				_alloc = alloc;
				_comp = comp;

				_TSTART = new nodeMap;
				_TSTART->parent = NULL;
				_TSTART->right = NULL;
				_TSTART->left = NULL;
				_TSTART->color = FIRST;
				
				_TNULL = new nodeMap;
				_TNULL->parent = NULL;
				_TNULL->right = NULL;
				_TNULL->left = NULL;
				_TNULL->color = LAST;

				_map = NULL;
				_TSTART->parent = NULL;
				_TNULL->parent = NULL;
				_root = NULL;
				_size = 0;
			}

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare & comp = key_compare(),
															const allocator_type& alloc = allocator_type(), 
															typename ft::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
			{
				_alloc = alloc;
				_comp = comp;

				_TSTART = new nodeMap;
				_TSTART->parent = NULL;
				_TSTART->right = NULL;
				_TSTART->left = NULL;
				_TSTART->color = FIRST;

				_TNULL = new nodeMap;
				_TNULL->parent = NULL;
				_TNULL->right = NULL;
				_TNULL->left = NULL;
				_TNULL->color = LAST;

				_map = NULL;
				_TSTART->parent = NULL;
				_TNULL->parent = NULL;
				_root = NULL;
				_size = 0;

				insert(first, last);
			}

			map (const map& x)
			{
				_TNULL = new nodeMap;
				_TSTART = new nodeMap;
				*this = x;
			}

		/*
		** -------------------------------- DESTRUCTOR --------------------------------
		*/
			~map()
			{
				clear();
				delete _TNULL;
				delete _TSTART;
			}
		/*
		** --------------------------------- OVERLOAD ---------------------------------
		*/

			map& operator= (const map& x)
			{
				_TNULL->parent = NULL;
				_TNULL->right = NULL;
				_TNULL->left = NULL;
				_TNULL->color = LAST;

				_map = NULL;
				_TSTART->parent = NULL;
				_TNULL->parent = NULL;
				_root = NULL;
				_size = 0;

				clear();
				
				if (x._size)
					insert(x.begin(), x.end());
					
				return (*this);
			}

		/*
		** --------------------------------- METHODS ----------------------------------
		*/

		/* Iterators */

			iterator begin()
			{
				if (_size == 0)
					return _TNULL;
				return _TSTART->parent;
			}
			const_iterator begin() const
			{
				if (_size == 0)
					return _TNULL;
				return _TSTART->parent;
			}

			iterator end()
			{
				if (_size == 0)
					return _TNULL;
				return _TNULL->parent->right;
			}
			const_iterator end() const
			{
				if (_size == 0)
					return _TNULL;
				return _TNULL->parent->right;
			}

			reverse_iterator rbegin()
			{
				if (_size == 0)
					return _TNULL;
				return _TNULL->parent;
			}
			const_reverse_iterator rbegin() const
			{
				if (_size == 0)
					return _TNULL;
				return _TNULL->parent;
			}

			reverse_iterator rend() { return _TSTART; }
			const_reverse_iterator rend() const { return _TSTART; }

		/* Capacity */

			bool empty() const { return (_size == 0 ? true : false); }
			size_type size() const { return _size; }
			size_type max_size() const { return (std::numeric_limits<size_type>::max() / (sizeof(nodeMap))); }

		/* Element access */

			mapped_type &operator[](const key_type &key)
			{
				return insert(std::make_pair(key, mapped_type())).first->second;
			}

		/* Modifiers */

			std::pair<iterator, bool> insert(const value_type &val)
			{
				if (_size == 0)
					return (createFirstNode(val));

				nodeMap *whereAdd = findNode(val, _root);

				if (whereAdd->data.first == val.first)
					return std::make_pair(iterator(whereAdd), false);
				else
				{
					nodeMap *newNode = (nodeMap *)::operator new(sizeof(nodeMap));
					_alloc.construct(&(newNode->data), val);
					
					newNode->color = RED_TREE;
					newNode->parent = whereAdd;
					newNode->right = NULL;
					newNode->left = NULL;

					if (whereAdd->data.first > val.first)
					{
						whereAdd->left = newNode;
						if (newNode->data.first < _TSTART->parent->data.first)
							_TSTART->parent = newNode;
					}
					else if (whereAdd->data.first < val.first)
					{
						if (whereAdd->right == _TNULL)
						{
							newNode->right = _TNULL;
							_TNULL->parent = newNode;
						}
						whereAdd->right = newNode;
						if (newNode->data.first > _TNULL->parent->data.first)
						{
							_TNULL->parent = newNode;
						}
					}
					_size++;
					insertFix(newNode);
					return std::make_pair(iterator(newNode), true);
				}
				return std::make_pair(iterator(_root), true);
			}

			iterator insert(iterator position, const value_type &val)
			{
				nodeMap *whereAdd = position.ptr;

				if (checkTruePositionForKey(whereAdd, val))
				{
					whereAdd = findNode(val, whereAdd);
					if (whereAdd->data.first > val.first && whereAdd->left == NULL)
					{
						nodeMap *newNode = createNode(val);
						newNode->parent = whereAdd;
						newNode->color = RED_TREE;

						whereAdd->left = newNode;

						if (_TSTART->parent == whereAdd)
							_TSTART->parent = newNode;
						_size++;
						insertFix(newNode);
						return (iterator)newNode;
					}
					else if (whereAdd->data.first < val.first && (whereAdd->right == NULL || whereAdd->right == _TNULL))
					{
						nodeMap *newNode = createNode(val);
						newNode->parent = whereAdd;
						newNode->color = RED_TREE;

						whereAdd->right = newNode;

						if (_TNULL->parent == whereAdd)
						{
							_TNULL->parent = newNode;
							newNode->right = _TNULL;
							_TNULL->parent = newNode;
						}
						_size++;
						insertFix(newNode);
						return (iterator)newNode;
					}
				}
				return (insert(val).first);
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last,
											typename ft::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
			{
				for ( ; first != last; first++)
					insert(*first); // insert(first.ptr->data);
			}

			void erase(iterator position)
			{
				nodeMap *x;
				nodeMap *y;
				nodeMap *nodeToBeDeleted = position.ptr;
				int originalColor = nodeToBeDeleted->color;
		
				if (nodeToBeDeleted->left == NULL)
				{
					x = nodeToBeDeleted->right;
					rbTransplant(nodeToBeDeleted, x);

					if (nodeToBeDeleted == _TSTART->parent)
					{
						if (x)
							_TSTART->parent = minimum(x);
						else
							_TSTART->parent = nodeToBeDeleted->parent;
					}
					if (nodeToBeDeleted == _TNULL->parent)
						_TNULL->parent = _TNULL->parent;
				}
				else if (nodeToBeDeleted->right == NULL)
				{
					x = nodeToBeDeleted->left;
					rbTransplant(nodeToBeDeleted, x);
				}
				else
				{
					y = minimum(nodeToBeDeleted->right);
					
					x = y->right;

					if (y->parent == nodeToBeDeleted)
					{
						x->parent = y;
					}
					else
					{
						rbTransplant(y, y->right);
						y->right = nodeToBeDeleted->right;
						y->right->parent = y;
					}

					rbTransplant(nodeToBeDeleted, y);
					y->left = nodeToBeDeleted->left;
					y->left->parent = y;
				}

				if (originalColor == BLACK_TREE)
				{
					deleteFix(x);
				}
				_TNULL->color = LAST;
				delete nodeToBeDeleted;
				_size--;
			}

			size_type erase(const key_type &key)
			{
				nodeMap *findNoda = NULL;
				findNoda = findNodaKey(key);

				if (findNoda == NULL || findNoda == _TNULL)
					return 0;

				erase(iterator(findNoda));
				return 1;
			}

			void erase (iterator first, iterator last)
			{
				while (_size && first != last)
				{
					erase(first);
					first++;
				}
			}

			void swap(map &x)
			{
				ft::itemswap(_alloc, x._alloc);
				ft::itemswap(_comp, x._comp);
				ft::itemswap(_map, x._map);
				ft::itemswap(_root, x._root);
				ft::itemswap(_size, x._size);
				ft::itemswap(_TNULL, x._TNULL);
				ft::itemswap(_TSTART, x._TSTART);
			}

			void clear()
			{
				if (empty())
					return;
					
				_TNULL->parent->right = NULL;
				clear(_root);
				_map = NULL;
				_TSTART->parent = NULL;
				_TNULL->parent = NULL;
				_root = NULL;
				_size = 0;
				_TNULL->parent = NULL;
			}

		/* Observers */

			key_compare key_comp() const { return _comp; }
			value_compare value_comp() const { return value_compare(_comp); }

		/* Operations */

			iterator find (const key_type& key)
			{
				nodeMap * tmp = _root;
				int flag = 1;

				while (flag)
				{
					flag = 0;
					for (; tmp->data.first > key && tmp->left != NULL; flag++)
						tmp = tmp->left;

					for (; tmp->data.first < key && tmp->right != NULL; flag++)
						tmp = tmp->right;
				}
				return (iterator)tmp;
			}
			
			const_iterator find (const key_type& key) const
			{
				nodeMap * tmp = _root;
				int flag = 1;

				while (flag)
				{
					flag = 0;
					for (; tmp->data.first > key && tmp->left != NULL; flag++)
						tmp = tmp->left;

					for (; tmp->data.first < key && tmp->right != NULL; flag++)
						tmp = tmp->right;
				}
				return (const_iterator)tmp;
			}

			size_type count (const key_type& k) const
			{
				if (find(k).ptr->color == LAST)
					return (0);
				return (1);
			}

			iterator lower_bound (const key_type& k)
			{
				iterator it = find(k);
				if (it.ptr == _TNULL)
					return (it);
				if (it.ptr->data.first < k)
				{
					it++;
					return (it);
				}
				return (it);
			}
			
			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator it = find(k);
				if (it.ptr == _TNULL)
					return (it);
				if (it.ptr->data.first < k)
				{
					it++;
					return (it);
				}
				return (it);
			}

			iterator upper_bound (const key_type& k)
			{
				iterator it = find(k);
				if (it.ptr == _TNULL)
					return (it);
				it++;
				return (it);
			}
			
			const_iterator upper_bound (const key_type& k) const
			{
				const_iterator it = find(k);
				if (it.ptr == _TNULL)
					return (it);
				it++;
				return (it);
			}

			std::pair <const_iterator, const_iterator> equal_range (const key_type& k) const
			{
				return std::make_pair(const_iterator(lower_bound(k)), const_iterator(upper_bound(k)));
			}
					
			std::pair <iterator, iterator> equal_range (const key_type& k)
			{
				return std::make_pair(iterator(lower_bound(k)), iterator(upper_bound(k)));
			}

			// void printHelper(nodeMap *root, std::string indent, bool last)
			// {
			// 	if (root && root != _TNULL)
			// 	{
			// 		std::cout << indent;
			// 		if (last)
			// 		{
			// 			std::cout << "R----";
			// 			indent += "   ";
			// 		}
			// 		else
			// 		{
			// 			std::cout << "L----";
			// 			indent += "|  ";
			// 		}

			// 		std::string sColor = root->color ? "\x1b[34;1m" : "\x1b[31;1m";
			// 		std::cout << sColor << root->data.first << "\x1b[0m" << std::endl;
			// 		printHelper(root->left, indent, false);
			// 		printHelper(root->right, indent, true);
			// 	}
			// }

			// void printTree()
			// {
			// 	if (_root)
			// 	{
			// 		std::cout << std::endl;
			// 		printHelper(_root, "", true);
			// 		std::cout << std::endl;
			// 	}
			// }

			void _print_tree()
			{
				std::cout << "_print_tree" << " |";
				iterator itSys = begin();
				for ( ; itSys != end(); itSys++)
				{
					std::cout << "" << std::setw(7) << itSys->first << "    | ";
				}
				std::cout << "\x1b[33;1m " << itSys->first << "\x1b[0m | ";
				std::cout << '\n' << "              |" ;

				itSys = begin();
				for (; itSys != end(); itSys++)
				{
					std::cout << "" << std::setw(7) << itSys->second << "    | ";
				}
				// std::cout << "\x1b[33;1m " << itSys->second << "\x1b[0m | ";
				std::cout << '\n' << '\n';
			}

		private:
		
			allocator_type _alloc;
			key_compare _comp;
			nodeMap *_map;
			nodeMap *_root;
			size_type _size;
			nodeMap *_TNULL;
			nodeMap *_TSTART;
		
			std::pair<iterator, bool> createFirstNode(const value_type &val)
			{
				_map = (nodeMap *)::operator new(sizeof(nodeMap));
				_alloc.construct(&(_map->data), val);
				_map->parent = NULL;
				_map->right = _TNULL;
				_map->left = NULL;
				_map->color = BLACK_TREE;

				_TSTART->parent = _map;
				_TNULL->parent = _map;
				_root = _map;
				_size++;

				_TNULL->parent = _map;
				return std::make_pair(iterator(_root), true);
			}

			nodeMap *createNode(const value_type &val)
			{
				nodeMap * newNode = (nodeMap *)::operator new(sizeof(nodeMap));
				_alloc.construct(&(newNode->data), val);
				newNode->parent = NULL;
				newNode->right = NULL;
				newNode->left = NULL;
				newNode->color = BLACK_TREE;

				return newNode;
			}

			nodeMap *findNode(const value_type &value, nodeMap *whereAdd) 
			{
				int flag = 1;

				while (flag)
				{
					flag = 0;
					for (; whereAdd->data.first > value.first && whereAdd->left != NULL; flag++)
						whereAdd = whereAdd->left;

					for (; whereAdd->data.first < value.first && whereAdd->right != NULL; flag++)
						whereAdd = whereAdd->right;
				}
				if (whereAdd == _TNULL)
					whereAdd = _TNULL->parent;
				return (whereAdd);
			}

			void turnLeft(nodeMap *node)
			{
				nodeMap *y = node->right;
				node->right = y->left;
				if (y->left != NULL)
				{
					y->left->parent = node;
				}
				y->parent = node->parent;
				if (node->parent == NULL)
				{
					_root = y;
				}
				else if (node == node->parent->left)
				{
					node->parent->left = y;
				}
				else
				{
					node->parent->right = y;
				}
				y->left = node;
				node->parent = y;
			}

			void turnRight(nodeMap *node)
			{
				nodeMap *y = node->left;
				node->left = y->right;
				if (y->right != NULL)
				{
					y->right->parent = node;
				}
				y->parent = node->parent;
				if (node->parent == NULL)
				{
					_root = y;
				}
				else if (node == node->parent->right)
				{
					node->parent->right = y;
				}
				else
				{
					node->parent->left = y;
				}
				y->right = node;
				node->parent = y;
			}

			void insertFix(nodeMap *node)
			{
				nodeMap *tmp;

				while (node->parent->color == RED_TREE)
				{
					if (node->parent->parent->left == node->parent)
					{												
						tmp = node->parent;
						if (tmp->parent->right && tmp->parent->right->color == RED_TREE) 
						{
							tmp->parent->right->color = BLACK_TREE; 
							tmp->color = BLACK_TREE;
							tmp->parent->color = RED_TREE;
							node = node->parent->parent; 
						}
						else
						{
							if (node == node->parent->right) 
							{
								node = node->parent; 
								turnLeft(node);		 
							}
							node->parent->color = BLACK_TREE;	   
							node->parent->parent->color = RED_TREE; 
							turnRight(node->parent->parent);   
						}
					}
					else
					{
						if (node->parent->parent->right == node->parent)
						{
							tmp = node->parent;
							if (tmp->parent->left && tmp->parent->left->color == RED_TREE) 
							{
								tmp->parent->left->color = BLACK_TREE; 
								tmp->color = BLACK_TREE;
								tmp->parent->color = RED_TREE;
								node = node->parent->parent; 
							}
							else
							{
								if (node == node->parent->left) 
								{
									node = node->parent; 
									turnRight(node);	 
								}
								node->parent->color = BLACK_TREE;	   
								node->parent->parent->color = RED_TREE; 
								turnLeft(node->parent->parent);	   
							}
						}
					}
					if (node == _root)
						break;
				}
				_root->color = BLACK_TREE;
			}

			void rbTransplant(nodeMap *nodeToBeDeleted, nodeMap *x) 
			{
				if (nodeToBeDeleted->parent == NULL)
					_root = x;
				else if (nodeToBeDeleted == nodeToBeDeleted->parent->left)
					nodeToBeDeleted->parent->left = x;
				else if (nodeToBeDeleted == nodeToBeDeleted->parent->right)
					nodeToBeDeleted->parent->right = x;
				
				if (x)
					x->parent = nodeToBeDeleted->parent;
			}

			void deleteFix(nodeMap *x)
			{
				nodeMap *s;

				if (x == NULL)
					return;

				while (x && x != _root && x->color == BLACK_TREE)
				{
					if (x->parent && x == x->parent->left)
					{
						s = x->parent->right;
						if (s && s->color == RED_TREE)
						{
							s->color = BLACK_TREE;
							x->parent->color = RED_TREE;
							turnLeft(x->parent);
							s = x->parent->right;
						}

						if (s && s->left && s->right && s->left->color == BLACK_TREE && s->right->color == BLACK_TREE)
						{
							s->color = RED_TREE;
							x = x->parent;
						}
						else
						{
							if (s && s->right && s->right->color == BLACK_TREE)
							{
								s->left->color = BLACK_TREE;
								s->color = RED_TREE;
								turnRight(s);
								s = x->parent->right;
							}

							s->color = x->parent->color;
							x->parent->color = BLACK_TREE;
							s->right->color = BLACK_TREE;
							turnLeft(x->parent);
							x = _root;
						}
					}
					else
					{
						s = x->parent->left;
						if (s && s->color == RED_TREE)
						{
							s->color = BLACK_TREE;
							x->parent->color = RED_TREE;
							turnRight(x->parent);
							s = x->parent->left;
						}

						if (s && s->right && s->right->color == BLACK_TREE && s->right->color == BLACK_TREE)
						{
							s->color = RED_TREE;
							x = x->parent;
						}
						else
						{
							if (s && s->left && s->left->color == BLACK_TREE)
							{
								s->right->color = BLACK_TREE;
								s->color = RED_TREE;
								turnLeft(s);
								s = x->parent->left;
							}

							s->color = x->parent->color;
							x->parent->color = BLACK_TREE;
							s->left->color = BLACK_TREE;
							turnRight(x->parent);
							x = _root;
						}
					}
				}
				x->color = BLACK_TREE;
			}

			nodeMap *minimum(nodeMap *node)
			{
				while (node->left != NULL)
					node = node->left;
				return node;
			}

			nodeMap *maximum(nodeMap *node)
			{
				while (node->right != NULL && node->right != _TNULL)
					node = node->right;
				return node;
			}

			void clear(nodeMap *position)
			{
				if (!position)
					return;
				clear(position->left);
				clear(position->right);
				delete position;
				_size--;
			}

			nodeMap *findNodaKey(const key_type &key)
			{
				nodeMap *findNoda = NULL;
				nodeMap *begin = _root;

				while (begin != _TNULL && begin != NULL)
				{
					if (begin->data.first == key)
					{
						findNoda = begin;
						break;
					}
					else if (begin->data.first <= key)
						begin = begin->right;
					else
						begin = begin->left;
				}
				if (findNoda == NULL || findNoda == _TNULL)
					return NULL;
				return findNoda;
			}

			bool	checkTruePositionForKey(nodeMap *node, const value_type &val)
				{
					if (val.first < node->data.first)
					{
						while (node->parent && node->parent->left == node && node->parent->data.first > val.first)
							node = node->parent;
							
						if (node->parent == NULL)
							return true;
						else if (node->parent && node->parent->right == node && node->parent->data.first < val.first)
							return true;
					}
					else if (val.first > node->data.first)
					{
						while (node->parent && node->parent->right == node && node->parent->data.first < val.first)
							node = node->parent;
							
						if (node->parent == NULL)
							return true;
						else if (node->parent && node->parent->left == node && node->parent->data.first > val.first)
							return true;
					}
					return false;
				}
		};

		/* Non-member function overloads */
			
			template <class Key, class T, class Compare, class Alloc>
			bool operator== (const ft::map <Key, T, Compare, Alloc> & lhs, const ft::map <Key, T, Compare, Alloc> & rhs)
			{
				if (lhs.size() == rhs.size())
				{
					ft::iteratorMap <Key, T> it1 = lhs.begin();
					ft::iteratorMap <Key, T> it2 = rhs.begin();
					
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

			template <class Key, class T, class Compare, class Alloc>
			bool operator!= (const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs)
			{
				return !(lhs == rhs);
			}

			template <class Key, class T, class Compare, class Alloc>
			bool operator<  (const map <Key, T, Compare, Alloc> & lhs, const map <Key, T, Compare, Alloc> & rhs)
			{
				if (lhs.size() == 0)
					return true;
				else if (rhs.size() == 0)
					return false;
				else
				{
					ft::iteratorMap <Key, T> it1 = lhs.begin();
					ft::iteratorMap <Key, T> it2 = rhs.begin();
						
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

			template <class Key, class T, class Compare, class Alloc>
			bool operator>  (const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs)
			{
				return (rhs < lhs);
			}

			template <class Key, class T, class Compare, class Alloc>
			bool operator<= (const map <Key, T, Compare, Alloc> & lhs, const map <Key, T, Compare, Alloc>& rhs) 
			{
				return !(rhs < lhs);
			}

			template <class Key, class T, class Compare, class Alloc>
			bool operator>= (const map <Key, T, Compare, Alloc>& lhs, const map <Key, T, Compare, Alloc>& rhs)
			{
				return 	!(lhs < rhs);
			}

			template <class Key, class T, class Compare, class Alloc>
			void swap (map <Key, T, Compare, Alloc> & x, map <Key, T, Compare, Alloc> & y) { x.swap(y); }

}
#endif
