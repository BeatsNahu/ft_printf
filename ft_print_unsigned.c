/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:28:01 by alopez-t          #+#    #+#             */
/*   Updated: 2026/11/03 14:58:58 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_unsigned(va_list args, t_flags *flags)
{
	char			*pfx;
	unsigned int	num;
	unsigned long	nb;
	int				len;

	num = va_arg(args, unsigned int);
	flags->base = "0123456789";
	pfx = h_get_prefix(num, flags);
	len = h_get_abs(num, &nb, flags->base);
	return (print_universal(flags, nb, len, pfx));
}
