/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:04:46 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/24 19:48:38 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../containers/vector/vector.hpp"
#include "containers_test.hpp"

#include <string>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

void				constructor_vector(int testNmb)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** CONSTRUCTOR ***                          " << "\x1b[0m" << std::endl;

	/* default constructor */
	std::cout << std::endl << "\x1b[33m" << "default constructor" << "\x1b[0m" << std::endl;	
	ft::vector <int> vectorConstrUserFree;
	std::vector <int> vectorConstrSysFree;

	testFunc(testNmb++, vectorConstrSysFree.size(), vectorConstrUserFree.size(),  "vector size()");


	/* simple constructor */
	std::cout << std::endl << "\x1b[33m" << "simple constructor" << "\x1b[0m" << std::endl;	
	ft::vector<int> vUser(4, 100);
	std::vector <int> vSys(4,100);

	std::cout << "*** PRINT VECTOR ***" << std::endl;
	print_std_vector(" Sys Erase:", vSys);
	print_ft_vector("User Erase:", vUser);
	std::cout << std::endl;

	ft::vector<int>::iterator itUser = vUser.begin();
	std::vector<int>::iterator itSys = vSys.begin();

	ft::vector<int>::iterator itUser2 = vUser.end();
	std::vector<int>::iterator itSys2 = vSys.end();

	testFunc(testNmb++, *itSys, *itUser, "vector begin()");
	testFunc(testNmb++, *itSys2, *itUser2, "vector end()"); // trash
	itUser2--;
	itSys2--;
	testFunc(testNmb++, *itSys2, *itUser2, "vector end()");
	testFunc(testNmb++, vUser.size(), vSys.size(),  "vector size()");
	getchar();


	/* copy constructor */
	std::cout << std::endl << "\x1b[33m" << "copy constructor" << "\x1b[0m" << std::endl;
	ft::vector  <int> vUserCopy(vUser);
	std::vector <int> vSysCopy(vSys);

	std::cout << "*** PRINT COPY CONSTRUCTOR ***" << std::endl;
	print_std_vector(" Sys Erase:", vSysCopy);
	print_ft_vector("User Erase:", vUserCopy);
	std::cout << std::endl;
	
	testFunc(testNmb++, vSysCopy.size(), vUserCopy.size(), "Constructor copy");
	
	// std::vector<int>::iterator itConstrCopySys = sysVectorCopy.begin();
	// ft::vector<int>::iterator itConstrCopy = userVectorCopy.begin();
	
	
	// testFunc(testNmb++, *itConstrCopySys, *itConstrCopy, "Constructor copy - value");

	// itConstrCopySys =  sysVectorCopy.end();
	// itConstrCopySys--;
	// itConstrCopy =  userVectorCopy.end();
	// itConstrCopy--;

	// std::cout << std::endl << "\x1b[33m" << "constructor InputIterator" << "\x1b[0m" << std::endl;

	
	// itConstrCopySys = sysVectorCopy.begin();
	// itConstrCopy = userVectorCopy.begin();

	// std::vector  <int>::iterator itConstrCopySys2 = sysVectorCopy.end();
	// ft::vector  <int>::iterator itConstrCopy2 = userVectorCopy.end();

	// ft::vector  <int> userVectorInputIt(itConstrCopy,itConstrCopy2);
	// std::vector <int> sysVectorInpuIt(itConstrCopySys, itConstrCopySys2);
	
	// testFunc(testNmb++, sysVectorCopy.size(), userVectorCopy.size(), "Constructor InputIterator");
	// testFunc(testNmb++, *itConstrCopySys, *itConstrCopy, "Constructor InputIterator - value");

	// itConstrCopySys =  sysVectorCopy.end();
	// itConstrCopySys--;
	// itConstrCopy =  userVectorCopy.end();
	// itConstrCopy--;
	
	// testFunc(testNmb++, *itConstrCopySys, *itConstrCopy, "Back value is");
	// getchar();
	// std::system("clear");

}

// void				iterators_vector(int testNmb, int testAll)
// {
// 	std::cout << std::endl << "\x1b[33m" << "                              *** ITERATORS ***                          " << "\x1b[0m" << std::endl;
	
// 	int			begin = 0;				//  
// 	int			end = 0;			// 
// 	int			rbegin = 0;			// 
// 	int			rend = 0;			// 
// 	int			const_begin = 0;				//  
// 	int			const_end = 0;
// 	int			const_rbegin = 0;			// 
// 	int			const_rend = 0;

// 	if (testAll)
// 	{
// 		begin = 1;				//  
// 		end = 1;			// 
// 		rbegin = 1;			// 
// 		rend = 1;			//
// 		const_begin = 1;				//  
// 		const_end = 1;
// 		const_rbegin = 1;			// 
// 		const_rend = 1;
// 	}
	
// 	//***************************CONST BEGIN AND CONST END************************//
// 	if(const_begin && const_end)
// 	{
// 		std::cout << std::endl << "\x1b[33m" << "const begin and const end" << "\x1b[0m" << std::endl;

// 		const ft::vector  <int> userVectorConst(5,4);
// 		const std::vector <int> sysVectorConst(5,4);

// 		std::vector <int>::const_iterator const_s_s = sysVectorConst.begin(); 
// 		ft::vector <int>::const_iterator const_m_s = userVectorConst.begin();
// 		std::vector <int>::const_iterator const_s_f;
// 		const_s_f  = sysVectorConst.end();
// 		const_s_f--;
// 		ft::vector <int>::const_iterator const_m_f;
// 		const_m_f = userVectorConst.end();
// 		const_m_f--;

// 		testFunc(testNmb++, *const_s_s, *const_m_s, "Const test begin");
// 		testFunc(testNmb++, *const_s_f, *const_m_f, "Const test end");
// 	}
	


// 	//***************************CONST RBEGIN AND CONST REND************************//
// 	if(const_rbegin && const_rend)
// 	{
// 		const ft::vector  <int> userVectorConst(5,4);
// 		const std::vector <int> sysVectorConst(5,4);
		
// 		std::cout << std::endl << "\x1b[33m" << "const rbegin and const rend" << "\x1b[0m" << std::endl;

// 		std::vector <int>::const_reverse_iterator constr_s_s = sysVectorConst.rbegin(); 
// 		constr_s_s++;
// 		ft::vector <int>::const_reverse_iterator constr_m_s = userVectorConst.rbegin();
// 		constr_m_s++;
// 		std::vector <int>::const_reverse_iterator constr_s_f;
// 		constr_s_f  = sysVectorConst.rend();
// 		constr_s_f--;
// 		ft::vector <int>::const_reverse_iterator constr_m_f;
// 		constr_m_f = userVectorConst.rend();
// 		constr_m_f--;

		
// 		testFunc(testNmb++, *constr_s_s, *constr_m_s, "Const reverse test begin");
// 		testFunc(testNmb++, *constr_s_f, *constr_m_f, "Const reverse test end");
// 	}
	
// 	//***************************BEGIN AND END************************//

// 	if(begin && end)
// 	{
// 		std::cout << std::endl << "\x1b[33m" << "begin and end" << "\x1b[0m" << std::endl;

// 		ft::vector  <int> userVectorSimple(5,4);
// 		std::vector <int> sysVectorSimple(5,4);

// 		std::vector <int>::iterator simple_s_s = sysVectorSimple.begin(); 
// 		ft::vector <int>::iterator simple_m_s = userVectorSimple.begin();
// 		std::vector <int>::iterator simple_s_f;
// 		simple_s_f  = sysVectorSimple.end();
// 		simple_s_f--;
// 		ft::vector <int>::iterator simple_m_f;
// 		simple_m_f = userVectorSimple.end();
// 		simple_m_f--;
			

// 		testFunc(testNmb++, *simple_s_s, *simple_m_s, "test begin");
// 		testFunc(testNmb++, *simple_s_f, *simple_m_f, "test end");
// 	}



// 	//***************************REVERSE BEGIN AND END************************//
// 	if(rbegin && rend)
// 	{
// 		ft::vector  <int> userVectorSimple(5,4);
// 		std::vector <int> sysVectorSimple(5,4);

// 		std::cout << std::endl << "\x1b[33m" << "reverse begin and end" << "\x1b[0m" << std::endl;

// 		std::vector <int>::reverse_iterator simpler_s_s = sysVectorSimple.rbegin(); 
// 		simpler_s_s++;
// 		ft::vector <int>::reverse_iterator simpler_m_s = userVectorSimple.rbegin();
// 		simpler_m_s++;
// 		std::vector <int>::reverse_iterator simpler_s_f;
// 		simpler_s_f  = sysVectorSimple.rend();
// 		simpler_s_f--;
// 		ft::vector <int>::reverse_iterator simpler_m_f;
// 		simpler_m_f = userVectorSimple.rend();

// 		testFunc(testNmb++, *simpler_s_s, *simpler_m_s, "reverse test begin");
// 		testFunc(testNmb++, *simpler_s_f, *simpler_m_s, "reverse test end");
// 	}

// 	getchar();
// 	system("clear");
// }

// void				capacity_vector(int testNmb, int testAll)
// {
// 	std::cout << std::endl << "\x1b[33m" << "                              *** CAPACITY ***                          " << "\x1b[0m" << std::endl;
	
// 	int			size = 0;				//  
// 	int			max_size = 0;			// 
// 	int			resize = 0;			// 
// 	int			capacity = 0;			// 
// 	int			empty = 0;				//  
// 	int			reserve = 0;


// 	if (testAll)
// 	{
// 		size = 1;				//  
// 		max_size = 1;			// 
// 		resize = 1;			// 
// 		capacity = 1;			// 
// 		empty = 1;				//  
// 		reserve = 1;
// 	}
	
	
// 	//***************************SIZE************************//
// 	if(size)
// 	{
// 		std::cout << std::endl << "\x1b[33m" << "size" << "\x1b[0m" << std::endl;

// 		ft::vector  <int> userVectorSimple(7,4);
// 		std::vector <int> sysVectorSimple(7,4);

// 		testFunc(testNmb++, sysVectorSimple.size(), userVectorSimple.size(), "size");
// 		getchar();
// 	}

