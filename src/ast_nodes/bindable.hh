#pragma once

namespace ast
{

  template <typename T> class Bindable
  {
  public:
    const T* def_get() const { return def_; }
    void def_set(T* def) { def_ = def; }

  private:
    T* def_ = nullptr;
  };

} // namespace ast
