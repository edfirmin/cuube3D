/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:53:00 by edfirmin          #+#    #+#             */
/*   Updated: 2024/03/02 13:11:41 by edfirmin         ###   ########.fr       */
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

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
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
	print_tab(data->map);//rm
	pars_map(data);
	return (0);
}
