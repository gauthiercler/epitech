#include	<gtest/gtest.h>
#include	<sources/classes/components/gates/AND.hpp>
#include <sources/classes/components/True.hpp>
#include <sources/classes/components/False.hpp>
#include	<sources/classes/components/INPUT.hpp>
#include	<sources/classes/Pin.hpp>

TEST(PIN_Component, Constructor) {
  nts::IComponent	*Component = new True();

  Pin			*Pin1 = new Pin();
  Pin			*Pin2 = new Pin(Pin::PinType::INPUT);
  Pin			*Pin3 = new Pin(Pin::PinType::OUTPUT);

  Pin			*Pin4 = new Pin(Pin::PinType::INPUT, NULL, 1);
  Pin			*Pin5 = new Pin(Pin::PinType::OUTPUT, Component, 1234);

  ASSERT_EQ((int) Pin::PinType::INPUT, Pin1->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, Pin1->getValue());
  ASSERT_EQ(NULL, Pin1->getMotherboard());
  ASSERT_EQ(0, Pin1->getMBnumber());

  ASSERT_EQ((int) Pin::PinType::INPUT, Pin2->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, Pin2->getValue());
  ASSERT_EQ(NULL, Pin2->getMotherboard());
  ASSERT_EQ(0, Pin2->getMBnumber());

  ASSERT_EQ((int) Pin::PinType::OUTPUT, Pin3->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, Pin3->getValue());
  ASSERT_EQ(NULL, Pin3->getMotherboard());
  ASSERT_EQ(0, Pin3->getMBnumber());

  ASSERT_EQ((int) Pin::PinType::INPUT, Pin4->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, Pin4->getValue());
  ASSERT_EQ(NULL, Pin4->getMotherboard());
  ASSERT_EQ(1, Pin4->getMBnumber());

  ASSERT_EQ((int) Pin::PinType::OUTPUT, Pin5->getType());
  ASSERT_EQ((int) nts::Tristate::UNDEFINED, Pin5->getValue());
  ASSERT_EQ(Component, Pin5->getMotherboard());
  ASSERT_EQ(1234, Pin5->getMBnumber());
}

TEST(PIN_Component, SetValue) {
  Pin			*PinV = new Pin();

  ASSERT_EQ((int) nts::Tristate::UNDEFINED, PinV->getValue());
  PinV->setValue(nts::Tristate::TRUE);
  ASSERT_EQ((int) nts::Tristate::TRUE, PinV->getValue());
  PinV->setValue(nts::Tristate::FALSE);
  ASSERT_EQ((int) nts::Tristate::FALSE, PinV->getValue());
}

TEST(PIN_Component, SetLinkState) {
  Pin			*PinS = new Pin();

  ASSERT_FALSE(PinS->isLinked());
  PinS->setLinkState(true);
  ASSERT_TRUE(PinS->isLinked());
  PinS->setLinkState(false);
  ASSERT_FALSE(PinS->isLinked());
}

TEST(PIN_Component, SetLockState) {
  Pin			*PinS = new Pin();

  ASSERT_FALSE(PinS->isLocked());
  PinS->setLockState(true);
  ASSERT_TRUE(PinS->isLocked());
  PinS->setLockState(false);
  ASSERT_FALSE(PinS->isLocked());
}