// 	//***************************MAX_SIZE************************//
// 	if(max_size)
// 	{
// 		ft::vector  <int> userVectorSimple(7,4);
// 		std::vector <int> sysVectorSimple(7,4);

// 		std::cout << std::endl << "\x1b[33m" << "max_size" << "\x1b[0m" << std::endl;
// 		testFunc(testNmb++, sysVectorSimple.max_size(), userVectorSimple.max_size(), "max_size");
// 		getchar();
// 	}

// 	//***************************RESIZE************************//
// 	if(resize)
// 	{
// 		std::cout << std::endl << "\x1b[33m" << "resize" << "\x1b[0m" << std::endl;
// 		ft::vector  <int> userVectorResize(3,4);
// 		std::vector <int> sysVectorResize(3,4);

// 		std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "userVectorResize size: "<< userVectorResize.size()<< std::endl;
// 		std::cout << "sysVectorResize size: "<< sysVectorResize.size()<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout << "User array:   ";
// 		for(size_t i = 0; i < userVectorResize.size(); i++)
// 		{
// 			std::cout << userVectorResize[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array: ";
// 		for(size_t i = 0; i < sysVectorResize.size(); i++)
// 		{
// 			std::cout << sysVectorResize[i]<< " ";
// 		}
// 		std::cout<< std::endl;


// 		userVectorResize.resize(5,7);
// 		sysVectorResize.resize(5,7);


// 		std::cout << "*** AFTER ***" << std::endl;
// 		std::cout << "userVectorResize size: "<< userVectorResize.size()<< std::endl;
// 		std::cout << "sysVectorResize size: "<< sysVectorResize.size()<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout << "User array:   ";
// 		for(size_t i = 0; i < userVectorResize.size(); i++)
// 		{
// 			std::cout << userVectorResize[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array: ";
// 		for(size_t i = 0; i < sysVectorResize.size(); i++)
// 		{
// 			std::cout << sysVectorResize[i]<< " ";
// 		}
// 		std::cout<< std::endl;

// 		std::vector<int>::iterator itResize = sysVectorResize.end();
// 		itResize--;
// 		ft::vector<int>::iterator itResize2 = userVectorResize.end();
// 		itResize2--;

// 		testFunc(testNmb++, sysVectorResize.size(), userVectorResize.size(), "size");
// 		testFunc(testNmb++, *sysVectorResize.begin(), *userVectorResize.begin(), "begin");
// 		testFunc(testNmb++, *itResize, *itResize2, "end");
// 		getchar();
// 		system("clear");

// 		std::cout << std::endl << "\x1b[33m" << "resize 2" << "\x1b[0m" << std::endl;
// 		userVectorResize.assign(10,2);
// 		sysVectorResize.assign(10,2);

// 		std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "userVectorResize size: "<< userVectorResize.size()<< std::endl;
// 		std::cout << "sysVectorResize size: "<< sysVectorResize.size()<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout << "User array:   ";
// 		for(size_t i = 0; i < userVectorResize.size(); i++)
// 		{
// 			std::cout << userVectorResize[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array: ";
// 		for(size_t i = 0; i < sysVectorResize.size(); i++)
// 		{
// 			std::cout << sysVectorResize[i]<< " ";
// 		}
// 		std::cout<< std::endl;


// 		userVectorResize.resize(5);
// 		sysVectorResize.resize(5);


// 		std::cout << "*** AFTER ***" << std::endl;
// 		std::cout << "userVectorResize size: "<< userVectorResize.size()<< std::endl;
// 		std::cout << "sysVectorResize size: "<< sysVectorResize.size()<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout << "User array:   ";
// 		for(size_t i = 0; i < userVectorResize.size(); i++)
// 		{
// 			std::cout << userVectorResize[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array: ";
// 		for(size_t i = 0; i < sysVectorResize.size(); i++)
// 		{
// 			std::cout << sysVectorResize[i]<< " ";
// 		}
// 		std::cout<< std::endl;

// 		itResize = sysVectorResize.end();
// 		itResize--;
// 		itResize2 = userVectorResize.end();
// 		itResize2--;

// 		testFunc(testNmb++, sysVectorResize.size(), userVectorResize.size(), "size");
// 		testFunc(testNmb++, *sysVectorResize.begin(), *userVectorResize.begin(), "begin");
// 		testFunc(testNmb++, *itResize, *itResize2, "end");
// 		getchar();
// 		system("clear");
// 	}
	
// 	//***************************CAPACITY************************//
// 	if(capacity)
// 	{
// 		ft::vector  <int> userVectorSimple(7,4);
// 		std::vector <int> sysVectorSimple(7,4);

// 		std::cout << std::endl << "\x1b[33m" << "capacity" << "\x1b[0m" << std::endl;
// 		testFunc(testNmb++, sysVectorSimple.capacity(), userVectorSimple.capacity(), "capacity");
// 		getchar();
// 	}
	
// 	//***************************EMPTY************************//
// 	if(empty)
// 	{
// 		std::cout << std::endl << "\x1b[33m" << "empty" << "\x1b[0m" << std::endl;
	
// 		ft::vector  <int> userVectorSimple(7,4);
// 		std::vector <int> sysVectorSimple(7,4);

// 		ft::vector  <int> userVectorSimple1;
// 		std::vector <int> sysVectorSimple1;
		
// 		testFunc(testNmb++, sysVectorSimple1.empty(), userVectorSimple1.empty(), "vector empty");
// 		testFunc(testNmb++, sysVectorSimple.empty(), userVectorSimple.empty(), "vector no empty");
// 		getchar();
// 	}
	
// 	//***************************RESERVE************************// //ДЕЛАТЬ!!!!!!!!!
// 	if(reserve)
// 	{
// 		std::cout << std::endl << "\x1b[33m" << "reserve" << "\x1b[0m" << std::endl;
	
// 		ft::vector  <int> userVectorReserve(7,4);
// 		std::vector <int> sysVectorReserve(7,4);

// 		testFunc(testNmb++, sysVectorReserve.capacity(), userVectorReserve.capacity(), "capacity");

// 		userVectorReserve.reserve(20);
// 		sysVectorReserve.reserve(20);
// 		testFunc(testNmb++, sysVectorReserve.capacity(), userVectorReserve.capacity(), "capacity");

// 		userVectorReserve.reserve(0);
// 		sysVectorReserve.reserve(0);
// 		testFunc(testNmb++, sysVectorReserve.capacity(), userVectorReserve.capacity(), "capacity");

// 		getchar();
// 		system("clear");

		
// 	}
// }

// void				elementAccess_vector(int testNmb, int testAll)
// {
// 	std::cout << std::endl << "\x1b[33m" << "                              *** ELEMENT ACCESS ***                          " << "\x1b[0m" << std::endl;
	
// 	int			Operator = 0;				//  
// 	int			at = 0;			// 
// 	int			front = 0;			// 
// 	int			back = 0;			// 


// 	if (testAll)
// 	{
// 		Operator = 1;				//  
// 		at = 1;			// 
// 		front = 1;			// 
// 		back = 1;
// 	}
	
// 	//***************************OPERATOR []************************//
// 	if(Operator)
// 	{
// 		std::cout << std::endl << "\x1b[33m" << "operator []" << "\x1b[0m" << std::endl;

// 		ft::vector  <int> userVectorOperator(5,4);
// 		std::vector <int> sysVectorOperator(5,4);

// 		std::cout<<"user test"<<std::endl;
// 		for(size_t i = 0; i < userVectorOperator.size(); i++)
// 		{
// 			std::cout<< userVectorOperator[i]<< " ";
// 		}
// 		std::cout<<std::endl;

// 		std::cout<<"sys test"<<std::endl;
// 		for(size_t i = 0; i < sysVectorOperator.size(); i++)
// 		{
// 			std::cout<< sysVectorOperator[i]<< " ";
// 		}
// 		std::cout<<std::endl;
// 		testFunc(testNmb++, userVectorOperator[0], sysVectorOperator[0], "check arr[0]");
// 		std::cout<<std::endl;
// 		getchar();
		
// 	}

// 	//***************************AT************************//
// 	if(at)
// 	{
// 		try
// 		{
// 			std::cout << std::endl << "\x1b[33m" << "at" << "\x1b[0m" << std::endl;

// 			ft::vector  <int> userVectorAt;
// 			std::vector <int> sysVectorAt;

// 			for(size_t i = 0; i < 10; i++)
// 			{
// 				 userVectorAt.push_back(i);
// 				 sysVectorAt.push_back(i);
// 			}
			
// 			testFunc(testNmb++, userVectorAt.at(5), sysVectorAt.at(5), ".at(5)");

// 			// testFunc(testNmb++, userVectorAt.at(30), sysVectorAt.at(30), ".at(30) - wrong"); раскомментить когда надо
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cout << "EXCEPTOIN: Out of Range error:" <<std::cerr << e.what() << '\n';
// 		}
// 		getchar();
// 		try
// 		{
// 			std::cout << std::endl << "\x1b[33m" << "at const" << "\x1b[0m" << std::endl;

// 			const ft::vector  <int> userVectorAt(5, 4);
// 			const std::vector <int> sysVectorAt(5, 4);

			
// 			testFunc(testNmb++, userVectorAt.at(4), sysVectorAt.at(4), ".at(5)");

// 			// testFunc(testNmb++, userVectorAt.at(30), sysVectorAt.at(30), ".at(30) - wrong"); раскомментить когда надо
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cout << "EXCEPTOIN: Out of Range error:" <<std::cerr << e.what() << '\n';
// 		}
// 		getchar();
// 	}
	
// 	//***************************FRONT************************//
// 	if(front)
// 	{
// 		std::cout << std::endl << "\x1b[33m" << "front" << "\x1b[0m" << std::endl;

// 		ft::vector  <int> userVectorFront;
// 		std::vector <int> sysVectorFront;

// 		for(size_t i = 1; i < 10; i++)
// 		{
// 				userVectorFront.push_back(i);
// 				sysVectorFront.push_back(i);
// 		}

// 		testFunc(testNmb++, userVectorFront.front(), sysVectorFront.front(), "front");
// 		getchar();
	
