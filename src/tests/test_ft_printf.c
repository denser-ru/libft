#include "libft.h"
#include "ft_frame.h"
#include <stdio.h>

int main()
{
//	ft_putstr(ESC CLRSRC);
//	ft_frame((t_frame){1, 1, 24, 2, 0, 0});
//	ft_term_goto(5,2);
//	ft_printf(ESC "[%dm" "Привет, " ESC "[%dm" "Мир" ESC "[%dm" ESC "[0m"
//		"! =)\n", F_RED, F_BLUE, F_WHITE);
//	ft_term_goto(0,4);
	ft_printf("my   строка проверки: %d\n", 1.01);
	printf("orig строка проверки: %d\n", 1.01);
	ft_putstr("\n");
	ft_printf("строка проверки: %d\n", 1);
	printf("строка проверки: %d\n", 1);
	ft_putstr("\n");
	ft_printf("строка проверки: %f\n", 1.01);
	printf("строка проверки: %f\n", 1.01);
	ft_putstr("\n");
	ft_printf("строка проверки: %5f\n", 1.0);
	printf("строка проверки: %5f\n", 1.0);
	ft_putstr("\n");
	ft_printf("строка проверки: %5.f\n", 1.0);
	printf("строка проверки: %5.f\n", 1.0);
//	ft_term_goto(0,6);
	return 0;
}
