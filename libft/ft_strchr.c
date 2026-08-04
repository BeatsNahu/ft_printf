/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:59:53 by alopez-t          #+#    #+#             */
/*   Updated: 2026/06/04 11:37:52 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	letter;
	size_t			i;

	i = 0;
	letter = (unsigned char) c;
	while (s[i] != letter && s[i] != '\0')
		i++;
	if (s[i] == letter)
		return ((char *)&s[i]);
	return (NULL);
}
