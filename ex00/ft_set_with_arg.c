/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_with_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdegryse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:01:36 by kdegryse          #+#    #+#             */
/*   Updated: 2023/02/18 16:12:10 by kdegryse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	ft_pattern_max(t_box **grille, int size)
{
	int i;

	i = 1;
	while (i < size - 1)
	{
		if (grille[0][i].value == 1 && grille[1][i].value == 0)
			set_val_array(grille[1][i], size - 2);
		else if (grille[0][i].value == 1 && grille[1][i].value != 0)
			return (0);
		if (grille[i][0].value == 1 && grille[i][1].value == 0)
			set_val_array(grille[i][1], size - 2);
		else if (grille[i][0].value == 1 && grille[i][1].value != 0)
			return (0);
		if (grille[size - 1][i].value == 1 && grille[size - 2][i].value == 0)
			set_val_array(grille[size - 2][i], size - 2);
		else if (grille[size - 1][i].value == 1 && grille[size - 2][i].value != 0)
			return (0);
		if (grille[i][size - 1].value == 1 && grille[i][size - 2].value == 0)
			set_val_array(grille[i][size - 2], size - 2);
		else if (grille[i][size - 1].value == 1 && grille[i][size - 2].value != 0)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_pattern_elim(t_box **grille, int size)
{
	int i;
	int j;
	int k;

	i = 1;
	while (i < size - 1)
	{
		j = 1;
		while (j < size - 2)
		{
			k = 1;
			while (k < size - 2)
			{
				if (grille[0][i].value > j)
					ft_remove_higher(grille[k][i], size - j - 1 + k);
				if (grille[i][0].value > j)
					ft_remove_higher(grille[i][k], size - j - 1 + k);
				if (grille[size - 1][i].value > j)
					ft_remove_higher(grille[size - k][i], size - j - 1 - k);
				if (grille[i][size - 1].value > j)
					ft_remove_higher(grille[i][size - k], size - j - 1 - k);
				k++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_set_with_arg(t_box **grille)
{
	int size;

	size = grille[0][0].size + 2;
	if (!ft_pattern_max(grille, size))
		return (0);
	if (ft_pattern_elim(grille,size))
		return (0);
	return (1);
}
