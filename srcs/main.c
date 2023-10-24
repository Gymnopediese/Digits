/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:52:52 by albaud            #+#    #+#             */
/*   Updated: 2023/10/24 12:14:32 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(void)
{
	t_boy	boy;

	bzero(&boy, sizeof(t_boy));
	while (1)
	{
		input_box(&boy, "select an option", 3, (char *[]){
			"train new neurones",
			"load neuronal network",
			"test neurones"
		}, (void (*[])()){
			option_train,
			option_load,
			option_test
		});
		print_net(&boy.net);
	}
}

// int main()
// {
// 	t_boy	boy;

// 	init_neuronal_network(&boy.net, (t_info){
// 		.name = "test",
// 		.inputs = 784,
// 		.hiden_layers = 1,
// 		.hiden_layers_size = (int []){784},
// 		.outputs = 10,
// 		.function = FUNCTION_SIGMOID,
// 		.learning = -0.01,
// 	});
// 	boy.train = read_csv_file("./archive/mnist_train.csv", 784, 10, 1, 60000);
// 	boy.test = read_csv_file("./archive/mnist_test.csv", 784, 10, 1, 10000);
// 	m_apply(&boy.train.input, div255);
// 	m_apply(&boy.test.input, div255);
// 	train_test_neuronal_network(&boy.net,
// 		&boy.train, &boy.test, 100);
// }
