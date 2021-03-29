/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   containers_test.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:45:56 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/29 21:14:53 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINERS_TEST_HPP
#define CONTAINERS_TEST_HPP

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>

#include <list>
#include <vector>
#include <map>

#include "../containers/list/list.hpp"
#include "../containers/vector/vector.hpp"
#include "../containers/map/map.hpp"

void		list_test(void);
void		map_test(void);
// void		queue_test(void);
// void		stack_test(void);
void		vector_test(void);

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

/* 
** list 
*/

template <typename T>
void print_std_list (std::string testName, T List)
{
	std::cout << testName;
	for (std::list<int>::iterator it = List.begin(); it != List.end(); it++)
	{
		std::cout << ' ' << *it;
	}
	std::cout << '\n';
}

template <typename T>
void print_ft_list (std::string testName, T List)
{
	std::cout << testName;
	for (ft::list <int> ::iterator it = List.begin(); it != List.end(); it++)
	{
		std::cout << ' ' << *it;
	}
	std::cout << '\n';
}

/* 
** vector 
*/

template <typename T>
void print_std_vector (std::string testName, T & Vector)
{
	std::cout << testName;

	for (std::vector <int> :: iterator it = Vector.begin(); it != Vector.end(); it++)
	{
		std::cout << ' ' << *it;
	}
	std::cout << '\n';
}

template <typename T>
void print_ft_vector (std::string testName,  T & Vector)
{
	std::cout << testName;

	for (ft::vector <int> ::iterator it = Vector.begin(); it != Vector.end(); it++)
	{
		std::cout << ' ' << *it;
	}
	std::cout << '\n';
}

/* 
** Map 
*/

template <typename T>
void print_std_map (std::string testName, T & Map)
{
	std::cout << testName << " |";
	std::map <int, int> :: iterator itSys = Map.begin();
	for ( ; itSys != Map.end(); itSys++)
	{
		std::cout << "" << std::setw(7) << itSys->first << "    | ";
	}
	std::cout << '\n' << "              |" ;

	itSys = Map.begin();
	for (; itSys != Map.end(); itSys++)
	{
		std::cout << "" << std::setw(7) << itSys->second << "    | ";
	}
	std::cout << '\n' << '\n';
}

template <typename T>
void print_ft_map (std::string testName, T & Map)
{
	std::cout << testName << " |";
	ft::map <int, int> :: iterator itUserBegin = Map.begin();


	// std::cout << "                                            find sega"<< std::endl;
	
	for (; itUserBegin != Map.end(); itUserBegin++)
	{
		std::cout << "" << itUserBegin.getColor() << std::setw(7) << itUserBegin->first << "\x1b[0m    | ";
	}
	std::cout << "" << itUserBegin.getColor() << itUserBegin->first << "\x1b[0m | ";
	std::cout << '\n' << "              |" ;



	itUserBegin = Map.begin();
	for (; itUserBegin != Map.end(); itUserBegin++)
	{
		std::cout << "" << itUserBegin.getColor() << std::setw(7) << itUserBegin->second << "\x1b[0m    | ";
	}
	std::cout << "" << itUserBegin.getColor() << itUserBegin->second << "\x1b[0m | ";
	std::cout << '\n' << '\n';
}

// template <typename T>
// void print_std_map_inv (std::string testName, T & Map)
// {
// 	std::cout << testName << " |";
// 	std::map <int, int> :: iterator itSys = Map.end();
// 	itSys--;
// 	for ( ; itSys != Map.begin(); itSys--)
// 	{
// 		std::cout << "" << std::setw(7) << itSys->first << "    | ";
// 	}
// 	std::cout << "" << std::setw(7) << itSys->first << "    | ";
// 	std::cout << '\n' << "              |" ;

// 	itSys = Map.end();
// 	itSys--;
// 	for (; itSys != Map.begin(); itSys--)
// 	{
// 		std::cout << "" << std::setw(7) << itSys->second << "    | ";
// 	}
// 	std::cout << "" << std::setw(7) << itSys->second << "    | ";
// 	std::cout << '\n' << '\n';
// }

// template <typename T>
// void print_ft_map_inv (std::string testName, T & Map)
// {
// 	std::cout << testName << " |";
// 	ft::map <int, int> :: iterator itUserBegin = Map.end();

// 	std::cout << "here 1 " << std::endl;
// 	itUserBegin--;
// 	std::cout << "here 4 " << std::endl;
	
// 	for (; itUserBegin != Map.begin(); itUserBegin--)
// 	{
// 		std::cout << "" << itUserBegin.getColor() << std::setw(7) << itUserBegin->first << "\x1b[0m    | ";
// 	}
// 	std::cout << "" << itUserBegin.getColor() << std::setw(7) << itUserBegin->first << "\x1b[0m    | ";
// 	std::cout << '\n' << "              |" ;
// 	itUserBegin--;
// 	itUserBegin = Map.end();
// 	for (; itUserBegin != Map.begin(); itUserBegin--)
// 	{
// 		std::cout << "" << itUserBegin.getColor() << std::setw(7) << itUserBegin->second << "\x1b[0m    | ";
// 	}
// 	std::cout << "" << itUserBegin.getColor() << std::setw(7) << itUserBegin->second << "\x1b[0m    | ";
// 	std::cout << '\n' << '\n';
// }

#endif
