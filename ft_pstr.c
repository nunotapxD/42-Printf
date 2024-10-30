/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomas-a <ntomas-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:45:44 by ntomas-a          #+#    #+#             */
/*   Updated: 2024/10/30 00:34:17 by ntomas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Função que imprime uma string e retorna o número de caracteres escritos.
int ft_pstr(char *str) {
    // Verifica se a string é nula.
    if (!str) {
        // Se for nula, escreve "(null)" e retorna o número de caracters escritos (6).
        return write(1, "(null)", 6);
    }

    // Se o primeiro caracter da string não for o terminador nulo.
    if (*str) {
        // Chama ft_pchar para escrever o caracter atual e captura o número de caracteres escritos.
        int count = ft_pchar(*str); 
        // Chama recursivamente ft_pstr com o próximo caracterer da string e soma ao contador.
        return count + ft_pstr(str + 1);
    }
    // Caso base: se chegarmos ao fim da string (terminador nulo), retorna 0.
    return 0; 
}