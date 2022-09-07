/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:38:44 by qrolland          #+#    #+#             */
/*   Updated: 2022/06/30 15:38:50 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(long n)
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

void	ft_preci_int(long *n, int *len, t_flags fl)
{
	if (*n < 0)
	{
		ft_putchar_fd('-', 1);
		*n = -*n;
		(*len)++;
	}
	while (fl.preci > ft_intlen(*n))
	{
		ft_putchar_fd('0', 1);
		fl.preci--;
		(*len)++;
	}
	if (!(fl.preci == 0 && *n == 0))
	{
		ft_putnbr_fd(*n, 1);
		(*len) += ft_intlen(*n);
	}
	else if (fl.width)
	{
		ft_putchar_fd(' ', 1);
		(*len)++;
	}
}

void	ft_width_int(long *n, int *len, int neg, t_flags fl)
{
	int	length;

	length = fl.preci;
	if (fl.preci < (long int)ft_intlen(*n))
		length = (long int)ft_intlen(*n);
	if (*n < 0 || neg == 1)
		length++;
	if (*n < 0 && (fl.zero || fl.width - 1 == fl.preci))
	{
		ft_putchar_fd('-', 1);
		*n = -*n;
		(*len)++;
	}	
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

int	ft_conversion_int(va_list arg, t_flags fl)
{
	int			len;
	int			neg;
	long int	n;

	len = 0;
	neg = 0;
	n = va_arg(arg, int);
	if (n < 0)
		neg = 1;
	if (fl.minus)
	{
		ft_preci_int(&n, &len, fl);
		ft_width_int(&n, &len, neg, fl);
	}
	else
	{
		ft_width_int(&n, &len, neg, fl);
		ft_preci_int(&n, &len, fl);
	}
	return (len);
}
