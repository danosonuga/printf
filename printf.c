#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format
 * @format: The format parameter specifier
 *
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list ap;
	const char *p;
	char *sval;
	int ival, i;

	va_start(ap, format);
	for (p = format; *p; p++)
	{
		if (*p != '%')
		{
			_putchar(*p);
			i++;
			continue;
		}
		switch (*++p)
		{
			case 'd':
				ival = va_arg(ap, int);
				i += print(ival);
				break;
			case 'i':
				ival = va_arg(ap, int);
				i += print(ival);
				break;
			case 's':
				sval = va_arg(ap, char *);
				i += printstr(sval);
				break;
			case 'c':
				_putchar((char) va_arg(ap, int));
				i++;
				break;
			default:
				--p;
				_putchar(*p);
				i++;
				break;
		}
	}
	va_end(ap);
	return (i);
}

/**
  *printstr- printstr
  *@s: str
  *Return: no of char printed
  */
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
