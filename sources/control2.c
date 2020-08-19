/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:11:11 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/22 17:13:54 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	boldmodeactivator(t_sto *inf)
{
	if (!(inf->boldmodeindex))
	{
		inf->boldmodeindex++;
		makeart(inf);
	}
	else
	{
		inf->boldmodeindex = 0;
		makeart(inf);
	}
}

void	vgmodeactivator(t_sto *inf)
{
	if (!(inf->vgmodeindex))
	{
		inf->vgmodeindex++;
		makeart(inf);
	}
	else
	{
		inf->vgmodeindex = 0;
		makeart(inf);
	}
}

void	changeproj(t_sto *inf)
{
	inf->alpha = 0;
	inf->beta = 0;
	inf->gamma = 0;
	inf->vgmodeindex = 0;
	if (inf->projindex == 0)
	{
		inf->projindex = 1;
		makeart(inf);
	}
	else if (inf->projindex == 1)
	{
		inf->projindex = 2;
		makeart(inf);
	}
	else if (inf->projindex == 2)
	{
		inf->projindex = 0;
		makeart(inf);
	}
}

void	changecolortheme(t_sto *inf)
{
	if (inf->colorthemeindex == 0)
	{
		inf->colorthemeindex = 1;
		makeart(inf);
	}
	else if (inf->colorthemeindex == 1)
	{
		inf->colorthemeindex = 2;
		makeart(inf);
	}
	else if (inf->colorthemeindex == 2)
	{
		inf->colorthemeindex = 0;
		makeart(inf);
	}
}
