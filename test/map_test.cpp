/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:48:16 by gbroccol          #+#    #+#             */
/*   Updated: 2021/04/01 17:06:05 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers_test.hpp"

void				constructor_map(int testNmb)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** CONSTRUCTOR ***                          " << "\x1b[0m" << std::endl;

	std::map <int, int> mapSys;
	ft::map <int, int> mapUser;
	
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

	/* constructor InputIterator */
	std::cout << std::endl << "\x1b[33m" << "constructor InputIterator" << "\x1b[0m" << std::endl;

	/* copy constructor */
	std::cout << std::endl << "\x1b[33m" << "copy constructor" << "\x1b[0m" << std::endl;

	// mapSys['a'] = 10;
	// mapSys['b'] = 30;
	// mapSys['c'] = 50;
	// mapSys['d'] = 70;

	// std::map<char,int> second (mapSys.begin(),mapSys.end());

	// std::map<char,int> third (second);

	// std::map<char,int,classcomp> fourth;                 // class as Compare

	// bool(*fn_pt)(char,char) = fncomp;
	// std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
	
	
}

// void				iterators_map(int testNmb, int testAll)
// {
// 	std::cout << std::endl << "\x1b[33m" << "                              *** ITERATORS ***                          " << "\x1b[0m" << std::endl;
	
// 	int			begin = 0;
// 	int			end = 0;
// 	int			rbegin = 0;
// 	int			rend = 0;

// 	if (testAll)
// 	{
// 		begin = 1;
// 		end = 1;
// 		rbegin = 1;
// 		rend = 1;
// 	}

	
// 	/* *************************** BEGIN AND END ************************/
// 	if(begin && end)
// 	{
// 		std::cout << std::endl << "\x1b[33m" << "begin and end" << "\x1b[0m" << std::endl;

		
// 	}

// 	/* ************************** REVERSE BEGIN AND END *********************** */
// 	if(rbegin && rend)
// 	{
// 		std::cout << std::endl << "\x1b[33m" << "reverse begin and end" << "\x1b[0m" << std::endl;

		
// 	}
// 	getchar();
// }

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

		testFunc(testNmb++, mapSys.max_size(), mapUser.size(), "Size is");

		getchar();
	}

	//*************************** EMPTY ************************//
	if(empty)
	{
		std::cout << std::endl << "\x1b[33m" << "empty" << "\x1b[0m" << std::endl;
	
		getchar();
	}
}

void				elementAccess_map(int testNmb, int testAll)
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
}

