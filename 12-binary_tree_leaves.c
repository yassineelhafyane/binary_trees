#include "binary_trees.h"

/**
 * binary_tree_leaves - Function that counts no. of leaves in a binary tree
 * @tree: Pointer to the root node of the tree to count the leaves of
 * Return: No. of leaves in tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t tree_leaves = 0;

	if (tree)
	{
		if (!tree->left && !tree->right)
			tree_leaves += 1;
		else
			tree_leaves += 0;

		tree_leaves += binary_tree_leaves(tree->left);
		tree_leaves += binary_tree_leaves(tree->right);
	}
	return (tree_leaves);
}
