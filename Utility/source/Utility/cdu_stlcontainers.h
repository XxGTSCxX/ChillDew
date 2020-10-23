#pragma once

#include "cdu_core.h"
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <memory> // std::unique_ptr, std::shared_ptr, std::weak_ptr

namespace chilldew::utility
{

    template <typename value_t> using allocator = std::allocator<value_t>;

    template <typename key_t                  > using unordered_set = std::unordered_set<key_t         >;
    template <typename key_t                  > using set           = std::set          <key_t         >;
    template <typename key_t, typename value_t> using unordered_map = std::unordered_map<key_t, value_t>;
    template <typename key_t, typename value_t> using map           = std::map          <key_t, value_t>;
    template <                typename value_t> using vector        = std::vector       <value_t       >;
    template <                typename value_t> using list          = std::list         <value_t       >;

    template <typename value_t> using unique_ptr = std::unique_ptr<value_t>;
    template <typename value_t> using shared_ptr = std::shared_ptr<value_t>;
    template <typename value_t> using weak_ptr   = std::weak_ptr  <value_t>;

}
