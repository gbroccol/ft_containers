/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   containers_test.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:45:56 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/03 19:04:47 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINERS_TEST_HPP
#define CONTAINERS_TEST_HPP

#include <iostream>
#include <iomanip>
#include <cstdio>

#include <list>

#include "../containers/list.hpp"
#include "../containers/list_iterator.hpp"

void		list_test(void);
// void		map_test(void);
// void		queue_test(void);
// void		stack_test(void);
// void		vector_test(void);

template <typename T>
void				testFunc(int testNmb, T sysValue, T userValue, std::string testName)
{
	int len = testName.length();
	
	if (testNmb <= 9)
		std::cout << " ";
	
	std::cout << "\x1b[36m" << testNmb++ << ". " << testName;
	std::cout << " ";
	for (int i = 0; (i + len) < 80; i++)
		std::cout << ".";
	std::cout << " ";
	std::cout << "\x1b[0m";
	
	if (sysValue == userValue)
	{
		std::cout << "\x1b[32m" << "OK" << "\x1b[0m" << std::endl;
		std::cout << std::setw(86) << "Answer: " << sysValue << std::endl;
	}
	else
	{
		std::cout << "\x1b[31m" << "WRONG" << "\x1b[0m" << std::endl;
		std::cout << std::setw(86) << "Expected answer: " << sysValue << std::endl;
		std::cout << std::setw(86) << "Your answer: " << userValue << std::endl;
	}	
}

template <typename T>
void print_std_list (std::string testName, T List)
{
	std::cout << testName;
	for (std::list<int>::iterator it = List.begin(); it != List.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

template <typename T>
void print_ft_list (std::string testName, T List)
{
	std::cout << testName;
	for (ft::list <int> ::iterator it = List.begin(); it != List.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

#endif
