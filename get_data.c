/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:57:09 by edfirmin          #+#    #+#             */
/*   Updated: 2024/03/02 12:16:03 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_data(t_data *data, char **map, char *buff)
{
	int	n;

	data->texture = malloc(1 * sizeof(t_texture));
	get_texture(data, map);
	tab_free(map);
	// free (buff);
	// printf ("tex_ceiling = %s\n", data->texture->ceiling);
	// printf ("tex_north = %s\n", data->texture->north);
	// printf ("tex_south = %s\n", data->texture->south);
	// printf ("tex_east = %s\n", data->texture->east);
	// printf ("tex_west = %s\n", data->texture->west);
	// printf ("tex_floor = %s\n", data->texture->floor);
	// error_mes(1235, data);
	n = get_map_size(data, buff);
	data->map = get_map(n, buff);
}

void	set_tex(t_texture *tex)
{
	tex->ceiling = NULL;
	tex->east = NULL;
	tex->floor = NULL;
	tex->north = NULL;
	tex->south =  NULL;
	tex->west = NULL;
}
