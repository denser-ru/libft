#include "libft.h"
#include "ft_map.h"

void	ft_map_print_all(t_map_elm *arr)
{
	while (arr)
	{
		ft_putnstr(arr->key, arr->size_key);
		ft_putchar('=');
		ft_putnstr(arr->value, arr->size_value);
		ft_putchar('\n');
		arr = arr->next;
	}
}