/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:11:27 by gbroccol          #+#    #+#             */
/*   Updated: 2021/04/26 19:54:47 by gbroccol         ###   ########.fr       */
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
	int distance(Iterator first, Iterator last)
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




		template <typename T>
    	class allocator: public std::allocator<T>
    	{
			public:
			
                typedef size_t size_type;
                typedef T* pointer;
                typedef const T* const_pointer;

                template<typename _Tp1>
                struct rebind
                {
                	typedef allocator<_Tp1> other;
                };

                pointer allocate(size_type n, const void *hint=0)
                {
                	return std::allocator<T>::allocate(n, hint);
                }

                void deallocate(pointer p, size_type n)
                {
                    return std::allocator<T>::deallocate(p, n);
                }

                allocator() throw(): std::allocator<T>() { fprintf(stderr, "Hello allocator!\n"); }
                allocator(const allocator &a) throw(): std::allocator<T>(a) { }
                
				template <class U>                    
                allocator(const allocator<U> &a) throw(): std::allocator<T>(a) { }
                ~allocator() throw() { }
        };
}

#endif
