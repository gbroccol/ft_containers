/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:14:10 by gbroccol          #+#    #+#             */
/*   Updated: 2021/05/03 15:23:42 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATOR_HPP
# define ALLOCATOR_HPP

namespace ft
{

// 	template <typename T>
// 	class allocator <void>
// 	{
// public:
//   typedef void* pointer;
//   typedef const void* const_pointer;
//   typedef void value_type;
//   template <class U> struct rebind { typedef allocator<U> other; };
// };

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

			// void deallocate (pointer p, size_type n);

			size_type max_size() const throw() { return std::numeric_limits<std::size_t>::max() / sizeof(T); }

			void construct ( pointer p, const_reference val ) { new((void*)p)T(val); }

			void destroy (pointer p) { p->~T(); }




			// pointer allocate(size_type n, const void *hint=0)
			// {
			// 	return std::allocator<T>::allocate(n, hint);
			// }

			// void deallocate(pointer p, size_type n)
			// {
			// 	return std::allocator<T>::deallocate(p, n);
			// }

			// allocator() throw(): std::allocator<T>() { fprintf(stderr, "Hello allocator!\n"); }
			// allocator(const allocator &a) throw(): std::allocator<T>(a) { }
			
			// template <class U>                    
			// allocator(const allocator<U> &a) throw(): std::allocator<T>(a) { }

	};

}
#endif




// template <class T>
	// class _LIBCPP_TEMPLATE_VIS allocator
	// {
	// public:
	// 	typedef size_t				size_type;
	// 	typedef ptrdiff_t			difference_type;
	// 	typedef T*					pointer;
	// 	typedef const T*			const_pointer;
	// 	typedef T&					reference;
	// 	typedef const T&			const_reference;
	// 	typedef T					value_type;

	// 	typedef true_type propagate_on_container_move_assignment;
	// 	typedef true_type is_always_equal;

	// 	template <class _Up> struct rebind {typedef allocator<_Up> other;};

	// 	_LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX17
	// 	allocator() _NOEXCEPT {}

	// 	template <class _Up>
	// 	_LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX17
	// 	allocator(const allocator<_Up>&) _NOEXCEPT {}

	// 	_LIBCPP_INLINE_VISIBILITY pointer address(reference __x) const _NOEXCEPT
	// 		{return _VSTD::addressof(__x);}
	// 	_LIBCPP_INLINE_VISIBILITY const_pointer address(const_reference __x) const _NOEXCEPT
	// 		{return _VSTD::addressof(__x);}
	// 	_LIBCPP_NODISCARD_AFTER_CXX17 _LIBCPP_INLINE_VISIBILITY
		// pointer allocate(size_type __n, allocator<void>::const_pointer = 0)
		// 	{
		// 	if (__n > max_size())
		// 		__throw_length_error("allocator<T>::allocate(size_t n)"
		// 							" 'n' exceeds maximum supported size");
		// 	return static_cast<pointer>(_VSTD::__libcpp_allocate(__n * sizeof(T), _LIBCPP_ALIGNOF(T)));
		// 	}
	// 	_LIBCPP_INLINE_VISIBILITY void deallocate(pointer __p, size_type __n) _NOEXCEPT
	// 		{_VSTD::__libcpp_deallocate((void*)__p, __n * sizeof(T), _LIBCPP_ALIGNOF(T));}
	// 	_LIBCPP_INLINE_VISIBILITY size_type max_size() const _NOEXCEPT
	// 		{return size_type(~0) / sizeof(T);}
	// #if !defined(_LIBCPP_HAS_NO_RVALUE_REFERENCES) && !defined(_LIBCPP_HAS_NO_VARIADICS)
	// 	template <class _Up, class... _Args>
	// 		_LIBCPP_INLINE_VISIBILITY
	// 		void
	// 		construct(_Up* __p, _Args&&... __args)
	// 		{
	// 			::new((void*)__p) _Up(_VSTD::forward<_Args>(__args)...);
	// 		}
	// #else  // !defined(_LIBCPP_HAS_NO_RVALUE_REFERENCES) && !defined(_LIBCPP_HAS_NO_VARIADICS)
	// 		_LIBCPP_INLINE_VISIBILITY
	// 		void
	// 		construct(pointer __p)
	// 		{
	// 			::new((void*)__p) T();
	// 		}
	// # if defined(_LIBCPP_HAS_NO_RVALUE_REFERENCES)

	// 	template <class _A0>
	// 		_LIBCPP_INLINE_VISIBILITY
	// 		void
	// 		construct(pointer __p, _A0& __a0)
	// 		{
	// 			::new((void*)__p) T(__a0);
	// 		}
	// 	template <class _A0>
	// 		_LIBCPP_INLINE_VISIBILITY
	// 		void
	// 		construct(pointer __p, const _A0& __a0)
	// 		{
	// 			::new((void*)__p) T(__a0);
	// 		}
	// # endif  // defined(_LIBCPP_HAS_NO_RVALUE_REFERENCES)
	
	// 	template <class _A0, class _A1>
	// 		_LIBCPP_INLINE_VISIBILITY
	// 		void
	// 		construct(pointer __p, _A0& __a0, _A1& __a1)
	// 		{
	// 			::new((void*)__p) T(__a0, __a1);
	// 		}
			
	// 	template <class _A0, class _A1>
	// 		_LIBCPP_INLINE_VISIBILITY
	// 		void
	// 		construct(pointer __p, const _A0& __a0, _A1& __a1)
	// 		{
	// 			::new((void*)__p) T(__a0, __a1);
	// 		}
			
	// 	template <class _A0, class _A1>
	// 		_LIBCPP_INLINE_VISIBILITY
	// 		void
	// 		construct(pointer __p, _A0& __a0, const _A1& __a1)
	// 		{
	// 			::new((void*)__p) T(__a0, __a1);
	// 		}

	// 		template <class _A0, class _A1>
	// 		_LIBCPP_INLINE_VISIBILITY
	// 		void
	// 		construct(pointer __p, const _A0& __a0, const _A1& __a1)
	// 		{
	// 			::new((void*)__p) T(__a0, __a1);
	// 		}
	// #endif  // !defined(_LIBCPP_HAS_NO_RVALUE_REFERENCES) && !defined(_LIBCPP_HAS_NO_VARIADICS)
	// 	_LIBCPP_INLINE_VISIBILITY void destroy(pointer __p) {__p->~T();}
	// };