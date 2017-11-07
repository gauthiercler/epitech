/*
** string.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/test/string/string.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Oct 02 22:16:06 2017 Gauthier Cler
** Last update Mon Oct 02 22:16:06 2017 Gauthier Cler
*/

#include <gtest/gtest.h>
#include "Model.hpp"
#include "schema/schema.hpp"

#define TEST_SUITE (_PREFIX + std::string("string/"))

TEST(StringTest, valid) {
  ASSERT_EQ(generateSchemaTest(
    TEST_SUITE + "schemas/default.json",
    TEST_SUITE + "models/valid.json"),
	    true);
}

TEST(StringTest, empty) {
  ASSERT_EQ(generateSchemaTest(
    TEST_SUITE + "schemas/default.json",
    TEST_SUITE + "models/empty.json"),
	    false);
}
