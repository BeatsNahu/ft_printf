/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:28:57 by alopez-t          #+#    #+#             */
/*   Updated: 2026/10/31 14:29:16 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	h_print_chars(int i, char c)
{
	int	counter;

	counter = 0;
	while (i > 0)
	{
		write(1, &c, 1);
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
		write(1, &str[i], 1);
		i++;
	}
}

void	h_putnbr_base(unsigned long n, char *base)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
		h_putnbr_base(n / base_len, base);
	write(1, &base[n % base_len], 1);
}

char	*h_get_prefix(long num, t_flags *flags)
{
	if (num < 0)
		return ("-");
	else if (flags->plus)
		return ("+");
	else if (flags->space)
		return (" ");
	else if (flags->hash && num != 0)
	{
		if (flags->specifier == 'x' || flags->specifier == 'p')
			return ("0x");
		else if (flags->specifier == 'X')
			return ("0X");
	}
	return ("");
}

int	h_get_abs(long n, unsigned long *nb, char *base)
{
	unsigned long	tmp;
	int				len;
	size_t			base_len;

	if (n < 0)
		*nb = (unsigned long)(-(n + 1)) + 1;
	else
		*nb = (unsigned long)n;
	tmp = *nb;
	len = 1;
	base_len = ft_strlen(base);
	while (tmp >= base_len)
	{
		tmp = tmp / base_len;
		len++;
	}
	return (len);
}
