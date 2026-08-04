/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:58:44 by alopez-t          #+#    #+#             */
/*   Updated: 2026/06/03 10:58:45 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	caracter;

	src = (unsigned char *)s;
	caracter = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (src[i] == caracter)
			return ((void *)&src[i]);
		i++;
	}
	return (NULL);
}
