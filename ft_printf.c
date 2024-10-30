/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomas-a <ntomas-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:25:51 by ntomas-a          #+#    #+#             */
/*   Updated: 2024/10/30 00:37:35 by ntomas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Função auxiliar que procura um caractere em uma string.
// Retorna um ponteiro para a primeira ocorrência de caracter ou NULL se não encontrado.
static char *ft_strchr(const char *str, int b) {
    while (*str) {
        if (*str == b)
            return (char *)str; // Retorna o ponteiro para o caracter encontrado.
        str++;
    }
    return (b == 0) ? (char *)str : NULL; // Trata o caso do caracter nulo ('\0').
}

// Função que encontra o tipo de formato e chama a função correspondente para imprimir.
static int ft_findtype(char c, va_list arg) {
    if (c == 'c')
        return ft_pchar(va_arg(arg, int)); // Imprime um caracter.
    if (c == 's')
        return ft_pstr(va_arg(arg, char *)); // Imprime uma string.
    if (c == 'p')
        return ft_ppnt(va_arg(arg, void *)); // Imprime um ponteiro.
    if (c == 'd' || c == 'i')
        return ft_pnmb(va_arg(arg, int)); // Imprime um número inteiro.
    if (c == 'u')
        return ft_prunmb(va_arg(arg, unsigned int)); // Imprime um número inteiro não assinado.
    if (c == 'x' || c == 'X')
        return ft_phex(va_arg(arg, unsigned int), c); // Imprime um número em hexadecimal.
    return ft_pchar(c); // Imprime o caractere '%' caso não corresponda a nenhum tipo.
}

// Função principal que implementa a formatação semelhante ao printf.
int ft_printf(const char *format, ...) {
    va_list arg; // Declaração da lista de argumentos variáveis.
    int count = 0; // Inicializa o contador de caracteres escritos.
    int i = 0; // Inicializa o índice para percorrer a string de formato.

    va_start(arg, format); // Inicializa a lista de argumentos.
    while (format[i]) { // Enquanto não chegamos ao fim da string de formato.
        // Verifica se o caractere atual é '%' e se o próximo caractere é um tipo válido.
        if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1])) {
            count += ft_findtype(format[++i], arg); // Chama ft_findtype com o tipo correspondente.
        } else {
            count += ft_pchar(format[i]); // Imprime o caractere normal.
        }
        i++; // Avança para o próximo caractere.
    }
    va_end(arg); // Finaliza o uso da lista de argumentos.
    return count; // Retorna o total de caracteres escritos.
}

/*int		main(void)
{
	char	a;
	char	*str;
	char	*str2;
	char	percent;
	int		i;
	unsigned int	b;
	unsigned int	hex;

	a = 'a';
	str = "ugdygd";
	str2 = "10";
	i = -42174612;
	b = -42174612;
	hex = -10;
	percent = '%';

	// %c
	write(1, "ft_c\n", 5);
	printf("%d\n", printf("%c\n", a));
	printf("%d\n", ft_printf("%c\n", a));
	printf("\n\n");

	// %s
	write(1, "ft_s\n", 5);
	printf("%d\n", printf("%s\n", str));
	printf("%d\n", ft_printf("%s\n", str));
	printf("\n\n");

	// %p
	write(1, "ft_p\n", 5);
	printf("%d\n", printf("%p\n", str2));
	printf("%d\n", ft_printf("%p\n", str2));
	printf("\n\n");
	// %d
	write(10123456789abcdeft_x\n", 5);
	printf("%d\n", printf("%x\n", hex));
	printf("%d\n", ft_printf("%x\n", hex));
	printf("\n\n");

	// %X
	write(1, "ft_X\n", 5);
	printf("%d\n", printf("%X\n", hex));
	printf("%d\n", ft_printf("%X\n", hex));
	printf("\n\n");

	// %%
	write(1, "ft_percent\n", 12);
	printf("%d\n", printf("%%\n"));
	printf("%d\n", ft_printf("%%\n", percent));
	printf("\n\n");
}*/