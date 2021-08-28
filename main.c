#include "mlx/mlx.h"
#include "stdio.h"
#include "stdlib.h"

#include "main.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
    void	*img;
    void	*img2;
    int pos_player_x;
    int pos_player_y;
    char **tab;
    int res_x;
    int res_y;
    int move_count;
}				t_vars;

void    ft_find_pos(t_vars *vars)
{
    int x;
    int y;

    x = 0;
    y = 0;

    while (vars->tab[x])
    {
        y = 0;
        while (vars->tab[x][y])
        {
            if (vars->tab[x][y] == 'P')
            {
                vars->pos_player_x = x;
                vars->pos_player_y = y;
            }
            y++;
        }
        x++;
    }
}

int	ft_nb_collectible(char **tab)
{
    int x;
    int y;
    int i;

    x = 0;
    y = 0;
    i = 0;

    while (tab[x])
    {
        y = 0;
        while (tab[x][y])
        {
            if (tab[x][y] == 'C')
                i++;
            y++;
        }
        x++;
    }
    printf("i = %d\n", i);
    return i;
}

void    ft_show_tab(char **tab)
{
    int x;
    int y;
    int i;

    x = 0;
    y = 0;
    i = 0;

    while (tab[x])
    {
        y = 0;
        while (tab[x][y])
        {
            printf("%c", tab[x][y]);
            y++;
        }
        printf("\n");
        x++;
    }
}

int     ft_move_top(t_vars *vars)
{
    printf("top\n");
    ft_show_tab(vars->tab);
    printf("-----------------\n");
    printf("case : %c\n", vars->tab[vars->pos_player_x - 1][vars->pos_player_y]);
    if (vars->tab[vars->pos_player_x - 1][vars->pos_player_y] != '1' && vars->tab[vars->pos_player_x - 1][vars->pos_player_y] != 'E')
    {
        vars->tab[vars->pos_player_x][vars->pos_player_y] = '0';
        vars->tab[vars->pos_player_x - 1][vars->pos_player_y] = 'P';
        vars->pos_player_x = vars->pos_player_x - 1;
        ft_show_tab(vars->tab);
        printf("*******************\n");
        return 1;
    }
    if (vars->tab[vars->pos_player_x - 1][vars->pos_player_y] == 'E')
    {
        printf("case E\n");
        if (ft_nb_collectible(vars->tab) == 0)
        {
            printf("end of the game\n");
            vars->tab[vars->pos_player_x][vars->pos_player_y] = '0';
            vars->tab[vars->pos_player_x - 1][vars->pos_player_y] = 'P';
            vars->pos_player_x = vars->pos_player_x - 1;
            return 1;
        }
        else
            printf("il y toujours %d collectible\n", ft_nb_collectible(vars->tab));
    }
    return 0;
}

int     ft_move_bot(t_vars *vars)
{
    printf("bot\n");
    ft_show_tab(vars->tab);
    printf("-----------------\n");
    printf("case : %c\n", vars->tab[vars->pos_player_x + 1][vars->pos_player_y]);
    if (vars->tab[vars->pos_player_x + 1][vars->pos_player_y] != '1' && vars->tab[vars->pos_player_x + 1][vars->pos_player_y] != 'E')
    {
        vars->tab[vars->pos_player_x][vars->pos_player_y] = '0';
        vars->tab[vars->pos_player_x + 1][vars->pos_player_y] = 'P';
        vars->pos_player_x = vars->pos_player_x + 1;
        ft_show_tab(vars->tab);
        printf("****************\n");
        return 1;
    }
    if (vars->tab[vars->pos_player_x + 1][vars->pos_player_y] == 'E')
    {
        printf("case E\n");
        if (ft_nb_collectible(vars->tab) == 0)
        {
            printf("end of the game\n");
            vars->tab[vars->pos_player_x][vars->pos_player_y] = '0';
            vars->tab[vars->pos_player_x + 1][vars->pos_player_y] = 'P';
            vars->pos_player_x = vars->pos_player_x + 1;
            return 1;
        }
        else
            printf("il y toujours %d collectible\n", ft_nb_collectible(vars->tab));
    }
    return 0;
}

int     ft_move_left(t_vars *vars)
{
    printf("left\n");
    ft_show_tab(vars->tab);
    printf("-----------------\n");
    printf("case : %c\n", vars->tab[vars->pos_player_x][vars->pos_player_y - 1]);
    if (vars->tab[vars->pos_player_x][vars->pos_player_y - 1] != '1' && vars->tab[vars->pos_player_x][vars->pos_player_y - 1] != 'E')
    {
        vars->tab[vars->pos_player_x][vars->pos_player_y] = '0';
        vars->tab[vars->pos_player_x][vars->pos_player_y - 1] = 'P';
        vars->pos_player_y = vars->pos_player_y - 1;
        // ft_show_tab(vars->tab);
        // printf("***************\n");
        return 1;
    }
    if (vars->tab[vars->pos_player_x][vars->pos_player_y - 1] == 'E')
    {
        if (ft_nb_collectible(vars->tab) == 0)
        {
            printf("end of the game\n");
            vars->tab[vars->pos_player_x][vars->pos_player_y] = '0';
            vars->tab[vars->pos_player_x ][vars->pos_player_y - 1] = 'P';
            vars->pos_player_y = vars->pos_player_y - 1;
            return 1;
        }
        else
            printf("il y toujours %d collectible\n", ft_nb_collectible(vars->tab));
    }
    return 0;
}

