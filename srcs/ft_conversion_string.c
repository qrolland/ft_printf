/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:43:21 by qrolland          #+#    #+#             */
/*   Updated: 2022/06/30 15:43:21 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_preci_string(t_flags fl, char *str, int *len)
{
	int		i;

	i = 0;
	if (!str)
	{
		if (fl.preci > 5 || fl.preci == -1)
		{
			ft_putstr_fd("(null)", 1);
			(*len) += 6;
		}
	}
	else
	{
		while (str[i] && i != fl.preci)
		{
			ft_putchar_fd(*(str + i), 1);
			i++;
			(*len)++;
		}
	}
}

void	ft_width_string(t_flags fl, char *str, int *len)
{
	int	strlen;

	if (!str)
	{
		if (fl.preci > 5 || fl.preci == -1)
			strlen = 6;
		else
			strlen = 0;
	}
	else
		strlen = ft_strlen(str);
	while (fl.width > strlen || (fl.width > fl.preci && fl.preci != -1))
	{
		if (fl.zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		fl.width--;
		(*len)++;
	}
}

int	ft_conversion_string(va_list arg, t_flags fl)
{
	int		len;
	char	*str;

	len = 0;
	str = va_arg(arg, char *);
	if (fl.minus)
	{
		ft_preci_string(fl, str, &len);
		ft_width_string(fl, str, &len);
	}
	else
	{
		ft_width_string(fl, str, &len);
		ft_preci_string(fl, str, &len);
	}
	return (len);
}
