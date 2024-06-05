#include "binary_trees.h"

/**
 * binary_tree_insert_left -  inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: Value to be stored in the new node
 *
 * Return: Pointer to the new node or NULL if fails or parent is NULL
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    if (parent == NULL)
        return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = parent->left; /* Making them to share a child */
	new_node->right = NULL;

    if (parent->left != NULL)
        parent->left->parent = new_node; /* Making new node parent to any existing child */

    parent->left = new_node; /* Making new node child to the parent to make it parent to the shared left child*/
	return (new_node);
}
