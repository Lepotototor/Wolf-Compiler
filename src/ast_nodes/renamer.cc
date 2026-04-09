#include "renamer.hh"

#include "../ast_nodes/var.hh"

namespace ast
{

  void Renamer::operator()(Var& e)
  {
    if (e.def_get() == nullptr)
      {
        std::clog << "Def not set for " << e.identifier_get() << " at "
                  << e.location_get() << "\n";
      }
    else
      {
        e.identifier_set(e.def_get()->name_get());
      }
  }

  void Renamer::operator()(VarDec& e)
  {
    e.type_get().accept(*this);
    if (e.init_get())
      e.init_get()->accept(*this);

    e.name_set(e.name_get() + "." + std::to_string(count_++));
  }

} // namespace ast
