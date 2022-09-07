/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_unsigned.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:37:47 by qrolland          #+#    #+#             */
/*   Updated: 2022/06/30 15:38:32 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsignedlen(long unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_preci_unsigned(long unsigned int n, int *len, t_flags fl)
{
	while (fl.preci > ft_unsignedlen(n))
	{
		ft_putchar_fd('0', 1);
		fl.preci--;
		(*len)++;
	}
	if (!(fl.preci == 0 && n == 0))
	{
		ft_putnbr_fd(n, 1);
		(*len) += ft_unsignedlen(n);
	}
	else if (fl.width)
	{
		ft_putchar_fd(' ', 1);
		(*len)++;
	}
}

void	ft_width_unsigned(long unsigned int n, int *len, t_flags fl)
{
	int	length;

	length = fl.preci;
	if (fl.preci < ft_unsignedlen(n))
		length = ft_unsignedlen(n);
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

int	ft_conversion_unsigned(va_list arg, t_flags fl)
{
	int					len;
	long unsigned int	n;

	len = 0;
	n = va_arg(arg, unsigned int);
	if (fl.minus)
	{
		ft_preci_unsigned(n, &len, fl);
		ft_width_unsigned(n, &len, fl);
	}
	else
	{
		ft_width_unsigned(n, &len, fl);
		ft_preci_unsigned(n, &len, fl);
	}
	return (len);
}
