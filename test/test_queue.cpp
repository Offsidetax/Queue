#include "queue.h"
#include <gtest.h>

TEST(Queue, can_create_queue)
{
	ASSERT_NO_THROW(Queue<int> s);
}


TEST(Queue, can_create_copied_queue)
{
    Queue<int> s1;

	ASSERT_NO_THROW(Queue<int> s2(s1));
}

TEST(Queue, equal_queue_are_equal)
{
    Queue<int> s1;
    Queue<int> s2;
    s1.Push(1); s2.Push(1);
    s1.Push(1); s2.Push(1);

    ASSERT_EQ(s1==s2,1);
}

TEST(Queue, not_equal_queues_are_not_equal)
{
    Queue<int> s1;
    Queue<int> s2;
    s1.Push(1); s2.Push(2);
    s1.Push(1); s2.Push(2);

    ASSERT_EQ(s1!=s2, 1);
}

TEST(Queue, copied_queue_is_equal_to_source_one)
{
    Queue<int> s1;

    Queue<int> s2(s1);

    EXPECT_EQ(s1==s2, 1);
}

TEST(Queue, can_get_size)
{
    Queue<int> s;
    s.Push(1);
    s.Push(1);
    s.Push(1);
    s.Push(1);

    EXPECT_EQ(4, s.size());
}

TEST(Queue, can_check_if_queue_is_empty)
{
    Queue<int> s;

    EXPECT_EQ(1, s.IsEmpty());
}

TEST(Queue, can_push_element_in_queue)
{
    Queue<int> s;

    ASSERT_NO_THROW(s.Push(1));
}

TEST(Queue, can_pop_element_from_non_empty_queue)
{
    Queue<int> s;
    s.Push(1);

    ASSERT_NO_THROW(s.Pop());
}

TEST(Queue, cant_pop_element_from_empty_queue)
{
    Queue<int> s;

    ASSERT_ANY_THROW(s.Pop());
}

TEST(Queue, can_get_top_element_from_non_empty_queue)
{
    Queue<int> s;
    s.Push(1);
    s.Push(2);

    ASSERT_NO_THROW(s.Pop(),2);
}

TEST(Queue, can_get_top_element_from_queue)
{
    Queue<int> s;

    ASSERT_ANY_THROW(s.Pop());
}

TEST(Queue, some_push_and_pop_operations_in_random_order)
{
    Queue<int> s;
    Queue<int> s1;
    s1.Push(6);
    
    s.Push(1);
    s.Pop();
    s.Push(2);
    s.Push(3);
    s.Pop();
    s.Push(4);
    s.Pop();
    s.Pop();
    s.Push(5);
    s.Push(6);
    s.Pop();

    EXPECT_EQ(s1==s, 1);
}