#include "ft_printf.h"
#include "ft_frame.h"

int main()
{
	ft_putstr(ESC CLRSRC);
	ft_frame((t_frame){1, 1, 30, 3, 0, 0});
	ft_term_goto(2,2);
	ft_printf("Hello, World!\n");
	ft_term_goto(0,6);
	return 0;
}
