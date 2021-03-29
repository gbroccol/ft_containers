/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:48:16 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/29 21:03:15 by gbroccol         ###   ########.fr       */
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

// void				capacity_map(int testNmb, int testAll)
// {
// 	std::cout << std::endl << "\x1b[33m" << "                              *** CAPACITY ***                          " << "\x1b[0m" << std::endl;
	
// 	int			size = 0;	  
// 	int			max_size = 0; 
// 	int			empty = 0;	  

// 	if (testAll)
// 	{
// 		size = 1;	  
// 		max_size = 1;
// 		empty = 1;
// 	}
	
// 	//***************************SIZE************************//
// 	if(size)
// 	{
// 		std::cout << std::endl << "\x1b[33m" << "size" << "\x1b[0m" << std::endl;
		
// 		getchar();
// 	}

// 	//***************************MAX_SIZE************************//
// 	if(max_size)
// 	{
// 		std::cout << std::endl << "\x1b[33m" << "max_size" << "\x1b[0m" << std::endl;

// 		getchar();
// 	}


	
// 	//***************************EMPTY************************//
// 	if(empty)
// 	{
// 		std::cout << std::endl << "\x1b[33m" << "empty" << "\x1b[0m" << std::endl;
	
// 		getchar();
// 	}
// }

// void				elementAccess_map(int testNmb, int testAll)
// {
// 	std::cout << std::endl << "\x1b[33m" << "                              *** ELEMENT ACCESS ***                          " << "\x1b[0m" << std::endl;
	
// 	int			Operator = 0;	  

// 	if (testAll)
// 	{
// 		Operator = 1;	  
// 	}
	
// 	//***************************OPERATOR []************************//
// 	if(Operator)
// 	{
// 		std::cout << std::endl << "\x1b[33m" << "operator []" << "\x1b[0m" << std::endl;

// 		getchar();
		
// 	}
// }

void				modifiers_map(int testNmb, int testAll)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** MODIFIERS ***                          " << "\x1b[0m" << std::endl;

	int			insert = 0;
	int			erase = 0; 
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

		mapUser.insert ( std::pair <int, int> (20, 42) );
		mapUser.insert ( std::pair <int, int> (20, 42) );
		mapUser.insert ( std::pair <int, int> (10, 10) );
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

		// print_std_map_inv("     sysMap: ", mapSys);
		// print_ft_map_inv("    userMap: ", mapUser);

		testFunc(testNmb++, mapSys.size(), mapUser.size(), "Size is");

	}

	// //***************************ERASE************************//
	// if(erase)
	// {
	// 	std::cout << std::endl << "\x1b[33m" << "erase" << "\x1b[0m" << std::endl;
		
		
	// }
	
	// //***************************SWAP************************//
	// if(swap)
	// {
	// 	std::cout << std::endl << "\x1b[33m" << "swap" << "\x1b[0m" << std::endl;
	// }
	
	// //***************************CLEAR************************//
	// if(clear)
	// {
	// 	std::cout << std::endl << "\x1b[33m" << "clear" << "\x1b[0m" << std::endl;
	// }

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
	int testAll = 1;

	system("clear");

	std::cout << "\x1b[32m" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "|           MAP TESTING          |" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl << std::endl;
	std::cout << "\x1b[0m";

	/*			Member functions			*/
	constructor_map(testNmb);	
	// iterators_map(testNmb, testAll);
	// capacity_map(testNmb, testAll);
	// elementAccess_map(testNmb, testAll);
	modifiers_map(testNmb, testAll);
	// overloads_map(testNmb, testAll);
}
