/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:27:51 by alopez-t          #+#    #+#             */
/*   Updated: 2026/11/03 15:04:50 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_int(va_list args, t_flags *flags)
{
	char			*pfx;
	long			num;
	unsigned long	nb;
	int				len;

	flags->hash = 0;
	num = (long)va_arg(args, int);
	flags->base = "0123456789";
	pfx = h_get_prefix(num, flags);
	if (num < 0)
		num = -num;
	len = h_get_abs((unsigned long)num, &nb, flags->base);
	return (print_universal(flags, nb, len, pfx));
}
