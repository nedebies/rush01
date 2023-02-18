/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hburton <hburton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:57:16 by nesdebie          #+#    #+#             */
/*   Updated: 2023/02/18 16:07:59 by kdegryse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
#include<stdio.h>
typedef	struct	s_box
{
	int		array;
	int		value;
}	t_box;

int	ft_parsing(char *str);
t_box	**create_array(char *str, int size);
t_box **free_array(t_box **box, int i);
void	ft_print(t_box **box, int size);
void	ft_remove(t_box my_box, int n);
void	ft_remove_higher(t_box my_box, int n, int size);
t_box	**ft_set_with_arg(t_box **grille, int size);
t_box	**ft_search_value(t_box **grille, int size);
t_box	**ft_solve(t_box **grille, int size);
void	set_val_array(t_box my_box, int n);