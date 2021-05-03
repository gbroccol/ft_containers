/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:32:21 by gbroccol          #+#    #+#             */
/*   Updated: 2021/05/03 16:39:08 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iterator>
#include <iostream>
#include <deque>

namespace ft 
{
	// template <class T, class Container = ft::list <T> >
	template <class T, class Container = std::deque <T> >
	class queue 
    { 
		public: 

			typedef T										value_type;
			typedef Container								container_type;
			typedef size_t									size_type;

			/*
			** -------------------------------- CONSTRUCTOR --------------------------------
			*/
		
			explicit queue (const container_type& ctnr = container_type())
			{
				_cont = ctnr;
			}
			
			/*
			** --------------------------------- METHODS ----------------------------------
			*/
				bool empty() const { return _cont.empty(); }
				size_type size() const { return _cont.size(); }

				value_type& front() { return _cont.front(); }
				const value_type& front() const { return _cont.front(); }

				value_type& back() { return _cont.back(); }
				const value_type& back() const { return _cont.back(); }

				void push (const value_type& val) { _cont.push_back(val); }

				void pop() { _cont.pop_front(); }	


			/* Non-member function overloads */

				friend bool operator== (const queue <T, Container> & lhs, const queue <T, Container> & rhs)
				{
					return (lhs._cont == rhs._cont ? true : false);
				}

				friend bool operator!= (const queue <T,Container> & lhs, const queue<T,Container>& rhs)
				{
					return (lhs._cont != rhs._cont ? true : false);
				}

				friend bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
				{
					return (lhs._cont < rhs._cont ? true : false);
				}

				friend bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
				{
					return (lhs._cont <= rhs._cont ? true : false);
				}

				friend bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
				{
					return (lhs._cont > rhs._cont ? true : false);
				}

				friend bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
				{
					return (lhs._cont >= rhs._cont ? true : false);
				}	

		private:

			Container	_cont;
			
    }; 	
}

#endif
