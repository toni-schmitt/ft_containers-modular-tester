/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_objects.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:40:08 by tschmitt          #+#    #+#             */
/*   Updated: 2022/10/26 19:40:09 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../i_base_test.hpp"
#include "../generic/construction_test.hpp"
#include "../generic/capacity_test.hpp"
#include "../generic/iterator_test.hpp"
#include "capacity_test.hpp"
#include "element_access_test.hpp"
#include "modifiers.hpp"

namespace vector
{
	template < class ContainerSTD, class ContainerFT >
	struct test_objects
	{
		static i_base_test<ContainerSTD> *std[];
		static i_base_test<ContainerFT> *ft[];
	};

	template < class ContainerSTD, class ContainerFT >
	i_base_test<ContainerSTD> *test_objects<ContainerSTD, ContainerFT>::std[] = {
			new generic::construction_test<ContainerSTD>(false),
			new generic::capacity_test<ContainerSTD>(false),
			new generic::iterator_test<ContainerSTD>(false),
			new vector::capacity_test<ContainerSTD>(false),
			new vector::element_access_test<ContainerSTD>(false),
			new vector::modifiers_test<ContainerSTD>(false),
			NULL
	};
	template < class ContainerSTD, class ContainerFT >
	i_base_test<ContainerFT> *test_objects<ContainerSTD, ContainerFT>::ft[] = {
			new generic::construction_test<ContainerFT>(false),
			new generic::capacity_test<ContainerFT>(false),
			new generic::iterator_test<ContainerFT>(false),
			new vector::capacity_test<ContainerFT>(false),
			new vector::element_access_test<ContainerFT>(false),
			new vector::modifiers_test<ContainerFT>(false),
			NULL
	};
}