//===-- OCamlLanguage.h ------------------------------------------*- C++
//-*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef liblldb_OCamlLanguage_h_
#define liblldb_OCamlLanguage_h_

// C Includes
// C++ Includes
#include <vector>

// Other libraries and framework includes
#include "llvm/ADT/StringRef.h"

// Project includes
#include "lldb/Target/Language.h"
#include "lldb/Utility/ConstString.h"
#include "lldb/lldb-private.h"

namespace lldb_private {

class OCamlLanguage : public Language {
public:
  lldb::LanguageType GetLanguageType() const override {
    return lldb::eLanguageTypeOCaml;
  }

  static void Initialize();

  static void Terminate();

  static lldb_private::Language *CreateInstance(lldb::LanguageType language);

  static lldb_private::ConstString GetPluginNameStatic();

  ConstString GetPluginName() override;

  uint32_t GetPluginVersion() override;

  bool IsNilReference(ValueObject &valobj) override;
};

} // namespace lldb_private

#endif // liblldb_OCamlLanguage_h_