int     ft_move_right(t_vars *vars)
{
    printf("right\n");
    ft_show_tab(vars->tab);
    printf("-----------------\n");
    printf("case : %c\n", vars->tab[vars->pos_player_x][vars->pos_player_y + 1]);
    if (vars->tab[vars->pos_player_x][vars->pos_player_y + 1] != '1' && vars->tab[vars->pos_player_x][vars->pos_player_y + 1] != 'E')
    {
        vars->tab[vars->pos_player_x][vars->pos_player_y] = '0';
        vars->tab[vars->pos_player_x][vars->pos_player_y + 1] = 'P';
        vars->pos_player_y = vars->pos_player_y + 1;
        ft_show_tab(vars->tab);
        printf("********************\n");
        return 1;
    }
    if (vars->tab[vars->pos_player_x][vars->pos_player_y + 1] == 'E')
    {
        if (ft_nb_collectible(vars->tab) == 0)
        {
            printf("end of the game\n");
            vars->tab[vars->pos_player_x][vars->pos_player_y] = '0';
            vars->tab[vars->pos_player_x ][vars->pos_player_y + 1] = 'P';
            vars->pos_player_y = vars->pos_player_y + 1;
            return 1;
        }
        else
            printf("il y toujours %d collectible\n", ft_nb_collectible(vars->tab));
    }
    return 0;
}

int	key_hook2(int keycode, t_vars *vars)
{
	if (keycode == 13 || keycode == 126)
        vars->move_count += ft_move_top(vars);
    if (keycode == 1 || keycode == 125)
        vars->move_count += ft_move_bot(vars);
    if (keycode == 0 || keycode == 123)
        vars->move_count += ft_move_left(vars);
    if (keycode == 2 || keycode == 124)
        vars->move_count += ft_move_right(vars);
    printf("nombre de coups joués = %d\n", vars->move_count);
    return 1;
}


int     ft_size_round(int x)
{
    int i = 0;
    int n = x;
    while (n != 0)
    {
        n =  n / 10;
        i++;
    }
    return i;
}

int     my_mlx_pixel_color(t_data_img *data, int x, int y)
{
    char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return *(unsigned int*)dst;
}

int     ft_find_color(char c, t_data_struct *structure, int x, int y)
{
    if (c == '1')
        return (my_mlx_pixel_color(&structure->wall, (y % 32), (x % 32)));
    if (c == 'P')
        return 0xABDCBA;
    if (c == '0')
        return (my_mlx_pixel_color(&structure->floor, (y % 32), (x % 32)));
    if (c == 'C')
        return 0XFEACBD;
    if (c == 'E')
        return 0XAECDBF;
    return 0;
}

int    ft_put_string(t_vars *vars)
{
    char *str;
    int size_round;
    int mv = vars->move_count;
    size_round = ft_size_round(mv) + 6;
    if (!(str = malloc(sizeof(char) * (6 + size_round))))
        return 0;
    str[0] = 'c';
    str[1] = 'o';
    str[2] = 'u';
    str[3] = 'p';
    str[4] = ' ';
    size_round--;
    str[6] = '\0';
    size_round--;
    int u = 5;

    while (size_round > 4)
    {
        str[size_round] = (mv % 10) + 48;
        mv /= 10;
        size_round--;
    }
    mlx_string_put(vars->mlx, vars->win, 580, 20, 0x00FF0000, str);
    return 1;
}

// int    create_image(t_vars *vars)
// {
//     int i = 0;
//     int j = 0;
//     vars->img = mlx_new_image(vars->mlx, vars->res_x, vars->res_y);

//     int pixel_bits;
//     int line_bytes;
//     int endian;
//     char *buffer = mlx_get_data_addr(vars->img, &pixel_bits, &line_bytes, &endian);
//     while (vars->tab[i])
//     {
//         j = 0;
//         while (vars->tab[i][j])
//         {

//             int color;
//             int y;
//             int x;
//             int case_x = vars->res_x / 10;
//             int case_y = vars->res_y / 5;
//             int save_y;
//             int save_x;

//             color = ft_find_color(vars->tab[i][j]);
            
//             if (pixel_bits != 32)
//                 color = mlx_get_color_value(vars->mlx, color);

