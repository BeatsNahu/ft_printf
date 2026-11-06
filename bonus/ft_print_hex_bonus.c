/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:06:41 by alopez-t          #+#    #+#             */
/*   Updated: 2026/11/06 15:09:02 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_hex(va_list args, t_flags *flags)
{
	char			*pfx;
	unsigned int	num;
	unsigned long	nb;
	int				len;

	if (flags->has_prec || flags->minus)
		flags->zero = 0;
	flags->plus = 0;
	flags->space = 0;
	num = va_arg(args, unsigned int);
	if (flags->specifier == 'X')
		flags->base = "0123456789ABCDEF";
	else
		flags->base = "0123456789abcdef";
	pfx = h_get_prefix(num, flags);
	len = h_get_abs(num, &nb, flags->base);
	if (flags->has_prec && flags->precision == 0 && nb == 0)
		len = 0;
	if (flags->has_prec && flags->precision > len)
		flags->zeros = flags->precision - len;
	flags->pad = flags->width - (len + flags->zeros + (int)ft_strlen(pfx));
	if (flags->pad < 0)
		flags->pad = 0;
	return (print_universal(flags, nb, len, pfx));
}
