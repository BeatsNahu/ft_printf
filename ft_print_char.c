/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:27:26 by alopez-t          #+#    #+#             */
/*   Updated: 2026/10/31 14:29:48 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_char(va_list args, t_flags *flags)
{
	char	c;

	(void)flags;
	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
	return (1);
}
