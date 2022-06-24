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
    IdleState(/* args */);
    IdleState(const IdleState& other);
	IdleState& operator=(const IdleState& other);
public:
    void enter( ShowerStateMachine* shower );
    void run( ShowerStateMachine* shower );
    void exit( ShowerStateMachine* shower );
    static ShowerState& getInstance();
    ~IdleState();
};

class SelectUser : public ShowerState
{
private:
    SelectUser(/* args */);
    SelectUser(const SelectUser& other);
	SelectUser& operator=(const SelectUser& other);
public:
    void enter( ShowerStateMachine* shower );
    void run( ShowerStateMachine* shower );
    void exit( ShowerStateMachine* shower );
    static ShowerState& getInstance();
    ~SelectUser();
};

class BeginShower : public ShowerState
{
private:
    BeginShower(/* args */);
    BeginShower(const BeginShower& other);
	BeginShower& operator=(const BeginShower& other);
public:
    void enter( ShowerStateMachine* shower );
    void run( ShowerStateMachine* shower );
    void exit( ShowerStateMachine* shower );
    static ShowerState& getInstance();
    ~BeginShower();
};

class ManualControl : public ShowerState
{
private:
    ManualControl(/* args */);
    ManualControl(const ManualControl& other);
	ManualControl& operator=(const ManualControl& other);
public:
    void enter( ShowerStateMachine* shower );
    void run( ShowerStateMachine* shower );
    void exit( ShowerStateMachine* shower );
    static ShowerState& getInstance();
    ~ManualControl();
};

class EndShower : public ShowerState
{
private:
    EndShower(/* args */);
    EndShower(const EndShower& other);
	EndShower& operator=(const EndShower& other);
public:
    void enter( ShowerStateMachine* shower );
    void run( ShowerStateMachine* shower );
    void exit( ShowerStateMachine* shower );
    static ShowerState& getInstance();
    ~EndShower();
};

class SyncApp : public ShowerState
{
private:
    SyncApp(/* args */);
    SyncApp(const SyncApp& other);
	SyncApp& operator=(const SyncApp& other);
public:
    void enter( ShowerStateMachine* shower );
    void run( ShowerStateMachine* shower );
    void exit( ShowerStateMachine* shower );
    static ShowerState& getInstance();
    ~SyncApp();
};

class NULLState : public ShowerState
{
private:
    NULLState(/* args */);
    NULLState(const NULLState& other);
	NULLState& operator=(const NULLState& other);
public:
    void enter( ShowerStateMachine* shower );
    void run( ShowerStateMachine* shower );
    void exit( ShowerStateMachine* shower );
    static ShowerState& getInstance();
    ~NULLState();
};


#endif /* SHOWER_STATE_HPP_ */