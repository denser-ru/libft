#include "libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char	*d;

	d = (char *)malloc(len + 1);
	if (!d)
		return (NULL);
	d[len] = '\0';
	while (len--)
		d[len] = s1[len];
	return (d);
}
