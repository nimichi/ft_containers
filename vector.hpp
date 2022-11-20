/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:40:58 by mnies             #+#    #+#             */
/*   Updated: 2022/11/20 11:08:12 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <stdexcept>
#include "iterators.hpp"

namespace ft {
	// template <class T>
	// class vector_iterator{
	// 	public:
	// 		//Member types
	// 		typedef T								value_type;
	// 		typedef ptrdiff_t						difference_type;
	// 		typedef T*								pointer;
	// 		typedef T&								reference;
	// 		typedef std::random_access_iterator_tag	iterator_category;

	// 		//Member functions
	// 		vector_iterator() : _ptr(NULL){

	// 		}

	// 		vector_iterator(const pointer ptr) : _ptr(ptr)
	// 		{

	// 		}




	// 		~vector_iterator(){

	// 		}

	// 		bool operator==(const vector_iterator& other) const {
	// 			return(this->_ptr == other._ptr);
	// 		}

	// 		bool operator<(const vector_iterator& other) const {
	// 			return(this->_ptr < other._ptr);
	// 		}

	// 		bool operator!=(const vector_iterator& other) const {
	// 			return(this->_ptr != other._ptr);
	// 		}

	// 		bool operator>(const vector_iterator& other) const {
	// 			return(this->_ptr > other._ptr);
	// 		}

	// 		bool operator>=(const vector_iterator& other) const {
	// 			return(this->_ptr >= other._ptr);
	// 		}

	// 		bool operator<=(const vector_iterator& other) const {
	// 			return(this->_ptr <= other._ptr);
	// 		}

	// 		vector_iterator operator-(difference_type other) const {
	// 			return(_ptr - other);
	// 		}

	// 		value_type* operator*(){
	// 			return (_ptr);
	// 		}

	// 		vector_iterator& operator++(){
	// 			_ptr++;
	// 			return (*this);
	// 		}

	// 		vector_iterator operator++(int){
	// 			vector_iterator	temp;
	// 			temp = *this;
	// 			++*this;
	// 			return (temp);
	// 		}

	// 		vector_iterator& operator--(){
	// 			_ptr--;
	// 			return (*this);
	// 		}

	// 		vector_iterator operator--(int){
	// 			vector_iterator	temp;
	// 			temp = *this;
	// 			--*this;
	// 			return (temp);
	// 		}

	// 		// vector_iterator operator+(const vector_iterator& other){

	// 		// }

	// 		vector_iterator operator=(const vector_iterator& other)
	// 		{
	// 			_ptr = other._ptr;
	// 			return (*this);
	// 		}

	// 		reference operator*(void) const {
	// 			return (*_ptr);
	// 		}

	// 		vector_iterator	operator+(size_t count)
	// 		{
	// 			_ptr = _ptr + count;
	// 			return (*this);
	// 		}

	// 	private:
	// 		value_type* _ptr;
	// };

	// // template <class T>
	// // class vector_const_iterator{
	// 	public:
	// 		//Member types
	// 		typedef T								value_type;
	// 		typedef ptrdiff_t						difference_type;
	// 		typedef T*								pointer;
	// 		typedef T&								reference;
	// 		typedef std::random_access_iterator_tag	iterator_category;

	// 		//Member functions
	// 		vector_const_iterator() : _ptr(NULL){

	// 		}

	// 		vector_const_iterator(const pointer ptr) : _ptr(ptr)
	// 		{

	// 		}

	// 		vector_const_iterator(const vector_const_iterator& other) : _ptr(other._ptr)
	// 		{

	// 		}

	// 		~vector_const_iterator(){

	// 		}

	// 		bool operator==(const vector_const_iterator& other) const {
	// 			return(this->_ptr == other._ptr);
	// 		}

	// 		bool operator<(const vector_const_iterator& other) const {
	// 			return(this->_ptr < other._ptr);
	// 		}

	// 		bool operator!=(const vector_const_iterator& other) const {
	// 			return(this->_ptr != other._ptr);
	// 		}

	// 		bool operator>(const vector_const_iterator& other) const {
	// 			return(this->_ptr > other._ptr);
	// 		}

	// 		bool operator>=(const vector_const_iterator& other) const {
	// 			return(this->_ptr >= other._ptr);
	// 		}

	// 		bool operator<=(const vector_const_iterator& other) const {
	// 			return(this->_ptr <= other._ptr);
	// 		}

	// 		difference_type operator-(const difference_type& other) const {
	// 			return(_ptr - other);
	// 		}

	// 		value_type* operator*(){
	// 			return (_ptr);
	// 		}

	// 		vector_const_iterator& operator++(){
	// 			_ptr++;
	// 			return (*this);
	// 		}

	// 		vector_const_iterator operator++(int){
	// 			vector_const_iterator	temp;
	// 			temp = *this;
	// 			++*this;
	// 			return (temp);
	// 		}

	// 		vector_const_iterator& operator--(){
	// 			_ptr--;
	// 			return (*this);
	// 		}

	// 		vector_const_iterator operator--(int){
	// 			vector_const_iterator	temp;
	// 			temp = *this;
	// 			--*this;
	// 			return (temp);
	// 		}

	// 		// vector_iterator operator+(const vector_iterator& other){

	// 		// }

	// 		vector_const_iterator operator=(const vector_const_iterator& other)
	// 		{
	// 			_ptr = other._ptr;
	// 			return (*this);
	// 		}

	// 		// vector_iterator	operator*(size_t count)
	// 		// {

	// 		// }

	// 		vector_const_iterator	operator+(size_t count)
	// 		{
	// 			_ptr = _ptr + count;
	// 			return (*this);
	// 		}

	// 	private:
	// 		value_type* _ptr;
	// };

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
			typedef T                                                            value_type;
			typedef Allocator                                                    allocator_type;
			typedef size_t                                                       size_type;
			typedef ptrdiff_t                                                    difference_type;
			typedef value_type&                                                  reference;
			typedef const value_type&                                            const_reference;
			typedef value_type*                                                  pointer;
			typedef const value_type*                                            const_pointer;
			typedef vector_random_access_iterator_iterator<value_type>           iterator;
			typedef vector_random_access_iterator_iterator<const value_type>     const_iterator;
			typedef std::reverse_iterator<iterator>                              reverse_iterator;
			typedef std::reverse_iterator<const_iterator>                        const_reverse_iterator;

			//Member functions
			vector(const allocator_type& alloc = allocator_type()) : _begin(NULL), _end(NULL), _limit(NULL), _allocator(alloc){

			}

			vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _begin(NULL), _end(NULL), _limit(NULL), _allocator(alloc){
				resize(n, val);
			}

			vector(const vector& other) : _begin(NULL), _end(NULL), _limit(NULL), _allocator(other._allocator){
				enlarge(other.capacity());
				size_type i = other.size();
				_end = _begin + i;
				while(i != 0){
					i--;
					_begin[i] = other._begin[i];
				}
			}

			~vector(void){
				delete [] _begin;
			}

			iterator begin(){
				return(iterator(this->_begin));
			}

			const_iterator begin() const{
				return(const_iterator(this->_begin));
			}

			iterator end(){
				return(iterator(this->_end));
			}

			const_iterator end() const{
				return(const_iterator(this->_end));
			}

			reverse_iterator rbegin(){
				return(reverse_iterator(this->_begin));
			}

			// const_reverse_iterator rbegin() const{
			// 	return(reverse_iterator(this->_begin))
			// }

			reverse_iterator rend(){
				return(reverse_iterator(this->_end));
			}

			// const_reverse_iterator rend() const{
			// 	return(reverse_iterator(this->_end))
			// }

			allocator_type get_allocator() const{
				return (_allocator);
			}

			// vector& operator=( const vector& other ); //inval
			// void assign( size_type count, const T& value ); //inval
			// allocator_type get_allocator() const;

			//	Element access
			reference at( size_type pos ){
				if (pos >= size())
					throw std::out_of_range("Error: out of range");
				return (_begin[pos]);
			}

			const_reference at( size_type pos ) const{
				if (pos >= size())
					throw std::out_of_range("Error: out of range");
				return (_begin[pos]);
			}

			reference operator[]( size_type pos ){
				return (_begin[pos]);
			}

			const_reference operator[]( size_type pos ) const{
				return (_begin[pos]);
			}

			reference front(){
				return (*_begin);
			}

			const_reference front() const{
				return (*_begin);
			}

			reference back(){
				return (*(_end - 1));
			}

			const_reference back() const{
				return (*(_end - 1));
			}

			value_type* data(){
				return (_begin);
			}

			const value_type* data() const{
				return (_begin);
			}

			//	Capacity
			bool empty() const{
				if (_begin == _end)
					return (true);
				return (false);
			}

			size_type size() const{
				return (_end - _begin);
			}

			size_type max_size() const{
				return (4611686018427387903); // TODO
			}

			void reserve( size_type new_cap ){
				if (new_cap <= capacity())
					return;
				enlarge(new_cap);
			} //inval

			size_type capacity() const{
				return (_limit - _begin);
			}

			//	Moifiers
			void clear(){
				_end = _begin;
			} //inval

			// iterator insert( const_iterator pos, const T& value ); //inval
			// iterator insert( const_iterator pos, size_type count, const T& value ); //inval
			// constexpr iterator insert( const_iterator pos, size_type count, const T& value ); //inval
			template< class input_iterator > iterator insert( const_iterator pos, input_iterator first, input_iterator last ){
				(void)pos;
				(void)first;
				(void)last;
			} //inval

			iterator erase( iterator pos ){
				iterator	temp_it;
				int			i;

				temp_it = begin();
				while (temp_it != pos && *temp_it != _end)
					temp_it++;
				if (*temp_it == _end)
					return (temp_it);
				i = 0;
				while (*temp_it + i + 1 != _end)
				{
					*(*temp_it + i) = *(*temp_it + i + 1) ;
					i++;
				}
				_end--;
				return (temp_it);
			} //inval

			iterator erase( iterator first, iterator last ){
				iterator	temp_it;
				size_type	i;
				size_type	range;

				temp_it = begin();
				while (temp_it != first && *temp_it != _end)
					temp_it++;
				if (*temp_it == _end)
					return (temp_it);
				range = *last - *first + 1;
				i = 0;
				while (*temp_it + i + 1 != _end)
				{
					*(*temp_it + i) = *(*temp_it + i + range) ;
					i++;
				}
				_end = _end - range;
				return (temp_it);
			} //inval

			void push_back( const value_type& value ){
				if (_end == _limit)
					enlarge();
				*_end = value;
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
			value_type*		_begin;
			value_type*		_end;
			value_type*		_limit;
			allocator_type	_allocator;

			void enlarge(size_type new_cap = 0){
				value_type*		temp_ptr;

				if(size() == 0 && new_cap == 0)
					new_cap = 1;
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
				_limit = temp_ptr + new_cap;
				_end = temp_ptr + size();
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
	// template<typename L, typename R> typename vector_iterator<L>::difference_type
	// operator-(const vector_iterator<L> lhs, const vector_iterator<R> rhs)
	// {
	// 	return (lhs - rhs);
	// }
}
