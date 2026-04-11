#include "binder.hh"

#include "../ast_nodes/block-item.hh"
#include "../ast_nodes/block.hh"
#include "../ast_nodes/function-dec.hh"
#include "../ast_nodes/type-name.hh"
#include "../ast_nodes/var.hh"

#include "../misc/format-helper.hh"

namespace ast
{

  void Binder::operator()(FunctionDec& e)
  {
    // TODO func args will vardec, we must visit them

    var_map_.scope_begin();

    e.return_type_get().accept(*this);
    e.body_get().accept(*this);

    var_map_.scope_end();
  }

  void Binder::operator()(BlockStatement& e)
  {
    var_map_.scope_begin();

    for (BlockItem* bi : e.items_get())
      bi->accept(*this);

    var_map_.scope_end();
  }

  void Binder::operator()(Var& e)
  {
    VarDec* def = var_map_.get(e.identifier_get());

    if (def == nullptr)
      {
        error_ << misc::error_type::bind << misc::err() << "Variable `"
               << misc::bold(e.identifier_get()) << "` is not declared\n";
      }
    else
      {
        e.def_set(def);
      }
  }

  void Binder::operator()(VarDec& e)
  {
    e.type_get().accept(*this);
    if (e.init_get())
      e.init_get()->accept(*this);

    if (var_map_.current_contain(e.name_get()))
      {
        error_ << misc::error_type::bind << misc::err() << "Variable `"
               << misc::bold(e.name_get())
               << "` was already declared in this scope\n";
      }
    else
      {
        var_map_.put(e.name_get(), &e);
      }
  }

} // namespace ast
