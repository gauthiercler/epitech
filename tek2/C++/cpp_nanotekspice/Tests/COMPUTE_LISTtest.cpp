#include	<gtest/gtest.h>
#include <sources/classes/components/C4081.hpp>
#include	"classes/components/OUTPUT.hpp"
#include	"classes/components/INPUT.hpp"
#include	"classes/Pin.hpp"

TEST(IComponent, Compute)
{
  nts::IComponent	*Input = new INPUT();
  nts::IComponent	*Output = new OUTPUT();

  static_cast<nts::AComponent *>(Input)->getPinAt(1)->setValue(nts::Tristate::TRUE);

  Output->SetLink(1, *Input, 1);
  ASSERT_EQ((int) nts::Tristate::TRUE, Output->Compute(1));
}

TEST(COMPUTE_LIST_Component, SingleT) {
  nts::IComponent	*Input = new INPUT();
  nts::IComponent	*Output = new OUTPUT();

  static_cast<nts::AComponent *>(Input)->getPinAt(1)->setValue(nts::Tristate::TRUE);

  Output->SetLink(1, *Input, 1);
  ASSERT_EQ((int) nts::Tristate::TRUE, Output->Compute(1));
}

TEST(COMPUTE_LIST_Component, SingleF) {
  nts::IComponent	*Input = new INPUT();
  nts::IComponent	*Output = new OUTPUT();

  static_cast<nts::AComponent *>(Input)->getPinAt(1)->setValue(nts::Tristate::FALSE);

  Output->SetLink(1, *Input, 1);
  ASSERT_EQ((int) nts::Tristate::FALSE, Output->Compute(1));
}

TEST(COMPUTE_LIST_Component, SingleU) {
  nts::IComponent	*Input = new INPUT();
  nts::IComponent	*Output = new OUTPUT();

  Output->SetLink(1, *Input, 1);
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, Output->Compute(1));
}

TEST(COMPUTE_LIST_Component, TxU) {
  nts::IComponent	*Input1 = new INPUT();
  nts::IComponent	*Input2 = new INPUT();
  nts::IComponent	*Input3 = new INPUT();
  nts::IComponent	*Input4 = new INPUT();
  nts::IComponent	*Output1 = new OUTPUT();
  nts::IComponent	*Output2 = new OUTPUT();

  Output1->SetLink(1, *Input1, 1);
  Output1->SetLink(1, *Input2, 1);

  Output2->SetLink(1, *Input3, 1);
  Output2->SetLink(1, *Input4, 1);

  static_cast<nts::AComponent *>(Input1)->getPinAt(1)->setValue(nts::Tristate::TRUE);
  static_cast<nts::AComponent *>(Input4)->getPinAt(1)->setValue(nts::Tristate::TRUE);
  ASSERT_EQ((int) nts::Tristate::TRUE, Output1->Compute(1));
  ASSERT_EQ((int) nts::Tristate::TRUE, Output2->Compute(1));
}

TEST(COMPUTE_LIST_Component, TxF) {
  nts::IComponent	*Input1 = new INPUT();
  nts::IComponent	*Input2 = new INPUT();
  nts::IComponent	*Input3 = new INPUT();
  nts::IComponent	*Input4 = new INPUT();
  nts::IComponent	*Output1 = new OUTPUT();
  nts::IComponent	*Output2 = new OUTPUT();

  Output1->SetLink(1, *Input1, 1);
  Output1->SetLink(1, *Input2, 1);

  Output2->SetLink(1, *Input3, 1);
  Output2->SetLink(1, *Input4, 1);

  static_cast<nts::AComponent *>(Input1)->getPinAt(1)->setValue(nts::Tristate::TRUE);
  static_cast<nts::AComponent *>(Input2)->getPinAt(1)->setValue(nts::Tristate::FALSE);
  static_cast<nts::AComponent *>(Input3)->getPinAt(1)->setValue(nts::Tristate::FALSE);
  static_cast<nts::AComponent *>(Input4)->getPinAt(1)->setValue(nts::Tristate::TRUE);
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, Output1->Compute(1));
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, Output2->Compute(1));
}

TEST(COMPUTE_LIST_Component, TxT) {
  nts::IComponent	*Input1 = new INPUT();
  nts::IComponent	*Input2 = new INPUT();
  nts::IComponent	*Output = new OUTPUT();

  Output->SetLink(1, *Input1, 1);
  Output->SetLink(1, *Input2, 1);

  static_cast<nts::AComponent *>(Input1)->getPinAt(1)->setValue(nts::Tristate::TRUE);
  static_cast<nts::AComponent *>(Input2)->getPinAt(1)->setValue(nts::Tristate::TRUE);
  ASSERT_EQ((int) nts::Tristate::TRUE, Output->Compute(1));
}

