#pragma once

#include "../visitor/ast_visitor.hh"

#include "../misc/error.hh"
#include "../misc/scoped-map.hh"

#include <string>

namespace ast
{

  class Binder : public Visitor
  {
  public:
    Binder(misc::Error& error)
      : error_(error)
    {}

    virtual void operator()(FunctionDec& e) override;
    virtual void operator()(BlockStatement& e) override;
    virtual void operator()(While& e) override;
    virtual void operator()(DoWhile& e) override;
    virtual void operator()(For& e) override;
    virtual void operator()(Break& e) override;
    virtual void operator()(Continue& e) override;
    virtual void operator()(Var& e) override;
    virtual void operator()(VarDec& e) override;

  private:
    // Use to send binding errors
    misc::Error& error_;

    misc::scoped_map<std::string, VarDec*> var_map_;

    LoopStatement* curr_loop_ = nullptr;
  };

} // namespace ast
