/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnmb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomas-a <ntomas-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:26:02 by ntomas-a          #+#    #+#             */
/*   Updated: 2024/10/30 00:48:00 by ntomas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Função que imprime um número inteiro (positivo ou negativo) e retorna o número de caracters escritos.
int ft_pnmb(int n) {
    int count = 0; // Inicializa o contador de caracters escritos.
    long i = n; // Converte o número para long para lidar com o valor negativo.

    // Verifica se o número é negativo.
    if (i < 0) {
        count += write(1, "-", 1); // Imprime o sinal de negativo.
        i = -i; // Torna o número positivo para facilitar a impressão.
    }

    // Se o número for maior ou igual a 10, chama a função recursivamente para os dígitos mais significativos.
    if (i >= 10) {
        count += ft_pnmb(i / 10); // Chamada recursiva para o dígito mais significativo.
    }

    // Escreve o dígito menos significativo e adiciona ao contador.
    count += ft_pchar((i % 10) + '0'); // Converte o dígito em caracter e escreve.

    return count; // Retorna o total de caracters escritos.
}