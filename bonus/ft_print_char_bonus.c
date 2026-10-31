/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    :+:+         :+:     */
/*   By: alopez-t <alopez-t@student.42barcelona.com> #+  :+:       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:12:55 by alopez-t          #+#    #+#             */
/*   Updated: 2026/10/31 15:12:55 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_char(va_list args, t_flags *flags)
{
	char	c;

	c = va_arg(args, int);
	if (flags->minus == 0)
	{
		h_print_chars(flags->width - 1, ' ');
		ft_putchar_fd(c, 1);
	}
	else
	{
		ft_putchar_fd(c, 1);
		h_print_chars(flags->width - 1, ' ');
	}
	if (flags->width > 0)
		return (flags->width);
	return (1);
}
