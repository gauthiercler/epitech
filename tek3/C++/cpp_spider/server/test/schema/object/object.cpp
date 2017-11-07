/*
** object.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/test/object/object.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Oct 02 22:19:27 2017 Gauthier Cler
** Last update Mon Oct 02 22:19:27 2017 Gauthier Cler
*/

#include <gtest/gtest.h>
#include "Model.hpp"
#include "schema/schema.hpp"

#define TEST_SUITE (_PREFIX + std::string("object/"))

TEST(ObjectTest, valid) {
  ASSERT_EQ(generateSchemaTest(
    TEST_SUITE + "schemas/default.json",
    TEST_SUITE + "models/valid.json"),
	    true);
}

TEST(ObjectTest, empty) {
  ASSERT_EQ(generateSchemaTest(
    TEST_SUITE + "schemas/default.json",
    TEST_SUITE + "models/empty.json"),
	    false);
}

TEST(ObjectTest, recursive) {
  ASSERT_EQ(generateSchemaTest(
    TEST_SUITE + "schemas/recursive.json",
    TEST_SUITE + "models/recursive.json"
  ), true);
}

TEST(ObjectTest, noitem) {
  ASSERT_EQ(generateSchemaTest(
    TEST_SUITE + "schemas/noitems.json",
    TEST_SUITE + "models/valid.json"
  ), false);
}