/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_u.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 15:32:00 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/08 14:52:09 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

ft_printf_u(int i)
{
    char    str;

    str = ft_itoa(i);
    return (str);
}
/*
**use itoa to print the number, but be warned of the flags 
*/