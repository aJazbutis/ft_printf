/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:08:56 by ajazbuti          #+#    #+#             */
/*   Updated: 2021/11/05 20:35:29 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_solve_u(t_printf *p)
{
	unsigned int	u;
	char			*s;

	u = va_arg(p->args, unsigned int);
	if (u == 0 && p->prec && p->prec_v == 0)
		s = (char *)ft_calloc(1, 1);
	else
		s = ft_utoa(u);
	if (!s)
		return (s);
	if (p->prec)
	{
		s = ft_prec_nbr(p, s);
		if (s && p->wdth > (int)ft_strlen(s))
			s = ft_put_field(p, s);
	}
	else if (p->wdth > (int)ft_strlen(s))
		s = ft_solve_field(p, s, 0);
	return (s);
}
