	// void		sortExtra(iterator beginX, iterator middleX, iterator endX)
			// {
			// 	std::cout << "-> " << *beginX << std::endl;
			// 	std::cout << "-> " << *middleX << std::endl;
			// 	std::cout << "-> " << *endX << std::endl << std::endl;

			// 	// iterator begin2  = begin;
			// 	// // iterator middle2 = middle; 
			// 	// iterator end2     = end;

			// 	while (beginX != middleX)
			// 	{
			// 		while (*beginX < *middleX)
			// 		{
			// 			std::cout << "------------------------ BeginX (" << *beginX << ") < MiddleX(" << *middleX << ")" << std::endl;
			// 			beginX++;
			// 		}
					
			// 		std::cout << std::endl << "BeginX (" << *beginX << ") > MiddleX (" << *middleX << ")" << std::endl;
					
			// 		while (endX != middleX)
			// 		{
			// 			while (*endX > *middleX)
			// 			{
			// 				std::cout << "------------------------   EndX (" << *endX << ") > MiddleX(" << *middleX << ")" << std::endl;
			// 				endX--;
			// 			}
						
			// 			if (endX != middleX)
			// 			{
			// 				std::cout << std::endl << "  EndX (" << *endX << ") < MiddleX (" << *middleX << ")" << std::endl;
			// 				std::cout << std::endl << "CHANGE " << *endX << " AND " << *beginX << std::endl;
							
			// 				ft::itemswap(beginX.getptr()->data, endX.getptr()->data);
			// 				beginX++;
			// 				endX--;			
												
			// 				break ;
			// 			}
			// 			else
			// 			{
			// 				// endX++;
			// 				// middleX.getptr()->next->pre = beginX.getptr();
			// 				// middleX.getptr()->next = beginX.getptr();
							 

							
			// 				// beginX.getptr()->next->pre = beginX.getptr()->pre;
			// 				// beginX.getptr()->pre = beginX.getptr()->next->pre;

			// 				// beginX.getptr() = middleX.getptr()->next 
							

			// 				return;
			// 			}
						
						
			// 		}
			// 		beginX++;
			// 	}
			// 	// if ()
			// }



			// void sort() // var1
			// {
			// 	int size = ((int)_Tail->data / 2);
			// 	iterator middle = begin();
			// 	while (size--)
			// 		middle++;
					
			// 	sortExtra(begin(), middle, (end()--));
			// }
