/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:49:01 by kmaneera          #+#    #+#             */
/*   Updated: 2020/08/19 11:43:53 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# define SCREENWIDTH 1920
# define SCREENHEIGHT 1080
# define NOCOLOR -1
# define MENUCOLOR      0xD3D3D3
# define MP_W           13
# define MP_S           1
# define MP_A           0
# define MP_D           2
# define MP_Q           12
# define MP_E           14
# define MP_V           9
# define MP_B           11
# define MP_T           17
# define MP_P			35
# define MP_L           37
# define MP_ESC		    53
# define PLUS   		24
# define MINUS  		27
# define ARW_UP			126
# define ARW_DOWN		125
# define ARW_LEFT		123
# define ARW_RIGHT		124
# define R_SHIFT        258
# define L_SHIFT        257

typedef struct		s_coord
{
	int x;
	int y;
	int z;
	int color;
}					t_coord;

typedef struct		s_lst
{
	t_coord			*coord;
	int				ne;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_sto
{
	char	*filename;
	t_lst	**maplst;
	int		*colorarr;
	int		*zarr;
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		img_bpp;
	int		img_sl;
	int		img_edn;
	int		sw;
	int		sh;
	int		mw;
	int		mh;
	int		zmin;
	int		zmax;
	int		zrange;
	int		zoom;
	int		campos_y;
	int		campos_x;
	int		z_scaler;
	int		boldmodeindex;
	int		vgmodeindex;
	int		screensavermodeindex;
	int		projindex;
	int		colorthemeindex;
	int		clindex;
	double	alpha;
	double	beta;
	double	gamma;
}					t_sto;

typedef struct		s_pl
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		e2;
	int		curx;
	int		cury;
	int		curcolor;
	double	perc;
}					t_pl;

void				lst_add_back(t_lst **alst, t_lst *new);
t_lst				*lstnew(t_coord *el, int ne);
t_sto				*infini(void);
int					get_ne(const char *s, char c);
void				readline(t_sto *inf, char *line);
void				readmap(t_sto *inf, char *filename);
void				lsttoarr(t_sto *inf);
void				getzoom(t_sto *inf);
int					get_ne(const char *s, char c);
void				putline(t_sto *inf, t_coord *h, t_coord *t);
void				makeart(t_sto *inf);
void				clearscreen(t_sto *inf);
void				proj(t_sto *inf, t_coord *h, t_coord *t);
int					getstdcolor(t_sto *inf, int y, int x);
int					shader(t_pl *pl, t_coord *h, t_coord *t);
void				putmenu(t_sto *inf);
void				putmenu2(t_sto *inf);
void				rotator(t_sto *inf, t_coord *coord);
void				errexit(char *str);
void				move(t_sto *inf, int key);
void				move_vg(t_sto *inf, int key);
void				z_adj(t_sto *inf, int key);
void				rotate(t_sto *inf, int key);
void				zoom_adj(t_sto *inf, int key);
void				boldmodeactivator(t_sto *inf);
void				vgmodeactivator(t_sto *inf);
void				changeproj(t_sto *inf);
void				changecolortheme(t_sto *inf);
void				control(t_sto *inf);

#endif
