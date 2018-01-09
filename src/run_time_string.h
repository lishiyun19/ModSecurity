/*
 * ModSecurity, http://www.modsecurity.org/
 * Copyright (c) 2015 Trustwave Holdings, Inc. (http://www.trustwave.com/)
 *
 * You may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * If any of the files related to licensing are missing or if you have any
 * other questions related to licensing please contact Trustwave Holdings, Inc.
 * directly using the email address security@modsecurity.org.
 *
 */


#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#include "modsecurity/modsecurity.h"
#include "modsecurity/transaction.h"
#include "src/variables/variable.h"

#ifndef SRC_RUN_TIME_STRING_H_
#define SRC_RUN_TIME_STRING_H_

namespace modsecurity {

class RunTimeElementHolder {
 public:
    RunTimeElementHolder() :
        m_string("") {
            m_var.reset(NULL);
        };
    std::unique_ptr<modsecurity::Variables::Variable> m_var;
    std::string m_string;
};

class RunTimeString {
 public:
    RunTimeString() {
    };
    void appendText(std::string &text);
    void appendVar(std::unique_ptr<modsecurity::Variables::Variable> var);
    std::string evaluate(Transaction *t);

 protected:
    std::list<std::unique_ptr<RunTimeElementHolder>> m_elements;
};


}  // namespace modsecurity



#endif  // SRC_RUN_TIME_STRING_H_
