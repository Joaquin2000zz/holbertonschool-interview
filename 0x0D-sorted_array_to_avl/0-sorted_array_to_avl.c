#include "binary_trees.h"


/**
 * rec - makes the recursion
 *
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * @parent: parent node or null in case of root node
 */
avl_t *rec(int *array, size_t size, avl_t *parent)
{
    binary_tree_t *node = NULL;
    avl_t *root = NULL;

    node = malloc(sizeof(avl_t));
    if (!node)
        return (NULL);
    root = node;

    if (!array || size == 0)
        return (NULL);
    root->parent = parent, root->left = NULL, root->right = NULL;
    root->n = array[(size - 1) / 2];
    root->left = rec(array, (size - 1) / 2, root);
    root->right = rec(array + (size + 1) / 2, (size - 1) / 2, root);

    return (root);    
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 *
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return (NULL);

    return (rec(array, size, NULL));
}
