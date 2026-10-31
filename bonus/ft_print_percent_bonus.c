/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent_bonus.c                           :+:      :+:    :+:   */
/*                                                    :+:+         :+:     */
/*   By: alopez-t <alopez-t@student.42barcelona.com> #+  :+:       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:12:55 by alopez-t          #+#    #+#             */
/*   Updated: 2026/10/31 15:12:55 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_percent(va_list args, t_flags *flags)
{
	(void)args;
	if (flags->minus)
		flags->zero = 0;
	if (flags->minus)
	{
		ft_putchar_fd('%', 1);
		if (flags->width > 1)
			h_print_chars(flags->width - 1, ' ');
	}
	else
	{
		if (flags->width > 1)
		{
			if (flags->zero)
				h_print_chars(flags->width - 1, '0');
			else
				h_print_chars(flags->width - 1, ' ');
		}
		ft_putchar_fd('%', 1);
	}
	if (flags->width > 1)
		return (flags->width);
	return (1);
}
