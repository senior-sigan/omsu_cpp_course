#pragma once

#include <string>

// НЕ редактируйте этот файл.

namespace fasm {

class IOperation;  // forward declaration

class Parser {
 public:
  explicit Parser(const std::string& code);
  bool ParseLine();
  IOperation* GetCurrentOperation() const;
};
}  // namespace fasm
