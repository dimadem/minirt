/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:36:26 by mcoskune          #+#    #+#             */
/*   Updated: 2024/11/25 15:57:27 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_init.h"

//	Variables of parse structures are initialized to their default values
void	init_pars(t_parse *pars)
{
	pars->count_a = 0;
	pars->count_c = 0;
	pars->count_l = 0;
	pars->count_sp = 0;
	pars->count_pl = 0;
	pars->count_cy = 0;
	pars->error_encountered = false;
	pars->lux = NULL;
}
