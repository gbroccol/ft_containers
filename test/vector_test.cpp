/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnowbir <ssnowbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:04:46 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/16 15:39:46 by ssnowbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../containers/vector/vector.hpp"
#include "containers_test.hpp"

#include <string>
#include <cassert>
#include <algorithm>

// #include <vector>
// #include <map>
// #include <stack>
// #include <queue>

#include <iostream>

#include <vector>

// using namespace std; // delete
// using namespace ft; // delete


void				constructor_vector(int testNmb)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** CONSTRUCTOR ***                          " << "\x1b[0m" << std::endl;

	std::cout << std::endl << "\x1b[33m" << "simple constructor" << "\x1b[0m" << std::endl;	
	ft::vector<int> vectorConstr(4, 100);
	std::vector<int> vectorConstrSys(4,100);

	ft::vector<int>::iterator itConstr = vectorConstr.begin();
	std::vector<int>::iterator itConstrSys = vectorConstrSys.begin();
	ft::vector<int>::iterator itConstrEnd;
	itConstrEnd = vectorConstr.end();
	std::vector<int>::iterator itConstrSysEnd;
	itConstrSysEnd = vectorConstrSys.end();

	testFunc(testNmb++, *itConstrSys, *itConstr, "vector begin()");
	testFunc(testNmb++, vectorConstrSys.size(), vectorConstr.size(),  "vector size()");
	testNmb++;
	getchar();
	system("clear");

	std::cout << std::endl << "\x1b[33m" << "copy constructor" << "\x1b[0m" << std::endl;
	ft::vector  <int> userVectorCopy(vectorConstr);
	std::vector <int> sysVectorCopy(vectorConstrSys);
	testFunc(testNmb++, sysVectorCopy.size(), userVectorCopy.size(), "Constructor copy");
	
	std::vector<int>::iterator itConstrCopySys = sysVectorCopy.begin();
	ft::vector<int>::iterator itConstrCopy = userVectorCopy.begin();
	
	
	testFunc(testNmb++, *itConstrCopySys, *itConstrCopy, "Constructor copy - value");

	itConstrCopySys =  sysVectorCopy.end();
	itConstrCopySys--;
	itConstrCopy =  userVectorCopy.end();
	itConstrCopy--;
	

	

	testFunc(testNmb++, *itConstrCopySys, *itConstrCopy, "Back value is");
	getchar();
	std::system("clear");


	
	
}

