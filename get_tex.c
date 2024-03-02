/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:48:37 by edfirmin          #+#    #+#             */
/*   Updated: 2024/03/02 10:49:40 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture(t_data *data, char **tab)
{
	int		i;
	char	**ttab;

	i = 0;
	set_tex(data->texture);
	while (tab[i])
	{
		if (check_full(data->texture))
			return ;
		ttab = ft_split(tab[i], ' ');
		if (ttab[2] || !ttab[1])
		{
			tab_free(ttab);
			tab_free(tab);
			error_mes(3, data);
		}
		get_texture2(data, ttab, tab);
		tab_free(ttab);
		i++;
	}
	if (!check_full(data->texture))
	{
		tab_free(tab);
		error_mes(3, data);
	}
}

void	get_texture2(t_data *data, char **tab, char **g_free)
{
	int	n;

	n = 0;
	if (ft_strlen(tab[0]) > 2)
	{
		tab_free(tab);
		tab_free(g_free);
		error_mes(3, data);
	}
	n = what_tex(tab[0]);
	if (n == 0)
	{
		tab_free(tab);
		tab_free(g_free);
		error_mes(3, data);
	}
	get_texture3(tab[1], data->texture, n);
}

void	get_texture3(char *str, t_texture *tex, int n)
{
	free_d_tex(tex, n);
	if (n == 1)
		tex->north = ft_strdup(str);
	if (n == 2)
		tex->south = ft_strdup(str);
	if (n == 3)
		tex->east = ft_strdup(str);
	if (n == 4)
		tex->west = ft_strdup(str);
	if (n == 5)
		tex->floor = ft_strdup(str);
	if (n == 6)
		tex->ceiling = ft_strdup(str);
}
