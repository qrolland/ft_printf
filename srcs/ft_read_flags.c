/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:43:03 by qrolland          #+#    #+#             */
/*   Updated: 2022/06/30 15:45:08 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_width_flags(const char *str, va_list arg, t_flags *fl)
{
	if (*str == '*')
	{
		fl->width = va_arg(arg, int);
		str++;
	}
	else
	{
		fl->width = ft_atoi(str);
		while (ft_isdigit((int)*str))
			str++;
		str--;
	}
	return (str);
}

const char	*ft_preci_flags(const char *str, va_list arg, t_flags *fl)
{
	fl->preci = 0;
	str++;
	if (*str == '*')
	{
		fl->preci = va_arg(arg, int);
		str++;
	}
	else
	{
		fl->preci = ft_atoi(str);
		while (ft_isdigit((int)*str))
			str++;
		str--;
	}
	return (str);
}

const char	*ft_read_flags(const char *str, va_list arg, t_flags *fl)
{
	while (ft_strchr("-0.*123456789", *str))
	{
		if (*str == '-')
			fl->minus = 1;
		else if (*str == '0')
			fl->zero = 1;
		else if (*str == '.')
		{
			str = ft_preci_flags(str, arg, fl);
		}
		else if (ft_isdigit((int)*str) || *str == '*')
		{
			str = ft_width_flags(str, arg, fl);
		}
		str++;
	}
	if (fl->preci >= 0)
		fl->zero = 0;
	return (str);
}
