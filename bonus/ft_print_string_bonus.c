/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_bonus.c                            :+:      :+:    :+:   */
/*                                                    :+:+         :+:     */
/*   By: alopez-t <alopez-t@student.42barcelona.com> #+  :+:       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:12:55 by alopez-t          #+#    #+#             */
/*   Updated: 2026/10/31 15:12:55 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_string(va_list args, t_flags *flags)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (!str && (!flags->has_prec || flags->precision >= 6))
		str = "(null)";
	else if (!str && (flags->has_prec && flags->precision < 6))
		str = "";
	len = ft_strlen(str);
	if (flags->has_prec && (size_t)flags->precision < ft_strlen(str))
		len = flags->precision;
	if (flags->minus == 1)
	{
		h_print_str(len, str);
		h_print_chars(flags->width - len, ' ');
	}
	else
	{
		h_print_chars(flags->width - len, ' ');
		h_print_str(len, str);
	}
	if (flags->width > len)
		return (flags->width);
	return (len);
}
