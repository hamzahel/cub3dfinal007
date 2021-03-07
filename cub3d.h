/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:15:25 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/03/01 13:01:24 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include "utils/utils.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# define PLANE 1
# define DIR 1

typedef struct		s_window
{
	int				w;
	int				h;
	int				rep;
}					t_window;

typedef struct		s_file
{
	int				fd;
	int				ret;
	int				eof;
	char			*line;
}					t_file;

typedef struct		s_parse
{
	char			**spliter;
	char			**rgb;
}					t_parse;

typedef struct		s_path
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	int				rep;
}					t_path;

typedef struct		s_textures
{
	int				s_fd;
	int				no_fd;
	int				so_fd;
	int				we_fd;
	int				ea_fd;
	int				rep;
}					t_tex;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_color
{
	t_rgb			f;
	t_rgb			c;
	int				rep;
}					t_color;

typedef struct		s_sprite
{
	int				mapx;
	int				mapy;
	int				fd;
	double			spdistane;
	struct s_sprite	*next;
}					t_sprite;

typedef struct		s_map
{
	char			**tab;
	char			*line;
	int				index;
	int				val;
	int				rep;
	int				**pos;
}					t_map;

typedef struct		s_img
{
	void			*ptn;
	int				*data;
	int				bpp;
	int				line;
	int				endian;
	int				w;
	int				h;
}					t_img;

typedef	struct		s_bmp
{
	int				filesize;
	int				padding;
	int				y;
}					t_bmp;

typedef struct		s_cub
{
	t_window		win;
	t_file			file;
	t_parse			parse;
	t_path			path;
	t_color			color;
	t_tex			tex;
	t_map			map;
	t_img			textu[5];
	t_img			img;
	t_sprite		*sprite;
	t_bmp			bmp;
	char			**argv;
	char			*image;
	void			*mlx_ptn;
	void			*mlx_win;
	double			posx;
	double			posy;
	double			planex;
	double			oldplanex;
	double			planey;
	double			time;
	double			oldtime;
	double			camerax;
	double			raydirx;
	double			raydiry;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			movespeed;
	double			rotspeed;
	double			frametime;
	double			dirx;
	double			olddirx;
	double			diry;
	double			perpdistwall;
	double			wallx;
	double			step;
	double			texpos;
	double			spritex;
	double			spritey;
	double			invdet;
	double			transx;
	double			transy;
	double			*sprite_buffer;
	int				ray;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				texwidth;
	int				texheight;
	int				tex_x;
	int				tex_y;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				drawstartx;
	int				drawstarty;
	int				drawendx;
	int				drawendy;
	int				spritescx;
	int				spriteheight;
	int				spritewidth;
	int				spriteline;
	int				spritecount;
	int				argc;
	int				si;
	int				col;
	int				b_pos;
	int				data;
	int				filesize;
	int				keyboard[125];
	int				parse_sort;
	char			*save;
}					t_cub;

void				initvalues(t_cub *cub);
void				parsing(t_cub *cub);
void				ft_print(char *content);
void				check_param(t_cub *cub, int *fd, char *ex, int t);
void				get_textures(t_cub *cub);
void				get_colors(t_cub *cub);
void				get_window(t_cub *cub);
void				get_map(t_cub *cub);
void				map_checker(t_cub *cub);
void				add_textures(t_cub *cub);
void				drawing(t_cub *cub);
void				calc(t_cub *cub);
void				sidedist(t_cub *cub);
void				hit(t_cub *cub);
void				wall(t_cub *cub);
void				rendering(t_cub *cub);
int					creatergb(t_rgb *color);
void				bmp_filling(t_cub *cub, t_rgb *color);
void				wallrendering(t_cub *cub);
void				player_pos(char c, int x, int y, t_cub *cub);
int					keypressed(int key, t_cub *cub);
int					keyreleased(int key, t_cub *cub);
void				movesupdown(t_cub *cub);
void				movesides(t_cub *cub);
void				look(t_cub *cub);
int					keyclose(t_cub *cub);
int					dealkey(t_cub *cub);
void				createsprite(int x, int y, t_cub *cub);
t_sprite			*ft_lstnew(int mapx, int mapy, int fd);
void				ft_lstadd_front(t_sprite **alst, t_sprite *new, t_cub *cub);
void				sprite(t_cub *cub);
void				spriterendering(t_cub *cub);
void				spriteimage(t_cub *cub);
void				bmp(t_cub *cub);
void				bmp_filling(t_cub *cub, t_rgb *fc);
unsigned char		*bmp_header(int size);
unsigned char		*bmp_info(t_cub *cub);
void				bmp_save(t_cub *cub);
void				sortsprite(t_sprite *first, int count);
void				calcsprite(t_cub *cub);
void				spriteswap(t_sprite *head, t_sprite *next);
int					range_color(char **x);
int					is_space(char c);
void				error_map(t_cub *cub, int x, int y, int max);
void				init_player_pos(t_cub *cub, double dir, double pln);
void				get_map(t_cub *cub);
int					position_check(char c);
int					notempty_tex(t_cub *cub);
int					validechar(char c);
int					countwords(char const *str, char c);
int					isnotnum(char *str);
void				rgbcheck(t_cub *cub);
void				bpm_looping(t_cub *cub, int fd, unsigned char *bmppad);
void				insert_textures(t_cub *cub, char **path, int *fd);
void				sprite_helper(t_cub *cub, t_sprite *next);
void				clean(t_cub *cub);
void				spliter_clean(t_cub *cub);
void				map_clean(t_cub *cub);
void				rgb_clean(t_cub *cub);

#endif
