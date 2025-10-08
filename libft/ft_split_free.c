/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:30:00 by badr              #+#    #+#             */
/*   Updated: 2025/10/08 15:23:02 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Libère un tableau de chaînes alloué dynamiquement (typiquement par ft_split).
** 
** Paramètres:
**   split - tableau de chaînes terminé par NULL à libérer
**
** Note: Libère chaque chaîne puis le tableau lui-même.
*/
void	ft_split_free(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
