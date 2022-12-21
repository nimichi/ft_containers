#pragma once

#include <memory>
#include <stdexcept>
#include "iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "lexicographical_compare.hpp"

namespace ft {

	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:

			//Member types
			typedef T															value_type;
			typedef Allocator													allocator_type;
			typedef size_t														size_type;
			typedef ptrdiff_t													difference_type;
			typedef value_type&													reference;
			typedef const value_type&											const_reference;
			typedef value_type*													pointer;
			typedef const value_type*											const_pointer;
			typedef ft::iterator<random_access_iterator_tag, value_type>		iterator;
			typedef ft::iterator<random_access_iterator_tag, const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;

		private:
			pointer		_begin;
			pointer		_end;
			pointer		_limit;
			allocator_type	_allocator;

		public:
			//Member functions
			vector(const allocator_type& alloc = allocator_type()) : _allocator(alloc){
				_begin = allocate(1);
				_end = _begin;
				_limit = _begin + 1;
			}

			vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _allocator(alloc){
				if (n == 0)
				{
					_begin = allocate(1);
					_limit = _begin + 1;
				}
				else
				{
					_begin = allocate(n);
					_limit = _begin + n;
				}
				_end = _begin + n;
				while(n > 0){
					n--;
					_begin[n] = val;
				}
			}

			vector(const vector& other) : _allocator(other._allocator){
				pointer tmp_ptr;

				_begin = allocate(other.capacity());
				_limit = _begin + other.capacity();
				_end = _begin;

				tmp_ptr = other._begin;
				while(tmp_ptr != other._end){
					*_end = *tmp_ptr;
					_end++;
					tmp_ptr++;
				}
			}

			template< class InputIt >
			vector( InputIt first, InputIt last, const Allocator& alloc = Allocator(), typename enable_if<!ft::is_integral<InputIt>::value>::type* = 0) :  _allocator(alloc){
				size_type	count;
				InputIt		tmp_iter;

				count = 0;
				tmp_iter = first;
				while (tmp_iter != last)
				{
					tmp_iter++;
					count++;
				}
				_begin = allocate(count);
				_limit = _begin + (count);
				assign(first, last);
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
				return(reverse_iterator(end()));
			}

			const_reverse_iterator rbegin() const{
				return(const_reverse_iterator(end()));
			}

			reverse_iterator rend(){
				return(reverse_iterator(begin()));
			}

			const_reverse_iterator rend() const{
				return(const_reverse_iterator(begin()));
			}

			allocator_type get_allocator() const{
				return (_allocator);
			}

			template <class InputIterator>
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
			assign (InputIterator first, InputIterator last){
				size_type		count;
				InputIterator	tmp_iter;

				count = 0;
				tmp_iter = first;
				while (tmp_iter != last)
				{
					tmp_iter++;
					count++;
				}
				if (count > capacity())
					enlarge(count);
				_end = _begin + count;
				while (count > 0)
				{
					count--;
					last--;
					_begin[count] = *last;
				}
			} // inval

			vector& operator=( const vector& other ){
				pointer tmp_ptr;

				if (other.size() > capacity())
				{
					delete [] _begin;
					_begin = allocate(other.capacity());
					_limit = _begin + other.capacity();
				}
				else
					_limit = _begin + other.capacity();
				_end = _begin;
				tmp_ptr = other._begin;
				while(tmp_ptr != other._end)
				{
					*_end = *tmp_ptr;
					_end++;
					tmp_ptr++;
				}
				return(*this);
			}

