/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:00:05 by edfirmin          #+#    #+#             */
/*   Updated: 2024/03/02 16:37:21 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "lib/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <math.h>

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
}			t_texture;

typedef struct s_data
{
	char		**map;
	t_texture	*texture;
}			t_data;

// typedef struct s_player
// {

// };

//----------utile1----------//
void	free_all(t_data *data);
int		ft_free2(char *str1, char *str2);
void	error_mes(int n, t_data	*data);
char	*line(char *buffer, int fd, t_data *data);
void	check_name(char *str, t_data *data);

//----------utile2----------//
int		tab_len(char **tab);

//----------get_tex----------//
void	get_texture(t_data *data, char **tab);
void	get_texture2(t_data *data, char **tab, char **g_free);
void	get_texture3(char *str, t_texture *tex, int n);

//----------get_tex_utile----------//
int		check_full(t_texture *tex);
int		lil_tex(char *str);
int		big_tex(char *str);
int		what_tex(char *str);
void	free_d_tex(t_texture *tex, int n);

//----------get_data----------//
void	get_data(t_data *data, char **map, char *buff);
void	set_tex(t_texture *tex);

//----------gat_map----------//
int		get_map_size(t_data *data, char *buff);
char	**get_map(int n, char *buff);
char	*put_line(char *src);
int		c_back_n(char *str);

//----------pars_map----------//
void	pars_map(t_data *data);
void	check_around(t_data *data, int i, int j);
void	check_close_map(t_data *data);

//----------pars_map_utile1----------//
int		map_char(char c);
int		n_player(char c);
int		is_out(char c);
void	check_bad_char(t_data *data);
void	check_n_player(t_data *data);

#endif