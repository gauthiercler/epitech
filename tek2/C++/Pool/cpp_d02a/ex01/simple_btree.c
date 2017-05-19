/*
** simple_btree.c for cpp_d02 in /home/gogo/rendu/tek2/cpp_d02a/ex01/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Fri Jan  6 00:16:54 2017 Gauthier Cler
** Last update Fri Jan  6 01:03:41 2017 Gauthier Cler
*/

#include	<stdlib.h>
#include	"simple_btree.h"

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))


t_bool		btree_is_empty(t_tree tree)
{
  if (!tree)
    return TRUE;
  return FALSE;
}

unsigned int	btree_get_size(t_tree tree)
{
  unsigned int	sum = 1;
  if (!tree)
    return 0;
  if (tree->right)
    sum += btree_get_size(tree->right);
  if (tree->left)
    sum += btree_get_size(tree->left);
  return sum;
}

unsigned int	btree_get_depth(t_tree tree)
{
  unsigned int	right = 1;
  unsigned int	left = 1;

  if (!tree)
    return 0;
  right += btree_get_depth(tree->right);
  left += btree_get_depth(tree->left);
  if (right > left)
    return right;
  return left;
}

t_bool	btree_create_node(t_tree *root_ptr, double value)
{
  t_tree	new_ptr;

  new_ptr = malloc(sizeof(t_node));
  if (!new_ptr)
    return FALSE;
  new_ptr->right = NULL;
  new_ptr->left = NULL;
  new_ptr->value = value;
  *root_ptr = new_ptr;
  return TRUE;
}

t_bool	btree_delete(t_tree *root_ptr)
{
  if (!root_ptr)
    return FALSE;
  if ((*root_ptr)->right){
      btree_delete(&(*root_ptr)->right);
      free((*root_ptr)->right);
    }
  if ((*root_ptr)->left){
      btree_delete(&(*root_ptr)->left);
      free((*root_ptr)->left);
    }
  return TRUE;
}

double	btree_get_max_value(t_tree tree)
{
  double max;

  if (!tree)
    return 0;

  max = tree->value;
  if (tree->right)
    max = MAX(max, btree_get_max_value(tree->right));
  if (tree->left)
    max = MAX(max, btree_get_max_value(tree->left));
  return max;
}

double	btree_get_min_value(t_tree tree)
{
  double min;

  if (!tree)
    return 0;

  min = tree->value;
  if (tree->right)
    min = MIN(min, btree_get_min_value(tree->right));
  if (tree->left)
    min = MIN(min, btree_get_min_value(tree->left));
  return min;
}
