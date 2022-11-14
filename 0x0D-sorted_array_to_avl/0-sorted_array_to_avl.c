#include "binary_trees.h"


/**
 * sorted_array_to_avl - builds an AVL tree from an array
 *
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: root node
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	size_t mid;
	avl_t *root;

	if (!array || size < 1)
		return (NULL);
	root = malloc(sizeof(avl_t));
	if (!root)
		return (NULL);
	mid = size / 2;
	root->n = array[mid];
	root->left = sorted_array_to_avl(array, mid);
	root->right = sorted_array_to_avl(array + mid + 1, size - mid - 1);
	root->left ? root->left->parent = root : 0;
	root->right ? root->right->parent = root : 0;
	return (root);
}
