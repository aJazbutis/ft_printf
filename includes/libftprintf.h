/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:57:30 by ajazbuti          #+#    #+#             */
/*   Updated: 2021/11/05 16:11:56 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct s_printf
{
	const char	*format;
	va_list		args;
	int			wdth;
	int			mnus;
	int			zero;
	int			prec;
	int			prec_v;
	int			plus;
	int			hash;
	int			spce;
	int			p_ed;
}t_printf;

int		ft_printf(const char *format, ...);
void	ft_inspect(t_printf *p);
int		ft_convert(t_printf *p);
char	*ft_solve_hex(t_printf *p);
char	*ft_solve_s(t_printf *p);
char	*ft_solve_c(t_printf *p);
char	*ft_solve_u(t_printf *p);
char	*ft_solve_di(t_printf *p);
char	*ft_solve_p(t_printf *p);
char	*ft_solve_field(t_printf *p, char *s, int l);
char	*ft_nbr_prc(t_printf *p, char *s, char *prfx);
char	*ft_prec_nbr(t_printf *p, char *s);
char	*ft_put_field(t_printf *p, char *s);
#endif
