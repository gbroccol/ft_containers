/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:48:18 by gbroccol          #+#    #+#             */
/*   Updated: 2021/05/03 12:51:11 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers_test.hpp"

void memberFunc_queue(int testNmb,  int testAll)
{
	int constructor = 1;
	int empty = 0;
	int size = 0;
	int front = 0;
	int back = 0;
	int push = 0;
	int pop = 0;

	testNmb++;

	if(testAll)
	{
		constructor = 1;
		empty = 1;
		size = 1;
		front = 1;
		back = 1;
		push = 1;
		pop = 1;	
	}
	
	if(constructor)
	{
		std::cout << std::endl << "\x1b[33m" << "                              *** CONSTRUCTOR ***                          " << "\x1b[0m" << std::endl;
		std::cout << std::endl << "\x1b[33m" << "constructor" << "\x1b[0m" << std::endl;

		std::queue <int> queueSys0;                 // empty queue
		ft::queue  <int> queueUser0;                 // empty queue
	
		std::list <int> mylist (2, 200);         // list with 2 elements
		ft::queue <int, std::list <int> > queueUser1 (mylist);
		std::queue<int, std::list<int> > queueSys1 (mylist);

		queueSys1.push(5);
		queueUser1.push(5);

		testFunc(testNmb++,  queueSys1.empty(), queueUser1.empty(), "empty");
		testFunc(testNmb++,  queueSys1.size(), queueUser1.size(), "size");
		testFunc(testNmb++, queueSys1.front(), queueUser1.front(), "front");
		testFunc(testNmb++, queueSys1.back(), queueUser1.back(), "back");
		
		queueSys1.pop();
		queueUser1.pop();

		testFunc(testNmb++,  queueSys1.empty(), queueUser1.empty(), "empty");
		testFunc(testNmb++,  queueSys1.size(), queueUser1.size(), "size");
		testFunc(testNmb++, queueSys1.front(), queueUser1.front(), "front");
		testFunc(testNmb++, queueSys1.back(), queueUser1.back(), "back");
		// getchar();
		// std::system("clear");
	}

	if(empty)
	{
		std::cout << std::endl << "\x1b[33m" << "empty" << "\x1b[0m" << std::endl;
		ft::queue<int> queueEmpty;
		std::queue<int> queueEmptySys;

		testFunc(testNmb++,  queueEmptySys.empty(), queueEmpty.empty(), "empty");

		for(int i = 1; i < 6; i++)
		{
			 queueEmpty.push(i);
			 queueEmptySys.push(i);
		}
		testFunc(testNmb++,  queueEmptySys.empty(), queueEmpty.empty(), "empty");
		
		// getchar();
		// std::system("clear");
	}
	
	if(push)
	{
		std::cout << std::endl << "\x1b[33m" << "push" << "\x1b[0m" << std::endl;
		ft::queue<int> queuePush;
		std::queue<int> queuePushSys;

		queuePush.push(21);
		queuePushSys.push(21);
		testFunc(testNmb++,  queuePushSys.size(), queuePush.size(), "size");
		testFunc(testNmb++, queuePushSys.front(), queuePush.front(), "front");
		testFunc(testNmb++, queuePushSys.back(), queuePush.back(), "back");

		// getchar();
		// std::system("clear");
	}

	if(pop)
	{
		std::cout << std::endl << "\x1b[33m" << "pop" << "\x1b[0m" << std::endl;
		ft::queue<int> queuePop;
		std::queue<int> queuePopSys;
		for(int i = 1; i < 6; i++)
		{
			 queuePop.push(i);
			 queuePopSys.push(i);
		}
		queuePop.pop();
		queuePopSys.pop();
		testFunc(testNmb++,  queuePopSys.size(), queuePop.size(), "size");
		testFunc(testNmb++, queuePopSys.front(), queuePop.front(), "front");
		testFunc(testNmb++, queuePopSys.back(), queuePop.back(), "back");
		// getchar();
		// std::system("clear");
	}
	
	if(size)
	{
		std::cout << std::endl << "\x1b[33m" << "size" << "\x1b[0m" << std::endl;
		ft::queue<int> queueSize;
		std::queue<int> queueSizeSys;
		for(int i = 1; i < 6; i++)
		{
			 queueSize.push(i);
			 queueSizeSys.push(i);
		}
		testFunc(testNmb++,  queueSizeSys.size(), queueSize.size(), "size");
		// getchar();
		// std::system("clear");
	}

	if(front)
	{
		std::cout << std::endl << "\x1b[33m" << "front" << "\x1b[0m" << std::endl;
		ft::queue<int> queueFront;
		std::queue<int> queueFrontSys;

		for(int i = 1; i < 6; i++)
		{
			 queueFront.push(i);
			 queueFrontSys.push(i);
		}
		testFunc(testNmb++,  queueFrontSys.size(), queueFront.size(), "size");
		testFunc(testNmb++,  queueFrontSys.front(), queueFront.front(), "front");

		// getchar();
		// std::system("clear");
	}

	if(back)
	{
		std::cout << std::endl << "\x1b[33m" << "back" << "\x1b[0m" << std::endl;
		ft::queue<int> queueBack;
		std::queue<int> queueBackSys;

		for(int i = 1; i < 6; i++)
		{
			 queueBack.push(i);
			 queueBackSys.push(i);
		}
		testFunc(testNmb++,  queueBackSys.size(), queueBack.size(), "size");
		testFunc(testNmb++,  queueBackSys.back(), queueBack.back(), "back");
		
		// getchar();
		// std::system("clear");
	}
}

void non_memberFunc_queue(int testNmb)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** OVERLOADES ***                          " << "\x1b[0m" << std::endl;
	std::list<int> queueSys_a ;
    queueSys_a.push_back(10);
    queueSys_a.push_back(20);
    queueSys_a.push_back(30);
    std::list<int> queueSys_b ;
    queueSys_b.push_back(10);
    queueSys_b.push_back(20);
    queueSys_b.push_back(30);
    std::list<int> queueSys_c;
    queueSys_c.push_back(30);
    queueSys_c.push_back(20);
    queueSys_c.push_back(10);
    std::list<int> queueSys_d;
    std::list<int> queueSys_f;
    queueSys_f.push_back(30);
	
    ft::queue<int, std::list<int> > queue_a(queueSys_a);
    ft::queue<int, std::list<int> > queue_b(queueSys_b);
    ft::queue<int, std::list<int> > queue_c(queueSys_c);
    ft::queue<int, std::list<int> > queue_d(queueSys_d);
    ft::queue<int, std::list<int> > queue_f(queueSys_f);

    testFunc(testNmb++, (queueSys_a == queueSys_b), (queue_a == queue_b), "a == b");
    testFunc(testNmb++, (queueSys_b == queueSys_c), (queue_b == queue_c), "b == c");
    testFunc(testNmb++, (queueSys_a == queueSys_d), (queue_a == queue_d), "a == d");
    testFunc(testNmb++, (queueSys_d == queueSys_c), (queue_d == queue_c), "d == c");
    testFunc(testNmb++, (queueSys_a == queueSys_f), (queue_a == queue_f), "a == f");
    testFunc(testNmb++, (queueSys_f == queueSys_c), (queue_f == queue_c), "f == c");
    testFunc(testNmb++, (queueSys_a != queueSys_b), (queue_a != queue_b), "a != b");
    testFunc(testNmb++, (queueSys_b != queueSys_c), (queue_b != queue_c), "b != c");
    testFunc(testNmb++, (queueSys_a != queueSys_d), (queue_a != queue_d), "a != d");
    testFunc(testNmb++, (queueSys_d != queueSys_c), (queue_d != queue_c), "d != c");
    testFunc(testNmb++, (queueSys_a != queueSys_f), (queue_a != queue_f), "a != f");
    testFunc(testNmb++, (queueSys_f != queueSys_c), (queue_f != queue_c), "f != c");
    testFunc(testNmb++, (queueSys_a < queueSys_b), (queue_a < queue_b), "a < b");
    testFunc(testNmb++, (queueSys_b < queueSys_c), (queue_b < queue_c), "b < c");
    testFunc(testNmb++, (queueSys_a < queueSys_d), (queue_a < queue_d), "a < d");
    testFunc(testNmb++, (queueSys_d < queueSys_c), (queue_d < queue_c), "d < c");
    testFunc(testNmb++, (queueSys_a < queueSys_f), (queue_a < queue_f), "a < f");
    testFunc(testNmb++, (queueSys_f < queueSys_c), (queue_f < queue_c), "f < c");
    testFunc(testNmb++, (queueSys_a > queueSys_b), (queue_a > queue_b), "a > b");
    testFunc(testNmb++, (queueSys_b > queueSys_c), (queue_b > queue_c), "b > c");
    testFunc(testNmb++, (queueSys_a > queueSys_d), (queue_a > queue_d), "a > d");
    testFunc(testNmb++, (queueSys_d > queueSys_c), (queue_d > queue_c), "d > c");
    testFunc(testNmb++, (queueSys_a > queueSys_f), (queue_a > queue_f), "a > f");
    testFunc(testNmb++, (queueSys_f > queueSys_c), (queue_f > queue_c), "f > c");
    testFunc(testNmb++, (queueSys_a <= queueSys_b), (queue_a <= queue_b), "a <= b");
    testFunc(testNmb++, (queueSys_b <= queueSys_c), (queue_b <= queue_c), "b <= c");
    testFunc(testNmb++, (queueSys_a <= queueSys_d), (queue_a <= queue_d), "a <= d");
    testFunc(testNmb++, (queueSys_d <= queueSys_c), (queue_d <= queue_c), "d <= c");
    testFunc(testNmb++, (queueSys_a <= queueSys_f), (queue_a <= queue_f), "a <= f");
    testFunc(testNmb++, (queueSys_f <= queueSys_c), (queue_f <= queue_c), "f <= c");
    testFunc(testNmb++, (queueSys_a >= queueSys_b), (queue_a >= queue_b), "a >= b");
    testFunc(testNmb++, (queueSys_b >= queueSys_c), (queue_b >= queue_c), "b >= c");
    testFunc(testNmb++, (queueSys_a >= queueSys_d), (queue_a >= queue_d), "a >= d");
    testFunc(testNmb++, (queueSys_d >= queueSys_c), (queue_d >= queue_c), "d >= c");
    testFunc(testNmb++, (queueSys_a >= queueSys_f), (queue_a >= queue_f), "a >= f");
    testFunc(testNmb++, (queueSys_f >= queueSys_c), (queue_f >= queue_c), "f >= c");
    // getchar();
}

void queue_test()
{
	std::cout << "\x1b[32m" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "|          QUEUE TESTING         |" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl << std::endl;
	std::cout << "\x1b[0m";

	int testNmb = 0;
	int testAll = 1;

	memberFunc_queue(testNmb,  testAll);
	non_memberFunc_queue(testNmb);
}