// 		// std::cout << std::endl << "\x1b[33m" << "front empty" << "\x1b[0m" << std::endl;

// 		// userVectorFront.clear();
// 		// sysVectorFront.clear();

// 		// testFunc(testNmb++, userVectorFront.front(), sysVectorFront.front(), "front empty");
// 		// getchar();

// 				std::cout << std::endl << "\x1b[33m" << "front const" << "\x1b[0m" << std::endl;

// 		userVectorFront.clear();
// 		sysVectorFront.clear();

// 		for(size_t i = 1; i < 10; i++)
// 		{
// 				userVectorFront.push_back(i);
// 				sysVectorFront.push_back(i);
// 		}

// 		testFunc(testNmb++, userVectorFront.front(), sysVectorFront.front(), "front const");
// 		getchar();

// 		// 		std::cout << std::endl << "\x1b[33m" << "front const empty" << "\x1b[0m" << std::endl;

// 		// userVectorFront.clear();
// 		// sysVectorFront.clear();


// 		// testFunc(testNmb++, userVectorFront.front(), sysVectorFront.front(), "front const empty");
// 		// getchar();
// 	}
// 	//***************************BACK************************//
// 	if(back)
// 	{
// 		std::cout << std::endl << "\x1b[33m" << "back" << "\x1b[0m" << std::endl;

// 		ft::vector  <int> userVectorBack;
// 		std::vector <int> sysVectorBack;

// 		for(size_t i = 1; i < 10; i++)
// 		{
// 				userVectorBack.push_back(i);
// 				sysVectorBack.push_back(i);
// 		}

// 		testFunc(testNmb++, sysVectorBack.back() - 1,userVectorBack.back() - 1,  "back");
// 		getchar();
	
// 		// std::cout << std::endl << "\x1b[33m" << "back empty" << "\x1b[0m" << std::endl;

// 		// userVectorBack.clear();
// 		// sysVectorBack.clear();

// 		// testFunc(testNmb++, sysVectorBack.back() - 1, userVectorBack.back() - 1, "back empty");
// 		// getchar();

// 				std::cout << std::endl << "\x1b[33m" << "back const" << "\x1b[0m" << std::endl;

// 		userVectorBack.clear();
// 		sysVectorBack.clear();

// 		for(size_t i = 1; i < 10; i++)
// 		{
// 				userVectorBack.push_back(i);
// 				sysVectorBack.push_back(i);
// 		}

// 		testFunc(testNmb++, sysVectorBack.back() - 1, userVectorBack.back() - 1, "back const");
// 		getchar();

// 		// 		std::cout << std::endl << "\x1b[33m" << "back const empty" << "\x1b[0m" << std::endl;

// 		// userVectorBack.clear();
// 		// sysVectorBack.clear();


// 		// testFunc(testNmb++, sysVectorBack.back() - 1, userVectorBack.back() - 1, "back const empty");
// 		// getchar();
// 	}
// }

// void				modifiers_vector(int testNmb, int testAll)
// {
// 	std::cout << std::endl << "\x1b[33m" << "                              *** MODIFIERS ***                          " << "\x1b[0m" << std::endl;
// 	// testNmb++;
// 	//***************************ASSIGN************************//

// 	int			assign = 0;				//  
// 	int			push_back = 0;			// 
// 	int			pop_back = 0;			// 
// 	int			insert = 0;				// 
// 	int			erase = 0;				//  
// 	int			swap = 0;				//
// 	int			clear = 0;				//


// 	if (testAll)
// 	{
// 		assign = 1;				//  
// 		push_back = 1;			// 
// 		pop_back = 1;			// 
// 		insert = 1;				// 
// 		erase = 1;				//  
// 		swap = 1;				//
// 		clear = 1;				//
// 	}
// 	//***************************ASSIGN************************//
// 	if(assign)
// 	{
// 		std::cout << std::endl << "\x1b[33m" << "assign" << "\x1b[0m" << std::endl;
// 		ft::vector  <int> userVectorAssign;
// 		std::vector <int> sysVectorAssign;

// 		for(int i = 0; i < 10; i++)
// 		{
// 			sysVectorAssign.push_back(i);
// 			userVectorAssign.push_back(i);
// 		}

// 		sysVectorAssign.assign(5,42);
// 		userVectorAssign.assign(5,42);
		
// 		// std::cout << "*** AFTER ***" << std::endl;
// 		// std::cout << "userVectorAssign size: "<< userVectorAssign.size()<< std::endl;
// 		// std::cout << "sysVectorAssign size: "<< sysVectorAssign.size()<< std::endl;
// 		std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "userVectorAssign size: "<< userVectorAssign.size()<< std::endl;
// 		std::cout << "sysVectorAssign size: "<< sysVectorAssign.size()<< std::endl;
// 		print_ft_vector("userVectorAssign:", userVectorAssign);
// 		print_std_vector("sysVectorAssign:", sysVectorAssign);
// 		std::cout<< std::endl;
// 		std::vector <int>::iterator Assign_s_v = sysVectorAssign.begin(); 
// 		ft::vector <int>::iterator Assign_m_v = userVectorAssign.begin();

// 		testFunc(testNmb++, *Assign_s_v, *Assign_m_v, "begin");
// 		Assign_s_v = sysVectorAssign.end();
// 		Assign_s_v--;
// 		Assign_m_v = userVectorAssign.end();
// 		Assign_m_v--;
		
// 		testFunc(testNmb++, *Assign_s_v, *Assign_m_v, "end");

// 		getchar();


// 		std::cout << std::endl << "\x1b[33m" << "assign2" << "\x1b[0m" << std::endl;





		
// 		userVectorAssign.clear();
// 		sysVectorAssign.clear();

// 		std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "userVectorAssign size: "<< userVectorAssign.size()<< std::endl;
// 		std::cout << "sysVectorAssign size: "<< sysVectorAssign.size()<< std::endl;
// 		print_ft_vector("userVectorAssign:", userVectorAssign);
// 		print_std_vector("sysVectorAssign:", sysVectorAssign);

// 		sysVectorAssign.assign(5,42);
// 		userVectorAssign.assign(5,42);
		

// 		std::cout << "*** AFTER ***" << std::endl;
// 		std::cout << "userVectorAssign size: "<< userVectorAssign.size()<< std::endl;
// 		std::cout << "sysVectorAssign size: "<< sysVectorAssign.size()<< std::endl;
// 		print_ft_vector("userVectorAssign:", userVectorAssign);
// 		print_std_vector("sysVectorAssign:", sysVectorAssign);
// 		Assign_s_v = sysVectorAssign.begin(); 
// 		Assign_m_v = userVectorAssign.begin();

// 		testFunc(testNmb++, *Assign_s_v, *Assign_m_v, "begin");
// 		Assign_s_v = sysVectorAssign.end();
// 		Assign_s_v--;
// 		Assign_m_v = userVectorAssign.end();
// 		Assign_m_v--;
		
// 		testFunc(testNmb++, *Assign_s_v, *Assign_m_v, "end");

// 		getchar();
// 		system("clear");
	
// 		std::cout << std::endl << "\x1b[33m" << "assign InputIterator" << "\x1b[0m" << std::endl;

// 		userVectorAssign.clear();
// 		sysVectorAssign.clear();

// 		for(int i = 0; i < 10; i++)
// 		{
// 			sysVectorAssign.push_back(i);
// 			userVectorAssign.push_back(i);
// 		}

// 		ft::vector  <int> userVectorAssign2;
// 		std::vector <int> sysVectorAssign2;
		

// 		std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "userVectorAssign size: "<< userVectorAssign2.size()<< std::endl;
// 		std::cout << "sysVectorAssign size: "<< sysVectorAssign2.size()<< std::endl;
// 		print_ft_vector("userVectorAssign:", userVectorAssign2);
// 		print_std_vector("sysVectorAssign:", sysVectorAssign2);

// 		sysVectorAssign2.assign(sysVectorAssign.begin(),sysVectorAssign.end());
// 		userVectorAssign2.assign(userVectorAssign.begin(),userVectorAssign.end());
		

// 		std::cout << "*** AFTER ***" << std::endl;
// 		std::cout << "userVectorAssign size: "<< userVectorAssign2.size()<< std::endl;
// 		std::cout << "sysVectorAssign size: "<< sysVectorAssign2.size()<< std::endl;
// 		print_ft_vector("userVectorAssign:", userVectorAssign2);
// 		print_std_vector("sysVectorAssign:", sysVectorAssign2);
// 		Assign_s_v = sysVectorAssign2.begin(); 
// 		Assign_m_v = userVectorAssign2.begin();

// 		testFunc(testNmb++, *Assign_s_v, *Assign_m_v, "begin");
// 		Assign_s_v = sysVectorAssign2.end();
// 		Assign_s_v--;
// 		Assign_m_v = userVectorAssign2.end();
// 		Assign_m_v--;
		
// 		testFunc(testNmb++, *Assign_s_v, *Assign_m_v, "end");

// 		getchar();
// 		system("clear");

// 		std::cout << std::endl << "\x1b[33m" << "assign InputIterator empty" << "\x1b[0m" << std::endl;

// 		userVectorAssign.clear();
// 		sysVectorAssign.clear();

// 		userVectorAssign2.clear();
// 		sysVectorAssign2.clear();
		

// 		std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "userVectorAssign size: "<< userVectorAssign2.size()<< std::endl;
// 		std::cout << "sysVectorAssign size: "<< sysVectorAssign2.size()<< std::endl;
// 		print_ft_vector("userVectorAssign:", userVectorAssign2);
// 		print_std_vector("sysVectorAssign:", sysVectorAssign2);

// 		sysVectorAssign2.assign(sysVectorAssign.begin(),sysVectorAssign.end());
// 		userVectorAssign2.assign(userVectorAssign.begin(),userVectorAssign.end());
		

// 		std::cout << "*** AFTER ***" << std::endl;
// 		std::cout << "userVectorAssign size: "<< userVectorAssign2.size()<< std::endl;
// 		std::cout << "sysVectorAssign size: "<< sysVectorAssign2.size()<< std::endl;
// 		print_ft_vector("userVectorAssign:", userVectorAssign2);
// 		print_std_vector("sysVectorAssign:", sysVectorAssign2);

