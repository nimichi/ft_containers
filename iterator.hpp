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

	template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class iterator
	{
		public:
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
		private:
			pointer _ptr;
		public:
			iterator()
			{

			}

			iterator(pointer ptr) : _ptr(ptr)
			{

			}

			template <class type>
			iterator(const iterator<iterator_category, type> &iter) : _ptr(iter.base())
			{

			}

			iterator& operator=(const iterator& other)
			{
				if (this != &other)
				{
					_ptr = other._ptr;
				}
				return *this;
			}

			~iterator()
			{

			}

			reference operator*() const
			{
				return *_ptr;
			}

			pointer operator->() const
			{
				return (pointer)std::addressof(*_ptr);
			}

			iterator& operator++()
			{
				++_ptr;
				return *this;
			}

			iterator operator++(int)
			{
				iterator temp(*this);
				++(*this);
				return temp;
			}

			iterator& operator--()
			{
				--_ptr;
				return *this;
			}

			iterator operator--(int)
			{
				iterator temp(*this);
				--(*this);
				return temp;
			}

			iterator operator+ (difference_type diff) const
			{
				iterator temp(*this);
				temp += diff;
				return temp;
			}

			iterator& operator+=(difference_type diff)
			{
				_ptr += diff;
				return *this;
			}

			iterator operator-(difference_type diff) const
			{
				return *this + (-diff);
			}

			iterator& operator-=(difference_type diff)
			{
				*this += -diff;
				return *this;
			}

			reference operator[](difference_type diff) const
			{
				return _ptr[diff];
			}

			pointer base() const
			{
				return _ptr;
			}

		private:

			template <class type1, class type2>
			friend bool operator==(const iterator<random_access_iterator_tag, type1>& lhs, const iterator<random_access_iterator_tag, type2>& rhs);

			template <class type1, class type2>
			friend bool operator!=(const iterator<random_access_iterator_tag, type1>& lhs, const iterator<random_access_iterator_tag, type2>& rhs);

			template <class type1, class type2>
			friend bool operator<=(const iterator<random_access_iterator_tag, type1>& lhs, const iterator<random_access_iterator_tag, type2>& rhs);

			template <class type1, class type2>
			friend bool operator>=(const iterator<random_access_iterator_tag, type1>& lhs, const iterator<random_access_iterator_tag, type2>& rhs);

			template <class type1, class type2>
			friend bool operator<(const iterator<random_access_iterator_tag, type1>& lhs, const iterator<random_access_iterator_tag, type2>& rhs);

			template <class type1, class type2>
			friend bool operator>(const iterator<random_access_iterator_tag, type1>& lhs, const iterator<random_access_iterator_tag, type2>& rhs);

			template <class type1, class type2>
			friend typename iterator<random_access_iterator_tag, type1>::difference_type operator-(const iterator<random_access_iterator_tag, type1>& lhs, const iterator<random_access_iterator_tag, type2>& rhs);

			template <class type>
			friend iterator<random_access_iterator_tag, type> operator+(typename iterator<random_access_iterator_tag, type>::difference_type lhs, iterator<random_access_iterator_tag, type>& rhs);


	};

	template <class type1, class type2>
	bool operator==(const iterator<random_access_iterator_tag, type1>& lhs, const iterator<random_access_iterator_tag, type2>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class type1, class type2>
	bool operator!=(const iterator<random_access_iterator_tag, type1>& lhs, const iterator<random_access_iterator_tag, type2>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class type1, class type2>
	bool operator<=(const iterator<random_access_iterator_tag, type1>& lhs, const iterator<random_access_iterator_tag, type2>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <class type1, class type2>
	bool operator>=(const iterator<random_access_iterator_tag, type1>& lhs, const iterator<random_access_iterator_tag, type2>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <class type1, class type2>
	bool operator<(const iterator<random_access_iterator_tag, type1>& lhs, const iterator<random_access_iterator_tag, type2>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <class type1, class type2>
	bool operator>(const iterator<random_access_iterator_tag, type1>& lhs, const iterator<random_access_iterator_tag, type2>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <class type1, class type2>
	typename iterator<random_access_iterator_tag, type1>::difference_type operator-(const iterator<random_access_iterator_tag, type1>& lhs, const iterator<random_access_iterator_tag, type2>& rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template <class type>
	iterator<random_access_iterator_tag, type> operator+(typename iterator<random_access_iterator_tag, type>::difference_type lhs, iterator<random_access_iterator_tag, type>& rhs)
	{
		return (rhs + lhs);
	}

	template <class Iterator>
	class reverse_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category, typename iterator_traits<Iterator>::value_type>
	{
	protected:
		Iterator _iter;
	public:
		typedef Iterator											iterator_type;
		typedef typename iterator_traits<Iterator>::difference_type	difference_type;
		typedef typename iterator_traits<Iterator>::reference		reference;
		typedef typename iterator_traits<Iterator>::pointer			pointer;

		reverse_iterator(){

		}

		reverse_iterator(Iterator x){
			_iter = x;
		}

		template <class U>
		reverse_iterator(const reverse_iterator<U>& u) : _iter(u.base())
		{
		}

		template <class U>
		reverse_iterator& operator=(const reverse_iterator<U>& u)
		{
			_iter = u.base();
			return *this;
		}

		iterator_type base() const
		{
			return(_iter);
		}

		reference operator*() const
		{
			Iterator ret = _iter;
			return *--ret;
		}

		pointer operator->() const{
			return (pointer)std::addressof(operator*());
		}

		reverse_iterator& operator++()
		{
			--_iter;
			return *this;
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator temp(*this);
			++(*this);
			return temp;
		}

		reverse_iterator& operator--()
		{
			++_iter;
			return *this;
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator temp(*this);
			--(*this);
			return temp;
		}

		reverse_iterator operator+(difference_type n) const
		{
			return reverse_iterator(_iter - n);
		}

		reverse_iterator& operator+=(difference_type n)
		{
			_iter -= n;
			return *this;
		}

		reverse_iterator operator-(difference_type n) const
		{
			return reverse_iterator(_iter + n);
		}


		reverse_iterator& operator-=(difference_type n)
		{
			_iter += n;
			return *this;
		}

		reference operator[](difference_type n) const
		{
			return *(*this + n);
		}

	};

	template <class Iterator1, class Iterator2>
	bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class Iterator1, class Iterator2>
	bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& it )
	{
		return reverse_iterator<Iterator>(it.base() - n);
	}

	template <class Iterator1, class Iterator2>
	typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return (rhs.base() - lhs.base());
	}

} // namespace ft