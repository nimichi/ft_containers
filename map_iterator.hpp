/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:54:30 by mnies             #+#    #+#             */
/*   Updated: 2022/12/30 23:50:51 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iterator.hpp"

namespace ft
{
	template <class TreeNode>
	class map_iterator
	{
		private:
			TreeNode *tree_node;

		public:
			typedef ft::bidirectional_iterator_tag			iterator_category;
			typedef typename TreeNode::value_type			value_type;
			typedef ptrdiff_t								difference_type;
			typedef value_type&								reference;
			typedef value_type*								pointer;

			map_iterator()
			{

			}

			map_iterator(TreeNode *node)  : tree_node(node)
			{

			}

			map_iterator(const map_iterator &other) : tree_node(other.tree_node)
			{

			}

			reference operator*() const
			{
				return tree_node->get_value();
			}

			pointer operator->() const
			{
				//return pointer_traits<pointer>::pointer_to(tree_node->get_value());
				return NULL;
			}

			map_iterator& operator++()
			{
				++tree_node;
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
				--tree_node;
				return *this;
			}

			map_iterator operator--(int)
			{
				map_iterator ret(*this);
				--(*this);
				return ret;
			}

			friend bool operator==(const map_iterator& lhs, const map_iterator& rhs)
			{
				return lhs.tree_node == rhs.tree_node;
			}

			friend bool operator!=(const map_iterator& lhs, const map_iterator& rhs)
			{
				return lhs.tree_node != rhs.tree_node;
			}
	};
} // namespace ft
