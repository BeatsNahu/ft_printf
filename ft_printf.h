/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:28:37 by alopez-t          #+#    #+#             */
/*   Updated: 2026/10/31 14:37:03 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	char	*base;
	int		specifier;
	int		width;
	int		precision;
	int		has_prec;
	int		minus;
	int		zero;
	int		hash;
	int		space;
	int		plus;
	int		pad;
	int		zeros;
}			t_flags;

int			ft_printf(char const *str, ...);
typedef int	(*t_print_func)(va_list, t_flags *);
void		get_flags(const char *str, int *i, t_flags *flags);

/*
	Functions for the specifiers
 */
int			print_char(va_list args, t_flags *flags);
int			print_string(va_list args, t_flags *flags);
int			print_percent(va_list args, t_flags *flags);
int			print_int(va_list args, t_flags *flags);
int			print_unsigned(va_list args, t_flags *flags);
int			print_hex(va_list args, t_flags *flags);
int			print_pointer(va_list args, t_flags *flags);
int			print_universal(t_flags *flags, unsigned long nb, int len,
				char *pfx);

/*
	Functions for help
*/

int			h_print_chars(int i, char c);
void		h_print_str(int len, char *str);
void		h_putnbr_base(unsigned long n, char *base);
char		*h_get_prefix(long num, t_flags *flags);
int			h_get_abs(long n, unsigned long *nb, char *base);

#endif
