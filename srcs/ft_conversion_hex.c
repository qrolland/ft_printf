/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:41:52 by qrolland          #+#    #+#             */
/*   Updated: 2022/06/30 15:43:55 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	ft_putnbr_hex(unsigned int n, char c)
{
	if (n >= 16)
	{
		ft_putnbr_hex(n / 16, c);
		ft_putnbr_hex(n % 16, c);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
		{
			if (c == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			if (c == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}
}

void	ft_preci_hex(unsigned int hex, int *len, t_flags fl, char c)
{
	while (fl.preci > ft_hexlen(hex))
	{
		ft_putchar_fd('0', 1);
		fl.preci--;
		(*len)++;
	}
	if (!(fl.preci == 0 && hex == 0))
	{
		ft_putnbr_hex(hex, c);
		(*len) += ft_hexlen(hex);
	}
	else if (fl.width)
	{
		ft_putchar_fd(' ', 1);
		(*len)++;
	}
}

void	ft_width_hex(unsigned int hex, int *len, t_flags fl)
{
	int		length;

	length = fl.preci;
	if (fl.preci < ft_hexlen(hex))
		length = ft_hexlen(hex);
	while (fl.width > length)
	{
		if (fl.zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		fl.width--;
		(*len)++;
	}
}

int	ft_conversion_hex(va_list arg, t_flags fl, char c)
{
	int				len;
	unsigned int	hex;

	len = 0;
	hex = va_arg(arg, unsigned int);
	if (fl.minus)
	{
		ft_preci_hex(hex, &len, fl, c);
		ft_width_hex(hex, &len, fl);
	}
	else
	{
		ft_width_hex(hex, &len, fl);
		ft_preci_hex(hex, &len, fl, c);
	}
	return (len);
}
