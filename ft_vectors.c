/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 05:27:01 by pprivalo          #+#    #+#             */
/*   Updated: 2018/02/14 15:28:33 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "vector.h"

t_vector	*ft_make_m(t_vector v0, t_vector v1, t_vector v2, t_vector v3)
{
	t_vector	*mtrx;

	if (!(mtrx = (t_vector *)malloc(sizeof(t_vector) * 4)))
		ft_errors(3, "");
	mtrx[0] = v0;
	mtrx[1] = v1;
	mtrx[2] = v2;
	mtrx[3] = v3;
	return (mtrx);
}

t_vector	ft_make_v(double x, double y, double z, double a)
{
	t_vector	vector;

	vector[0] = x;
	vector[1] = y;
	vector[2] = z;
	vector[3] = a;
	return (vector);
}

t_vector	ft_mult_mtrx(t_vector *mtrx, t_vector vc2)
{
	int			i;
	t_vector	res;

	i = -1;
	while (++i < 4)
		res[i] = mtrx[i][0] * vc2[0] + mtrx[i][1] * vc2[1] +
					mtrx[i][2] * vc2[2] + mtrx[i][2] * vc2[3];
	return (res);
}
