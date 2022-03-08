/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:00:18 by ajazbuti          #+#    #+#             */
/*   Updated: 2021/11/05 14:18:55 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_init_it(t_printf *p, const char *format)
{
	p->format = format;
	p->p_ed = 0;
}

int	ft_printf(const	char *format, ...)
{
	t_printf	*prnt_it;
	int			printed;

	prnt_it = (t_printf *)malloc(sizeof(t_printf));
	if (!prnt_it)
		return (-1);
	ft_init_it(prnt_it, format);
	va_start(prnt_it->args, format);
	while (*prnt_it->format)
	{
		if (*prnt_it->format != '%')
		{
			prnt_it->p_ed += write(1, prnt_it->format, 1);
			prnt_it->format++;
		}
		if (*prnt_it->format == '%')
			ft_inspect(prnt_it);
	}
	va_end(prnt_it->args);
	printed = prnt_it->p_ed;
	free(prnt_it);
	return (printed);
}
