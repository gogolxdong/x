// 1999-04-12 bkoz

// Copyright (C) 1999-2020 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

// 27.6.1.2.2 arithmetic extractors

#include <istream>
#include <sstream>
#include <locale>
#include <testsuite_hooks.h>

void test10()
{
  std::string str_01("0 00 000 +0 +0 -0");
  std::stringbuf isbuf_01(str_01);
  std::istream is_01(&isbuf_01);

  int n = 365;
  is_01 >> n;
  VERIFY( n == 0 );
  n = 364;
  is_01 >> n;
  VERIFY( n == 0 );
  n = 363;
  is_01 >> n;
  VERIFY( n == 0 );
  n = 362;
  is_01 >> n;
  VERIFY( n == 0 );
  n = 361;
  is_01 >> n;
  VERIFY( n == 0 );
  n = 360;
  is_01 >> n;
  VERIFY( n == 0 );
  VERIFY( is_01.rdstate() == std::ios_base::eofbit );

  std::string str_02("0x32 0X33 033 33");
  std::stringbuf isbuf_02(str_02);
  std::istream is_02(&isbuf_02);
  is_02.unsetf(std::ios_base::basefield);
  is_02 >> n;
  VERIFY( n == 50 );
  is_02 >> n;
  VERIFY( n == 51 );
  is_02 >> n;
  VERIFY( n == 27 );
  is_02 >> n;
  VERIFY( n == 33 );
  VERIFY( is_02.rdstate() == std::ios_base::eofbit );

  std::stringbuf isbuf_03(str_02);
  std::istream is_03(&isbuf_03);
  char c;
  int m;

  is_03 >> std::dec >> n >> c >> m;
  VERIFY( n == 0 );
  VERIFY( c == 'x' );
  VERIFY( m == 32 );

  is_03 >> std::oct >> m >> c >> n;
  VERIFY( m == 0 );
  VERIFY( c == 'X' );
  VERIFY( n == 27 );

  is_03 >> std::dec >> m >> n;
  VERIFY( m == 33 );
  VERIFY( n == 33 );
  VERIFY( is_03.rdstate() == std::ios_base::eofbit );

  std::string str_04("3. 4.5E+2a5E-3 .6E1");
  std::stringbuf isbuf_04(str_04);
  std::istream is_04(&isbuf_04);

  double f;
  is_04 >> f;
  VERIFY( f == 3.0 );
  is_04 >> f;
  VERIFY( f == 450.0 );
  is_04.ignore();
  is_04 >> f;
  VERIFY( f == 0.005 );
  is_04 >> f;
  VERIFY( f == 6 );
  VERIFY( is_03.rdstate() == std::ios_base::eofbit );

  std::string str_05("0E20 5Ea E16");
  std::stringbuf isbuf_05(str_05);
  std::istream is_05(&isbuf_05);

  is_05 >> f;
  VERIFY( f == 0 );
  f = 1;
  is_05 >> f;
  VERIFY( f == 0 );
  VERIFY( is_05.rdstate() == std::ios_base::failbit );
  is_05.clear();
  is_05 >> c;
  VERIFY( c == 'a' );
  f = 1;
  is_05 >> f;
  VERIFY( f == 0 );
  VERIFY( is_05.rdstate() == std::ios_base::failbit );
  is_05.clear();
  is_05.ignore();
  is_05 >> n;
  VERIFY( n == 16 );
}

int main()
{
  test10();
  return 0;
}
