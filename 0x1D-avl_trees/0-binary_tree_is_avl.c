#include "binary_trees.h"

int height(const binary_tree_t *tree)
{
    int h_left = 0, h_right = 0;
    if (!tree)
        return (0);
    h_left = height(tree->left);
    h_right = height(tree->right);
    if (h_left > h_right)
        return (1 + h_left);
    else
        return (1 + h_right);
}

int binary_tree_is_avl(const binary_tree_t *tree)
{

    int h_l = 0, h_r = 0, distance = 0;
    binary_tree_t *l, *r;

    if (!tree)
        return (1);
    l = tree->left;
    r = tree->right;
    h_l = height(l);
    h_r = height(r);
    distance = h_l > h_r ? h_l - h_r : h_r - h_l;

    if (distance <= 1  && binary_tree_is_avl(l) && binary_tree_is_avl(r))
        return (1);
    return (0);
}