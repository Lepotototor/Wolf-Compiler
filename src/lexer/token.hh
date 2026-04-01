#pragma once

#include "../misc/location.hh"

namespace lexer
{
  enum token_type
  {
    END_OF_FILE = 0,

    // Tokens with value
    NUM_TOK,
    STRING_TOK,

    VOID_TOK,     // void
    INT_TOK,      // int
    CHAR_TOK,     // char
    FLOAT_TOK,    // flot
    DOUBLE_TOK,   // double
    UNSIGNED_TOK, // unsigned
    SIGNED_TOK,   // signed
    LONG_TOK,     // long
    SHORT_TOK,    // short
    REGISTER_TOK, // register

    STRUCT_TOK, // struct
    UNION_TOK,  // union
    ENUM_TOK,   // enum

    TYPEDEF_TOK,  // typedef
    EXTERN_TOK,   // extern
    CONST_TOK,    // const
    STATIC_TOK,   // static
    INLINE_TOK,   // inline
    VOLATILE_TOK, // volatile

    WHILE_TOK,    // while
    FOR_TOK,      // for
    DO_TOK,       // do
    BREAK_TOK,    // break
    CONTINUE_TOK, // continue
    IF_TOK,       // if
    ELSE_TOK,     // else
    SWITCH_TOK,   // switch
    CASE_TOK,     // case
    DEFAULT_TOK,  // default
    GOTO_TOK,     // goto
    SIZEOF_TOK,   // sizeof
    RETURN_TOK,   // return

    NOT_TOK,      // !
    EQ_TOK,       // ==
    NOT_EQ,       // !=
    LT_TOK,       // <
    GT_TOK,       // >
    LE_TOK,       // <=
    GE_TOK,       // >=
    AND_TOK,      // &&
    OR_TOK,       // ||
    PLUS_TOK,     // +
    MINUS_TOK,    // -
    STAR_TOK,     // *
    DIV_TOK,      // /
    MOD_TOK,      // %
    TILD_TOK,     // ~
    AMP_TOK,      // &
    PIPE_TOK,     // |
    XOR_TOK,      // ^
    RSHIFT_TOK,   // >>
    LSHIFT_TOK,   // <<
    QUESTION_TOK, // ?

    INC_TOK, // ++
    DEC_TOK, // --

    PLUS_ASSIGN_TOK,   // +=
    MINUS_ASSIGN_TOK,  // -=
    MULT_ASSIGN_TOK,   // *=
    DIV_ASSIGN_TOK,    // /=
    MOD_ASSIGN_TOK,    // %=
    AMP_ASSIGN_TOK,    // &=
    PIPE_ASSIGN_TOK,   // |=
    XOR_ASSIGN_TOK,    // ^=
    RSHIFT_ASSIGN_TOK, // >>=
    LSHIFT_ASSIGN_TOK, // <<=

    ASSIGN_TOK,    // =
    DOT_TOK,       // .
    ARROW_TOK,     // ->
    COMMA_TOK,     // ,
    SEMICOLON_TOK, // ;
    COLON_TOK,     // :
    ELLIPSIS_TOK,  // ...

    OPAR_TOK,  // (
    CPAR_TOK,  // )
    OCURL_TOK, // {
    CCURL_TOK, // }
    OBRA_TOK,  // [
    CBRA_TOK,  // ]

    NB_TOKEN,
  };

  class Token : public misc::Locable
  {
  public:
    Token(token_type t, misc::Location& location)
      : misc::Locable(location)
      , type_(t)
    {}

    virtual bool operator==(const std::string&) const;
    virtual bool operator==(const char) const;

    token_type type() const;

  protected:
    token_type type_;
  };

  class ValueToken : public Token
  {
  public:
    ValueToken(token_type t, misc::Location& location, const std::string& val)
      : Token(t, location)
      , val_(val)
    {}

    virtual bool operator==(const std::string&) const override;
    virtual bool operator==(const char) const override;

    const std::string& val_get() const;

  private:
    const std::string val_;
  };

  const std::string tok_repr(const Token&);

} // namespace lexer
