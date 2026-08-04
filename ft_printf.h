/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 19:41:12 by alopez-t          #+#    #+#             */
/*   Updated: 2026/07/25 19:41:15 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_flags
{
	int	specifier;
	int	width;
	int	precision;
	int	has_prec;
	int	minus;
	int	zero;
	int	hash;
	int	space;
	int	plus;
}	t_flags;

int		ft_printf(char const *str, ...);
typedef int	(*t_print_func)(va_list, t_flags *);
void	get_flags(const char *str, int *i, t_flags *flags);
int		print_char(va_list args, t_flags *flags);
int		print_string(va_list args, t_flags *flags);
int		print_percent(va_list args, t_flags *flags);
int		print_int(va_list args, t_flags *flags);
int		print_unsigned(va_list args, t_flags *flags);
int		print_hex(va_list args, t_flags *flags);

#endif
