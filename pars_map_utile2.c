/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_utile2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:57:07 by edfirmin          #+#    #+#             */
/*   Updated: 2024/03/12 20:07:46 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_val(int *tab)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (tab[i] < 0 || tab[i] > 255)
			return (0);
		i++;
	}
	return (1);
}

int	check_col(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ',')
			j++;
		if (str[i] != ',' && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (j != 2)
		return (0);
	return (1);
	
}

void	get_fl(t_data *data)
{
	char	**tab;
	int		i;

	i = 0;
	if (!check_col(data->texture->floor))
		error_mes(3, data);
	tab = ft_split(data->texture->floor, ',');
	if (tab_len(tab) != 3)
		error_mes(7, data);
	while (i < 3)
	{
		data->texture->fl[i] = ft_atoi(tab[i]);
		i++;
	}
    tab_free(tab);
	if (!check_val(data->texture->fl))
		error_mes(7, data);
}

void	get_ce(t_data *data)
{
	char	**tab;
	int		i;

	i = 0;
	if (!check_col(data->texture->ceiling))
		error_mes(3, data);
	tab = ft_split(data->texture->ceiling, ',');
	if (tab_len(tab) != 3)
		error_mes(12, data);
	while (i < 3)
	{
		data->texture->ce[i] = ft_atoi(tab[i]);
		i++;
	}
    tab_free(tab);
	if (!check_val(data->texture->ce))
		error_mes(7, data);
}
