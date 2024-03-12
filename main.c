/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:53:00 by edfirmin          #+#    #+#             */
/*   Updated: 2024/03/12 11:55:26 by edfirmin         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_data	*data;
	char	*buff;
	char	**tab;
	// void	*ptr;
	// void	*wind;
	// void	*ima;
	// int		x;
	// int		y;

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
	print_tab(data->map);
	error_mes(131, data);
	// ptr = mlx_init();
	// wind = mlx_new_window(ptr, 500, 500, "yjnkj");
	// ima = mlx_xpm_file_to_image(ptr, "image.xpm", &x, &y);
	// mlx_put_image_to_window(ptr, wind, ima, 100, 100);
	// mlx_hook(wind, 17, 1L << 21, ft_close, ima);
	// mlx_loop(ptr);
	//---The Code-----//
	// mumuse_mlx(data);
	return (0);
}
