/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:06:59 by alopez-t          #+#    #+#             */
/*   Updated: 2026/11/06 15:09:12 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_int(va_list args, t_flags *flags)
{
	char			*pfx;
	long			num;
	unsigned long	nb;
	int				len;

	if (flags->has_prec || flags->minus)
		flags->zero = 0;
	flags->hash = 0;
	num = (long)va_arg(args, int);
	flags->base = "0123456789";
	pfx = h_get_prefix(num, flags);
	if (num < 0)
		num = -num;
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
