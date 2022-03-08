/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:27:32 by ajazbuti          #+#    #+#             */
/*   Updated: 2021/11/05 20:43:40 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_c_nt(t_printf *p, unsigned char c)
{
	if (p->wdth <= 1)
		p->p_ed += write(1, &c, 1);
	else if (p->mnus)
	{
		p->p_ed += write(1, &c, 1);
		while (--p->wdth > 0)
			p->p_ed += write(1, " ", 1);
	}
	else if (p->zero)
	{
		while (--p->wdth > 0)
			p->p_ed += write(1, "0", 1);
		p->p_ed += write(1, &c, 1);
	}
	else
	{
		while (--p->wdth > 0)
			p->p_ed += write(1, " ", 1);
		p->p_ed += write(1, &c, 1);
	}
}

char	*ft_solve_c(t_printf *p)
{
	char			*s;
	unsigned char	c;

	s = NULL;
	if (*p->format == '%')
	{
		c = '%';
		ft_c_nt(p, c);
	}
	else
	{
		c = (unsigned int)va_arg(p->args, int);
		ft_c_nt(p, c);
	}	
	return (s);
}
