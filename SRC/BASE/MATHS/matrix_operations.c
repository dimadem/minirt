/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:13:46 by mcoskune          #+#    #+#             */
/*   Updated: 2025/04/07 13:42:17 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	matrix_clone(t_matrix *original)
{
	t_matrix	c_matrix;
	int			i;
	int			j;

	c_matrix = matrix_create(original->n, original->m);
	j = 0;
	while (j < original->n)
	{
		i = 0;
		while (i < original->m)
		{
			c_matrix.data[j][i] = original->data[j][i];
			i++;
		}
		j++;
	}
	return (c_matrix);
}

t_matrix	matrix_identity(int n)
{
	t_matrix	identity;
	int			i;

	identity = matrix_create(n, n);
	i = 0;
	while (i < n)
	{
		identity.data[i][i] = 1.0;
		i++;
	}
	return (identity);
}

t_matrix	matrix_transpose(t_matrix *matrix)
{
	int			i;
	int			j;
	t_matrix	transpose;

	transpose = matrix_create(matrix->m, matrix->n);
	j = 0;
	while (j < matrix->n)
	{
		i = 0;
		while (i < matrix->m)
		{
			transpose.data[i][j] = matrix->data[j][i];
			i++;
		}
		j++;
	}
	return (transpose);
}


static double	calculate_value_tup(t_matrix *mat1, t_tuple *tup1, int i, int j)
{
	int		k;
	double	sum;

	k = 0;
	sum = 0;
	while (k < mat1->m)
	{
		sum += mat1->data[j][k] * tup1->data[k][i];
		k++;
	}
	return (sum);
}

static void	result_iterator_tup(t_tuple *result, t_matrix *mat1, t_tuple *tup1)
{
	int	i;
	int	j;

	j = 0;
	while (j < mat1->n)
	{
		i = 0;
		while (i < tup1->m)
		{
			result->data[j][i] = calculate_value_tup(mat1, tup1, i, j);
			i++;
		}
		j++;
	}
}

t_tuple	matrix_tuple_multiple(t_matrix *matrix1, t_tuple *tup1)
{
	t_tuple	result;

	// if (matrix1->m != matrix2->n)
	// 	return (errmsg("Error - Matrix Mult is not legal!"), NULL);
	result = tuple_create(0, 0, 0, 0);
	result_iterator_tup(&result, matrix1, tup1);
	return (result);
}



static double	calculate_value(t_matrix *mat1, t_matrix *mat2, int i, int j)
{
	int		k;
	double	sum;

	k = 0;
	sum = 0;
	while (k < mat1->m)
	{
		sum += mat1->data[j][k] * mat2->data[k][i];
		k++;
	}
	return (sum);
}

static void	result_iterator(t_matrix *result, t_matrix *mat1, t_matrix *mat2)
{
	int	i;
	int	j;

	j = 0;
	while (j < mat1->n)
	{
		i = 0;
		while (i < mat2->m)
		{
			result->data[j][i] = calculate_value(mat1, mat2, i, j);
			i++;
		}
		j++;
	}
}

t_matrix	matrix_multiple(t_matrix *matrix1, t_matrix *matrix2)
{
	t_matrix	result;

	// if (matrix1->m != matrix2->n)
	// 	return (errmsg("Error - Matrix Mult is not legal!"), NULL);
	result = matrix_create(matrix1->n, matrix2->m);
	result_iterator(&result, matrix1, matrix2);
	return (result);
}

t_matrix	matrix_create(int n, int m)
{
	t_matrix	matrix;
	int			i;
	int			j;

	matrix.n = n;
	matrix.m = m;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			matrix.data[i][j] = 0;
			j++;
		}
		i++;
	}
	return (matrix);
}

int	matrix_compare(t_matrix *mat1, t_matrix *mat2)
{
	int	i;
	int	j;

	if (!mat1 || !mat2)
		return (1);
	if (mat1->n != mat2->n || mat1->m != mat2->m)
		return (2);
	j = 0;
	while (j < mat1->n)
	{
		i = 0;
		while (i < mat1->m)
		{
			if (!epsilon(mat1->data[j][i], mat2->data[j][i]))
				return (3);
			i++;
		}
		j++;
	}
	return (0);
}

t_matrix	matrix_scalar_mult(t_matrix *matrix, double scalar)
{
	int			i;
	int			j;
	t_matrix	result;

	j = 0;
	while (j < matrix->n)
	{
		i = 0;
		while (i < matrix->m)
		{
			result.data[j][i] = matrix->data[j][i] * scalar;
			i++;
		}
		j++;
	}
	return (result);
}

t_matrix	matrix_sub(t_matrix *mat1, t_matrix *mat2)
{
	int			i;
	int			j;
	t_matrix	result;

	j = 0;
	while (j < mat1->n)
	{
		i = 0;
		while (i < mat1->m)
		{
			result.data[j][i] = mat1->data[j][i] - mat2->data[j][i];
			i++;
		}
		j++;
	}
	return (result);
}

t_matrix	matrix_sum(t_matrix *mat1, t_matrix *mat2)
{
	int			i;
	int			j;
	t_matrix	result;

	j = 0;
	while (j < mat1->n)
	{
		i = 0;
		while (i < mat1->m)
		{
			result.data[j][i] = mat1->data[j][i] + mat2->data[j][i];
			i++;
		}
		j++;
	}
	return (result);
}
