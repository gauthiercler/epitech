#include	<gtest/gtest.h>
#include	<sources/interfaces/IComponent.hpp>
#include	<sources/classes/components/C4013.hpp>
#include <sources/classes/components/True.hpp>
#include <sources/classes/components/False.hpp>
#include <sources/classes/components/CLOCK.hpp>

TEST(C4013_Component, Constructor)
{
  nts::IComponent	*C4013I = new C4013();
  nts::AComponent	*C4013A = static_cast<nts::AComponent *>(C4013I);

  ASSERT_EQ("Dual D-Type Flip-Flop", C4013A->getName());
  ASSERT_EQ(14, C4013A->getNbPins());

  ASSERT_EQ((int) Pin::PinType::OUTPUT, C4013A->getPinAt(1)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4013A->getPinAt(1)->getValue());
  ASSERT_EQ((int) Pin::PinType::OUTPUT, C4013A->getPinAt(2)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4013A->getPinAt(2)->getValue());
  ASSERT_EQ((int) Pin::PinType::INPUT, C4013A->getPinAt(3)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4013A->getPinAt(3)->getValue());
  ASSERT_EQ((int) Pin::PinType::INPUT, C4013A->getPinAt(4)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4013A->getPinAt(4)->getValue());
  ASSERT_EQ((int) Pin::PinType::INPUT, C4013A->getPinAt(5)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4013A->getPinAt(5)->getValue());
  ASSERT_EQ((int) Pin::PinType::INPUT, C4013A->getPinAt(6)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4013A->getPinAt(6)->getValue());

  ASSERT_EQ((int) Pin::PinType::IGNORED, C4013A->getPinAt(7)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4013A->getPinAt(7)->getValue());

  ASSERT_EQ((int) Pin::PinType::INPUT, C4013A->getPinAt(8)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4013A->getPinAt(8)->getValue());
  ASSERT_EQ((int) Pin::PinType::INPUT, C4013A->getPinAt(9)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4013A->getPinAt(9)->getValue());
  ASSERT_EQ((int) Pin::PinType::INPUT, C4013A->getPinAt(10)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4013A->getPinAt(10)->getValue());
  ASSERT_EQ((int) Pin::PinType::INPUT, C4013A->getPinAt(11)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4013A->getPinAt(11)->getValue());
  ASSERT_EQ((int) Pin::PinType::OUTPUT, C4013A->getPinAt(12)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4013A->getPinAt(12)->getValue());
  ASSERT_EQ((int) Pin::PinType::OUTPUT, C4013A->getPinAt(13)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4013A->getPinAt(13)->getValue());

  ASSERT_EQ((int) Pin::PinType::IGNORED, C4013A->getPinAt(14)->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, C4013A->getPinAt(14)->getValue());
}

TEST(C4013_Component, ClockUpxDataFalse)
{
  nts::IComponent	*DFlipFlop = new C4013();
  nts::IComponent	*Clock = new CLOCK();
  nts::IComponent	*TRUE = new True();
  nts::IComponent	*FALSE = new False();

  DFlipFlop->SetLink(3, *Clock, 1);
  DFlipFlop->SetLink(4, *FALSE, 1);
  DFlipFlop->SetLink(5, *FALSE, 1);
  DFlipFlop->SetLink(6, *FALSE, 1);

  dynamic_cast<nts::AComponent *>(Clock)->getPinAt(1)->setValue(nts::Tristate::FALSE);

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, DFlipFlop->Compute(1));
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, DFlipFlop->Compute(2));

  dynamic_cast<nts::AComponent *>(Clock)->getPinAt(1)->setValue(nts::Tristate::TRUE);
  ASSERT_EQ((int) nts::Tristate::FALSE, DFlipFlop->Compute(1));
  ASSERT_EQ((int) nts::Tristate::TRUE, DFlipFlop->Compute(2));
}

