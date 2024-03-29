/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:48:20 by gbroccol          #+#    #+#             */
/*   Updated: 2021/05/03 12:51:45 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers_test.hpp"

void memberFunc_stack(int testNmb,  int testAll)
{
	int constructor = 0;
	int empty = 0;
	int size = 0;
	int push = 0;
	int pop = 0;
	int top = 0;

	if(testAll)
	{
		constructor = 1;
		empty = 1;
		size = 1;
		push = 1;
		pop = 1;
		top = 1;	
	}
	if(constructor)
	{
		std::cout << std::endl << "\x1b[33m" << "                              *** CONSTRUCTOR ***                          " << "\x1b[0m" << std::endl;
		std::cout << std::endl << "\x1b[33m" << "constructor test" << "\x1b[0m" << std::endl;
		
		std::deque<int> mydeque (3,100);          // deque with 3 elements
		std::vector<int> myvector (2,200);        // vector with 2 elements

		ft::stack<int> first;                    // empty stack
		ft::stack<int> second (mydeque);         // stack initialized to copy of deque

		ft::stack<int,std::vector<int> > third;  // empty stack using vector
		ft::stack<int,std::vector<int> > fourth (myvector);

		std::stack<int> first2;                 // empty stack
		std::stack<int> second2 (mydeque);       // stack initialized to copy of stack

		std::stack<int,std::vector<int> > third2; // empty stack with list as underlying container
		std::stack<int,std::vector<int> > fourth2 (myvector);

		testFunc(testNmb++,  fourth2.size(), fourth.size(), "size");
		testFunc(testNmb++,  fourth2.top(), fourth.top(), "top");
		testFunc(testNmb++,  second2.size(), second.size(), "size");
		testFunc(testNmb++,  second2.top(), second.top(), "top");

		// getchar();
		// std::system("clear");
	}

	if(empty)
	{
		std::cout << std::endl << "\x1b[33m" << "empty" << "\x1b[0m" << std::endl;
		ft::stack<int> stackEmpty;
		std::stack<int> stackEmptySys;

		testFunc(testNmb++,  stackEmptySys.empty(), stackEmpty.empty(), "empty");

		for(int i = 1; i < 6; i++)
		{
			 stackEmpty.push(i);
			 stackEmptySys.push(i);
		}
		testFunc(testNmb++,  stackEmptySys.empty(), stackEmpty.empty(), "empty");
		
		// getchar();
		// std::system("clear");
	}
	
	if(push)
	{
		std::cout << std::endl << "\x1b[33m" << "push" << "\x1b[0m" << std::endl;
		ft::stack<int> stackPush;
		std::stack<int> stackPushSys;

		stackPush.push(21);
		stackPushSys.push(21);
		testFunc(testNmb++,  stackPushSys.size(), stackPush.size(), "size");
		testFunc(testNmb++,  stackPushSys.top(), stackPush.top(), "top");

		// getchar();
		// std::system("clear");
	}

	if(pop)
	{
		std::cout << std::endl << "\x1b[33m" << "pop" << "\x1b[0m" << std::endl;
		ft::stack<int> stackPop;
		std::stack<int> stackPopSys;
		for(int i = 1; i < 6; i++)
		{
			 stackPop.push(i);
			 stackPopSys.push(i);
		}
		stackPop.pop();
		stackPopSys.pop();
		testFunc(testNmb++,  stackPopSys.size(), stackPop.size(), "size");
		testFunc(testNmb++,  stackPopSys.top(), stackPop.top(), "top");
		// getchar();
		// std::system("clear");
	}
	
	if(size)
	{
		std::cout << std::endl << "\x1b[33m" << "size" << "\x1b[0m" << std::endl;
		ft::stack<int> stackSize;
		std::stack<int> stackSizeSys;
		for(int i = 1; i < 6; i++)
		{
			 stackSize.push(i);
			 stackSizeSys.push(i);
		}
		testFunc(testNmb++,  stackSizeSys.size(), stackSize.size(), "size");
		// getchar();
		// std::system("clear");
	}
}

void non_memberFunc_stack(int testNmb)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** OVERLOADES ***                          " << "\x1b[0m" << std::endl;
	
	std::list<int> stackSys_a ;
	
    stackSys_a.push_back(10);
    stackSys_a.push_back(20);
    stackSys_a.push_back(30);

    std::list<int> stackSys_b ;

    stackSys_b.push_back(10);
    stackSys_b.push_back(20);
    stackSys_b.push_back(30);

    std::list<int> stackSys_c;

    stackSys_c.push_back(30);
    stackSys_c.push_back(20);
    stackSys_c.push_back(10);
	
    std::list<int> stackSys_d;
    std::list<int> stackSys_f;
	
    stackSys_f.push_back(30);

    ft::queue<int, std::list<int> > stack_a(stackSys_a);
    ft::queue<int, std::list<int> > stack_b(stackSys_b);
    ft::queue<int, std::list<int> > stack_c(stackSys_c);
    ft::queue<int, std::list<int> > stack_d(stackSys_d);
    ft::queue<int, std::list<int> > stack_f(stackSys_f);

    testFunc(testNmb++, (stackSys_a == stackSys_b), (stack_a == stack_b), "a == b");
    testFunc(testNmb++, (stackSys_b == stackSys_c), (stack_b == stack_c), "b == c");
    testFunc(testNmb++, (stackSys_a == stackSys_d), (stack_a == stack_d), "a == d");
    testFunc(testNmb++, (stackSys_d == stackSys_c), (stack_d == stack_c), "d == c");
    testFunc(testNmb++, (stackSys_a == stackSys_f), (stack_a == stack_f), "a == f");
    testFunc(testNmb++, (stackSys_f == stackSys_c), (stack_f == stack_c), "f == c");
	
    testFunc(testNmb++, (stackSys_a != stackSys_b), (stack_a != stack_b), "a != b");
    testFunc(testNmb++, (stackSys_b != stackSys_c), (stack_b != stack_c), "b != c");
    testFunc(testNmb++, (stackSys_a != stackSys_d), (stack_a != stack_d), "a != d");
    testFunc(testNmb++, (stackSys_d != stackSys_c), (stack_d != stack_c), "d != c");
    testFunc(testNmb++, (stackSys_a != stackSys_f), (stack_a != stack_f), "a != f");
    testFunc(testNmb++, (stackSys_f != stackSys_c), (stack_f != stack_c), "f != c");
	
    testFunc(testNmb++, (stackSys_a < stackSys_b), (stack_a < stack_b), "a < b");
    testFunc(testNmb++, (stackSys_b < stackSys_c), (stack_b < stack_c), "b < c");
    testFunc(testNmb++, (stackSys_a < stackSys_d), (stack_a < stack_d), "a < d");
    testFunc(testNmb++, (stackSys_d < stackSys_c), (stack_d < stack_c), "d < c");
    testFunc(testNmb++, (stackSys_a < stackSys_f), (stack_a < stack_f), "a < f");
    testFunc(testNmb++, (stackSys_f < stackSys_c), (stack_f < stack_c), "f < c");
	
    testFunc(testNmb++, (stackSys_a > stackSys_b), (stack_a > stack_b), "a > b");
    testFunc(testNmb++, (stackSys_b > stackSys_c), (stack_b > stack_c), "b > c");
    testFunc(testNmb++, (stackSys_a > stackSys_d), (stack_a > stack_d), "a > d");
    testFunc(testNmb++, (stackSys_d > stackSys_c), (stack_d > stack_c), "d > c");
    testFunc(testNmb++, (stackSys_a > stackSys_f), (stack_a > stack_f), "a > f");
    testFunc(testNmb++, (stackSys_f > stackSys_c), (stack_f > stack_c), "f > c");
	
    testFunc(testNmb++, (stackSys_a <= stackSys_b), (stack_a <= stack_b), "a <= b");
    testFunc(testNmb++, (stackSys_b <= stackSys_c), (stack_b <= stack_c), "b <= c");
    testFunc(testNmb++, (stackSys_a <= stackSys_d), (stack_a <= stack_d), "a <= d");
    testFunc(testNmb++, (stackSys_d <= stackSys_c), (stack_d <= stack_c), "d <= c");
    testFunc(testNmb++, (stackSys_a <= stackSys_f), (stack_a <= stack_f), "a <= f");
    testFunc(testNmb++, (stackSys_f <= stackSys_c), (stack_f <= stack_c), "f <= c");
	
    testFunc(testNmb++, (stackSys_a >= stackSys_b), (stack_a >= stack_b), "a >= b");
    testFunc(testNmb++, (stackSys_b >= stackSys_c), (stack_b >= stack_c), "b >= c");
    testFunc(testNmb++, (stackSys_a >= stackSys_d), (stack_a >= stack_d), "a >= d");
    testFunc(testNmb++, (stackSys_d >= stackSys_c), (stack_d >= stack_c), "d >= c");
    testFunc(testNmb++, (stackSys_a >= stackSys_f), (stack_a >= stack_f), "a >= f");
    testFunc(testNmb++, (stackSys_f >= stackSys_c), (stack_f >= stack_c), "f >= c");
}

void stack_test()
{
	std::cout << "\x1b[32m" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "|          STACK TESTING         |" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl << std::endl;
	std::cout << "\x1b[0m";
	int testNmb = 0;
	int testAll = 1;
	memberFunc_stack(testNmb, testAll);
	non_memberFunc_stack(testNmb);
}
