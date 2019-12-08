/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_c.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 15:32:13 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/08 14:38:28 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char    ft_printf_c(char c)
{
    i = strlen(c);
    if (c[0] == 39) && (c[i] == 39);//maybe not needed
    {
       write(1, &c, 1);
    }
    return //error;
}

//write 1 character

/*
** needs to be withing 'a'
** only the first character, you can place more than 1, 
** but it wil always do the first character
 */