// 		getchar();
// 		system("clear");


// 	}

// 	//***************************PUSH_BACK************************//
// 	if(push_back)
// 	{
// 		std::cout << std::endl << "\x1b[33m" << "push_back" << "\x1b[0m" << std::endl;
// 		ft::vector  <int> userVectorPush;
// 		std::vector <int> sysVectorPush;

// 		 std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "userVectorPush size: "<< userVectorPush.size()<< std::endl;
// 		std::cout << "sysVectorPush size: "<< sysVectorPush.size()<< std::endl;
// 		print_ft_vector("userVectorPush:", userVectorPush);
// 		print_std_vector("sysVectorPush:", sysVectorPush);
		
// 		for(int i = 0; i < 10; i++)
// 		{
// 			sysVectorPush.push_back(i);
// 			userVectorPush.push_back(i);
// 		}
// 		std::cout << "*** AFTER ***" << std::endl;
// 		std::cout << "userVectorPush size: "<< userVectorPush.size()<< std::endl;
// 		std::cout << "sysVectorPush size: "<< sysVectorPush.size()<< std::endl;
// 		print_ft_vector("userVectorPush:", userVectorPush);
// 		print_std_vector("sysVectorPush:", sysVectorPush);
		
// 		testFunc(testNmb++, sysVectorPush.size(), userVectorPush.size(), "size");
// 		std::vector <int>::iterator push_s_v = sysVectorPush.begin(); 
// 		ft::vector <int>::iterator push_m_v = userVectorPush.begin();

// 		testFunc(testNmb++, *push_s_v, *push_m_v, "begin");
// 		push_s_v = sysVectorPush.end();
// 		push_s_v--;
// 		push_m_v = userVectorPush.end();
// 		push_m_v--;
		
// 		testFunc(testNmb++, *push_s_v, *push_m_v, "end");
		
// 		sysVectorPush.push_back(20);
// 		userVectorPush.push_back(20);
// 		push_s_v = sysVectorPush.end();
// 		push_s_v--;
// 		push_m_v = userVectorPush.end();
// 		push_m_v--;

// 		std::cout << "*** AFTER ***" << std::endl;
// 		std::cout << "userVectorPush size: "<< userVectorPush.size()<< std::endl;
// 		std::cout << "sysVectorPush size: "<< sysVectorPush.size()<< std::endl;
// 		print_ft_vector("userVectorPush:", userVectorPush);
// 		print_std_vector("sysVectorPush:", sysVectorPush);
		
// 		testFunc(testNmb++, sysVectorPush.size(), userVectorPush.size(), "new size");
		
// 		testFunc(testNmb++, *push_s_v, *push_m_v, "new end");

// 		getchar();
// 		system("clear");
// 	}

// 	//***************************POP_BACK************************//
// 	if(pop_back)
// 	{
// 		std::cout << std::endl << "\x1b[33m" << "pop_back" << "\x1b[0m" << std::endl;
// 		ft::vector  <int> userVectorPop;
// 		std::vector <int> sysVectorPop;

// 		for(int i = 0; i < 10; i++)
// 		{
// 			sysVectorPop.push_back(i);
// 			userVectorPop.push_back(i);
// 		}
// 		 std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "userVectorPop size: "<< userVectorPop.size()<< std::endl;
// 		std::cout << "sysVectorPop size: "<< sysVectorPop.size()<< std::endl;
// 		print_ft_vector("userVectorPop:", userVectorPop);
// 		print_std_vector("sysVectorPop:", sysVectorPop);
// 		std::vector <int>::iterator pop_s_v = sysVectorPop.begin(); 
// 		ft::vector <int>::iterator pop_m_v = userVectorPop.begin();
// 		testFunc(testNmb++, *pop_s_v, *pop_m_v, "begin");
// 		sysVectorPop.pop_back();
// 		userVectorPop.pop_back();
// 		std::cout << "*** AFTER ***" << std::endl;
// 		std::cout << "userVectorPop size: "<< userVectorPop.size()<< std::endl;
// 		std::cout << "sysVectorPop size: "<< sysVectorPop.size()<< std::endl;
// 		print_ft_vector("userVectorPop:", userVectorPop);
// 		print_std_vector("sysVectorPop:", sysVectorPop);
// 		testFunc(testNmb++, sysVectorPop.size(), userVectorPop.size(), "size");

// 		pop_s_v = sysVectorPop.begin();
// 		pop_m_v = userVectorPop.begin();
// 		testFunc(testNmb++, *pop_s_v, *pop_m_v, "begin");
// 		pop_s_v = sysVectorPop.end();
// 		pop_s_v--;
// 		pop_m_v = userVectorPop.end();
// 		pop_m_v--;
		
// 		testFunc(testNmb++, *pop_s_v, *pop_m_v, "end");

// 		getchar();
// 		system("clear");
// 	}

// 	//***************************INSERT************************//
// 	if(insert)
// 	{
// 		std::cout << std::endl << "\x1b[33m" << "insert" << "\x1b[0m" << std::endl;
// 		std::cout << std::endl << "iterator insert (iterator position, const value_type& val)" << std::endl;
// 		ft::vector  <int> userVectorInsert;
// 		std::vector <int> sysVectorInsert;

// 		for(int i = 0; i < 2; i++)
// 		{
// 			sysVectorInsert.push_back(i);
// 			userVectorInsert.push_back(i);
// 		}
	
// 		std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "userVectorInsert size: "<< userVectorInsert.size()<< std::endl;
// 		std::cout << "sysVectorPop size: "<< sysVectorInsert.size()<< std::endl;
// 		print_ft_vector("userVectorInsert:", userVectorInsert);
// 		print_std_vector("sysVectorInsert:", sysVectorInsert);
// 		std::cout<< std::endl;

		
// 		std::vector <int>::iterator Insert_s_v = sysVectorInsert.begin(); 
// 		ft::vector <int>::iterator Insert_m_v =userVectorInsert.begin();
// 		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "begin");
// 		testFunc(testNmb++, *sysVectorInsert.insert(Insert_s_v, 12), *userVectorInsert.insert(Insert_m_v,12), "position iterators");

		
// 		std::cout << "*** AFTER ***" << std::endl;
// 		std::cout << "userVectorInsert size: "<< userVectorInsert.size()<< std::endl;
// 		std::cout << "sysVectorInsert size: "<< sysVectorInsert.size()<< std::endl;
// 		print_ft_vector("userVectorInsert:", userVectorInsert);
// 		print_std_vector("sysVectorInsert:", sysVectorInsert);
// 		std::cout<< std::endl;

		
// 		testFunc(testNmb++, sysVectorInsert.size(), userVectorInsert.size(), "size");
		

// 		Insert_s_v = sysVectorInsert.begin();
// 		Insert_m_v = userVectorInsert.begin();
// 		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "begin");
// 		Insert_s_v = sysVectorInsert.end();
// 		Insert_s_v--;
// 		Insert_m_v = userVectorInsert.end();
// 		Insert_m_v--;
		
// 		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "end");

// 		getchar();
// 		system("clear");

// 				std::cout << std::endl << "\x1b[33m" << "insert 2" << "\x1b[0m" << std::endl;
	
// 		std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "userVectorInsert size: "<< userVectorInsert.size()<< std::endl;
// 		std::cout << "sysVectorPop size: "<< sysVectorInsert.size()<< std::endl;
// 		print_ft_vector("userVectorInsert:", userVectorInsert);
// 		print_std_vector("sysVectorInsert:", sysVectorInsert);
// 		std::cout<< std::endl;

		
// 		Insert_s_v = sysVectorInsert.begin(); 
// 		Insert_m_v = userVectorInsert.begin();
// 		for(int i = 0; i < 1; i++)
// 		{
// 			Insert_s_v++;
// 			Insert_m_v++;
// 		}
// 		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "begin");
// 		testFunc(testNmb++, *sysVectorInsert.insert(Insert_s_v, 9), *userVectorInsert.insert(Insert_m_v,9), "position iterators");
		
// 		std::cout << "*** AFTER ***" << std::endl;
// 		std::cout << "userVectorInsert size: "<< userVectorInsert.size()<< std::endl;
// 		std::cout << "sysVectorInsert size: "<< sysVectorInsert.size()<< std::endl;
// 		print_ft_vector("userVectorInsert:", userVectorInsert);
// 		print_std_vector("sysVectorInsert:", sysVectorInsert);
// 		std::cout<< std::endl;

		
// 		testFunc(testNmb++, sysVectorInsert.size(), userVectorInsert.size(), "size");

// 		Insert_s_v = sysVectorInsert.begin();
// 		Insert_m_v = userVectorInsert.begin();
// 		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "begin");
// 		Insert_s_v = sysVectorInsert.end();
// 		Insert_s_v--;
// 		Insert_m_v = userVectorInsert.end();
// 		Insert_m_v--;
		
// 		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "end");

// 		getchar();
// 		system("clear");

// 				std::cout << std::endl << "\x1b[33m" << "insert 3" << "\x1b[0m" << std::endl;
	
// 		std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "userVectorInsert size: "<< userVectorInsert.size()<< std::endl;
// 		std::cout << "sysVectorPop size: "<< sysVectorInsert.size()<< std::endl;
// 		print_ft_vector("userVectorInsert:", userVectorInsert);
// 		print_std_vector("sysVectorInsert:", sysVectorInsert);
// 		std::cout<< std::endl;

		
// 		Insert_s_v = sysVectorInsert.begin(); 
// 		Insert_m_v = userVectorInsert.begin();
// 		for(int i = 0; i < 2; i++)
// 		{
// 			Insert_s_v++;
// 			Insert_m_v++;
// 		}
// 		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "begin");
		
		
// 		testFunc(testNmb++, *sysVectorInsert.insert(Insert_s_v, 0), *userVectorInsert.insert(Insert_m_v,0), "position iterators");
		
