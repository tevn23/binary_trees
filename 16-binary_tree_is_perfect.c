#include "binary_trees.h"

/**
 * binary_tree_depth - Calculate the depth of the leftmost node.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: Depth of the tree.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}


/**
 * is_perfect_recursive - Recursively checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree.
 * @depth: The depth of the tree.
 * @level: The current level in the tree.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int is_perfect_recursive(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
	{
		return (1);
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		return (depth == level + 1);
	}

	if (tree->left == NULL || tree->right == NULL)
	{
		return (0);
	}
	return (is_perfect_recursive(tree->left, depth, level + 1) &&
			is_perfect_recursive(tree->right, depth, level + 1));
}


/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int depth = binary_tree_depth(tree);

	return (is_perfect_recursive(tree, depth, 0));
}
