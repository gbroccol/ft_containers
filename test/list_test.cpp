/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:48:13 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/02 19:44:01 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers_test.hpp"
#include "../containers/list.hpp"
#include "../containers/list_iterator.hpp"

// #include <string>
// #include <cassert>
// #include <algorithm>

// #include <list>
// #include <map>
// #include <stack>
// #include <queue>

// #include <iostream>

// #include <vector>

// #include <iostream>
// #include <iomanip>



void				list_test()
{
	int testNmb = 0;
	
	std::cout << "\x1b[33m" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "|          LIST TESTING          |" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl << std::endl;
	std::cout << "\x1b[0m";

	ft::list <int> testMyList;
	std::list <int> testOriginalList;

	std::list <int> :: iterator sysData;
	ft::list <int> :: iterator userData = testMyList.begin(); // delete  = testMyList.begin()

	/*
	*
	*
	*
	*			SIZE
	*
	*
	*
	*/

	std::cout << std::endl << "\x1b[33m" << "                                 *** SIZE ***                          " << "\x1b[0m" << std::endl;

	testFunc(testNmb++, testMyList.empty(), testOriginalList.empty(), "Empty list - true");

	testFunc(testNmb++, testMyList.size(), testOriginalList.size(), "Size test free list");
	
	testMyList.push_front(10);
	testOriginalList.push_front(10);
	testFunc(testNmb++, testMyList.size(), testOriginalList.size(), "Size test");

	testFunc(testNmb++, testMyList.empty(), testOriginalList.empty(), "Empty list - false");

	testMyList.push_back(11);
	testOriginalList.push_back(11);
	testFunc(testNmb++, testMyList.size(), testOriginalList.size(), "Size test free list");

	testMyList.push_front(9);
	testOriginalList.push_front(9);
	testFunc(testNmb++, testMyList.size(), testOriginalList.size(), "Size test free list");
	
	/*
	*
	*
	*
	*			VALUES AND OPERATORS
	*
	*
	*
	*/

	std::cout << std::endl << "\x1b[33m" << "                         *** VALUES AND OPERATORS ***                          " << "\x1b[0m" << std::endl;

	try
	{
		ft::list  <int> testMyListTest;
		std::list <int> testOriginalListTest;

		std::list <int> :: iterator sysDataTest = testOriginalListTest.begin();
		ft::list <int> :: iterator userDataTest = testMyListTest.begin();

		testFunc(testNmb++, *sysDataTest, *userDataTest, "Operators test *a");

		sysDataTest++;
		userDataTest++;
		testFunc(testNmb++, *sysDataTest, *userDataTest, "Operators test a++");

		sysDataTest--;
		userDataTest--;
		testFunc(testNmb++, *sysDataTest, *userDataTest, "Operators test a--");

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	




	
	sysData = testOriginalList.begin();
	userData = testMyList.begin();
	testFunc(testNmb++, *sysData, *userData, "Operators test *a");



	sysData = testOriginalList.begin();
	userData = testMyList.begin();
	sysData++;
	userData++;
	testFunc(testNmb++, *sysData, *userData, "Operators test a++");

	sysData++;
	userData++;
	testFunc(testNmb++, *sysData, *userData, "Operators test a++");

	sysData++;
	userData++;
	sysData++;
	userData++;
	testFunc(testNmb++, *sysData, *userData, "Operators test a++");

	// sysData = testOriginalList.begin();
	// userData = testMyList.begin();
	// sysData++;
	// itML02++;
	std::cout << "\x1b[36m" << testNmb++ << ". Begin value test ++a ...................................... " << "\x1b[0m";
	// if (*sysData == *itML02)
	// {
	// 	std::cout << "\x1b[32m" << "OK" << "\x1b[0m" << std::endl;
	// 	std::cout << std::setw(69) << "Answer: " << *sysData << std::endl;
	// }
	// else
		std::cout << "\x1b[31m" << "NO TEST" << "\x1b[0m" << std::endl;

	sysData = testOriginalList.end();
	userData = testMyList.end();
	sysData--;
	userData--;
	testFunc(testNmb++, *sysData, *userData, "End value test a--");

	// sysData = testOriginalList.end();
	// userData = testMyList.end();
	// sysData--;
	// userData--;
	std::cout << "\x1b[36m" << testNmb++ << ". End value test --a ...................................... " << "\x1b[0m";
	// if (*itTOL == *userData)
	// {
	// 	std::cout << "\x1b[32m" << "OK" << "\x1b[0m" << std::endl;
	// 	std::cout << std::setw(69) << "Answer: " << *itTOL << std::endl;
	// }
	// else
	// {
		std::cout << "\x1b[31m" << "NO TEST" << "\x1b[0m" << std::endl;
	// 	std::cout << std::setw(69) << "Expected answer: " << *itTOL << std::endl;
	// 	std::cout << std::setw(69) << "Your answer: " << *userData << std::endl;
	// }

	
	// try
	// {
	// 	ft::list <int> testMyList1;
	// 	std::list <int> testOriginalList1;

	// 	testMyList1.push_front(55);
	// 	testOriginalList1.push_front(55);


		
	// 	sysData = testOriginalList.end();
	// 	userData = testMyList.end();
		
	// 	sysData = testOriginalList.begin();
	// 	userData = testMyList.begin();

		std::cout << "\x1b[36m" << testNmb++ << ". End value test a=b ...................................... " << "\x1b[0m";
	// 	if (*sysData == *userData)
	// 	{
	// 		std::cout << "\x1b[32m" << "OK" << "\x1b[0m" << std::endl;
	// 		std::cout << std::setw(69) << "Answer: " << *sysData << std::endl;
	// 	}
	// 	else
	// 	{
			std::cout << "\x1b[31m" << "NO TEST" << "\x1b[0m" << std::endl;
	// 		std::cout << std::setw(69) << "Expected answer: " << *sysData << std::endl;
	// 		std::cout << std::setw(69) << "Your answer: " << *userData << std::endl;
	// 	}


		
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	
	/*
	*
	*
	*
	*			CONSTRUCTOR
	*
	*
	*
	*/

	std::cout << std::endl << "\x1b[33m" << "                              *** CONSTRUCTOR ***                          " << "\x1b[0m" << std::endl;

	ft::list  <int> userList((size_t)10, 42);
	std::list <int> sysList((size_t)10, 42);

	testFunc(testNmb++, sysList.size(), userList.size(), "Constructor list(size, value)");

	std::list <int> :: iterator sysIterator = sysList.begin();
	ft::list <int> :: iterator userIterator = userList.begin();

	testFunc(testNmb++, *sysIterator, *userIterator, "Constructor list(size, value)");

	/*		COPY		*/
	// ft::list  <int> userListCopy(userList);
	// std::list <int> sysListCopy(sysList);
	// testFunc(testNmb++, sysListCopy.size(), userListCopy.size(), "Constructor copy");
	
	// sysIterator = sysListCopy.begin();
	// userIterator = userListCopy.begin();
	
	// testFunc(testNmb++, *sysIterator, *userIterator, "Constructor copy - value");

	userList.push_front(0);
	sysList.push_front(0);

	sysIterator = sysList.begin();
	userIterator = userList.begin();

	testFunc(testNmb++, *sysIterator, *userIterator, "Front value is");

	userList.push_back(50);
	sysList.push_back(50);

	sysIterator = sysList.end();
	userIterator = userList.end();

	sysIterator--;
	userIterator--;

	testFunc(testNmb++, *sysIterator, *userIterator, "Back value is");

	userList.pop_front();
	sysList.pop_front();

	sysIterator = sysList.begin();
	userIterator = userList.begin();

	testFunc(testNmb++, *sysIterator, *userIterator, "Front value is");

	userList.pop_back();
	sysList.pop_back();

	sysIterator = sysList.end();
	userIterator = userList.end();

	sysIterator--;
	userIterator--;

	testFunc(testNmb++, *sysIterator, *userIterator, "Back value is");

	/*
	*
	*
	*
	*			Element access
	*
	*
	*
	*/

	std::cout << std::endl << "\x1b[33m" << "                              *** ELEMENT ACCESS ***                          " << "\x1b[0m" << std::endl;

	userList.push_front(11111111);
	sysList.push_front(11111111);

	userList.push_back(22222222);
	sysList.push_back(22222222);
	
	testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
	testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");
	
	/*
	*
	*
	*
	*			Modifiers
	*
	*
	*
	*/

	std::cout << std::endl << "\x1b[33m" << "                              *** MODIFIERS ***                          " << "\x1b[0m" << std::endl;

	testFunc(testNmb++, sysList.size(), userList.size(), "Size is (assign 1)");

	/*		assign 1		*/
	userList.assign(5, 21);
	sysList.assign(5, 21);
	testFunc(testNmb++, sysList.size(), userList.size(), "Size is (assign 1)");
	testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (assign 1)");
	testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (assign 1)");
	std::cout << std::endl;

	/*		assign 2		*/

	// userList.push_front(11111111);
	// sysList.push_front(11111111);

	// userList.push_back(22222222);
	// sysList.push_back(22222222);
	
	// // userList.assign(5, 21);
	// sysList.assign(sysList.begin(), sysList.end());
	// testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
	// testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
	// testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

	/*		insert 1		*/
	sysList.clear();
	userList.clear();

	sysList.assign(1, 100);
	userList.assign(1, 100);

	sysList.insert(sysList.begin(), 5);
	userList.insert(userList.begin(), 5);

	testFunc(testNmb++, sysList.size(), userList.size(), "Size is (insert 1)");
	testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (insert 1)");
	testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (insert 1)");
	std::cout << std::endl;
	
	/*		insert 2		*/
	sysList.clear();
	userList.clear();

	sysList.assign(1, 100);
	userList.assign(1, 100);

	sysList.insert(sysList.begin(), 3, 5);
	userList.insert(userList.begin(), 3, 5);

	testFunc(testNmb++, sysList.size(), userList.size(), "Size is (insert 2)");
	testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (insert 2)");
	testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (insert 2)");
	std::cout << std::endl;

	/*		swap 1		*/
	// sysList.clear();
	// userList.clear();

	// std::list <int> sysListSwap1(5, 100);
	// ft::list <int> userListSwap1(5, 100);

	// std::list <int> sysListSwap2(10, 500);
	// ft::list <int> userListSwap2(10, 500);

	// std::cout << "*** BEFORE ***" << std::endl;

	// std::cout << " SysListSwap1:";
	// for (std::list<int>::iterator it = sysListSwap1.begin(); it != sysListSwap1.end(); it++)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';
  
	// std::cout << " SysListSwap2:";
	// for (std::list<int>::iterator it = sysListSwap2.begin(); it != sysListSwap2.end(); it++)
	// 	std::cout << ' ' << *it;
	// std::cout << std::endl << std::endl;

	// std::cout << "*** BEFORE ***" << std::endl;

	// std::cout << "UserListSwap1:";
	// for (ft::list<int>::iterator it = userListSwap1.begin(); it != userListSwap1.end(); it++)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';
  
	// std::cout << "UserListSwap2:";
	// for (ft::list<int>::iterator it = userListSwap2.begin(); it != userListSwap2.end(); it++)
	// 	std::cout << ' ' << *it;
	// std::cout << std::endl << std::endl;

	// sysListSwap1.swap(sysListSwap2);
	// userListSwap1.swap(userListSwap2);

	// std::cout << "*** AFTER ***" << std::endl;
	// std::cout << " SysListSwap1:";
	// for (std::list<int>::iterator it = sysListSwap1.begin(); it != sysListSwap1.end(); it++)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';
  
	// std::cout << " SysListSwap2:";
	// for (std::list<int>::iterator it = sysListSwap2.begin(); it != sysListSwap2.end(); it++)
	// 	std::cout << ' ' << *it;
	// std::cout << std::endl << std::endl;

	// std::cout << "*** AFTER ***" << std::endl;

	// std::cout << "UserListSwap1:";
	// for (ft::list<int>::iterator it = userListSwap1.begin(); it != userListSwap1.end(); it++)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';
  
	// std::cout << "UserListSwap2:";
	// for (ft::list<int>::iterator it = userListSwap2.begin(); it != userListSwap2.end(); it++)
	// 	std::cout << ' ' << *it;
	// std::cout << std::endl << std::endl;

  
	
}
