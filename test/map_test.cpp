/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:48:16 by gbroccol          #+#    #+#             */
/*   Updated: 2021/04/02 20:42:43 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers_test.hpp"

void				constructor_map(int testNmb, int testAll)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** CONSTRUCTOR ***                          " << "\x1b[0m" << std::endl;

	std::map <int, int> mapSys;
	ft::map <int, int> mapUser;

	int defaultC = 0;
	int InputIteratorC = 0;
	int copyC = 0;

	if (testAll)
	{
		defaultC = 1;
		InputIteratorC = 1;
		copyC = 1;
	}

	if (defaultC)
	{
		/* default constructor */
		std::cout << std::endl << "\x1b[33m" << "default constructor" << "\x1b[0m" << std::endl;
		
		mapSys.insert ( std::pair <int, int> (20, 42) );
		mapSys.insert ( std::pair <int, int> (20, 42) );
		mapSys.insert ( std::pair <int, int> (10, 10) );
		mapSys.insert ( std::pair <int, int> (42, 0) );

		/* user part */

		mapUser.insert ( std::pair <int, int> (20, 42) );
		mapUser.insert ( std::pair <int, int> (20, 42) );
		mapUser.insert ( std::pair <int, int> (10, 10) );
		mapUser.insert ( std::pair <int, int> (42, 0) );
		
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);

		testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
		getchar();
		system("clear");
	}

	if (InputIteratorC)
	{
		/* constructor InputIterator */
		std::cout << std::endl << "\x1b[33m" << "constructor InputIterator" << "\x1b[0m" << std::endl;

	// 	std::map<char,int> mapSysChar;
	// 	ft::map<char,int> mapUserChar;

	// 	mapSysChar.insert ( std::pair <int, int> (20, 42) );
	// 	mapSysChar.insert ( std::pair <int, int> (30, 75) );
	// 	mapSysChar.insert ( std::pair <int, int> (-150, 0) );
	// 	mapSysChar.insert ( std::pair <int, int> (150, 60) );
		
	// 	mapUserChar.insert ( std::pair <int, int> (20, 42) );
	// 	mapUserChar.insert ( std::pair <int, int> (30, 75) );
	// 	mapUserChar.insert ( std::pair <int, int> (-150, 0) );
	// 	mapUserChar.insert ( std::pair <int, int> (150, 60) );

	// 	// mapSysChar['a']=10;
	// 	// mapSysChar['b']=30;
	// 	// mapSysChar['c']=50;
	// 	// mapSysChar['d']=70;

	// 	// mapUserChar['a']=10;
	// 	// mapUserChar['b']=30;
	// 	// mapUserChar['c']=50;
	// 	// mapUserChar['d']=70;

	//   	std::map<int,int> mapSysChar2 (mapSysChar.begin(),mapSysChar.end());
	// 	ft::map<int,int> mapUserChar2 (mapUserChar.begin(),mapUserChar.end());

		
	// 	std::cout << "******* AFTER *******"<<std::endl;
	// 	print_std_map("     sysMap: ",  mapSysChar2);
	// 	print_ft_map("    userMap: ", mapUserChar2);

	// 	ft::map<int, int>:: iterator IterUser = mapUserChar2.end();
	// 	IterUser--;
	// 	std::map<int, int>:: iterator IterSys = mapSysChar2.end();
	// 	IterSys--;
	// 	testFunc(testNmb++, mapSysChar2.begin()->first, mapUserChar2.begin()->first, "begin");
	// 	testFunc(testNmb++, mapSysChar2.size(), mapUserChar2.size(), "Size is");
	// 	testFunc(testNmb++, IterSys->first, IterUser->first, "end");

	// 	getchar();
	// 	system("clear");

		/* constructor InputIterator */
		std::cout << std::endl << "\x1b[33m" << "constructor InputIterator" << "\x1b[0m" << std::endl;

	// 	mapSysChar.clear();
	// 	mapUserChar.clear();

	//   	std::map<int,int> mapSysChar3 (mapSysChar.begin(),mapSysChar.end());
	// 	ft::map<int,int> mapUserChar3 (mapUserChar.begin(),mapUserChar.end());

		
	// 	std::cout << "******* AFTER *******"<<std::endl;
	// 	print_std_map("     sysMap: ",  mapSysChar3);
	// 	print_ft_map("    userMap: ", mapUserChar3);

	// 	testFunc(testNmb++, mapSysChar3.size(), mapUserChar3.size(), "Size is");

	// 	getchar();
	// 	system("clear");
	}

	if (copyC)
	{
		/* copy constructor 1 */
		std::cout << std::endl << "\x1b[33m" << "copy constructor 1" << "\x1b[0m" << std::endl;
		
		mapSys.clear();
		mapUser.clear();

		mapSys.insert ( std::pair <int, int> (20, 42) );
		mapSys.insert ( std::pair <int, int> (30, 75) );
		mapSys.insert ( std::pair <int, int> (-150, 0) );
		mapSys.insert ( std::pair <int, int> (150, 60) );
		
		mapUser.insert ( std::pair <int, int> (20, 42) );
		mapUser.insert ( std::pair <int, int> (30, 75) );
		mapUser.insert ( std::pair <int, int> (-150, 0) );
		mapUser.insert ( std::pair <int, int> (150, 60) );

	  	std::map<int, int> mapSys2 (mapSys);
		// ft::map<int, int> mapUser2 (mapUser);

		std::cout << "******* AFTER *******"<<std::endl;
		print_std_map("     sysMap: ",  mapSys2);
		// print_ft_map("    userMap: ", mapUser2);

		// IterUser = mapUser2.end();
		// IterSys = mapSys2.end();
		
		// IterUser--;
		// IterSys--;

		// testFunc(testNmb++, mapSys2.begin()->first, mapUser2.begin()->first, "begin");
		// testFunc(testNmb++, mapSys2.size(), mapUser2.size(), "Size is");
		// testFunc(testNmb++, IterSys->first, IterUser->first, "end");

		getchar();
		// system("clear");

		/* copy constructor 2 */
		// std::cout << std::endl << "\x1b[33m" << "copy constructor 2" << "\x1b[0m" << std::endl;
		
	// 	mapSys.clear();
	// 	mapUser.clear();

	//   std::map<int,int> mapSys4 (mapSys);
	// 	ft::map<int,int> mapUser4 (mapUser);

		
	// 	std::cout << "******* AFTER *******"<<std::endl;
	// 	print_std_map("     sysMap: ",  mapSys4);
	// 	print_ft_map("    userMap: ", mapUser4);

	// 	testFunc(testNmb++, mapSys4.size(), mapUser4.size(), "Size is");

		getchar();
	}
	
	system("clear");
}