TEST(COMPUTE_LIST_Component, FxU) {
  nts::IComponent	*Input1 = new INPUT();
  nts::IComponent	*Input2 = new INPUT();
  nts::IComponent	*Input3 = new INPUT();
  nts::IComponent	*Input4 = new INPUT();
  nts::IComponent	*Output1 = new OUTPUT();
  nts::IComponent	*Output2 = new OUTPUT();

  Output1->SetLink(1, *Input1, 1);
  Output1->SetLink(1, *Input2, 1);

  Output2->SetLink(1, *Input3, 1);
  Output2->SetLink(1, *Input4, 1);

  static_cast<nts::AComponent *>(Input1)->getPinAt(1)->setValue(nts::Tristate::FALSE);
  static_cast<nts::AComponent *>(Input4)->getPinAt(1)->setValue(nts::Tristate::FALSE);
  ASSERT_EQ((int) nts::Tristate::FALSE, Output1->Compute(1));
  ASSERT_EQ((int) nts::Tristate::FALSE, Output2->Compute(1));
}

TEST(COMPUTE_LIST_Component, FxF) {
  nts::IComponent	*Input1 = new INPUT();
  nts::IComponent	*Input2 = new INPUT();
  nts::IComponent	*Output = new OUTPUT();

  Output->SetLink(1, *Input1, 1);
  Output->SetLink(1, *Input2, 1);

  static_cast<nts::AComponent *>(Input1)->getPinAt(1)->setValue(nts::Tristate::FALSE);
  static_cast<nts::AComponent *>(Input2)->getPinAt(1)->setValue(nts::Tristate::FALSE);
  ASSERT_EQ((int) nts::Tristate::FALSE, Output->Compute(1));
}

TEST(COMPUTE_LIST_Component, MultipleTxU) {
  nts::IComponent	*Input1 = new INPUT();
  nts::IComponent	*Input2 = new INPUT();
  nts::IComponent	*Input3 = new INPUT();
  nts::IComponent	*Input4 = new INPUT();
  nts::IComponent	*Output = new OUTPUT();

  Output->SetLink(1, *Input1, 1);
  Output->SetLink(1, *Input2, 1);
  Output->SetLink(1, *Input3, 1);
  Output->SetLink(1, *Input4, 1);

  static_cast<nts::AComponent *>(Input1)->getPinAt(1)->setValue(nts::Tristate::UNDEFINED);
  static_cast<nts::AComponent *>(Input2)->getPinAt(1)->setValue(nts::Tristate::TRUE);
  static_cast<nts::AComponent *>(Input3)->getPinAt(1)->setValue(nts::Tristate::TRUE);
  static_cast<nts::AComponent *>(Input4)->getPinAt(1)->setValue(nts::Tristate::UNDEFINED);

  ASSERT_EQ((int) nts::Tristate::TRUE, Output->Compute(1));
}

TEST(COMPUTE_LIST_Component, MultipleFxU) {
  nts::IComponent	*Input1 = new INPUT();
  nts::IComponent	*Input2 = new INPUT();
  nts::IComponent	*Input3 = new INPUT();
  nts::IComponent	*Input4 = new INPUT();
  nts::IComponent	*Output = new OUTPUT();

  Output->SetLink(1, *Input1, 1);
  Output->SetLink(1, *Input2, 1);
  Output->SetLink(1, *Input3, 1);
  Output->SetLink(1, *Input4, 1);

  static_cast<nts::AComponent *>(Input1)->getPinAt(1)->setValue(nts::Tristate::FALSE);
  static_cast<nts::AComponent *>(Input2)->getPinAt(1)->setValue(nts::Tristate::UNDEFINED);
  static_cast<nts::AComponent *>(Input3)->getPinAt(1)->setValue(nts::Tristate::UNDEFINED);
  static_cast<nts::AComponent *>(Input4)->getPinAt(1)->setValue(nts::Tristate::FALSE);

  ASSERT_EQ((int) nts::Tristate::FALSE, Output->Compute(1));
}

