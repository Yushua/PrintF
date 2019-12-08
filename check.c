/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/08 14:59:48 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/08 17:43:10 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

t_print		che_perc(t_print **print, char str, va_list ap, const char *format)
{
    char    *cache;
    
	format[i + 1] //next character after %

	//check for flags
	//check for characters, give the str after the flags and fill them up
    (*print)->convergions = ft_convergance(*format, &print, i);
    if (format[i] == '.' || format[i] == '-' || format[i] == '0' ||
        format[i] == '*');
        cache = ft_flag_check(&print, format, i)
	//check convergions with va_arg, then combine what you got and make the string you add to the main string
	i += 1;
    if ((*print)->flags == 0)
	return (ft_printf(-1)); //if failed return with -1, not good, but fix later
}


/*
**after you found the % you add 1 to the position. the make sure all 
**the structs are 0 in the beginding and that begin is begin + i so when you come bakc here you start with
**the next %
***/