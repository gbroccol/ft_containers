#include "containers_test.hpp"

void				capacity(int testNmb)
{
	ft::list <int> testMyList;
	std::list <int> testOriginalList;

	std::list <int> :: iterator sysData;
	ft::list <int> :: iterator userData = testMyList.begin(); // delete  = testMyList.begin()

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

	
	/*		Size of list CHAR		*/
	std::cout << std::endl << "\x1b[33m" << "Size of list CHAR" << "\x1b[0m" << std::endl;
	
	ft::list <char> userListChar;
	std::list <char> sysListChar;
	
	for (int i = 0; i < 33; i++)
	{
		sysListChar.push_back('a');			
		userListChar.push_back('a');
	}

	std::list <char> :: iterator sysIteratorChar = sysListChar.begin();
	ft::list <char> :: iterator userIteratorChar  = userListChar.begin();

	for (int i = 0; i < 33; i++)
	{
		sysIteratorChar++;
		userIteratorChar++;
	}
	testFunc(testNmb++, userListChar.size(), userListChar.size(), "Size is <char>");
	testFunc(testNmb++, *sysIteratorChar, *userIteratorChar, "Size of list <char>");
	getchar();
	// std::system("clear");
}

void				operators(int testNmb)
{
	std::cout << std::endl << "\x1b[33m" << "                         *** VALUES AND OPERATORS ***                          " << "\x1b[0m" << std::endl;

	ft::list <int> testMyList;
	std::list <int> testOriginalList;

	std::list <int> :: iterator sysData;
	ft::list <int> :: iterator userData = testMyList.begin(); // delete  = testMyList.begin()

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
	getchar();
	// std::system("clear");
}

void				constructor(int testNmb)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** CONSTRUCTOR ***                          " << "\x1b[0m" << std::endl;

	ft::list  <int> userList((size_t)10, 42);
	std::list <int> sysList((size_t)10, 42);

	testFunc(testNmb++, sysList.size(), userList.size(), "Constructor list(size, value)");

	std::list <int> :: iterator sysIterator = sysList.begin();
	ft::list <int> :: iterator userIterator = userList.begin();

	testFunc(testNmb++, *sysIterator, *userIterator, "Constructor list(size, value)");

	/*		COPY		*/
	ft::list  <int> userListCopy(userList);
	std::list <int> sysListCopy(sysList);
	testFunc(testNmb++, sysListCopy.size(), userListCopy.size(), "Constructor copy");
	
	sysIterator = sysListCopy.begin();
	userIterator = userListCopy.begin();
	
	testFunc(testNmb++, *sysIterator, *userIterator, "Constructor copy - value");

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
	getchar();
	// std::system("clear");
}

void				elementAccess(int testNmb)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** ELEMENT ACCESS ***                          " << "\x1b[0m" << std::endl;

	ft::list  <int> userList((size_t)10, 42);
	std::list <int> sysList((size_t)10, 42);

	userList.push_front(11111111);
	sysList.push_front(11111111);

	userList.push_back(22222222);
	sysList.push_back(22222222);
	
	testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
	testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");
	
	getchar();
	// std::system("clear");
}

