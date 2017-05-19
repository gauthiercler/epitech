#include	<gtest/gtest.h>
#include	<sources/classes/components/gates/AND.hpp>
#include <sources/classes/components/True.hpp>
#include <sources/classes/components/False.hpp>
#include	<sources/classes/components/INPUT.hpp>

TEST(AND_Component, Constructor) {
  nts::IComponent	*ANDI = new AND();
  nts::AComponent	*ANDA = static_cast<nts::AComponent *>(ANDI);

  ASSERT_EQ("AND", ANDA->getName());
  ASSERT_EQ(3, ANDA->getNbPins());

  ASSERT_EQ((int) Pin::PinType::INPUT, ANDA->getPinAt(1)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, ANDA->getPinAt(1)->getValue());

  ASSERT_EQ((int) Pin::PinType::INPUT, ANDA->getPinAt(2)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, ANDA->getPinAt(2)->getValue());

  ASSERT_EQ((int) Pin::PinType::OUTPUT, ANDA->getPinAt(3)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, ANDA->getPinAt(3)->getValue());
}

TEST(AND_Component, ComputeTxT) {
  nts::IComponent	*ANDI = new AND();
  nts::IComponent	*TRUE = new True();

  ANDI->SetLink(1, *TRUE, 1);
  ANDI->SetLink(2, *TRUE, 1);
  ASSERT_EQ((int) nts::Tristate::TRUE, ANDI->Compute(3));
}

TEST(AND_Component, ComputeFxF) {
  nts::IComponent	*ANDI = new AND();
  nts::IComponent	*FALSE = new False();

  ANDI->SetLink(1, *FALSE, 1);
  ANDI->SetLink(2, *FALSE, 1);
  ASSERT_EQ((int) nts::Tristate::FALSE, ANDI->Compute(3));
}

TEST(AND_Component, ComputeTxF) {
  nts::IComponent	*ANDI = new AND();
  nts::IComponent	*TRUE = new True();
  nts::IComponent	*FALSE = new False();

  ANDI->SetLink(1, *TRUE, 1);
  ANDI->SetLink(2, *FALSE, 1);

  ASSERT_EQ((int) nts::Tristate::FALSE, ANDI->Compute(3));
}

TEST(AND_Component, ComputeUxT) {
  nts::IComponent	*ANDI = new AND();
  nts::IComponent	*Input = new INPUT();
  nts::IComponent	*TRUE = new True();

  ANDI->SetLink(1, *Input, 1);
  ANDI->SetLink(2, *TRUE, 1);

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, ANDI->Compute(3));
}

TEST(AND_Component, ComputeUxF) {
  nts::IComponent	*ANDI = new AND();
  nts::IComponent	*Input = new INPUT();
  nts::IComponent	*FALSE = new False();

  ANDI->SetLink(1, *Input, 1);
  ANDI->SetLink(2, *FALSE, 1);

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, ANDI->Compute(3));
}

TEST(AND_Component, ComputeUxU) {
  nts::IComponent	*ANDI = new AND();
  nts::IComponent	*Input1 = new INPUT();
  nts::IComponent	*Input2 = new INPUT();

  ANDI->SetLink(1, *Input1, 1);
  ANDI->SetLink(2, *Input2, 1);

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, ANDI->Compute(3));
}