/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hburton <hburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:10:13 by hburton           #+#    #+#             */
/*   Updated: 2023/02/18 15:08:36 by hburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_remove(t_box my_box, int n)
{
	my_box.array[n - 1] = 0;
}

void	ft_remove_higher(t_box my_box, int n, int size)
{
	int	i;

	i = n - 1;
	if (n < size)
	{
		while (my_box.array[i])
		{
			my_box.array[i] = 0;
			i++;
		}
	}
}

void	set_val_array(t_box my_box, int n)
{
	int i;

	my_box.value = n;
	i = 0;
	write(1, "t", 1);		
	while (my_box.array[i])
	{
		write(1, "o", 1);
		if (my_box.array[i] != n)
			my_box.array[i] = 0;
		i++;
	}
}