#pragma once

#include <cstddef>

namespace ft
{

	// ENABLE_IF

	template<bool, class InType = void>
	struct enable_if {};

	template <class InType>
	struct enable_if<true, InType> {
		typedef InType type;
	};

	// PAIR AND MAKE_PAIR

	template <class first_type, class second_type>
	struct pair
	{
		typedef first_type	key_type;
		typedef second_type	mapped_type;

		first_type first;
		second_type second;

		pair() : first(), second() {}

		template<class f, class s>
		pair (const pair<f, s>& pair) : first(pair.first), second(pair.second) {}

		pair(first_type first, second_type second) : first(first), second(second) {}
	};


	template <class first_type, class second_type>
	pair<first_type, second_type> make_pair(first_type first, second_type second)
	{
		return pair<first_type, second_type>(first, second);
	}

	template <class T1, class T2>
	inline bool operator==(const pair<T1, T2>& x, const pair<T1, T2>& y)
	{
		return x.first == y.first && x.second == y.second;
	}

	template <class T1, class T2>
	inline bool operator!=(const pair<T1, T2>& x, const pair<T1, T2>& y)
	{
		return !(x == y);
	}

	template <class T1, class T2>
	inline bool operator<(const pair<T1, T2>& x, const pair<T1, T2>& y)
	{
		return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
	}

	template <class T1, class T2>
	inline bool operator<=(const pair<T1, T2>& x, const pair<T1, T2>& y)
	{
		return !(y < x);
	}

	template <class T1, class T2>
	inline bool operator>(const pair<T1, T2>& x, const pair<T1, T2>& y)
	{
		return y < x;
	}

	template <class T1, class T2>
	inline bool operator>=(const pair<T1, T2>& x, const pair<T1, T2>& y)
	{
		return !(x < y);
	}



	// LEXICOGRAPHICAL_COMPARE

	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2){
		while (1)
		{
			if (last1 < first1 && last2 < first2)
				return (false);
			if (last1 < first1)
				return (true);
			if (last2 < first2)
				return (false);
			if (first2.base() == NULL)
				return (false);
			if (first1.base() == NULL)
				return (true);
			if (*first1 < *first2)
				return (true);
			if (*first2 < *first1)
				return (false);
			first1++;
			first2++;
		}
	}



	// IS_INTEGRAL

	template <class InType>
	struct remove_const            {typedef InType type;};

	template <class InType>
	struct remove_const<const InType> {typedef InType type;};

	template <class InType>
	struct remove_volatile               {typedef InType type;};

	template <class InType>
	struct remove_volatile<volatile InType> {typedef InType type;};

	template <class T>    class i_is_integral                     : public std::false_type {};
	template <>           class i_is_integral<bool>               : public std::true_type {};
	template <>           class i_is_integral<char>               : public std::true_type {};
	template <>           class i_is_integral<signed char>        : public std::true_type {};
	template <>           class i_is_integral<unsigned char>      : public std::true_type {};
	template <>           class i_is_integral<wchar_t>            : public std::true_type {};
	template <>           class i_is_integral<char16_t>           : public std::true_type {};
	template <>           class i_is_integral<char32_t>           : public std::true_type {};
	template <>           class i_is_integral<short>              : public std::true_type {};
	template <>           class i_is_integral<unsigned short>     : public std::true_type {};
	template <>           class i_is_integral<int>                : public std::true_type {};
	template <>           class i_is_integral<unsigned int>       : public std::true_type {};
	template <>           class i_is_integral<long>               : public std::true_type {};
	template <>           class i_is_integral<unsigned long>      : public std::true_type {};
	template <>           class i_is_integral<long long>          : public std::true_type {};
	template <>           class i_is_integral<unsigned long long> : public std::true_type {};

	template <class InType>
	struct is_integral : public i_is_integral<typename remove_volatile<typename remove_const<InType>::type>::type > {};

	// ITERATOR_TRAITS

	typedef std::output_iterator_tag        output_iterator_tag;
	typedef std::input_iterator_tag         input_iterator_tag;
	typedef std::forward_iterator_tag       forward_iterator_tag;
	typedef std::bidirectional_iterator_tag bidirectional_iterator_tag;
	typedef std::random_access_iterator_tag random_access_iterator_tag;

	template<class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <typename T>
	struct iterator_traits<T*> {
		typedef T							value_type;
		typedef std::ptrdiff_t				difference_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template <typename Iterator>
	inline typename iterator_traits<Iterator>::iterator_category iterator_category(const Iterator&)
	{
		return typename iterator_traits<Iterator>::iterator_category();
	}

	// EQUAL

	template <typename InputIterator1, typename InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1) {
			if (!(*first1 == *first2)) return false;
			++first1;
			++first2;
		}
		return true;
	}
} // namespace ft