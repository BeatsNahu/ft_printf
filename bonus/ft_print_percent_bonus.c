/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:07:14 by alopez-t          #+#    #+#             */
/*   Updated: 2026/11/06 15:09:26 by alopez-t         ###   ########.fr       */
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
