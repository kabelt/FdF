/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:07:51 by kmaneera          #+#    #+#             */
/*   Updated: 2020/08/19 11:29:27 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move(t_sto *inf, int key)
{
	if (key == ARW_UP)
	{
		inf->campos_y += 30;
		makeart(inf);
	}
	else if (key == ARW_DOWN)
	{
		inf->campos_y -= 30;
		makeart(inf);
	}
	else if (key == ARW_LEFT)
	{
		inf->campos_x += 30;
		makeart(inf);
	}
	else if (key == ARW_RIGHT)
	{
		inf->campos_x -= 30;
		makeart(inf);
	}
}

void	move_vg(t_sto *inf, int key)
{
	if (key == ARW_UP)
	{
		inf->campos_y -= 1;
		makeart(inf);
	}
	else if (key == ARW_DOWN)
	{
		inf->campos_y += 1;
		makeart(inf);
	}
	else if (key == ARW_LEFT)
	{
		inf->campos_x -= 1;
		makeart(inf);
	}
	else if (key == ARW_RIGHT)
	{
		inf->campos_x += 1;
		makeart(inf);
	}
}

void	z_adj(t_sto *inf, int key)
{
	if (key == L_SHIFT)
	{
		inf->z_scaler++;
		makeart(inf);
	}
	else if (key == R_SHIFT && inf->z_scaler >= 2)
	{
		inf->z_scaler--;
		makeart(inf);
	}
}

// void	rotate(t_sto *inf, int key)
// {
// 	if (key == NP_6)
// 		inf->beta += 0.05;
// 	else if (key == NP_4)
// 		inf->beta -= 0.05;
// 	else if (key == NP_2)
// 		inf->alpha += 0.05;
// 	else if (key == NP_8)
// 		inf->alpha -= 0.05;
// 	else if (key == NP_9)
// 		inf->gamma += 0.05;
// 	else if (key == NP_1)
// 		inf->gamma -= 0.05;
// 	makeart(inf);
// }

void	rotate(t_sto *inf, int key)
{
	if (key == MP_D)
		inf->beta += 0.05;
	else if (key == MP_A)
		inf->beta -= 0.05;
	else if (key == MP_S)
		inf->alpha += 0.05;
	else if (key == MP_W)
		inf->alpha -= 0.05;
	else if (key == MP_E)
		inf->gamma += 0.05;
	else if (key == MP_Q)
		inf->gamma -= 0.05;
	makeart(inf);
}

// void	zoom_adj(t_sto *inf, int key)
// {
// 	if (key == PLUS)
// 	{
// 		inf->zoom += 5;
// 		makeart(inf);
// 	}
// 	else if (key == MINUS && inf->zoom >= 2)
// 	{
// 		inf->zoom -= 5;
// 		makeart(inf);
// 	}
// }

void	zoom_adj(t_sto *inf, int key)
{
	if (key == PLUS)
	{
		inf->zoom += 1;
		makeart(inf);
	}
	else if (key == MINUS && inf->zoom >= 2)
	{
		inf->zoom -= 1;
		makeart(inf);
	}
}
