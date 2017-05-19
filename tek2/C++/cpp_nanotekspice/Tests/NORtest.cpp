#include	<gtest/gtest.h>
#include	<sources/classes/components/gates/NOR.hpp>
#include <sources/classes/components/True.hpp>
#include <sources/classes/components/False.hpp>
#include	<sources/classes/components/INPUT.hpp>

TEST(NOR_Component, Constructor) {
  nts::IComponent	*NORI = new NOR();
  nts::AComponent	*NORA = static_cast<nts::AComponent *>(NORI);

  ASSERT_EQ("NOR", NORA->getName());
  ASSERT_EQ(3, NORA->getNbPins());

  ASSERT_EQ((int) Pin::PinType::INPUT, NORA->getPinAt(1)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, NORA->getPinAt(1)->getValue());

  ASSERT_EQ((int) Pin::PinType::INPUT, NORA->getPinAt(2)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, NORA->getPinAt(2)->getValue());

  ASSERT_EQ((int) Pin::PinType::OUTPUT, NORA->getPinAt(3)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, NORA->getPinAt(3)->getValue());
}

TEST(NOR_Component, ComputeTxT) {
  nts::IComponent	*NORI = new NOR();
  nts::IComponent	*TRUE = new True();

  NORI->SetLink(1, *TRUE, 1);
  NORI->SetLink(2, *TRUE, 1);
  ASSERT_EQ((int) nts::Tristate::FALSE, NORI->Compute(3));
}

TEST(NOR_Component, ComputeFxF) {
  nts::IComponent	*NORI = new NOR();
  nts::IComponent	*FALSE = new False();

  NORI->SetLink(1, *FALSE, 1);
  NORI->SetLink(2, *FALSE, 1);
  ASSERT_EQ((int) nts::Tristate::TRUE, NORI->Compute(3));
}

TEST(NOR_Component, ComputeTxF) {
  nts::IComponent	*NORI = new NOR();
  nts::IComponent	*TRUE = new True();
  nts::IComponent	*FALSE = new False();

  NORI->SetLink(1, *TRUE, 1);
  NORI->SetLink(2, *FALSE, 1);

  ASSERT_EQ((int) nts::Tristate::FALSE, NORI->Compute(3));
}

TEST(NOR_Component, ComputeUxT) {
  nts::IComponent	*NORI = new NOR();
  nts::IComponent	*Input = new INPUT();
  nts::IComponent	*TRUE = new True();

  NORI->SetLink(1, *Input, 1);
  NORI->SetLink(2, *TRUE, 1);

  ASSERT_EQ((int) nts::Tristate::FALSE, NORI->Compute(3));
}

TEST(NOR_Component, ComputeUxF) {
  nts::IComponent	*NORI = new NOR();
  nts::IComponent	*Input = new INPUT();
  nts::IComponent	*FALSE = new False();

  NORI->SetLink(1, *Input, 1);
  NORI->SetLink(2, *FALSE, 1);

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, NORI->Compute(3));
}

TEST(NOR_Component, ComputeUxU) {
  nts::IComponent	*NORI = new NOR();
  nts::IComponent	*Input1 = new INPUT();
  nts::IComponent	*Input2 = new INPUT();

  NORI->SetLink(1, *Input1, 1);
  NORI->SetLink(2, *Input2, 1);

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, NORI->Compute(3));
}