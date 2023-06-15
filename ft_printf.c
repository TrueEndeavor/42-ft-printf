/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:03:58 by lannur-s          #+#    #+#             */
/*   Updated: 2023/06/15 19:04:44 by lannur-s         ###   ########.fr       */
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
		return (print_char(*(int *)&arg));
	else if (c == 's')
		return (print_string((char *)arg));
	else if (c == 'd' || c == 'i')
		return (print_nbr(*((int *)&arg)));
	else if (c == 'u')
		return (print_unsigned_nbr(*((unsigned int *)&arg)));
	else if (c == 'x')
		return (print_hexa(*((unsigned int *)&arg, BASE_HEX, LOWER));
	else if (c == 'X')
		return (print_hexa(*((unsigned int *)&arg, BASE_HEX, UPPER));
	else if (c == 'p')
	{
		address = (unsigned long)(*(int *)&arg);
		add_leading_zeros(address);
		return (print_hexa(address, BASE_HEX, UPPER), 1);
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
