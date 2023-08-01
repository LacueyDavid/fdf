/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:31:14 by dlacuey           #+#    #+#             */
/*   Updated: 2023/05/12 18:31:32 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*traveler;

	traveler = NULL;
	if (lst != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			traveler = *lst;
			while (traveler->next)
				traveler = traveler->next;
			traveler->next = new;
		}
	}
}
