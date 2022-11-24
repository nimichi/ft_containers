/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:41:12 by mnies             #+#    #+#             */
/*   Updated: 2022/11/24 05:10:02 by mnies            ###   ########.fr       */
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

	template<typename T>
	class vector_iterator
	{
		public:
			typedef T                   value_type;
			typedef ptrdiff_t           difference_type;
			typedef T*                  pointer;
			typedef T&                  reference;
			typedef input_iterator_tag  iterator_category;

			vector_iterator(){

			}

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

	template<typename T>
	class vector_input_iterator : public vector_iterator<T>
	{
		public:
			bool operator==(const vector_input_iterator& other) const {
				return(this->_ptr == other._ptr);
			}
	};

	template<typename T>
	class vector_random_access_iterator_iterator : public vector_iterator<T>
	{
		public:
			vector_random_access_iterator_iterator(){

			}

			vector_random_access_iterator_iterator(const typename vector_iterator<T>::pointer ptr){
				this->_ptr = ptr;
			}

			vector_random_access_iterator_iterator(const vector_random_access_iterator_iterator& other){
				this->_ptr = other._ptr;
			}

			bool operator==(const vector_random_access_iterator_iterator<T>& other) const {
				return(this->_ptr == other._ptr);
			}

			bool operator!=(const vector_random_access_iterator_iterator<T>& other) const {
				return(this->_ptr != other._ptr);
			}

			typename vector_iterator<T>::difference_type operator-(const vector_random_access_iterator_iterator<T>& other) const {
				return(this->_ptr - other._ptr);
			}

			typename vector_iterator<T>::difference_type operator+(const vector_random_access_iterator_iterator<T>& other) const {
				return(this->_ptr + other._ptr);
			}

			vector_random_access_iterator_iterator<T> operator+(const typename vector_iterator<T>::difference_type& other){
				this->_ptr = this->_ptr + other;
				return(*this);
			}

			vector_random_access_iterator_iterator<T> & operator++(){
				this->_ptr++;
				return (*this);
			}

			vector_random_access_iterator_iterator<T> operator++(int){
				vector_random_access_iterator_iterator<T>	temp;
				temp = *this;
				++*this;
				return (temp);
			}

			vector_random_access_iterator_iterator<T> & operator--(){
				this->_ptr--;
				return (*this);
			}

			vector_random_access_iterator_iterator<T> operator--(int){
				vector_random_access_iterator_iterator<T>	temp;
				temp = *this;
				--*this;
				return (temp);
			}
	};
} // namespace ft



