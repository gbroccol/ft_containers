/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:11:27 by gbroccol          #+#    #+#             */
/*   Updated: 2021/05/03 18:30:23 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRA_HPP
# define EXTRA_HPP

namespace ft
{
	template<typename Iterator>
	bool checkin(Iterator xBegin, Iterator xEnd, Iterator first)
	{
		if (xBegin.ptr == first.ptr)
			return true;
		
		while (xBegin != xEnd)
		{
			if (xBegin.ptr == first.ptr)
				return true;
			xBegin++;
		}
		return false;
	}

	template<typename Iterator>
	int distance_my(Iterator first, Iterator last)
	{
		int dist = 0;

		while (first != last)
		{
			++dist;
			++first;
		}
		return dist;
	}
	
	template< typename T >
	void	itemswap(T & value1, T & value2)
	{
		T tmp = value1;
		value1 = value2;
		value2 = tmp;
	}

	template<bool, typename T = void>
	struct enable_if
	{ };

	template<typename T>
	struct enable_if <true, T>
	{ typedef T type; };

	
	
}
#endif
