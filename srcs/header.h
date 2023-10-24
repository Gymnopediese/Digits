/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:50:51 by albaud            #+#    #+#             */
/*   Updated: 2023/10/24 11:51:59 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libalbaud/libs.h"

typedef struct s_boy
{
	t_draw	draw;
	t_net	net;
	t_data	train;
	t_data	test;
}	t_boy;

void	option_train(t_boy *boy);
void	option_test(t_boy *boy);
void	option_load(t_boy *boy);

#endif