void				iterators_map(int testNmb, int testAll)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** ITERATORS ***                          " << "\x1b[0m" << std::endl;
	
	int			begin = 1;
	int			end = 1;
	int			rbegin = 0;
	int			rend = 0;

	if (testAll)
	{
		begin = 1;
		end = 1;
		rbegin = 1;
		rend = 1;
	}
	
	/* *************************** BEGIN AND END ************************/
	if(begin && end)
	{
		std::cout << std::endl << "\x1b[33m" << "begin and end" << "\x1b[0m" << std::endl;
		std::map <int, int> mapSys;
		ft::map <int, int> mapUser;
		mapSys.insert ( std::pair <int, int> (42, 0) );
		mapUser.insert ( std::pair <int, int> (42, 0) );
		mapSys.insert ( std::pair <int, int> (21, 0) );
		mapUser.insert ( std::pair <int, int> (21, 0) );
		mapSys.insert ( std::pair <int, int> (30, 5) );
		mapUser.insert ( std::pair <int, int> (30, 5) );
		mapSys.insert ( std::pair <int, int> (12, 45) );
		mapUser.insert ( std::pair <int, int> (12, 45) );

		
		testFunc(testNmb++, mapSys.begin()->first, mapUser.begin()->first, "begin");
		std::map <int, int> ::iterator iterSysBeginEnd = mapSys.end();
		iterSysBeginEnd--;
		ft::map <int, int> :: iterator iterUserBeginEnd = mapUser.end();
		iterUserBeginEnd--;
		testFunc(testNmb++, iterSysBeginEnd->first, iterUserBeginEnd->first, "end");
		
		getchar();

		iterSysBeginEnd = mapSys.begin();
		iterSysBeginEnd++;
		iterUserBeginEnd = mapUser.begin();
		iterUserBeginEnd++;

		testFunc(testNmb++, iterSysBeginEnd->first, iterUserBeginEnd->first, "++begin");
		iterSysBeginEnd = mapSys.end();
		iterSysBeginEnd--;
		iterSysBeginEnd--;
		iterUserBeginEnd = mapUser.end();
		iterUserBeginEnd--;
		iterUserBeginEnd--;
		testFunc(testNmb++, iterSysBeginEnd->first, iterUserBeginEnd->first, "--end");
		
		getchar();

		// std::cout << std::endl << "\x1b[33m" << "const begin and end" << "\x1b[0m" << std::endl;

		// const std::map <int, int> mapSysConst(mapSys.begin(), mapSys.end());
		// const ft::map <int, int> mapUserConst(mapUser.begin(), mapUser.end());

		// std::map <int, int> ::const_iterator iterSysBeginEndConst = mapSysConst.end();
		// ft::map <int, int> :: const_iterator iterUserBeginEndConst = mapUserConst.end();

		// iterSysBeginEndConst--;
		// iterUserBeginEndConst--;

		// testFunc(testNmb++, mapSysConst.begin()->first, mapUserConst.begin()->first, "const begin");
		// testFunc(testNmb++,  iterSysBeginEndConst->first, iterUserBeginEndConst->first, "const end");

		// getchar();

		// iterSysBeginEnd = mapSys.begin();
		// iterSysBeginEnd++;
		// iterUserBeginEnd = mapUser.begin();
		// iterUserBeginEnd++;

		// testFunc(testNmb++, iterSysBeginEnd->first, iterUserBeginEnd->first, "++begin");
		// iterSysBeginEnd = mapSys.end();
		// iterSysBeginEnd--;
		// iterSysBeginEnd--;
		// iterUserBeginEnd = mapUser.end();
		// iterUserBeginEnd--;
		// iterUserBeginEnd--;
		// testFunc(testNmb++, iterSysBeginEnd->first, iterUserBeginEnd->first, "--end");
		// getchar();
		
		// system("clear");
	}

	/* ************************** REVERSE BEGIN AND END *********************** */
	if(rbegin && rend)
	{
		std::cout << std::endl << "\x1b[33m" << "reverse begin and end" << "\x1b[0m" << std::endl;
// 		std::map <int, int> mapSys;
// 		ft::map <int, int> mapUser;
// 		mapSys.insert ( std::pair <int, int> (42, 0) );
// 		mapUser.insert ( std::pair <int, int> (42, 0) );
// 		mapSys.insert ( std::pair <int, int> (21, 0) );
// 		mapUser.insert ( std::pair <int, int> (21, 0) );
// 		mapSys.insert ( std::pair <int, int> (30, 5) );
// 		mapUser.insert ( std::pair <int, int> (30, 5) );
// 		mapSys.insert ( std::pair <int, int> (12, 45) );
// 		mapUser.insert ( std::pair <int, int> (12, 45) );

// 		std::map <int, int>::reverse_iterator iterSysBeginEndRev = mapSys.rbegin();
// 		ft::map <int, int>::reverse_iterator iterUserBeginEndRev = mapUser.rbegin();
// 		testFunc(testNmb++, iterSysBeginEndRev->first, iterUserBeginEndRev->first, "rbegin");
// 		iterSysBeginEndRev = mapSys.rend();
// 		iterSysBeginEndRev--;
// 		iterUserBeginEndRev = mapUser.rend();
// 		iterUserBeginEndRev--;
// 		testFunc(testNmb++, iterSysBeginEndRev->first, iterUserBeginEndRev->first, "rend");

// 		iterSysBeginEndRev = mapSys.rbegin();
// 		iterSysBeginEndRev++;
// 		iterUserBeginEndRev = mapUser.rbegin();
// 		iterUserBeginEndRev++;

// 		testFunc(testNmb++, iterSysBeginEndRev->first, iterUserBeginEndRev->first, "++rbegin");
// 		iterSysBeginEndRev = mapSys.rend();
// 		iterSysBeginEndRev--;
// 		iterSysBeginEndRev--;
// 		iterUserBeginEndRev = mapUser.rend();
// 		iterUserBeginEndRev--;
// 		iterUserBeginEndRev--;
// 		testFunc(testNmb++, iterSysBeginEndRev->first, iterUserBeginEndRev->first, "--rend");

// 		std::cout << std::endl << "\x1b[33m" << "const reverse begin and end" << "\x1b[0m" << std::endl;

// 		const std::map <int, int> mapSysConst(mapSys.begin(), mapSys.end());
// 		const ft::map <int, int> mapUserConst(mapUser.begin(), mapUser.end());

// 		std::map <int, int> ::const_reverse_iterator iterSysBeginEndConstRev = mapSysConst.rend();
// 		ft::map <int, int> :: const_reverse_iterator iterUserBeginEndConstRev = mapUserConst.rend();

// 		iterSysBeginEndConstRev--;
// 		iterUserBeginEndConstRev--;

// 		testFunc(testNmb++, mapSysConst.rbegin()->first, mapUserConst.rbegin()->first, "const rbegin");
// 		testFunc(testNmb++,  iterSysBeginEndConstRev->first, iterUserBeginEndConstRev->first, "const rend");

// 		getchar();

// 		iterSysBeginEndRev = mapSys.rbegin();
// 		iterSysBeginEndRev++;
// 		iterUserBeginEndRev = mapUser.rbegin();
// 		iterUserBeginEndRev++;

// 		testFunc(testNmb++, iterSysBeginEndRev->first, iterUserBeginEndRev->first, "++rbegin");
// 		iterSysBeginEndRev = mapSys.rend();
// 		iterSysBeginEndRev--;
// 		iterSysBeginEndRev--;
// 		iterUserBeginEndRev = mapUser.rend();
// 		iterUserBeginEndRev--;
// 		iterUserBeginEndRev--;
// 		testFunc(testNmb++, iterSysBeginEndRev->first, iterUserBeginEndRev->first, "--rend");
	
		getchar();
// 		system("clear");
	}
	// system("clear");
}

void				capacity_map(int testNmb, int testAll)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** CAPACITY ***                          " << "\x1b[0m" << std::endl;
	
	int			size = 0;	  
	int			max_size = 0; 
	int			empty = 0;	 

	testNmb++; 

	if (testAll)
	{
		size = 1;	  
		max_size = 1;
		empty = 1;
	}

	std::map <int, int> mapSys;
	ft::map <int, int> mapUser;
	
	//*************************** SIZE ************************//
	if(size)
	{
		std::cout << std::endl << "\x1b[33m" << "size" << "\x1b[0m" << std::endl;

		testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
	}

	//*************************** MAX_SIZE ************************//
	if(max_size)
	{
		std::cout << std::endl << "\x1b[33m" << "max_size" << "\x1b[0m" << std::endl;

		testFunc(testNmb++, mapSys.max_size(), mapUser.max_size(), "Size is");
	}

	//*************************** EMPTY ************************//
	if(empty)
	{
		std::cout << std::endl << "\x1b[33m" << "empty" << "\x1b[0m" << std::endl;
		testFunc(testNmb++, mapSys.empty(), mapUser.empty(), "Empty");

		mapSys.insert ( std::pair <int, int> (1, 10) );
		mapUser.insert ( std::pair <int, int> (1, 10) );

		testFunc(testNmb++, mapSys.empty(), mapUser.empty(), "Empty");
	}
	getchar();
}

void				element_access_map(int testNmb, int testAll)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** ELEMENT ACCESS ***                          " << "\x1b[0m" << std::endl;
	
	int			Operator = 0;	  

	if (testAll)
	{
		Operator = 1;	  
	}
	
	//***************************OPERATOR []************************//
	if (Operator)
	{
		std::cout << std::endl << "\x1b[33m" << "operator []" << "\x1b[0m" << std::endl;
		
		std::map <int, int> mapSys;
		ft::map <int, int> mapUser;

		mapSys.insert ( std::pair <int, int> (20, 1) );
		mapSys.insert ( std::pair <int, int> (20, 2) );
		mapSys.insert ( std::pair <int, int> (10, 3) );
		mapSys.insert ( std::pair <int, int> (42, 4) );
		
		mapSys.insert ( std::pair <int, int> (-50, 5) );
		mapSys.insert ( std::pair <int, int> (15, 6) );
		mapSys.insert ( std::pair <int, int> (30, 7) );
		mapSys.insert ( std::pair <int, int> (100, 8) );

		mapSys.insert ( std::pair <int, int> (-99, 9) );
		mapSys.insert ( std::pair <int, int> (1, 10) );

		/* user part */

		mapUser.insert ( std::pair <int, int> (20, 1) );
		mapUser.insert ( std::pair <int, int> (20, 2) );
		mapUser.insert ( std::pair <int, int> (10, 3) );
		mapUser.insert ( std::pair <int, int> (42, 4) );
		
		mapUser.insert ( std::pair <int, int> (-50, 5) );
		mapUser.insert ( std::pair <int, int> (15, 6) );
		mapUser.insert ( std::pair <int, int> (30, 7) );
		mapUser.insert ( std::pair <int, int> (100, 8) );

		mapUser.insert ( std::pair <int, int> (-99, 9) );
		mapUser.insert ( std::pair <int, int> (1, 10) );

		testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
		
		testFunc(testNmb++, mapSys[20], mapUser[20],		"Value is");
		testFunc(testNmb++, mapSys[10], mapUser[10],		"Value is");
		testFunc(testNmb++, mapSys[42], mapUser[42],		"Value is");
		testFunc(testNmb++, mapSys[-50], mapUser[-50],		"Value is");
		testFunc(testNmb++, mapSys[15], mapUser[15],		"Value is");
		testFunc(testNmb++, mapSys[30], mapUser[30],		"Value is");
		testFunc(testNmb++, mapSys[100], mapUser[100],		"Value is");
		testFunc(testNmb++, mapSys[-99], mapUser[-99],		"Value is");
		testFunc(testNmb++, mapSys[1], mapUser[1],			"Value is");

		testFunc(testNmb++, mapSys[15555], mapUser[15555],			"No Such Value");
		
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);
	}
	getchar();
	system("clear");
}

