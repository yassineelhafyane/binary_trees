#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Function that  rotates right the binary tree
 * @tree: The root node of the binary tree
 * Return: New node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *mid;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	mid = tree->left;
	tree->left = mid->right;

	if (mid->right != NULL)
		mid->right->parent = tree;

	mid->right = tree;
	mid->parent = tree->parent;
	tree->parent = mid;
	return (mid);
}
