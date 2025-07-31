/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enricant <enricant@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:00:00 by enricant          #+#    #+#             */
/*   Updated: 2025/07/14 09:35:32 by enricant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	aux;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		aux = tab[i];
		tab[i] = tab [j];
		tab[j] = aux;
		j--;
		i++;
	}
	return ;
}
/* *
#include <stdio.h>
int main() {
  int miArray[] = {1, 2, 3, 4, 5};
  int tamano = sizeof(miArray) / sizeof(miArray[0]);

  printf("Array original: ");
  for (int i = 0; i < tamano; i++) {
    printf("%d ", miArray[i]);
  }
  printf("\n");

  ft_rev_int_tab(miArray, tamano);

  printf("Array invertido: ");
  for (int i = 0; i < tamano; i++) {
    printf("%d ", miArray[i]);
  }
  printf("\n");

  return 0;
}
* */