void				modifiers_map(int testNmb, int testAll)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** MODIFIERS ***                          " << "\x1b[0m" << std::endl;

	int			insert1 = 0;			// std::pair<iterator, bool> insert(const value_type &val)
	int			insert2 = 0;			// iterator insert(iterator position, const value_type &val)
	int			insert3 = 1;			// void insert (InputIterator first, InputIterator last);
	int			erase = 0; 
	int			swap = 0;
	int			clear = 0;

	if (testAll)
	{
		insert1 = 1;
		insert2 = 1;
		insert3 = 1;
		erase = 1; 
		swap = 1;
		clear = 1;
	}

	std::map <int, int> mapSys;
	ft::map <int, int> mapUser;

	std::map <int, int> mapSys2;
	ft::map <int, int> mapUser2;

	ft::map<int, int>:: iterator IterUser;
	std::map<int, int>:: iterator IterSys;

	//***************************INSERT************************//
	if(insert1)
	{
		/* insert */
		std::cout << std::endl << "\x1b[33m" << "insert 1 (print it)" << "\x1b[0m" << std::endl;
		
		mapSys.insert ( std::pair <int, int> (20, 42) );
		mapSys.insert ( std::pair <int, int> (20, 42) );
		mapSys.insert ( std::pair <int, int> (10, 10) );
		mapSys.insert ( std::pair <int, int> (42, 0) );
		
		mapSys.insert ( std::pair <int, int> (-50, 0) );
		mapSys.insert ( std::pair <int, int> (15, 0) );
		mapSys.insert ( std::pair <int, int> (30, 0) );
		mapSys.insert ( std::pair <int, int> (100, 0) );

		mapSys.insert ( std::pair <int, int> (-99, 0) );
		mapSys.insert ( std::pair <int, int> (1, 0) );

		mapSys.insert ( std::pair <int, int> (14, 0) );
		mapSys.insert ( std::pair <int, int> (16, 0) );
		
		mapSys.insert ( std::pair <int, int> (29, 0) );
		mapSys.insert ( std::pair <int, int> (40, 0) );
		
		mapSys.insert ( std::pair <int, int> (45, 0) );
		mapSys.insert ( std::pair <int, int> (105, 0) );

		/* user part */

		mapUser.insert ( std::pair <int, int> (20, 0) );
		mapUser.insert ( std::pair <int, int> (20, 0) );
		mapUser.insert ( std::pair <int, int> (10, 0) );
		mapUser.insert ( std::pair <int, int> (42, 0) );
		
		mapUser.insert ( std::pair <int, int> (-50, 0) );
		mapUser.insert ( std::pair <int, int> (15, 0) );
		mapUser.insert ( std::pair <int, int> (30, 0) );
		mapUser.insert ( std::pair <int, int> (100, 0) );

		mapUser.insert ( std::pair <int, int> (-99, 0) );
		mapUser.insert ( std::pair <int, int> (1, 0) );

		mapUser.insert ( std::pair <int, int> (14, 0) );
		mapUser.insert ( std::pair <int, int> (16, 0) );
		
		mapUser.insert ( std::pair <int, int> (29, 0) );
		mapUser.insert ( std::pair <int, int> (40, 0) );
		
		mapUser.insert ( std::pair <int, int> (45, 0) );
		mapUser.insert ( std::pair <int, int> (105, 0) );
		
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);
		
		IterUser = mapUser.end();
		IterSys = mapSys.end();

		IterUser--;
		IterSys--;
		
		testFunc(testNmb++, mapSys.begin()->first, mapUser.begin()->first, "begin");
		testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
		testFunc(testNmb++, IterSys->first, IterUser->first, "end");

		getchar();
		
		/* insert 2 */
		std::cout << std::endl << "\x1b[33m" << "insert 2 (print it inverted tree)" << "\x1b[0m" << std::endl;

		print_std_map_inv("     sysMap: ", mapSys);
		print_ft_map_inv("    userMap: ", mapUser);

		testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");

		getchar();

		std::cout << std::endl << "\x1b[33m" << "insert 3" << "\x1b[0m" << std::endl;
		
		mapSys.clear();
		mapUser.clear();

		mapSys.insert ( std::pair <int, int> (55 , 0) );
		mapSys.insert ( std::pair <int, int> (40 , 0) );
		mapSys.insert ( std::pair <int, int> (65 , 0) );
		mapSys.insert ( std::pair <int, int> (60 , 0) );
		mapSys.insert ( std::pair <int, int> (75 , 0) );
		mapSys.insert ( std::pair <int, int> (57 , 0) );
		mapSys.insert ( std::pair <int, int> (45 , 0) );
		mapSys.insert ( std::pair <int, int> (41 , 0) );

		/* user part */

		mapUser.insert ( std::pair <int, int> (55 , 0) );
		mapUser.insert ( std::pair <int, int> (40 , 0) );
		mapUser.insert ( std::pair <int, int> (65 , 0) );
		mapUser.insert ( std::pair <int, int> (60 , 0) );
		mapUser.insert ( std::pair <int, int> (75 , 0) );
		mapUser.insert ( std::pair <int, int> (57 , 0) );
		mapUser.insert ( std::pair <int, int> (45 , 0) );
		mapUser.insert ( std::pair <int, int> (41 , 0) );
		
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);
		IterUser = mapUser.end();
		IterUser--;
		IterSys = mapSys.end();
		IterSys--;
		testFunc(testNmb++, mapSys.begin()->first, mapUser.begin()->first, "begin");
		testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
		testFunc(testNmb++, IterSys->first, IterUser->first, "end");

		getchar();
	}

	if(insert2)
	{
		/* insert 2.0 */
		std::cout << std::endl << "\x1b[33m" << "insert 2.0 (true position - add -150 to begin())" << "\x1b[0m" << std::endl;
		
		mapSys.insert ( std::pair <int, int> (20, 0) );
		mapSys.insert ( std::pair <int, int> (20, 0) );
		mapSys.insert ( std::pair <int, int> (10, 10) );
		mapSys.insert ( std::pair <int, int> (42, 0) );
		
		mapSys.insert ( std::pair <int, int> (-50, 0) );
		mapSys.insert ( std::pair <int, int> (15, 0) );
		mapSys.insert ( std::pair <int, int> (30, 0) );
		mapSys.insert ( std::pair <int, int> (100, 0) );

		mapSys.insert ( std::pair <int, int> (-99, 0) );
		mapSys.insert ( std::pair <int, int> (1, 0) );

		mapSys.insert ( std::pair <int, int> (14, 0) );
		mapSys.insert ( std::pair <int, int> (16, 0) );
		
		mapSys.insert ( std::pair <int, int> (29, 0) );
		mapSys.insert ( std::pair <int, int> (40, 0) );
		
		mapSys.insert ( std::pair <int, int> (45, 0) );
		mapSys.insert ( std::pair <int, int> (105, 0) );

		/* user part */

		mapUser.insert ( std::pair <int, int> (20, 0) );
		mapUser.insert ( std::pair <int, int> (20, 0) );
		mapUser.insert ( std::pair <int, int> (10, 0) );
		mapUser.insert ( std::pair <int, int> (42, 0) );
		
		mapUser.insert ( std::pair <int, int> (-50, 0) );
		mapUser.insert ( std::pair <int, int> (15, 0) );
		mapUser.insert ( std::pair <int, int> (30, 0) );
		mapUser.insert ( std::pair <int, int> (100, 0) );

		mapUser.insert ( std::pair <int, int> (-99, 0) );
		mapUser.insert ( std::pair <int, int> (1, 0) );

		mapUser.insert ( std::pair <int, int> (14, 0) );
		mapUser.insert ( std::pair <int, int> (16, 0) );
		
		mapUser.insert ( std::pair <int, int> (29, 0) );
		mapUser.insert ( std::pair <int, int> (40, 0) );
		
		mapUser.insert ( std::pair <int, int> (45, 0) );
		mapUser.insert ( std::pair <int, int> (105, 0) );
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);

		mapUser.printTree();
		
		IterSys = mapSys.begin();
		IterUser = mapUser.begin();

		IterSys = mapSys.insert(IterSys, std::pair<int,int>(-150, 300));
		IterUser = mapUser.insert(IterUser, std::pair<int,int>(-150, 300));

		std::cout << "*** AFTER ***" << std::endl;
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);

		mapUser.printTree();

		testFunc(testNmb++, mapSys.begin()->first,  mapUser.begin()->first, "Begin");
		testFunc(testNmb++, mapSys.size(), 			mapUser.size(), "Size is");
		testFunc(testNmb++, IterSys->first, 		IterUser->first, "Return value (first) is");
		testFunc(testNmb++, IterSys->second, 		IterUser->second, "Return value (second) is");
		IterSys++;
		IterUser++;
		testFunc(testNmb++, IterSys->first, IterUser->first, "Return value is");
		testFunc(testNmb++, IterSys->second, IterUser->second, "Return value is");

		getchar();

		/* insert 2.1 */
		std::cout << std::endl << "\x1b[33m" << "insert 2.1 (true position - add 110 to end())" << "\x1b[0m" << std::endl;

		IterSys = mapSys.end();
		IterUser = mapUser.end();

		IterSys--;
		IterUser--;

		IterSys = mapSys.insert(IterSys, std::pair<int,int>(110, 300));
		IterUser = mapUser.insert(IterUser, std::pair<int,int>(110, 300));

		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);

		testFunc(testNmb++, mapSys.begin()->first, mapUser.begin()->first, "Begin");
		testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
		testFunc(testNmb++, IterSys->first, IterUser->first, "Return value (first) is");
		testFunc(testNmb++, IterSys->second, IterUser->second, "Return value (second) is");
		IterSys--;
		IterUser--;
		testFunc(testNmb++, IterSys->first, IterUser->first, "Return value is");
		testFunc(testNmb++, IterSys->second, IterUser->second, "Return value is");

		getchar();

		/* insert 2.2 */
		std::cout << std::endl << "\x1b[33m" << "insert 2.2 (false position - add 35 to end()--)" << "\x1b[0m" << std::endl;

		IterSys = mapSys.end();
		IterUser = mapUser.end();

		IterSys--;
		IterUser--;
		
		IterSys = mapSys.insert(IterSys, std::pair<int,int>(35, 35));
		IterUser = mapUser.insert(IterUser, std::pair<int,int>(35, 35));

		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);

		testFunc(testNmb++, mapSys.begin()->first, mapUser.begin()->first, "Begin");
		testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
		testFunc(testNmb++, IterSys->first, IterUser->first, "Return value (first) is");
		testFunc(testNmb++, IterSys->second, IterUser->second, "Return value (second) is");
		IterSys--;
		IterUser--;
		testFunc(testNmb++, IterSys->first, IterUser->first, "Return value is");
		testFunc(testNmb++, IterSys->second, IterUser->second, "Return value is");

		getchar();

		/* insert 2.3 */
		std::cout << std::endl << "\x1b[33m" << "insert 2.3 (there is such key(35))" << "\x1b[0m" << std::endl;

		IterSys = mapSys.insert(IterSys, std::pair<int,int>(35, 35));
		IterUser = mapUser.insert(IterUser, std::pair<int,int>(35, 35));

		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);

		testFunc(testNmb++, mapSys.begin()->first, mapUser.begin()->first, "Begin");
		testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
		testFunc(testNmb++, IterSys->first, IterUser->first, "Return value (first) is");
		testFunc(testNmb++, IterSys->second, IterUser->second, "Return value (second) is");
		IterSys--;
		IterUser--;
		testFunc(testNmb++, IterSys->first, IterUser->first, "Return value is");
		testFunc(testNmb++, IterSys->second, IterUser->second, "Return value is");

		getchar();

		/* insert 2.4 */
		std::cout << std::endl << "\x1b[33m" << "insert 2.4 (position from another map (add 11) - sega)" << "\x1b[0m" << std::endl;

		// mapSys.insert(mapSys2.begin(), std::pair<int,int>(11, 11));
		// mapSys.insert(mapUser2.begin(), std::pair<int,int>(-150,300));
		getchar();
	}

	if (insert3)
	{
		/* insert 1 */
		std::cout << std::endl << "\x1b[33m" << "insert 1 ( void insert (InputIterator first, InputIterator last);)" << "\x1b[0m" << std::endl;
		
		mapUser.clear();
		mapSys.clear();
		
		std::map <int, int> mapSys2;
		ft::map <int, int> mapUser2;
		
		mapSys.insert ( std::pair <int, int> (-50, 5) );
		mapSys.insert ( std::pair <int, int> (15, 6) );
		mapSys.insert ( std::pair <int, int> (30, 7) );
		mapSys.insert ( std::pair <int, int> (100, 8) );

		mapUser.insert ( std::pair <int, int> (-50, 5) );
		mapUser.insert ( std::pair <int, int> (15, 6) );
		mapUser.insert ( std::pair <int, int> (30, 7) );
		mapUser.insert ( std::pair <int, int> (100, 8) );

		ft::map<int, int>::iterator IterInsertUser = mapUser.begin();
		std::map<int, int>::iterator IterInsertSys = mapSys.begin();

		ft::map<int,int>::iterator IterInsertUserEnd = mapUser.end();
		IterInsertUserEnd--;
		std::map<int,int>::iterator IterInsertSysEnd = mapSys.end();
		IterInsertSysEnd--;
		std::cout << "******* BEFORE *******"<<std::endl;
		print_std_map("     sysMap: ", mapSys2);
		print_ft_map("    userMap: ", mapUser2);
		
		mapSys2.insert (IterInsertSys,  IterInsertSysEnd);
		mapUser2.insert (IterInsertUser, IterInsertUserEnd);

		std::cout << "******* AFTER *******"<<std::endl;
		print_std_map("     sysMap: ", mapSys2);
		print_ft_map("    userMap: ", mapUser2);
		ft::map<int, int>:: iterator IterUser = mapUser2.end();
		IterUser--;
		std::map<int, int>:: iterator IterSys = mapSys2.end();
		IterSys--;
		testFunc(testNmb++, mapSys2.begin()->first, mapUser2.begin()->first, "begin");
		testFunc(testNmb++, mapSys2.size(), mapUser2.size(), "Size is");
		testFunc(testNmb++, IterSys->first, IterUser->first, "end");
		getchar();
		system("clear");
		
		/* insert 2 */
		std::cout << std::endl << "\x1b[33m" << "insert 2 ((InputIterator first, InputIterator last);)" << "\x1b[0m" << std::endl;
		
		mapUser.clear();
		mapSys.clear();
		
		mapSys2.clear();
		mapSys2.insert ( std::pair <int, int> (30, 7) );
		mapSys2.insert ( std::pair <int, int> (100, 8) );
		mapSys2.insert ( std::pair <int, int> (-99, 9) );
		mapSys2.insert ( std::pair <int, int> (1, 10) );
		
		mapUser2.clear();
		mapUser2.insert ( std::pair <int, int> (30, 7) );
		mapUser2.insert ( std::pair <int, int> (100, 8) );
		mapUser2.insert ( std::pair <int, int> (-99, 9) );
		mapUser2.insert ( std::pair <int, int> (1, 10) );

		mapSys.insert ( std::pair <int, int> (-50, 5) );
		mapSys.insert ( std::pair <int, int> (15, 6) );
		mapSys.insert ( std::pair <int, int> (30, 7) );
		mapSys.insert ( std::pair <int, int> (100, 8) );

		mapUser.insert ( std::pair <int, int> (-50, 5) );
		mapUser.insert ( std::pair <int, int> (15, 6) );
		mapUser.insert ( std::pair <int, int> (30, 7) );
		mapUser.insert ( std::pair <int, int> (100, 8) );

		IterInsertUser = mapUser.begin();
		IterInsertSys = mapSys.begin();

		IterInsertUserEnd = mapUser.end();
		IterInsertUserEnd--;
		IterInsertSysEnd = mapSys.end();
		IterInsertSysEnd--;

		std::cout << "******* BEFORE *******"<<std::endl;
		print_std_map("     sysMap: ", mapSys2);
		print_ft_map("    userMap: ", mapUser2);
		
		mapSys2.insert (IterInsertSys,  IterInsertSysEnd);
		mapUser2.insert (IterInsertUser, IterInsertUserEnd);

		std::cout << "******* AFTER *******"<<std::endl;
		print_std_map("     sysMap: ", mapSys2);
		print_ft_map("    userMap: ", mapUser2);
		IterUser = mapUser2.end();
		IterUser--;
		IterSys = mapSys2.end();
		IterSys--;
		testFunc(testNmb++, mapSys2.begin()->first, mapUser2.begin()->first, "begin");
		testFunc(testNmb++, mapSys2.size(), mapUser2.size(), "Size is");
		testFunc(testNmb++, IterSys->first, IterUser->first, "end");

		getchar();
		system("clear");

		/* insert 3 */
		std::cout << std::endl << "\x1b[33m" << "insert 3 ((InputIterator first, InputIterator last);)" << "\x1b[0m" << std::endl;
		
		mapSys2.clear();
		mapSys2.insert ( std::pair <int, int> (30, 7) );
		mapSys2.insert ( std::pair <int, int> (100, 8) );
		mapSys2.insert ( std::pair <int, int> (-99, 9) );
		mapSys2.insert ( std::pair <int, int> (1, 10) );
		
		mapUser2.clear();
		mapUser2.insert ( std::pair <int, int> (30, 7) );
		mapUser2.insert ( std::pair <int, int> (100, 8) );
		mapUser2.insert ( std::pair <int, int> (-99, 9) );
		mapUser2.insert ( std::pair <int, int> (1, 10) );



		mapSys.insert ( std::pair <int, int> (-50, 5) );
		mapSys.insert ( std::pair <int, int> (15, 6) );
		mapSys.insert ( std::pair <int, int> (30, 7) );
		mapSys.insert ( std::pair <int, int> (100, 8) );

		mapUser.insert ( std::pair <int, int> (-50, 5) );
		mapUser.insert ( std::pair <int, int> (15, 6) );
		mapUser.insert ( std::pair <int, int> (30, 7) );
		mapUser.insert ( std::pair <int, int> (100, 8) );

		IterInsertUser = mapUser.begin();
		IterInsertSys = mapSys.begin();
		
		std::cout << "******* BEFORE *******"<<std::endl;
		print_std_map("     sysMap: ", mapSys2);
		print_ft_map("    userMap: ", mapUser2);
		
		mapSys2.insert (IterInsertSys,  ++IterInsertSys);
		mapUser2.insert (IterInsertUser, ++IterInsertUser);

		std::cout << "******* AFTER *******"<<std::endl;
		print_std_map("     sysMap: ", mapSys2);
		print_ft_map("    userMap: ", mapUser2);
		IterUser = mapUser2.end();
		IterUser--;
		IterSys = mapSys2.end();
		IterSys--;
		testFunc(testNmb++, mapSys2.begin()->first, mapUser2.begin()->first, "begin");
		testFunc(testNmb++, mapSys2.size(), mapUser2.size(), "Size is");
		testFunc(testNmb++, IterSys->first, IterUser->first, "end");

		getchar();
		system("clear");

		/* insert 4 */
		std::cout << std::endl << "\x1b[33m" << "insert 4 ((InputIterator first, InputIterator last);)" << "\x1b[0m" << std::endl;
		
		mapSys2.clear();
		mapUser2.clear();

		mapSys.clear();
		mapUser.clear();
	
		mapSys.insert ( std::pair <int, int> (-50, 5) );
		mapSys.insert ( std::pair <int, int> (15, 6) );
		mapSys.insert ( std::pair <int, int> (30, 7) );
		mapSys.insert ( std::pair <int, int> (100, 8) );

		mapUser.insert ( std::pair <int, int> (-50, 5) );
		mapUser.insert ( std::pair <int, int> (15, 6) );
		mapUser.insert ( std::pair <int, int> (30, 7) );
		mapUser.insert ( std::pair <int, int> (100, 8) );

		IterInsertUser = mapUser.begin();
		IterInsertSys = mapSys.begin();
		
		std::cout << "******* BEFORE *******"<<std::endl;
		print_std_map("     sysMap: ", mapSys2);
		print_ft_map("    userMap: ", mapUser2);
		
		mapSys2.insert (IterInsertSys,  ++IterInsertSys);
		mapUser2.insert (IterInsertUser, ++IterInsertUser);

		std::cout << "******* AFTER *******"<<std::endl;
		print_std_map("     sysMap: ", mapSys2);
		print_ft_map("    userMap: ", mapUser2);
		IterUser = mapUser2.end();
		IterUser--;
		IterSys = mapSys2.end();
		IterSys--;
		testFunc(testNmb++, mapSys2.begin()->first, mapUser2.begin()->first, "begin");
		testFunc(testNmb++, mapSys2.size(), mapUser2.size(), "Size is");
		testFunc(testNmb++, IterSys->first, IterUser->first, "end");

		getchar();
		system("clear");

		/* insert 5 */
		std::cout << std::endl << "\x1b[33m" << "insert 5 ((InputIterator first, InputIterator last);) - sega" << "\x1b[0m" << std::endl;
		
		mapSys.clear();
		mapUser.clear();
		
		mapSys2.clear();
		mapUser2.clear();
	
		mapSys2.insert ( std::pair <int, int> (-50, 5) );
		mapSys2.insert ( std::pair <int, int> (15, 6) );
		mapSys2.insert ( std::pair <int, int> (30, 7) );
		mapSys2.insert ( std::pair <int, int> (100, 8) );

		mapUser2.insert ( std::pair <int, int> (-50, 5) );
		mapUser2.insert ( std::pair <int, int> (15, 6) );
		mapUser2.insert ( std::pair <int, int> (30, 7) );
		mapUser2.insert ( std::pair <int, int> (100, 8) );

		IterInsertUser = mapUser.begin();
		IterInsertSys = mapSys.begin();
		
		std::cout << "******* BEFORE *******"<<std::endl;
		print_std_map("     sysMap: ", mapSys2);
		print_ft_map("    userMap: ", mapUser2);
		
		mapSys2.insert (IterInsertSys,  IterInsertSys);
		mapUser2.insert (IterInsertUser, IterInsertUser);

		std::cout << "******* AFTER *******"<<std::endl;
		print_std_map("     sysMap: ", mapSys2);
		print_ft_map("    userMap: ", mapUser2);
		IterUser = mapUser2.end();
		IterUser--;
		IterSys = mapSys2.end();
		IterSys--;
		testFunc(testNmb++, mapSys2.begin()->first, mapUser2.begin()->first, "begin");
		testFunc(testNmb++, mapSys2.size(), mapUser2.size(), "Size is");
		testFunc(testNmb++, IterSys->first, IterUser->first, "end");

		getchar();
		system("clear");

		// /* insert 6 */
		// std::cout << std::endl << "\x1b[33m" << "insert 6 ((InputIterator first, InputIterator last);)" << "\x1b[0m" << std::endl;
		
		// mapSys.clear();
		// mapUser.clear();
		
		// mapSys2.clear();
		// mapUser2.clear();
	
		// mapSys2.insert ( std::pair <int, int> (-50, 5) );
		// mapSys2.insert ( std::pair <int, int> (15, 6) );
		// mapSys2.insert ( std::pair <int, int> (30, 7) );
		// mapSys2.insert ( std::pair <int, int> (100, 8) );

		// mapUser2.insert ( std::pair <int, int> (-50, 5) );
		// mapUser2.insert ( std::pair <int, int> (15, 6) );
		// mapUser2.insert ( std::pair <int, int> (30, 7) );
		// mapUser2.insert ( std::pair <int, int> (100, 8) );

		// IterInsertUser = mapUser.begin();
		// IterInsertSys = mapSys.begin();
		
		// std::cout << "******* BEFORE *******"<<std::endl;
		// print_std_map("     sysMap: ", mapSys2);
		// print_ft_map("    userMap: ", mapUser2);
		
		// // mapSys2.insert (++IterInsertSys,  IterInsertSys);
		// mapUser2.insert (++IterInsertUser, IterInsertUser);

		// std::cout << "******* AFTER *******"<<std::endl;
		// print_std_map("     sysMap: ", mapSys);
		// print_ft_map("    userMap: ", mapUser);
		// IterUser = mapUser.end();
		// IterUser--;
		// IterSys = mapSys.end();
		// IterSys--;
		// testFunc(testNmb++, mapSys.begin()->first, mapUser.begin()->first, "begin");
		// testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
		// testFunc(testNmb++, IterSys->first, IterUser->first, "end");

		// getchar();
		// system("clear");

		// /* insert 7 */
		// std::cout << std::endl << "\x1b[33m" << "insert 7 ((InputIterator first, InputIterator last);)" << "\x1b[0m" << std::endl;
		
		// mapSys.clear();
		// mapUser.clear();
		
		// mapSys2.clear();
		// mapUser2.clear();
	
		// mapSys2.insert ( std::pair <int, int> (-50, 5) );
		// mapSys2.insert ( std::pair <int, int> (15, 6) );
		// mapSys2.insert ( std::pair <int, int> (30, 7) );
		// mapSys2.insert ( std::pair <int, int> (100, 8) );

		// mapUser2.insert ( std::pair <int, int> (-50, 5) );
		// mapUser2.insert ( std::pair <int, int> (15, 6) );
		// mapUser2.insert ( std::pair <int, int> (30, 7) );
		// mapUser2.insert ( std::pair <int, int> (100, 8) );

		// IterInsertUser = mapUser.begin();
		// IterInsertSys = mapSys.begin();
		
		// std::cout << "******* BEFORE *******"<<std::endl;
		// print_std_map("     sysMap: ", mapSys2);
		// print_ft_map("    userMap: ", mapUser2);
		
		// mapSys2.insert (IterInsertSys,  IterInsertSys);
		// mapUser2.insert (IterInsertUser, IterInsertUser);

		// std::cout << "******* AFTER *******"<<std::endl;
		// print_std_map("     sysMap: ", mapSys2);
		// print_ft_map("    userMap: ", mapUser2);
		// IterUser = mapUser2.end();
		// IterUser--;
		// IterSys = mapSys2.end();
		// IterSys--;
		// testFunc(testNmb++, mapSys2.begin()->first, mapUser2.begin()->first, "begin");
		// testFunc(testNmb++, mapSys2.size(), mapUser2.size(), "Size is");
		// testFunc(testNmb++, IterSys->first, IterUser->first, "end");

		// getchar();
		// system("clear");

		// /* insert 8 */
		// std::cout << std::endl << "\x1b[33m" << "insert 8 ((InputIterator first, InputIterator last);)" << "\x1b[0m" << std::endl;
		
		// mapSys.clear();
		// mapUser.clear();
	
		// mapSys.insert ( std::pair <int, int> (-50, 5) );
		// mapSys.insert ( std::pair <int, int> (15, 6) );
		// mapSys.insert ( std::pair <int, int> (30, 7) );
		// mapSys.insert ( std::pair <int, int> (100, 8) );

		// mapUser.insert ( std::pair <int, int> (-50, 5) );
		// mapUser.insert ( std::pair <int, int> (15, 6) );
		// mapUser.insert ( std::pair <int, int> (30, 7) );
		// mapUser.insert ( std::pair <int, int> (100, 8) );

		// std::cout << "******* BEFORE *******"<<std::endl;
		// print_std_map("     sysMap: ", mapSys);
		// print_ft_map("    userMap: ", mapUser);

		// IterInsertUser = mapUser.end();
		// IterInsertSys = mapSys.end();

		// IterInsertSys--;
		// IterInsertUser--;
		
		// mapSys.insert (mapSys.begin(),  IterInsertSys);
		// mapUser.insert (mapUser.begin(), IterInsertUser);

		// std::cout << "******* AFTER *******"<<std::endl;
		// print_std_map("     sysMap: ", mapSys);
		// print_ft_map("    userMap: ", mapUser);

		// IterUser = mapUser.end();
		// IterSys = mapSys.end();
		
		// IterUser--;
		// IterSys--;

		// testFunc(testNmb++, mapSys2.begin()->first, mapUser2.begin()->first, "begin");
		// testFunc(testNmb++, mapSys2.size(), mapUser2.size(), "Size is");
		// testFunc(testNmb++, IterSys->first, IterUser->first, "end");

		// getchar();
		// system("clear");

		// /* insert 9 */
		// std::cout << std::endl << "\x1b[33m" << "insert 9 ((InputIterator first, InputIterator last);)" << "\x1b[0m" << std::endl;
		
		// mapSys.clear();
		// mapUser.clear();
	
		// mapSys.insert ( std::pair <int, int> (-50, 5) );
		// mapSys.insert ( std::pair <int, int> (15, 6) );
		// mapSys.insert ( std::pair <int, int> (30, 7) );
		// mapSys.insert ( std::pair <int, int> (100, 8) );

		// mapUser.insert ( std::pair <int, int> (-50, 5) );
		// mapUser.insert ( std::pair <int, int> (15, 6) );
		// mapUser.insert ( std::pair <int, int> (30, 7) );
		// mapUser.insert ( std::pair <int, int> (100, 8) );

		// std::cout << "******* BEFORE *******"<<std::endl;
		// print_std_map("     sysMap: ", mapSys);
		// print_ft_map("    userMap: ", mapUser);

		// IterInsertUser = mapUser.end();
		// IterInsertSys = mapSys.end();

		// IterInsertSys--;
		// IterInsertUser--;
		
		// mapSys.insert (IterInsertSys, mapSys.begin());
		// mapUser.insert (IterInsertUser, mapUser.begin());

		// std::cout << "******* AFTER *******"<<std::endl;
		// print_std_map("     sysMap: ", mapSys);
		// print_ft_map("    userMap: ", mapUser);

		// IterUser = mapUser.end();
		// IterSys = mapSys.end();
		
		// IterUser--;
		// IterSys--;

		// testFunc(testNmb++, mapSys2.begin()->first, mapUser2.begin()->first, "begin");
		// testFunc(testNmb++, mapSys2.size(), mapUser2.size(), "Size is");
		// testFunc(testNmb++, IterSys->first, IterUser->first, "end");

		// getchar();
		// system("clear");
		
	}

	//***************************ERASE************************//
	if(erase)
	{
		std::cout << std::endl << "\x1b[33m" << "erase 40 (delete start)" << "\x1b[0m" << std::endl;
		
		mapSys.clear();
		mapUser.clear();

		mapSys.insert ( std::pair <int, int> (55 , 0) );
		mapSys.insert ( std::pair <int, int> (40 , 0) );
		mapSys.insert ( std::pair <int, int> (65 , 0) );
		mapSys.insert ( std::pair <int, int> (60 , 0) );
		mapSys.insert ( std::pair <int, int> (75 , 0) );
		mapSys.insert ( std::pair <int, int> (57 , 0) );

		/* user part */

		mapUser.insert ( std::pair <int, int> (55 , 0) );
		mapUser.insert ( std::pair <int, int> (40 , 0) );
		mapUser.insert ( std::pair <int, int> (65 , 0) );
		mapUser.insert ( std::pair <int, int> (60 , 0) );
		mapUser.insert ( std::pair <int, int> (75 , 0) );
		mapUser.insert ( std::pair <int, int> (57 , 0) );
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);

		std::map <int, int> :: iterator itSysBegin = mapSys.begin();
		ft::map <int, int> :: iterator itUserBegin = mapUser.begin();
		
		mapSys.erase(itSysBegin);
		mapUser.erase(itUserBegin);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);

		std::map <int, int> :: iterator itSysEnd = mapSys.end();
		itSysEnd--;
		ft::map <int, int> :: iterator itUserEnd = mapUser.end();
		itUserEnd--;

		testFunc(testNmb++, mapSys.begin()->first, mapUser.begin()->first, "begin");
		testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
		testFunc(testNmb++, itSysEnd->first, itUserEnd->first, "end");
		
		getchar();
		system("clear");

		std::cout << std::endl << "\x1b[33m" << "erase 40 (delete finish)" << "\x1b[0m" << std::endl;
		
		mapSys.clear();
		mapUser.clear();

		mapSys.insert ( std::pair <int, int> (55 , 0) );
		mapSys.insert ( std::pair <int, int> (40 , 0) );
		mapSys.insert ( std::pair <int, int> (65 , 0) );
		mapSys.insert ( std::pair <int, int> (60 , 0) );
		mapSys.insert ( std::pair <int, int> (75 , 0) );
		mapSys.insert ( std::pair <int, int> (57 , 0) );

		/* user part */

		mapUser.insert ( std::pair <int, int> (55 , 0) );
		mapUser.insert ( std::pair <int, int> (40 , 0) );
		mapUser.insert ( std::pair <int, int> (65 , 0) );
		mapUser.insert ( std::pair <int, int> (60 , 0) );
		mapUser.insert ( std::pair <int, int> (75 , 0) );
		mapUser.insert ( std::pair <int, int> (57 , 0) );
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);
		
		mapSys.erase(75);
		mapUser.erase(75);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);

		itSysEnd = mapSys.end();
		itSysEnd--;
		itUserEnd = mapUser.end();
		itUserEnd--;

		testFunc(testNmb++, mapSys.begin()->first, mapUser.begin()->first, "begin");
		testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
		testFunc(testNmb++, itSysEnd->first, itUserEnd->first, "end");
		
		getchar();
		system("clear");

		std::cout << std::endl << "\x1b[33m" << "erase 41" << "\x1b[0m" << std::endl;
		
		mapSys.clear();
		mapUser.clear();

		mapSys.insert ( std::pair <int, int> (55 , 0) );
		mapSys.insert ( std::pair <int, int> (40 , 0) );
		mapSys.insert ( std::pair <int, int> (65 , 0) );
		mapSys.insert ( std::pair <int, int> (60 , 0) );
		mapSys.insert ( std::pair <int, int> (75 , 0) );
		mapSys.insert ( std::pair <int, int> (57 , 0) );
		mapSys.insert ( std::pair <int, int> (41 , 0) );

		/* user part */

		mapUser.insert ( std::pair <int, int> (55 , 0) );
		mapUser.insert ( std::pair <int, int> (40 , 0) );
		mapUser.insert ( std::pair <int, int> (65 , 0) );
		mapUser.insert ( std::pair <int, int> (60 , 0) );
		mapUser.insert ( std::pair <int, int> (75 , 0) );
		mapUser.insert ( std::pair <int, int> (57 , 0) );
		mapUser.insert ( std::pair <int, int> (41 , 0) );
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);

		itSysBegin = mapSys.begin();
		itUserBegin = mapUser.begin();

		itSysBegin++;
		itUserBegin++;
		
		mapSys.erase(itSysBegin);
		mapUser.erase(itUserBegin);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);

		itSysEnd = mapSys.end();
		itSysEnd--;
		itUserEnd = mapUser.end();
		itUserEnd--;

		testFunc(testNmb++, mapSys.begin()->first, mapUser.begin()->first, "begin");
		testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
		testFunc(testNmb++, itSysEnd->first, itUserEnd->first, "end");
		
		getchar();
		system("clear");

		// std::cout << std::endl << "\x1b[33m" << "erase 40" << "\x1b[0m" << std::endl;
		
		// mapSys.clear();
		// mapUser.clear();

		// mapSys.insert ( std::pair <int, int> (55 , 0) );
		// mapSys.insert ( std::pair <int, int> (40 , 0) );
		// mapSys.insert ( std::pair <int, int> (65 , 0) );
		// mapSys.insert ( std::pair <int, int> (60 , 0) );
		// mapSys.insert ( std::pair <int, int> (75 , 0) );
		// mapSys.insert ( std::pair <int, int> (57 , 0) );
		// mapSys.insert ( std::pair <int, int> (45 , 0) );

		// /* user part */

		// mapUser.insert ( std::pair <int, int> (55 , 0) );
		// mapUser.insert ( std::pair <int, int> (40 , 0) );
		// mapUser.insert ( std::pair <int, int> (65 , 0) );
		// mapUser.insert ( std::pair <int, int> (60 , 0) );
		// mapUser.insert ( std::pair <int, int> (75 , 0) );
		// mapUser.insert ( std::pair <int, int> (57 , 0) );
		// mapUser.insert ( std::pair <int, int> (45 , 0) );
		
		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_map("     sysMap: ", mapSys);
		// print_ft_map("    userMap: ", mapUser);
		
		// mapSys.erase(40);
		// mapUser.erase(40);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_map("     sysMap: ", mapSys);
		// print_ft_map("    userMap: ", mapUser);

		// itSysEnd = mapSys.end();
		// itSysEnd--;
		// itUserEnd = mapUser.end();
		// itUserEnd--;

		// testFunc(testNmb++, mapSys.begin()->first, mapUser.begin()->first, "begin");
		// testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
		// testFunc(testNmb++, itSysEnd->first, itUserEnd->first, "end");
		// getchar();
		// system("clear");

		// std::cout << std::endl << "\x1b[33m" << "erase 100 (size_type erase (const key_type& k);)" << "\x1b[0m" << std::endl;
		
		// mapSys.clear();
		// mapUser.clear();

		// mapSys.insert ( std::pair <int, int> (55 , 0) );
		// mapSys.insert ( std::pair <int, int> (40 , 0) );
		// mapSys.insert ( std::pair <int, int> (65 , 0) );
		// mapSys.insert ( std::pair <int, int> (60 , 0) );
		// mapSys.insert ( std::pair <int, int> (75 , 0) );
		// mapSys.insert ( std::pair <int, int> (57 , 0) );

		// /* user part */

		// mapUser.insert ( std::pair <int, int> (55 , 0) );
		// mapUser.insert ( std::pair <int, int> (40 , 0) );
		// mapUser.insert ( std::pair <int, int> (65 , 0) );
		// mapUser.insert ( std::pair <int, int> (60 , 0) );
		// mapUser.insert ( std::pair <int, int> (75 , 0) );
		// mapUser.insert ( std::pair <int, int> (57 , 0) );
		
		// // std::cout << "*** BEFORE ***" << std::endl;
		// // print_std_map("     sysMap: ", mapSys);
		// // print_ft_map("    userMap: ", mapUser);
		
		// testFunc(testNmb++, mapSys.erase(100), mapUser.erase(100), "return value");

		// // std::cout << "*** AFTER ***" << std::endl;
		// // print_std_map("     sysMap: ", mapSys);
		// // print_ft_map("    userMap: ", mapUser);
		// itSysEnd = mapSys.end();
		// itSysEnd--;
		// itUserEnd = mapUser.end();
		// itUserEnd--;

		// testFunc(testNmb++, mapSys.begin()->first, mapUser.begin()->first, "begin");
		// testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
		// testFunc(testNmb++, itSysEnd->first, itUserEnd->first, "end");
		// getchar();
		// system("clear");

		// std::cout << std::endl << "\x1b[33m" << "erase 40 (size_type erase (const key_type& k);)" << "\x1b[0m" << std::endl;
		
		// mapSys.clear();
		// mapUser.clear();

		// mapSys.insert ( std::pair <int, int> (55 , 0) );
		// mapSys.insert ( std::pair <int, int> (40 , 0) );
		// mapSys.insert ( std::pair <int, int> (65 , 0) );
		// mapSys.insert ( std::pair <int, int> (60 , 0) );
		// mapSys.insert ( std::pair <int, int> (75 , 0) );
		// mapSys.insert ( std::pair <int, int> (57 , 0) );

		// /* user part */

		// mapUser.insert ( std::pair <int, int> (55 , 0) );
		// mapUser.insert ( std::pair <int, int> (40 , 0) );
		// mapUser.insert ( std::pair <int, int> (65 , 0) );
		// mapUser.insert ( std::pair <int, int> (60 , 0) );
		// mapUser.insert ( std::pair <int, int> (75 , 0) );
		// mapUser.insert ( std::pair <int, int> (57 , 0) );
		
		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_map("     sysMap: ", mapSys);
		// print_ft_map("    userMap: ", mapUser);
		
		// testFunc(testNmb++, mapSys.erase(40), mapUser.erase(40), "return value");

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_map("     sysMap: ", mapSys);
		// print_ft_map("    userMap: ", mapUser);

		// itSysEnd = mapSys.end();
		// itSysEnd--;
		// itUserEnd = mapUser.end();
		// itUserEnd--;

		// testFunc(testNmb++, mapSys.begin()->first, mapUser.begin()->first, "begin");
		// testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
		// testFunc(testNmb++, itSysEnd->first, itUserEnd->first, "end");
				
		// getchar();
		// system("clear");

		// std::cout << std::endl << "\x1b[33m" << "erase incorrect number (size_type erase (const key_type& k);)" << "\x1b[0m" << std::endl;
		
		// mapSys.clear();
		// mapUser.clear();

		// mapSys.insert ( std::pair <int, int> (55 , 0) );
		// mapSys.insert ( std::pair <int, int> (40 , 0) );
		// mapSys.insert ( std::pair <int, int> (65 , 0) );
		// mapSys.insert ( std::pair <int, int> (60 , 0) );
		// mapSys.insert ( std::pair <int, int> (75 , 0) );
		// mapSys.insert ( std::pair <int, int> (57 , 0) );

		// /* user part */

		// mapUser.insert ( std::pair <int, int> (55 , 0) );
		// mapUser.insert ( std::pair <int, int> (40 , 0) );
		// mapUser.insert ( std::pair <int, int> (65 , 0) );
		// mapUser.insert ( std::pair <int, int> (60 , 0) );
		// mapUser.insert ( std::pair <int, int> (75 , 0) );
		// mapUser.insert ( std::pair <int, int> (57 , 0) );
		
		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_map("     sysMap: ", mapSys);
		// print_ft_map("    userMap: ", mapUser);
		
		// testFunc(testNmb++, mapSys.erase(200), mapUser.erase(200), "return value");

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_map("     sysMap: ", mapSys);
		// print_ft_map("    userMap: ", mapUser);

		// itSysEnd = mapSys.end();
		// itSysEnd--;
		// itUserEnd = mapUser.end();
		// itUserEnd--;

		// testFunc(testNmb++, mapSys.begin()->first, mapUser.begin()->first, "begin");
		// testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
		// testFunc(testNmb++, itSysEnd->first, itUserEnd->first, "end");
				
		// getchar();
		// system("clear");



		// std::cout << std::endl << "\x1b[33m" << "erase 65" << "\x1b[0m" << std::endl;
		
		// mapSys.clear();
		// mapUser.clear();

		// mapSys.insert ( std::pair <int, int> (55 , 0) );
		// mapSys.insert ( std::pair <int, int> (40 , 0) );
		// mapSys.insert ( std::pair <int, int> (65 , 0) );
		// mapSys.insert ( std::pair <int, int> (60 , 0) );
		// mapSys.insert ( std::pair <int, int> (75 , 0) );
		// mapSys.insert ( std::pair <int, int> (57 , 0) );

		// /* user part */

		// mapUser.insert ( std::pair <int, int> (55 , 0) );
		// mapUser.insert ( std::pair <int, int> (40 , 0) );
		// mapUser.insert ( std::pair <int, int> (65 , 0) );
		// mapUser.insert ( std::pair <int, int> (60 , 0) );
		// mapUser.insert ( std::pair <int, int> (75 , 0) );
		// mapUser.insert ( std::pair <int, int> (57 , 0) );
		
		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_map("     sysMap: ", mapSys);
		// print_ft_map("    userMap: ", mapUser);
		
		// mapSys.erase(65);
		// mapUser.erase(65);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_map("     sysMap: ", mapSys);
		// print_ft_map("    userMap: ", mapUser);

		// itSysEnd = mapSys.end();
		// itSysEnd--;
		// itUserEnd = mapUser.end();
		// itUserEnd--;

		// testFunc(testNmb++, mapSys.begin()->first, mapUser.begin()->first, "begin");
		// testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
		// testFunc(testNmb++, itSysEnd->first, itUserEnd->first, "end");
		
		// getchar();
		// system("clear");
		
		// std::cout << std::endl << "\x1b[33m" << "erase all (void erase (iterator first, iterator last))" << "\x1b[0m" << std::endl;
		
		// mapSys.clear();
		// mapUser.clear();

		// mapSys.insert ( std::pair <int, int> (55 , 0) );
		// mapSys.insert ( std::pair <int, int> (40 , 0) );
		// mapSys.insert ( std::pair <int, int> (65 , 0) );
		// mapSys.insert ( std::pair <int, int> (60 , 0) );
		// mapSys.insert ( std::pair <int, int> (75 , 0) );
		// mapSys.insert ( std::pair <int, int> (57 , 0) );

		// /* user part */

		// mapUser.insert ( std::pair <int, int> (55 , 0) );
		// mapUser.insert ( std::pair <int, int> (40 , 0) );
		// mapUser.insert ( std::pair <int, int> (65 , 0) );
		// mapUser.insert ( std::pair <int, int> (60 , 0) );
		// mapUser.insert ( std::pair <int, int> (75 , 0) );
		// mapUser.insert ( std::pair <int, int> (57 , 0) );
		
		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_map("     sysMap: ", mapSys);
		// print_ft_map("    userMap: ", mapUser);

		// ft::map<int, int>::iterator mapUserErase = mapUser.begin();
		// std::map<int, int>::iterator mapSysErase = mapSys.begin();
		
		// ft::map<int, int>::iterator mapUserEraseEnd = mapUser.end();
		// std::map<int, int>::iterator mapSysEraseEnd = mapSys.end();

		//  mapSys.erase(mapSysErase, mapSysEraseEnd);
		//  mapUser.erase(mapUserErase, mapUserEraseEnd);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_map("     sysMap: ", mapSys);
		// print_ft_map("    userMap: ", mapUser);

		// testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
		
		// getchar();
		// system("clear");
		
		// std::cout << std::endl << "\x1b[33m" << "erase 40 (void erase (iterator first, iterator last))" << "\x1b[0m" << std::endl;
		
		// 		mapSys.clear();
		// mapUser.clear();

		// mapSys.insert ( std::pair <int, int> (55 , 0) );
		// mapSys.insert ( std::pair <int, int> (40 , 0) );
		// mapSys.insert ( std::pair <int, int> (65 , 0) );
		// mapSys.insert ( std::pair <int, int> (60 , 0) );
		// mapSys.insert ( std::pair <int, int> (75 , 0) );
		// mapSys.insert ( std::pair <int, int> (57 , 0) );

		// /* user part */

		// mapUser.insert ( std::pair <int, int> (55 , 0) );
		// mapUser.insert ( std::pair <int, int> (40 , 0) );
		// mapUser.insert ( std::pair <int, int> (65 , 0) );
		// mapUser.insert ( std::pair <int, int> (60 , 0) );
		// mapUser.insert ( std::pair <int, int> (75 , 0) );
		// mapUser.insert ( std::pair <int, int> (57 , 0) );
		
		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_map("     sysMap: ", mapSys);
		// print_ft_map("    userMap: ", mapUser);

		// mapUserErase = mapUser.begin();
		
		// mapSysErase = mapSys.begin();
		
		// mapUserEraseEnd = mapUser.begin();
		// mapUserEraseEnd++;
		// mapSysEraseEnd = mapSys.begin();
		// mapSysEraseEnd++;

		//  mapSys.erase(mapSysErase, mapSysEraseEnd);
		//  mapUser.erase(mapUserErase, mapUserEraseEnd);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_map("     sysMap: ", mapSys);
		// print_ft_map("    userMap: ", mapUser);

		// itSysEnd = mapSys.end();
		// itSysEnd--;
		// itUserEnd = mapUser.end();
		// itUserEnd--;

		// testFunc(testNmb++, mapSys.begin()->first, mapUser.begin()->first, "begin");
		// testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
		// testFunc(testNmb++, itSysEnd->first, itUserEnd->first, "end");
		
		// getchar();
		// system("clear");

		// std::cout << std::endl << "\x1b[33m" << "erase 75 (void erase (iterator first, iterator last))" << "\x1b[0m" << std::endl;
		
		// 		mapSys.clear();
		// mapUser.clear();

		// mapSys.insert ( std::pair <int, int> (55 , 0) );
		// mapSys.insert ( std::pair <int, int> (40 , 0) );
		// mapSys.insert ( std::pair <int, int> (65 , 0) );
		// mapSys.insert ( std::pair <int, int> (60 , 0) );
		// mapSys.insert ( std::pair <int, int> (75 , 0) );
		// mapSys.insert ( std::pair <int, int> (57 , 0) );

		// /* user part */

		// mapUser.insert ( std::pair <int, int> (55 , 0) );
		// mapUser.insert ( std::pair <int, int> (40 , 0) );
		// mapUser.insert ( std::pair <int, int> (65 , 0) );
		// mapUser.insert ( std::pair <int, int> (60 , 0) );
		// mapUser.insert ( std::pair <int, int> (75 , 0) );
		// mapUser.insert ( std::pair <int, int> (57 , 0) );
		
		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_map("     sysMap: ", mapSys);
		// print_ft_map("    userMap: ", mapUser);

		// mapUserErase = mapUser.end();
		
		// mapSysErase = mapSys.end();
		
		// mapUserEraseEnd = mapUser.end();
		// mapUserErase--;
		// mapSysEraseEnd = mapSys.end();
		// mapSysErase--;

		//  mapSys.erase(mapSysErase, mapSysEraseEnd);
		//  mapUser.erase(mapUserErase, mapUserEraseEnd);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_map("     sysMap: ", mapSys);
		// print_ft_map("    userMap: ", mapUser);

		// itSysEnd = mapSys.end();
		// itSysEnd--;
		// itUserEnd = mapUser.end();
		// itUserEnd--;

		// testFunc(testNmb++, mapSys.begin()->first, mapUser.begin()->first, "begin");
		// testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
		// testFunc(testNmb++, itSysEnd->first, itUserEnd->first, "end");
		
		// getchar();
		// system("clear");

		// std::cout << std::endl << "\x1b[33m" << "erase NULL (void erase (iterator first, iterator last))" << "\x1b[0m" << std::endl;
		
		// mapSys.clear();
		// mapUser.clear();

		// mapSys.insert ( std::pair <int, int> (55 , 0) );
		// mapSys.insert ( std::pair <int, int> (40 , 0) );
		// mapSys.insert ( std::pair <int, int> (65 , 0) );
		// mapSys.insert ( std::pair <int, int> (60 , 0) );
		// mapSys.insert ( std::pair <int, int> (75 , 0) );
		// mapSys.insert ( std::pair <int, int> (57 , 0) );

		// /* user part */

		// mapUser.insert ( std::pair <int, int> (55 , 0) );
		// mapUser.insert ( std::pair <int, int> (40 , 0) );
		// mapUser.insert ( std::pair <int, int> (65 , 0) );
		// mapUser.insert ( std::pair <int, int> (60 , 0) );
		// mapUser.insert ( std::pair <int, int> (75 , 0) );
		// mapUser.insert ( std::pair <int, int> (57 , 0) );
		
		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_map("     sysMap: ", mapSys);
		// print_ft_map("    userMap: ", mapUser);

		// ft::map<int, int>::iterator mapUserEraseNull;
		// std::map<int, int>::iterator mapSysEraseNull;

		//  mapSys.erase(mapSysEraseNull, mapSysEraseNull);
		//  mapUser.erase(mapUserEraseNull, mapUserEraseNull);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_map("     sysMap: ", mapSys);
		// print_ft_map("    userMap: ", mapUser);

		// itSysEnd = mapSys.end();
		// itSysEnd--;
		// itUserEnd = mapUser.end();
		// itUserEnd--;

		// testFunc(testNmb++, mapSys.begin()->first, mapUser.begin()->first, "begin");
		// testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
		// testFunc(testNmb++, itSysEnd->first, itUserEnd->first, "end");
		
		// getchar();
		// system("clear");
		
	}
	
	//***************************SWAP************************//
	if(swap)
	{
		std::cout << std::endl << "\x1b[33m" << "swap" << "\x1b[0m" << std::endl;

		mapSys.clear();
		mapUser.clear();

		mapSys.insert(std::pair<int, int>(20, 0));
		mapSys.insert(std::pair<int, int>(10, 0));
		mapSys.insert(std::pair<int, int>(30, 0));
		mapSys.insert(std::pair<int, int>(15, 0));

		mapUser.insert(std::pair<int, int>(20, 0));
		mapUser.insert(std::pair<int, int>(10, 0));
		mapUser.insert(std::pair<int, int>(30, 0));
		mapUser.insert(std::pair<int, int>(15, 0));

		mapSys2.clear();
		mapUser2.clear();

		mapSys2.insert(std::pair<int, int>(120, 0));
		mapSys2.insert(std::pair<int, int>(110, 0));
		mapSys2.insert(std::pair<int, int>(130, 0));
		mapSys2.insert(std::pair<int, int>(115, 0));
		mapSys2.insert(std::pair<int, int>(125, 0));

		mapUser2.insert(std::pair<int, int>(120, 0));
		mapUser2.insert(std::pair<int, int>(110, 0));
		mapUser2.insert(std::pair<int, int>(130, 0));
		mapUser2.insert(std::pair<int, int>(115, 0));
		mapUser2.insert(std::pair<int, int>(125, 0));

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);

		print_std_map("    sysMap2: ", mapSys2);
		print_ft_map("   userMap2: ", mapUser2);

		mapSys.swap(mapSys2);
		mapUser.swap(mapUser2);
		
		std::cout << "*** AFTER ***" << std::endl;
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);

		print_std_map("    sysMap2: ", mapSys2);
		print_ft_map("   userMap2: ", mapUser2);

		testFunc(testNmb++, mapSys.begin()->first,  mapUser.begin()->first, "Begin");
		testFunc(testNmb++, mapSys.size(), 			mapUser.size(), "Size is");

		testFunc(testNmb++, mapSys2.begin()->first, mapUser2.begin()->first, "Begin (2)");
		testFunc(testNmb++, mapSys2.size(), 		mapUser2.size(), "Size (2) is");

		getchar();
		
		/* swap 2 */
		std::cout << std::endl << "\x1b[33m" << "swap 2" << "\x1b[0m" << std::endl;

		mapSys.clear();
		mapUser.clear();

		mapSys.insert(std::pair<int, int>(20, 0));
		mapSys.insert(std::pair<int, int>(10, 0));
		mapSys.insert(std::pair<int, int>(30, 0));

		mapUser.insert(std::pair<int, int>(20, 0));
		mapUser.insert(std::pair<int, int>(10, 0));
		mapUser.insert(std::pair<int, int>(30, 0));

		mapSys2.clear();
		mapUser2.clear();

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);

		print_std_map("    sysMap2: ", mapSys2);
		print_ft_map("   userMap2: ", mapUser2);

		mapSys.swap(mapSys2);
		mapUser.swap(mapUser2);
		
		std::cout << "*** AFTER ***" << std::endl;
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);

		print_std_map("    sysMap2: ", mapSys2);
		print_ft_map("   userMap2: ", mapUser2);
		
		testFunc(testNmb++, mapSys.size(), 			mapUser.size(), "Size is");

		testFunc(testNmb++, mapSys2.begin()->first, mapUser2.begin()->first, "Begin (2)");
		testFunc(testNmb++, mapSys2.size(), 		mapUser2.size(), "Size (2) is");
	}
	
	//***************************CLEAR************************//
	if(clear)
	{
		/* clear 1 */
		std::cout << std::endl << "\x1b[33m" << "clear 1 (print empty map)" << "\x1b[0m" << std::endl;
		
		std::map <int, int> mapSys1;
		ft::map <int, int> mapUser1;
		
		print_std_map("     sysMap: ", mapSys1);
		print_ft_map("    userMap: ", mapUser1);
		
		/* clear 2 */
		std::cout << std::endl << "\x1b[33m" << "clear" << "\x1b[0m" << std::endl;

		mapSys.insert ( std::pair <int, int> (20, 42) );
		mapSys.insert ( std::pair <int, int> (20, 42) );
		mapSys.insert ( std::pair <int, int> (10, 10) );
		mapSys.insert ( std::pair <int, int> (42, 0) );
		
		mapSys.insert ( std::pair <int, int> (-50, 0) );
		mapSys.insert ( std::pair <int, int> (15, 0) );
		mapSys.insert ( std::pair <int, int> (30, 0) );
		mapSys.insert ( std::pair <int, int> (100, 0) );

		mapSys.insert ( std::pair <int, int> (-99, 0) );
		mapSys.insert ( std::pair <int, int> (1, 0) );

		mapSys.insert ( std::pair <int, int> (14, 0) );
		mapSys.insert ( std::pair <int, int> (16, 0) );
		
		mapSys.insert ( std::pair <int, int> (29, 0) );
		mapSys.insert ( std::pair <int, int> (40, 0) );
		
		mapSys.insert ( std::pair <int, int> (45, 0) );
		mapSys.insert ( std::pair <int, int> (105, 0) );

		/* user part */

		mapUser.insert ( std::pair <int, int> (20, 0) );
		mapUser.insert ( std::pair <int, int> (20, 0) );
		mapUser.insert ( std::pair <int, int> (10, 0) );
		mapUser.insert ( std::pair <int, int> (42, 0) );
		
		mapUser.insert ( std::pair <int, int> (-50, 0) );
		mapUser.insert ( std::pair <int, int> (15, 0) );
		mapUser.insert ( std::pair <int, int> (30, 0) );
		mapUser.insert ( std::pair <int, int> (100, 0) );

		mapUser.insert ( std::pair <int, int> (-99, 0) );
		mapUser.insert ( std::pair <int, int> (1, 0) );

		mapUser.insert ( std::pair <int, int> (14, 0) );
		mapUser.insert ( std::pair <int, int> (16, 0) );
		
		mapUser.insert ( std::pair <int, int> (29, 0) );
		mapUser.insert ( std::pair <int, int> (40, 0) );
		
		mapUser.insert ( std::pair <int, int> (45, 0) );
		mapUser.insert ( std::pair <int, int> (105, 0) );
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);
		
		testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
		
		mapSys.clear();
		mapUser.clear();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);
		
		testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");
		
	}

}

