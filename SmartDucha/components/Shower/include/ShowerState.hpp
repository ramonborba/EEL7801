/**
 * @file ShowerState.hpp
 * 
 * @brief Shower states header file for the state machine
 * 
 * @author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * @version 0.1
 * 
 * @date 24-06-2022
 */

#ifndef SHOWER_STATE_HPP_
#define SHOWER_STATE_HPP_

#include "Shower.hpp"

class ShowerStateMachine;

class ShowerState
{
public:
    virtual void enter( ShowerStateMachine* ) = 0;
    virtual void run( ShowerStateMachine* ) = 0;
    virtual void exit( ShowerStateMachine* ) = 0;
    virtual ~ShowerState() {};
};


class IdleState : public ShowerState
{
private:
    IdleState(/* args */) = default;
    IdleState(const IdleState& other) = default;
	IdleState& operator=(const IdleState& other);
public:
    void enter( ShowerStateMachine* shower );
    void run( ShowerStateMachine* shower );
    void exit( ShowerStateMachine* shower );
    static ShowerState& getInstance();
    ~IdleState() = default;
};

class SelectUser : public ShowerState
{
private:
    SelectUser(/* args */) = default;
    SelectUser(const SelectUser& other) = default;
	SelectUser& operator=(const SelectUser& other);
public:
    void enter( ShowerStateMachine* shower );
    void run( ShowerStateMachine* shower );
    void exit( ShowerStateMachine* shower );
    static ShowerState& getInstance();
    ~SelectUser() = default;
};

class BeginShower : public ShowerState
{
private:
    BeginShower(/* args */) = default;
    BeginShower(const BeginShower& other) = default;
	BeginShower& operator=(const BeginShower& other);
public:
    void enter( ShowerStateMachine* shower );
    void run( ShowerStateMachine* shower );
    void exit( ShowerStateMachine* shower );
    static ShowerState& getInstance();
    ~BeginShower() = default;
};

class ManualControl : public ShowerState
{
private:
    ManualControl(/* args */) = default;
    ManualControl(const ManualControl& other) = default;
	ManualControl& operator=(const ManualControl& other);
public:
    void enter( ShowerStateMachine* shower );
    void run( ShowerStateMachine* shower );
    void exit( ShowerStateMachine* shower );
    static ShowerState& getInstance();
    ~ManualControl() = default;
};

class EndShower : public ShowerState
{
private:
    EndShower(/* args */) = default;
    EndShower(const EndShower& other) = default;
	EndShower& operator=(const EndShower& other);
public:
    void enter( ShowerStateMachine* shower );
    void run( ShowerStateMachine* shower );
    void exit( ShowerStateMachine* shower );
    static ShowerState& getInstance();
    ~EndShower() = default;
};

class SyncApp : public ShowerState
{
private:
    SyncApp(/* args */) = default;
    SyncApp(const SyncApp& other) = default;
	SyncApp& operator=(const SyncApp& other);
public:
    void enter( ShowerStateMachine* shower );
    void run( ShowerStateMachine* shower );
    void exit( ShowerStateMachine* shower );
    static ShowerState& getInstance();
    ~SyncApp() = default;
};

class NULLState : public ShowerState
{
private:
    NULLState(/* args */) = default;
    NULLState(const NULLState& other) = default;
	NULLState& operator=(const NULLState& other);
public:
    void enter( ShowerStateMachine* shower );
    void run( ShowerStateMachine* shower );
    void exit( ShowerStateMachine* shower );
    static ShowerState& getInstance();
    ~NULLState() = default;
};


#endif /* SHOWER_STATE_HPP_ */