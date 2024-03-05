/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:35:44 by edfirmin          #+#    #+#             */
/*   Updated: 2024/03/05 10:03:38 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	go_free(char **ttab, char **tab, char *buff, t_data *data)
{
	tab_free(ttab);
	tab_free(tab);
	free (buff);
	error_mes(3, data);
}
