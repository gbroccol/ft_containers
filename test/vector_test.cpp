/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:04:46 by gbroccol          #+#    #+#             */
/*   Updated: 2021/03/01 13:13:32 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../containers/vector.hpp"
#include "containers_test.hpp"

// #include <string>
// #include <cassert>
// #include <algorithm>

// #include <list>
// #include <map>
// #include <stack>
// #include <queue>

// #include <iostream>

// #include <vector>

// using namespace std; // delete
// using namespace ft; // delete


void vector_test()
{
	std::cout << "\x1b[32m" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "|         VECTOR TESTING         |" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "+ ------------------------------ +" << std::endl << std::endl;
	std::cout << "\x1b[0m";
    
	ft::vector <int> testInt;
	ft::vector <char> testChar;

    // testInt.push(10);
    // testInt.push(20);
    // testInt.push(30);
    // testInt.push(40);
    // testInt.push(50);
    // testChar.push(71);
    // testChar.push(72);
    // testChar.push(73);
    // testChar.push(74);
 
    std::cout << "Vector size : " << testInt.size() << std::endl;
    // std::cout << "Vector capacity : " << testInt.getcapacity() << std::endl;
 
    // std::cout << "Vector elements : ";
    // testInt.print();
 
    // testInt.push(100, 1);
 
    // std::cout << "\nAfter updating 1st index" << std::endl;
 
    // std::cout << "Vector elements of type int : " << std::endl;
    // testInt.print();
    // // This was possible because we used templates
    // std::cout << "Vector elements of type char : " << std::endl;
    // testChar.print();
    // std::cout << "Element at 1st index of type int: " << testInt.get(1)
    //      << std::endl;
    // std::cout << "Element at 1st index of type char: "
    //      << testChar.get(1) << std::endl;
 
    // testInt.pop();
    // testChar.pop();
 
    // std::cout << "\nAfter deleting last element" << std::endl;
 
    // std::cout << "Vector size of type int: " << testInt.size() << std::endl;
    // std::cout << "Vector size of type char: " << testChar.size()
    //      << std::endl;
    // std::cout << "Vector capacity of type int : "
    //      << testInt.getcapacity() << std::endl;
    // std::cout << "Vector capacity of type char : "
    //      << testChar.getcapacity() << std::endl;
 
    // std::cout << "Vector elements of type int: ";
    // testInt.print();
    // std::cout << "Vector elements of type char: ";
    // testChar.print();


	
  
    // return 0; 

}



// int vector_test()
// {
// 	std::cout << "\x1b[34m";
// 	std::cout << "+ ------------------------------ +" << std::endl;
// 	std::cout << "|                                |" << std::endl;
// 	std::cout << "|         VECTOR TESTING         |" << std::endl;
// 	std::cout << "|                                |" << std::endl;
// 	std::cout << "+ ------------------------------ +" << std::endl;
// 	std::cout << "\x1b[0m";
	
//    Vector<int> v;

//    v.reserve(2);
//    assert(v.capacity() == 2);

//    Vector<string> v1(2);
//    assert(v1.capacity() == 2);
//    assert(v1.size() == 2);
//    assert(v1[0] == "");
//    assert(v1[1] == "");

//    v1[0] = "hi";
//    assert(v1[0] == "hi");

//    Vector<int> v2(2, 7);
//    assert(v2[1] == 7);

//    Vector<int> v10(v2);
//    assert(v10[1] == 7);

//    Vector<string> v3(2, "hello");
//    assert(v3.size() == 2);
//    assert(v3.capacity() == 2);
//    assert(v3[0] == "hello");
//    assert(v3[1] == "hello");

//    v3.resize(1);
//    assert(v3.size() == 1);
//    assert(v3[0] == "hello");

//    Vector<string> v4 = v3;
//    assert(v4.size() == 1);
//    assert(v4[0] == v3[0]);
//    v3[0] = "test";
//    assert(v4[0] != v3[0]);  
//    assert(v4[0] == "hello");

//    v3.pop_back();
//    assert(v3.size() == 0);

//    Vector<int> v5(7, 9);
//    Vector<int>::iterator it = v5.begin();
//    while (it != v5.end())
//    {
//       assert(*it == 9);
//       ++it;
//    }

//    Vector<int> v6;
//    v6.push_back(100);
//    assert(v6.size() == 1);
//    assert(v6[0] == 100);
//    v6.push_back(101);
//    assert(v6.size() == 2);
//    assert(v6[0] == 100);
//    v6.push_back(101);

//    cout << "SUCCESS\n";
// 	return (0);
// }