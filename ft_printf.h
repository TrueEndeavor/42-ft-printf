/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:04:15 by lannur-s          #+#    #+#             */
/*   Updated: 2023/06/15 15:54:13 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h> // for NULL
# include <stdio.h>
# include "./libft/libft.h"

# define STD_OUT 1
# define BASE_HEX 16
# define UPPER 1
# define LOWER 0

int		ft_printf(const char *format, ...);
int		print_char(char c);
int		print_string(char *s);
int		print_nbr(int n);
int		print_unsigned_nbr(unsigned int un);
int		print_hexa(int n, int base, int uppercase);

#endif
