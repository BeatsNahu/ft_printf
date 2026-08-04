/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-t <alopez-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:59:31 by alopez-t          #+#    #+#             */
/*   Updated: 2026/06/03 10:59:32 by alopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	ln;
	char		c;

	ln = (long int)n;
	if (ln < 0)
	{
		write (fd, "-", 1);
		ln = ln * -1;
	}
	if (ln >= 10)
	{
		ft_putnbr_fd(ln / 10, fd);
	}
	c = (ln % 10) + '0';
	write (fd, &c, 1);
}
