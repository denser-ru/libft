#include "libft.h"
#include "ft_map.h"

t_map	*ft_map_new(void)
{
	t_map	*map;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->end = map->mem;
	map->tail = map->arr;
	map->last = map->arr;
	map->root = map->arr;
	return (map);
}