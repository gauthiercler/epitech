#include	<gtest/gtest.h>
#include	<sources/classes/components/OUTPUT.hpp>

TEST(OUTPUT_Component, Constructor) {
  nts::IComponent	*OutputI = new OUTPUT();
  nts::AComponent	*OutputA = static_cast<nts::AComponent *>(OutputI);

  ASSERT_EQ("OUTPUT", OutputA->getName());
  ASSERT_EQ(1, OutputA->getNbPins());
  ASSERT_EQ((int) Pin::PinType::INPUT, OutputA->getPinAt(1)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, OutputA->getPinAt(1)->getValue());
}

TEST(OUTPUT_Component, Compute) {
  nts::IComponent	*OutputI = new OUTPUT();

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, OutputI->Compute(1));
}
