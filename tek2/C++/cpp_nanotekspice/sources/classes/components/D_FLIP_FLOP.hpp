#ifndef CPP_NANOTEKSPICE_FLIP_FLOP_HPP
#define CPP_NANOTEKSPICE_FLIP_FLOP_HPP


#include <sources/classes/AComponent.hpp>

class D_FLIP_FLOP : public nts::AComponent{

private:
  nts::Tristate		ClockSave;
public:
  D_FLIP_FLOP(const std::string &name = "D_FLIP_FLOP");
  virtual ~D_FLIP_FLOP();
  virtual nts::Tristate 	Compute(size_t pin_num_this = 1);
};


#endif //CPP_NANOTEKSPICE_FLIP_FLOP_HPP
