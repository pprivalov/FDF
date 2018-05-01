/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprivalo <pprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 18:30:13 by pprivalo          #+#    #+#             */
/*   Updated: 2018/02/04 18:23:02 by pprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_H
# define _VECTOR_H

typedef double	t_vector __attribute__((vector_size(sizeof(double)*4)));

t_vector		ft_mult_mtrx(t_vector *vec1, t_vector vec2);
t_vector		*ft_make_m(t_vector v0, t_vector v1, t_vector v2, t_vector v3);
t_vector		ft_make_v(double x, double y, double z, double a);

#endif
