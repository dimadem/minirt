/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:45:51 by mcoskune          #+#    #+#             */
/*   Updated: 2024/11/26 16:29:41 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../muk_lib.h"

//	This function is used to free double pointers.
void	free_dptr(void **dptr)
{
	int	i;

	if (dptr == NULL)
		return ;
	i = 0;
	while (dptr[i] != NULL)
	{
		free(dptr[i]);
		dptr[i] = NULL;
		i++;
	}
	free (dptr);
	dptr = NULL;
}
