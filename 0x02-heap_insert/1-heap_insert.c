#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: the tree to traverse
 * Return: the height or null if !tree
 */
int binary_tree_height(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left += binary_tree_height(tree->left) + 1;
	if (tree->right)
		right += binary_tree_height(tree->right) + 1;
	if (left >= right)
		return (left);
	else
		return (right);
}

/**
 * binary_tree_balance - function that measures the height of a binary tree
 * @tree: the tree to traverse
 * Return: the height or null if !tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int altura_izq, altura_der;

	if (!tree)
		return (0);
	if (tree->left)
		altura_izq = binary_tree_height(tree->left) + 1;
	else
		altura_izq = binary_tree_height(tree->left);
	if (tree->right)
	{
		altura_der = binary_tree_height(tree->right) + 1;
	}
	else
	{
		altura_der = binary_tree_height(tree->right);
	}
	return (altura_izq - altura_der);
}

heap_t *finding_place(heap_t *tree)
{
	if (tree)
	{
		if (binary_tree_balance(tree) > 0)
		{
			if (!tree->right)
				return (tree);
			return finding_place(tree->right);
		}
		else
		{
			if (!tree->left)
				return (tree);
			return finding_place(tree->left);
		}
	}
	return (NULL);
}

void moving_foward(heap_t *tree, heap_t **root)
{
	heap_t *aux = NULL, *aux1 = NULL;
	printf("q es el tree aca? %d\n", tree->n);

}

void moving(heap_t *tree, heap_t **root)
{
	heap_t *aux = NULL, *aux1 = NULL;
	printf("entrÃ a ordenar \n");
	if (tree->parent && tree->parent->parent)
	{
		if (aux->left)
                {
                        if (aux->left->n == tree->n)
                        {
                                aux1 = aux;
                                aux->parent = tree;
                                aux->left = tree->left;
                                aux->right = tree->right;
                                tree->parent = aux1->parent;
                                tree->left = aux1;
                                tree->right = aux->right;
                        }
                }
                if (aux->right)
                {
                        if (aux->right->n == tree->n)
                        {
                                aux1 = aux;
                                aux->parent = tree;
                                aux->left = tree->right;
                                aux->right = tree->left;
                                tree->parent = aux1->parent;
                                tree->left = aux1;
                                tree->right = aux->left;

                        }
                }
	
			moving(tree->parent, root);
	}
	
	if (tree->parent->n <= tree->n)
	{
		printf("entre aca????????????? owo\n");
		aux = tree->parent;
		printf("q carajos con el aux n %d\n", aux->n);
		printf("q carajos con el tree n %d\n", tree->n);
		if (aux->left)
		{
			if (aux->left->n == tree->n)
			{
				aux1 = aux;
				aux->parent = tree;
				aux->left = tree->left;
				aux->right = tree->right;
				tree->parent = aux1->parent;
				tree->left = aux1;
				tree->right = aux->right;
				*root = tree;
			}
		}
		if (aux->right)
		{
			if (aux->right->n == tree->n)
			{
                                aux1 = aux;
                                aux->parent = tree;
                                aux->left = tree->right;
                                aux->right = tree->left;
                                tree->parent = aux1->parent;
                                tree->left = aux1;
                                tree->right = aux->left;
				*root = tree;

			}
		}
		printf("desp de los if\n");
	}
	moving_foward(tree, root);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: root node
 * @value: value of the new node
 * Return: pointe to the inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = NULL, *aux = NULL, *worm;
	int flag = 0;

	if ((*root))
	{
		printf("existe root\n");
		worm = *root;
		printf("el balace %d\n", binary_tree_balance(worm));
		if (binary_tree_balance(worm) > 0)
		{
			printf("la rama de la izquierda es mas grande\n");
			if (!worm->right)
			{
				printf("hola el worm entro acÃ izquierda %d\n", worm->n);
				aux = binary_tree_node(worm, value);
				worm->right = aux;
				binary_tree_print(*root);
				if (aux->parent->n <= aux->n)
					moving(aux, root);
				return (aux);
			}
			aux = finding_place(worm->right);
			printf("desp del return de la rama izquierda\n");
			flag = 0;
		}
		else
		{
			printf("la rama de la derecha es mas grande\n");
			if (!worm->left)
			{
				printf("hola el worm entro acÃ derecha %d\n", worm->n);
				aux = binary_tree_node(worm, value);
				worm->left = aux;
				binary_tree_print(*root);
				if (aux->parent->n <= aux->n)
					moving(aux, root);
				return (aux);
			}
			aux = finding_place(worm->left);
			printf("desp del return de la rama grande\n");
			flag = 1;
		}
		printf("voy a retornar aux %d\n", aux->n);
		worm = binary_tree_node(aux, value);
		if (flag)
			aux->left = worm;
		else
			aux->right = worm;
		return (worm);
	}
	new = binary_tree_node(*root, value);
	*root = new;
	return (new);
}