void				observers_map(int testNmb, int testAll)
{
	int key_comp = 0;
	int value_comp = 0;
	
	if (testAll)
	{
		key_comp = 1;
		value_comp = 1; 
	}
	
	std::map <char, int> mapSys;
	ft::map  <char, int> mapUser;

	std::map <char, int>:: iterator IterSys;
	ft::map  <char, int>:: iterator IterUser;

	std::map <char, int> :: key_compare compSys  = mapSys.key_comp();
	ft::map  <char, int> :: key_compare compUser = mapUser.key_comp();

	if (key_comp)
	{
		/* key_comp */
		std::cout << std::endl << "\x1b[33m" << "key_comp" << "\x1b[0m" << std::endl;
		
		mapSys['a'] = 10;
		mapSys['g'] = 11;
		mapSys['c'] = 8;
		mapSys['h'] = 8;
		mapSys['e'] = 13;
		mapSys['f'] = 0;
		mapSys['z'] = 1;
		mapSys['a'] = 5;
		mapSys['b'] = 5;
		mapSys['h'] = 5;

		mapUser['a'] = 10;
		mapUser['g'] = 11;
		mapUser['c'] = 8;
		mapUser['h'] = 8;
		mapUser['e'] = 13;
		mapUser['f'] = 0;
		mapUser['z'] = 1;
		mapUser['a'] = 5;
		mapUser['b'] = 5;
		mapUser['h'] = 5;
		
		IterSys = mapSys.end();
		IterUser = mapUser.end();
		
		IterSys--;
		IterUser--;

		char highestSys = IterSys->first;
		char highestUser = IterUser->first;

		IterSys = mapSys.begin();
		IterUser = mapUser.begin();

		while (compSys((*IterSys).first, highestSys) || compUser((*IterUser).first, highestUser))
		{
			testFunc(testNmb++, IterSys->first, IterUser->first, "First");
			testFunc(testNmb++, IterSys->second, IterUser->second, "Second");
			IterSys++;
			IterUser++;
		}

		getchar();		
	}
	
	if (value_comp)
	{
		/* value_comp */
		std::cout << std::endl << "\x1b[33m" << "value_comp" << "\x1b[0m" << std::endl;
		
		mapSys.clear();
		mapUser.clear();
		
		mapSys['x'] = 1001;
		mapSys['z'] = 4001;
		mapSys['y'] = 2002;
		mapSys['z'] = 3003;

		mapUser['x'] = 1001;
		mapUser['z'] = 4001;
		mapUser['y'] = 2002;
		mapUser['z'] = 3003;

		IterSys = mapSys.end();
		IterUser = mapUser.end();
		
		IterSys--;
		IterUser--;

		std::pair<char,int> highestSys  = *IterSys;          // last element
		std::pair<char,int> highestUser = *IterUser;

		IterSys = mapSys.begin();
		IterUser = mapUser.begin();

		while (mapSys.value_comp()(*IterSys, highestSys) || mapUser.value_comp()(*IterUser, highestUser))
		{
			testFunc(testNmb++, IterSys->first, IterUser->first, "First");
			testFunc(testNmb++, IterSys->second, IterUser->second, "Second");
			IterSys++;
			IterUser++;
		}
		testFunc(testNmb++, IterSys->first, IterUser->first, "First");
		testFunc(testNmb++, IterSys->second, IterUser->second, "Second");
	}
}

