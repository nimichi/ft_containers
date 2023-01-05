/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 06:46:52 by mnies             #+#    #+#             */
/*   Updated: 2023/01/05 17:20:02 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {
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
}
