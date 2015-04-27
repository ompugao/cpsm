// cpsm - fuzzy path matcher
// Copyright (C) 2015 Jamie Liu
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef CPSM_STR_UTIL_H_
#define CPSM_STR_UTIL_H_

#include <sstream>
#include <string>

#include <boost/utility/string_ref.hpp>

namespace cpsm {

inline void str_cat_impl(std::stringstream& ss) {}

template <typename T, typename... Args>
void str_cat_impl(std::stringstream& ss, T const& x, Args... args) {
  ss << x;
  str_cat_impl(ss, args...);
}

// Concatenates an arbitrary number of arguments that can be stringifed through
// a stringstream.
template <typename... Args>
std::string str_cat(Args... args) {
  std::stringstream ss;
  str_cat_impl(ss, args...);
  return ss.str();
}

// Returns a new std::string that is a copy of the data viewed by the given
// boost::string_ref.
inline std::string copy_string_ref(boost::string_ref const sref) {
  return std::string(sref.data(), sref.size());
}

} // namespace cpsm

#endif /* CPSM_STR_UTIL_H_ */