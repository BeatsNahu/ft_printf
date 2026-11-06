/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:07:28 by alopez-t          #+#    #+#             */
/*   Updated: 2026/11/06 15:09:48 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	print_null_pointer(t_flags *flags)
{
	if (flags->minus)
	{
		ft_putstr_fd("(nil)", 1);
		h_print_chars(flags->width - 5, ' ');
	}
	else
	{
		h_print_chars(flags->width - 5, ' ');
		ft_putstr_fd("(nil)", 1);
	}
	if (flags->width > 5)
		return (flags->width);
	return (5);
}

int	print_pointer(va_list args, t_flags *flags)
{
	unsigned long	ptr;
	unsigned long	nb;
	char			*pfx;
	int				len;

	ptr = (unsigned long)va_arg(args, void *);
	if (!ptr)
		return (print_null_pointer(flags));
	if (flags->minus || flags->has_prec)
		flags->zero = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 1;
	flags->base = "0123456789abcdef";
	pfx = h_get_prefix((long)ptr, flags);
	len = h_get_abs(ptr, &nb, flags->base);
	if (flags->has_prec && flags->precision > len)
		flags->zeros = flags->precision - len;
	flags->pad = flags->width - (len + flags->zeros + (int)ft_strlen(pfx));
	if (flags->pad < 0)
		flags->pad = 0;
	return (print_universal(flags, nb, len, pfx));
}
