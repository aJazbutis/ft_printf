/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:21:04 by ajazbuti          #+#    #+#             */
/*   Updated: 2021/11/05 15:48:31 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_wrt_it(t_printf *p, char *conv_ed)
{
	ft_putstr_fd(conv_ed, 1);
	p->p_ed += ft_strlen(conv_ed);
	free(conv_ed);
}

int	ft_convert(t_printf *p)
{
	char	*conv_ed;

	conv_ed = NULL;
	if (*p->format && !(ft_strchr("cspdiuxX%", *p->format)))
		conv_ed = (char *)ft_calloc(1, 1);
	else if (*p->format == 'c' || *p->format == '%')
		conv_ed = ft_solve_c(p);
	else if (*p->format == 's')
		conv_ed = ft_solve_s(p);
	else if (*p->format == 'p')
		conv_ed = ft_solve_p(p);
	else if (*p->format == 'd' || *p->format == 'i')
		conv_ed = ft_solve_di(p);
	else if (*p->format == 'u')
		conv_ed = ft_solve_u(p);
	else if (*p->format == 'x' || *p->format == 'X')
		conv_ed = ft_solve_hex(p);
	p->format++;
	if (conv_ed)
		ft_wrt_it(p, conv_ed);
	return (0);
}
