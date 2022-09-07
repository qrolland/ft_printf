/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:42:13 by qrolland          #+#    #+#             */
/*   Updated: 2022/06/30 15:42:22 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion_char(va_list arg, t_flags fl)
{
	int	len;

	len = 1;
	if (fl.minus)
		ft_putchar_fd((char)va_arg(arg, int), 1);
	while (fl.width > 1)
	{
		ft_putchar_fd(' ', 1);
		fl.width--;
		len++;
	}
	if (!fl.minus)
		ft_putchar_fd((char)va_arg(arg, int), 1);
	return (len);
}
