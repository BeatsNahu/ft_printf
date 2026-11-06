/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_universal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:02:35 by alopez-t          #+#    #+#             */
/*   Updated: 2026/11/06 15:04:45 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_universal(t_flags *flags, unsigned long nb, int len, char *pfx)
{
	int	printed;

	printed = 0;
	if (flags->minus)
	{
		ft_putstr_fd(pfx, 1);
		printed += (int)ft_strlen(pfx);
		printed += h_print_chars(flags->zeros, '0');
	}
	else
	{
		if (!flags->zero)
			printed += h_print_chars(flags->pad, ' ');
		ft_putstr_fd(pfx, 1);
		printed += (int)ft_strlen(pfx);
		printed += h_print_chars(flags->zeros, '0');
		if (flags->zero)
			printed += h_print_chars(flags->pad, '0');
	}
	if (len > 0)
		h_putnbr_base(nb, flags->base);
	printed += len;
	if (flags->minus)
		printed += h_print_chars(flags->pad, ' ');
	return (printed);
}
