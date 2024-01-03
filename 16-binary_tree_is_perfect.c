#include "binary_trees.h"

int exponent(int x, int y);

/**
 * binary_tree_is_perfect - Function that checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0, nodes = 0, power = 0;

	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	height = binary_tree_height(tree);
	nodes = binary_tree_size(tree);

	power = (size_t)exponent(2, height + 1);
	return (power - 1 == nodes);
}

/**
 * exponent - returns x exponent y
 * @x: The base value
 * @y: The exponent
 *
 * Return: x^y or -1 if y is negative
 */

int exponent(int x, int y)
{
	if (y < 0)
		return (-1);

	if (y == 0)
		return (1);
	else
		return (x * exponent(x, y - 1));

}

/**
 * binary_tree_size - Function that measures the size of a binary tree
 * @tree: The tree to measure the size of
 * Return: size of tree, 0 otherwise
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_height - Function that measures the height of a binary tree
 * @tree: The tree to measure the height of
 * Return: height of tree, 0 if otherwise
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
