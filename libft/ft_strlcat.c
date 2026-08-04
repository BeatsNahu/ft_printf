/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:00:23 by alopez-t          #+#    #+#             */
/*   Updated: 2026/06/03 11:00:23 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	start_cpy;
	size_t	len_src;
	size_t	len_dst;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dest);
	start_cpy = len_dst;
	if (dstsize <= len_dst)
		return (len_src + dstsize);
	i = 0;
	while (start_cpy < (dstsize - 1) && src[i] != '\0')
	{
		dest[start_cpy] = src[i];
		start_cpy++;
		i++;
	}
	dest[start_cpy] = '\0';
	return (len_src + len_dst);
}
