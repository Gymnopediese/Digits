/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:52:52 by albaud            #+#    #+#             */
/*   Updated: 2023/10/19 10:32:50 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libalbaud/libs.h"


typedef struct s_boy
{
	t_draw	draw;
	t_net	net;
	t_data	train;
	t_data	test;
}	t_boy;

// void	read_data(t_net *network)
// {
// 	char	**temp;
// 	int		i;

// 	temp = f_readlines(
// 			"/Users/albaud/Desktop/42/rank_ia/digits/archive/mnist_train.csv");
// 	i = 0;
// 	while (temp[++i])
// 	{
// 		ft_atoia_fast(&temp[i][2], ',', network->input.arr[i - 1].arr, 255);
// 		network->output.arr[i - 1].arr[ft_atoi(temp[i])] = 1;
// 	}
// 	m_apply(&network->input, binary);
// 	ft_free_pp((void **)temp);
// }

// double	test(t_net *net)
// {
// 	char	**temp;
// 	int		i;
// 	t_v		v;
// 	double	c;

// 	c = 0;
// 	v = v_new(784, 0);
// 	temp = f_readlines(
// 			"/Users/albaud/Desktop/42/rank_ia/digits/archive/mnist_test.csv");
// 	i = 0;
// 	while (temp[++i])
// 	{
// 		ft_atoia_fast(&temp[i][2], ',', v.arr, 255);
// 		v_apply(&v, binary);
// 		ia_forward(net, &v);
// 		ft_atoi(temp[i]) == v_maxi(&net->predicted_output))
// 		{
// 			c += 1;
// 		}
// 	}
// 	return (c / 10000 * 100);
// }

double	div255(double n)
{
	return (n / 255.0 > 0.5);
}

int	loop(t_boy *boy)
{
	static int	i = 0;

	printf("%i\n", v_maxi(&boy->train.output.arr[i]));
	put_canvas(&boy->train.input.arr[i++], &boy->draw);
	return (0);
}


int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	t_boy	boy;

	// init_draw_canvas(&boy.draw, 28, 28, 28);
	init_neuronal_network(&boy.net, (t_info){
		.name = "test",
		.inputs = 784,
		.hiden_layers = 1,
		.hiden_layers_size = (int []){16},
		.outputs = 10,
		.function = sigmoid,
		.function_prime = sigmoid_prime,
		.learning = 0.001,
	});
	printf("hidden %d", boy.net.info.hiden_layers_size[0]);
	boy.train = read_csv_file("./archive/mnist_train.csv", 784, 10, 1, 60000);
	printf("slaut\n");
	boy.test = read_csv_file("./archive/mnist_test.csv", 784, 10, 1, 10000);
	// put_canvas(boy.train.input.arr, &boy.draw);
	// mlx_loop_hook(boy.draw.w.mlx, loop, &boy);
	// mlx_loop(boy.draw.w.mlx);
	printf("slaut\n");
	m_apply(&boy.train.input, div255);
	m_apply(&boy.test.input, div255);
	// m_apply(&train.input, binary);
	// m_apply(&test.input, binary);
	train_test_neuronal_network(&boy.net, &boy.train, &boy.test, 100);
	// train_neuronal_network(&net, &train, 10);
	// test_neuronal_network(&net, &test);
}

//./digit  31,95s user 0,38s system 98% cpu 32,890 total
//./digit  30,70s user 0,35s system 97% cpu 31,756 total




