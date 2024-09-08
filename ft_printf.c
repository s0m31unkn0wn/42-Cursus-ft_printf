/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:53:09 by armirono          #+#    #+#             */
/*   Updated: 2024/09/04 16:32:58 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	read_format(char form, va_list ap)
{
	int	i;

	i = 0;
	if (form == 'c')
		i += modified_putchar(va_arg(ap, int));
	if (form == 's')
		i += modified_putstr(va_arg(ap, char *));
	if (form == 'p')
	{
		write(1, "0x", 2);
		i += (2 + putptr(va_arg(ap, unsigned long), 16));
	}
	if (form == 'd' || form == 'i')
		i += modified_putnbr(va_arg(ap, int), 10, form);
	if (form == 'u')
		i += modified_putnbr(va_arg(ap, unsigned int), 10, form);
	if (form == 'x' || form == 'X')
		i += modified_putnbr(va_arg(ap, unsigned int), 16, form);
	if (form == '%')
	{
		i += write(1, "%", 1);
	}
	return (i);
}

int	ft_printf(const char *form, ...)
{
	va_list			ap;
	unsigned int	i;

	i = 0;
	va_start(ap, form);
	while (*form)
	{
		if (*form == '%')
			i += read_format(*++form, ap);
		else
			i += write(1, form, 1);
		form++;
	}
	va_end(ap);
	return (i);
}
