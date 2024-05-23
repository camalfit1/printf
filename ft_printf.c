/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camalfit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:55:40 by camalfit          #+#    #+#             */
/*   Updated: 2024/04/04 09:40:58 by camalfit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_format(va_list va, const char *str, size_t *counter)
{
	if (*str == 'c')
		ft_printchar(va_arg(va, int), counter);
	else if (*str == 's')
		ft_printstr(va_arg(va, char *), counter);
	else if (*str == 'p')
		ft_pointer(va_arg(va, size_t), counter);
	else if (*str == 'i' || *str == 'd')
		ft_nbr(va_arg(va, int), counter);
	else if (*str == 'u')
		ft_unsigned_int(va_arg(va, unsigned int), counter);
	else if (*str == 'x')
		ft_hex(va_arg(va, unsigned int), counter, 'x');
	else if (*str == 'X')
		ft_hex(va_arg(va, unsigned int), counter, 'X');
	else if (*str == '%')
		ft_printchar(*str, counter);
}

int	ft_printf(const char *str, ...)
{
	va_list		va;
	size_t		counter;

	counter = 0;
	if (!str)
		return (0);
	counter = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(va, str, &counter);
		}
		else
			ft_printchar(*str, &counter);
		str++;
	}
	va_end(va);
	return (counter);
}
