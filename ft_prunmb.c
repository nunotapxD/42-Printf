/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prunmb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomas-a <ntomas-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:26:32 by ntomas-a          #+#    #+#             */
/*   Updated: 2024/10/30 00:35:12 by ntomas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Função que imprime um número inteiro não assinado e retorna o número de caracters escritos.
int ft_prunmb(unsigned int n) {
    int count = 0; // Contador para o número de caracters escritos

    // Se o número é maior ou igual a 10, processa a parte mais significativa.
    if (n >= 10) {
        count += ft_prunmb(n / 10); // Chamada recursiva para a parte mais significativa
    }
    
    // Converte o dígito menos significativo para caractere e escreve.
    count += ft_pchar((n % 10) + '0'); // Escreve o dígito atual e incrementa o contador

    return count; // Retorna o total de caracteres escritos
}
