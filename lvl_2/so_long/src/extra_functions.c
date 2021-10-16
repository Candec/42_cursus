/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez- <jibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:03:44 by jibanez-          #+#    #+#             */
/*   Updated: 2021/10/16 20:53:38 by jibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

int	render(t_mlx *data)
{
	if (data->win_ptr == NULL)
		return (1);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, 960, 540, 0xFF0000);
	return (0);
}