// void operations_map(int testNmb, int testAll)
// {
// 	std::cout << std::endl << "\x1b[33m" << "                              *** OPERATIONS MAP ***                          " << "\x1b[0m" << std::endl;

// 	int			find= 1;
// 	int			count = 0;
// 	int			lower_bound = 1;
// 	int			upper_bound = 0; 
// 	int			equal_range = 0;

// 	if (testAll)
// 	{
// 		find= 0;
// 		count = 0;
// 		lower_bound = 0;
// 		upper_bound = 0; 
// 		equal_range = 0;
// 	}
// 	if(find)
// 	{
// 		std::cout << std::endl << "\x1b[33m" << "find" << "\x1b[0m" << std::endl;

// 		std::map <int, int> mapSys;
// 		ft::map <int, int> mapUser;
// 		mapSys.insert ( std::pair <int, int> (42, 0) );
// 		mapUser.insert ( std::pair <int, int> (42, 0) );
// 		mapSys.insert ( std::pair <int, int> (21, 0) );
// 		mapUser.insert ( std::pair <int, int> (21, 0) );
// 		mapSys.insert ( std::pair <int, int> (30, 5) );
// 		mapUser.insert ( std::pair <int, int> (30, 5) );
// 		mapSys.insert ( std::pair <int, int> (12, 45) );
// 		mapUser.insert ( std::pair <int, int> (12, 45) );
		

