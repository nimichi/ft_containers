/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:40:58 by mnies             #+#    #+#             */
/*   Updated: 2022/11/15 01:39:57 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>

namespace ft {
	template <class T>
	class vector_iterator{
		public:
			//Member types
			typedef T         value_type;
			// typedef Distance  difference_type;
			// typedef Pointer   pointer;
			// typedef Reference reference;
			// typedef Category  iterator_category;

			//Member functions
			vector_iterator(){
				_ptr = NULL;
			}

			vector_iterator(const vector_iterator& other)
			{
				this = other;
			}

			vector_iterator operator=(const vector_iterator& other)
			{
				_ptr = other._ptr;
			}

			~vector_iterator(){

			}
		private:
			value_type* _ptr;
	};


	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			// //Member typdef
			// template< bool B, class T = void > struct enable_if;
			// template< class Iter > struct iterator_traits;
			// template< class T > struct iterator_traits<T*>;
			// template< class Iter > class reverse_iterator;
			// template< class T > struct is_integral;
			// // TODO compare
			// template< class T1, class T2 > struct pair;
			// template< class T1, class T2 > std::pair<T1, T2> make_pair( T1 t, T2 u );

			//Member types
			typedef T                                     value_type;
			typedef Allocator                             allocator_type;
			typedef size_t                                size_type;
			typedef ptrdiff_t                             difference_type;
			typedef value_type&                           reference;
			typedef const value_type&                     const_reference;
			typedef value_type*                           pointer;
			typedef const value_type*                     const_pointer;
			typedef vector_iterator<value_type>           iterator;
			// typedef typename MyConstIterator<value_type>           const_iterator;
			// typedef typename std::reverse_iterator<iterator>       reverse_iterator;
			// typedef typename std::reverse_iterator<const_iterator> const_reverse_iterator;

			//Member functions
			vector(void) : _begin(NULL), _end(NULL), _limit(NULL){

			}

			~vector(void){
				delete [] _begin;
			}

			// vector& operator=( const vector& other ); //inval
			// void assign( size_type count, const T& value ); //inval
			// allocator_type get_allocator() const;

			//	Element access
			reference at( size_type pos ){
				return (&_begin[pos]);
			}

			const_reference at( size_type pos ) const{
				return (&_begin[pos]);
			}

			reference operator[]( size_type pos ){
				return (&_begin[pos]);
			}

			const_reference operator[]( size_type pos ) const{
				return (&_begin[pos]);
			}

			reference front(){
				return (_begin);
			}

			const_reference front() const{
				return (_begin);
			}

			reference back(){
				return (_end);
			}

			const_reference back() const{
				return (_end);
			}

			value_type* data(){
				return (_begin);
			}

			const value_type* data() const{
				return (_begin);
			}

			//	Capacity
			bool empty() const{
				if (_begin + 1 == _end || _begin == NULL)
					return (true);
				return (false);
			}

			size_type size() const{
				if (_begin == NULL)
					return (0);
				return (_end - 1 - _begin);
			}

			size_type max_size() const{
				return ((0x2^32)/sizeof(value_type) - 1);
			}

			void reserve( size_type new_cap ){
				if (new_cap <= capacity())
					return;
				enlarge(new_cap);
			} //inval

			size_type capacity() const{
				if (_begin == NULL)
					return (0);
				return (_limit - 1 - _begin);
			}

			// //	Moifiers
			// void clear(); //inval
			// iterator insert( const_iterator pos, const T& value ); //inval
			// iterator insert( const_iterator pos, size_type count, const T& value ); //inval
			// constexpr iterator insert( const_iterator pos, size_type count, const T& value ); //inval
			// template< class InputIt > iterator insert( const_iterator pos, InputIt first, InputIt last ); //inval
			// iterator erase( iterator pos ); //inval
			// iterator erase( iterator first, iterator last ); //inval
			void push_back( const value_type& value ){
				if (_end == _limit)
					enlarge();
				_end = new value_type(value);
				_end++;
			} //inval

			void pop_back(){
				if (_begin != _end)
					_end--;
			} //inval

			void resize( size_type count, value_type value = value_type() ){
				if (count == 0)
				{
					delete [] _begin;
					_begin = NULL;
					_end = NULL;
					_limit = NULL;
					return;
				}
				enlarge(count);
				while (_end != _limit)
				{
					*_end = value;
					_end++;
				}
			} //inval

			void swap( vector& other ){
				value_type *temp;

				temp = other._begin();
				other._begin = _begin;
				_begin = temp;
				temp = other._end();
				other._end = _end;
				_end = temp;
				temp = other._limit();
				other._limit = _limit;
				_limit = temp;
			} //inval

		private:
			value_type* _begin;
			value_type* _end;
			value_type* _limit;

			void enlarge(size_type new_cap = 0){
				value_type*		temp_ptr;

				if(size() == 0 && new_cap == 0)
					new_cap = 0;
				else if (new_cap == 0)
				{
					if (size() < max_size() / 2)
						new_cap = size() * 2;
					else if (new_cap == max_size())
						throw std::bad_alloc();
					else
						new_cap =  max_size();
				}
				temp_ptr = new value_type[new_cap];
				size_type i = size();
				while (i != 0)
				{
					i--;
					temp_ptr[i] = _begin[i];
				}
				_limit = temp_ptr + new_cap + 1;
				_end = temp_ptr + size() + 1;
				delete [] _begin;
				_begin = temp_ptr;
			}
	};
	// template< class T, class Allocator > bool operator==( const std::vector<T,Allocator>& lhs, const std::vector<T,Allocator>& rhs );
	// template< class T, class Allocator > bool operator!=( const std::vector<T,Allocator>& lhs, const std::vector<T,Allocator>& rhs );
	// template< class T, class Allocator > bool operator<( const std::vector<T,Allocator>& lhs, const std::vector<T,Allocator>& rhs );
	// template< class T, class Allocator > bool operator<=( const std::vector<T,Allocator>& lhs, const std::vector<T,Allocator>& rhs );
	// template< class T, class Allocator > bool operator>( const std::vector<T,Allocator>& lhs, const std::vector<T,Allocator>& rhs );
	// template< class T, class Allocator > bool operator>=( const std::vector<T,Allocator>& lhs, const std::vector<T,Allocator>& rhs );
	// template< class T, class Allocator > void swap( std::vector<T,Allocator>& lhs, std::vector<T,Allocator>& rhs );
}
