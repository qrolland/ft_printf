/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:42:29 by qrolland          #+#    #+#             */
/*   Updated: 2022/06/30 15:42:29 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_read_conversion(char c, va_list arg, t_flags fl)
{
	if (c == 'c')
		return (ft_conversion_char(arg, fl));
	if (c == 's')
		return (ft_conversion_string(arg, fl));
	if (c == 'p')
		return (ft_conversion_ptr(arg, fl));
	if (c == 'd' || c == 'i')
		return (ft_conversion_int(arg, fl));
	if (c == 'u')
		return (ft_conversion_unsigned(arg, fl));
	if (c == 'x' || c == 'X')
		return (ft_conversion_hex(arg, fl, c));
	if (c == '%')
		return (ft_conversion_percent(fl));
	return (0);
}

const char	*ft_read_arg(const char *str, va_list arg, int *len)
{
	t_flags	fl;

	fl.minus = 0;
	fl.zero = 0;
	fl.width = 0;
	fl.preci = -1;
	str = ft_read_flags(str, arg, &fl);
	*len += ft_read_conversion(*str, arg, fl);
	return (str);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;

	len = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format = ft_read_arg(format + 1, arg, &len);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			len++;
		}
		format++;
	}
	va_end(arg);
	return (len);
}
