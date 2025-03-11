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

/**
 * Frees a NULL-terminated array of pointers and the array itself.
 * The array must be NULL-terminated.
 * This function nullifies individual pointers after freeing.
 * Note that setting dptr = NULL has no effect since dptr is passed by value.
 * 
 * @param dptr The NULL-terminated array of pointers to free
 */
void	free_dptr(void **dptr)
{
	int	i;

	if (dptr == NULL)
		return ;
	i = 0;
	while (dptr[i] != NULL)
	{
		free(dptr[i]);
		dptr[i] = NULL;  // This can be useful to prevent use-after-free bugs
		i++;
	}
	free(dptr);
	// Note: setting dptr = NULL has no effect since dptr is passed by value
}
