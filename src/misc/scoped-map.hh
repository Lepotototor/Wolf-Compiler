#pragma once

#include <iostream>
#include <map>
#include <vector>

namespace misc
{
  template <typename Key, typename Data> class scoped_map
  {
    using map = std::map<Key, Data>;
    using map_vec = std::vector<map>;

  public:
    scoped_map() = default;
    ~scoped_map() = default;

    void scope_begin();
    void scope_end();

    void put(const Key& key, const Data& value);
    Data get(const Key& key) const;

    bool current_contain(const Key& key) const;

    std::ostream& dump(std::ostream& ostr) const;

  private:
    map_vec scopes_;
    size_t current_scope_ = 0;
    // DEXIF
  };

  template <typename Key, typename Data>
  std::ostream& operator<<(std::ostream& ostr,
                           const scoped_map<Key, Data>& tbl);

} // namespace misc

#include "scoped-map.hxx"
