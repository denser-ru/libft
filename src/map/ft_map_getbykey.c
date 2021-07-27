#include "libft.h"
#include "ft_map.h"

t_list	*ft_map_getbykey(t_map *map, t_list *value, char *key)
{
	t_map_elm	*elm;

	elm = map->root;
	while (elm)
	{
		if (!ft_strncmp(elm->key, key, elm->size_key))
		{
			value->content = elm->value;
			value->content_size = elm->size_value;
			return (value);
		}
		elm = elm->next;
	}
	return (NULL);
}