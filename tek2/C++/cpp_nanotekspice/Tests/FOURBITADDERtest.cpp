#include	<gtest/gtest.h>
#include	<sources/classes/components/C4008.hpp>
#include	<sources/classes/components/True.hpp>
#include	<sources/classes/components/False.hpp>

TEST(C4008_Component, SevenxFifteen)
{
  nts::IComponent	*Chipset4BitAdder = new C4008();
  nts::IComponent	*True1 = new True();
  nts::IComponent	*True2 = new True();
  nts::IComponent	*True3 = new True();
  nts::IComponent	*False1 = new False();
  nts::IComponent	*True4 = new True();
  nts::IComponent	*True5 = new True();
  nts::IComponent	*True6 = new True();
  nts::IComponent	*True7 = new True();
  nts::IComponent	*False2 = new False();
  // A = 7
  // 7 => 0111 | A4, A3, A2, A1
  Chipset4BitAdder->SetLink(7, *True1, 1);
  Chipset4BitAdder->SetLink(5, *True2, 1);
  Chipset4BitAdder->SetLink(3, *True3, 1);
  Chipset4BitAdder->SetLink(1, *False1, 1);

  // B = 15
  // 15 => 1111 | B4, B3, B2, B1
  Chipset4BitAdder->SetLink(6, *True4, 1);
  Chipset4BitAdder->SetLink(4, *True5, 1);
  Chipset4BitAdder->SetLink(2, *True6, 1);
  Chipset4BitAdder->SetLink(15, *True7, 1);

  Chipset4BitAdder->SetLink(9, *False2, 1);

  ASSERT_EQ((int) nts::Tristate::FALSE, Chipset4BitAdder->Compute(10));
  ASSERT_EQ((int) nts::Tristate::TRUE, Chipset4BitAdder->Compute(11));
  ASSERT_EQ((int) nts::Tristate::TRUE, Chipset4BitAdder->Compute(12));
  ASSERT_EQ((int) nts::Tristate::FALSE, Chipset4BitAdder->Compute(13));
  ASSERT_EQ((int) nts::Tristate::TRUE, Chipset4BitAdder->Compute(14));
}