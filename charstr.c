/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camalfit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:00:01 by camalfit          #+#    #+#             */
/*   Updated: 2024/04/04 09:17:31 by camalfit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/********Words*****/
/*character*/
void	ft_printchar(char c, size_t *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

/*string*/
void	ft_printstr(char *str, size_t *counter)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_printchar(*str, counter);
		str++;
	}
}
