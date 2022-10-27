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

			container_type this_container = FILL_CONTAINER_WITH_TEST_CASE;
			(*this->ofs) << "Testing with Container of Size " << this_container.size() << std::endl;

			this->_test_operator(this_container);
			this->_test_at(this_container);

			this->print_test_end();
		}

	private:
		void _test_operator(container_type &container)
		{
			(*this->ofs) << "operator[]" << std::endl;

			std::srand(50000000);
			value_type *test_case = GET_TEST_CASE;

			for (size_t i = 0; i < container.size() / 2 && i < test_cases::size; ++i)
			{
				size_t index = std::rand() % 10;
				TRY_CATCH_WRITE((*this->ofs) << index << ':' << container[ test_case[ index ].first ] << ',');
				TRY_CATCH_WRITE(
						(*this->ofs) << index << ':' << (container[ test_case[ index ].first ] = test_case[ i ].first)
									 << ','
				);
			}
			(*this->ofs) << std::endl;

			(*this->ofs) << std::endl;
		}

		void _test_at(container_type &container)
		{
			(*this->ofs) << "at()" << std::endl;

			std::srand(500);
			value_type *test_case = GET_TEST_CASE;

			for (size_t i = 0; i < container.size() / 2; ++i)
			{
				ssize_t index = std::rand() % 10;
				TRY_CATCH_WRITE((*this->ofs) << index << ':' << container.at(test_case[ index ].first) << ',');
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