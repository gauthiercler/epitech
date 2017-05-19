#include	<gtest/gtest.h>
#include	<sources/classes/components/gates/OR.hpp>
#include <sources/classes/components/True.hpp>
#include <sources/classes/components/False.hpp>
#include	<sources/classes/components/INPUT.hpp>

TEST(ORComponent, Constructor) {
  nts::IComponent	*ORI = new OR();
  nts::AComponent	*ORA = static_cast<nts::AComponent *>(ORI);

  ASSERT_EQ("OR", ORA->getName());
  ASSERT_EQ(3, ORA->getNbPins());

  ASSERT_EQ((int) Pin::PinType::INPUT, ORA->getPinAt(1)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, ORA->getPinAt(1)->getValue());

  ASSERT_EQ((int) Pin::PinType::INPUT, ORA->getPinAt(2)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, ORA->getPinAt(2)->getValue());

  ASSERT_EQ((int) Pin::PinType::OUTPUT, ORA->getPinAt(3)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, ORA->getPinAt(3)->getValue());
}

TEST(ORComponent, ComputeTxT) {
  nts::IComponent	*ORI = new OR();
  nts::IComponent	*TRUE = new True();

  ORI->SetLink(1, *TRUE, 1);
  ORI->SetLink(2, *TRUE, 1);
  ASSERT_EQ((int) nts::Tristate::TRUE, ORI->Compute(3));
}

TEST(ORComponent, ComputeFxF) {
  nts::IComponent	*ORI = new OR();
  nts::IComponent	*FALSE = new False();

  ORI->SetLink(1, *FALSE, 1);
  ORI->SetLink(2, *FALSE, 1);
  ASSERT_EQ((int) nts::Tristate::FALSE, ORI->Compute(3));
}

TEST(ORComponent, ComputeTxF) {
  nts::IComponent	*ORI = new OR();
  nts::IComponent	*TRUE = new True();
  nts::IComponent	*FALSE = new False();

  ORI->SetLink(1, *TRUE, 1);
  ORI->SetLink(2, *FALSE, 1);

  ASSERT_EQ((int) nts::Tristate::TRUE, ORI->Compute(3));
}

TEST(ORComponent, ComputeUxT) {
  nts::IComponent	*ORI = new OR();
  nts::IComponent	*Input = new INPUT();
  nts::IComponent	*TRUE = new True();

  ORI->SetLink(1, *Input, 1);
  ORI->SetLink(2, *TRUE, 1);

  ASSERT_EQ((int) nts::Tristate::TRUE, ORI->Compute(3));
}

TEST(ORComponent, ComputeUxF) {
  nts::IComponent	*ORI = new OR();
  nts::IComponent	*Input = new INPUT();
  nts::IComponent	*FALSE = new False();

  ORI->SetLink(1, *Input, 1);
  ORI->SetLink(2, *FALSE, 1);

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, ORI->Compute(3));
}

TEST(ORComponent, ComputeUxU) {
  nts::IComponent	*ORI = new OR();
  nts::IComponent	*Input1 = new INPUT();
  nts::IComponent	*Input2 = new INPUT();

  ORI->SetLink(1, *Input1, 1);
  ORI->SetLink(2, *Input2, 1);

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, ORI->Compute(3));
}