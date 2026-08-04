/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:57:42 by alopez-t          #+#    #+#             */
/*   Updated: 2026/06/03 10:57:43 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_getlen(long int ln)
{
	int	i;

	i = 0;
	if (ln <= 0)
		i++;
	while (ln != 0)
	{
		ln = ln / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	ln;
	int			quantity;
	char		*in_text;

	ln = (long int) n;
	quantity = ft_getlen(ln);
	in_text = (char *)malloc(sizeof(char) * quantity + 1);
	if (!in_text)
		return (NULL);
	in_text[quantity] = '\0';
	if (ln == 0)
		in_text[0] = '0';
	if (ln < 0)
	{
		in_text[0] = '-';
		ln = ln * -1;
	}
	while (ln > 0)
	{
		in_text[quantity - 1] = (ln % 10) + '0';
		ln = ln / 10;
		quantity--;
	}
	return (in_text);
}
