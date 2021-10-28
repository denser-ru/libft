/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:07:37 by cayako            #+#    #+#             */
/*   Updated: 2021/10/28 13:25:03 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H

# define FT_MAP_H

# include "libft.h"

# define FT_MAP_BUF		4096
# define FT_ERR_LEN		255
# define FT_MAP_MAX_ELM	100

typedef struct s_map		t_map;
typedef struct s_map_elm	t_map_elm;

struct s_map_elm
{
	char				*key;
	char				*value;
	size_t				size_key;
	size_t				size_value;
	struct s_map_elm	*prev;
	struct s_map_elm	*next;
};

struct s_map
{
	char			mem[FT_MAP_BUF];
	char			*end;
	t_map_elm		arr[FT_MAP_MAX_ELM];
	t_map_elm		*root;
	t_map_elm		*last;
	t_map_elm		*tail;
	size_t			count;
	size_t			deleted;
	size_t			size;
	char			err[FT_ERR_LEN];
};

// map/ft_map_add.c
t_map		*ft_map_add(t_map *map, char *key, char *value);

// map/ft_map_new.c
t_map		*ft_map_new(void);

// map/ft_map_getbykey.c
t_list		*ft_map_getbykey(t_map *map, t_list *value, char *key);
t_map_elm	*ft_map_get_elm(t_map *map, char *key);

// map/void	ft_map_print_all.c
void		ft_map_print_all(t_map_elm *arr);

// map/ft_map_from_env.c
int			ft_map_from_env(t_map *map, char **env);

// map/ft_map_del_elm.c
int			ft_map_del_elm(t_map *map, char *key);

#endif
