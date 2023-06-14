/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:03:58 by lannur-s          #+#    #+#             */
/*   Updated: 2023/06/14 16:36:49 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_num_digits(unsigned long address, int base)
{
	int	num_digits;

	num_digits = 0;
	while ((int)address >= base)
	{
		address /= base;
		num_digits++;
	}
	return (num_digits);
}

static void	add_leading_zeros(unsigned long address)
{
	int	leading_zeros;

	leading_zeros = sizeof(address) * 2 - get_num_digits(address, BASE_HEX);
	while (leading_zeros > 0)
	{
		ft_putchar_fd('0', STD_OUT);
		leading_zeros--;
	}
}

static int	do_print(const char c, void *arg)
{
	unsigned long	address;

	if (c == 'c')
		ft_putchar_fd(*(int *)&arg, STD_OUT);
	else if (c == 's')
		ft_putstr_fd((char *)arg, STD_OUT);
	else if (c == 'd')
		ft_putnbr_fd(*((int *)arg), STD_OUT);
	else if (c == 'u')
		ft_putunsignednbr_fd(*((unsigned int *)arg), STD_OUT);
	else if (c == 'x')
		ft_putnbr_base_fd(*((int *)arg), STD_OUT, BASE_HEX, LOWER);
	else if (c == 'X')
		ft_putnbr_base_fd(*((int *)arg), STD_OUT, BASE_HEX, UPPER);
	else if (c == 'p')
	{
		address = (unsigned long)arg;
		add_leading_zeros(address);
		ft_putnbr_base_fd((unsigned long)arg, STD_OUT, BASE_HEX, UPPER);
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	void	*v;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("csdiuxXp", *format))
			{
				v = va_arg(args, void *);
				do_print(*format, v);
			}
			else if (*format == '%')
				ft_putchar_fd('%', STD_OUT);
		}
		else
			ft_putchar_fd(*format, STD_OUT);
		format++;
	}
	va_end(args);
	return (1);
}
