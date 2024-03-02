/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:12:38 by edfirmin          #+#    #+#             */
/*   Updated: 2024/02/29 13:13:04 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free(char *str1, char *str2)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (NULL);
}
