/* A Bison parser, made by GNU Bison 2.3b.655-27c2.  */

/* Positions for Bison parsers in C++

   Copyright (C) 2002-2011 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/**
 ** \file position.hh
 ** Define the yy::position class.
 */

#ifndef BISON_POSITION_HH
# define BISON_POSITION_HH

# include <iostream>
# include <string>
# include <algorithm>


namespace yy {
/* Line 39 of location.cc  */
#line 49 "/home/bearclaw/aldebaran/qi-2/urbi/kernel/build-linux32/src/parser/position.hh"
  /// Abstract a position.
  class position
  {
  public:

    /// Construct a position.
    explicit position (libport::Symbol* f = 0,
                       unsigned int l = 1u,
                       unsigned int c = 1u)
      : filename (f)
      , line (l)
      , column (c)
    {
    }


    /// Initialization.
    inline void initialize (libport::Symbol* fn)
    {
      filename = fn;
      line = 1u;
      column = 1u;
    }

    /** \name Line and Column related manipulators
     ** \{ */
    /// (line related) Advance to the COUNT next lines.
    /// Set current column to initial value.
    inline void lines (int count = 1)
    {
      column = 1u;
      line += count;
    }

    /// (column related) Advance to the COUNT next columns.
    inline void columns (int count = 1)
    {
      column = std::max (1u, column + count);
    }
    /** \} */

    /// File name to which this position refers.
    libport::Symbol* filename;
    /// Current line number.
    unsigned int line;
    /// Current column number.
    unsigned int column;
  };

  /// Add and assign a position.
  inline const position&
  operator+= (position& res, const int width)
  {
    res.columns (width);
    return res;
  }

  /// Add two position objects.
  inline const position
  operator+ (const position& begin, const int width)
  {
    position res = begin;
    return res += width;
  }

  /// Add and assign a position.
  inline const position&
  operator-= (position& res, const int width)
  {
    return res += -width;
  }

  /// Add two position objects.
  inline const position
  operator- (const position& begin, const int width)
  {
    return begin + -width;
  }

  /** \brief Intercept output stream redirection.
   ** \param ostr the destination output stream
   ** \param pos a reference to the position to redirect
   */
  inline std::ostream&
  operator<< (std::ostream& ostr, const position& pos)
  {
    if (pos.filename)
      ostr << *pos.filename << ':';
    return ostr << pos.line << '.' << pos.column;
  }


} // yy
/* Line 149 of location.cc  */
#line 144 "/home/bearclaw/aldebaran/qi-2/urbi/kernel/build-linux32/src/parser/position.hh"
#endif // not BISON_POSITION_HH