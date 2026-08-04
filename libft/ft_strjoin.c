/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:00:17 by alopez-t          #+#    #+#             */
/*   Updated: 2026/06/03 11:00:17 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sz_s1;
	size_t	sz_s2;
	char	*new_str;

	sz_s1 = ft_strlen(s1);
	sz_s2 = ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (sz_s1 + sz_s2 + 1));
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1, sz_s1);
	ft_memcpy(&new_str[sz_s1], s2, sz_s2);
	new_str[sz_s1 + sz_s2] = '\0';
	return (new_str);
}
