/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 00:03:58 by armirono          #+#    #+#             */
/*   Updated: 2024/08/30 18:26:56 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	modified_putchar(int c)
{
	return (write(1, &c, 1));
}

int	modified_putstr(char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (*s)
		i += write(1, s++, 1);
	return (i);
}

int	modified_putnbr(long n, int base, char capitalized)
{
	int		i;
	char	*digits;

	if (capitalized == 'X')
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	i = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return (modified_putnbr(-n, base, capitalized) + 1);
	}
	if (n < base)
		return (i + modified_putchar(digits[n]));
	else
	{
		i = modified_putnbr(n / base, base, capitalized);
		return (i + modified_putnbr(n % base, base, capitalized));
	}
}

int	putptr(unsigned long n, unsigned int base)
{
	int		i;
	char	*digits;

	digits = "0123456789abcdef";
	i = 0;
	if (n < base)
		return (i + modified_putchar(digits[n]));
	else
	{
		i = putptr(n / base, base);
		return (i + putptr(n % base, base));
	}
}
