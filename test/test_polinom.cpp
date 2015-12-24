#include <gtest.h>
#include "node.h"
#include "list.h"
#include "polinom.h"
#include "monom.h"

TEST(list, can_create_list)
{
	ASSERT_NO_THROW(list<int> _list);
}

TEST(list, can_write_list)
{
	list<string> number;

	ASSERT_NO_THROW(number.writelist());
}

TEST(list, can_add_elem)
{
	list<string> str;

	str.add("A");
	str.writelist();

	ASSERT_NO_THROW(str.add("a"););
}

TEST(list, can_get_head)
{
	list<int> _list;
	_list.add(1);
	_list.add(3);
	EXPECT_EQ(_list.getheaddata(),3);
}

TEST(list, can_add_sort_elem)
{
	list<int> _list;
	_list.add(1);
	_list.add(4);
	_list.add(2);
	_list.add(3);
	_list.add(6);
	_list.add(5);
	_list.writelist();
	EXPECT_EQ(_list.getheaddata(),6);
}

TEST(list, can_del_first)
{
	list<int> _list;
	_list.add(1);
	_list.delfirst();
	_list.writelist();
	EXPECT_EQ(_list.getheaddata(),0);
}

TEST(list, can_del_list)
{
	list<int> _list;
	_list.add(1);
	_list.add(3);
	_list.add(2);
	_list.dellist();
	_list.add(0);
	_list.writelist();
	EXPECT_EQ(_list.getheaddata(),0);
}

// тесты мономов и полиномов

TEST(polinom, can_create_monom)
{
	ASSERT_NO_THROW(monom _monom);
}

TEST(polinom, can_create_node_monom)
{
	ASSERT_NO_THROW(node<monom> _node);
}

TEST(polinom, can_create_list_monom)
{
	ASSERT_NO_THROW(list<monom> _list);
}

TEST(polinom, can_create_polinom)
{
	ASSERT_NO_THROW(polinom _pol);
}

TEST(polinom, can_create_copy_polinom)
{
	polinom _pol;
	ASSERT_NO_THROW(polinom _polcopy(_pol));
}

TEST(polinom, can_add_head)
{
	polinom _pol;
	_pol.add(1,1);
	_pol.writelist();
	ASSERT_NO_THROW(_pol.add(2,2));
}

TEST(polinom,can_add_more_monoms)
{
	polinom _pol;
	_pol.add(1,3);
	_pol.add(1,1);
	_pol.add(1,2);
	_pol.add(1,1);
	_pol.add(1,3);
	_pol.add(1,2);
	_pol.add(1,3);

	_pol.writelist();
	ASSERT_NO_THROW(_pol.add(2,2));
}

TEST(polinom,can_simplify)
{
	polinom _pol;
	_pol.add(1,1);
	_pol.add(1,2);
	_pol.add(1,1);
	_pol.add(1,2);
	_pol.add(0,3);
	_pol.simplify();
	_pol.writelist();
}

TEST(polinom,can_expect)
{
	polinom _pol;
	_pol.add(1,1);
	_pol.add(1,2);
	_pol.add(1,1);
	_pol.add(1,2);
	polinom _pol1;
	_pol1 = _pol;
	_pol1.writelist();
}

TEST(polinom,can_multiply_on_const)
{
	polinom _pol;
	_pol.add(1,1);
	_pol.add(1,2);
	_pol.add(1,1);
	polinom _pol1;
	_pol1 = _pol * 2;
	_pol1.writelist();
}

TEST(polinom,can_multiply_on_polinom)
{
	polinom _pol;
	_pol.add(1,1);
	_pol.add(1,2);
	_pol.add(1,1);
	polinom _pol1;
	_pol1 = _pol * _pol;
	_pol1.writelist();
}

TEST(polinom,can_addition_polinom)
{
	polinom _pol;
	_pol.add(1,1);
	_pol.add(1,2);
	_pol.add(1,1);
	polinom _pol1;
	_pol1 = _pol + _pol;
	_pol1.writelist();
}

TEST(polinom,can_deduct_polinom)
{
	polinom _pol;
	_pol.add(1,1);
	_pol.add(1,2);
	_pol.add(1,1);
	polinom _pol1;
	_pol1.add(1,2);
	_pol1.add(1,1);
	polinom _pol2;
	_pol2 = _pol1 - _pol;
	_pol2.writelist();
}