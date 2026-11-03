/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:27:56 by alopez-t          #+#    #+#             */
/*   Updated: 2026/11/03 15:01:06 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_pointer(va_list args, t_flags *flags)
{
	unsigned long	ptr;
	unsigned long	nb;
	char			*pfx;
	int				len;

	ptr = (unsigned long)va_arg(args, void *);
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	flags->hash = 1;
	flags->base = "0123456789abcdef";
	pfx = h_get_prefix((long)ptr, flags);
	len = h_get_abs(ptr, &nb, flags->base);
	return (print_universal(flags, nb, len, pfx));
}
