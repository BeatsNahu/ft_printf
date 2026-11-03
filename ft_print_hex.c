/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:27:45 by alopez-t          #+#    #+#             */
/*   Updated: 2026/11/03 15:07:51 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_hex(va_list args, t_flags *flags)
{
	char			*pfx;
	unsigned int	num;
	unsigned long	nb;
	int				len;

	num = va_arg(args, unsigned int);
	if (flags->specifier == 'X')
		flags->base = "0123456789ABCDEF";
	else
		flags->base = "0123456789abcdef";
	pfx = h_get_prefix((long)num, flags);
	len = h_get_abs(num, &nb, flags->base);
	return (print_universal(flags, nb, len, pfx));
}
