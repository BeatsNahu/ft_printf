/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:00:01 by alopez-t          #+#    #+#             */
/*   Updated: 2026/06/03 11:00:02 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	size;
	char	*text_dup;

	size = ft_strlen(src);
	text_dup = (char *) malloc ((size + 1) * sizeof (char));
	if (!text_dup)
		return (NULL);
	ft_memcpy(text_dup, src, size);
	text_dup[size] = '\0';
	return (text_dup);
}
