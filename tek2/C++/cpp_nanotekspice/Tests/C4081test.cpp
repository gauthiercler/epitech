#include	<gtest/gtest.h>
#include	<sources/classes/components/C4081.hpp>
#include <sources/classes/components/True.hpp>
#include <sources/classes/components/False.hpp>
#include	<sources/classes/components/INPUT.hpp>

TEST(C4081_Component, Constructor) {
  nts::IComponent	*C4081I = new C4081();
  nts::AComponent	*C4081A = static_cast<nts::AComponent *>(C4081I);

  ASSERT_EQ("QUAD 2 INPUT AND GATE", C4081A->getName());
  ASSERT_EQ(14, C4081A->getNbPins());

  ASSERT_EQ((int) Pin::PinType::INPUT, C4081A->getPinAt(1)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081A->getPinAt(1)->getValue());
  ASSERT_EQ((int) Pin::PinType::INPUT, C4081A->getPinAt(2)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081A->getPinAt(2)->getValue());
  ASSERT_EQ((int) Pin::PinType::OUTPUT, C4081A->getPinAt(3)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081A->getPinAt(3)->getValue());

  ASSERT_EQ((int) Pin::PinType::OUTPUT, C4081A->getPinAt(4)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081A->getPinAt(4)->getValue());
  ASSERT_EQ((int) Pin::PinType::INPUT, C4081A->getPinAt(5)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081A->getPinAt(5)->getValue());
  ASSERT_EQ((int) Pin::PinType::INPUT, C4081A->getPinAt(6)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081A->getPinAt(6)->getValue());

  ASSERT_EQ((int) Pin::PinType::IGNORED, C4081A->getPinAt(7)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081A->getPinAt(7)->getValue());

  ASSERT_EQ((int) Pin::PinType::INPUT, C4081A->getPinAt(8)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081A->getPinAt(8)->getValue());
  ASSERT_EQ((int) Pin::PinType::INPUT, C4081A->getPinAt(9)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081A->getPinAt(9)->getValue());
  ASSERT_EQ((int) Pin::PinType::OUTPUT, C4081A->getPinAt(10)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081A->getPinAt(10)->getValue());

  ASSERT_EQ((int) Pin::PinType::OUTPUT, C4081A->getPinAt(11)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081A->getPinAt(11)->getValue());
  ASSERT_EQ((int) Pin::PinType::INPUT, C4081A->getPinAt(12)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081A->getPinAt(12)->getValue());
  ASSERT_EQ((int) Pin::PinType::INPUT, C4081A->getPinAt(13)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081A->getPinAt(13)->getValue());

  ASSERT_EQ((int) Pin::PinType::IGNORED, C4081A->getPinAt(14)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081A->getPinAt(14)->getValue());
}

TEST(C4081_Component, ComputeTxT) {
  nts::IComponent	*C4081I = new C4081();
  nts::IComponent	*TRUE = new True();

  C4081I->SetLink(1, *TRUE, 1);
  C4081I->SetLink(2, *TRUE, 1);
  C4081I->SetLink(5, *TRUE, 1);
  C4081I->SetLink(6, *TRUE, 1);
  C4081I->SetLink(8, *TRUE, 1);
  C4081I->SetLink(9, *TRUE, 1);
  C4081I->SetLink(12, *TRUE, 1);
  C4081I->SetLink(13, *TRUE, 1);

  ASSERT_EQ((int) nts::Tristate::TRUE, C4081I->Compute(3));
  ASSERT_EQ((int) nts::Tristate::TRUE, C4081I->Compute(4));
  ASSERT_EQ((int) nts::Tristate::TRUE, C4081I->Compute(10));
  ASSERT_EQ((int) nts::Tristate::TRUE, C4081I->Compute(11));
}

