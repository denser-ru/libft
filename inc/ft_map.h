/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:07:37 by cayako            #+#    #+#             */
/*   Updated: 2021/11/11 11:19:25 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H

# define FT_MAP_H

# include "libft.h"

# define FT_MAP_BUF				40960
# define FT_ERR_LEN				255
# define FT_MAP_MAX_NAME_LEN	255
# define FT_MAP_MAX_ELM			82

typedef struct s_map		t_map;
typedef struct s_map_elm	t_map_elm;

struct s_map_elm
{
	char				key[FT_MAP_MAX_NAME_LEN + 1];
	char				value[FT_MAP_MAX_NAME_LEN + 1];
	t_2list				*b_key;
	t_2list				*b_value;
	size_t				size_key;
	size_t				size_value;
	struct s_map_elm	*prev;
	struct s_map_elm	*next;
};

struct s_map
{
	t_map_elm		arr[FT_MAP_MAX_ELM];
	t_map_elm		*root;
	t_map_elm		*last;
	t_map_elm		*tail;
	t_2list			*big_value;
	t_2list			*del_list;
	size_t			count;
	size_t			deleted;
	size_t			size;
	char			err[FT_ERR_LEN];
};

// map/ft_map_add.c
t_map		*ft_map_add(t_map *map, char *key, char *value);
t_map_elm	*find_current_location(t_map_elm *elm, char *key);
void		insert_elm(t_map *map, t_map_elm *cur, t_map_elm *in);

/*
** map/ft_map_set.c
*/
t_map		*ft_map_set(t_map *map, char *key, char *value);

// map/ft_map_new.c
t_map		*ft_map_new(void);

// map/ft_map_getbykey.c
t_list		*ft_map_getbykey(t_map *map, t_list *value, char *key);
t_map_elm	*ft_map_get_elm(t_map *map, char *key);

// map/void	ft_map_print_all.c
void		ft_map_print_all(t_map *map);
void		ft_map_print_all_arr(t_map *map);
void		ft_map_stat(t_map *map);

// map/ft_map_from_env.c
int			ft_map_from_env(t_map *map, char **env);

// map/ft_map_del_elm.c
int			ft_map_del_elm(t_map *map, char *key);

/*
** map/ft_map_destroy.c
*/
int			ft_map_destroy(t_map **map);

#endif
