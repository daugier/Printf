/*  H   H  EEEE     A     DDDDD   EEEE  RRR   ##
##  H   H  E       AAA    D    D  E     R  R  ##
##  HHHHH  EEEE   A   A   D    D  EEEE  RRR   ##
##  H   H  E      AAAAA   D    D  E     RR    ##
##  H   H  EEEE  A     A  DDDDD   EEEE  R R   */

#include "includes/libft.h"

va_list	more_convert_type(char c, va_list ap)
{
	int	i;

	if (c == 'X')
	{
		i = va_arg(ap, int);
		ft_putstr(ft_convert_base(ft_itoa(i), DECI, HEXAM));
	}
	if (c == 'x')
	{
		i = va_arg(ap, int);
		ft_putstr(ft_convert_base(ft_itoa(i), DECI, HEXA));
	}
	return (ap);
}

va_list	convert_type(char c, char c2, va_list ap)
{
	int	i;

	if (c == 'c')
		ft_putchar(va_arg(ap, int));
	if (c == 'C' || (c == 'l' && c2 == 'c'))
		ft_putchar(va_arg(ap, int));
	else if (c == 's')
		ft_putstr(va_arg(ap, char *));
	else if (c == 'S' || (c == 'l' && c2 == 's'))
		ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c =='i' || c == 'o' || c == 'u' ||
			(c == 'l' && c2 == 'o') || c == 'O' ||
			c == 'U' || (c == 'l' && c2 == 'u'))
		ft_putnbr(va_arg(ap, int));
	else if (c == 'p')
	{
		i = va_arg(ap, int);
		ft_putstr("0x");
		ft_putstr((ft_convert_base(ft_itoa(i), DECI, HEXA)));
	}
	else if (c == 'D' || (c == 'l' && c2 == 'd'))
		ft_putnbr(va_arg(ap, int));
	else
		ap = more_convert_type(c, ap);
	return (ap);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int	i;
	char	flag;

	i = -1;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			++i;
			if (format[i] == '%')
				ft_putchar(format[i]);
			if (ft_indexinstr(format[i], "#0-+"))
			{
				flag = format[i];
				i++;
				if (flag)
					flag = flag;
			}
			ap = convert_type(format[i], format[i + 1], ap);
		}
		else
			ft_putchar(format[i]);
	}
	va_end(ap);
	return (0);
}
