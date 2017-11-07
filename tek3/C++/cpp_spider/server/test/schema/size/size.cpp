/*
** size.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/test/schema/size/size.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:46:13 2017 Gauthier Cler
** Last update Sun Oct 08 19:46:13 2017 Gauthier Cler
*/

#include <gtest/gtest.h>
#include "Model.hpp"
#include "schema/schema.hpp"

#define TEST_SUITE (_PREFIX + std::string("size/"))

TEST(SizeTest, more) {
  ASSERT_EQ(generateSchemaTest(
    TEST_SUITE + "schemas/default.json",
    TEST_SUITE + "models/more.json"),
	    false);
}

TEST(SizeTest, less) {
  ASSERT_EQ(generateSchemaTest(
    TEST_SUITE + "schemas/default.json",
    TEST_SUITE + "models/less.json"),
	    false);
}

TEST(SizeTest, valid) {
  ASSERT_EQ(generateSchemaTest(
    TEST_SUITE + "schemas/default.json",
    TEST_SUITE + "models/valid.json"),
	    true);
}

TEST(SizeTest, complex_more) {
  ASSERT_EQ(generateSchemaTest(
    TEST_SUITE + "schemas/complex.json",
    TEST_SUITE + "models/complexmore.json"),
	    false);
}

TEST(SizeTest, complex_less) {
  ASSERT_EQ(generateSchemaTest(
    TEST_SUITE + "schemas/complex.json",
    TEST_SUITE + "models/complexless.json"),
	    false);
}

TEST(SizeTest, complex_valid) {
  ASSERT_EQ(generateSchemaTest(
    TEST_SUITE + "schemas/complex.json",
    TEST_SUITE + "models/complexvalid.json"),
	    true);
}

