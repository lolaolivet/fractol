/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:18:21 by lolivet           #+#    #+#             */
/*   Updated: 2018/05/07 15:18:33 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** définir x1 = -2.1
** définir x2 = 0.6
** définir y1 = -1.2
** définir y2 = 1.2
** définir zoom = 100
** définir iteration_max = 100
** définir image_x = (x2 - x1) * zoom
** définir image_y = (y2 - y1) * zoom
** un tableau que l'on va incrémenter à chaque fois que la suite Z_n passera par un point.
** définir pixels comme un tableau 2D de image_x cases sur image_y cases avec toutes les cases initialisés à 0
** en théorie, on devrait faire une seul boucle dans laquelle on devrait prendre les coordonnés (x; y) au hasard.
** Pour x = 0 tant que x < image_x par pas de 1
**    Pour y = 0 tant que y < image_y par pas de 1
**         définir c_r = x / zoom + x1
**         définir c_i = y / zoom + y1
**        définir z_r = 0
**         définir z_i = 0
**         définir i = 0
**         définir tmp_pixels comme une liste de coordonnées
**         Faire
**             définir tmp = z_r
**             z_r = z_r*z_r - z_i*z_i + c_r
**          z_i = 2*z_i*tmp + c_i
**             i = i+1
**             ajouter les coordonnées ((z_r-x1)*zoom; (z_i-y1)*zoom) au tableau tmp_pixels
**         Tant que z_r*z_r + z_i*z_i < 4 et i < iteration_max
**         si i != iteration_max
**             Pour chaque valeurs pixel de tmp_pixels
**                 si la case pixels[pixel[0]][pixel[1]] existe
**                     on incrémente la case en question
**                 finSi
**             finPour
**         finSi
**     finPour
** finPour
** Pour chaque case de coordonnée (x; y) de l'image
**     Dessiner le pixel de coordonnée (x; y) avec la couleur rgb(min(pixels[x][y], 255), min(pixels[x][y], 255), min(pixels[x][y], 255))
** finPour
*/
void    draw_buddhabrot(t_args *a)
{
    double  x1 = -2.1;
    double  x2 = 0.6;
    double  y1 = -1.2;
    double  y2 = 1.2;
    int     zoom = 100;
    int     iter_max = 100;
    double  img_x = (x2 - x1) * zoom;
    double  img_y = (y2 - y1) * zoom;
    double  pixels[img_x][img_y];
    int i = 0;
    int j = 0;
    while (i < img_x)
    {
        ft_bzero(&pixels[i], sizeof(img_y));
        i++;
    }
    i = 0;
    while (i < img_x)
    {
        while (j < img_y)
        {
            printf("%f",pixels[i][j]);
            j++;
        }
        printf("\n");
        j = 0;
        i++;
    }
}