TEST(C4081_Component, ComputeFxF) {
  nts::IComponent	*C4081I = new C4081();
  nts::IComponent	*FALSE = new False();

  C4081I->SetLink(1, *FALSE, 1);
  C4081I->SetLink(2, *FALSE, 1);
  C4081I->SetLink(5, *FALSE, 1);
  C4081I->SetLink(6, *FALSE, 1);
  C4081I->SetLink(8, *FALSE, 1);
  C4081I->SetLink(9, *FALSE, 1);
  C4081I->SetLink(12, *FALSE, 1);
  C4081I->SetLink(13, *FALSE, 1);

  ASSERT_EQ((int) nts::Tristate::FALSE, C4081I->Compute(3));
  ASSERT_EQ((int) nts::Tristate::FALSE, C4081I->Compute(4));
  ASSERT_EQ((int) nts::Tristate::FALSE, C4081I->Compute(10));
  ASSERT_EQ((int) nts::Tristate::FALSE, C4081I->Compute(11));
}

TEST(C4081_Component, ComputeTxF) {
  nts::IComponent	*C4081I = new C4081();
  nts::IComponent	*TRUE = new True();
  nts::IComponent	*FALSE = new False();

  C4081I->SetLink(1, *TRUE, 1);
  C4081I->SetLink(2, *FALSE, 1);
  C4081I->SetLink(5, *FALSE, 1);
  C4081I->SetLink(6, *TRUE, 1);
  C4081I->SetLink(8, *TRUE, 1);
  C4081I->SetLink(9, *FALSE, 1);
  C4081I->SetLink(12, *FALSE, 1);
  C4081I->SetLink(13, *TRUE, 1);

  ASSERT_EQ((int) nts::Tristate::FALSE, C4081I->Compute(3));
  ASSERT_EQ((int) nts::Tristate::FALSE, C4081I->Compute(4));
  ASSERT_EQ((int) nts::Tristate::FALSE, C4081I->Compute(10));
  ASSERT_EQ((int) nts::Tristate::FALSE, C4081I->Compute(11));
}

TEST(C4081_Component, ComputeUxT) {
  nts::IComponent	*C4081I = new C4081();
  nts::IComponent	*Input = new INPUT();
  nts::IComponent	*TRUE = new True();

  C4081I->SetLink(1, *TRUE, 1);
  C4081I->SetLink(2, *Input, 1);
  C4081I->SetLink(5, *Input, 1);
  C4081I->SetLink(6, *TRUE, 1);

  C4081I->SetLink(8, *TRUE, 1);
  C4081I->SetLink(13, *TRUE, 1);

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081I->Compute(3));
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081I->Compute(4));
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081I->Compute(10));
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081I->Compute(11));
}

TEST(C4081_Component, ComputeUxF) {
  nts::IComponent	*C4081I = new C4081();
  nts::IComponent	*Input = new INPUT();
  nts::IComponent	*FALSE = new False();

  C4081I->SetLink(1, *FALSE, 1);
  C4081I->SetLink(2, *Input, 1);
  C4081I->SetLink(5, *Input, 1);
  C4081I->SetLink(6, *FALSE, 1);

  C4081I->SetLink(8, *FALSE, 1);
  C4081I->SetLink(13, *FALSE, 1);

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081I->Compute(3));
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081I->Compute(4));
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081I->Compute(10));
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081I->Compute(11));
}

TEST(C4081_Component, ComputeUxU) {
  nts::IComponent	*C4081I = new C4081();
  nts::IComponent	*Input1 = new INPUT();
  nts::IComponent	*Input2 = new INPUT();

  C4081I->SetLink(1, *Input1, 1);
  C4081I->SetLink(2, *Input2, 1);
  C4081I->SetLink(5, *Input2, 1);
  C4081I->SetLink(6, *Input1, 1);

  C4081I->SetLink(8, *Input1, 1);
  C4081I->SetLink(13, *Input2, 1);

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081I->Compute(3));
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081I->Compute(4));
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081I->Compute(10));
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4081I->Compute(11));
}