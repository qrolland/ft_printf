/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:39:00 by qrolland          #+#    #+#             */
/*   Updated: 2022/06/30 15:41:14 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexalen(unsigned long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	ft_putnbr_hexa(unsigned long n)
{
	if (n >= 16)
	{
		ft_putnbr_hexa(n / 16);
		ft_putnbr_hexa(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10 + 'a'), 1);
	}
}

void	ft_preci_ptr(unsigned long ptr, int *len, t_flags fl)
{
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		(*len) += 5;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		(*len) += 2;
		while (fl.preci > 0 && fl.preci > ft_hexalen(ptr))
		{
			ft_putchar_fd('0', 1);
			fl.preci--;
			(*len)++;
		}
		ft_putnbr_hexa(ptr);
		(*len) += ft_hexalen(ptr);
	}
}

void	ft_width_ptr(unsigned long ptr, int *len, t_flags fl)
{
	if (ptr)
	{
		while (fl.width > ft_hexalen(ptr) + 2)
		{
			ft_putchar_fd(' ', 1);
			fl.width--;
			(*len)++;
		}
	}
	else
	{
		while (fl.width > 5)
		{
			ft_putchar_fd(' ', 1);
			fl.width--;
			(*len)++;
		}	
	}
}

int	ft_conversion_ptr(va_list arg, t_flags fl)
{
	unsigned long	ptr;
	int				len;

	len = 0;
	ptr = va_arg(arg, unsigned long);
	if (fl.minus)
	{
		ft_preci_ptr(ptr, &len, fl);
		ft_width_ptr(ptr, &len, fl);
	}
	else
	{
		ft_width_ptr(ptr, &len, fl);
		ft_preci_ptr(ptr, &len, fl);
	}
	return (len);
}
