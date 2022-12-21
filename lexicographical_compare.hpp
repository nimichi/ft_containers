/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 09:06:32 by mnies             #+#    #+#             */
/*   Updated: 2022/12/18 09:32:04 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


namespace ft {
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
			if (*first1 < *first2)
				return (true);
			if (*first2 < *first1)
				return (false);
			first1++;
			first2++;
		}
	}
}
