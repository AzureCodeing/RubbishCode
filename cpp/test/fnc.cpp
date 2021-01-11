#include <iostream>
#include <functional>
#include <unordered_map>
#include <string>
#include <unistd.h>

//状态机器的实现

using namespace std;

/*----------状态机架构----------*/
typedef int eState;
eState NullState = -1;

class FSM;

class State
{
public:
    virtual void OnStateEnter() = 0;
    virtual void OnStateTick() = 0;
    virtual void OnStateExit() = 0;

    State(FSM* _fsm):fsm(_fsm) {}
protected:
    FSM *fsm  = nullptr;
};


class FSM
{
private:
    unordered_map<eState, State*> all_status;
    eState curState = -1;
public:
    //注册新状态
    bool Register(eState e, State* pState){
        all_status[e] = pState;
        return true;
    }

    //状态转移函数
    bool Trans(eState newState){
        all_status[curState]->OnStateExit();
        all_status[newState]->OnStateEnter();

        curState = newState;
        return true;
    }

    //设置初始状态
    void SetInitState(eState s){
        curState = s;
    }

    //定时调用
    void Tick(){
        all_status[curState]->OnStateTick();
    }
};
/*-------------使用例子开始-----------------*/
const int State_Idle = 1;
const int State_Attack = 2;
const int State_GoHome = 3;

//实际应用，具有三个状态都继承State然后分别实现

class StateIdle: public State
{
public:
    StateIdle(FSM *fsm) : State(fsm) {}
    int test_counter = 0;
    void OnStateEnter() {
        cout << "---Idle Enter---" << endl;
        test_counter = 0;
    }    
    void OnStateTick(){
        cout << "Idle Tick" << endl;
        //模拟一个定时状态的转移
        test_counter++;
        if(test_counter == 5){
            fsm->Trans(State_Attack);
        }
    }
    void OnStateExit() {cout << "----StateExit----" << endl;}
};

class StateAttack : public State
{
public:
    int test_counter = 0;
    StateAttack(FSM* fsm) : State(fsm) {}
    void OnStateEnter() {
        cout << "---AttackEnter---" << endl;
        test_counter = 0;
        }
    void OnStateExit() {cout << "---AttackExit---" << endl;}
    void OnStateTick() {
    cout << "StateAttack" << endl;
    test_counter++;
    if(test_counter == 5) fsm->Trans(State_GoHome);
    }
};

class StateGoHome : public State
{
public:
    int test_counter = 0;
    StateGoHome(FSM* fsm) : State(fsm) {}
    void OnStateEnter() {
        cout << "---GoHomeEnter---" << endl;
        test_counter = 0;
        }
    void OnStateExit() {cout << "---GoHomeExit---" << endl;}
    void OnStateTick() {
        cout << "StateGoHome" << endl;
        test_counter++;
        if(test_counter==5) fsm->Trans(State_Idle);
        }
};

int main(int argc, char *argv[])
{
    FSM* fsm = new FSM();
    State* stateIdel = new StateIdle(fsm);
    State* stateAttack = new StateAttack(fsm);
    State* stateGoHome = new StateGoHome(fsm);
    fsm->Register(State_Idle, stateIdel);
    fsm->Register(State_Attack, stateAttack);
    fsm->Register(State_GoHome, stateGoHome);

    fsm->SetInitState(State_Idle);
    while(true){
        fsm->Tick();
        sleep(1);
    }
    return 0;
}