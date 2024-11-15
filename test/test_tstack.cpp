#include "tstack.h"

#include <gtest.h>

TEST(tStack, can_create_stack_not_parametr)
{
	ASSERT_NO_THROW(Stack<int> s);
}

TEST(tStack, can_create_stack_with_one_parametr)
{
	ASSERT_NO_THROW(Stack<int> s(2));
}

TEST(tStack, can_create_stack_with_two_parametr)
{
	ASSERT_NO_THROW(Stack<int> s(2, 0));
}

TEST(tStack, can_create_stack_negative_size)
{
	ASSERT_ANY_THROW(Stack<int> s(-2, 0));
}


TEST(tStack, test_operator_ravno_equal_length)
{
	Stack<int> s(1, 0);
	Stack<int> s1(2, 0);

	s.push(3);

	s1 = s;

	EXPECT_EQ(s, s1);
}

TEST(tStack, test_operator_ravno_different_length)
{
	Stack<int> s(2, 0);
	Stack<int> s1(2, 0);

	s.push(3);

	s1 = s;

	EXPECT_EQ(s, s1);
}

TEST(tStack, test_operator_ravno_equal_list)
{
	Stack<int> s(1, 0);
	Stack<int> s1(1, 0);

	s.push(3);
	s1.push(3);

	s1 = s;

	EXPECT_EQ(s, s1);
}

TEST(tStack, test_operator_ravno_different_memory)
{
	Stack<int> s(1, 0);
	Stack<int> s1(2, 0);

	s.push(3);

	s1 = s;
	
	s1.change(2);

	EXPECT_EQ(3, s.top());
	EXPECT_EQ(2, s1.top());
}

TEST(tStack, test_push_data)
{
	Stack<int> s(1, 0);

	s.push(3);

	EXPECT_EQ(3, s.top());
}

TEST(tStack, test_push_top)
{
	Stack<int> s(1, 0);

	s.push(3);

	EXPECT_EQ(2, s.size());
}

TEST(tStack, test_pop_data)
{
	Stack<int> s(1, 0);

	s.push(1);
	s.pop();

	EXPECT_EQ(0, s.top());
}

TEST(tStack, test_pop_top)
{
	Stack<int> s(2, 0);

	s.pop();

	EXPECT_EQ(1, s.size());
}

TEST(tStack, test_pop_empty)
{
	Stack<int> s;
	
	ASSERT_ANY_THROW(s.pop());
}

TEST(tStack, test_top)
{
	Stack<int> s(2, 0);

	s.push(2);

	EXPECT_EQ(2, s.top());
}

TEST(tStack, test_top_empty)
{
	Stack<int> s;

	ASSERT_ANY_THROW(s.top());
}

TEST(tStack, test_empty)
{
	Stack<int> s;

	EXPECT_EQ(true, s.empty());
}

TEST(tStack, test_not_empty)
{
	Stack<int> s(1);

	EXPECT_EQ(false, s.empty());
}

TEST(tStack, test_size)
{
	Stack<int> s(10);

	EXPECT_EQ(10, s.size());
}

TEST(tStack, test_null_size)
{
	Stack<int> s;

	EXPECT_EQ(0, s.size());
}

TEST(tStack, test_push_pop)
{
	Stack<int> s(2, 0);

	s.push(1);
	s.pop();
	s.push(1);
	s.push(2);
	s.push(3);
	s.pop();
	s.push(1);
	s.pop();
	s.pop();

	EXPECT_EQ(1, s.top());
}
