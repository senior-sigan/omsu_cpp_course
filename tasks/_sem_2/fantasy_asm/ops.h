#pragma once

namespace fasm {

class Memory;        // forward declaration
class MutableValue;  // forward declaration
class Value;         // forward declaration

class IOperation {
 public:
  virtual void Apply(Memory& mem) = 0;
  virtual ~IOperation() = default;
};

class AddOp : public IOperation {
  MutableValue* const op1_;
  const Value* const op2_;

 public:
  AddOp(MutableValue* op1, const Value* op2);
  void Apply(Memory& mem) override;
};

class CmpOp : public IOperation {
  const Value* const op1_;
  const Value* const op2_;

 public:
  CmpOp(const Value* op1, const Value* op2);
  void Apply(Memory& mem) override;
};

class JeOp : public IOperation {
  const Value* const op1_;

 public:
  explicit JeOp(Value* const op1);
  void Apply(Memory& mem) override;
};

class JgOp : public IOperation {
  const Value* const op1_;

 public:
  explicit JgOp(Value* const op1);
  void Apply(Memory& mem) override;
};

class JlOp : public IOperation {
  const Value* const op1_;

 public:
  explicit JlOp(Value* const op1);
  void Apply(Memory& mem) override;
};

class JmpOp : public IOperation {
  const Value* const op1_;

 public:
  explicit JmpOp(Value* const op1);
  void Apply(Memory& mem) override;
};

class MovOp : public IOperation {
  MutableValue* const op1_;
  const Value* const op2_;

 public:
  MovOp(MutableValue* op1, const Value* op2);
  void Apply(Memory& mem) override;
};

class MulOp : public IOperation {
  MutableValue* const op1_;
  const Value* const op2_;

 public:
  MulOp(MutableValue* op1, const Value* op2);
  void Apply(Memory& mem) override;
};

class PopOp : public IOperation {
  MutableValue* const op1_;

 public:
  explicit PopOp(MutableValue* const op1);
  void Apply(Memory& mem) override;
};

class PushOp : public IOperation {
  const Value* const op1_;

 public:
  explicit PushOp(Value* const op1);
  void Apply(Memory& mem) override;
};
}  // namespace fasm