TEST(C4013_Component, ClockTrueDataTrue)
{
  nts::IComponent	*DFlipFlop = new C4013();
  nts::IComponent	*TRUE = new True();
  nts::IComponent	*FALSE = new False();

  DFlipFlop->SetLink(3, *TRUE, 1);
  DFlipFlop->SetLink(4, *FALSE, 1);
  DFlipFlop->SetLink(5, *TRUE, 1);
  DFlipFlop->SetLink(6, *FALSE, 1);

  ASSERT_EQ((int) nts::Tristate::TRUE, DFlipFlop->Compute(1));
  ASSERT_EQ((int) nts::Tristate::FALSE, DFlipFlop->Compute(2));
}

TEST(C4013_Component, ClockFalseNoSetReset)
{
  nts::IComponent	*DFlipFlop = new C4013();
  nts::IComponent	*TRUE = new True();
  nts::IComponent	*FALSE = new False();

  DFlipFlop->SetLink(3, *FALSE, 1);
  DFlipFlop->SetLink(4, *FALSE, 1);
  DFlipFlop->SetLink(5, *FALSE, 1);
  DFlipFlop->SetLink(6, *FALSE, 1);

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, DFlipFlop->Compute(1));
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, DFlipFlop->Compute(2));
}

TEST(C4013_Component, ClockTrueNoSetReset)
{
  nts::IComponent	*DFlipFlop = new C4013();
  nts::IComponent	*TRUE = new True();
  nts::IComponent	*FALSE = new False();

  DFlipFlop->SetLink(3, *TRUE, 1);
  DFlipFlop->SetLink(4, *FALSE, 1);
  DFlipFlop->SetLink(5, *FALSE, 1);
  DFlipFlop->SetLink(6, *FALSE, 1);

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, DFlipFlop->Compute(1));
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, DFlipFlop->Compute(2));
}

TEST(C4013_Component, ResetTruexSetFalse)
{
  nts::IComponent	*DFlipFlop = new C4013();
  nts::IComponent	*TRUE = new True();
  nts::IComponent	*FALSE = new False();

  DFlipFlop->SetLink(3, *FALSE, 1);
  DFlipFlop->SetLink(4, *TRUE, 1);
  DFlipFlop->SetLink(5, *FALSE, 1);
  DFlipFlop->SetLink(6, *FALSE, 1);

  ASSERT_EQ((int) nts::Tristate::FALSE, DFlipFlop->Compute(1));
  ASSERT_EQ((int) nts::Tristate::TRUE, DFlipFlop->Compute(2));
}

TEST(C4013_Component, ResetFalsexSetTrue)
{
  nts::IComponent	*DFlipFlop = new C4013();
  nts::IComponent	*TRUE = new True();
  nts::IComponent	*FALSE = new False();

  DFlipFlop->SetLink(3, *FALSE, 1);
  DFlipFlop->SetLink(4, *FALSE, 1);
  DFlipFlop->SetLink(5, *FALSE, 1);
  DFlipFlop->SetLink(6, *TRUE, 1);

  ASSERT_EQ((int) nts::Tristate::TRUE, DFlipFlop->Compute(1));
  ASSERT_EQ((int) nts::Tristate::FALSE, DFlipFlop->Compute(2));
}

TEST(C4013_Component, ResetFalsexSetFalse)
{
  nts::IComponent	*DFlipFlop = new C4013();
  nts::IComponent	*TRUE = new True();
  nts::IComponent	*FALSE = new False();

  DFlipFlop->SetLink(3, *FALSE, 1);
  DFlipFlop->SetLink(4, *TRUE, 1);
  DFlipFlop->SetLink(5, *FALSE, 1);
  DFlipFlop->SetLink(6, *TRUE, 1);

  ASSERT_EQ((int) nts::Tristate::TRUE, DFlipFlop->Compute(1));
  ASSERT_EQ((int) nts::Tristate::TRUE, DFlipFlop->Compute(2));
}