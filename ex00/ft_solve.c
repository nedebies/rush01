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

int	ft_solve(t_box **grille)
{
	if (!ft_set_with_arg(grille))
		return (0);
	if (!ft_search_value(grille))
		return (0);
	return (1);
}
