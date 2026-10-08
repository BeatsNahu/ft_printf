/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:27:02 by alopez-t          #+#    #+#             */
/*   Updated: 2026/10/08 16:40:15 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	h_print_chars(int i, char c)
{
	int	counter;

	counter = 0
	while (i > 0)
	{
		write (1, &c, 1);
		i--;
		counter++;
	}
	return (counter);
}

void	h_print_str(int len, char *str)
{
	int	i;

	i = 0;
	while (i < len)
	{
		write (1, &str[i], 1);
		i++;
	}
}

int	h_puthex_recursive(unsigned long n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += h_puthex_recursive(n / 16, base);
		len += h_puthex_recursive(n % 16, base);
	}
	else
	{
		write (1, &base[n], 1);
		len++;
	}
	return (len);
}

int	h_print_signe(int n, t_flags *flags)
{
	if (flags->plus == 1)
		h_print_chars(1, '+');
	else if (flags->space == 1)
		h_print_chars(1, ' ');
	else if (n < 0)
		h_print_chars(1, '-');
	else
		return (0);
	return (1);
}
