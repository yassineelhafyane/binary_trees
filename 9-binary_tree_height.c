#include "binary_trees.h"

/**
 * binary_tree_height - Function that measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: Height of tree, 0 if tree is MULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t l_child = 0, r_child = 0;

		if (tree->left)
			l_child = 1 + binary_tree_height(tree->left);
		else
			l_child = 0;

		if (tree->right)
			r_child = 1 + binary_tree_height(tree->right);
		else
			r_child = 0;

		if (l_child > r_child)
			return (l_child);
		else
			return (r_child);
	}
	return (0);
}
