/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:57:09 by edfirmin          #+#    #+#             */
/*   Updated: 2024/03/14 15:17:27 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_data(t_data *data, char **map, char *buff)
{
	int	n;

	data->texture = malloc(1 * sizeof(t_texture));
	get_texture(data, map, buff);
	tab_free(map);
	n = get_map_size(data, buff);
	data->map = get_map(n, buff);
}

void	set_tex(t_texture *tex)
{
	tex->ceiling = NULL;
	tex->east = NULL;
	tex->floor = NULL;
	tex->north = NULL;
	tex->south = NULL;
	tex->west = NULL;
}