void				modifiers(int testNmb, int testAll)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** MODIFIERS ***                          " << "\x1b[0m" << std::endl;

	int			assign = 0;				// - 		1/2		template 
	// int			push_front = 0;			// 
	// int			pop_front = 0;			// 
	// int			push_back = 0;			// 
	// int			pop_back = 0;			// 
	int			insert = 0;				// 			2/3
	int			erase = 0;				// +
	int			swap = 0;				// 
	int			resize = 0;				// 

	if (testAll)
	{
		assign = 1;
		insert = 1;
		erase = 1;
		swap = 1;
		resize = 1;
	}

	ft::list  <int> userList((size_t)10, 42);
	std::list <int> sysList((size_t)10, 42);

	ft::list  <int> userList2((size_t)10, 42);
	std::list <int> sysList2((size_t)10, 42);

	std::list <int> :: iterator sysIterator = sysList.begin();
	ft::list <int> :: iterator userIterator = userList.begin();

	if (assign)
	{
		std::cout << std::endl << "\x1b[33m" << "assign" << "\x1b[0m" << std::endl;
		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (assign 1)");

		/*		assign 1		*/
		userList.assign(5, 21);
		sysList.assign(5, 21);
		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (assign 1)");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (assign 1)");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (assign 1)");
		std::cout << std::endl;

		/*		assign 2		*/ 											//template

		// userList.push_front(11111111);
		// sysList.push_front(11111111);

		// userList.push_back(22222222);
		// sysList.push_back(22222222);
		
		// userList.assign(userList2.begin(), userList2.end());
		// sysList.assign(sysList2.begin(), sysList2.end());

		// testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		// testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		// testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");
		// getchar();
		// std::system("clear");

		// std::list<int> first;
		// std::list<int> second;

		// first.assign (7,100);                      // 7 ints with value 100

		// second.assign (first.begin(),first.end()); // a copy of first

		// std::cout << "Size of first: " << int (first.size()) << '\n';
		// std::cout << "Size of second: " << int (second.size()) << '\n';


	}
	
	if (insert)
	{
		std::cout << std::endl << "\x1b[33m" << "insert" << "\x1b[0m" << std::endl;
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
		getchar();
		// std::system("clear");
	}

	if (erase)
	{
		std::cout << std::endl << "\x1b[33m" << "erase" << "\x1b[0m" << std::endl;
	/*		erase 1		*/
	sysList.clear();
	userList.clear();

	sysList.push_back(1);			// 1 2 3
	userList.push_back(1);

	sysList.push_back(2);			// 1 2 3
	userList.push_back(2);

	sysList.push_back(3);			// 1 2 3
	userList.push_back(3);

	// std::cout << "*** BEFORE ***" << std::endl;
	// print_std_list(" Sys Erase:", sysList);
	// print_ft_list("User Erase:", userList);
	// std::cout << std::endl;
  
	sysIterator = sysList.erase(sysList.begin());
	userIterator = userList.erase(userList.begin());

	// std::cout << "*** AFTER ***" << std::endl;
	// print_std_list(" Sys Erase:", sysList);
	// print_ft_list("User Erase:", userList);
	// std::cout << std::endl;

	testFunc(testNmb++, sysList.size(), userList.size(), "Size is (erase 1)");
	testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (erase 1)");
	testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (erase 1)");
	testFunc(testNmb++, *sysIterator, *userIterator, "Return value (erase 1)");
	std::cout << std::endl;

	/*		erase 1.1		*/
	sysList.clear();
	userList.clear();

	sysList.push_back(1);			// 1 
	userList.push_back(1);

	// std::cout << "*** BEFORE ***" << std::endl;
	// print_std_list(" Sys Erase:", sysList);
	// print_ft_list("User Erase:", userList);
	// std::cout << std::endl;
  
	sysIterator = sysList.erase(sysList.begin());
	userIterator = userList.erase(userList.begin());

	// std::cout << "*** AFTER ***" << std::endl;
	// print_std_list(" Sys Erase:", sysList);
	// print_ft_list("User Erase:", userList);
	// std::cout << std::endl;

	testFunc(testNmb++, sysList.size(), userList.size(), "Size is (erase 1.1)");
	testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (erase 1.1)");
	testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (erase 1.1)");
	testFunc(testNmb++, *sysIterator, *userIterator, "Return value (erase 1.1)");
	std::cout << std::endl;

	/*		erase 2		*/
	sysList.clear();
	userList.clear();

	sysList.push_back(1);			// 1 2 3
	userList.push_back(1);

	sysList.push_back(2);			// 1 2 3
	userList.push_back(2);

	sysList.push_back(3);			// 1 2 3
	userList.push_back(3);
	
	// std::cout << "*** BEFORE ***" << std::endl;
	// print_std_list(" Sys Erase:", sysList);
	// print_ft_list("User Erase:", userList);
	// std::cout << std::endl;
  
	sysIterator = sysList.begin();

	userIterator = userList.begin();
  
	sysIterator = sysList.erase(sysList.begin(), sysIterator);
	userIterator = userList.erase(userList.begin(), userIterator);

	// std::cout << "*** AFTER ***" << std::endl;
	// print_std_list(" Sys Erase:", sysList);
	// print_ft_list("User Erase:", userList);
	// std::cout << std::endl;

	testFunc(testNmb++, sysList.size(), userList.size(), "Size is (erase 2)");
	testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (erase 2)");
	testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (erase 2)");
	testFunc(testNmb++, *sysIterator, *userIterator, "Return value (erase 2)");
	std::cout << std::endl;

	/*		erase 2.0		*/
	sysList.clear();
	userList.clear();

	sysList.push_back(1);			// 1 2 3
	userList.push_back(1);

	sysList.push_back(2);			// 1 2 3
	userList.push_back(2);

	sysList.push_back(3);			// 1 2 3
	userList.push_back(3);
	
	// std::cout << "*** BEFORE ***" << std::endl;
	// print_std_list(" Sys Erase:", sysList);
	// print_ft_list("User Erase:", userList);
	// std::cout << std::endl;
  
	sysIterator = sysList.begin();
	sysIterator++;

	userIterator = userList.begin();
	userIterator++;
  
	sysIterator = sysList.erase(sysList.begin(), sysIterator);
	userIterator = userList.erase(userList.begin(), userIterator);

	// std::cout << "*** AFTER ***" << std::endl;
	// print_std_list(" Sys Erase:", sysList);
	// print_ft_list("User Erase:", userList);
	// std::cout << std::endl;

	testFunc(testNmb++, sysList.size(), userList.size(), "Size is (erase 2.0)");
	testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (erase 2.0)");
	testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (erase 2.0)");
	testFunc(testNmb++, *sysIterator, *userIterator, "Return value (erase 2.0)");
	std::cout << std::endl;

	/*		erase 2.1		*/
	sysList.clear();
	userList.clear();

	sysList.push_back(1);			// 1 2 3
	userList.push_back(1);

	sysList.push_back(2);			// 1 2 3
	userList.push_back(2);

	sysList.push_back(3);			// 1 2 3
	userList.push_back(3);
	
	// std::cout << "*** BEFORE ***" << std::endl;
	// print_std_list(" Sys Erase:", sysList);
	// print_ft_list("User Erase:", userList);
	// std::cout << std::endl;
  
	sysIterator = sysList.begin();
	sysIterator++;
	sysIterator++;

	userIterator = userList.begin();
	userIterator++;
	userIterator++;
  
	sysIterator = sysList.erase(sysList.begin(), sysIterator);
	userIterator = userList.erase(userList.begin(), userIterator);

	// std::cout << "*** AFTER ***" << std::endl;
	// print_std_list(" Sys Erase:", sysList);
	// print_ft_list("User Erase:", userList);
	// std::cout << std::endl;

	testFunc(testNmb++, sysList.size(), userList.size(), "Size is (erase 2.1)");
	testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (erase 2.1)");
	testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (erase 2.1)");
	testFunc(testNmb++, *sysIterator, *userIterator, "Return value (erase 2.1)");
	std::cout << std::endl;

	/*		erase 2.2		*/
	sysList.clear();
	userList.clear();

	sysList.push_back(1);			// 1 2 3
	userList.push_back(1);

	sysList.push_back(2);			// 1 2 3
	userList.push_back(2);

	sysList.push_back(3);			// 1 2 3
	userList.push_back(3);
	
	// std::cout << "*** BEFORE ***" << std::endl;
	// print_std_list(" Sys Erase:", sysList);
	// print_ft_list("User Erase:", userList);
	// std::cout << std::endl;
  
	sysIterator = sysList.begin();
	sysIterator++;
	sysIterator++;
	sysIterator++;

	userIterator = userList.begin();
	userIterator++;
	userIterator++;
	userIterator++;
  
	sysIterator = sysList.erase(sysList.begin(), sysIterator);
	userIterator = userList.erase(userList.begin(), userIterator);

	// std::cout << "*** AFTER ***" << std::endl;
	// print_std_list(" Sys Erase:", sysList);
	// print_ft_list("User Erase:", userList);
	// std::cout << std::endl;

	testFunc(testNmb++, sysList.size(), userList.size(), "Size is (erase 2.2)");
	testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (erase 2.2)");
	testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (erase 2.2)");
	testFunc(testNmb++, *sysIterator, *userIterator, "Return value (erase 2.2)");
	std::cout << std::endl;

	/*		erase 2.3		*/
	sysList.clear();
	userList.clear();

	sysList.push_back(5);			// 5 6 7
	userList.push_back(5);

	sysList.push_back(6);			// 5 6 7
	userList.push_back(6);

	sysList.push_back(7);			// 5 6 7
	userList.push_back(7);
	
	// std::cout << "*** BEFORE ***" << std::endl;
	// print_std_list(" Sys Erase:", sysList);
	// print_ft_list("User Erase:", userList);
	// std::cout << std::endl;
  
	sysIterator = sysList.begin();
	sysIterator++;
	sysIterator++;
	sysIterator++;
	sysIterator++;

	userIterator = userList.begin();
	userIterator++;
	userIterator++;
	userIterator++;
	userIterator++;

	testFunc(testNmb++, *(sysList.begin()), *(userList.begin()), "First iterator is (erase 2.3)");
	testFunc(testNmb++, *sysIterator, *userIterator, "Last iterator is (erase 2.3)");
  
	sysIterator = sysList.erase(sysList.begin(), sysIterator);
	userIterator = userList.erase(userList.begin(), userIterator);

	// std::cout << "*** AFTER ***" << std::endl;
	// print_std_list(" Sys Erase:", sysList);
	// print_ft_list("User Erase:", userList);
	// std::cout << std::endl;

	testFunc(testNmb++, sysList.size(), userList.size(), "Size is (erase 2.3)");
	testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (erase 2.3)");
	testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (erase 2.3)");
	testFunc(testNmb++, *sysIterator, *userIterator, "Return value (erase 2.3)");
	std::cout << std::endl;
	getchar();
	// std::system("clear");
	}

	if (swap)
	{
		/*		swap 1		*/
		std::cout << std::endl << "\x1b[33m" << "swap" << "\x1b[0m" << std::endl;

		std::list <int> sysListSwap1;
		ft::list <int> userListSwap1;

		sysListSwap1.push_back(1);
		userListSwap1.push_back(1);
		
		sysListSwap1.push_back(2);
		userListSwap1.push_back(2);
		
		sysListSwap1.push_back(3);
		userListSwap1.push_back(3);

		std::list <int> sysListSwap2;
		ft::list <int> userListSwap2;

		sysListSwap2.push_back(4);
		userListSwap2.push_back(4);
		
		sysListSwap2.push_back(5);
		userListSwap2.push_back(5);
		
		sysListSwap2.push_back(6);
		userListSwap2.push_back(6);

		sysListSwap2.push_back(7);
		userListSwap2.push_back(7);
		
		sysListSwap2.push_back(8);
		userListSwap2.push_back(8);
		
		sysListSwap2.push_back(9);
		userListSwap2.push_back(9);

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" SysListSwap1:", sysListSwap1);
		print_std_list(" SysListSwap2:", sysListSwap2);
		std::cout << std::endl;
		print_ft_list("UserListSwap1:", userListSwap1);
		print_ft_list("UserListSwap2:", userListSwap2);
		std::cout << std::endl;

		sysListSwap1.swap(sysListSwap2);
		userListSwap1.swap(userListSwap2);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysListSwap1:", sysListSwap1);
		print_std_list(" SysListSwap2:", sysListSwap2);
		std::cout << std::endl;
		print_ft_list("UserListSwap1:", userListSwap1);
		print_ft_list("UserListSwap2:", userListSwap2);
		std::cout << std::endl;

		testFunc(testNmb++, sysListSwap1.size(), userListSwap1.size(), "Size is (swap)");
		testFunc(testNmb++, sysListSwap1.front(), userListSwap1.front(), "Front value is (swap)");
		testFunc(testNmb++, sysListSwap1.back(), userListSwap1.back(), "Back value is (swap)");

		testFunc(testNmb++, sysListSwap2.size(), userListSwap2.size(), "Size is (swap)");
		testFunc(testNmb++, sysListSwap2.front(), userListSwap2.front(), "Front value is (swap)");
		testFunc(testNmb++, sysListSwap2.back(), userListSwap2.back(), "Back value is (swap)");

		getchar();
		// std::system("clear");
	}
	
	if (resize)
	{
		/*		resize 1		*/
		std::cout << std::endl << "\x1b[33m" << "resize" << "\x1b[0m" << std::endl;
		
		sysList.clear();
		userList.clear();
		
		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		sysList.resize(3, 9);
		userList.resize(3, 9);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (resize 1)");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (resize 1)");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (resize 1)");
		getchar();
		// std::system("clear");

		/*		resize 2		*/
		std::cout << std::endl << "\x1b[33m" << "resize" << "\x1b[0m" << std::endl;
		
		sysList.clear();
		userList.clear();

		sysList.push_back(5);			// 5 6 7
		userList.push_back(5);

		sysList.push_back(6);			// 5 6 7
		userList.push_back(6);

		sysList.push_back(7);			// 5 6 7
		userList.push_back(7);
		
		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		sysList.resize(3, 9);
		userList.resize(3, 9);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (resize 2)");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (resize 2)");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (resize 2)");
		getchar();
		// std::system("clear");

		/*		resize 3		*/
		std::cout << std::endl << "\x1b[33m" << "resize" << "\x1b[0m" << std::endl;
		
		sysList.clear();
		userList.clear();

		sysList.push_back(5);			// 5 6 7
		userList.push_back(5);

		sysList.push_back(6);			// 5 6 7
		userList.push_back(6);

		sysList.push_back(7);			// 5 6 7
		userList.push_back(7);
		
		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		sysList.resize(5, 9);
		userList.resize(5, 9);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (resize 3)");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (resize 3)");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (resize 3)");
		getchar();
		// std::system("clear");


		/*		resize 4		*/
		std::cout << std::endl << "\x1b[33m" << "resize" << "\x1b[0m" << std::endl;
		
		sysList.clear();
		userList.clear();

		sysList.push_back(5);			// 5 6 7
		userList.push_back(5);

		sysList.push_back(6);			// 5 6 7
		userList.push_back(6);

		sysList.push_back(7);			// 5 6 7
		userList.push_back(7);
		
		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		sysList.resize(1, 9);
		userList.resize(1, 9);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_list(" Sys Erase:", sysList);
		// print_ft_list("User Erase:", userList);
		// std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is (resize 4)");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is (resize 4)");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (resize 4)");
		getchar();
		// std::system("clear");
	}
	
}

