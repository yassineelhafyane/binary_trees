#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
int avl(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_avl - Function that finds if a binary tree is an avl
 * @tree: Pointer to the root node of the tree
 * Return: 1 if tree is avl, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (avl(tree, INT_MIN, INT_MAX));
}

/**
 * avl - Function that finds if a binary tree is an avl
 * @tree: Pointer to the root node of the tree
 * @min: The minimum value
 * @max: The maximum value
 *
 * Return: 1 if tree is avl, 0 otherwise
 */
int avl(const binary_tree_t *tree, int min, int max)
{
	int l_child, r_child;

	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	l_child = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	r_child = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(l_child - r_child) > 1)
		return (0);

	return (avl(tree->left, min, tree->n - 1) &&
			avl(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_height - Function that measures the height of a binary tree
 * @tree: The tree to measure the height of
 * Return: height of tree, 0 otherwise
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (!tree)
		return (0);

	l_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	r_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (l_height > r_height ? l_height : r_height);
}
