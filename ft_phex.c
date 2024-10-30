/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomas-a <ntomas-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:09:47 by ntomas-a          #+#    #+#             */
/*   Updated: 2024/10/30 00:53:36 by ntomas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Função que imprime um número em formato hexadecimal 
// e retorna o número de caracters escritos.
int	ft_phex(unsigned long n, char c)
{
	int	count;
       	// Inicializa o contador de caracters escritos.
	char	*base; 
	// Declara um ponteiro para a base hexadecimal.

	count = 0;
	// Define a base de acordo com o formato (minúsculas ou maiúsculas).
	base = (c == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";

    // Se o número for maior ou igual a 16, chama a função
    // recursivamente para os dígitos mais significativos.
	if (n >= 16)
	{
		count += ft_phex(n / 16, c);
// Chamada recursiva para processar o número.
	}

// Adiciona o caracter correspondente 
// ao dígito menos significativo na base hexadecimal.
	count += ft_pchar(base[n % 16]);

	return count;
// Retorna o total de caracters escritos.
}