void				operations(int testNmb, int testAll)
{
	std::cout << std::endl << "\x1b[33m" << "                              *** OPERATIONS ***" << "\x1b[0m" << std::endl;

	int			splice = 0;				// +	3/3
	int			remove = 0;				// +
	int			removeIf = 0;			// -			template
	int			unique = 0;				// -	1/2		template
	int			merge = 0;				// -
	int			sort = 1;				// 
	int			reverse = 0;			// 

	if (testAll)
	{
		splice = 1;
		remove = 1;
		removeIf = 1;
		unique = 1;
		merge = 1;
		sort = 1;
		reverse = 1;
	}

	std::list <int> sysList;
	ft::list <int> userList;

	std::list <int> sysList2;
	ft::list <int> userList2;

	std::list <int> :: iterator sysIter;
	ft::list <int> :: iterator userIter = userList2.begin();

	std::list <int> :: iterator sysWhereAdd1;
	ft::list <int> :: iterator userWhereAdd1 = userList2.begin();

	if (splice)
	{
		/*		void splice (iterator position, list& x);		*/
		std::cout << std::endl << "\x1b[33m" << "splice" << "\x1b[0m" << std::endl;

		std::list <int> sysListSplice1;
		ft::list <int> userListSplice1;

		for (int i = 1; i <= 3; i++)
		{
			sysListSplice1.push_back(i);
			userListSplice1.push_back(i);
		}

		std::list <int> sysListSplice2;
		ft::list <int> userListSplice2;

		for (int i = 4; i <= 9; i++)
		{
			sysListSplice2.push_back(i);
			userListSplice2.push_back(i);
		}

		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_list(" SysListSplice1:", sysListSplice1);
		// print_std_list(" SysListSplice2:", sysListSplice2);
		// std::cout << std::endl;
		// print_ft_list("UserListSplice1:", userListSplice1);
		// print_ft_list("UserListSplice2:", userListSplice2);
		// std::cout << std::endl;

		sysListSplice1.splice(sysListSplice1.begin(), sysListSplice2);
		userListSplice1.splice(userListSplice1.begin(), userListSplice2);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_list(" SysListSplice1:", sysListSplice1);
		// print_std_list(" SysListSplice2:", sysListSplice2);
		// std::cout << std::endl;
		// print_ft_list("UserListSplice1:", userListSplice1);
		// print_ft_list("UserListSplice2:", userListSplice2);
		// std::cout << std::endl;

		testFunc(testNmb++, sysListSplice1.size(), userListSplice1.size(), "Size is (Splice 1)");
		testFunc(testNmb++, sysListSplice1.front(), userListSplice1.front(), "Front value is (Splice 1)");
		testFunc(testNmb++, sysListSplice1.back(), userListSplice1.back(), "Back value is (Splice 1)");

		testFunc(testNmb++, sysListSplice2.size(), userListSplice2.size(), "Size is (Splice 1)");
		testFunc(testNmb++, sysListSplice2.front(), userListSplice2.front(), "Front value is (Splice 1)");
		testFunc(testNmb++, sysListSplice2.back(), userListSplice2.back(), "Back value is (Splice 1)");

		getchar();
		// std::system("clear");

		/*		void splice (iterator position, list& x, iterator i);		*/
		std::cout << std::endl << "\x1b[33m" << "splice" << "\x1b[0m" << std::endl;

			sysListSplice1.clear();
		userListSplice1.clear();

		for (int i = 1; i <= 4; i++)
		{
			sysListSplice1.push_back(555555);
			userListSplice1.push_back(555555);
		}

		sysListSplice2.clear();
		userListSplice2.clear();

		for (int i = 1; i <= 9; i++)
		{
			sysListSplice2.push_back(i);
			userListSplice2.push_back(i);
		}

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" SysListSplice1:", sysListSplice1);
		print_std_list(" SysListSplice2:", sysListSplice2);
		std::cout << std::endl;
		print_ft_list("UserListSplice1:", userListSplice1);
		print_ft_list("UserListSplice2:", userListSplice2);
		std::cout << std::endl;

		sysIter = sysListSplice2.begin();
		userIter = userListSplice2.begin();

		sysIter++;
		userIter++;

		sysWhereAdd1 = sysListSplice1.begin();
		userWhereAdd1 = userListSplice1.begin();

		sysWhereAdd1++;
		userWhereAdd1++;

		sysWhereAdd1++;
		userWhereAdd1++;

		sysListSplice1.splice(sysWhereAdd1, sysListSplice2, sysIter);
		userListSplice1.splice(userWhereAdd1, userListSplice2, userIter);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysListSplice1:", sysListSplice1);
		print_std_list(" SysListSplice2:", sysListSplice2);
		std::cout << std::endl;
		print_ft_list("UserListSplice1:", userListSplice1);
		print_ft_list("UserListSplice2:", userListSplice2);
		std::cout << std::endl;

		testFunc(testNmb++, sysListSplice1.size(), userListSplice1.size(), "Size is (Splice 2.1)");
		testFunc(testNmb++, sysListSplice1.front(), userListSplice1.front(), "Front value is (Splice 2.1)");
		testFunc(testNmb++, sysListSplice1.back(), userListSplice1.back(), "Back value is (Splice 2.1)");

		testFunc(testNmb++, sysListSplice2.size(), userListSplice2.size(), "Size is (Splice 2.1)");
		testFunc(testNmb++, sysListSplice2.front(), userListSplice2.front(), "Front value is (Splice 2.1)");
		testFunc(testNmb++, sysListSplice2.back(), userListSplice2.back(), "Back value is (Splice 2.1)");
		getchar();
		// std::system("clear");

		/*		void splice (iterator position, list& x, iterator i);		*/
		std::cout << std::endl << "\x1b[33m" << "splice" << "\x1b[0m" << std::endl;

		sysListSplice1.clear();
		userListSplice1.clear();

		for (int i = 1; i <= 4; i++)
		{
			sysListSplice1.push_back(555555);
			userListSplice1.push_back(555555);
		}

		sysListSplice2.clear();
		userListSplice2.clear();

		for (int i = 1; i <= 9; i++)
		{
			sysListSplice2.push_back(i);
			userListSplice2.push_back(i);
		}

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" SysListSplice1:", sysListSplice1);
		print_std_list(" SysListSplice2:", sysListSplice2);
		std::cout << std::endl;
		print_ft_list("UserListSplice1:", userListSplice1);
		print_ft_list("UserListSplice2:", userListSplice2);
		std::cout << std::endl;

		sysIter = sysListSplice2.begin();
		userIter = userListSplice2.begin();

		sysIter++;
		userIter++;

		sysWhereAdd1 = sysListSplice1.begin();
		userWhereAdd1 = userListSplice1.begin();

		sysWhereAdd1++;
		userWhereAdd1++;

		sysWhereAdd1++;
		userWhereAdd1++;

		sysListSplice1.splice(sysWhereAdd1, sysListSplice2, sysWhereAdd1);
		userListSplice1.splice(userWhereAdd1, userListSplice2, userWhereAdd1);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysListSplice1:", sysListSplice1);
		print_std_list(" SysListSplice2:", sysListSplice2);
		std::cout << std::endl;
		print_ft_list("UserListSplice1:", userListSplice1);
		print_ft_list("UserListSplice2:", userListSplice2);
		std::cout << std::endl;

		testFunc(testNmb++, sysListSplice1.size(), userListSplice1.size(), "Size is (Splice 2.2)");
		testFunc(testNmb++, sysListSplice1.front(), userListSplice1.front(), "Front value is (Splice 2.2)");
		testFunc(testNmb++, sysListSplice1.back(), userListSplice1.back(), "Back value is (Splice 2.2)");

		testFunc(testNmb++, sysListSplice2.size(), userListSplice2.size(), "Size is (Splice 2.2)");
		testFunc(testNmb++, sysListSplice2.front(), userListSplice2.front(), "Front value is (Splice 2.2)");
		testFunc(testNmb++, sysListSplice2.back(), userListSplice2.back(), "Back value is (Splice 2.2)");
		getchar();
		// std::system("clear");

		/*		void splice (iterator position, list& x, iterator i);		*/
		std::cout << std::endl << "\x1b[33m" << "splice" << "\x1b[0m" << std::endl;

		sysListSplice1.clear();
		userListSplice1.clear();

		for (int i = 1; i <= 4; i++)
		{
			sysListSplice1.push_back(555555);
			userListSplice1.push_back(555555);
		}

		sysListSplice2.clear();
		userListSplice2.clear();

		for (int i = 1; i <= 9; i++)
		{
			sysListSplice2.push_back(i);
			userListSplice2.push_back(i);
		}

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" SysListSplice1:", sysListSplice1);
		print_std_list(" SysListSplice2:", sysListSplice2);
		std::cout << std::endl;
		print_ft_list("UserListSplice1:", userListSplice1);
		print_ft_list("UserListSplice2:", userListSplice2);
		std::cout << std::endl;

		sysIter = sysListSplice2.begin();
		userIter = userListSplice2.begin();

		sysIter++;
		userIter++;

		sysWhereAdd1 = sysListSplice1.begin();
		userWhereAdd1 = userListSplice1.begin();

		sysWhereAdd1++;
		userWhereAdd1++;

		sysWhereAdd1++;
		userWhereAdd1++;

		sysListSplice1.splice(sysWhereAdd1, sysListSplice2, sysWhereAdd1++);
		userListSplice1.splice(userWhereAdd1, userListSplice2, userWhereAdd1++);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysListSplice1:", sysListSplice1);
		print_std_list(" SysListSplice2:", sysListSplice2);
		std::cout << std::endl;
		print_ft_list("UserListSplice1:", userListSplice1);
		print_ft_list("UserListSplice2:", userListSplice2);
		std::cout << std::endl;

		testFunc(testNmb++, sysListSplice1.size(), userListSplice1.size(), "Size is (Splice 2.3)");
		testFunc(testNmb++, sysListSplice1.front(), userListSplice1.front(), "Front value is (Splice 2.3)");
		testFunc(testNmb++, sysListSplice1.back(), userListSplice1.back(), "Back value is (Splice 2.3)");

		testFunc(testNmb++, sysListSplice2.size(), userListSplice2.size(), "Size is (Splice 2.3)");
		testFunc(testNmb++, sysListSplice2.front(), userListSplice2.front(), "Front value is (Splice 2.3)");
		testFunc(testNmb++, sysListSplice2.back(), userListSplice2.back(), "Back value is (Splice 2.3)");
		getchar();
		// std::system("clear");


		/*		void splice (iterator position, list& x, iterator first, iterator last);		*/
		std::cout << std::endl << "\x1b[33m" << "splice" << "\x1b[0m" << std::endl;

		sysListSplice1.clear();
		userListSplice1.clear();

		for (int i = 1; i <= 4; i++)
		{
			sysListSplice1.push_back(1000000);
			userListSplice1.push_back(1000000);
		}

		sysListSplice2.clear();
		userListSplice2.clear();

		for (int i = 10; i <= 20; i++)
		{
			sysListSplice2.push_back(i);
			userListSplice2.push_back(i);
		}

		// std::cout << "*** BEFORE ***" << std::endl;
		// print_std_list(" SysListSplice1:", sysListSplice1);
		// print_std_list(" SysListSplice2:", sysListSplice2);
		// std::cout << std::endl;
		// print_ft_list("UserListSplice1:", userListSplice1);
		// print_ft_list("UserListSplice2:", userListSplice2);
		// std::cout << std::endl;

		std::list <int> :: iterator sysStart2 = sysListSplice2.begin();
		ft::list <int> :: iterator userStart2 = userListSplice2.begin();

		sysStart2++;
		userStart2++;

		std::list <int> :: iterator sysEnd2 = sysListSplice2.end();
		ft::list <int> :: iterator userEnd2 = userListSplice2.end();
		
		sysEnd2--;
		userEnd2--;

		std::list <int> :: iterator sysWhereAdd = sysListSplice1.begin();
		ft::list <int> :: iterator userWhereAdd = userListSplice1.begin();

		sysWhereAdd++;
		userWhereAdd++;

		sysWhereAdd++;
		userWhereAdd++;

		sysListSplice1.splice(sysWhereAdd, sysListSplice2, sysStart2, sysEnd2);
		userListSplice1.splice(userWhereAdd, userListSplice2, userStart2, userEnd2);

		// std::cout << "*** AFTER ***" << std::endl;
		// print_std_list(" SysListSplice1:", sysListSplice1);
		// print_std_list(" SysListSplice2:", sysListSplice2);
		// std::cout << std::endl;
		// print_ft_list("UserListSplice1:", userListSplice1);
		// print_ft_list("UserListSplice2:", userListSplice2);
		// std::cout << std::endl;

		testFunc(testNmb++, sysListSplice1.size(), userListSplice1.size(), "Size is (Splice 3)");
		testFunc(testNmb++, sysListSplice1.front(), userListSplice1.front(), "Front value is (Splice 3)");
		testFunc(testNmb++, sysListSplice1.back(), userListSplice1.back(), "Back value is (Splice 3)");

		testFunc(testNmb++, sysListSplice2.size(), userListSplice2.size(), "Size is (Splice 3)");
		testFunc(testNmb++, sysListSplice2.front(), userListSplice2.front(), "Front value is (Splice 3)");
		testFunc(testNmb++, sysListSplice2.back(), userListSplice2.back(), "Back value is (Splice 3)");

		getchar();
		// std::system("clear");
	}
	
	if (remove)
	{
		/*		remove		*/
		std::cout << std::endl << "\x1b[33m" << "remove" << "\x1b[0m" << std::endl;

		for (int i = -1; i <= 1; i++)
		{
			sysList.push_back(i);
			userList.push_back(i);
		}
		for (int i = 1; i <= 3; i++)
		{
			sysList.push_back(0);
			userList.push_back(0);

			sysList.push_front(0);
			userList.push_front(0);
		}
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		std::cout << std::endl;

		sysList.remove(0);
		userList.remove(0);

		sysList.remove(2);
		userList.remove(2);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysList:", sysList);
		std::cout << std::endl;
		print_ft_list("UserList:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is (Splic");

		getchar();
		// std::system("clear");

	}

	if (removeIf)
	{

	}

	if (unique)
	{
		/*		unique		*/
		std::cout << std::endl << "\x1b[33m" << "unique 1" << "\x1b[0m" << std::endl;

		sysList.clear();
		userList.clear();

		for (int i = 1; i <= 10; i++)
		{
			sysList.push_back(i);
			userList.push_back(i);

			sysList.push_back(i);
			userList.push_back(i);
		}
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		std::cout << std::endl;

		sysList.unique();
		userList.unique();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysList:", sysList);
		std::cout << std::endl;
		print_ft_list("UserList:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is ");

		getchar();
		// std::system("clear");

		/*		unique		*/
		std::cout << std::endl << "\x1b[33m" << "unique 2" << "\x1b[0m" << std::endl;

		sysList.clear();
		userList.clear();

		for (int i = 1; i <= 5; i++)
		{
			sysList.push_back(i);
			userList.push_back(i);

			sysList.push_back(5);
			userList.push_back(5);

			sysList.push_back(i);
			userList.push_back(i);
		}
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		std::cout << std::endl;

		sysList.unique();
		userList.unique();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysList:", sysList);
		std::cout << std::endl;
		print_ft_list("UserList:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		getchar();
		// std::system("clear");

		/*		unique		*/
		std::cout << std::endl << "\x1b[33m" << "unique 3" << "\x1b[0m" << std::endl;

		sysList.clear();
		userList.clear();

		for (int i = 5; i < 10; i++)
		{
			sysList.push_back(i);
			userList.push_back(i);

			sysList.push_back(i);
			userList.push_back(i);
		}
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		std::cout << std::endl;

		sysList.unique();
		userList.unique();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysList:", sysList);
		std::cout << std::endl;
		print_ft_list("UserList:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		getchar();
		// std::system("clear");

		/*		unique		*/
		std::cout << std::endl << "\x1b[33m" << "unique 4" << "\x1b[0m" << std::endl;

		sysList.clear();
		userList.clear();
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		std::cout << std::endl;

		sysList.unique();
		userList.unique();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysList:", sysList);
		std::cout << std::endl;
		print_ft_list("UserList:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is ");

		getchar();
		// std::system("clear");

		/*		unique		*/
		std::cout << std::endl << "\x1b[33m" << "unique 5" << "\x1b[0m" << std::endl;

		sysList.clear();
		userList.clear();

		for (int i = 1; i <= 1; i++)
		{
			sysList.push_back(1);
			userList.push_back(1);
		}
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		std::cout << std::endl;

		sysList.unique();
		userList.unique();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysList:", sysList);
		std::cout << std::endl;
		print_ft_list("UserList:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is ");

		getchar();
		// std::system("clear");
	}

	if (merge)
	{
		/*		merge		*/
		std::cout << std::endl << "\x1b[33m" << "merge 1" << "\x1b[0m" << std::endl;

		sysList.clear();
		userList.clear();

		for (int i = 1; i <= 9; i++)
		{
			sysList.push_back(i);
			userList.push_back(i);
		}
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		std::cout << std::endl;

		sysList.merge(sysList);
		userList.merge(userList);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysList:", sysList);
		std::cout << std::endl;
		print_ft_list("UserList:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList2.size(), userList2.size(), "Size is");
		testFunc(testNmb++, sysList2.front(), userList2.front(), "Front value is");
		testFunc(testNmb++, sysList2.back(), userList2.back(), "Back value is ");

		getchar();
		// std::system("clear");

		/*		merge		*/
		std::cout << std::endl << "\x1b[33m" << "merge 2" << "\x1b[0m" << std::endl;

		sysList.clear();
		userList.clear();

		sysList2.clear();
		userList2.clear();

		for (int i = 5; i <= 15; i++)
		{
			sysList.push_back(i);
			userList.push_back(i);
		}

		for (int i = 1; i < 5; i++)
		{
			sysList2.push_back(3);
			userList2.push_back(3);
		}
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		print_std_list(" sysList:", sysList2);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		print_ft_list("userList:", userList2);
		std::cout << std::endl;

		sysList.merge(sysList2);
		userList.merge(userList2);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" sysList:", sysList);
		print_std_list(" sysList:", sysList2);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		print_ft_list("userList:", userList2);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList2.size(), userList2.size(), "Size is");
		testFunc(testNmb++, sysList2.front(), userList2.front(), "Front value is");
		testFunc(testNmb++, sysList2.back(), userList2.back(), "Back value is ");

		getchar();
		// std::system("clear");


		/*		merge		*/
		std::cout << std::endl << "\x1b[33m" << "merge 3" << "\x1b[0m" << std::endl;

		sysList.clear();
		userList.clear();

		sysList2.clear();
		userList2.clear();

		for (int i = 1; i <= 9; i++)
		{
			sysList.push_back(i);
			userList.push_back(i);
		}

		for (int i = 1; i <= 15; i++)
		{
			sysList2.push_back(i);
			userList2.push_back(i);
		}
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		print_std_list(" sysList:", sysList2);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		print_ft_list("userList:", userList2);
		std::cout << std::endl;

		sysList.merge(sysList2);
		userList.merge(userList2);
		// userList.unique();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" sysList:", sysList);
		print_std_list(" sysList:", sysList2);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		print_ft_list("userList:", userList2);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList2.size(), userList2.size(), "Size is");
		testFunc(testNmb++, sysList2.front(), userList2.front(), "Front value is");
		testFunc(testNmb++, sysList2.back(), userList2.back(), "Back value is ");

		getchar();
		// std::system("clear");

		/*		merge		*/
		std::cout << std::endl << "\x1b[33m" << "merge 4" << "\x1b[0m" << std::endl;

		sysList.clear();
		userList.clear();

		sysList2.clear();
		userList2.clear();

		for (int i = 1; i <= 9; i++)
		{
			sysList.push_back(i);
			userList.push_back(i);
		}

		for (int i = 6; i >= -5; i--)
		{
			sysList2.push_back(i);
			userList2.push_back(i);
		}
		
		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		print_std_list(" sysList:", sysList2);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		print_ft_list("userList:", userList2);
		std::cout << std::endl;

		sysList.merge(sysList2);
		userList.merge(userList2);

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" sysList:", sysList);
		print_std_list(" sysList:", sysList2);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		print_ft_list("userList:", userList2);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList2.size(), userList2.size(), "Size is");
		testFunc(testNmb++, sysList2.front(), userList2.front(), "Front value is");
		testFunc(testNmb++, sysList2.back(), userList2.back(), "Back value is ");

		getchar();
		// std::system("clear");
	}

	if (sort)
	{
		/*		sort		*/
		std::cout << std::endl << "\x1b[33m" << "sort 1" << "\x1b[0m" << std::endl;

		sysList.clear();
		userList.clear();

		sysList.push_back(100);
		userList.push_back(100);

		int j = -10;
		for (int i = 0; i <= 10; i++)
		{
			sysList.push_back(i);
			userList.push_back(i);

			sysList.push_back(j);
			userList.push_back(j);

			j++;
		}

		sysList.push_back(-5);
		userList.push_back(-5);

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		std::cout << std::endl;

		sysList.sort();
		userList.sort();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysList:", sysList);
		std::cout << std::endl;
		print_ft_list("UserList:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		getchar();
		// std::system("clear");

		/*		sort		*/
		std::cout << std::endl << "\x1b[33m" << "sort 2" << "\x1b[0m" << std::endl;

		sysList.clear();
		userList.clear();

		sysList.push_back(5);
		userList.push_back(5);

		sysList.push_back(2);
		userList.push_back(2);

		sysList.push_back(100);
		userList.push_back(100);

		sysList.push_back(30);
		userList.push_back(30);

		sysList.push_back(10);
		userList.push_back(10);

		sysList.push_back(1);
		userList.push_back(1);
		
		sysList.push_back(6);
		userList.push_back(6);

		sysList.push_back(150);
		userList.push_back(150);

		std::cout << "*** BEFORE ***" << std::endl;
		print_std_list(" sysList:", sysList);
		std::cout << std::endl;
		print_ft_list("userList:", userList);
		std::cout << std::endl;

		sysList.sort();
		userList.sort();

		std::cout << "*** AFTER ***" << std::endl;
		print_std_list(" SysList:", sysList);
		std::cout << std::endl;
		print_ft_list("UserList:", userList);
		std::cout << std::endl;

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		testFunc(testNmb++, sysList.size(), userList.size(), "Size is");
		testFunc(testNmb++, sysList.front(), userList.front(), "Front value is");
		testFunc(testNmb++, sysList.back(), userList.back(), "Back value is");

		getchar();
		// std::system("clear");
	}

	if (reverse)
	{

	}
}

void				list_test()
{
	int testNmb = 0;
	int testAll = 0;
	
	std::cout << "\x1b[33m" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "|          LIST TESTING          |" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl << std::endl;
	std::cout << "\x1b[0m";

	/*			Member functions			*/
	
	/* extra */
	// operators(testNmb);

	// constructor(testNmb);
	// destructor(testNmb);			// need tests
	// operator=(testNmb);			// need tests
	
	// iterators(testNmb);			// need tests
	// capacity(testNmb);
	// elementAccess(testNmb);
	// modifiers(testNmb, testAll);
	operations(testNmb, testAll);
	// observers(testNmb);			// need tests
	// overloads(testNmb);			// need tests
}
