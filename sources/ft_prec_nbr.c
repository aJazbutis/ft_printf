/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:55:11 by ajazbuti          #+#    #+#             */
/*   Updated: 2021/11/05 16:02:22 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_prec_nbr(t_printf *p, char *s)
{
	char	*str;
	char	*tmp;

	str = NULL;
	if (p->prec_v <= (int)ft_strlen(s))
		return (s);
	tmp = (char *)ft_calloc(p->prec_v - ft_strlen(s) + 1, 1);
	if (tmp)
	{
		ft_memset(tmp, '0', p->prec_v - ft_strlen(s));
		str = ft_strjoin(tmp, s);
		free(s);
		free(tmp);
	}
	return (str);
}
