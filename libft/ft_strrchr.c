/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:00:56 by alopez-t          #+#    #+#             */
/*   Updated: 2026/06/04 11:38:35 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	letter;
	size_t			last_occurrence;

	last_occurrence = ft_strlen(s);
	letter = (unsigned char) c;
	while (s[last_occurrence] != letter && last_occurrence > 0)
		last_occurrence--;
	if (s[last_occurrence] == letter)
		return ((char *)&s[last_occurrence]);
	return (NULL);
}
