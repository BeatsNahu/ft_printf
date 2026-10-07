/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*      i                                          +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 10:39:36 by alopez-t          #+#    #+#             */
/*   Updated: 2026/08/03 10:39:37 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	get_num_len(long n)
{
	int	n_len;

	n_len = 1;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		n = n / 10;
		n_len++;
	}
	return (n_len);
}

int	print_int(va_list args, t_flags *flags)
{
	int	len_n;
	int	num;
	int	total_printed;

	num = va_arg(args, int);
	len_n = get_num_len(num);
	if (flags->minus == 1)
	{
		flags->zero = 0;
		total_printed += print_signe(flags);
		if (flags->precision == 1 && flags->precision > len)
			total_printed += h_print_chars((len_n - flags->precision), '0');
		ft_putnbr(num);
		if (len_n < flags->width)
			total_printed += h_print_chars((flags->width - total_printed), ' ');
	}
	return (len);
}

int	print_unsigned(va_list args, t_flags *flags)
{
	(void)args;
	(void)flags;
	return (0);
}

int	print_hex(va_list args, t_flags *flags)
{
	(void)args;
	(void)flags;
	/*
	if (flags->hash == 1)
		write (1, "0x", 2);
	base = "0123456789abcdef";
	if (flags->specifier == 'X')
		base = "0123456789ABCDEF";
		*/
	return (0);
}
