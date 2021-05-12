#include "ft_printf.h"
#include "ft_frame.h"

int main()
{
	ft_putstr(ESC CLRSRC);
	ft_frame((t_frame){1, 1, 24, 2, 0, 0});
	ft_term_goto(5,2);
	ft_printf(ESC "[%dm" "Привет, " ESC "[%dm" "Мир" ESC "[%dm" ESC "[0m"
		"! =)\n", F_RED, F_BLUE, F_WHITE);
	ft_term_goto(0,6);
	return 0;
}
