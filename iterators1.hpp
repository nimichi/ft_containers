/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:41:12 by mnies             #+#    #+#             */
/*   Updated: 2022/12/14 20:46:12 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	struct input_iterator_tag  {};
	struct output_iterator_tag {};
	struct forward_iterator_tag       : public input_iterator_tag         {};
	struct bidirectional_iterator_tag : public forward_iterator_tag       {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template<class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template<class T>
	struct typename iterator_traits<T>
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef random_access_iterator_tag iterator_category;
	};

	template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class iterator_f
	{
		public:
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
		private:
			T __i;
		public:
			iterator_f()
			{

			}

			template <class _Up>
			iterator_f(const iterator_f<iterator_category, _Up> &__u) : __i(__u.base())
			{

			}

			reference operator*() const
			{
				return *__i;
			}

			pointer operator->() const
			{
				return (pointer)_VSTD::addressof(*__i);
			}

			iterator_f& operator++()
			{
				++__i;
				return *this;
			}

			iterator_f operator++(int)
			{
				iterator_f __tmp(*this);
				++(*this);
				return __tmp;
			}

			iterator_f& operator--()
			{
				--__i;
				return *this;
			}

			iterator_f operator--(int)
			{
				iterator_f __tmp(*this);
				--(*this);
				return __tmp;
			}

			iterator_f operator+ (difference_type __n) const
			{
				iterator_f __w(*this);
				__w += __n;
				return __w;
			}

			iterator_f& operator+=(difference_type __n)
			{
				__i += __n;
				return *this;
			}

			iterator_f operator- (difference_type __n) const
			{
				return *this + (-__n);
			}

			iterator_f& operator-=(difference_type __n)
			{
				*this += -__n;
				return *this;
			}

			reference operator[](difference_type __n) const
			{
				return __i[__n];
			}

			T base() const
			{
				return __i;
			}

		private:
			iterator_f(T __x) : __i(__x) {}

			// template <class _Up> friend class iterator;
			// template <class _CharT, class _Traits, class _Alloc> friend class basic_string;
			// template <class _Tp, class _Alloc> friend class _LIBCPP_TEMPLATE_VIS vector;
			// template <class _Tp, size_t> friend class _LIBCPP_TEMPLATE_VIS span;

			// template <class T1>
			// friend bool operator==(const iterator_f<iterator_category, T1>&, const iterator_f<iterator_category, T1>&);

			// template <class T1>
			// friend bool operator<(const iterator_f<iterator_category, T1>&, const iterator_f<iterator_category, T1>&);

			// template <class T1>
			// friend bool operator!=(const iterator_f<iterator_category, T1>&, const iterator_f<iterator_category, T1>&);

			// template <class T1>
			// friend bool operator>(const iterator_f<iterator_category, T1>&, const iterator_f<iterator_category, T1>&);

			// template <class T1>
			// friend bool operator>=(const iterator_f<iterator_category, T1>&, const iterator_f<iterator_category, T1>&);

			// template <class T1>
			// friend bool operator<=(const iterator_f<iterator_category, T1>&, const iterator_f<iterator_category, T1>&);

			// template <class T1>
			// friend iterator_f<iterator_category, T>  operator-(const iterator_f<iterator_category, T1>& __x, const iterator_f<iterator_category, T1>& __y);

			// template <class T1>
			// friend iterator_f<iterator_category, T1> operator+(typename iterator_f<iterator_category, T1>::difference_type, iterator_f<iterator_category, T1>);

			// template <class _Ip, class _Op> friend _LIBCPP_CONSTEXPR_AFTER_CXX17 _Op copy(_Ip, _Ip, _Op);
			// template <class _B1, class _B2> friend _LIBCPP_CONSTEXPR_AFTER_CXX17 _B2 copy_backward(_B1, _B1, _B2);
			// template <class _Ip, class _Op> friend _Op move(_Ip, _Ip, _Op);
			// template <class _B1, class _B2> friend _B2 move_backward(_B1, _B1, _B2);

			// template <class _Tp>
			// friend typename enable_if<is_trivially_copy_assignable<_Tp>::value, _Tp*>::type __unwrapT(iterator<iterator_category, _Tp*>);
	};

	// template <class T1>
	// bool operator==(const iterator_f<typename iterator_traits<T1>::iterator_category, T1>& __x, const iterator_f<typename iterator_traits<T1>::iterator_category, T1>& __y)
	// {
	// 	return __x.base() == __y.base();
	// }

	// template <class T1>
	// bool operator<(const iterator_f<typename iterator_traits<T1>::iterator_category, T1>& __x, const iterator_f<typename iterator_traits<T1>::iterator_category, T1>& __y)
	// {
	// 	return __x.base() < __y.base();
	// }

	// template <class T1>
	// bool operator!=(const iterator_f<typename iterator_traits<T1>::iterator_category, T1>& __x, const iterator_f<typename iterator_traits<T1>::iterator_category, T1>& __y)
	// {
	// 	return !(__x == __y);
	// }

	// template <class T1>
	// bool operator>(const iterator_f<typename iterator_traits<T1>::iterator_category, T1>& __x, const iterator_f<typename iterator_traits<T1>::iterator_category, T1>& __y)
	// {
	// 	return __y < __x;
	// }

	// template <class T1>
	// bool operator>=(const iterator_f<typename iterator_traits<T1>::iterator_category, T1>& __x, const iterator_f<typename iterator_traits<T1>::iterator_category, T1>& __y)
	// {
	// 	return !(__x < __y);
	// }

	// template <class T1>
	// bool operator<=(const iterator_f<typename iterator_traits<T1>::iterator_category, T1>& __x, const iterator_f<typename iterator_traits<T1>::iterator_category, T1>& __y)
	// {
	// 	return !(__y < __x);
	// }

	// template <class T1>
	// bool operator!=(const iterator_f<typename iterator_traits<T1>::iterator_category, T1>& __x, const iterator_f<typename iterator_traits<T1>::iterator_category, T1>& __y)
	// {
	// 	return !(__x == __y);
	// }

	// template <class T1>
	// bool operator>(const iterator_f<typename iterator_traits<T1>::iterator_category, T1>& __x, const iterator_f<typename iterator_traits<T1>::iterator_category, T1>& __y)
	// {
	// 	return __y < __x;
	// }

	// template <class T1>
	// bool operator>=(const iterator_f<typename iterator_traits<T1>::iterator_category, T1>& __x, const iterator_f<typename iterator_traits<T1>::iterator_category, T1>& __y)
	// {
	// 	return !(__x < __y);
	// }

	// template <class T1>
	// bool operator<=(const iterator_f<typename iterator_traits<T1>::iterator_category, T1>& __x, const iterator_f<typename iterator_traits<T1>::iterator_category, T1>& __y)
	// {
	// 	return !(__y < __x);
	// }

	// template <class T1>
	// iterator_f<typename iterator_traits<T1>::iterator_category, T1>  operator-(const iterator_f<typename iterator_traits<T1>::iterator_category, T1>& __x, const iterator_f<typename iterator_traits<T1>::iterator_category, T1>& __y)
	// {
	// 	return __x.base() - __y.base();
	// }

	// template <class T>
	// iterator_f<typename iterator_traits<T1>::iterator_category, T> operator+(typename iterator_f<typename iterator_traits<T1>::iterator_category, T>::difference_type __n, iterator_f<typename iterator_traits<T1>::iterator_category, T> __x)
	// {
	// 	__x += __n;
	// 	return __x;
	// }

	template <class Iterator>
	class reverse_iterator : public iterator_f<typename iterator_traits<Iterator>::iterator_category, typename iterator_traits<Iterator>::value_type>
	{
	protected:
		Iterator current;
	public:
		typedef Iterator											iterator_type;
		typedef typename iterator_traits<Iterator>::difference_type	difference_type;
		typedef typename iterator_traits<Iterator>::reference		reference;
		typedef typename iterator_traits<Iterator>::pointer			pointer;

		reverse_iterator();

		explicit reverse_iterator(Iterator x);

		template <class U>
		reverse_iterator(const reverse_iterator<U>& u);

		template <class U>
		reverse_iterator& operator=(const reverse_iterator<U>& u);

		Iterator base() const;

		reference operator*() const;

		pointer operator->() const;

		reverse_iterator& operator++();

		reverse_iterator operator++(int);

		reverse_iterator& operator--();

		reverse_iterator operator--(int);

		reverse_iterator operator+ (difference_type n) const;

		reverse_iterator& operator+=(difference_type n);

		reverse_iterator operator- (difference_type n) const;

		reverse_iterator& operator-=(difference_type n);

		reference operator[](difference_type n) const;

	};

} // namespace ft



