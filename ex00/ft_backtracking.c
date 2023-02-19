/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdegryse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:00:19 by kdegryse          #+#    #+#             */
/*   Updated: 2023/02/18 15:49:22 by kdegryse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int		ft_check_cols_up(int **box, int x, int size)
{
	int		cpt;
	int		y;
	int		i;

	y = 1;
	cpt = 1;
	i = 1;
	while (y + i <= size)
	{
		if (box[x][y] < box[x][y + i])
		{
			cpt++;
			y += i;
			i = 1;
		}
		else
			i++;
	}
	if (cpt == box[x][0])
		return (0);
	else
		return (1);
}

static int		ft_check_cols_down(int **box, int x, int size)
{
	int		cpt;
	int		y;
	int		i;

	y = size;
	cpt = 1;
	i = 1;
	while (y - i >= 1)
	{
		if (box[x][y] < box[x][y - i])
		{
			cpt++;
			y -= i;
			i = 1;
		}
		else
			i++;
	}
	if (cpt == box[x][size + 1])
		return (0);
	else
		return (1);
}

static int		ft_check_row_left(int **box, int y, int size)
{
	int		cpt;
	int		x;
	int		i;

	x = 1;
	cpt = 1;
	i = 1;
	while (x + i <= size)
	{
		if (box[x][y] < box[x + i][y])
		{
			cpt++;
			x += i;
			i = 1;
		}
		else
			i++;
	}
	if (cpt == box[0][y])
		return (0);
	else
		return (1);
}

static int		ft_check_row_right(int **box, int y, int size)
{
	int		cpt;
	int		x;
	int		i;

	x = size;
	cpt = 1;
	i = 1;
	while (x - i >= 1)
	{
		if (box[x][y] < box[x - i][y])
		{
			cpt++;
			x -= i;
			i = 1;
		}
		else
			i++;
	}
	if (cpt == box[size + 1][y])
		return (0);
	else
		return (1);
}

static int		ft_checkmatch(int **box, int size) // verifie les horizontales et verticales
{
	int		i;

	i = 1;
	while (i <= size)
	{
		if (ft_check_cols_up(box, i, size))
			return (1);
		if (ft_check_cols_down(box, i, size))
			return (1);
		if (ft_check_row_left(box, i, size))
			return (1);
		if (ft_check_row_right(box, i, size))
			return (1);
		i++;
	}
	return (0);
}

static int		check(int **box, int i, int xy, int size) //verifie si i est deja present dans la box
{
	int row;
	int col;
	int x;
	int y;

	x = xy / 10;
	y = xy %10;
	row = 1;
	col = 1;
	while (row <= size)
	{
		if (i == box[row][y])
			return (1);
		row++;
	}
	while (col <= size)
	{
		if (i == box[x][col])
			return (1);
		col++;
	}
	return (0);
}

int		ft_backtracking(int **box, int size, int x, int y)
{
	int i;

	i = 1;
	while (1)
	{
		while (i <= size && check(box, i, (10 * x + y), size))
			i++;
		if (i <= size)
			box[x][y] = i;
		else
		{
			box[x][y] = 0;
			return (1);
		}
		if (x == size && y == size)
		{
			if (ft_checkmatch(box, size))
			{
				if (i >= size)
					return (1);
				else
					continue ;
			}
			else
				return (0);
		}
		if (x == size)
		{
			if (ft_backtracking(box, size, 1, y + 1))
				continue;
			return (0);
		}
		else
		{
			if (ft_backtracking(box, size, x + 1, y))
				continue;
			return (0);
		}
	}
}
