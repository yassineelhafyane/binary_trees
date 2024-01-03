#include "binary_trees.h"

/**
 * binary_tree_sibling - Function that Finds sibling of a node in a b-tree.
 * @node: Pointer to the node to find the sibling of.
 * Return: Pointer to the sibling or NUll if otherwise
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}
