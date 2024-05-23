/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camalfit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:53:50 by camalfit          #+#    #+#             */
/*   Updated: 2024/04/04 09:39:04 by camalfit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/*******Numbers******/
/*pointer*/
void	ft_pointer(size_t pointer, size_t *counter)
{
	char	*hex_digits;
	char	hex_string[17];
	int		i;

	hex_digits = "0123456789abcdef";
	i = 0;
	hex_string[16] = '\0';
	if (pointer == 0)
	{
		ft_printstr("(nil)", counter);
		return ;
	}
	while (pointer != 0)
	{
		hex_string[i++] = hex_digits[pointer % 16];
		pointer /= 16;
	}
	ft_printstr("0x", counter);
	while (i > 0)
	{
		ft_printchar(hex_string[--i], counter);
	}
}

/*numbers i/d*/
void	ft_nbr(int number, size_t *counter)
{
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*counter) += 11;
		return ;
	}
	if (number < 0)
	{
		ft_printchar('-', counter);
		ft_nbr(-number, counter);
	}
	else
	{
		if (number > 9)
		{
			ft_nbr(number / 10, counter);
		}
		ft_printchar(number % 10 + '0', counter);
	}
}

void	ft_unsigned_int(unsigned int i, size_t *counter)
{
	if (i >= 10)
	{
		ft_unsigned_int(i / 10, counter);
	}
	ft_printchar(i % 10 + '0', counter);
}

/*hexa x/X*/
void	ft_hex(unsigned int x, size_t *length, char xX)
{
	char	string[25];
	char	*character;
	int		i;

	i = 0;
	if (xX == 'X')
		character = "0123456789ABCDEF";
	else
		character = "0123456789abcdef";
	if (x == 0)
	{
		ft_printchar('0', length);
		return ;
	}
	while (x != 0)
	{
		string[i] = character[x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_printchar(string[i], length);
}
