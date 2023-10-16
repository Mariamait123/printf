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

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(li, format);
	for (; *format; format++)
	{
		if (*format != '%')
		{
			print(format);
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				print(va_arg(li, int));
			}
			else if (*format == '%')
			{
				print(format);
			}
			else if (*format == 's')
			{
				i = prints(st = va_arg(li, char *));
				printed += (i) ;
			}
		}
		printed++;
	}
	va_end(li);
	return (printed);
}
/**
  *print: prints buff
  *@buff: input to be printed
  *@i: memory space of buff
  *Return: 1
  */
int print(char c)
{
	return (write(1, &c, 1));
}
int prints(char *s)
{
	int i = 0;

	for (; s[i] != '\0'; i++)
		print(s[i]);
	return (i);
}
