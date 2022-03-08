/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:07:27 by ajazbuti          #+#    #+#             */
/*   Updated: 2021/11/05 20:41:49 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_tupper(unsigned int i, char *s)
{
	if (s[i] >= 'a' && s[i] <= 'z')
		s[i] -= 32;
}

static char	*ft_hex_pt_two(t_printf *p, char *hex, int n)
{
	if (p->prec)
	{
		hex = ft_prec_nbr(p, hex);
		if (p->hash && hex)
			hex = ft_add_prfx("0x", hex);
		if (p->wdth > (int)ft_strlen(hex) && hex)
			hex = ft_put_field(p, hex);
	}
	else if (p->hash)
	{
		if (n != 0)
		{
			if (p->wdth > 2 + (int)ft_strlen(hex))
				hex = ft_solve_field(p, hex, 2);
			if (hex)
				hex = ft_add_prfx("0x", hex);
		}
	}
	else if (p->wdth > (int)ft_strlen(hex))
		hex = ft_solve_field(p, hex, 0);
	return (hex);
}

char	*ft_solve_hex(t_printf *p)
{
	int		n;
	char	*hex;

	n = va_arg(p->args, unsigned int);
	if (n == 0 && p->prec && p->prec_v == 0)
		hex = (char *)ft_calloc(1, 1);
	else
		hex = ft_utobase(n, "0123456789abcdef");
	if (!hex)
		return (hex);
	hex = ft_hex_pt_two(p, hex, n);
	if (*p->format == 'X' && hex)
		ft_striteri(hex, &ft_tupper);
	return (hex);
}
