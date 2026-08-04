/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 19:41:34 by alopez-t          #+#    #+#             */
/*   Updated: 2026/07/25 19:41:36 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	execute_conversion(t_flags *flags, va_list args)
{
	static const t_print_func	g_dispatch[127] = {
	['c'] = print_char,
	['s'] = print_string,
	['%'] = print_percent,
	['d'] = print_int,
	['i'] = print_int,
	['u'] = print_unsigned,
	['x'] = print_hex,
	['X'] = print_hex
	};
	int							spec;

	spec = flags->specifier;
	if (spec >= 0 && spec <= 127 && g_dispatch[spec] != NULL)
		return (g_dispatch[spec](args, flags));
	return (0);
}

static void	parse_flag_char(char c, t_flags *flags)
{
	if (c == '-')
		flags->minus = 1;
	else if (c == '0')
		flags->zero = 1;
	else if (c == '#')
		flags->hash = 1;
	else if (c == ' ')
		flags->space = 1;
	else if (c == '+')
		flags->plus = 1;
}

void	get_flags(const char *str, int *i, t_flags *flags)
{
	(*i)++;
	while (ft_strchr("-0# +", (int)str[*i]))
		parse_flag_char(str[(*i)++], flags);
	while (ft_isdigit(str[*i]))
		flags->width = (flags->width * 10) + (str[(*i)++] - '0');
	if (str[*i] == '.')
	{
		flags->has_prec = 1;
		(*i)++;
		while (ft_isdigit(str[*i]))
			flags->precision = (flags->precision * 10) + (str[(*i)++] - '0');
	}
	if (ft_strchr("cspdiuxX%", (int)str[*i]))
		flags->specifier = str[(*i)++];
}

int	ft_printf(char const *str, ...)
{
	t_flags	flags;
	va_list	vargs;
	int		length_print;
	int		i;

	va_start(vargs, str);
	i = 0;
	length_print = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_bzero(&flags, sizeof(t_flags));
			get_flags(str, &i, &flags);
			length_print += execute_conversion(&flags, vargs);
		}
		else
		{
			write(1, &str[i], 1);
			length_print++;
			i++;
		}
	}
	va_end(vargs);
	return (length_print);
}
