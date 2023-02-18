/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdegryse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:39:48 by kdegryse          #+#    #+#             */
/*   Updated: 2023/02/18 16:07:04 by kdegryse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	ft_set_value(t_box mybox)
{
	int verif;
	int val;
	int	i;

	verif = 0;
	i = 0;
	while (mybox.array[i])
	{
		if (mybox.array[i] != 0)
		{
			val = mybox.array[i];
			verif++;
		}
		i++;
	}
	if (verif == 1)
		mybox.value = val;
	else
		val = 0;
	return (val);
}

static t_box	**ft_remove_row_line(t_box **grille, int x, int y, int rm, int size)
{
	int i;
	int val;

	i = 1;
	while (i < size - 1)
	{
		ft_remove(grille[i][y], rm);
		val = ft_set_value(grille[i][y]);
		if (val != 0)
			ft_remove_row_line(grille, i, y, val, size);
		i++;
	}
	i = 1;
	while (i < size - 1)
	{
		ft_remove(grille[x][i], rm);
		val = ft_set_value(grille[x][i]);
		if (val != 0)
			ft_remove_row_line(grille, x, i, val, size);
		i++;
	}
	return (grille);
}

t_box **ft_search_value(t_box **grille, int size)
{
	int val;
	int i;
	int j;

	size += 2;
	i = 1;
	while (i < size + 1)
	{
		j = 1;
		while (j < size + 1)
		{
			val = ft_set_value(grille[i][j]);
			if (val != 0)
				grille = ft_remove_row_line(grille, i, j, val, size - 2);
			j++;
		}
		i++;
	}
	return (grille);
}	
