/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_term_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 01:15:07 by cayako            #+#    #+#             */
/*   Updated: 2021/11/14 13:59:39 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <unistd.h>

/*
** Для таких задач используются коды управления терминалом.
** Почитать подробно: man console_codes.
** Пример использования:
*/

/*
**  Сюда будут записаны размеры экрана.
**
** int width, height;
*/

/*
**  Отмена построчной буферизации в libc.
**  Если этого не сделать, следующие команды не уйдут терминалу,
**  пока libc не получит от программы код '\n'.
**
** setvbuf(stdout, NULL, _IONBF, 0);
*/

/*
**  Попытка установить координаты курсора в 255,255
**  (терминал установит курсор в правый нижний угол).
**  Затем запрос координат курсора у терминала.
**
** fputs("\x1B[255;255H\x1B[6n", stdout);
*/

/*
**  Чтение координат курсора.
**  Координаты считаются с 1, поэтому полученные значения
**  можно смело считать за размеры терминала.
**  Функция scanf должна вернуть число 2.
** scanf("\x1B[%d;%dR", &height, &width);
*/

void	get_term_size(unsigned int *width, unsigned int *height)
{
	struct winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	*height = w.ws_row;
	*width = w.ws_col;
}
