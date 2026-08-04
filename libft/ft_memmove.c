/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:59:04 by alopez-t          #+#    #+#             */
/*   Updated: 2026/06/03 10:59:04 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*text_dest;
	unsigned char	*text_src;

	text_dest = (unsigned char *)dest;
	text_src = (unsigned char *)src;
	if (dest > src)
	{
		while (n > 0)
		{
			text_dest[n - 1] = text_src[n - 1];
			n--;
		}
		return (dest);
	}
	ft_memcpy(dest, src, n);
	return (dest);
}
