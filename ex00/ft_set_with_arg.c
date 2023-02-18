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

static t_box	**ft_pattern_max(t_box **grille, int size)
{
	int i;
	i = 1;
	printf("%d\n", size);
	while (i < (size - 1))
	{
		write(1, "a\n", 1);
		if (grille[0][i].value == 1 && grille[1][i].value == 0)
			set_val_array(grille[1][i], size - 2);
		else if (grille[0][i].value == 1 && grille[1][i].value != 0)
			return (NULL);
		write(1, "b\n", 1);
		if (grille[i][0].value == 1 && grille[i][1].value == 0)
			set_val_array(grille[i][1], size - 2);
		else if (grille[i][0].value == 1 && grille[i][1].value != 0)
			return (NULL);
		write(1, "c\n", 1);
		if (grille[size - 1][i].value == 1 && grille[size - 2][i].value == 0)
		{
			set_val_array(grille[size - 2][i], size - 2);
			write(1, "d\n", 1);
		}
		else if (grille[size - 1][i].value == 1 && grille[size - 2][i].value != 0)
			return (NULL);
		write(1, "e\n", 1);
		if (grille[i][size - 1].value == 1 && grille[i][size - 2].value == 0)
			set_val_array(grille[i][size - 2], size - 2);
		else if (grille[i][size - 1].value == 1 && grille[i][size - 2].value != 0)
			return (NULL);
		i++;
	}
	return (grille);
}

static t_box	**ft_pattern_elim(t_box **grille, int size)
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
					ft_remove_higher(grille[k][i], size - j - 1 + k, size - 2);
				if (grille[i][0].value > j)
					ft_remove_higher(grille[i][k], size - j - 1 + k, size - 2);
				if (grille[size - 1][i].value > j)
					ft_remove_higher(grille[size - k][i], size - j - 1 - k, size - 2);
				if (grille[i][size - 1].value > j)
					ft_remove_higher(grille[i][size - k], size - j - 1 - k, size - 2);
				k++;
			}
			j++;
		}
		i++;
	}
	return (grille);
}

t_box	**ft_set_with_arg(t_box **grille, int size)
{
	size += 2;
	grille = ft_pattern_max(grille, size);
	if (!grille)
		return (NULL);
	grille = ft_pattern_elim(grille,size);
	if (!grille)
		return (NULL);
	return (grille);
}
