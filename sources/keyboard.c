/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:22:39 by kmaneera          #+#    #+#             */
/*   Updated: 2020/08/19 11:27:06 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	keyboard2(int key, t_sto *inf)
{
	if (key == R_SHIFT || key == L_SHIFT)
		z_adj(inf, key);



	// else if (key >= NP_1 && key <= NP_9)
	// 	rotate(inf, key);

    else if (key == MP_W || key == MP_S ||\
            key == MP_A || key == MP_D ||\
            key == MP_Q || key == MP_E)
		rotate(inf, key);

	else if (key == PLUS || key == MINUS)
		zoom_adj(inf, key);
	else if (key == MP_B)
		boldmodeactivator(inf);
	else if (key == MP_V)
		vgmodeactivator(inf);
	else if (key == MP_P)
		changeproj(inf);
	else if (key == MP_T)
		changecolortheme(inf);
	return (0);
}

static int	exitprogram(t_sto *inf)
{
	free(inf->zarr);
	free(inf->colorarr);
	free(inf);
	if (inf->clindex)
		system("leaks fdf");
	exit(0);
}

static void	leakdetection(t_sto *inf)
{
	if (inf->clindex == 0)
	{
		inf->clindex = 1;
		makeart(inf);
	}
	else
	{
		inf->clindex = 0;
		makeart(inf);
	}
}

static int	keyboard(int key, t_sto *inf)
{
	int x;

	x = inf->mh;
	if (key == MP_ESC)
		exitprogram(inf);
	else if (key == MP_L)
		leakdetection(inf);
	else if (key >= 123 && key <= 126)
	{
		if (inf->vgmodeindex)
			move_vg(inf, key);
		else
			move(inf, key);
	}
	return (keyboard2(key, inf));
}

void		control(t_sto *inf)
{
	mlx_key_hook(inf->win, keyboard, inf);
}