TEST(COMPUTE_LIST_Component, MultipleUxU) {
  nts::IComponent	*Input1 = new INPUT();
  nts::IComponent	*Input2 = new INPUT();
  nts::IComponent	*Input3 = new INPUT();
  nts::IComponent	*Input4 = new INPUT();
  nts::IComponent	*Output = new OUTPUT();

  Output->SetLink(1, *Input1, 1);
  Output->SetLink(1, *Input2, 1);
  Output->SetLink(1, *Input3, 1);
  Output->SetLink(1, *Input4, 1);

  static_cast<nts::AComponent *>(Input1)->getPinAt(1)->setValue(nts::Tristate::UNDEFINED);
  static_cast<nts::AComponent *>(Input2)->getPinAt(1)->setValue(nts::Tristate::UNDEFINED);
  static_cast<nts::AComponent *>(Input3)->getPinAt(1)->setValue(nts::Tristate::UNDEFINED);
  static_cast<nts::AComponent *>(Input4)->getPinAt(1)->setValue(nts::Tristate::UNDEFINED);

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, Output->Compute(1));
}

TEST(COMPUTE_LIST_Component, LinkedInputTxT) {
  nts::IComponent	*Input1 = new INPUT();
  nts::IComponent	*Input2 = new INPUT();
  nts::IComponent	*Output = new OUTPUT();

  Input1->SetLink(1, *Input2, 1);
  Output->SetLink(1, *Input1, 1);

  static_cast<nts::AComponent *>(Input1)->getPinAt(1)->setValue(nts::Tristate::TRUE);
  static_cast<nts::AComponent *>(Input2)->getPinAt(1)->setValue(nts::Tristate::TRUE);

  ASSERT_EQ((int) nts::Tristate::TRUE, Output->Compute(1));
}

TEST(COMPUTE_LIST_Component, LinkedInputFxF) {
  nts::IComponent	*Input1 = new INPUT();
  nts::IComponent	*Input2 = new INPUT();
  nts::IComponent	*Output = new OUTPUT();

  Input1->SetLink(1, *Input2, 1);
  Output->SetLink(1, *Input1, 1);

  static_cast<nts::AComponent *>(Input1)->getPinAt(1)->setValue(nts::Tristate::FALSE);
  static_cast<nts::AComponent *>(Input2)->getPinAt(1)->setValue(nts::Tristate::FALSE);

  ASSERT_EQ((int) nts::Tristate::FALSE, Output->Compute(1));
}

TEST(COMPUTE_LIST_Component, LinkedInputTxF) {
  nts::IComponent	*Input1 = new INPUT();
  nts::IComponent	*Input2 = new INPUT();
  nts::IComponent	*Output = new OUTPUT();

  Input1->SetLink(1, *Input2, 1);
  Output->SetLink(1, *Input1, 1);

  static_cast<nts::AComponent *>(Input1)->getPinAt(1)->setValue(nts::Tristate::TRUE);
  static_cast<nts::AComponent *>(Input2)->getPinAt(1)->setValue(nts::Tristate::FALSE);

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, Output->Compute(1));
}

TEST(COMPUTE_LIST_Component, Input5xAND) {
  nts::IComponent	*ChipsetAND = new C4081();
  nts::IComponent	*Input1 = new INPUT();
  nts::IComponent	*Input2 = new INPUT();
  nts::IComponent	*Input3 = new INPUT();
  nts::IComponent	*Input4 = new INPUT();
  nts::IComponent	*Input5 = new INPUT();

  static_cast<nts::AComponent *>(Input1)->getPinAt(1)->setValue(nts::Tristate::TRUE);
  static_cast<nts::AComponent *>(Input2)->getPinAt(1)->setValue(nts::Tristate::TRUE);
  static_cast<nts::AComponent *>(Input3)->getPinAt(1)->setValue(nts::Tristate::TRUE);
  static_cast<nts::AComponent *>(Input4)->getPinAt(1)->setValue(nts::Tristate::TRUE);
  static_cast<nts::AComponent *>(Input5)->getPinAt(1)->setValue(nts::Tristate::TRUE);

  ChipsetAND->SetLink(1, *Input1, 1);
  ChipsetAND->SetLink(1, *Input2, 1);
  ChipsetAND->SetLink(1, *Input3, 1);
  ChipsetAND->SetLink(1, *Input4, 1);
  ChipsetAND->SetLink(1, *Input5, 1);
  ChipsetAND->SetLink(2, *Input2, 1);

  ASSERT_EQ((int) nts::Tristate::TRUE, ChipsetAND->Compute(3));
}