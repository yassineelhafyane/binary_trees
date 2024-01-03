#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Function that  rotates left the binary tree
 * @tree: The root node of the binary tree
 * Return: New node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *mid;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	mid = tree->right;
	tree->right = mid->left;

	if (mid->left != NULL)
		mid->left->parent = tree;

	mid->left = tree;
	mid->parent = tree->parent;
	tree->parent = mid;
	return (mid);
}
