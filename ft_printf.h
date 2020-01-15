/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 16:10:06 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/15 23:38:15 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_print
{
	int			end;
	int			position;
	char		convergence;
	int			min;
	int			zero;
	char		*flag_str;
	char		*input_str;
	char		*input_str_2;
	int			width_nb;
	int			precision;
	int			positive;
	int			len;
	int			start;
	int			w_width;
	int			p_width;
	int			error;
	int			neg;
	int			pre;
	int			ii;
}				t_print;

int		ft_printf(const char *format, ...);
int		ft_printf_check(const char *format, va_list ap);
char	ft_convergence(t_print **print, int i, const char *format);
char	*ft_long_itoa(unsigned long i);
void	ft_destruct_free(t_print *print);

void	ft_print_f(t_print **print, va_list ap, int i, const char *format);
void	ft_min_zero(t_print **print, int i, const char *format);
void	ft_find_pre(t_print **print, int i, const char *format, va_list ap);
void	ft_find_flag(t_print **print, va_list ap, int i, const char *format);
void	ft_find_nb(t_print **print, int i, const char *format, va_list ap);

void	struct_zero(t_print **print);
char	*ft_empty_str(long nb);
void	ft_save_nb(t_print **print, int i, const char *format);

void	ft_precision_nb(t_print **print, int i, const char *format,
			va_list ap);

void	ft_save_input(t_print **print, va_list ap, int i);
void	ft_print_c(t_print **print, va_list ap);
void	ft_print_s(t_print **print, va_list ap);
void	ft_print_i(t_print **print, va_list ap, int i);
void	ft_print_u(t_print **print, va_list ap);
void	ft_print_x(t_print **print, va_list ap);
void	ft_print_p(t_print **print, va_list ap);
void	ft_write_string_1(t_print **print);
char	*ft_fill_z_s(long nb);

void	ft_flag_str(t_print **print);
char	*ft_flag_min(t_print **print);
char	*ft_flag_no(long s, long p, t_print **print);

void	ft_write_str(t_print **print);
char	*ft_str_min(long s, t_print **print);
char	*ft_str_no(long s, t_print **print, long p);

char	*ft_hex(unsigned long i, unsigned long j, t_print **print);
char	*ft_hex_two(char *str, t_print **print, unsigned long j, unsigned long i);
char	ft_turn_hex(unsigned long i, unsigned long j, t_print **print);

int		ft_atoi(const char *str);
size_t	ft_strlen(char *s);
char	*ft_itoa(int n);

char	*nwstr(void);
void	ft_write_pro(t_print **print);
char	*ft_fill_w_null(t_print **print);

void	ft_write_int(t_print **print);
char	*ft_int_min(long s, int w, t_print **print);
char	*ft_int_no(long s, int w, t_print **print, long p);
char	*ft_fill_z(long w, t_print **print);
char	*ft_empty_int(long w, long s, t_print **print);
char	*ft_fill_z(long nb, t_print **print);
char	*ft_strjoin(char *s1, char *s2);
void	ft_take_min(t_print **print);
char	*ft_exemption1(t_print **print, int w);

void	ft_att_z(t_print **print, int p, int s);

void	ft_write_hex(t_print **print);
char	*ft_hex_no(long s, int w, t_print **print, long p);
char	*ft_hex_min(long s, int w, t_print **print);
char	*a_to_a(t_print **print);

void	ft_write_p(t_print **print);
char	*ft_p_no(long s, int w, t_print **print, long p);
char	*ft_p_min(long s, int w, t_print **print);

char	*ft_strdup(char *s1);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

#endif