void				iterators_vector(int testNmb, int testAll)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** ITERATORS ***                          " << "\x1b[0m" << std::endl;
	
	int			begin = 0;				//  
	int			end = 0;			// 
	int			rbegin = 0;			// 
	int			rend = 0;			// 
	int			const_begin = 0;				//  
	int			const_end = 0;
	int			const_rbegin = 0;			// 
	int			const_rend = 0;

	if (testAll)
	{
		begin = 1;				//  
		end = 1;			// 
		rbegin = 1;			// 
		rend = 1;			//
		const_begin = 1;				//  
		const_end = 1;
		const_rbegin = 1;			// 
		const_rend = 1;
	}
	
	//***************************CONST BEGIN AND CONST END************************//
	if(const_begin && const_end)
	{
		std::cout << std::endl << "\x1b[33m" << "const begin and const end" << "\x1b[0m" << std::endl;

		const ft::vector  <int> userVectorConst(5,4);
		const std::vector <int> sysVectorConst(5,4);

		std::vector <int>::const_iterator const_s_s = sysVectorConst.begin(); 
		ft::vector <int>::const_iterator const_m_s = userVectorConst.begin();
		std::vector <int>::const_iterator const_s_f;
		const_s_f  = sysVectorConst.end();
		const_s_f--;
		ft::vector <int>::const_iterator const_m_f;
		const_m_f = userVectorConst.end();
		const_m_f--;

		testFunc(testNmb++, *const_s_s, *const_m_s, "Const test begin");
		testFunc(testNmb++, *const_s_f, *const_m_f, "Const test end");
	}
	


	//***************************CONST RBEGIN AND CONST REND************************//
	if(const_rbegin && const_rend)
	{
		const ft::vector  <int> userVectorConst(5,4);
		const std::vector <int> sysVectorConst(5,4);
		
		std::cout << std::endl << "\x1b[33m" << "const rbegin and const rend" << "\x1b[0m" << std::endl;

		std::vector <int>::const_reverse_iterator constr_s_s = sysVectorConst.rbegin(); 
		constr_s_s++;
		ft::vector <int>::const_reverse_iterator constr_m_s = userVectorConst.rbegin();
		constr_m_s++;
		std::vector <int>::const_reverse_iterator constr_s_f;
		constr_s_f  = sysVectorConst.rend();
		constr_s_f--;
		ft::vector <int>::const_reverse_iterator constr_m_f;
		constr_m_f = userVectorConst.rend();
		constr_m_f--;

		
		testFunc(testNmb++, *constr_s_s, *constr_m_s, "Const reverse test begin");
		testFunc(testNmb++, *constr_s_f, *constr_m_f, "Const reverse test end");
	}
	
	//***************************BEGIN AND END************************//

	if(begin && end)
	{
		std::cout << std::endl << "\x1b[33m" << "begin and end" << "\x1b[0m" << std::endl;

		ft::vector  <int> userVectorSimple(5,4);
		std::vector <int> sysVectorSimple(5,4);

		std::vector <int>::iterator simple_s_s = sysVectorSimple.begin(); 
		ft::vector <int>::iterator simple_m_s = userVectorSimple.begin();
		std::vector <int>::iterator simple_s_f;
		simple_s_f  = sysVectorSimple.end();
		simple_s_f--;
		ft::vector <int>::iterator simple_m_f;
		simple_m_f = userVectorSimple.end();
		simple_m_f--;
			

		testFunc(testNmb++, *simple_s_s, *simple_m_s, "test begin");
		testFunc(testNmb++, *simple_s_f, *simple_m_f, "test end");
	}



	//***************************REVERSE BEGIN AND END************************//
	if(rbegin && rend)
	{
		ft::vector  <int> userVectorSimple(5,4);
		std::vector <int> sysVectorSimple(5,4);

		std::cout << std::endl << "\x1b[33m" << "reverse begin and end" << "\x1b[0m" << std::endl;

		std::vector <int>::reverse_iterator simpler_s_s = sysVectorSimple.rbegin(); 
		simpler_s_s++;
		ft::vector <int>::reverse_iterator simpler_m_s = userVectorSimple.rbegin();
		simpler_m_s++;
		std::vector <int>::reverse_iterator simpler_s_f;
		simpler_s_f  = sysVectorSimple.rend();
		simpler_s_f--;
		ft::vector <int>::reverse_iterator simpler_m_f;
		simpler_m_f = userVectorSimple.rend();

		testFunc(testNmb++, *simpler_s_s, *simpler_m_s, "reverse test begin");
		testFunc(testNmb++, *simpler_s_f, *simpler_m_s, "reverse test end");
	}

	getchar();
	system("clear");
}

void				capacity_vector(int testNmb, int testAll)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** CAPACITY ***                          " << "\x1b[0m" << std::endl;
	
	int			size = 0;				//  
	int			max_size = 0;			// 
	int			resize = 0;			// 
	int			capacity = 0;			// 
	int			empty = 0;				//  
	int			reserve = 0;


	if (testAll)
	{
		size = 1;				//  
		max_size = 1;			// 
		resize = 1;			// 
		capacity = 1;			// 
		empty = 1;				//  
		reserve = 1;
	}
	
	
	//***************************SIZE************************//
	if(size)
	{
		std::cout << std::endl << "\x1b[33m" << "size" << "\x1b[0m" << std::endl;

		ft::vector  <int> userVectorSimple(7,4);
		std::vector <int> sysVectorSimple(7,4);

		testFunc(testNmb++, sysVectorSimple.size(), userVectorSimple.size(), "size");
	}

	//***************************MAX_SIZE************************//
	if(max_size)
	{
		ft::vector  <int> userVectorSimple(7,4);
		std::vector <int> sysVectorSimple(7,4);

		std::cout << std::endl << "\x1b[33m" << "max_size" << "\x1b[0m" << std::endl;
		testFunc(testNmb++, sysVectorSimple.max_size(), userVectorSimple.max_size(), "max_size");
	}
	
	//***************************CAPACITY************************//
	if(capacity)
	{
		ft::vector  <int> userVectorSimple(7,4);
		std::vector <int> sysVectorSimple(7,4);

		std::cout << std::endl << "\x1b[33m" << "capacity" << "\x1b[0m" << std::endl;
		testFunc(testNmb++, sysVectorSimple.capacity(), userVectorSimple.capacity(), "capacity");
	}
	
	//***************************EMPTY************************//
	if(empty)
	{
		std::cout << std::endl << "\x1b[33m" << "empty" << "\x1b[0m" << std::endl;
	
		ft::vector  <int> userVectorSimple(7,4);
		std::vector <int> sysVectorSimple(7,4);

		ft::vector  <int> userVectorSimple1;
		std::vector <int> sysVectorSimple1;
		
		testFunc(testNmb++, sysVectorSimple1.empty(), userVectorSimple1.empty(), "vector empty");
		testFunc(testNmb++, sysVectorSimple.empty(), userVectorSimple.empty(), "vector no empty");
		getchar();
		system("clear");
	}
	
	//***************************RESERVE************************// //ДЕЛАТЬ!!!!!!!!!
	if(reserve)
	{
		
	}
}

