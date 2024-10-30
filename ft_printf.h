/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomas-a <ntomas-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:26:16 by ntomas-a          #+#    #+#             */
/*   Updated: 2024/10/30 00:35:56 by ntomas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>   // Para funções de alocação de memória.
# include <unistd.h>   // Para funções de escrita e leitura.
# include <stdio.h>    // Para funções de entrada/saída padrão.
# include <string.h>   // Para funções de manipulação de strings.
# include <ctype.h>    // Para funções de classificação de caracters.
# include <limits.h>   // Para definir constantes relacionadas a limites.
# include <sys/types.h> // Para definições de tipos de dados.
# include <sys/uio.h>  // Para estruturas de entrada/saída.
# include <sys/stat.h> // Para definições de estruturas de status de arquivos.
# include <fcntl.h>    // Para operações de controlo de arquivos.
# include <stdarg.h>   // Para manipulação de argumentos variáveis.

int		ft_printf(char const *tyle, ...); // Função principal que imprime de acordo com o formato fornecido.
int		ft_pchar(char c);                  // Função que imprime um único caractere.
int		ft_pstr(char *str);                 // Função que imprime uma string.
int		ft_pnmb(int n);                     // Função que imprime um número inteiro.
int		ft_prunmb(unsigned int n);          // Função que imprime um número inteiro não assinado.
int		ft_phex(unsigned long n, char c);   // Função que imprime um número em formato hexadecimal.
int		ft_ppnt(void *str);                  // Função que imprime um ponteiro.

#endif