// 		std::cout << "*** AFTER ***" << std::endl;
// 		std::cout << "userVectorInsert size: "<< userVectorInsert.size()<< std::endl;
// 		std::cout << "sysVectorInsert size: "<< sysVectorInsert.size()<< std::endl;
// 		print_ft_vector("userVectorInsert:", userVectorInsert);
// 		print_std_vector("sysVectorInsert:", sysVectorInsert);
// 		std::cout<< std::endl;


// 		testFunc(testNmb++, sysVectorInsert.size(), userVectorInsert.size(), "size");

// 		Insert_s_v = sysVectorInsert.begin();
// 		Insert_m_v = userVectorInsert.begin();
// 		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "begin");
// 		Insert_s_v = sysVectorInsert.end();
// 		Insert_s_v--;
// 		Insert_m_v = userVectorInsert.end();
// 		Insert_m_v--;
		
// 		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "end");

// 		getchar();
// 		system("clear");

// 		std::cout << std::endl << "\x1b[33m" << "insert 4" << "\x1b[0m" << std::endl;
				
// 		userVectorInsert.clear();
// 		sysVectorInsert.clear();


// 		std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "userVectorInsert size: "<< userVectorInsert.size()<< std::endl;
// 		std::cout << "sysVectorPop size: "<< sysVectorInsert.size()<< std::endl;
// 		print_ft_vector("userVectorInsert:", userVectorInsert);
// 		print_std_vector("sysVectorInsert:", sysVectorInsert);
// 		std::cout<< std::endl;

		
// 		Insert_s_v = sysVectorInsert.begin(); 
// 		Insert_m_v = userVectorInsert.begin();
		
		
// 		testFunc(testNmb++, *userVectorInsert.insert(Insert_m_v,16), *sysVectorInsert.insert(Insert_s_v, 16), "position iterators");
		
// 		std::cout << "*** AFTER ***" << std::endl;
// 		std::cout << "userVectorInsert size: "<< userVectorInsert.size()<< std::endl;
// 		std::cout << "sysVectorInsert size: "<< sysVectorInsert.size()<< std::endl;
// 		print_ft_vector("userVectorInsert:", userVectorInsert);
// 		print_std_vector("sysVectorInsert:", sysVectorInsert);
// 		std::cout<< std::endl;

		
// 		testFunc(testNmb++, sysVectorInsert.size(), userVectorInsert.size(), "size");


// 		Insert_s_v = sysVectorInsert.begin();
// 		Insert_m_v = userVectorInsert.begin();
// 		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "begin");
// 		Insert_s_v = sysVectorInsert.end();
// 		Insert_s_v--;
// 		Insert_m_v = userVectorInsert.end();
// 		Insert_m_v--;
		
// 		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "end");

// 		getchar();
// 		system("clear");

// 		std::cout << std::endl << "\x1b[33m" << "insert 5" << "\x1b[0m" << std::endl;
// 		std::cout << std::endl << "void insert (iterator position, size_type n, const value_type& val)" << std::endl;
				
// 		userVectorInsert.clear();
// 		sysVectorInsert.clear();
	
// 		std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "userVectorInsert size: "<< userVectorInsert.size()<< std::endl;
// 		std::cout << "sysVectorPop size: "<< sysVectorInsert.size()<< std::endl;
// 		print_ft_vector("userVectorInsert:", userVectorInsert);
// 		print_std_vector("sysVectorInsert:", sysVectorInsert);
// 		std::cout<< std::endl;

		
// 		Insert_s_v = sysVectorInsert.begin(); 
// 		Insert_m_v = userVectorInsert.begin();
// 		userVectorInsert.insert(Insert_m_v,2, 42);
// 		sysVectorInsert.insert(Insert_s_v,2, 42);
		
// 		std::cout << "*** AFTER ***" << std::endl;
// 		std::cout << "userVectorInsert size: "<< userVectorInsert.size()<< std::endl;
// 		std::cout << "sysVectorInsert size: "<< sysVectorInsert.size()<< std::endl;
// 		print_ft_vector("userVectorInsert:", userVectorInsert);
// 		print_std_vector("sysVectorInsert:", sysVectorInsert);
// 		std::cout<< std::endl;

		
// 		testFunc(testNmb++, sysVectorInsert.size(), userVectorInsert.size(), "size");


// 		Insert_s_v = sysVectorInsert.begin();
// 		Insert_m_v = userVectorInsert.begin();
// 		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "begin");
// 		Insert_s_v = sysVectorInsert.end();
// 		Insert_s_v--;
// 		Insert_m_v = userVectorInsert.end();
// 		Insert_m_v--;
		
// 		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "end");

// 		getchar();
// 		system("clear");

// 		std::cout << std::endl << "\x1b[33m" << "insert 6" << "\x1b[0m" << std::endl;
				
// 		userVectorInsert.clear();
// 		sysVectorInsert.clear();

// 		for(int i = 0; i < 10; i++)
// 		{
// 			sysVectorInsert.push_back(i);
// 			userVectorInsert.push_back(i);
// 		}
	
// 		std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "userVectorInsert size: "<< userVectorInsert.size()<< std::endl;
// 		std::cout << "sysVectorPop size: "<< sysVectorInsert.size()<< std::endl;
// 		print_ft_vector("userVectorInsert:", userVectorInsert);
// 		print_std_vector("sysVectorInsert:", sysVectorInsert);
// 		std::cout<< std::endl;

		
// 		Insert_s_v = sysVectorInsert.begin(); 
// 		Insert_m_v = userVectorInsert.begin();
// 		for(int i = 0; i < 2; i++)
// 		{
// 			Insert_s_v++;
// 			Insert_m_v++;
// 		}
// 		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "begin");

// 		userVectorInsert.insert(Insert_m_v,2, 8);
// 		sysVectorInsert.insert(Insert_s_v,2, 8);
		
// 		std::cout << "*** AFTER ***" << std::endl;
// 		std::cout << "userVectorInsert size: "<< userVectorInsert.size()<< std::endl;
// 		std::cout << "sysVectorInsert size: "<< sysVectorInsert.size()<< std::endl;
// 		print_ft_vector("userVectorInsert:", userVectorInsert);
// 		print_std_vector("sysVectorInsert:", sysVectorInsert);
// 		std::cout<< std::endl;

		
// 		testFunc(testNmb++, sysVectorInsert.size(), userVectorInsert.size(), "size");


// 		Insert_s_v = sysVectorInsert.begin();
// 		Insert_m_v = userVectorInsert.begin();
// 		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "begin");
// 		Insert_s_v = sysVectorInsert.end();
// 		Insert_s_v--;
// 		Insert_m_v = userVectorInsert.end();
// 		Insert_m_v--;
		
// 		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "end");

// 		getchar();
// 		system("clear");

// 				std::cout << std::endl << "\x1b[33m" << "insert InputIterator" << "\x1b[0m" << std::endl;
			
// 		userVectorInsert.clear();
// 		sysVectorInsert.clear();

// 		for(int i = 0; i < 10; i++)
// 		{
// 			sysVectorInsert.push_back(i);
// 			userVectorInsert.push_back(i);
// 		}
// 		ft::vector  <int> userVectorInsert9(2,10);
// 		std::vector <int>sysVectorInsert9(2,10);
// 		std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "userVectorInsert size: "<< userVectorInsert9.size()<< std::endl;
// 		std::cout << "sysVectorPop size: "<< sysVectorInsert9.size()<< std::endl;
// 		print_ft_vector("userVectorInsert:", userVectorInsert9);
// 		print_std_vector("sysVectorInsert:", sysVectorInsert9);
// 		std::cout<< std::endl;

		
// 		Insert_s_v = sysVectorInsert.begin(); 
// 		Insert_m_v = userVectorInsert.begin();
// 		for(int i = 0; i < 2; i++)
// 		{
// 			Insert_s_v++;
// 			Insert_m_v++;
// 		}
// 		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "begin");

		
// 		// userVectorInsert.insert(Insert_m_v,2, 8);
// 		// sysVectorInsert.insert(Insert_s_v,2, 8);
// 		userVectorInsert9.insert(userVectorInsert9.begin(), userVectorInsert.begin(), userVectorInsert.end());
// 		sysVectorInsert9.insert(sysVectorInsert9.begin(), sysVectorInsert.begin(), sysVectorInsert.end());
		
// 		std::cout << "*** AFTER ***" << std::endl;
// 		std::cout << "userVectorInsert size: "<< userVectorInsert9.size()<< std::endl;
// 		std::cout << "sysVectorInsert size: "<< sysVectorInsert9.size()<< std::endl;
// 		print_ft_vector("userVectorInsert:", userVectorInsert9);
// 		print_std_vector("sysVectorInsert:", sysVectorInsert9);
// 		std::cout<< std::endl;

		
// 		testFunc(testNmb++, sysVectorInsert9.size(), userVectorInsert9.size(), "size");


// 		Insert_s_v = sysVectorInsert.begin();
// 		Insert_m_v = userVectorInsert.begin();
// 		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "begin");
// 		Insert_s_v = sysVectorInsert.end();
// 		Insert_s_v--;
// 		Insert_m_v = userVectorInsert.end();
// 		Insert_m_v--;
		
// 		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "end");

// 		getchar();
// 		system("clear");		

// 				std::cout << std::endl << "\x1b[33m" << "insert InputIterator 2" << "\x1b[0m" << std::endl;
				
// 		userVectorInsert.clear();
// 		sysVectorInsert.clear();

// 		for(int i = 0; i < 10; i++)
// 		{
// 			sysVectorInsert.push_back(i);
// 			userVectorInsert.push_back(i);
// 		}
// 		ft::vector  <int> userVectorInsert6;
// 		std::vector <int>sysVectorInsert6;
// 		std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "userVectorInsert size: "<< userVectorInsert6.size()<< std::endl;
// 		std::cout << "sysVectorPop size: "<< sysVectorInsert6.size()<< std::endl;
// 		print_ft_vector("userVectorInsert:", userVectorInsert6);
// 		print_std_vector("sysVectorInsert:", sysVectorInsert6);
// 		std::cout<< std::endl;

		
// 		Insert_s_v = sysVectorInsert.begin(); 
// 		Insert_m_v = userVectorInsert.begin();
// 		for(int i = 0; i < 2; i++)
// 		{
// 			Insert_s_v++;
// 			Insert_m_v++;
// 		}
// 		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "begin");

		
// 		// userVectorInsert.insert(Insert_m_v,2, 8);
// 		// sysVectorInsert.insert(Insert_s_v,2, 8);
// 		userVectorInsert6.insert(userVectorInsert6.begin(), Insert_m_v, userVectorInsert.end());
// 		sysVectorInsert6.insert(sysVectorInsert6.begin(), Insert_s_v, sysVectorInsert.end());
		
