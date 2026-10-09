/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
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
	total_printed = len_n;
	total_printed += flags->precision - total_printed;
	if (flags->plus || flags->space || num < 0)
		total_printed++;
	if (flags->has_prec == 1 || flags->minus == 1)
		flags->zero = 0;
	if (flags->minus == 1)
	{
		h_print_signe(flags);
		if (flags->has_prec == 1 && flags->precision > len_n)
			total_printed += h_print_chars((flags->precision - len_n), '0');
		ft_putnbr_fd(num, 1);
		if (len_n < flags->width)
			total_printed += h_print_chars((flags->width - total_printed), ' ');
	}
	else
	{
		if (total_printed < flags->width)
		{
			total_printed += h_print_chars((flags->width - total_printed), ' ');
			h_print_signe(flags);
		}
		else if (flags->has_prec == 1 && flags->precision > len_n)
		{
			h_print_signe(flags);
			total_printed += h_print_chars((flags->precision - len_n), '0');
		}
		else if (flags->zero == 1)
			total_printed += h_print_chars((flags->width - len_n), '0');
		ft_putnbr_fd(num, 1);
	}
	return (total_printed);
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
