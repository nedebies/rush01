/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hburton <hburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:54:56 by nesdebie          #+#    #+#             */
/*   Updated: 2023/02/18 14:31:42 by hburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

t_box **free_array(t_box **box, int i)
{

	int j;
	int size;

	size = i;
	while (i >= 0)
	{
		j = size;
		while (j > 0)
		{
			free(box[i][j].array);
			j--;
		}
		free(box[i]);
		i--;
	}
	write (1, "c", 1);
	free (box);
	return (NULL);
}

int main(int ac, char **av)
{
	t_box	**box;
	int	size;

	if (ac != 2)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	size = ft_parsing(av[1]);
	if (size == 0)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	box = create_array(av[1], size);
	//check_box
	//ft_solve
	ft_print(box, size);
	free_array(box, (size + 1));
	return (0);
}