// 		std::cout << "*** AFTER ***" << std::endl;
// 		std::cout << "userVectorInsert size: "<< userVectorInsert6.size()<< std::endl;
// 		std::cout << "sysVectorInsert size: "<< sysVectorInsert6.size()<< std::endl;
// 		print_ft_vector("userVectorInsert:", userVectorInsert6);
// 		print_std_vector("sysVectorInsert:", sysVectorInsert6);
// 		std::cout<< std::endl;

		
// 		testFunc(testNmb++, sysVectorInsert6.size(), userVectorInsert6.size(), "size");


// 		Insert_s_v = sysVectorInsert.begin();
// 		Insert_m_v = userVectorInsert.begin();
// 		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "begin");
// 		Insert_s_v = sysVectorInsert.end();
// 		Insert_s_v--;
// 		Insert_m_v = userVectorInsert.end();
// 		Insert_m_v--;
		
// 		testFunc(testNmb++, *Insert_s_v, *Insert_m_v, "end");

// 		getchar();
// 		system("clear");
// 	}

// 	//***************************ERASE************************//
// 	if(erase)
// 	{
// 		std::cout << std::endl << "\x1b[33m" << "erase" << "\x1b[0m" << std::endl;
// 		ft::vector  <int> userVectorErase;
// 		std::vector <int> sysVectorErase;

// 		for(int i = 0; i < 10; i++)
// 		{
// 			sysVectorErase.push_back(i);
// 			userVectorErase.push_back(i);
// 		}

// 		std::vector <int>::iterator erase_s_v = sysVectorErase.begin(); 
// 		ft::vector <int>::iterator erase_m_v = userVectorErase.begin();

// 		testFunc(testNmb++, *erase_s_v, *erase_m_v, "begin");

// 		std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "userVectorErase size: "<< userVectorErase.size()<< std::endl;
// 		std::cout << "sysVectorErase size: "<< sysVectorErase.size()<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout << "User array:   ";
// 		for(size_t i = 0; i < userVectorErase.size(); i++)
// 		{
// 			std::cout << userVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array: ";
// 		for(size_t i = 0; i < sysVectorErase.size(); i++)
// 		{
// 			std::cout << sysVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;

// 		testFunc(testNmb++, *sysVectorErase.erase(erase_s_v), *userVectorErase.erase(erase_m_v), "position iterators");

// 		std::cout << "*** AFTER ***" << std::endl;
// 		std::cout << "userVectorErase size: "<< userVectorErase.size()<< std::endl;
// 		std::cout << "sysVectorPop size: "<< sysVectorErase.size()<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout << "User array:   ";
// 		for(size_t i = 0; i < userVectorErase.size(); i++)
// 		{
// 			std::cout << userVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array: ";
// 		for(size_t i = 0; i < sysVectorErase.size(); i++)
// 		{
// 			std::cout << sysVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;
		
// 		testFunc(testNmb++, sysVectorErase.size(), userVectorErase.size(), "size");
// 		testFunc(testNmb++, *erase_s_v, *erase_m_v, "begin");
// 		erase_s_v =  sysVectorErase.end();
// 		erase_s_v--;
// 		erase_m_v =  userVectorErase.end();
// 		erase_m_v--;
		
// 		testFunc(testNmb++, *erase_s_v, *erase_m_v, "end");

// 		getchar();
// 		system("clear");

// 		std::cout << std::endl << "\x1b[33m" << "erase 1" << "\x1b[0m" << std::endl;
		
// 		userVectorErase.clear();
// 		sysVectorErase.clear();

// 		for(int i = 0; i < 10; i++)
// 		{
// 			sysVectorErase.push_back(i);
// 			userVectorErase.push_back(i);
// 		}

// 		erase_s_v = sysVectorErase.begin(); 
// 		erase_m_v = userVectorErase.begin();

// 		for(int i = 0; i < 9; i++)
// 		{
// 			erase_s_v++;
// 			erase_m_v++;
// 		}

// 		testFunc(testNmb++, *erase_s_v, *erase_m_v, "begin");

// 		std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "userVectorErase size: "<< userVectorErase.size()<< std::endl;
// 		std::cout << "sysVectorErase size: "<< sysVectorErase.size()<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout << "User array:   ";
// 		for(size_t i = 0; i < userVectorErase.size(); i++)
// 		{
// 			std::cout << userVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array: ";
// 		for(size_t i = 0; i < sysVectorErase.size(); i++)
// 		{
// 			std::cout << sysVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;

// 		erase_s_v = sysVectorErase.erase(erase_s_v);
// 		erase_s_v--;

// 		testFunc(testNmb++, *erase_s_v, *userVectorErase.erase(erase_m_v), "position iterators");

// 		std::cout << "*** AFTER ***" << std::endl;
// 		std::cout << "userVectorErase size: "<< userVectorErase.size()<< std::endl;
// 		std::cout << "sysVectorPop size: "<< sysVectorErase.size()<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout << "User array:   ";
// 		for(size_t i = 0; i < userVectorErase.size(); i++)
// 		{
// 			std::cout << userVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array: ";
// 		for(size_t i = 0; i < sysVectorErase.size(); i++)
// 		{
// 			std::cout << sysVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;
		
// 		testFunc(testNmb++, sysVectorErase.size(), userVectorErase.size(), "size");
// 		erase_s_v = sysVectorErase.begin(); 
// 		erase_m_v = userVectorErase.begin();
// 		testFunc(testNmb++, *erase_s_v, *erase_m_v, "begin");
// 		erase_s_v =  sysVectorErase.end();
// 		erase_s_v--;
// 		erase_m_v =  userVectorErase.end();
// 		erase_m_v--;
		
// 		testFunc(testNmb++, *erase_s_v, *erase_m_v, "end");

// 		getchar();
// 		system("clear");

// 		std::cout << std::endl << "\x1b[33m" << "erase one element" << "\x1b[0m" << std::endl;
		
// 		userVectorErase.clear();
// 		sysVectorErase.clear();

// 		for(int i = 0; i < 1; i++)
// 		{
// 			sysVectorErase.push_back(i);
// 			userVectorErase.push_back(i);
// 		}

// 		erase_s_v = sysVectorErase.begin(); 
// 		erase_m_v = userVectorErase.begin();

// 		testFunc(testNmb++, *erase_s_v, *erase_m_v, "begin");

// 		std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "userVectorErase size: "<< userVectorErase.size()<< std::endl;
// 		std::cout << "sysVectorErase size: "<< sysVectorErase.size()<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout << "User array:   ";
// 		for(size_t i = 0; i < userVectorErase.size(); i++)
// 		{
// 			std::cout << userVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array: ";
// 		for(size_t i = 0; i < sysVectorErase.size(); i++)
// 		{
// 			std::cout << sysVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;

// 		erase_s_v = sysVectorErase.erase(erase_s_v);
// 		// erase_s_v--;

// 		testFunc(testNmb++, *erase_s_v, *userVectorErase.erase(erase_m_v), "position iterators");

// 		std::cout << "*** AFTER ***" << std::endl;
// 		std::cout << "userVectorErase size: "<< userVectorErase.size()<< std::endl;
// 		std::cout << "sysVectorPop size: "<< sysVectorErase.size()<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout << "User array:   ";
// 		for(size_t i = 0; i < userVectorErase.size(); i++)
// 		{
// 			std::cout << userVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array: ";
// 		for(size_t i = 0; i < sysVectorErase.size(); i++)
// 		{
// 			std::cout << sysVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;
		
// 		testFunc(testNmb++, sysVectorErase.size(), userVectorErase.size(), "size");
// 		erase_s_v = sysVectorErase.begin(); 
// 		erase_m_v = userVectorErase.begin();
// 		testFunc(testNmb++, *erase_s_v, *erase_m_v, "begin");
// 		erase_s_v =  sysVectorErase.end();
// 		// erase_s_v--;
// 		erase_m_v =  userVectorErase.end();
// 		// erase_m_v--;
		
// 		testFunc(testNmb++, *erase_s_v, *erase_m_v, "end");

// 				getchar();
// 		system("clear");


// 		std::cout << std::endl << "\x1b[33m" << "erase 4" << "\x1b[0m" << std::endl;
// 		std::cout << std::endl << "iterator erase (iterator first, iterator last)" << std::endl;
// 		userVectorErase.clear();
// 		sysVectorErase.clear();

// 		for(int i = 0; i < 10; i++)
// 		{
// 			sysVectorErase.push_back(i);
// 			userVectorErase.push_back(i);
// 		}

// 		erase_s_v = sysVectorErase.begin(); 
// 		erase_m_v = userVectorErase.begin();

// 		std::vector <int>::iterator erase_s_v2 = sysVectorErase.end(); 
// 		ft::vector <int>::iterator erase_m_v2 = userVectorErase.end();
// 		erase_s_v2--;
// 		erase_m_v2--;
		
		



// 		std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "userVectorErase size: "<< userVectorErase.size()<< std::endl;
// 		std::cout << "sysVectorErase size: "<< sysVectorErase.size()<< std::endl;
// 		std::cout << "userVectorErase begin: "<< *erase_m_v<< std::endl;
// 		std::cout << "sysVectorErase begin: "<< *erase_s_v<< std::endl;
// 		std::cout << "userVectorErase end: "<< *erase_m_v2<< std::endl;
// 		std::cout << "sysVectorErase end: "<< *erase_s_v2<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout << "User array:   ";
// 		for(size_t i = 0; i < userVectorErase.size(); i++)
// 		{
// 			std::cout << userVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array: ";
// 		for(size_t i = 0; i < sysVectorErase.size(); i++)
// 		{
// 			std::cout << sysVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;

