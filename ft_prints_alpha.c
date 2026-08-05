/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 10:39:41 by alopez-t          #+#    #+#             */
/*   Updated: 2026/08/05 15:58:20 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_char(va_list args, t_flags *flags)
{
	char	c;

	c = va_arg(args, int);
	if (flags->minus == 0)
	{
		h_print_space(flags->width - 1);
		write (1, &c, 1);
	}
	else
	{
		write (1, &c, 1);
		h_print_space(flags->width - 1);
	}
	if (flags->width != 0)
		return (flags->width);
	return (1);
}

int	print_string(va_list args, t_flags *flags)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags->has_prec == 1 && (size_t)flags->precision < ft_strlen(str))
		len = flags->precision;
	if (flags->minus == 1)
	{
		h_print_str(len, str);
		h_print_space(flags->width - len);
	}
	else
	{
		h_print_space(flags->width - len);
		h_print_str(len, str);
	}
	if (flags->width > len)
		return (flags->width);
	return (len);
}

int	print_percent(va_list args, t_flags *flags)
{
	(void)args;
	(void)flags;
	write (1, "%", 1);
	return (1);
}
/*
int	print_pointer(va_list args, t_flags *flags)
{
	return (0);
}
*/
