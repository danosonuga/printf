#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
  *_printf - prints all args in a format (see printf)
  *@format: format to prnt
  *Return: no of chars printed
  */
int _printf(const char *format, ...)
{
	va_list ap;
	int i, ilen, ival, dval;
	char *s;
	const char *p;
	char c;

	va_start(ap, format);
	for (p = format; *p; p++)
	{
		notspec(*p);
		i++;
		continue;
		
		switch (*++p)
		{
			case 'd':
				dval = va_arg(ap, int);
				ilen = print(dval);
				i += ilen;
				break;
			case 'i':
				ival = va_arg(ap, int);
				ilen = print(ival);
				i += ilen;
				break;
			case 's':
				s = va_arg(ap, char *);
				ilen = printstr(s);
				i += ilen;
				break;
			case 'c':
				c = (char) va_arg(ap, int);
				_putchar(c);
				i++;
				break;
			case '%':
				_putchar(37);
				i++;
				break;
			default:
				_putchar(*p);
				break;
		}
	}
	va_end(ap);
	return (i);
}

void notspec(char c)
{
	if (c != '%')
		_putchar(c);
}
int printstr(char *s)
{
	int i;

	if (s)
	{
		for (; *s; s++)
		{
			_putchar(*s);
			i++;
		}
	}
	return (i);
}

/**
  *_putchar - prints char to stdout
  *@c: char to be printed
  *Return: ASCII val of char
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
  *print - print an int with putchar only
  *@n: int
  *Return: no of char printed
  */
int print(int n)
{
	int i;


	i = 0;
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10)
	{
		print(n / 10);
		i++;
	}
	_putchar(n % 10 + '0');
	return (i);
}
