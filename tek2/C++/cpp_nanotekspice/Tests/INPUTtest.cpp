#include	<gtest/gtest.h>
#include	<sources/classes/components/INPUT.hpp>

TEST(INPUT_Component, Constructor) {
  nts::IComponent	*InputI = new INPUT();
  nts::AComponent	*InputA = static_cast<nts::AComponent *>(InputI);

  ASSERT_EQ("INPUT", InputA->getName());
  ASSERT_EQ(1, InputA->getNbPins());
  ASSERT_EQ((int) Pin::PinType::OUTPUT, InputA->getPinAt(1)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, InputA->getPinAt(1)->getValue());
}

TEST(INPUT_Component, ValueSetter) {
  nts::IComponent	*InputI = new INPUT();
  nts::AComponent	*InputA = static_cast<nts::AComponent *>(InputI);

  InputA->getPinAt(1)->setValue(nts::Tristate::TRUE);
  ASSERT_EQ((int) nts::Tristate::TRUE, InputA->getPinAt(1)->getValue());
  InputA->getPinAt(1)->setValue(nts::Tristate::FALSE);
  ASSERT_EQ((int) nts::Tristate::FALSE, InputA->getPinAt(1)->getValue());
  InputA->getPinAt(1)->setValue(nts::Tristate::UNDEFINED);
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, InputA->getPinAt(1)->getValue());
}

TEST(INPUT_Component, Compute) {
  nts::IComponent	*InputI = new INPUT();

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, InputI->Compute(1));
}
