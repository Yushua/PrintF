/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_prec.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 14:54:47 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/11 17:07:32 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_there_pre(t_print **print, const char *format, int  i, va_list ap) //if there is a . in str, meaning you need to go to .
{
	while((format[i] != '\0') || i != (*print)->end)
	{
		if (format[i] == '.')
		{
			(*print)->locationper = i; //location the percision
			ft_check_dot(&print, format, i, ap); 
			return (1)          
		}
		i++;
	}
	return (0);
}

int		ft_is_there_min(t_print **print, const char *format, int  i, va_list ap) //if there is a - in str
{
	while((format[i] != '\0') || i != (*print)->end)
	{
		if (format[i] == '-')
		{
			(*print)->locationmin = i; //location the percision
			ft_check_dot(&print, format, i, ap); 
			return (1)          
		}
		i++;
	}
	return (0);
}

int		ft_print_pre(t_print **print, const char *format, int  i, va_list ap)
{
	int		s; //location star
	int		b; //begin
	int		p; //location
	int		m;

	b = i;
	p = (*print)->locationper;
	if (ft_is_there_min(&print, format, i, ap))
		(*print)->min = 1;
	p++
	if (format[p] => '0' || format[p] =< '9') 
	{
		p -= 2;
		if (format[p] => '0' || format[p] =< '9')
		{
			ft_per_both(&print, format, i, ap);
			return(1);
		}
		p += 2;
		ft_per_after(&print, format, i, ap);
		return (1);
	}
	p -= 2;
	if (format[p] => '0' || format[p] =< '9')
	{
		ft_per_before(&print, format, i, ap);
		return(1);
	}
}

t_print		ft_per_before(t_print **print, const char *format, int  i, va_list ap)
{
	
}

t_print		ft_per_both(t_print **print, const char *format, int  i, va_list ap)
{

}

t_print		ft_per_after(t_print **print, const char *format, int  i, va_list ap)
{

}
/*

before:
if number before, it acts as empty ignore 0

after:
is number after dot, it becmoes bzero and 0 becomes nothing, dot is plced at the end
if - is before zero, remove 0

before and after:






*/