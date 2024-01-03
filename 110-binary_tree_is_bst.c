#include "binary_trees.h"

int bst(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_bst - Function that checks if a binary tree is a valid bst
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bst(tree, INT_MIN, INT_MAX));
}

/**
 * bst - Function that checks if a binary tree is a valid binary search tree
 * @tree: Pointer to the root node of the tree to check
 * @min: Value of the smallest node visited
 * @max: Value of the largest node visited
 *
 * Return: 1 if valid, 0 otherwise
 */
int bst(const binary_tree_t *tree, int min, int max)
{
	if (tree != NULL)
	{
		if (tree->n < min || tree->n > max)
			return (0);

		return (bst(tree->left, min, tree->n - 1) &&
				bst(tree->right, tree->n + 1, max));
	}
	return (1);
}

