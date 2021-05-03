/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:59:57 by gbroccol          #+#    #+#             */
/*   Updated: 2021/05/03 16:39:14 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <iterator>
#include <iostream>
#include <deque>

namespace ft 
{
	// template <class T, class Container = ft::list <T> >
	template <class T, class Container = std::deque <T> >
	class stack 
    { 
		public: 

			typedef T										value_type;
			typedef Container								container_type;
			typedef size_t									size_type;

			/*
			** -------------------------------- CONSTRUCTOR --------------------------------
			*/
		
			explicit stack (const container_type& ctnr = container_type())
			{
				_cont = ctnr;
			}
			
			/*
			** --------------------------------- METHODS ----------------------------------
			*/
				bool empty() const { return _cont.empty(); }
				size_type size() const { return _cont.size(); }

				value_type& top() { return _cont.back(); }
				const value_type& top() const { return _cont.back(); }

				void push (const value_type& val) { _cont.push_back(val); }

				void pop() { _cont.pop_back(); }	


			/* Non-member function overloads */

				friend bool operator== (const stack <T, Container> & lhs, const stack <T, Container> & rhs)
				{
					return (lhs._cont == rhs._cont ? true : false);
				}

				friend bool operator!= (const stack <T,Container> & lhs, const stack<T,Container>& rhs)
				{
					return (lhs._cont != rhs._cont ? true : false);
				}

				friend bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
				{
					return (lhs._cont < rhs._cont ? true : false);
				}

				friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
				{
					return (lhs._cont <= rhs._cont ? true : false);
				}

				friend bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
				{
					return (lhs._cont > rhs._cont ? true : false);
				}

				friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
				{
					return (lhs._cont >= rhs._cont ? true : false);
				}	

		private:

			Container	_cont;
			
    }; 	
}

#endif
