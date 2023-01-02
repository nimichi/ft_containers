/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:03:53 by mnies             #+#    #+#             */
/*   Updated: 2022/12/29 16:07:39 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{

	template <class first_type, class second_type>
	struct pair
	{
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
} // namespace ft
