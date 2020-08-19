/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:17:20 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/22 17:18:29 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotx(int *y, int *z, double alpha)
{
	int ytmp;

	ytmp = *y;
	*y = ytmp * cos(alpha) + *z * sin(alpha);
	*z = -ytmp * sin(alpha) + *z * cos(alpha);
}

static void	roty(int *x, int *z, double beta)
{
	int xtmp;

	xtmp = *x;
	*x = xtmp * cos(beta) + *z * sin(beta);
	*z = -xtmp * sin(beta) + *z * cos(beta);
}

static void	rotz(int *x, int *y, double gamma)
{
	int xtmp;
	int ytmp;

	xtmp = *x;
	ytmp = *y;
	*x = xtmp * cos(gamma) - ytmp * sin(gamma);
	*y = xtmp * sin(gamma) + ytmp * cos(gamma);
}

void		rotator(t_sto *inf, t_coord *coord)
{
	rotx(&coord->y, &coord->z, inf->alpha);
	roty(&coord->x, &coord->z, inf->beta);
	rotz(&coord->x, &coord->y, inf->gamma);
}
