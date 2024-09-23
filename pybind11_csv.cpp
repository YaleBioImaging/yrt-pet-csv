/*
* This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

#if BUILD_PYBIND11

#include "CSVListMode.hpp"

#include <pybind11/pybind11.h>

namespace py = pybind11;

void registerCSVPybind11Module(py::module& m)
{
	auto c = pybind11::class_<CSVListMode, ListMode>(m, "CSVListMode");
	c.def(py::init<const Scanner&, const std::string&>());
}

REGISTER_PROJDATA_PYBIND11("CSV", CSVListMode, registerCSVPybind11Module)

#endif
