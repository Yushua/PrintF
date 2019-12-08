/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 16:10:06 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/08 17:08:16 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct	s_print;
{
	int		width; //width of the input
	int		widthf; //width of the flags
	char	convergions; //if is c, s, p etc
	char	flags; //flags
	char	*input; // input like 1234
	int		position;
	int		end;
	int		positive;
	int		negative;
	char	*error //error
	int		size;
}			t_print;
