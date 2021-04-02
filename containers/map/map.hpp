/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:32:19 by gbroccol          #+#    #+#             */
/*   Updated: 2021/04/02 20:32:21 by gbroccol         ###   ########.fr       */
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
	template <class Key, class T, class Compare = std::less<Key>,
			  class Alloc = std::allocator<std::pair<const Key, T> > >
	class map
	{
	public:
	
		typedef Key										key_type;
		typedef T 										mapped_type;
		typedef std::pair<const Key, T> 				value_type;
		typedef std::less<key_type> 					key_compare;
		typedef std::allocator<value_type> 				allocator_type;
		typedef value_type &							reference;
		typedef const value_type &						const_reference;
		typedef value_type *							pointer;
		typedef const value_type *						const_pointer;
		typedef ft::iteratorMap<Key, T> 				iterator;
		typedef ft::const_iterator_map <Key, T> 		const_iterator;
		// typedef ft::const_reverse_iterator <Key, T> 			const_reverse_iterator;
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

			_TNULL = new nodeMap;
			_TNULL->parent = nullptr;
			_TNULL->right = nullptr;
			_TNULL->left = nullptr;
			_TNULL->color = LAST;
			_TNULL->data.first = 1;
			_TNULL->data.second = 1;

			_map = nullptr;
			_start = nullptr;
			_finish = nullptr;
			_root = nullptr;
			_size = 0;
		}

		// template <class InputIterator>
		// map (InputIterator first, InputIterator last, const key_compare & comp = key_compare(),
		//                                                 const allocator_type& alloc = allocator_type());

		// map (const map& x)
		// {
		// 	_alloc = x._alloc;
		// 	_comp = x._comp;

		// 	_TNULL = new nodeMap;
		// 	_TNULL->parent = nullptr;
		// 	_TNULL->right = nullptr;
		// 	_TNULL->left = nullptr;
		// 	_TNULL->color = LAST;
		// 	_TNULL->data.first = 1;
		// 	_TNULL->data.second = 1;

		// 	_map = nullptr;
		// 	_start = nullptr;
		// 	_finish = nullptr;
		// 	_root = nullptr;
		// 	_size = 0;

		// 	if (x._size)
		// 		this->insert(x.begin, x.rbegin);
		// }

		/*
			** -------------------------------- DESTRUCTOR --------------------------------
			*/

		~map()
		{
			this->clear();
			delete this->_TNULL;
		}

		/*
			** --------------------------------- OVERLOAD ---------------------------------
			*/

		// map& operator= (const map& x);

		/*
			** --------------------------------- METHODS ----------------------------------
			*/

		/* Iterators */

		iterator begin()
		{
			if (_size == 0)
				return _TNULL;
			return _start;
		}
		
		const_iterator begin() const
		{
			if (_size == 0)
				return _TNULL;
			return _start;
		}

		iterator end()
		{
			if (_size == 0)
				return _TNULL;
			return _finish->right;
		}
		
		const_iterator end() const
		{
			if (_size == 0)
				return _TNULL;
			return _finish->right;
		}

		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;

		// reverse_iterator rend();
		// const_reverse_iterator rend() const;

		/* Capacity */

		bool empty() const { return (_size == 0 ? true : false); }
		size_type size() const { return this->_size; }
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

			nodeMap *whereAdd = whereAddNode(val, _root);

			if (whereAdd->data.first == val.first)
				return std::make_pair(iterator(whereAdd), false); // rewrite
			else
			{
				nodeMap *newNode = new nodeMap;
				newNode->color = RED;
				newNode->data = val;
				newNode->parent = whereAdd;
				newNode->right = nullptr;
				newNode->left = nullptr;

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
				insertFix(newNode);
				return std::make_pair(iterator(newNode), true); // 11 st
			}
			return std::make_pair(iterator(this->_root), true); // 11 st
		}

		iterator insert(iterator position, const value_type &val)
		{
			nodeMap *whereAdd = position.getptr();

			std::cout << "*** " << whereAdd->data.first << "  ***" << std::endl;

			if ((whereAdd->parent && whereAdd->parent->right == whereAdd && whereAdd->parent->data.first < val.first) ||
				(whereAdd->parent && whereAdd->parent->left == whereAdd && whereAdd->parent->data.first > val.first))
			{
				whereAdd = whereAddNode(val, whereAdd);
				if (whereAdd->data.first > val.first && whereAdd->left == nullptr)
				{
					std::cout << "*** here1 ***" << std::endl;
					nodeMap *newNode = createNode(val);
					newNode->parent = whereAdd;
					newNode->color = RED;

					whereAdd->left = newNode;

					if (_start == whereAdd)
						_start = newNode;
					_size++;
					insertFix(newNode);
					return (iterator)newNode;
				}
				else if (whereAdd->data.first < val.first && (whereAdd->right == nullptr || whereAdd->right == _TNULL))
				{
					std::cout << "*** here2 ***" << std::endl;
					nodeMap *newNode = createNode(val);
					newNode->parent = whereAdd;
					newNode->color = RED;

					whereAdd->right = newNode;

					if (_finish == whereAdd)
					{
						_finish = newNode;
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
										typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
		{
			for ( ; first != last; first++)
			{
				std::cout << "here" << std::endl;
				insert(first.getptr()->data);
			}
		}

		void erase(iterator position)
		{
			nodeMap *x;
			nodeMap *y;
			nodeMap *nodeToBeDeleted = position.getptr();
			int originalColor = nodeToBeDeleted->color;
			std::cout << "ELEMENT TO DELETE IS " << nodeToBeDeleted->data.first << std::endl;

			if (nodeToBeDeleted->left == nullptr)
			{
				// std::cout << "--- 1 ---" << std::endl;
				x = nodeToBeDeleted->right;
				rbTransplant(nodeToBeDeleted, x);

				if (nodeToBeDeleted == _start)
				{
					if (x)
						_start = minimum(x);
					else
						_start = nodeToBeDeleted->parent;
				}
				if (nodeToBeDeleted == _finish)
					_finish = _TNULL->parent;
			}
			else if (nodeToBeDeleted->right == nullptr)
			{
				x = nodeToBeDeleted->left;
				rbTransplant(nodeToBeDeleted, x);
			}
			else
			{
				y = minimum(nodeToBeDeleted->right); // y = 80
				// originalColor = y->color;
				x = y->right; // x = tail

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
				// y->color = nodeToBeDeleted->color;
			}

			// nodeToBeDeleted->parent->left = nullptr;

			if (originalColor == BLACK)
			{
				deleteFix(x);
			}
			_TNULL->color = LAST;
			delete nodeToBeDeleted;
			_size--;
		}

		size_type erase(const key_type &key)
		{
			nodeMap *findNoda = nullptr;
			findNoda = findNodaKey(key);

			if (findNoda == nullptr || findNoda == _TNULL)
				return 0;

			erase(iterator(findNoda));
			return 1;
		}

		// void erase (iterator first, iterator last);

		void swap(map &x)
		{
			ft::itemswap(this->_alloc, x._alloc);
			ft::itemswap(this->_comp, x._comp);
			ft::itemswap(this->_map, x._map);
			ft::itemswap(this->_start, x._start);
			ft::itemswap(this->_finish, x._finish);
			ft::itemswap(this->_root, x._root);
			ft::itemswap(this->_size, x._size);
			ft::itemswap(this->_TNULL, x._TNULL);
		}

		void clear()
		{
			if (empty())
				return;
			_finish->right = nullptr;
			this->clear(this->_root);
			_map = nullptr;
			_start = nullptr;
			_finish = nullptr;
			_root = nullptr;
			_size = 0;
			_TNULL->parent = nullptr;
		}

		/* Observers */

		key_compare key_comp() const { return this->_comp; }

		// value_compare value_comp() const { return value_compare(this->_comp); }
		value_compare value_comp() const { return value_compare(this->_comp); }

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

		void printHelper(nodeMap *root, std::string indent, bool last)
		{
			if (root && root != _TNULL)
			{
				std::cout << indent;
				if (last)
				{
					std::cout << "R----";
					indent += "   ";
				}
				else
				{
					std::cout << "L----";
					indent += "|  ";
				}

				std::string sColor = root->color ? "\x1b[34;1m" : "\x1b[31;1m";
				std::cout << sColor << root->data.first << "\x1b[0m" << std::endl;
				printHelper(root->left, indent, false);
				printHelper(root->right, indent, true);
			}
		}

		void printTree()
		{
			if (_root)
			{
				std::cout << std::endl;
				printHelper(this->_root, "", true);
				std::cout << std::endl;
			}
		}

	private:
		allocator_type _alloc;
		key_compare _comp;
		nodeMap *_map;
		nodeMap *_start;
		nodeMap *_finish;
		nodeMap *_root;
		size_type _size;
		nodeMap *_TNULL;
		// enum color {BLACK, RED, LAST};

		std::pair<iterator, bool> createFirstNode(const value_type &val)
		{
			_map = new nodeMap;

			_map->parent = nullptr;
			_map->right = _TNULL;
			_map->left = nullptr;

			_map->data = val;
			_map->color = BLACK;

			_start = _map;
			_finish = _map;
			_root = _map;
			_size++;

			_TNULL->parent = _map;
			return std::make_pair(iterator(this->_root), true); // 11 st
		}

		nodeMap *createNode(const value_type &val)
		{
			nodeMap *newNode = new nodeMap;

			newNode->parent = nullptr;
			newNode->right = nullptr;
			newNode->left = nullptr;

			newNode->data = val;
			newNode->color = BLACK;

			return newNode;
		}

		nodeMap *whereAddNode(const value_type &value, nodeMap *whereAdd)
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
			if (y->left != nullptr)
			{
				y->left->parent = node;
			}
			y->parent = node->parent;
			if (node->parent == nullptr)
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
			if (y->right != nullptr)
			{
				y->right->parent = node;
			}
			y->parent = node->parent;
			if (node->parent == nullptr)
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

			while (node->parent->color == RED) // пока родитель ноды красный мы в цикле
			{
				if (node->parent->parent->left == node->parent) // если родитель ноды является
				{												//  левым элементом бабушки
					tmp = node->parent;
					if (tmp->parent->right && tmp->parent->right->color == RED) //и правый элемент бабушки красный
					{
						tmp->parent->right->color = BLACK; //делаем дочерние элементы бабушки(а значит и родителя черн)
						tmp->color = BLACK;
						tmp->parent->color = RED;
						node = node->parent->parent; // переходит к ноде бабушки
					}
					else
					{
						if (node == node->parent->right) // иначе если нода  правый ребенок
						{
							node = node->parent; // переходим на родителя
							turnLeft(node);		 //и переварачиваем влево
						}
						node->parent->color = BLACK;	   //делаем родителя черным
						node->parent->parent->color = RED; // а бабушку красным
						turnRight(node->parent->parent);   //поворачиваем бабушку вправо
					}
				}
				else
				{
					if (node->parent->parent->right == node->parent)
					{
						tmp = node->parent;
						if (tmp->parent->left && tmp->parent->left->color == RED) //и левый элемент бабушки красный
						{
							tmp->parent->left->color = BLACK; //делаем дочерние элементы бабушки(а значит и родителя черн)
							tmp->color = BLACK;
							tmp->parent->color = RED;
							node = node->parent->parent; // переходит к ноде бабушки
						}
						else
						{
							if (node == node->parent->left) // иначе если нода  левый ребенок
							{
								node = node->parent; //переходим к родителю
								turnRight(node);	 // поворачиваем вправо
							}
							node->parent->color = BLACK;	   //делаем родителя черным
							node->parent->parent->color = RED; // а бабушку красным
							turnLeft(node->parent->parent);	   //поворачиваем бабушку влево
						}
					}
				}
				if (node == _root)
					break;
			}
			_root->color = BLACK;
		}

		void rbTransplant(nodeMap *nodeToBeDeleted, nodeMap *x) // z , y
		{
			// std::cout << "--- 2 ---" << std::endl;
			if (nodeToBeDeleted->parent == nullptr)
			{
				// std::cout << "---- 1 ----" << std::endl;
				_root = x;
			}
			else if (nodeToBeDeleted == nodeToBeDeleted->parent->left)
			{
				// std::cout << "---- 2 ----" << std::endl;
				nodeToBeDeleted->parent->left = x;
				// std::cout << "---- 2 ----"<< std::endl;
			}
			else if (nodeToBeDeleted == nodeToBeDeleted->parent->right)
			{
				// std::cout << "---- 3 ----" << std::endl;
				nodeToBeDeleted->parent->right = x;
			}

			// std::cout << "here 1"<< std::endl;
			if (x)
			{
				// std::cout << "--- 3 ---" << std::endl;
				x->parent = nodeToBeDeleted->parent;
			}

			// std::cout << "here 2"<< std::endl;
		}

		// For balancing the tree after deletion
		void deleteFix(nodeMap *x)
		{
			nodeMap *s;

			if (x == nullptr)
				return;

			while (x && x != _root && x->color == BLACK)
			{
				if (x->parent && x == x->parent->left) // если х - левый элемент
				{
					s = x->parent->right;
					if (s && s->color == RED)
					{
						s->color = BLACK;
						x->parent->color = RED;
						turnLeft(x->parent);
						s = x->parent->right;
					}

					if (s && s->left && s->right && s->left->color == BLACK && s->right->color == BLACK)
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (s && s->right && s->right->color == BLACK)
						{
							s->left->color = BLACK;
							s->color = RED;
							turnRight(s);
							s = x->parent->right;
						}

						s->color = x->parent->color;
						x->parent->color = BLACK;
						s->right->color = BLACK;
						turnLeft(x->parent);
						x = _root;
					}
				}
				else // если х - правый элемент
				{
					s = x->parent->left;
					if (s && s->color == RED)
					{
						s->color = BLACK;
						x->parent->color = RED;
						turnRight(x->parent);
						s = x->parent->left;
					}

					if (s && s->right && s->right->color == BLACK && s->right->color == BLACK)
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (s && s->left && s->left->color == BLACK)
						{
							s->right->color = BLACK;
							s->color = RED;
							turnLeft(s);
							s = x->parent->left;
						}

						s->color = x->parent->color;
						x->parent->color = BLACK;
						s->left->color = BLACK;
						turnRight(x->parent);
						x = _root;
					}
				}
			}
			x->color = BLACK; // _root->color = BLACK;
		}

		nodeMap *minimum(nodeMap *node)
		{
			while (node->left != nullptr)
				node = node->left;
			return node;
		}

		nodeMap *maximum(nodeMap *node)
		{
			while (node->right != nullptr && node->right != _TNULL)
				node = node->right;
			return node;
		}

		void clear(nodeMap *position)
		{
			if (!position)
				return;
			clear(position->left);
			clear(position->right);
			// std::cout << "*** DELETE " << position->data.first << " ***" << std::endl;
			delete position;
			_size--;
		}

		nodeMap *findNodaKey(const key_type &key)
		{
			nodeMap *findNoda = nullptr;
			nodeMap *begin = _root;

			while (begin != _TNULL && begin != nullptr)
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
			if (findNoda == nullptr || findNoda == _TNULL)
				return nullptr;
			return findNoda;
		}
	};

	/* Non-member function overloads */

}
#endif
