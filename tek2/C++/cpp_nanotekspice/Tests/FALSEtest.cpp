#include	<gtest/gtest.h>
#include <sources/classes/components/False.hpp>

TEST(FALSE_Component, Constructor) {
  nts::IComponent	*FalseI = new False();
  nts::AComponent	*FalseA = static_cast<nts::AComponent *>(FalseI);

  ASSERT_EQ("FALSE", FalseA->getName());
  ASSERT_EQ(1, FalseA->getNbPins());
  ASSERT_EQ(Pin::OUTPUT, FalseA->getPinAt(1)->getType());
  ASSERT_EQ(nts::Tristate::FALSE, FalseA->getPinAt(1)->getValue());
}

TEST(FALSE_Component, Compute) {
  nts::IComponent	*FalseI = new False();

  ASSERT_EQ(nts::Tristate::FALSE, FalseI->Compute(1));
}