// 		testFunc(testNmb++, *sysVectorErase.erase(erase_s_v, erase_s_v2), *userVectorErase.erase(erase_m_v, erase_m_v2), "position iterators");

// 		std::cout << "*** AFTER ***" << std::endl;
// 		std::cout << "userVectorErase size: "<< userVectorErase.size()<< std::endl;
// 		std::cout << "sysVectorPop size: "<< sysVectorErase.size()<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout << "User array:   ";
// 		for(size_t i = 0; i < userVectorErase.size(); i++)
// 		{
// 			std::cout << userVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array: ";
// 		for(size_t i = 0; i < sysVectorErase.size(); i++)
// 		{
// 			std::cout << sysVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;
		
// 		testFunc(testNmb++, sysVectorErase.size(), userVectorErase.size(), "size");
// 		testFunc(testNmb++, *erase_s_v, *erase_m_v, "begin");
// 		erase_s_v =  sysVectorErase.end();
// 		erase_s_v--;
// 		erase_m_v =  userVectorErase.end();
// 		erase_m_v--;
		
// 		testFunc(testNmb++, *erase_s_v, *erase_m_v, "end");

// 		getchar();
// 		system("clear");

// 		std::cout << std::endl << "\x1b[33m" << "erase 5" << "\x1b[0m" << std::endl;
// 		std::cout << std::endl << "iterator erase (iterator first, iterator last)" << std::endl;
// 		userVectorErase.clear();
// 		sysVectorErase.clear();

// 		for(int i = 0; i < 10; i++)
// 		{
// 			sysVectorErase.push_back(i);
// 			userVectorErase.push_back(i);
// 		}

// 		erase_s_v = sysVectorErase.begin(); 
// 		erase_m_v = userVectorErase.begin();

// 		erase_s_v2 = sysVectorErase.begin(); 
// 		erase_m_v2 = userVectorErase.begin();

// 		std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "userVectorErase size: "<< userVectorErase.size()<< std::endl;
// 		std::cout << "sysVectorErase size: "<< sysVectorErase.size()<< std::endl;
// 		std::cout << "userVectorErase begin: "<< *erase_m_v<< std::endl;
// 		std::cout << "sysVectorErase begin: "<< *erase_s_v<< std::endl;
// 		std::cout << "userVectorErase end: "<< *erase_m_v2<< std::endl;
// 		std::cout << "sysVectorErase end: "<< *erase_s_v2<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout << "User array:   ";
// 		for(size_t i = 0; i < userVectorErase.size(); i++)
// 		{
// 			std::cout << userVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array: ";
// 		for(size_t i = 0; i < sysVectorErase.size(); i++)
// 		{
// 			std::cout << sysVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;

// 		testFunc(testNmb++, *sysVectorErase.erase(erase_s_v, erase_s_v2), *userVectorErase.erase(erase_m_v, erase_m_v2), "position iterators");

// 		std::cout << "*** AFTER ***" << std::endl;
// 		std::cout << "userVectorErase size: "<< userVectorErase.size()<< std::endl;
// 		std::cout << "sysVectorPop size: "<< sysVectorErase.size()<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout << "User array:   ";
// 		for(size_t i = 0; i < userVectorErase.size(); i++)
// 		{
// 			std::cout << userVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array: ";
// 		for(size_t i = 0; i < sysVectorErase.size(); i++)
// 		{
// 			std::cout << sysVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;
		
// 		testFunc(testNmb++, sysVectorErase.size(), userVectorErase.size(), "size");
// 		testFunc(testNmb++, *erase_s_v, *erase_m_v, "begin");
// 		erase_s_v =  sysVectorErase.end();
// 		erase_s_v--;
// 		erase_m_v =  userVectorErase.end();
// 		erase_m_v--;
		
// 		testFunc(testNmb++, *erase_s_v, *erase_m_v, "end");

// 		getchar();
// 		system("clear");

// 				std::cout << std::endl << "\x1b[33m" << "erase 6" << "\x1b[0m" << std::endl;
// 		std::cout << std::endl << "iterator erase (iterator first, iterator last)" << std::endl;
// 		userVectorErase.clear();
// 		sysVectorErase.clear();

// 		for(int i = 0; i < 10; i++)
// 		{
// 			sysVectorErase.push_back(i);
// 			userVectorErase.push_back(i);
// 		}

// 		erase_s_v = sysVectorErase.begin(); 
// 		erase_m_v = userVectorErase.begin();

// 		erase_s_v2 = sysVectorErase.begin();
// 		erase_s_v2++;
// 		erase_m_v2 = userVectorErase.begin();
// 		erase_m_v2++;

// 		std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "userVectorErase size: "<< userVectorErase.size()<< std::endl;
// 		std::cout << "sysVectorErase size: "<< sysVectorErase.size()<< std::endl;
// 		std::cout << "userVectorErase begin: "<< *erase_m_v<< std::endl;
// 		std::cout << "sysVectorErase begin: "<< *erase_s_v<< std::endl;
// 		std::cout << "userVectorErase end: "<< *erase_m_v2<< std::endl;
// 		std::cout << "sysVectorErase end: "<< *erase_s_v2<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout << "User array:   ";
// 		for(size_t i = 0; i < userVectorErase.size(); i++)
// 		{
// 			std::cout << userVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array: ";
// 		for(size_t i = 0; i < sysVectorErase.size(); i++)
// 		{
// 			std::cout << sysVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;

// 		testFunc(testNmb++, *sysVectorErase.erase(erase_s_v, erase_s_v2), *userVectorErase.erase(erase_m_v, erase_m_v2), "position iterators");

// 		std::cout << "*** AFTER ***" << std::endl;
// 		std::cout << "userVectorErase size: "<< userVectorErase.size()<< std::endl;
// 		std::cout << "sysVectorPop size: "<< sysVectorErase.size()<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout << "User array:   ";
// 		for(size_t i = 0; i < userVectorErase.size(); i++)
// 		{
// 			std::cout << userVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array: ";
// 		for(size_t i = 0; i < sysVectorErase.size(); i++)
// 		{
// 			std::cout << sysVectorErase[i]<< " ";
// 		}
// 		std::cout<< std::endl;
		
// 		testFunc(testNmb++, sysVectorErase.size(), userVectorErase.size(), "size");
// 		testFunc(testNmb++, *erase_s_v, *erase_m_v, "begin");
// 		erase_s_v =  sysVectorErase.end();
// 		erase_s_v--;
// 		erase_m_v =  userVectorErase.end();
// 		erase_m_v--;
		
// 		testFunc(testNmb++, *erase_s_v, *erase_m_v, "end");

// 		getchar();
// 		system("clear");
		
// 	}
	
// 	//***************************SWAP************************//
// 	if(swap)
// 	{
// 				std::cout << std::endl << "\x1b[33m" << "swap" << "\x1b[0m" << std::endl;

// 		ft::vector  <int> userVectorSwap;
// 		ft::vector  <int> userVectorSwap2;
// 		std::vector <int> sysVectorSwap;
// 		std::vector <int> sysVectorSwap2;
		
// 		for(int i = 0; i < 5; i++)
// 		{
// 			userVectorSwap.push_back(i);   //0 1 2 3 4
// 			sysVectorSwap.push_back(i);
// 		}

// 		for(int i = 5; i < 10; i++)
// 		{
// 			userVectorSwap2.push_back(i);  //5 6 7 8 9
// 			sysVectorSwap2.push_back(i);
// 		}		

// 		std::cout << "*** BEFORE ***" << std::endl;

// 		std::cout<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout << "User array:   ";
// 		for(size_t i = 0; i < userVectorSwap.size(); i++)
// 		{
// 			std::cout << userVectorSwap[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array: ";
// 		for(size_t i = 0; i < sysVectorSwap.size(); i++)
// 		{
// 			std::cout << sysVectorSwap[i]<< " ";
// 		}

// 		std::cout<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout << "User array2:   ";
// 		for(size_t i = 0; i < userVectorSwap2.size(); i++)
// 		{
// 			std::cout << userVectorSwap2[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array2: ";
// 		for(size_t i = 0; i < sysVectorSwap2.size(); i++)
// 		{
// 			std::cout << sysVectorSwap2[i]<< " ";
// 		}
// 		std::cout<< std::endl;


		

// 		userVectorSwap.swap(userVectorSwap2);
// 		sysVectorSwap.swap(sysVectorSwap2);
		


// 		std::cout << "***AFTER ***" << std::endl;

// 		std::cout << "User array:   ";
// 		for(size_t i = 0; i < userVectorSwap.size(); i++)
// 		{
// 			std::cout << userVectorSwap[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array: ";
// 		for(size_t i = 0; i < sysVectorSwap.size(); i++)
// 		{
// 			std::cout << sysVectorSwap[i]<< " ";
// 		}

// 		std::cout<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout << "User array2:   ";
// 		for(size_t i = 0; i < userVectorSwap2.size(); i++)
// 		{
// 			std::cout << userVectorSwap2[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array2: ";
// 		for(size_t i = 0; i < sysVectorSwap2.size(); i++)
// 		{
// 			std::cout << sysVectorSwap2[i]<< " ";
// 		}
// 		std::cout<< std::endl;

// 		ft::vector<int> ::iterator itSwap = userVectorSwap.end();
// 		itSwap--;
// 		std::vector<int> ::iterator itSwap2 = sysVectorSwap.end();
// 		itSwap2--;

// 		testFunc(testNmb++, sysVectorSwap.size(), userVectorSwap.size(), "begin first size");
// 		testFunc(testNmb++, *sysVectorSwap.begin(), *userVectorSwap.begin(), "begin first arr");
// 		testFunc(testNmb++, *itSwap, *itSwap2, "end first arr");

// 		itSwap = userVectorSwap2.end();
// 		itSwap--;
// 		itSwap2 = sysVectorSwap2.end();
// 		itSwap2--;

// 		testFunc(testNmb++, sysVectorSwap2.size(), userVectorSwap2.size(), "begin second size");
// 		testFunc(testNmb++, *sysVectorSwap2.begin(), *userVectorSwap2.begin(), "begin second arr");
// 		testFunc(testNmb++, *itSwap2, *itSwap, "end second arr");



