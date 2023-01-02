/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 06:56:27 by mnies             #+#    #+#             */
/*   Updated: 2022/12/28 12:59:58 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft{
	template<bool, class InType = void>
	struct enable_if {};

	template <class InType>
	struct enable_if<true, InType> {
		typedef InType type;
	};
}