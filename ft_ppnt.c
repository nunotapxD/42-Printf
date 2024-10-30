/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ppnt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomas-a <ntomas-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:26:08 by ntomas-a          #+#    #+#             */
/*   Updated: 2024/10/30 00:38:16 by ntomas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Função que imprime um ponteiro e retorna o número de caracters escritos.
int ft_ppnt(void *str) {
    int count = 0; // Inicializa o contador de caracters escritos.
    unsigned long pnt = (unsigned long)str; // Converte o ponteiro para um inteiro sem sinal de 64 bits.

    // Verifica se o ponteiro é nulo.
    if (!str) {
        // Se for nulo, escreve "(nil)" e retorna o número de caracters escritos (5).
        return write(1, "(nil)", 5);
    }

    // Escreve "0x" para indicar que o valor a seguir é um endereço em hexadecimal.
    count += write(1, "0x", 2); 
    // Chama ft_phex para imprimir o valor do ponteiro em formato hexadecimal.
    count += ft_phex(pnt, 'x'); 

    return count; // Retorna o total de caracters escritos.
}