/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:48:39 by qrolland          #+#    #+#             */
/*   Updated: 2022/06/30 15:49:13 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int				minus;
	int				zero;
	int				preci;
	int				width;
}				t_flags;

int			ft_conversion_char(va_list arg, t_flags fl);
int			ft_conversion_string(va_list arg, t_flags fl);
int			ft_conversion_ptr(va_list arg, t_flags fl);
int			ft_conversion_int(va_list arg, t_flags fl);
int			ft_conversion_unsigned(va_list arg, t_flags fl);
int			ft_conversion_hex(va_list arg, t_flags fl, char c);
int			ft_conversion_percent(t_flags fl);
const char	*ft_read_flags(const char *str, va_list arg, t_flags *fl);
int			ft_printf(const char *format, ...);

#endif
