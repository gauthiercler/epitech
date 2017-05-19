#include	<gtest/gtest.h>
#include	<sources/classes/components/gates/NOT.hpp>
#include <sources/classes/components/True.hpp>
#include <sources/classes/components/False.hpp>
#include	<sources/classes/components/INPUT.hpp>

TEST(NOT_Component, Constructor) {
  nts::IComponent	*NOTI = new NOT();
  nts::AComponent	*NOTA = static_cast<nts::AComponent *>(NOTI);

  ASSERT_EQ("NOT", NOTA->getName());
  ASSERT_EQ(2, NOTA->getNbPins());

  ASSERT_EQ((int) Pin::PinType::INPUT, NOTA->getPinAt(1)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, NOTA->getPinAt(1)->getValue());

  ASSERT_EQ((int) Pin::PinType::OUTPUT, NOTA->getPinAt(2)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, NOTA->getPinAt(2)->getValue());
}

TEST(NOT_Component, ComputeTxT) {
  nts::IComponent	*NOTI = new NOT();
  nts::IComponent	*TRUE = new True();

  NOTI->SetLink(1, *TRUE, 1);
  ASSERT_EQ((int) nts::Tristate::FALSE, NOTI->Compute(2));
}

TEST(NOT_Component, ComputeFxF) {
  nts::IComponent	*NOTI = new NOT();
  nts::IComponent	*FALSE = new False();

  NOTI->SetLink(1, *FALSE, 1);
  ASSERT_EQ((int) nts::Tristate::TRUE, NOTI->Compute(2));
}
