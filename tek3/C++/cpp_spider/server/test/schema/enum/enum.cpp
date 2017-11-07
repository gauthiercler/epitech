/*
** enum.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/test/enum/enum.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Oct 02 21:55:25 2017 Gauthier Cler
** Last update Mon Oct 02 21:55:26 2017 Gauthier Cler
*/

#include <gtest/gtest.h>
#include "Model.hpp"
#include "schema/schema.hpp"

#define TEST_SUITE (_PREFIX + std::string("enum/"))

TEST(EnumTest, valid) {
  ASSERT_EQ(generateSchemaTest(
    TEST_SUITE + "schemas/default.json",
    TEST_SUITE + "models/valid.json"),
	    true);
}

TEST(EnumTest, invalid) {
  ASSERT_EQ(generateSchemaTest(
    TEST_SUITE + "schemas/default.json",
    TEST_SUITE + "models/invalid.json"),
	    false);
}

TEST(EnumTest, emptyModel) {
  ASSERT_EQ(generateSchemaTest(
    TEST_SUITE + "schemas/empty.json",
    TEST_SUITE + "models/valid.json"),
	    false);
}