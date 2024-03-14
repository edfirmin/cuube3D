/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:53:00 by edfirmin          #+#    #+#             */
/*   Updated: 2024/03/14 16:07:57 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("tab[i] =%s\n", tab[i]);
		i++;
	}
}

// void	mumuse_mlx(t_data *data)
// {

// }

int	ft_close(void)
{
	exit (0);
	return (1);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	base1(t_data *data, t_vars *val)
{
	int		x;
	int		y;
	void	*ima;
	char	*buf;
	int		pix;
	int		line_bytes;
	int		endian;
	int		bits_per_pix;
	int		color;

	x = 0;
	ima = mlx_new_image(val->ptr, SIZE_X, SIZE_Y);
	buf = mlx_get_data_addr(ima, &bits_per_pix, &line_bytes, &endian);
	while (x < SIZE_X)
	{
		//---fonc_sol_plaf---//
		y = 0;
		while (y < SIZE_Y)
		{
			pix = (y * line_bytes) + (x * 4);
			if (y > SIZE_Y / 2)
				color = create_trgb(0, data->texture->fl[0], data->texture->fl[1], data->texture->fl[2]);
			else
				color = create_trgb(0, data->texture->ce[0], data->texture->ce[1], data->texture->ce[2]);
			buf[pix] = (color);
			buf[pix + 1] = (color >> 8);
			buf[pix + 2] = (color >> 16);
			buf[pix + 3] = (color >> 24);
			y++;
		}
		//-----------------//
		x++;
	}
	mlx_put_image_to_window(val->ptr, val->wind, ima, 0, 0);
	if (data)
		return ;
}

void	init_data(t_data *data)
{
	int	i;
	int	j;

	data->lmlx.ptr = mlx_init();
	data->lmlx.im_es = mlx_xpm_file_to_image(data->lmlx.ptr, data->texture->east, &i, &j);
	// if (!data->lmlx.im_es)
	// 	error_mes(4, data);
	// data->lmlx.im_we = mlx_xpm_file_to_image(data->lmlx.ptr, data->texture->west, &i, &j);
	// if (!data->lmlx.im_we)
	// 	error_mes(4, data);
	// data->lmlx.im_no = mlx_xpm_file_to_image(data->lmlx.ptr, data->texture->north, &i, &j);
	// if (!data->lmlx.im_no)
	// 	error_mes(4, data);
	// data->lmlx.im_so = mlx_xpm_file_to_image(data->lmlx.ptr, data->texture->south, &i, &j);
	// if (!data->lmlx.im_so)
	// 	error_mes(4, data);
	data->lmlx.wind = mlx_new_window(data->lmlx.ptr, SIZE_X, SIZE_Y, "cub3D");
}

int	recast(t_data *d)
{
	printf("%s\n", d->texture->ceiling);
	return (1);
}

int	touch(t_data *data)
{
	
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	*buff;
	char	**tab;

	buff = NULL;
	data = malloc (1 * sizeof(t_data));
	if (argc != 2)
		error_mes(0, data);
	check_name(argv[1], data);
	buff = line(buff, open(argv[1], O_RDONLY), data);
	if (!buff)
		error_mes(2, data);
	tab = ft_split(buff, '\n');
	get_data(data, tab, buff);
	pars_map(data);
	//---New---//
	init_data(data);
	base1(data, &data->lmlx);
	mlx_hook(data->lmlx.wind, 17, 1L << 21, ft_close, NULL);
	mlx_hook(data->lmlx.wind, 2, 1L << 0, touch, data);
	mlx_loop_hook(data->lmlx.ptr, recast, data);
	mlx_loop(data->lmlx.ptr);
	//---The Code-----//
	// mumuse_mlx(data);
	return (0);
}
