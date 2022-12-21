template <class _Iter>
class iterator
{
	public:
		typedef _Iter														iterator_type;
		typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef typename iterator_traits<iterator_type>::value_type			value_type;
		typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename iterator_traits<iterator_type>::pointer			pointer;
		typedef typename iterator_traits<iterator_type>::reference			reference;
	private:
		iterator_type __i;
	public:
		iterator()
	
		template <class _Up>
		iterator(const iterator<_Up> &__u, typename enable_if<is_convertible<_Up, iterator_type>::value>::type* = 0) : __i(__u.base())
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
	
		iterator& operator++()
		{
			++__i;
			return *this;
		}
	
		iterator operator++(int)
		{
			iterator __tmp(*this);
			 ++(*this); return __tmp;
		}
	
		iterator& operator--()
		{
			--__i;
			return *this;
		}
	
		iterator operator--(int)
		{
			iterator __tmp(*this);
			--(*this);
			return __tmp;
		}
	
		iterator operator+ (difference_type __n) const
		{
			iterator __w(*this);
			__w += __n;
			return __w;
		}
	
		iterator& operator+=(difference_type __n)
		{
			__i += __n;
			return *this;
		}
	
		iterator operator- (difference_type __n) const
		{
			return *this + (-__n);
		}
	
		iterator& operator-=(difference_type __n)
		{
			*this += -__n;
			return *this;
		}
	
		reference operator[](difference_type __n) const
		{
			return __i[__n];
		}
	
		iterator_type base() const
		{
			return __i;
		}
	
	private:
		iterator(iterator_type __x) : __i(__x) {}
	
		// template <class _Up> friend class iterator;
		// template <class _CharT, class _Traits, class _Alloc> friend class basic_string;
		// template <class _Tp, class _Alloc> friend class _LIBCPP_TEMPLATE_VIS vector;
		// template <class _Tp, size_t> friend class _LIBCPP_TEMPLATE_VIS span;
	
		template <class _Iter1, class _Iter2>
		friend bool operator==(const iterator<_Iter1>&, const iterator<_Iter2>&);
	
		template <class _Iter1, class _Iter2>
		friend bool operator<(const iterator<_Iter1>&, const iterator<_Iter2>&);
	
		template <class _Iter1, class _Iter2>
		friend bool operator!=(const iterator<_Iter1>&, const iterator<_Iter2>&);
	
		template <class _Iter1, class _Iter2>
		friend bool operator>(const iterator<_Iter1>&, const iterator<_Iter2>&);
	
		template <class _Iter1, class _Iter2>
		friend bool operator>=(const iterator<_Iter1>&, const iterator<_Iter2>&);
	
		template <class _Iter1, class _Iter2>
		friend bool operator<=(const iterator<_Iter1>&, const iterator<_Iter2>&);
	
		template <class _Iter1, class _Iter2>
		friend auto operator-(const iterator<_Iter1>& __x, const iterator<_Iter2>& __y)
		-> decltype(__x.base() - __y.base());
	
		template <class _Iter1>
		friend iterator<_Iter1> operator+(typename iterator<_Iter1>::difference_type, iterator<_Iter1>);
	
		// template <class _Ip, class _Op> friend _LIBCPP_CONSTEXPR_AFTER_CXX17 _Op copy(_Ip, _Ip, _Op);
		// template <class _B1, class _B2> friend _LIBCPP_CONSTEXPR_AFTER_CXX17 _B2 copy_backward(_B1, _B1, _B2);
		// template <class _Ip, class _Op> friend _Op move(_Ip, _Ip, _Op);
		// template <class _B1, class _B2> friend _B2 move_backward(_B1, _B1, _B2);
	
		// template <class _Tp>
		// friend typename enable_if<is_trivially_copy_assignable<_Tp>::value, _Tp*>::type __unwrap_iter(iterator<_Tp*>);
};

template <class _Iter1, class _Iter2>
bool operator==(const iterator<_Iter1>& __x, const iterator<_Iter2>& __y)
{
	return __x.base() == __y.base();
}

template <class _Iter1, class _Iter2>
bool operator<(const iterator<_Iter1>& __x, const iterator<_Iter2>& __y)
{
	return __x.base() < __y.base();
}

template <class _Iter1, class _Iter2>
bool operator!=(const iterator<_Iter1>& __x, const iterator<_Iter2>& __y)
{
	return !(__x == __y);
}

template <class _Iter1, class _Iter2>
bool operator>(const iterator<_Iter1>& __x, const iterator<_Iter2>& __y)
{
	return __y < __x;
}

template <class _Iter1, class _Iter2>
bool operator>=(const iterator<_Iter1>& __x, const iterator<_Iter2>& __y)
{
	return !(__x < __y);
}

template <class _Iter1, class _Iter2>
bool operator<=(const iterator<_Iter1>& __x, const iterator<_Iter2>& __y)
{
	return !(__y < __x);
}

template <class _Iter1>
bool operator!=(const iterator<_Iter1>& __x, const iterator<_Iter1>& __y)
{
	return !(__x == __y);
}

template <class _Iter1>
bool operator>(const iterator<_Iter1>& __x, const iterator<_Iter1>& __y)
{
	return __y < __x;
}

template <class _Iter1>
bool operator>=(const iterator<_Iter1>& __x, const iterator<_Iter1>& __y)
{
	return !(__x < __y);
}

template <class _Iter1>
bool operator<=(const iterator<_Iter1>& __x, const iterator<_Iter1>& __y)
{
	return !(__y < __x);
}

template <class _Iter1, class _Iter2>
auto operator-(const iterator<_Iter1>& __x, const iterator<_Iter2>& __y)
-> decltype(__x.base() - __y.base())
{
	return __x.base() - __y.base();
}

template <class _Iter>
iterator<_Iter> operator+(typename iterator<_Iter>::difference_type __n, iterator<_Iter> __x)
{
	__x += __n;
	return __x;
}