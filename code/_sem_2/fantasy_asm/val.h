#pragma once

#include "reg.h"

// НЕ редактируйте этот файл.

namespace fasm {

class Memory;  // forward declaration

class Value {
 public:
  virtual int Get(const Memory& mem) const = 0;
  virtual ~Value() = default;
};

class MutableValue : public Value {
 public:
  virtual void Set(Memory& mem, int value) = 0;
  ~MutableValue() override = default;
};

class ValueLiteral : public Value {
  const int value_;

 public:
  explicit ValueLiteral(int value);
  int Get(const Memory& mem) const override;
};

class ValueRegister : public MutableValue {
  const Register reg_;

 public:
  explicit ValueRegister(Register reg);
  void Set(Memory& mem, int value) override;
  int Get(const Memory& mem) const override;
};
}  // namespace fasm
