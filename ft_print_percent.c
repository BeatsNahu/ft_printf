/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:27:54 by alopez-t          #+#    #+#             */
/*   Updated: 2026/10/31 14:29:34 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_percent(va_list args, t_flags *flags)
{
	(void)args;
	(void)flags;
	ft_putchar_fd('%', 1);
	return (1);
}