			void assign( size_type count, const_reference value ){
				if (count > capacity())
					enlarge(count);
				_end = _begin + count;
				while (count != 0)
				{
					count--;
					_begin[count] = value;
				}
			}

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
				return std::min<size_type>(std::allocator_traits<allocator_type>::max_size(_allocator), std::numeric_limits<difference_type>::max());
			}

			void reserve( size_type new_cap ){
				if (new_cap <= capacity())
					return;
				enlarge(new_cap);
			}

			size_type capacity() const{
				return (_limit - _begin);
			}

			//	Moifiers
			void clear(){
				_end = _begin;
			}

			iterator insert (iterator pos, const value_type& val){
				pos = pre_insert(pos, 1);
				*pos = val;
				return (pos);
			}

			void insert(iterator pos, size_type n, const_reference val){
				pos = pre_insert(pos, n);
				while(n != 0)
				{
					*pos = val;
					pos++;
					n--;
				}
			}

			template<typename input_iterator>
			typename ft::enable_if<!ft::is_integral<input_iterator>::value, void>::type
			insert( iterator pos, input_iterator first, input_iterator last ){
				int n = 0;
				while (first != last){
					last--;
					n++;
				}
				pos = pre_insert(pos, n);
				while(n != 0)
				{
					*pos = *first;
					pos++;
					first++;
					n--;
				}
			}

			iterator erase( iterator pos ){
				return (erase(pos, pos + 1));
			}

			iterator erase( iterator first, iterator last ){
				iterator	temp;
				if (first == end())
					return (first);
				temp = first;
				while (last != end()){
					*first = *last;
					first++;
					last++;
				}
				while(first != last){
					first++;
					_end--;
				}
				return (temp);
			}

			void push_back( const value_type& value ){
				if (_end == _limit)
					enlarge();
				*_end = value;
				_end++;
			}

			void pop_back(){
				if (_begin != _end)
					_end--;
			}

			void resize( size_type count, value_type value = value_type() ){
				if (count > capacity())
					enlarge(count);
				if (count < size())
					_end = _begin + count;
				else
				{
					while (_end != _begin + count)
					{
						*_end = value;
						_end++;
					}
				}
			}

			void swap(vector& other){
				pointer	temp;

				temp = other._begin;
				other._begin = _begin;
				_begin = temp;
				temp = other._end;
				other._end = _end;
				_end = temp;
				temp = other._limit;
				other._limit = _limit;
				_limit = temp;
			}

		private:

			pointer allocate(size_type new_cap){
				if (new_cap >= max_size())
						throw std::bad_alloc();
				return (std::allocator_traits<allocator_type>::allocate(_allocator, new_cap));
			}

			void enlarge(size_type new_cap = 1){
				pointer		temp_ptr;
				size_type	increase;

				increase = size();
				if (increase = 0)
					increase = 1
				while (increase < new_cap)
				{
					if (size() < max_size() / 2)
						increase = size() * 2;
					else
						increase =  max_size();
				}
				temp_ptr = allocate(increase);
				size_type i = size();
				while (i != 0)
				{
					i--;
					temp_ptr[i] = _begin[i];
				}
				_limit = temp_ptr + increase;
				_end = temp_ptr + size();
				delete [] _begin;
				_begin = temp_ptr;
			}

			iterator pre_insert(iterator pos, size_type n){
				iterator ret_iter;
				pointer tmp_ptr;
				pointer del_ptr;
				size_type sze;


				if (pos.base() < _begin || pos.base() > _end)
					return (pos);
				sze = size();
				tmp_ptr = _begin;
				del_ptr = NULL;
				if (sze + n > capacity())
				{
					del_ptr = _begin;
					_begin = allocate(sze + n);
					_limit = _begin + sze + n;
					ret_iter = begin();
					while (tmp_ptr != pos.base()){
						*ret_iter = *tmp_ptr;
						ret_iter++;
						tmp_ptr++;
					}
					pos = ret_iter;
				}
				else
					ret_iter = pos;
				_end = _begin + sze + n;
				sze = _end - n - ret_iter.base();
				while(sze != 0)
				{
					sze--;
					*(ret_iter.base() + sze + n) = *(tmp_ptr + sze);
				}
				if (del_ptr != NULL && del_ptr != _begin)
					delete [] del_ptr;
				return(ret_iter);
			}
	};

	template <class type1, class type2>
	bool operator<=(const vector<type1>& rhs, const vector<type2>& lhs)
	{
		return !(ft::lexicographical_compare(lhs.begin(), --lhs.end(), rhs.begin(), --rhs.end()));
	}

	template <class type1, class type2>
	bool operator>=(const vector<type1>& rhs, const vector<type2>& lhs)
	{
		return !(ft::lexicographical_compare(rhs.begin(), --rhs.end(), lhs.begin(), --lhs.end()));
	}

	template <class type1, class type2>
	bool operator<(const vector<type1>& rhs, const vector<type2>& lhs)
	{
		return ft::lexicographical_compare(rhs.begin(), --rhs.end(), lhs.begin(), --lhs.end());
	}

	template <class type1, class type2>
	bool operator>(const vector<type1>& rhs, const vector<type2>& lhs)
	{
		return ft::lexicographical_compare(lhs.begin(), --lhs.end(), rhs.begin(), --rhs.end());
	}

	template <class type1, class type2>
	bool operator==(const vector<type1>& rhs, const vector<type2>& lhs)
	{
		return (!(rhs < lhs || lhs < rhs));
	}

	template <class type1, class type2>
	bool operator!=(const vector<type1>& rhs, const vector<type2>& lhs)
	{
		return (rhs < lhs || lhs < rhs);
	}
}