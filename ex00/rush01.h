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

int	ft_parsing(char *str);
int	**create_array(char *str, int size);
int **free_array(int **box, int i);
void	ft_print(int **box, int size);
int		ft_backtracking(int **arr, int size, int x, int y);