void				modifiers_vector(int testNmb, int testAll)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** MODIFIERS ***                          " << "\x1b[0m" << std::endl;
	// testNmb++;
	//***************************ASSIGN************************//

	int			assign = 0;				//  
	int			push_back = 0;			// 
	int			pop_back = 0;			// 
	int			insert = 0;				// 
	int			erase = 0;				//  
	int			swap = 0;				//
	int			clear = 0;				//


	if (testAll)
	{
		assign = 1;				//  
		push_back = 1;			// 
		pop_back = 1;			// 
		insert = 1;				// 
		erase = 1;				//  
		swap = 1;				//
		clear = 1;				//
	}
	//***************************ASSIGN************************//
	if(assign)
	{
		std::cout << std::endl << "\x1b[33m" << "assign" << "\x1b[0m" << std::endl;
		ft::vector  <int> userVectorAssign;
		std::vector <int> sysVectorAssign;

		for(int i = 0; i < 10; i++)
		{
			sysVectorAssign.push_back(i);
			userVectorAssign.push_back(i);
		}
		// std::cout << "*** BEFORE ***" << std::endl;
		// std::cout << "userVectorAssign size: "<< userVectorAssign.size()<< std::endl;
		// std::cout << "sysVectorAssign size: "<< sysVectorAssign.size()<< std::endl;
		// std::cout<< std::endl;
		// std::cout<< std::endl;
		// std::cout << "User array: ";
		// for(size_t i = 0; i < userVectorAssign.size(); i++)
		// {
		// 	std::cout << userVectorAssign[i];
		// }
		// std::cout<< std::endl;
		// std::cout << "System array: ";
		// for(size_t i = 0; i < sysVectorAssign.size(); i++)
		// {
		// 	std::cout << sysVectorAssign[i];
		// }
		// std::cout<< std::endl;
		sysVectorAssign.assign(5,42);
		userVectorAssign.assign(5,42);
		
		// std::cout << "*** AFTER ***" << std::endl;
		// std::cout << "userVectorAssign size: "<< userVectorAssign.size()<< std::endl;
		// std::cout << "sysVectorAssign size: "<< sysVectorAssign.size()<< std::endl;
		// std::cout<< std::endl;
		// std::cout<< std::endl;
		// std::cout << "User array: ";
		// for(size_t i = 0; i < userVectorAssign.size(); i++)
		// {
		// 	std::cout << userVectorAssign[i];
		// }
		// std::cout<< std::endl;
		// std::cout << "System array: ";
		// for(size_t i = 0; i < sysVectorAssign.size(); i++)
		// {
		// 	std::cout << sysVectorAssign[i];
		// }
		// std::cout<< std::endl;
		std::vector <int>::iterator Assign_s_v = sysVectorAssign.begin(); 
		ft::vector <int>::iterator Assign_m_v = userVectorAssign.begin();

		testFunc(testNmb++, *Assign_s_v, *Assign_m_v, "begin");
		Assign_s_v = sysVectorAssign.end();
		Assign_s_v--;
		Assign_m_v = userVectorAssign.end();
		Assign_m_v--;
		
		testFunc(testNmb++, *Assign_s_v, *Assign_m_v, "end");

		getchar();


		std::cout << std::endl << "\x1b[33m" << "assign2" << "\x1b[0m" << std::endl;
		userVectorAssign.clear();
		sysVectorAssign.clear();

		// std::cout << "*** BEFORE ***" << std::endl;
		// std::cout << "userVectorAssign size: "<< userVectorAssign.size()<< std::endl;
		// std::cout << "sysVectorAssign size: "<< sysVectorAssign.size()<< std::endl;
		// std::cout<< std::endl;
		// std::cout<< std::endl;
		// std::cout << "User array: ";
		// for(size_t i = 0; i < userVectorAssign.size(); i++)
		// {
		// 	std::cout << userVectorAssign[i];
		// }
		// std::cout<< std::endl;
		// std::cout << "System array: ";
		// for(size_t i = 0; i < sysVectorAssign.size(); i++)
		// {
		// 	std::cout << sysVectorAssign[i];
		// }
		// std::cout<< std::endl;

		sysVectorAssign.assign(5,42);
		userVectorAssign.assign(5,42);
		

		// std::cout << "*** AFTER ***" << std::endl;
		// std::cout << "userVectorAssign size: "<< userVectorAssign.size()<< std::endl;
		// std::cout << "sysVectorAssign size: "<< sysVectorAssign.size()<< std::endl;
		// std::cout<< std::endl;
		// std::cout<< std::endl;
		// std::cout << "User array: ";
		// for(size_t i = 0; i < userVectorAssign.size(); i++)
		// {
		// 	std::cout << userVectorAssign[i];
		// }
		// std::cout<< std::endl;
		// std::cout << "System array: ";
		// for(size_t i = 0; i < sysVectorAssign.size(); i++)
		// {
		// 	std::cout << sysVectorAssign[i];
		// }
		// std::cout<< std::endl;
		Assign_s_v = sysVectorAssign.begin(); 
		Assign_m_v = userVectorAssign.begin();

		testFunc(testNmb++, *Assign_s_v, *Assign_m_v, "begin");
		Assign_s_v = sysVectorAssign.end();
		Assign_s_v--;
		Assign_m_v = userVectorAssign.end();
		Assign_m_v--;
		
		testFunc(testNmb++, *Assign_s_v, *Assign_m_v, "end");

		getchar();
		system("clear");
	}

	//***************************PUSH_BACK************************//
	if(push_back)
	{
		std::cout << std::endl << "\x1b[33m" << "push_back" << "\x1b[0m" << std::endl;
		ft::vector  <int> userVectorPush;
		std::vector <int> sysVectorPush;

		//  std::cout << "*** BEFORE ***" << std::endl;
		// std::cout << "userVectorPush size: "<< userVectorPush.size()<< std::endl;
		// std::cout << "sysVectorPush size: "<< sysVectorPush.size()<< std::endl;
		// std::cout<< std::endl;
		// std::cout<< std::endl;
		// std::cout << "User array: ";
		// for(size_t i = 0; i < userVectorPush.size(); i++)
		// {
		// 	std::cout << userVectorPush[i];
		// }
		// std::cout<< std::endl;
		// std::cout << "System array: ";
		// for(size_t i = 0; i < sysVectorPush.size(); i++)
		// {
		// 	std::cout << sysVectorPush[i];
		// }
		// std::cout<< std::endl;
		for(int i = 0; i < 10; i++)
		{
			sysVectorPush.push_back(i);
			userVectorPush.push_back(i);
		}
		// std::cout << "*** AFTER ***" << std::endl;
		// std::cout << "userVectorPush size: "<< userVectorPush.size()<< std::endl;
		// std::cout << "sysVectorPush size: "<< sysVectorPush.size()<< std::endl;
		testFunc(testNmb++, sysVectorPush.size(), userVectorPush.size(), "size");
		std::vector <int>::iterator push_s_v = sysVectorPush.begin(); 
		ft::vector <int>::iterator push_m_v = userVectorPush.begin();

		testFunc(testNmb++, *push_s_v, *push_m_v, "begin");
		push_s_v = sysVectorPush.end();
		push_s_v--;
		push_m_v = userVectorPush.end();
		push_m_v--;
		
		testFunc(testNmb++, *push_s_v, *push_m_v, "end");
		
		sysVectorPush.push_back(20);
		userVectorPush.push_back(20);
		push_s_v = sysVectorPush.end();
		push_s_v--;
		push_m_v = userVectorPush.end();
		push_m_v--;

		// std::cout << "*** AFTER ***" << std::endl;
		// std::cout << "userVectorPush size: "<< userVectorPush.size()<< std::endl;
		// std::cout << "sysVectorPush size: "<< sysVectorPush.size()<< std::endl;
		// std::cout<< std::endl;
		// std::cout<< std::endl;
		// std::cout << "User array: ";
		// for(size_t i = 0; i < userVectorPush.size(); i++)
		// {
		// 	std::cout << userVectorPush[i];
		// }
		// std::cout<< std::endl;
		// std::cout << "System array: ";
		// for(size_t i = 0; i < sysVectorPush.size(); i++)
		// {
		// 	std::cout << sysVectorPush[i];
		// }
		// std::cout<< std::endl;
		testFunc(testNmb++, sysVectorPush.size(), userVectorPush.size(), "new size");
		
		testFunc(testNmb++, *push_s_v, *push_m_v, "new end");

		getchar();
		system("clear");
	}

	//***************************POP_BACK************************//
	if(pop_back)
	{
		std::cout << std::endl << "\x1b[33m" << "pop_back" << "\x1b[0m" << std::endl;
		ft::vector  <int> userVectorPop;
		std::vector <int> sysVectorPop;

		for(int i = 0; i < 10; i++)
		{
			sysVectorPop.push_back(i);
			userVectorPop.push_back(i);
		}
		//  std::cout << "*** BEFORE ***" << std::endl;
		// std::cout << "userVectorPop size: "<< userVectorPop.size()<< std::endl;
		// std::cout << "sysVectorPop size: "<< sysVectorPop.size()<< std::endl;
		// std::cout<< std::endl;
		// std::cout<< std::endl;
		// std::cout << "User array: ";
		// for(size_t i = 0; i < userVectorPop.size(); i++)
		// {
		// 	std::cout << userVectorPop[i];
		// }
		// std::cout<< std::endl;
		// std::cout << "System array: ";
		// for(size_t i = 0; i < sysVectorPop.size(); i++)
		// {
		// 	std::cout << sysVectorPop[i];
		// }
		// std::cout<< std::endl;
		std::vector <int>::iterator pop_s_v = sysVectorPop.begin(); 
		ft::vector <int>::iterator pop_m_v = userVectorPop.begin();
		testFunc(testNmb++, *pop_s_v, *pop_m_v, "begin");
		sysVectorPop.pop_back();
		userVectorPop.pop_back();
		// std::cout << "*** AFTER ***" << std::endl;
		// std::cout << "userVectorPop size: "<< userVectorPop.size()<< std::endl;
		// std::cout << "sysVectorPop size: "<< sysVectorPop.size()<< std::endl;
		// std::cout<< std::endl;
		// std::cout<< std::endl;
		// std::cout << "User array: ";
		// for(size_t i = 0; i < userVectorPop.size(); i++)
		// {
		// 	std::cout << userVectorPop[i];
		// }
		// std::cout<< std::endl;
		// std::cout << "System array: ";
		// for(size_t i = 0; i < sysVectorPop.size(); i++)
		// {
		// 	std::cout << sysVectorPop[i];
		// }
		// std::cout<< std::endl;
		testFunc(testNmb++, sysVectorPop.size(), userVectorPop.size(), "size");

		pop_s_v = sysVectorPop.begin();
		pop_m_v = userVectorPop.begin();
		testFunc(testNmb++, *pop_s_v, *pop_m_v, "begin");
		pop_s_v = sysVectorPop.end();
		pop_s_v--;
		pop_m_v = userVectorPop.end();
		pop_m_v--;
		
		testFunc(testNmb++, *pop_s_v, *pop_m_v, "end");

		getchar();
		system("clear");
	}

	//***************************INSERT************************//
	if(insert)
	{
		std::cout << std::endl << "\x1b[33m" << "insert" << "\x1b[0m" << std::endl;
		ft::vector  <int> userVectorInsert;
		std::vector <int> sysVectorInsert;

		for(int i = 0; i < 10; i++)
		{
			sysVectorInsert.push_back(i);
			userVectorInsert.push_back(i);
		}
	
		// std::cout << "*** BEFORE ***" << std::endl;
		// std::cout << "userVectorInsert size: "<< userVectorInsert.size()<< std::endl;
		// std::cout << "sysVectorPop size: "<< sysVectorInsert.size()<< std::endl;
		// std::cout<< std::endl;
		// std::cout<< std::endl;
		// std::cout << "User array: ";
		// for(size_t i = 0; i < userVectorInsert.size(); i++)
		// {
		// 	std::cout << userVectorInsert[i];
		// }
		// std::cout<< std::endl;
		// std::cout << "System array: ";
		// for(size_t i = 0; i < sysVectorInsert.size(); i++)
		// {
		// 	std::cout << sysVectorInsert[i];
		// }
		// std::cout<< std::endl;

		
		std::vector <int>::iterator Insert_s_v = sysVectorInsert.begin(); 
		ft::vector <int>::iterator Insert_m_v = userVectorInsert.begin();
		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "begin");
		sysVectorInsert.insert(Insert_s_v, 12);
		// userVectorInsert.insert(Insert_m_v,12);

		
		// std::cout << "*** AFTER ***" << std::endl;
		// std::cout << "userVectorInsert size: "<< userVectorInsert.size()<< std::endl;
		// std::cout << "sysVectorInsert size: "<< sysVectorInsert.size()<< std::endl;
		// std::cout<< std::endl;
		// std::cout<< std::endl;
		// std::cout << "User array: ";
		// for(size_t i = 0; i < userVectorInsert.size(); i++)
		// {
		// 	std::cout << userVectorInsert[i];
		// }
		// std::cout<< std::endl;
		// std::cout << "System array: ";
		// for(size_t i = 0; i < sysVectorInsert.size(); i++)
		// {
		// 	std::cout << sysVectorInsert[i];
		// }
		// std::cout<< std::endl;

		
		testFunc(testNmb++, sysVectorInsert.size(), userVectorInsert.size(), "size");

		Insert_s_v = sysVectorInsert.begin();
		Insert_m_v = userVectorInsert.begin();
		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "begin");
		Insert_s_v = sysVectorInsert.end();
		Insert_s_v--;
		Insert_m_v = userVectorInsert.end();
		Insert_m_v--;
		
		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "end");

		getchar();
		system("clear");
	}

	//***************************ERASE************************//
	if(erase)
	{
		
	}
	
	//***************************SWAP************************//
	if(swap)
	{
		
	}
	
	//***************************CLEAR************************//
	if(clear)
	{
		std::cout << std::endl << "\x1b[33m" << "clear" << "\x1b[0m" << std::endl;
		ft::vector  <int> userVectorClear(7,4);
		std::vector <int> sysVectorClear(7,4);
		// std::vector <int>::iterator clear_s = userVectorClear.begin(); 
		// ft::vector <int>::iterator clear_m = userVectorClear.begin();
		// std::cout << "*** BEFORE ***" << std::endl;
		// std::cout << "userVectorClear size: "<< userVectorClear.size()<< std::endl;
		// std::cout << "sysVectorClear size: "<< sysVectorClear.size()<< std::endl;

		userVectorClear.clear();
		sysVectorClear.clear();

		// std::cout << "*** AFTER ***" << std::endl;
		// std::cout << "userVectorClear size: "<< userVectorClear.size()<< std::endl;
		// std::cout << "sysVectorClear size: "<< sysVectorClear.size()<< std::endl;

		
		testFunc(testNmb++, sysVectorClear.size(), userVectorClear.size(), "vector clear");
	}

}
	

void				vector_test()
{
	int testNmb = 0;
	int testAll = 1;
	
	std::cout << "\x1b[33m" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "|         VECTOR TESTING         |" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl << std::endl;
	std::cout << "\x1b[0m";

	/*			Member functions			*/
	
	/* extra */
	// operators(testNmb);

	constructor_vector(testNmb);
	// destructor(testNmb);			// need tests
	// operatorEquality(testNmb);			// need tests
	
	iterators_vector(testNmb, testAll);
	capacity_vector(testNmb, testAll);
	// elementAccess(testNmb);
	modifiers_vector(testNmb, testAll);
	// operations(testNmb);
	// // observers(testNmb);			// need tests
	// overloads(testNmb);			// need tests

}

