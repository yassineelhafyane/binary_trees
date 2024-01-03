#include "binary_trees.h"

/**
 * binary_tree_depth - Function that measures depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 * Return: Depth of tree, 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree && tree->parent)
		return (1 + binary_tree_depth(tree->parent));
	else
		return (0);
}