//             y = (0 + case_y * i);
//             x = (0 + case_x * j);
//             save_y = y;
//             save_x = x;

//             while (y < (save_y + case_y))
//             {   
//                 x = (0 + case_x * j);
//                 save_x = x;

//                 while (x < (save_x + case_x))
//                 {
//                     int pixel = (y * line_bytes) + (x * 4);

//                     if (endian == 1)        // Most significant (Alpha) byte first
//                     {
//                         buffer[pixel + 0] = (color >> 24);
//                         buffer[pixel + 1] = (color >> 16) & 0xFF;
//                         buffer[pixel + 2] = (color >> 8) & 0xFF;
//                         buffer[pixel + 3] = (color) & 0xFF;
//                     }
//                     else if (endian == 0)   // Least significant (Blue) byte first
//                     {
//                         buffer[pixel + 0] = (color) & 0xFF;
//                         buffer[pixel + 1] = (color >> 8) & 0xFF;
//                         buffer[pixel + 2] = (color >> 16) & 0xFF;
//                         buffer[pixel + 3] = (color >> 24);
//                     }
//                     x++;
//                 }
//                 y++;
//             }
//             j++;
//         }
//         i++;
//     }
//     mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
//     ft_put_string(vars);
//     return 1;
// }

void	my_mlx_pixel_put(t_data_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
    // printf("1 : %d\n", color);
    // printf("2 : %d\n", *(unsigned int*)dst);
}

int    create_image2(t_vars *vars)
{
    t_data_struct structure;
    // t_data_img	img;
    int i = 0;
    int j = 0;
    vars->img = mlx_new_image(vars->mlx, vars->res_x, vars->res_y);

    int     img_height;
    int     img_width;
    char	*relative_path = "./stone.xpm";
    char	*relative_path2 = "./grass.xpm";

    // vars->img2 = mlx_xpm_file_to_image(vars->mlx, relative_path, &img_width, &img_height);
    structure.wall.img = mlx_xpm_file_to_image(vars->mlx, relative_path, &img_width, &img_height);
    structure.wall.addr = mlx_get_data_addr(structure.wall.img, &structure.wall.bits_per_pixel, &structure.wall.line_length,
								&structure.wall.endian);

    structure.floor.img = mlx_xpm_file_to_image(vars->mlx, relative_path2, &img_width, &img_height);
    structure.floor.addr = mlx_get_data_addr(structure.floor.img, &structure.floor.bits_per_pixel, &structure.floor.line_length,
								&structure.floor.endian);

    int pixel_bits;
    int line_bytes;
    int endian;
    char *buffer = mlx_get_data_addr(vars->img, &pixel_bits, &line_bytes, &endian);
    // printf("----%d\n", line_bytes);
    // printf("----%d\n", pixel_bits);
    while (vars->tab[i])
    {
        j = 0;
        while (vars->tab[i][j])
        {

            int color;
            int y;
            int x;
            int case_x = vars->res_x / 10;
            int case_y = vars->res_y / 5;
            int save_y;
            int save_x;
            
            if (pixel_bits != 32)
                color = mlx_get_color_value(vars->mlx, color);

            y = (0 + case_y * i);
            x = (0 + case_x * j);
            save_y = y;
            save_x = x;

            while (y < (save_y + case_y))
            {   
                x = (0 + case_x * j);
                save_x = x;

                while (x < (save_x + case_x))
                {
                    int pixel = (y * line_bytes) + (x * 4);
                    color = ft_find_color(vars->tab[i][j], &structure, x, y);

                    if (endian == 1)        // Most significant (Alpha) byte first
                    {
                        buffer[pixel + 0] = (color >> 24);
                        buffer[pixel + 1] = (color >> 16) & 0xFF;
                        buffer[pixel + 2] = (color >> 8) & 0xFF;
                        buffer[pixel + 3] = (color) & 0xFF;
                    }
                    else if (endian == 0)   // Least significant (Blue) byte first
                    {
                        buffer[pixel + 0] = (color) & 0xFF;
                        buffer[pixel + 1] = (color >> 8) & 0xFF;
                        buffer[pixel + 2] = (color >> 16) & 0xFF;
                        buffer[pixel + 3] = (color >> 24);
                    }
                    x++;
                }
                y++;
            }
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
    // mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
    return 1;
}

int	main(int ac, char **av)
{
	t_vars	vars;
    t_data_img image;

    (void)ac;
	int		img_width;
	int		img_height;
    char	*relative_path = "./Steven01/normal.png";
    image.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);

    vars.res_x = 640;
    vars.res_y = 360;
    vars.move_count = 0;

    vars.tab = ft_map(av[1]);
    
    ft_find_pos(&vars);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.res_x, vars.res_y, "Hello world!");

    mlx_key_hook(vars.win, key_hook2, &vars);
    mlx_loop_hook(vars.mlx, create_image2, &vars);

    mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);

	mlx_loop(vars.mlx);
}

