#include "token.hh"

#include "../misc/debug.hh"

namespace lexer
{
  const std::string tok_repr(const Token& tok)
  {
    switch (tok.type())
      {
      case END_OF_FILE_TOK:
        return "END_OF_FILE";

      case VOID_TOK:
        return "void";
      case INT_TOK:
        return "int";
      case CHAR_TOK:
        return "char";
      case FLOAT_TOK:
        return "flot";
      case DOUBLE_TOK:
        return "double";
      case UNSIGNED_TOK:
        return "unsigned";
      case SIGNED_TOK:
        return "signed";
      case LONG_TOK:
        return "long";
      case SHORT_TOK:
        return "short";
      case REGISTER_TOK:
        return "register";

      case STRUCT_TOK:
        return "struct";
      case UNION_TOK:
        return "union";
      case ENUM_TOK:
        return "enum";

      case TYPEDEF_TOK:
        return "typedef";
      case EXTERN_TOK:
        return "extern";
      case CONST_TOK:
        return "const";
      case STATIC_TOK:
        return "static";
      case INLINE_TOK:
        return "inline";
      case VOLATILE_TOK:
        return "volatile";

      case WHILE_TOK:
        return "while";
      case FOR_TOK:
        return "for";
      case DO_TOK:
        return "do";
      case BREAK_TOK:
        return "break";
      case CONTINUE_TOK:
        return "continue";
      case IF_TOK:
        return "if";
      case ELSE_TOK:
        return "else";
      case SWITCH_TOK:
        return "switch";
      case CASE_TOK:
        return "case";
      case DEFAULT_TOK:
        return "default";
      case GOTO_TOK:
        return "goto";
      case SIZEOF_TOK:
        return "sizeof";
      case RETURN_TOK:
        return "return";

      case NOT_TOK:
        return "!";
      case EQ_TOK:
        return "==";
      case NOT_EQ_TOK:
        return "!=";
      case LT_TOK:
        return "<";
      case GT_TOK:
        return ">";
      case LE_TOK:
        return "<=";
      case GE_TOK:
        return ">=";
      case AND_TOK:
        return "&&";
      case OR_TOK:
        return "||";
      case PLUS_TOK:
        return "+";
      case MINUS_TOK:
        return "-";
      case STAR_TOK:
        return "*";
      case DIV_TOK:
        return "/";
      case MOD_TOK:
        return "%";
      case TILD_TOK:
        return "~";
      case AMP_TOK:
        return "&";
      case PIPE_TOK:
        return "|";
      case XOR_TOK:
        return "^";
      case RSHIFT_TOK:
        return ">>";
      case LSHIFT_TOK:
        return "<<";
      case QUESTION_TOK:
        return "?";

      case INC_TOK:
        return "++";
      case DEC_TOK:
        return "--";

      case PLUS_ASSIGN_TOK:
        return "+=";
      case MINUS_ASSIGN_TOK:
        return "-=";
      case MULT_ASSIGN_TOK:
        return "*=";
      case DIV_ASSIGN_TOK:
        return "/=";
      case MOD_ASSIGN_TOK:
        return "%=";
      case AMP_ASSIGN_TOK:
        return "&=";
      case PIPE_ASSIGN_TOK:
        return "|=";
      case XOR_ASSIGN_TOK:
        return "^=";
      case RSHIFT_ASSIGN_TOK:
        return ">>=";
      case LSHIFT_ASSIGN_TOK:
        return "<<=";

      case ASSIGN_TOK:
        return "=";
      case DOT_TOK:
        return ".";
      case ARROW_TOK:
        return "->";
      case COMMA_TOK:
        return ",";
      case SEMICOLON_TOK:
        return ";";
      case COLON_TOK:
        return ":";
      case ELLIPSIS_TOK:
        return "...";

      case OPAR_TOK:
        return "(";
      case CPAR_TOK:
        return ")";
      case OCURL_TOK:
        return "{";
      case CCURL_TOK:
        return "}";
      case OBRA_TOK:
        return "[";
      case CBRA_TOK:
        return "]";

      default:
        if (tok.contain_value())
          {
            return tok.val_get();
          }
        else
          {
            std::cerr << tok.type() << "\n";
            unreachable();
          }
      }
  }
} // namespace lexer
