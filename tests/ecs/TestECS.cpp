/*
** EPITECH PROJECT, 2023
** TestECS.cpp
** File description:
** TestECS.cpp
*/

#include <gtest/gtest.h>
#include <spdlog/spdlog.h>

#include <boost/array.hpp>

TEST(ECS, TestECS)
{
    const auto expected = 1;
    const auto actual = 1;
    ASSERT_EQ(expected, actual);
}