// 		ft::map<int, int> ::iterator iterFindUser = mapUser.find(30);
// 		std::map<int, int> ::iterator iterFindSys = mapSys.find(30);

// 		testFunc(testNmb++, iterFindSys->second, iterFindUser->first, "second value");
// 		testFunc(testNmb++, iterFindSys->first, iterFindUser->first, "first value");
		
// 	}

// 	if(count)
// 	{
		
// 	}

// 	if(lower_bound)
// 	{
		
// 	}
	
// 	if(upper_bound)
// 	{
		
// 	}
	
// 	if(equal_range)
// 	{
		
// 	}
// }

// void allocator_map(int testNmb, int testAll)
// {
	
// }

void map_test()
{
	int testNmb = 0;
	int testAll = 0;

	system("clear");

	std::cout << "\x1b[32m" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "|           MAP TESTING          |" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl << std::endl;
	std::cout << "\x1b[0m";

	/*			Member functions			*/
	// constructor_map(testNmb, testAll);								// 
	// iterators_map(testNmb, testAll);						// 
	// capacity_map(testNmb, testAll);							// +
	// element_access_map(testNmb, testAll);					// +
	modifiers_map(testNmb, testAll);						// 
	// observers_map(testNmb, testAll);						// +
	// operations_map(testNmb, testAll);					// 
	// allocator_map(testNmb, testAll);
}
