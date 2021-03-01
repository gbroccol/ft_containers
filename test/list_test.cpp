/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:48:13 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/01 20:44:16 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers_test.hpp"
#include "../containers/list.hpp"
#include "../containers/list_iterator.hpp"

// #include <string>
// #include <cassert>
// #include <algorithm>

#include <list>
// #include <map>
// #include <stack>
// #include <queue>

// #include <iostream>

// // #include "../containers/vector.hpp"
// #include <vector>

// using namespace std; // delete
// using namespace ft; // delete

// #include <iostream>
#include <iomanip>

void list_test()
{
	std::cout << "\x1b[33m" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "|          LIST TESTING          |" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl << std::endl;
	std::cout << "\x1b[0m";

	// int tmp1 = 0;
	// int tmp2 = 0;

	std::list <int> :: iterator itTOL;
	// ft::list <int> :: iterator itML;

	ft::list <int> testMyList;
	std::list <int> testOriginalList;

	std::cout << "\x1b[36m" << " 1. Size test free list ............................................ " << "\x1b[0m";
	if (testMyList.size() == testOriginalList.size())
	{
		std::cout << "\x1b[32m" << "OK" << "\x1b[0m" << std::endl;
		std::cout << std::setw(69) << "Answer: " << testOriginalList.size()<< std::endl;
	}
	else
		std::cout << "\x1b[31m" << "WRONG" << "\x1b[0m" << std::endl;
	
	testMyList.push_front(10);
	testOriginalList.push_front(10);
	std::cout << "\x1b[36m" << " 2. Size test ...................................................... " << "\x1b[0m";
	if (testMyList.size() == testOriginalList.size())
	{
		std::cout << "\x1b[32m" << "OK" << "\x1b[0m" << std::endl;
		std::cout << std::setw(69) << "Answer: " << testOriginalList.size()<< std::endl;
	}
	else
		std::cout << "\x1b[31m" << "WRONG" << "\x1b[0m" << std::endl;

	testMyList.push_back(11);
	testOriginalList.push_back(11);
	std::cout << "\x1b[36m" << " 3. Size test ...................................................... " << "\x1b[0m";
	if (testMyList.size() == testOriginalList.size())
	{
		std::cout << "\x1b[32m" << "OK" << "\x1b[0m" << std::endl;
		std::cout << std::setw(69) << "Answer: " << testOriginalList.size()<< std::endl;
	}
	else
		std::cout << "\x1b[31m" << "WRONG" << "\x1b[0m" << std::endl;

	testMyList.push_front(9);
	testOriginalList.push_front(9);
	std::cout << "\x1b[36m" << " 4. Size test ...................................................... " << "\x1b[0m";
	if (testMyList.size() == testOriginalList.size())
	{
		std::cout << "\x1b[32m" << "OK" << "\x1b[0m" << std::endl;
		std::cout << std::setw(69) << "Answer: " << testOriginalList.size()<< std::endl;
	}
	else
		std::cout << "\x1b[31m" << "WRONG" << "\x1b[0m" << std::endl;

	itTOL = testOriginalList.begin();
	ft::list <int> :: iterator itML00 = testMyList.begin();
	std::cout << "\x1b[36m" << " 5. Begin value test ............................................... " << "\x1b[0m";
	if (*itTOL == *itML00)
	{
		std::cout << "\x1b[32m" << "OK" << "\x1b[0m" << std::endl;
		std::cout << std::setw(69) << "Answer: " << *itTOL << std::endl;
	}
	else
		std::cout << "\x1b[31m" << "WRONG" << "\x1b[0m" << std::endl;

	itTOL = testOriginalList.end();
	ft::list <int> :: iterator itML01 = testMyList.end();
	std::cout << "\x1b[36m" << " 6. End value test ................................................. " << "\x1b[0m";
	if (*itTOL == *itML01)
	{
		std::cout << "\x1b[32m" << "OK" << "\x1b[0m" << std::endl;
		std::cout << std::setw(69) << "Answer: " << *itTOL << std::endl;
	}
	else
	{
		std::cout << "\x1b[31m" << "WRONG" << "\x1b[0m" << std::endl;
		std::cout << std::setw(69) << "Expected answer: " << *itTOL << std::endl;
		std::cout << std::setw(69) << "Your answer: " << *itML01 << std::endl;
	}

	// itTOL = testOriginalList.begin();
	// ft::list <int> :: iterator itML02 = testMyList.begin();

	// itTOL++;
	// itML02++;

	// std::cout << "\x1b[36m" << " 7. Operator ++ test ................................................. " << "\x1b[0m";
	// if (*itTOL == *itML02)
	// {
	// 	std::cout << "\x1b[32m" << "OK" << "\x1b[0m" << std::endl;
	// 	std::cout << std::setw(69) << "Answer: " << *itTOL << std::endl;
	// }
	// else
	// {
	// 	std::cout << "\x1b[31m" << "WRONG" << "\x1b[0m" << std::endl;
	// 	std::cout << std::setw(69) << "Expected answer: " << *itTOL << std::endl;
	// 	std::cout << std::setw(69) << "Your answer: " << *itML02 << std::endl;
	// }

}
