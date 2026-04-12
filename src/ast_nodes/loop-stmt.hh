#pragma once

#include "stmt.hh"

namespace ast
{

  class LoopStatement : public Statement
  {
  public:
    LoopStatement(const misc::Location& loc)
      : Statement(loc)
    {}

    const std::string& cond_label_get() const { return cond_label_; }
    void cond_label_set(const std::string& lbl) { cond_label_ = lbl; }
    const std::string& end_label_get() const { return end_label_; }
    void end_label_set(const std::string& lbl) { end_label_ = lbl; }

  private:
    std::string cond_label_;
    std::string end_label_;
  };

} // namespace ast
