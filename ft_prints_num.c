/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/08/03 10:39:36 by alopez-t          #+#    #+#             */
/*   Updated: 2026/10/09 19:10:38 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	get_abs_len(int num, unsigned long *nb)
{
	unsigned long	tmp;
	int				len;

	if (num < 0)
		*nb = (unsigned long)(-(long)num);
	else
		*nb = (unsigned long)num;
	tmp = *nb;
	len = 1;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		len++;
	}
	return (len);
}

static int	print_int_right(int num, unsigned long nb, int len, t_flags *f)
{
	int	zeros;
	int	pad;

	zeros = 0;
	if (f->has_prec && f->precision > len)
		zeros = f->precision - len;
	pad = f->width - (len + zeros);
	if (num < 0 || f->plus || f->space)
		pad -= 1;
	if (pad < 0)
		pad = 0;
	if (!f->zero)
		h_print_chars(pad, ' ');
	h_print_signe(num, f);
	if (f->zero)
		h_print_chars(pad, '0');
	h_print_chars(zeros, '0');
	if (len > 0)
		h_putnbr_abs(nb);
	return (len + zeros + pad + (num < 0 || f->plus || f->space));
}

int	print_int(va_list args, t_flags *flags)
{
	int				num;
	unsigned long	nb;
	int				len_n;
	int				total_printed;

	num = va_arg(args, int);
	len_n = get_abs_len(num, &nb);
	if (flags->has_prec && flags->precision == 0 && num == 0)
		len_n = 0;
	total_printed = len_n;
	if (flags->plus || flags->space || num < 0)
		total_printed++;
	if (flags->has_prec || flags->minus)
		flags->zero = 0;
	if (flags->minus)
	{
		h_print_signe(num, flags);
		if (flags->has_prec && flags->precision > len_n)
			total_printed += h_print_chars((flags->precision - len_n), '0');
		if (len_n > 0)
			h_putnbr_abs(nb);
		if (total_printed < flags->width)
			total_printed += h_print_chars((flags->width - total_printed), ' ');
		return (total_printed);
	}
	return (print_int_right(num, nb, len_n, flags));
}

int	print_unsigned(va_list args, t_flags *flags)
{
	(void)args;
	(void)flags;
	return (0);
}

int	print_hex(va_list args, t_flags *flags)
{
	char			*base;
	unsigned int	num;
	int				total_printed;

	num = va_arg(args, unsigned int);
	if (flags->hash == 1 && num != 0)
		ft_putstr_fd("0x", 1);
	base = "0123456789abcdef";
	if (flags->specifier == 'X')
		base = "0123456789ABCDEF";
	total_printed = h_puthex_recursive(num, base);
	return (total_printed);
}
