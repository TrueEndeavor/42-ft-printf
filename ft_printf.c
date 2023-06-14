/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:03:58 by lannur-s          #+#    #+#             */
/*   Updated: 2023/06/14 18:10:45 by lannur-s         ###   ########.fr       */
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
		return (ft_putchar_fd(*(int *)&arg, STD_OUT), 1);
	else if (c == 's')
		return (ft_putstr_fd((char *)arg, STD_OUT), 1);
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(*((int *)arg), STD_OUT), 1);
	else if (c == 'u')
		return (ft_putunsignednbr_fd(*((unsigned int *)arg), STD_OUT), 1);
	else if (c == 'x')
		return (ft_putnbr_base_fd(*((int *)arg), STD_OUT, BASE_HEX, LOWER), 1);
	else if (c == 'X')
		return (ft_putnbr_base_fd(*((int *)arg), STD_OUT, BASE_HEX, UPPER), 1);
	else if (c == 'p')
	{
		address = (unsigned long)arg;
		add_leading_zeros(address);
		return (ft_putnbr_base_fd((unsigned long)arg, STD_OUT, BASE_HEX, UPPER), 1);
	}
	else if (c == '%')
		return (ft_putchar_fd('%', STD_OUT), 1);
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	void	*v;
	int		length;

	length = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%' && ft_strchr("csdiuxXp%", *(format + 1)) != 0)
		{
			format++;
			v = va_arg(args, void *);
			length += do_print(*format, v);
		}
		else
		{
			ft_putchar_fd(*format, STD_OUT);
			length++;
		}
		format++;
	}
	va_end(args);
	return (length);
}
