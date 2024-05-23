/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camalfit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:07:41 by camalfit          #+#    #+#             */
/*   Updated: 2024/04/04 09:16:39 by camalfit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(const char *str, ...);

/* format functions*/
void	ft_printchar(char c, size_t *counter);
void	ft_printstr(char *str, size_t *counter);
void	ft_nbr(int number, size_t *length);
void	ft_unsigned_int(unsigned int i, size_t *counter);
void	ft_hex(unsigned int x, size_t *length, char xX);
void	ft_pointer(size_t pointer, size_t *counter);
void	ft_printpercent(void);

#endif
