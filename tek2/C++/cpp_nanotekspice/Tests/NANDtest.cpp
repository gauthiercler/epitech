#include	<gtest/gtest.h>
#include	<sources/classes/components/gates/NAND.hpp>
#include <sources/classes/components/True.hpp>
#include	<sources/classes/components/False.hpp>
#include	<sources/classes/components/INPUT.hpp>

TEST(NAND_Component, Constructor) {
  nts::IComponent	*NANDI = new NAND();
  nts::AComponent	*NANDA = static_cast<nts::AComponent *>(NANDI);

  ASSERT_EQ("NAND", NANDA->getName());
  ASSERT_EQ(3, NANDA->getNbPins());

  ASSERT_EQ((int) Pin::PinType::INPUT, NANDA->getPinAt(1)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, NANDA->getPinAt(1)->getValue());

  ASSERT_EQ((int) Pin::PinType::INPUT, NANDA->getPinAt(2)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, NANDA->getPinAt(2)->getValue());

  ASSERT_EQ((int) Pin::PinType::OUTPUT, NANDA->getPinAt(3)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, NANDA->getPinAt(3)->getValue());
}

TEST(NAND_Component, ComputeTxT) {
  nts::IComponent	*NANDI = new NAND();
  nts::IComponent	*TRUE = new True();

  NANDI->SetLink(1, *TRUE, 1);
  NANDI->SetLink(2, *TRUE, 1);
  ASSERT_EQ((int) nts::Tristate::FALSE, NANDI->Compute(3));
}

TEST(NAND_Component, ComputeFxF) {
  nts::IComponent	*NANDI = new NAND();
  nts::IComponent	*FALSE = new False();

  NANDI->SetLink(1, *FALSE, 1);
  NANDI->SetLink(2, *FALSE, 1);
  ASSERT_EQ((int) nts::Tristate::TRUE, NANDI->Compute(3));
}

TEST(NAND_Component, ComputeTxF) {
  nts::IComponent	*NANDI  = new NAND();
  nts::IComponent	*TRUE = new True();
  nts::IComponent	*FALSE = new False();

  NANDI->SetLink(1, *TRUE, 1);
  NANDI->SetLink(2, *FALSE, 1);

  ASSERT_EQ((int) nts::Tristate::TRUE, NANDI->Compute(3));
}

TEST(NAND_Component, ComputeUxT) {
  nts::IComponent	*NANDI  = new NAND();
  nts::IComponent	*Input = new INPUT();
  nts::IComponent	*TRUE = new True();

  NANDI->SetLink(1, *Input, 1);
  NANDI->SetLink(2, *TRUE, 1);

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, NANDI->Compute(3));
}

TEST(NAND_Component, ComputeUxF) {
  nts::IComponent	*NANDI  = new NAND();
  nts::IComponent	*Input = new INPUT();
  nts::IComponent	*FALSE = new False();

  NANDI->SetLink(1, *Input, 1);
  NANDI->SetLink(2, *FALSE, 1);

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, NANDI->Compute(3));
}

TEST(NAND_Component, ComputeUxU) {
  nts::IComponent	*NANDI  = new NAND();
  nts::IComponent	*Input1 = new INPUT();
  nts::IComponent	*Input2 = new INPUT();

  NANDI->SetLink(1, *Input1, 1);
  NANDI->SetLink(2, *Input2, 1);

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, NANDI->Compute(3));
}