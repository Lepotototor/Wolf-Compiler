#pragma once

#include "scoped-map.hh"

#include <stdexcept>
#include <type_traits>

namespace misc
{
  template <typename Key, typename Data>
  void scoped_map<Key, Data>::scope_begin()
  {
    current_scope_++;
    scopes_.emplace_back();
  }

  template <typename Key, typename Data> void scoped_map<Key, Data>::scope_end()
  {
    if (current_scope_ > 0)
      {
        current_scope_--;
        scopes_.pop_back();
      }
  }

  template <typename Key, typename Data>
  void scoped_map<Key, Data>::put(const Key& key, const Data& value)
  {
    scopes_[current_scope_ - 1][key] = value;
  }

  template <typename Key, typename Data>
  Data scoped_map<Key, Data>::get(const Key& key) const
  {
    for (size_t i = current_scope_; i >= 1; i--)
      {
        try
          {
            return scopes_[i - 1].at(key);
          }
        catch (std::out_of_range&)
          {}
      }

    if constexpr (std::is_pointer<Data>::value)
      return nullptr;
    else
      throw std::out_of_range("Cant find value `" + key + "`");
  }

  template <typename Key, typename Data>
  bool scoped_map<Key, Data>::current_contain(const Key& key) const
  {
    try
      {
        return scopes_[current_scope_ - 1].contains(key);
      }
    catch (std::exception&)
      {
        return false;
      }
  }

  template <typename Key, typename Data>
  std::ostream& scoped_map<Key, Data>::dump(std::ostream& ostr) const
  {
    for (size_t i = current_scope_; i >= 1; i--)
      {
        ostr << "Scope " << i << "\n";

        for (const auto& it : scopes_[i - 1])
          {
            ostr << it.first << " -> " << it.second << "\n";
          }

        ostr << "\n";
      }

    return ostr;
  }

  template <typename Key, typename Data>
  inline std::ostream& operator<<(std::ostream& ostr,
                                  const scoped_map<Key, Data>& tbl)
  {
    return tbl.dump(ostr);
  }

} // namespace misc
