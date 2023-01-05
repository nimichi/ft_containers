/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:54:30 by mnies             #+#    #+#             */
/*   Updated: 2023/01/05 01:28:31 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iterator.hpp"

namespace ft
{
	template <class T>
	struct node
	{
		typedef T						value_type;

		node *left;
		node *right;
		node *parent;
		bool isRed;
		value_type* value;

		node() : left(NULL), right(NULL), parent(NULL), isRed(false), value(NULL)
		{

		}

		node(value_type* value, node *parent, node *head) : left(head), right(head), parent(parent), isRed(true), value(value)
		{

		}

		node(const node& other) : left(other.left), right(other.right), parent(other.parent), isRed(other.isRed), value(other.value)
		{

		}
	};

	template <class T>
	class const_map_iterator;

	template <class T>
	class map_iterator
	{
		public:
			typedef ft::bidirectional_iterator_tag			iterator_category;
			typedef T										value_type;
			typedef node<value_type>*						node_pointer;
			typedef ptrdiff_t								difference_type;
			typedef value_type&								reference;
			typedef value_type*								pointer;
			typedef const_map_iterator<value_type>			const_iterator;

		private:
			template <class> friend class const_map_iterator;

		protected:
			node_pointer _node;

		public:
			map_iterator() : _node(NULL){}

			map_iterator(node_pointer node)  : _node(node){}

			map_iterator(const map_iterator &other) : _node(other._node){}

			reference operator*() const { return *(_node->value); }

			pointer operator->() const { return &(operator*()); }

			map_iterator& operator++()
			{
				if (_node->right->value != NULL)
				{
					_node = _node->right;
					while (_node->left->value != NULL)
						_node = _node->left;
					return *this;
				}
				while (_node == _node->parent->right)
					_node = _node->parent;
				_node = _node->parent;
				return *this;
			}

			map_iterator operator++(int)
			{
				map_iterator ret(*this);
				++(*this);
				return ret;
			}

			map_iterator& operator--()
			{
				if (_node->left->value != NULL)
				{
					_node = _node->left;
					while (_node->right->value != NULL)
						_node = _node->right;
					return *this;
				}
				while (_node == _node->parent->left)
					_node = _node->parent;
				_node = _node->parent;
				return *this;
			}

			map_iterator operator--(int)
			{
				map_iterator ret(*this);
				--(*this);
				return ret;
			}

			bool operator==(const map_iterator& other) const { return _node == other._node; }

			bool operator==(const const_map_iterator<value_type>& other) const { return _node == other.base(); }

			bool operator!=(const map_iterator& other) const { return !(*this == other); }

			bool operator!=(const const_map_iterator<value_type>& other) const { return !(*this == other); }

			node_pointer base() const { return _node; }
	};

	template <class T>
	class const_map_iterator
	{
		public:
			typedef ft::bidirectional_iterator_tag			iterator_category;
			typedef T										value_type;
			typedef const node<value_type>*					node_pointer;
			typedef ptrdiff_t								difference_type;
			typedef value_type&								reference;
			typedef value_type*								pointer;
			typedef map_iterator<value_type>				iterator;

		private:
			node_pointer _node;

		public:

			const_map_iterator() : _node(NULL) {}

			const_map_iterator(const iterator& other) : _node(other._node) {}

			const_map_iterator(const const_map_iterator& other) : _node(other._node) {}

			const_map_iterator(node_pointer node) : _node(node) {}

			reference operator*() const { return *(_node->value); }

			pointer operator->() const { return &(operator*()); }

			const_map_iterator& operator++()
			{
				if (_node->right->value != NULL)
				{
					_node = _node->right;
					while (_node->left->value != NULL)
						_node = _node->left;
					return *this;
				}
				while (_node == _node->parent->right)
					_node = _node->parent;
				_node = _node->parent;
				return *this;
			}

			const_map_iterator operator++(int)
			{
				const_map_iterator t = *this;
				++(*this);
				return t;
			}

			const_map_iterator& operator--()
			{
				if (_node->left->value != NULL)
				{
					_node = _node->left;
					while (_node->right->value != NULL)
						_node = _node->right;
					return *this;
				}
				while (_node == _node->parent->left)
					_node = _node->parent;
				_node = _node->parent;
				return *this;
			}

			const_map_iterator operator--(int)
			{
				const_map_iterator t = *this;
				--(*this);
				return t;
			}

			bool operator==(const const_map_iterator& other) const { return _node == other._node; }

			bool operator==(const map_iterator<value_type>& other) const { return _node == other.base(); }

			bool operator!=(const const_map_iterator& other) const { return !(*this == other); }

			bool operator!=(const map_iterator<value_type>& other) const { return !(*this == other); }

			node_pointer base() const { return _node; }
};
} // namespace ft

