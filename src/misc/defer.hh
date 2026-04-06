#pragma once

#include "functional"

namespace misc
{

  class defer
  {
  public:
    defer() = default;

    defer(const std::function<void(void)>& func)
      : func_(func)
    {}

    ~defer() { func_(); }

    defer(const defer&) = delete;
    defer(defer&&) = delete;
    const defer& operator=(const defer&) = delete;
    defer&& operator=(const defer&&) = delete;

    void func_set(const std::function<void(void)>& func) { func_ = func; }

  private:
    std::function<void(void)> func_;
  };

} // namespace misc
