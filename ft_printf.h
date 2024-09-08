/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 23:54:12 by armirono          #+#    #+#             */
/*   Updated: 2024/08/30 18:08:13 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	modified_putchar(int c);
int	modified_putstr(char *s);
int	modified_putnbr(long n, int base, char capitalized);
int	putptr(unsigned long n, unsigned int base);
int	ft_printf(const char *format, ...);

#endif
