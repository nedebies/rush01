/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hburton <hburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:31:03 by hburton           #+#    #+#             */
/*   Updated: 2023/02/18 13:53:22 by hburton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	ft_exp(int base, int exp)
{
	int res;
	int i;

	res = 1;
	i = 0;
	while (i < exp)
	{
		res = res * base;
		i++;
	}
	return (res);
}

static void	set_struct(t_box st, int size)
{
	int i;
	i = 0;
	st.value = 0;
	st.array = ft_exp(2, size) - 1;
}

static t_box	*new_column(int size)
{
	t_box	*col;
	int	i;

	i = 0;
	col = malloc(sizeof(t_box) * (size + 2 + 1));
	if (!col)
		return (0);	
	while (i < size + 2)
	{
		set_struct(col[i], size);
		i++;
	}
	return (col);
}

static t_box	**add_params(t_box **box, char *s, int size)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i <= size && s[j])
	{
		box[i][0].value = s[j] - 48;
		i++;
		j += 2;
	}
	i = 1;
	while (i <= size && s[j])
	{
		box[i][size + 1].value = s[j] - 48;
		i++;
		j += 2;
	}
	i = 1;
	while (i <= size && s[j])
	{
		box[0][i].value = s[j] - 48;
		i++;
		j += 2;
	}
	i = 1;
	while (i <= size && s[j])
	{
		box[size + 1][i].value = s[j] - 48;
		i++;
		j += 2;
	}
	return (box);
}

t_box	**create_array(char *str, int size)
{
	t_box **box;
	int i;

	i = 0;
	box = malloc(sizeof(t_box *) * (size + 2 + 1));
	if (!box)
		return (NULL);
	while (i < (size + 2))
	{
		box[i] = new_column(size);
		if (!box[i])
			return (free_array(box, --i));
		i++;
	}
	box = add_params(box, str, size);
	return (box);
}
