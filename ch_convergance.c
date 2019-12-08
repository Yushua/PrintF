/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ch_convergance.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/08 16:00:12 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/08 17:53:27 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

t_print ft_convergance(const char (*format), t_print **print, int i)
{
    if (format[i] != '\0')
    {
        i++
        if (format[i] != '\0' || format[i] == '%')
        {
            i++
            if(format[i] != '\0' || format[i] == '%')
            {

            }
        }
    }
    else if (format[i] != '\0')
    {
        while (format[i] != '\0')
        {
            (*print)->end = i;
            if (format[i] == 'c')
                return ('c')
            else if (format == 's')
                return ('s')
            else if (format == 'p')
                return ('p')
            else if (format == 'd')
                return ('d')
            else if (format == 'i')
                return ('i')
            else if (format == 'u')
                return ('u')
            else if (format == 'x')
                return ('x')
            else if (format == 'X')
                return ('X')
            else if (format == '%')
                return ('%')
            i++; 
        }
    }
    return (formation->error)
}

/* 
**checks what the convergance is so later you cna check with your flags if 
**you need to do this flag, else, you return an error
*/
