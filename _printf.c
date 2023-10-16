#include "main.h"
int print(char c);
int prints(char *s);
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

	if (!format)
		return (-1);
	va_start(li, format);
	for (; *format; format++)
	{
		if (*format != '%')
		{
			print(*format);
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				print(va_arg(li, int));
			}
			else if (*format == '%')
			{
				print(*format);
			}
			else if (*format == 's')
			{
				i = prints(va_arg(li, char *));
				printed += (i - 1);
			}
		}
		printed++;
	}
	va_end(li);
	return (printed);
}
/**
  *print: prints c
  *@c: input c
  *Return: 1
  */
int print(char c)
{
	return (write(1, &c, 1));
}
/**
  *print: prints s
  *@s: input string
  *Return: number of char
  */
int prints(char *s)
{
	int i = 0;

	for (; s[i] != '\0'; i++)
		print(s[i]);
	return (i);
}
