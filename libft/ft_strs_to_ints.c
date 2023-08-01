/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_ints.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:02:55 by dlacuey           #+#    #+#             */
/*   Updated: 2023/07/25 16:03:09 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strs_to_ints(int *array, char **argv)
{
	size_t	index;

	index = 0;
	while (argv[index])
	{
		array[index] = ft_atoi(argv[index]);
		index++;
	}
}
