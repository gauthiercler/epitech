#include	<gtest/gtest.h>
#include <sources/classes/components/True.hpp>

TEST(TRUE_Component, Constructor) {
  nts::IComponent	*TrueI = new True();
  nts::AComponent	*TrueA = static_cast<nts::AComponent *>(TrueI);

  ASSERT_EQ("TRUE", TrueA->getName());
  ASSERT_EQ(1, TrueA->getNbPins());
  ASSERT_EQ(Pin::OUTPUT, TrueA->getPinAt(1)->getType());
  ASSERT_EQ(nts::Tristate::TRUE, TrueA->getPinAt(1)->getValue());
}

TEST(TRUE_Component, Compute) {
  nts::IComponent	*TrueI = new True();

  ASSERT_EQ(nts::Tristate::TRUE, TrueI->Compute(1));
}