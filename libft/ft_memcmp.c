/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:58:52 by alopez-t          #+#    #+#             */
/*   Updated: 2026/06/03 10:58:53 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*first_string;
	unsigned char	*second_string;

	first_string = (unsigned char *)s1;
	second_string = (unsigned char *)s2;
	i = 0;
	while (i < n && first_string[i] == second_string[i])
		i++;
	if (i < n)
		return (first_string[i] - second_string[i]);
	return (0);
}
