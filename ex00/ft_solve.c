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

t_box	**ft_solve(t_box **grille, int size)
{
	grille = ft_set_with_arg(grille, size);
	if (!grille)
		return (NULL);
	grille = ft_search_value(grille, size);
	if (!grille)
		return (NULL);
	return (grille);
}
