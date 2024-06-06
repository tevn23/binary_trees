#include "binary_trees.h"

/**
 * binary_tree_insert_right -  inserts a node as the right-child of other node
 * @parent: pointer to the node to insert the right-child in
 * @value: Value to be stored in the new node
 *
 * Return: Pointer to the new node or NULL if fails or parent is NULL
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL; /* Making them to share a child */
	new_node->right = parent->right;

	if (parent->right != NULL)
		parent->right->parent = new_node;

	parent->right = new_node;
	return (new_node);
}
