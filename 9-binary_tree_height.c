#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * 
 * Return: 0 if tree is NULL
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height = 0;
    size_t right_height = 0;
    
    if (tree == NULL)
        return (-1);
    
    left_height = binary_tree_height(tree->left) + 1;
    right_height = binary_tree_height(tree->right) + 1;

    if (left_height > right_height)
        return (left_height);

    else
        return (right_height);
}
