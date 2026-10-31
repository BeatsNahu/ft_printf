/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:27:59 by alopez-t          #+#    #+#             */
/*   Updated: 2026/10/31 14:29:27 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_string(va_list args, t_flags *flags)
{
	char	*str;
	int		len;

	(void)flags;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	h_print_str(len, str);
	return (len);
}
