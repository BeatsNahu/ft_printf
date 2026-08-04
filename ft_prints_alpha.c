/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 10:39:41 by alopez-t          #+#    #+#             */
/*   Updated: 2026/08/03 10:39:41 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_char(va_list args, t_flags *flags)
{
	return ();
}

int	print_string(va_list args, t_flags *flags)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	ft_putstr(str);
	return (ft_strlen(str));
}

int	print_percent(va_list args, t_flags *flags)
{
	return ();
}
