#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <cstdint>

std::vector<std::vector<std::string>> g_firstTuringMachine = {
    /* State x */   /*When 0        When 1*/
    /* State 0 */   {"0 0 R",       "1 1 L",},
    /* State 1 */   {"10 1 R",      "1 1 L",},
    /* State 10 */  {"1010 0 R",    "11 0 R",},
    /* State 11 */  {"100 0 R",     "11 1 R",},
    /* State 100 */ {"100 0 R",     "101 0 R",},
    /* State 101 */ {"111 0 L",     "110 1 L",},
    /* State 110 */ {"110 0 L",     "1 1 L",},
    /* State 111 */ {"111 0 L",     "1000 1 L",},
    /* State 1000 */{"1001 0 L",    "1000 1 L",},
    /* State 1001 */{"10 0 L",      "1 1 L",},
    /* State 1010 */{"0 0 STOP",    "1010 1 R",},
};

std::string g_initTape = "01111101111111110";

std::deque<char> ConvertStringToTape(const std::string& str) {
    std::deque<char> tape;
    for (char ch : str) {
        tape.push_back(ch);
    }
    return tape;
}

struct stateAction{
    enum class Action {
        LEFT,
        RIGHT,
        STOP
    };

    int nextState;
    char writeValue;
    Action action;
};

typedef std::vector<std::array<stateAction, 2>> TuringLogicDefinition;

TuringLogicDefinition ConvertTuringMachine(const std::vector<std::vector<std::string>>& tm) {
    TuringLogicDefinition convertedTM(tm.size());

    for (size_t i = 0; i < tm.size(); ++i) {
        std::array<stateAction, 2> stateActions;
        for (size_t j = 0; j < 2; ++j) {
            const std::string& instruction = tm[i][j];
            size_t pos1 = instruction.find(' ');
            size_t pos2 = instruction.find(' ', pos1 + 1);

            int nextState = std::stoi(instruction.substr(0, pos1));
            char writeValue = instruction[pos1 + 1];
            std::string actionStr = instruction.substr(pos2 + 1);

            stateAction::Action action;
            if (actionStr == "L") {
                action = stateAction::Action::LEFT;
            } else if (actionStr == "R") {
                action = stateAction::Action::RIGHT;
            } else if (actionStr == "STOP") {
                action = stateAction::Action::STOP;
            } else {
                throw std::invalid_argument("Invalid action: " + actionStr);
            }

            convertedTM[i][j] = {nextState, writeValue, action};
        }
    }

    return convertedTM;
}

class TuringMachine {
    TuringLogicDefinition mInnerLogic;
    std::deque<char> mTape;
    size_t mHeadPosition;
    int mCurrentState;
public:
    TuringMachine(const TuringLogicDefinition& tm, const std::deque<char>& tape)
        : mInnerLogic(tm), mTape(tape), mHeadPosition(0), mCurrentState(0) {}
    
    enum class ExecutionResult {
        CONTINUE,
        HALT,
        ERROR,
    };

    ExecutionResult Step() {
        if (mCurrentState < 0 || mCurrentState >= mInnerLogic.size()) {
            return ExecutionResult::ERROR;
        }

        char currentValue = mTape[mHeadPosition];
        int valueIndex = (currentValue == '0') ? 0 : 1;
        const stateAction& action = mInnerLogic[mCurrentState][valueIndex];
        mTape[mHeadPosition] = action.writeValue;
        mCurrentState = action.nextState;

        return ExecutionResult::CONTINUE;
    }
};

int main() {
    std::cout << "Turing Machine - The Emperor's New Mind" << std::endl;
    
    auto tape = ConvertStringToTape(g_initTape);
    auto turingMachine = ConvertTuringMachine(g_firstTuringMachine);



    return 0;
}
