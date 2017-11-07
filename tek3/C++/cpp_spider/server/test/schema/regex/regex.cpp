/*
** regex.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/test/regex/regex.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Oct 02 22:09:46 2017 Gauthier Cler
** Last update Mon Oct 02 22:09:46 2017 Gauthier Cler
*/

#include <gtest/gtest.h>
#include "Model.hpp"
#include "schema/schema.hpp"

#define TEST_SUITE (_PREFIX + std::string("regex/"))

TEST(RegexTest, valid) {
  ASSERT_EQ(generateSchemaTest(
    TEST_SUITE + "schemas/default.json",
    TEST_SUITE + "models/valid.json"),
	    true);
}

TEST(RegexTest, invalid) {
  ASSERT_EQ(generateSchemaTest(
    TEST_SUITE + "schemas/default.json",
    TEST_SUITE + "models/invalid.json"),
	    false);
}