void				modifiers_map(int testNmb, int testAll)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** MODIFIERS ***                          " << "\x1b[0m" << std::endl;

	int			insert = 0;
	int			erase = 1; 
	int			swap = 0;
	int			clear = 0;

	if (testAll)
	{
		insert = 1;
		erase = 1; 
		swap = 1;
		clear = 1;
	}

	std::map <int, int> mapSys;
	ft::map <int, int> mapUser;

	//***************************INSERT************************//
	if(insert)
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

		/* insert 2 */
		std::cout << std::endl << "\x1b[33m" << "insert 2 (print it inverted tree)" << "\x1b[0m" << std::endl;

		print_std_map_inv("     sysMap: ", mapSys);
		print_ft_map_inv("    userMap: ", mapUser);

		testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");

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

	}

	//***************************ERASE************************//
	if(erase)
	{
		std::cout << std::endl << "\x1b[33m" << "erase (delete start)" << "\x1b[0m" << std::endl;
		
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

		std::cout << std::endl << "\x1b[33m" << "erase (delete finish)" << "\x1b[0m" << std::endl;
		
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

		std::cout << std::endl << "\x1b[33m" << "erase 40" << "\x1b[0m" << std::endl;
		
		mapSys.clear();
		mapUser.clear();

		mapSys.insert ( std::pair <int, int> (55 , 0) );
		mapSys.insert ( std::pair <int, int> (40 , 0) );
		mapSys.insert ( std::pair <int, int> (65 , 0) );
		mapSys.insert ( std::pair <int, int> (60 , 0) );
		mapSys.insert ( std::pair <int, int> (75 , 0) );
		mapSys.insert ( std::pair <int, int> (57 , 0) );
		mapSys.insert ( std::pair <int, int> (45 , 0) );

		/* user part */

		mapUser.insert ( std::pair <int, int> (55 , 0) );
		mapUser.insert ( std::pair <int, int> (40 , 0) );
		mapUser.insert ( std::pair <int, int> (65 , 0) );
		mapUser.insert ( std::pair <int, int> (60 , 0) );
		mapUser.insert ( std::pair <int, int> (75 , 0) );
		mapUser.insert ( std::pair <int, int> (57 , 0) );
		mapUser.insert ( std::pair <int, int> (45 , 0) );
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);
		
		mapSys.erase(40);
		mapUser.erase(40);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);

		std::cout << std::endl << "\x1b[33m" << "erase 100 (size_type erase (const key_type& k);)" << "\x1b[0m" << std::endl;
		
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
		
		testFunc(testNmb++, mapSys.erase(100), mapUser.erase(100), "Size is");

		std::cout << "*** AFTER ***" << std::endl;
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);

		std::cout << std::endl << "\x1b[33m" << "erase 40 (size_type erase (const key_type& k);)" << "\x1b[0m" << std::endl;
		
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
		
		testFunc(testNmb++, mapSys.erase(40), mapUser.erase(40), "Return value");
		testFunc(testNmb++, mapSys.erase(100), mapUser.erase(100), "Return value");

		std::cout << "*** AFTER ***" << std::endl;
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);

		std::cout << std::endl << "\x1b[33m" << "erase 65" << "\x1b[0m" << std::endl;
		
		mapSys.clear();
		mapUser.clear();

		mapSys.insert ( std::pair <int, int> (55 , 0) );
		mapSys.insert ( std::pair <int, int> (40 , 0) );
		mapSys.insert ( std::pair <int, int> (65 , 0) );
		mapSys.insert ( std::pair <int, int> (60 , 0) );
		mapSys.insert ( std::pair <int, int> (75 , 0) );
		mapSys.insert ( std::pair <int, int> (57 , 0) );
		mapSys.insert ( std::pair <int, int> (80 , 0) );

		/* user part */

		mapUser.insert ( std::pair <int, int> (55 , 0) );
		mapUser.insert ( std::pair <int, int> (40 , 0) );
		mapUser.insert ( std::pair <int, int> (65 , 0) );
		mapUser.insert ( std::pair <int, int> (60 , 0) );
		mapUser.insert ( std::pair <int, int> (75 , 0) );
		mapUser.insert ( std::pair <int, int> (57 , 0) );
		mapUser.insert ( std::pair <int, int> (80 , 0) );
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);
		
		mapSys.erase(65);
		mapUser.erase(65);

		mapUser.printTree();
		// mapUser.printHelper();
		
		std::cout << "*** DELETE 65 ***" << std::endl;
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);

		mapSys.erase(75);
		mapUser.erase(75);

		std::cout << "*** DELETE 75 ***" << std::endl;
		print_std_map("     sysMap: ", mapSys);
		print_ft_map("    userMap: ", mapUser);
	
	}
	
	// //***************************SWAP************************//
	// if(swap)
	// {
	// 	std::cout << std::endl << "\x1b[33m" << "swap" << "\x1b[0m" << std::endl;
	// }
	
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
		
	}

}

// void			observers_map(int testNmb, int testAll)
// {
// 	int key_comp = 0;
// 	int value_comp = 0;
	
// 	if (testAll)
// 	{
// 		key_comp = 1;
// 		value_comp = 1; 
// 	}

	
	
// }


// void operations_map(int testNmb, int testAll)
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
	// constructor_map(testNmb);	
	// iterators_map(testNmb, testAll);
	// capacity_map(testNmb, testAll);
	// elementAccess_map(testNmb, testAll);			// +
	modifiers_map(testNmb, testAll);
	// overloads_map(testNmb, testAll);
}
