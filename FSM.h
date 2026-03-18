#pragma once

class UState;
class UTransition;

#include <iostream>

class UFSM
{
public:
	UFSM();
	~UFSM();

	UState* States;
	UTransition* Transitions;

	void Process(int CurrentState, std::string CurrentCondition);

	std::string GetStateName(int InID);
};

