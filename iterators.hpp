/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:41:12 by mnies             #+#    #+#             */
/*   Updated: 2022/11/25 02:20:24 by mnies            ###   ########.fr       */
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

	template<typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
		class iterator
		{
			public:
				typedef T			value_type;
				typedef Distance	difference_type;
				typedef Pointer		pointer;
				typedef Reference	reference;
				typedef Category	iterator_category;

				iterator(){

				}

				iterator(const iterator& other) : _ptr(other._ptr){

				}

				~iterator(){

				}

				iterator operator=(const iterator& other){
					_ptr = other._ptr;
					return (*this);
				}

				reference operator*(void) const {
					return (*_ptr);
				}

				iterator& operator++(){
					_ptr++;
					return (*this);
				}

			protected:
				pointer _ptr;
		};

	template<typename T>
		struct input_iterator : public iterator<input_iterator_tag, T>
		{
			public:
				bool operator==(const input_iterator& other) const {
					return(this->_ptr == other._ptr);
				}
		};


	template<typename T>
	class random_access_iterator : public iterator<random_access_iterator_tag, T>
	{
		public:
			random_access_iterator(){

			}

			random_access_iterator(const typename iterator<random_access_iterator_tag, T>::pointer ptr){
				this->_ptr = ptr;
			}

			random_access_iterator(const random_access_iterator<T>& other){
				this->_ptr = other._ptr;
			}

			bool operator==(const random_access_iterator<T>& other) const {
				return(this->_ptr == other._ptr);
			}

			bool operator!=(const random_access_iterator<T>& other) const {
				return(this->_ptr != other._ptr);
			}

			typename iterator<random_access_iterator_tag ,T>::difference_type operator-(const random_access_iterator<T>& other) const {
				return(this->_ptr - other._ptr);
			}

			typename iterator<random_access_iterator_tag ,T>::difference_type operator+(const random_access_iterator<T>& other) const {
				return(this->_ptr + other._ptr);
			}

			random_access_iterator<T> operator+(const typename iterator<random_access_iterator_tag ,T>::difference_type& other){
				this->_ptr = this->_ptr + other;
				return(*this);
			}

			random_access_iterator<T> operator-(const typename iterator<random_access_iterator_tag ,T>::difference_type& other){
				this->_ptr = this->_ptr - other;
				return(*this);
			}

			random_access_iterator<T> & operator++(){
				this->_ptr++;
				return (*this);
			}

			random_access_iterator<T> operator++(int){
				random_access_iterator<T>	temp;
				temp = *this;
				++*this;
				return (temp);
			}

			random_access_iterator<T> & operator--(){
				this->_ptr--;
				return (*this);
			}

			random_access_iterator<T> operator--(int){
				random_access_iterator<T>	temp;
				temp = *this;
				--*this;
				return (temp);
			}
	};
} // namespace ft



