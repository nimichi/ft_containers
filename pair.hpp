/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:03:53 by mnies             #+#    #+#             */
/*   Updated: 2023/01/05 03:09:18 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{

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
} // namespace ft
