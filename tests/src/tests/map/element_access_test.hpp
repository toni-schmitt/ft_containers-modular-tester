/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_access_test.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:39:00 by tschmitt          #+#    #+#             */
/*   Updated: 2022/10/26 19:39:01 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../i_base_test.hpp"
#include "../../utility/test_cases.hpp"

namespace map
{
	template < class Container >
	struct element_access_test : public i_base_test<Container>
	{
		typedef typename i_base_test<Container>::container_type container_type;
		typedef typename i_base_test<Container>::value_type value_type;

		void test(out_file_stream *ofs = NULL)
		{
			if (ofs != NULL)
			{
				this->update_ofs(ofs);
			}

			this->print_test_start();

			this->container = FILL_CONTAINER_WITH_TEST_CASE;
			(*this->ofs) << "Testing with Container of Size " << this->container.size() << std::endl;

			this->_test_operator(this->container);
			this->_test_at(this->container);

			this->print_test_end();
		}

	private:
		void _test_operator(container_type &container)
		{
			(*this->ofs) << "operator[]" << std::endl;

			value_type *test_case = GET_TEST_CASE;
			std::srand(*reinterpret_cast<int *>(&test_case[ 0 ].second));

			for (size_t i = 0; i < container.size() / 2 && i < test_cases::size; ++i)
			{
				size_t index;
				do
				{
					index = std::rand() % 10;
				} while (index >= container.size() && index >= 100);
				TRY_CATCH_WRITE((*this->ofs) << container[ test_case[ index ].first ] << ',');
				TRY_CATCH_WRITE((*this->ofs) << (container[ test_case[ index ].first ] = test_case[ i ].first) << ',');
			}
			(*this->ofs) << std::endl;

			(*this->ofs) << std::endl;
		}

		void _test_at(container_type &container)
		{
			(*this->ofs) << "at()" << std::endl;

			value_type *test_case = GET_TEST_CASE;
			std::srand(*reinterpret_cast<int *>(&test_case[ 0 ].second));

			for (size_t i = 0; i < container.size() / 2; ++i)
			{
				TRY_CATCH_WRITE((*this->ofs) << container.at(test_case[ std::rand() % 10 ].first) << ',');
			}
			(*this->ofs) << std::endl;

			(*this->ofs) << std::endl;
		}

	public:
		explicit element_access_test(
				bool run_test_in_constructor = true
		) : i_base_test<Container>("MapElementAccess")
		{
			if (!run_test_in_constructor)
				return;

			try
			{
				this->test();
			}
			catch (...)
			{
				throw;
			}
		}
	};
}