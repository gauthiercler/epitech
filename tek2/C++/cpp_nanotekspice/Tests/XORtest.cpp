#include	<gtest/gtest.h>
#include	<sources/classes/components/gates/XOR.hpp>
#include <sources/classes/components/True.hpp>
#include <sources/classes/components/False.hpp>
#include	<sources/classes/components/INPUT.hpp>

TEST(XOR_Component, Constructor) {
  nts::IComponent	*XORI = new XOR();
  nts::AComponent	*XORA = static_cast<nts::AComponent *>(XORI);

  ASSERT_EQ("XOR", XORA->getName());
  ASSERT_EQ(3, XORA->getNbPins());

  ASSERT_EQ((int) Pin::PinType::INPUT, XORA->getPinAt(1)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, XORA->getPinAt(1)->getValue());

  ASSERT_EQ((int) Pin::PinType::INPUT, XORA->getPinAt(2)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, XORA->getPinAt(2)->getValue());

  ASSERT_EQ((int) Pin::PinType::OUTPUT, XORA->getPinAt(3)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, XORA->getPinAt(3)->getValue());
}

TEST(XOR_Component, ComputeTxT) {
  nts::IComponent	*XORI = new XOR();
  nts::IComponent	*TRUE = new True();

  XORI->SetLink(1, *TRUE, 1);
  XORI->SetLink(2, *TRUE, 1);
  ASSERT_EQ((int) nts::Tristate::FALSE, XORI->Compute(3));
}

TEST(XOR_Component, ComputeFxF) {
  nts::IComponent	*XORI = new XOR();
  nts::IComponent	*FALSE = new False();

  XORI->SetLink(1, *FALSE, 1);
  XORI->SetLink(2, *FALSE, 1);
  ASSERT_EQ((int) nts::Tristate::FALSE, XORI->Compute(3));
}

TEST(XOR_Component, ComputeTxF) {
  nts::IComponent	*XORI = new XOR();
  nts::IComponent	*TRUE = new True();
  nts::IComponent	*FALSE = new False();

  XORI->SetLink(1, *TRUE, 1);
  XORI->SetLink(2, *FALSE, 1);

  ASSERT_EQ((int) nts::Tristate::TRUE, XORI->Compute(3));
}

TEST(XOR_Component, ComputeUxT) {
  nts::IComponent	*XORI = new XOR();
  nts::IComponent	*Input = new INPUT();
  nts::IComponent	*TRUE = new True();

  XORI->SetLink(1, *Input, 1);
  XORI->SetLink(2, *TRUE, 1);

  ASSERT_EQ((int) nts::Tristate::TRUE, XORI->Compute(3));
}

TEST(XOR_Component, ComputeUxF) {
  nts::IComponent	*XORI = new XOR();
  nts::IComponent	*Input = new INPUT();
  nts::IComponent	*FALSE = new False();

  XORI->SetLink(1, *Input, 1);
  XORI->SetLink(2, *FALSE, 1);

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, XORI->Compute(3));
}

TEST(XOR_Component, ComputeUxU) {
  nts::IComponent	*XORI = new XOR();
  nts::IComponent	*Input1 = new INPUT();
  nts::IComponent	*Input2 = new INPUT();

  XORI->SetLink(1, *Input1, 1);
  XORI->SetLink(2, *Input2, 1);

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, XORI->Compute(3));
}
