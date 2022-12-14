/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_test.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:38:49 by tschmitt          #+#    #+#             */
/*   Updated: 2022/10/26 19:38:50 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../i_base_test.hpp"
#include "../../utility/test_cases.hpp"
#include "../../utility/write.hpp"

namespace generic
{
	template < class Container >
	struct iterator_test : public i_base_test<Container>
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

			value_type *test_case = test_cases::get_test_case(value_type());
			container_type range = container_type(test_case, test_case + test_cases::size);
			container_type this_container;

			// Begin
			(*this->ofs) << "Testing \'.begin()\' on empty Container" << std::endl;
			write::iterator::to_file(this_container.begin(), this_container.end(), (*this->ofs));
			(*this->ofs) << "Testing \'.begin()\' on Container with a size of " << range.size() << std::endl;
			write::iterator::to_file(range.begin(), range.end(), (*this->ofs));

			// End
			(*this->ofs) << "Testing \'.end()\' on empty Container" << std::endl;
			write::iterator::to_file(this_container.end(), this_container.end(), (*this->ofs));
			(*this->ofs) << "Testing \'.end()\' on Container with a size of " << range.size() << std::endl;
			write::iterator::to_file(range.end(), range.end(), (*this->ofs));

			// RBegin
			(*this->ofs) << "Testing \'.rbegin()\' on empty Container" << std::endl;
			write::iterator::to_file(this_container.rbegin(), this_container.rend(), (*this->ofs));
			(*this->ofs) << "Testing \'.rbegin()\' on Container with a size of " << range.size() << std::endl;
			write::iterator::to_file(range.rbegin(), range.rend(), (*this->ofs));

			// REnd
			(*this->ofs) << "Testing \'.rend()\' on empty Container" << std::endl;
			write::iterator::to_file(this_container.rend(), this_container.rend(), (*this->ofs));
			(*this->ofs) << "Testing \'.rend()\' on Container with a size of " << range.size() << std::endl;
			write::iterator::to_file(range.rend(), range.rend(), (*this->ofs));

			try
			{
				// Incrementing
				(*this->ofs) << "Testing \'.operator++()\' on Container with a size of " << range.size()
							 << std::endl;
				(*this->ofs) << "\'.begin()\'" << std::endl;
				(*this->ofs) << *(range.begin().operator++()) << std::endl;
//					(*this->ofs) << "\'.end()\'" << std::endl;
//					(*this->ofs) << *(range.end().operator++()) << std::endl;
				(*this->ofs) << "\'.rbegin()\'" << std::endl;
				(*this->ofs) << *(range.rbegin().operator++()) << std::endl;
//					(*this->ofs) << "\'.rend()\'" << std::endl;
//					(*this->ofs) << *(range.rend().operator++()) << std::endl;

				// Decrementing
				(*this->ofs) << "Testing \'.operator--()\' on Container with a size of " << range.size()
							 << std::endl;
//					(*this->ofs) << "\'.begin()\'" << std::endl;
//					(*this->ofs) << *(range.begin().operator--()) << std::endl;
				(*this->ofs) << "\'.end()\'" << std::endl;
				(*this->ofs) << *(range.end().operator--()) << std::endl;
//					(*this->ofs) << "\'.rbegin()\'" << std::endl;
//					(*this->ofs) << *(range.rbegin().operator--()) << std::endl;
				(*this->ofs) << "\'.rend()\'" << std::endl;
				(*this->ofs) << *(range.rend().operator--()) << std::endl;
			}
			catch (std::exception &e)
			{
				(*this->ofs) << "Exception: " << e.what() << std::endl;
			}
			catch (...)
			{
				(*this->ofs) << "Exception of unknown type was thrown" << std::endl;
			}

			this->print_test_end();
		}

		explicit iterator_test(
				bool run_test_in_constructor = true
		) : i_base_test<Container>("iterator_test")
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