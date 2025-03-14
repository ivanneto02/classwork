// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.



// First part of user prologue.
#line 4 "katchup.parser.y"

	#include <iostream>
	#include <stdio.h>
	#include <string.h>

	char* mycont(char* a, char* b);
	int yylex(void);
	int yyerror(char* s);
	typedef struct yy_buffer_state *YY_BUFFER_STATE;
	void yy_switch_to_buffer(struct yy_buffer_state *new_buffer);
	struct yy_buffer_state* yy_create_buffer( FILE *file, int size );
	#define yyterminate() return END
	
	struct CodeNode {
		std::string code;
		std::string name;
	};

	// Each array holds a symbol
	struct CodeNode symbolhash[1000000000][32];

#line 62 "y.tab.cc"


#include "y.tab.hh"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 139 "y.tab.cc"


  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value (std::move (that.value))
  {}
#endif

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v)
    : Base (t)
    , value (YY_MOVE (v))
  {}

  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
  }

  // by_type.
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value))
  {
    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 45:
#line 164 "katchup.parser.y"
                {

	CodeNode* newNode = new CodeNode;
	newNode->code = "";
	newNode->name = (yystack_[0].value.str);

	char* error = "Semantic error.";

	if (!symbolhash.find(newNode)) {
		yyerror(error);
	}

	(yylhs.value.str) = newNode;
}
#line 589 "y.tab.cc"
    break;

  case 46:
#line 178 "katchup.parser.y"
                                                     {

}
#line 597 "y.tab.cc"
    break;

  case 57:
#line 200 "katchup.parser.y"
{

}
#line 605 "y.tab.cc"
    break;


#line 609 "y.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -75;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     142,   -75,   -75,   -75,   -75,   -36,   -35,   -25,   -18,   -16,
     -22,   -75,   -75,   -75,   -75,    28,   -30,   -75,    63,   -75,
     -75,   -23,    35,   142,   -75,   -75,   -75,     2,     4,   105,
      -1,     1,   -75,    -5,   142,     5,    16,   -75,     3,    63,
      63,   142,   -75,    28,   -75,    17,    21,   -75,   -75,    63,
      28,    18,    28,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,    63,   -75,   -75,   -75,   -75,
     -21,    28,    63,   -75,   -75,   -34,    53,    19,    22,    52,
      25,   -75,    30,    38,    26,   -75,    31,   -75,   -75,   -75,
      36,    54,   -75,    45,    48,    42,    51,    55,    59,   -75,
     -75,    28,   -75,    58,   -75,   -38,    56,    64,    66,    67,
      53,   142,   142,    63,   -75,    72,    28,   -75,   -75,    28,
     142,   -75,    99,   103,    70,    73,    71,   -75,   114,   -31,
     112,    84,    85,    28,   -75,    86,   142,    63,    89,   -75,
     -75,    94,    93,   -75,   -75,   106,   -75,    28,   -75,   111,
     -75,   142,    99,   -75
  };

  const signed char
  parser::yydefact_[] =
  {
       2,    62,    63,    64,    65,     0,     0,     0,     0,     0,
       0,    55,    56,    53,    54,     0,    45,    42,     0,    71,
      70,     0,     0,     2,     5,     6,     7,     0,     0,    31,
      34,    41,    43,     0,     2,     0,     0,    12,     0,     0,
       0,     2,    16,     0,    19,    45,     0,    18,    41,     0,
       0,     0,     0,     1,     3,    14,     8,    36,    35,    47,
      52,    50,    51,    48,    49,     0,    37,    38,    39,    40,
       0,     0,     0,     4,    13,     0,     0,     0,     0,     0,
       0,    17,     0,    61,     0,    44,     0,    30,    33,    11,
       0,     0,    10,     0,     0,    67,     0,     0,     0,    59,
      46,     0,    58,     0,    32,    45,     0,     0,    68,     0,
       0,     2,     2,     0,    60,     0,     0,     9,    15,     0,
       2,    66,    23,     0,     0,     0,     0,    69,     0,     0,
       0,     0,     0,     0,    29,     0,     2,     0,     0,    24,
      25,    28,     0,    57,    22,     0,    20,     0,    26,     0,
      27,     2,    23,    21
  };

  const signed char
  parser::yypgoto_[] =
  {
     -75,   -20,   -75,   -14,   -75,     6,   -75,   -75,   -75,     9,
     -75,     0,    87,   -75,   -75,   -75,    10,   -75,   -75,   -75,
     -75,   -75,    61,   -74,    62,   -75,   -75
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,    22,    23,    83,    24,   130,    25,    26,    27,   142,
     107,    47,    29,    65,    70,    30,    48,    66,    32,    33,
      34,    35,    84,    36,    94,    95,    37
  };

  const unsigned char
  parser::yytable_[] =
  {
      28,    46,    93,    54,    38,    13,    14,    49,    91,    92,
      31,   136,    39,   116,    73,    49,   137,    50,    51,    45,
      17,    79,    40,    28,    41,    43,    18,    42,    52,    80,
      67,    68,    69,    31,    28,    53,    93,    44,    86,    77,
      78,    28,    72,    71,    31,    55,    75,    56,    74,    82,
      76,    31,    11,    12,    13,    14,    45,    89,     1,     2,
       3,     4,    49,    44,    81,    87,    85,    96,    45,    17,
      97,    98,    90,    99,   102,    18,   100,   106,    11,    12,
      13,    14,   101,   103,   104,   108,   110,    11,    12,    13,
      14,   122,   123,   111,   105,    17,   109,   112,   115,   117,
     128,    18,   126,    45,    17,   127,   113,   118,   119,   120,
      18,    28,    28,   124,   125,   129,   144,   131,   132,   141,
      28,    31,    31,   134,   133,   135,   138,   139,   140,   143,
      31,   152,   146,   141,    57,    58,    28,   145,   147,    59,
      60,    61,    62,    63,    64,   148,    31,     1,     2,     3,
       4,    28,     5,   151,   149,     6,   150,    88,   153,     7,
       8,    31,   114,     9,     0,    10,    11,    12,    13,    14,
      15,     0,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,    17,     0,     0,     0,     0,     0,    18,
       0,    19,    20,     0,     0,    21
  };

  const short
  parser::yycheck_[] =
  {
       0,    15,    76,    23,    40,    26,    27,    45,    42,    43,
       0,    42,    47,    51,    34,    45,    47,    47,    18,    40,
      41,    41,    47,    23,    42,    47,    47,    43,    51,    43,
      31,    32,    33,    23,    34,     0,   110,     9,    52,    39,
      40,    41,    47,    42,    34,    43,    36,    43,    43,    49,
      47,    41,    24,    25,    26,    27,    40,    71,     5,     6,
       7,     8,    45,     9,    43,    65,    48,    48,    40,    41,
      48,    19,    72,    48,    48,    47,    46,    91,    24,    25,
      26,    27,    44,    52,    48,    40,    44,    24,    25,    26,
      27,   111,   112,    42,    40,    41,    48,    42,    40,    43,
     120,    47,   116,    40,    41,   119,    47,    43,    42,    42,
      47,   111,   112,   113,    42,    16,   136,    14,    48,   133,
     120,   111,   112,    52,    51,    11,    14,    43,    43,    43,
     120,   151,    43,   147,    29,    30,   136,   137,    44,    34,
      35,    36,    37,    38,    39,    52,   136,     5,     6,     7,
       8,   151,    10,    42,    48,    13,   147,    70,   152,    17,
      18,   151,   101,    21,    -1,    23,    24,    25,    26,    27,
      28,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    49,    50,    -1,    -1,    53
  };

  const signed char
  parser::yystos_[] =
  {
       0,     5,     6,     7,     8,    10,    13,    17,    18,    21,
      23,    24,    25,    26,    27,    28,    40,    41,    47,    49,
      50,    53,    55,    56,    58,    60,    61,    62,    65,    66,
      69,    70,    72,    73,    74,    75,    77,    80,    40,    47,
      47,    42,    43,    47,     9,    40,    57,    65,    70,    45,
      47,    65,    51,     0,    55,    43,    43,    29,    30,    34,
      35,    36,    37,    38,    39,    67,    71,    31,    32,    33,
      68,    42,    47,    55,    43,    70,    47,    65,    65,    55,
      57,    43,    65,    57,    76,    48,    57,    65,    66,    57,
      65,    42,    43,    77,    78,    79,    48,    48,    19,    48,
      46,    44,    48,    52,    48,    40,    57,    64,    40,    48,
      44,    42,    42,    47,    76,    40,    51,    43,    43,    42,
      42,    78,    55,    55,    65,    42,    57,    57,    55,    16,
      59,    14,    48,    51,    52,    11,    42,    47,    14,    43,
      43,    57,    63,    43,    55,    65,    43,    44,    52,    48,
      63,    42,    55,    59
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    54,    55,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      58,    59,    59,    59,    60,    61,    62,    63,    63,    64,
      65,    65,    65,    66,    66,    67,    67,    67,    68,    68,
      68,    69,    69,    69,    69,    70,    70,    71,    71,    71,
      71,    71,    71,    72,    72,    73,    73,    74,    75,    75,
      76,    76,    77,    77,    77,    77,    78,    78,    79,    79,
      80,    80
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     1,     1,     1,     2,     5,
       3,     3,     1,     2,     2,     5,     2,     3,     1,     1,
       9,     7,     3,     0,     8,     8,     9,     3,     1,     4,
       3,     1,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     9,     4,     4,
       3,     1,     1,     1,     1,     1,     3,     1,     2,     4,
       1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "END", "DIGIT", "INTEGER",
  "UNSIGNED_INTEGER", "FLOATING_POINT_NUMBER", "STRING", "STRING_LITERAL",
  "FUNCTION", "ENDFUN", "OF", "IF", "TAIL", "IFOTHER", "OTHER", "WHILE",
  "EXEC", "WHEN", "CONTINUE", "SCRATCH", "POUNCE", "MEOW", "NOT",
  "NOT_SYMBOL", "TRUE", "FALSE", "SWAT", "SUB", "ADD", "MULT", "DIV",
  "MOD", "EQUAL", "NEQ", "LT", "GT", "LTE", "GTE", "IDENT", "NUMBER",
  "COLON", "SEMICOLON", "COMMA", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET",
  "L_PAREN", "R_PAREN", "MULTI_LINE_COMMENT", "INLINE_COMMENT",
  "L_CURLY_BRACKET", "R_CURLY_BRACKET", "ARR", "$accept", "program",
  "statement", "literal", "if-statement", "if-other-statements",
  "while-statement", "exec-when-statement", "array-dec", "array-args",
  "array-call", "expression", "mulexp", "addit-op", "mulop", "term",
  "variable", "comp", "bool", "not", "function", "func-call", "func-args",
  "data-type", "func-params", "declaration", "comment", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    91,    91,    92,    93,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   111,   112,
     115,   118,   119,   120,   123,   126,   129,   132,   133,   136,
     139,   140,   141,   144,   145,   148,   149,   150,   153,   154,
     155,   158,   159,   160,   161,   164,   178,   183,   184,   185,
     186,   187,   188,   191,   192,   195,   196,   199,   205,   206,
     209,   210,   213,   214,   215,   216,   219,   220,   223,   224,
     227,   228
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
    };
    const int user_token_number_max_ = 308;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

} // yy
#line 1063 "y.tab.cc"

#line 231 "katchup.parser.y"


string mycont(std::string a, std::string b){
	strcat(a,b);
	return a;
}

void readFromFile(std::string);

int main(int argc, char **argv)
{
	if (argc > 1) {
		std::string fileName = argv[1];

		printf("Reading from file: \"%s\"\n\n", fileName);

		// call defined function
		readFromFile(fileName);

	} 

	printf("START OF PARSING\n");
	yyparse();
	printf("FINISHED!\n");
	

	return 0;
}     

void readFromFile(std::string inputFile) {

	FILE *fp; // File object
	fp = fopen(inputFile, "r+");
	printf("\"%s\" opened\n", inputFile);
	
	yy_switch_to_buffer(
        yy_create_buffer(fp, 255)
    );
	
}
