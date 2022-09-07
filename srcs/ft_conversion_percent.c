/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_percent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:43:13 by qrolland          #+#    #+#             */
/*   Updated: 2022/06/30 15:43:16 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion_percent(t_flags fl)
{
	int		len;

	len = 1;
	if (fl.minus)
		ft_putchar_fd('%', 1);
	while (fl.width > 1)
	{
		if (fl.zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		fl.width--;
		len++;
	}
	if (!fl.minus)
		ft_putchar_fd('%', 1);
	return (len);
}
