/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_ptr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 15:32:04 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/08 14:19:45 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

ft_printf_d(unsigned long nb)
{
    write(1, "0x", 2);
    ft_printf_d_hex(nb);
}

ft_printf_d_hex(unsigned long nb)
{
    char str[16] = "0123456789abcdef";
    
    if(nb > 15))
        ft_printf_d(nb /16)
    ft_putchar(str[nb % 16] + 0)
}

//write the pointer