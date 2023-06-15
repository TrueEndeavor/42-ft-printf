/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:58:04 by lannur-s          #+#    #+#             */
/*   Updated: 2023/06/15 19:03:10 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(int n)
{
	long	nbr;
	int		len;

	nbr = n;
	len = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', STD_OUT);
		nbr = -nbr;
		len++;
	}
	if (nbr >= 10)
		len += print_nbr(nbr / 10);
	ft_putchar_fd(nbr % 10 + '0', STD_OUT);
	len++;
	return (len);
}

