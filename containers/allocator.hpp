/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:14:10 by gbroccol          #+#    #+#             */
/*   Updated: 2021/05/20 16:15:53 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATOR_HPP
# define ALLOCATOR_HPP

namespace ft
{

	template <typename T>
	class allocator : public std::allocator<T>
	{
		public:

			typedef T			value_type;
			typedef T* 			pointer;
			typedef T& 			reference;
			typedef const T* 	const_pointer;
			typedef const T&	const_reference;
			typedef size_t		size_type;
					
			template <class U>	struct rebind { typedef allocator <U> other; }; // Its member type other is the equivalent allocator type to allocate elements of type Type

// CONSTRUCTOR
			allocator() throw() {}
			
			// allocator (const allocator& alloc) throw() {}

			// template <class U>
			// allocator (const allocator<U>& alloc) throw();

// DESTRUCTOR
			~allocator () throw() {}
			
// METHODS
			pointer address ( reference x ) const { return &x; }
			// const_pointer address ( const_reference x ) const { return &x; }

			pointer allocate (size_type n, const void* = 0)
			{
				pointer ret = (pointer)(::operator new(n * sizeof(T)));
				return ret;
			}

			void deallocate (pointer p, size_type n)
			{
				if (n)
					::operator delete((void*)p);
				else
					::operator delete((void*)p);
			}

			size_type max_size() const throw() { return std::numeric_limits<std::size_t>::max() / sizeof(T); }

			void construct ( pointer p, const_reference val ) { new((void*)p)T(val); }

			void destroy (pointer p) { p->~T(); }
	};

}
#endif
