#include "main.h"
/**
  *_printf - prints string
  *@format: character string
  *@...: input chars
  *Return: 1 for success
  *for error returns -1
  */
int _printf(const char *format, ...)
{
	va_list li;
	int printed = 0, i = 0;
	char c, *st;

	if (format == NULL)
		return (-1);
	va_start(li, format);
	for (; *format; format++)
	{
		if (*format != '%')
		{
			write(1, format, 1);
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				c = va_arg(li, int);
				write(1, &c, 1);
			}
			else if (*format == '%')
			{
				write(1, format, 1);
			}
			else if (*format == 's')
			{
				st = va_arg(li, char *);
				i = strlen(st);
				write(1, st, i);
				printed += i;
			}
		}
		if (*format != 's')
			printed++;
	}
	va_end(li);
	return (printed);
}
