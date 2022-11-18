/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:41:12 by mnies             #+#    #+#             */
/*   Updated: 2022/11/18 18:54:40 by mnies            ###   ########.fr       */
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

	template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class vector_iterator
	{
		public:
			typedef T         value_type;
			typedef Distance  difference_type;
			typedef Pointer   pointer;
			typedef Reference reference;
			typedef Category  iterator_category;

			vector_iterator(const vector_iterator& other) : _ptr(other._ptr){

			}

			~vector_iterator(){

			}

			vector_iterator operator=(const vector_iterator& other){
				_ptr = other._ptr;
				return (*this);
			}

			reference operator*(void) const {
				return (*_ptr);
			}

			vector_iterator& operator++(){
				_ptr++;
				return (*this);
			}

		protected:
			pointer _ptr;
	};

	template<class T>
	class vector_input_iterator : public vector_iterator<input_iterator_tag ,T>
	{
		public:
			typedef typename vector_iterator<input_iterator_tag ,T>::value_type        value_type;
			typedef typename vector_iterator<input_iterator_tag ,T>::difference_type   difference_type;
			typedef typename vector_iterator<input_iterator_tag ,T>::pointer           pointer;
			typedef typename vector_iterator<input_iterator_tag ,T>::reference         reference;
			typedef typename vector_iterator<input_iterator_tag ,T>::iterator_category iterator_category;

			bool operator==(const vector_input_iterator& other) const {
				return(this->_ptr == other._ptr);
			}
	};

	template<class T>
	class vector_random_access_iterator_iterator : public vector_iterator<random_access_iterator_tag ,T>
	{
		public:
			typedef typename vector_iterator<random_access_iterator_tag ,T>::value_type        value_type;
			typedef typename vector_iterator<random_access_iterator_tag ,T>::difference_type   difference_type;
			typedef typename vector_iterator<random_access_iterator_tag ,T>::pointer           pointer;
			typedef typename vector_iterator<random_access_iterator_tag ,T>::reference         reference;
			typedef typename vector_iterator<random_access_iterator_tag ,T>::iterator_category iterator_category;

			vector_random_access_iterator_iterator(const pointer ptr){
				_ptr = ptr;
			}

			vector_random_access_iterator_iterator(const vector_random_access_iterator_iterator& other){
				_ptr == other._ptr
			}

			bool operator==(const vector_input_iterator<T>& other) const {
				return(this->_ptr == other._ptr);
			}
	};
} // namespace ft



