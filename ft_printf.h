/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 16:10:06 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/22 16:21:03 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_print
{
	int			end;
	int			position;
	char		convergance;
	int			min;
	int			zero;
	char		*flag_str;
	char		*flag_str_pre;
	char		*input_str;
	int			width_nb;
	int			width;
	int			precision;
	int			pre_value;
	int			len;
}				t_print;

int		ft_printf(const char *format, ...);
int		ft_printf_check(const char *format, va_list ap);
char	ft_convergance(t_print **print, int i, const char *format);

void	ft_print_f(t_print **print, va_list ap, int i, const char *format);
void	ft_min_zero(t_print **print, va_list ap, int i, const char *format);
void	ft_find_pre(t_print **print, va_list ap, int i, const char *format);
void	ft_find_flag(t_print **print, va_list ap, int i, const char *format);
void	ft_find_nb(t_print **print, va_list ap, int i, const char *format);

void	struct_zero(t_print **print);
char	*ft_find_nb_z(t_print **print);
char	*ft_empty_str(t_print **print);
int		ft_save_nb(t_print **print, int i, const char *format);

void	ft_precision(t_print **print, va_list ap, int i, const char *format);
void	ft_precision_nb(t_print **print, va_list ap, int i, const char *format);

void	ft_save_input(t_print **print, va_list ap, int i, const char *format);
void	ft_save_c(t_print **print, va_list ap, int i, const char *format);
void	ft_print_s(t_print **print, va_list ap, int i, const char *format);
void	ft_print_string_1(t_print **print);

void	ft_flag_str(t_print **print);
char	*ft_flag_min(long s, t_print **print, long width);
char	*ft_flag_no(long s, long p, t_print **print, long width);

#endif

/*
check - and zero before the other flags, so numbers, * and .
remmeebr the numberS

	int			end;
	char		convergance;
	char		*flag_str;
	char		*flag_str_pre;
	char		*input_str;
	int			pre_n_c;// n_c, so the vallue
	int			precision; //is there a precision
	int			pre_value;
	int			width_v;
	int			width_nb; //width number
	int			width;
	int			min;
	int			zero;
	int			position;//position of 0 or -
	int			value;//remmember the value if its not 0, - . if - or 0, then its width
	int			width_save_nb;
	int			value_c;
	int			len;

*/
