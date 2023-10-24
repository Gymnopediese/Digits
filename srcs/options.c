/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:50:28 by albaud            #+#    #+#             */
/*   Updated: 2023/10/24 11:55:10 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	div255(double n)
{
	return ((n / 255.0) > 0.5);
}

void	loop(int key, t_boy *boy)
{
	if (key == KEYCODE_C)
		printf("the num%i\n", ia_predict(&boy->net, &boy->draw.canvas));
}

void	option_train(t_boy *boy)
{
	int	iter;

	init_neuronal_network(&boy->net, (t_info){
		.name = "test",
		.inputs = 784,
		.hiden_layers = 1,
		.hiden_layers_size = (int []){
		input_int("select the neuron ammount", 0, 10000)
	},
		.outputs = 10,
		.function = FUNCTION_SIGMOID,
		.learning = -input_double("select the learning rate", 0, 1),
	});
	iter = input_int("select the ammount of iterations", 0, 1000);
	boy->train = read_csv_file("./archive/mnist_train.csv", 784, 10, 1, 60000);
	boy->test = read_csv_file("./archive/mnist_test.csv", 784, 10, 1, 10000);
	m_apply(&boy->train.input, div255);
	m_apply(&boy->test.input, div255);
	train_test_neuronal_network(&boy->net, &boy->train, &boy->test, iter);
}

void	option_test(t_boy *boy)
{
	if (!boy->net.info.name)
		boy->net = ia_load(input(".snp file please").chars);
	init_draw_canvas(&boy->draw, 28, 28, 28);
	boy->draw.key = loop;
	mlx_loop(boy->draw.w.mlx);
}

void	option_load(t_boy *boy)
{
	boy->net = ia_load(input(".snp file please\n>> ").chars);
}