// 		getchar();
// 		system("clear");

// 		std::cout << std::endl << "\x1b[33m" << "swap 2" << "\x1b[0m" << std::endl;

// 		userVectorSwap.clear();
// 		userVectorSwap2.clear();
// 		sysVectorSwap.clear();
// 		sysVectorSwap2.clear();
		
// 		for(int i = 0; i < 5; i++)
// 		{
// 			userVectorSwap.push_back(i);   //0 1 2 3 4
// 			sysVectorSwap.push_back(i);
// 		}		

// 		std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout << "User array:   ";
// 		for(size_t i = 0; i < userVectorSwap.size(); i++)
// 		{
// 			std::cout << userVectorSwap[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array: ";
// 		for(size_t i = 0; i < sysVectorSwap.size(); i++)
// 		{
// 			std::cout << sysVectorSwap[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout << "User array2:   ";
// 		for(size_t i = 0; i < userVectorSwap2.size(); i++)
// 		{
// 			std::cout << userVectorSwap2[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array2: ";
// 		for(size_t i = 0; i < sysVectorSwap2.size(); i++)
// 		{
// 			std::cout << sysVectorSwap2[i]<< " ";
// 		}
// 		std::cout<< std::endl;


// 		userVectorSwap.swap(userVectorSwap2);
// 		sysVectorSwap.swap(sysVectorSwap2);
		


// 		std::cout << "***AFTER ***" << std::endl;

// 		std::cout << "User array:   ";
// 		for(size_t i = 0; i < userVectorSwap.size(); i++)
// 		{
// 			std::cout << userVectorSwap[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array: ";
// 		for(size_t i = 0; i < sysVectorSwap.size(); i++)
// 		{
// 			std::cout << sysVectorSwap[i]<< " ";
// 		}

// 		std::cout<< std::endl;
// 		std::cout<< std::endl;
// 		std::cout << "User array2:   ";
// 		for(size_t i = 0; i < userVectorSwap2.size(); i++)
// 		{
// 			std::cout << userVectorSwap2[i]<< " ";
// 		}
// 		std::cout<< std::endl;
// 		std::cout << "System array2: ";
// 		for(size_t i = 0; i < sysVectorSwap2.size(); i++)
// 		{
// 			std::cout << sysVectorSwap2[i]<< " ";
// 		}
// 		std::cout<< std::endl;


// 		testFunc(testNmb++, userVectorSwap.size(), sysVectorSwap.size(), "first size");

// 		itSwap = userVectorSwap2.end();
// 		itSwap--;
// 		itSwap2 = sysVectorSwap2.end();
// 		itSwap2--;

// 		testFunc(testNmb++, userVectorSwap2.size(), sysVectorSwap2.size(), "second size");

// 		getchar();
// 		system("clear");



		

// 				std::cout << std::endl << "\x1b[33m" << "swap empty" << "\x1b[0m" << std::endl;

// 		userVectorSwap.clear();
// 		userVectorSwap2.clear();
// 		sysVectorSwap.clear();
// 		sysVectorSwap2.clear();
			

// 		std::cout << "*** BEFORE ***" << std::endl;
// 		std::cout << "User array:   ";
// 		print_ft_vector("userVectorSwap:", userVectorSwap);
// 		print_std_vector("sysVectorSwap:", sysVectorSwap);
// 		std::cout<< std::endl;
// 		std::cout << "User array2:   ";
// 		print_ft_vector("userVectorSwap2:", userVectorSwap2);
// 		print_std_vector("sysVectorSwap2:", sysVectorSwap2);
// 		std::cout<< std::endl;


		

// 		userVectorSwap.swap(userVectorSwap2);
// 		sysVectorSwap.swap(sysVectorSwap2);
		


// 		std::cout << "***AFTER ***" << std::endl;
// 		std::cout << "User array:   ";
// 		print_ft_vector("userVectorSwap:", userVectorSwap);
// 		print_std_vector("sysVectorSwap:", sysVectorSwap);

// 		std::cout << "User array2:   ";
// 		print_ft_vector("userVectorSwap2:", userVectorSwap2);
// 		print_std_vector("sysVectorSwap2:", sysVectorSwap2);
// 		std::cout<< std::endl;


// 		testFunc(testNmb++, userVectorSwap.size(), sysVectorSwap.size(), "first size");
// 		testFunc(testNmb++, userVectorSwap2.size(), sysVectorSwap2.size(), "second size");


// 		getchar();
// 		system("clear");
// 	}
	
// 	//***************************CLEAR************************//
// 	if(clear)
// 	{
// 		std::cout << std::endl << "\x1b[33m" << "clear" << "\x1b[0m" << std::endl;
// 		ft::vector  <int> userVectorClear(7,4);
// 		std::vector <int> sysVectorClear(7,4);
// 		// std::vector <int>::iterator clear_s = userVectorClear.begin(); 
// 		// ft::vector <int>::iterator clear_m = userVectorClear.begin();
// 		// std::cout << "*** BEFORE ***" << std::endl;
// 		// std::cout << "userVectorClear size: "<< userVectorClear.size()<< std::endl;
// 		// std::cout << "sysVectorClear size: "<< sysVectorClear.size()<< std::endl;

// 		userVectorClear.clear();
// 		sysVectorClear.clear();

// 		// std::cout << "*** AFTER ***" << std::endl;
// 		// std::cout << "userVectorClear size: "<< userVectorClear.size()<< std::endl;
// 		// std::cout << "sysVectorClear size: "<< sysVectorClear.size()<< std::endl;

		
// 		testFunc(testNmb++, sysVectorClear.size(), userVectorClear.size(), "vector clear");
// 	}

// }

// void				allocator_vector(int testNmb)
// {
// 	std::cout << std::endl << "\x1b[33m" << "                              *** ALLOCATOR ***                          " << "\x1b[0m" << std::endl;
	
// 	std::vector<int> sysalloc;
// 	std::vector<int> myalloc;
// 	int * sys;
// 	int * my;
// 	unsigned int i;

// 	// allocate an array with space for 5 elements using vector's allocator:
// 	sys =sysalloc.get_allocator().allocate(5);
// 	my =  myalloc.get_allocator().allocate(5);

// 	// construct values in-place on the array:
// 	for (i=0; i<5; i++) sysalloc.get_allocator().construct(&sys[i],i);
// 	for (i=0; i<5; i++) myalloc.get_allocator().construct(&my[i],i);

// 	std::cout << "The allocated array contains system:";
// 	for (i=0; i<5; i++) std::cout << ' ' << sys[i];

// 	std::cout << "The allocated array contains my:";
// 	for (i=0; i<5; i++) std::cout << ' ' << my[i];

	
	
// 	std::cout << '\n';
// 	testFunc(testNmb++,  my[0],  sys[0], "alloc[0]");

// 	getchar();
// 		system("clear");
	
// }

// void				overloads_vector(int testNmb)
// {
// 	std::cout << std::endl << "\x1b[33m" << "                         *** OVERLOADES ***                          " << "\x1b[0m" << std::endl;

// 		std::vector<int> Sys_aV;
// 		std::vector<int> Sys_bV;
// 		std::vector<int> Sys_cV;

// 		ft::vector<int> User_aV;
// 		ft::vector<int> User_bV;
// 		ft::vector<int> User_cV;
// 		for (int i = 10; i < 40;)
// 		{
// 			Sys_aV.push_back(i);
// 			Sys_bV.push_back(i);
// 			User_aV.push_back(i);
// 			User_bV.push_back(i);
// 			i += 10;
// 		}
// 		for (int i = 30; i >= 10;)
// 		{
// 			Sys_cV.push_back(i);
// 			User_cV.push_back(i);
// 			i -= 10;
// 		}
		
// 		std::cout << "*** BEFORE ***" << std::endl;
		
// 		print_std_vector("sys_aV:", Sys_aV);
// 		print_std_vector("sys_bV:", Sys_bV);
// 		print_std_vector("sys_cV:", Sys_cV);
// 		std::cout << std::endl;	
// 		print_ft_vector("user_aV:", User_aV);
// 		print_ft_vector("user_bV:", User_bV);
// 		print_ft_vector("user_cV:", User_cV);
// 		std::cout << std::endl;
// 		bool equality = (User_aV == User_bV);
// 		bool unequality = (User_bV != User_cV);
// 		bool less = (User_bV < User_cV);
// 		bool more = (User_cV > User_bV);
// 		bool lessAndEquality = (User_aV <= User_bV);
// 		bool moreAndEquality = (User_aV >= User_bV);


// 		bool equality2 = (Sys_aV == Sys_bV);
// 		bool unequality2 = (Sys_bV != Sys_cV);
// 		bool less2 = (Sys_bV < Sys_cV);
// 		bool more2 = (Sys_cV > Sys_bV);
// 		bool lessAndEquality2 = (Sys_aV <= Sys_bV);
// 		bool moreAndEquality2 = (Sys_aV >= Sys_bV);

// 		testFunc(testNmb++, equality, equality2, "a == b");
// 		testFunc(testNmb++, unequality, unequality2, "b != c");
// 		testFunc(testNmb++, less, less2, "b < c");
// 		testFunc(testNmb++, more, more2, "c > b");
// 		testFunc(testNmb++, lessAndEquality, lessAndEquality2, "a <= b");
// 		testFunc(testNmb++, moreAndEquality, moreAndEquality2, "a >= b");
// }





void				vector_test()
{
	int testNmb = 0;
	// int testAll = 1;

	system("clear");
	
	std::cout << "\x1b[33m" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "|         VECTOR TESTING         |" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl << std::endl;
	std::cout << "\x1b[0m";

	/*			Member functions			*/
	constructor_vector(testNmb);	
	// iterators_vector(testNmb, 1);
	// capacity_vector(testNmb, 1);
	// elementAccess_vector(testNmb, 1);
	// modifiers_vector(testNmb, testAll);
	// overloads_vector(testNmb);
	
	/* extra */
	// allocator_vector(testNmb);
}

