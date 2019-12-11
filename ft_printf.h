/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 16:10:06 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/11 16:07:38 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libf/libft.h"

typedef struct	s_print;
{
	int		width; //width of the input string
	int		widthf; //width of the flags string
	char	convergions; //if is c, s, p , d, i, u, x, X
	int		ccode; //inlcuded if con is a int or a char 1 = str 2 = int
	char	*flags; //flags
	char	*input; // input like 1234
	int		begin; //begin after %
	int		end; //end of convergance
	int		negative; //if negative - flag is used
	char	*error //error
	int		locationper; //location of percentage two
	int		locationmin; //is there a min
	int		zero;
	int		min;
}			t_print;

/*
**end is not the ebginning, its just before the supposed next part, meaning after the convergance, between end and the next
**% you put those chaarcters in the string, this way i know where it ends
*/
