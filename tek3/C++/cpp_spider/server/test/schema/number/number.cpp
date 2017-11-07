/*
** number.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/test/number/number.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Oct 02 22:06:37 2017 Gauthier Cler
** Last update Mon Oct 02 22:06:37 2017 Gauthier Cler
*/

#include <gtest/gtest.h>
#include "Model.hpp"
#include "schema/schema.hpp"

#define TEST_SUITE (_PREFIX + std::string("number/"))

TEST(NumberTest, valid) {
  ASSERT_EQ(generateSchemaTest(
    TEST_SUITE + "schemas/default.json",
    TEST_SUITE + "models/valid.json"),
	    true);
}

TEST(NumberTest, negative) {
  ASSERT_EQ(generateSchemaTest(
    TEST_SUITE + "schemas/default.json",
    TEST_SUITE + "models/negative.json"),
	    false);
}

TEST(NumberTest, nonNumeric) {
  ASSERT_EQ(generateSchemaTest(
    TEST_SUITE + "schemas/default.json",
    TEST_SUITE + "models/nonNumeric.json"),
	    false);
}