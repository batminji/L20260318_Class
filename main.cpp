#include <iostream>
#include <string>

enum EState
{
	배회,
	추격,
	공격,
	죽음
};

enum ECondition
{
	적발견,
	적놓침,
	사정거리접근,
	사정거리이탈,
	HP없음
};

class ATransition
{
public:
	EState State;

	ATransition()
	{
		State = 배회;
	}

	void Transit(ECondition Condition)
	{
		if (Condition == 적발견)
		{
			State = 추격;
		}
		else if (Condition == 적놓침)
		{
			State = 배회;
		}
		else if (Condition == 사정거리접근)
		{
			State = 공격;
		}
		else if (Condition == 사정거리이탈)
		{
			State = 추격;
		}
		else if (Condition == HP없음)
		{
			State = 죽음;
		}
	}

	void PrintState()
	{
		if (State == 배회)
		{
			std::cout << "배회 중이다..." << std::endl;
		}
		else if (State == 추격)
		{
			std::cout << "적을 발견했다! 추격 중이다!" << std::endl;
		}
		else if (State == 공격)
		{
			std::cout << "공격 중이다!" << std::endl;
		}
		else if (State == 죽음)
		{
			std::cout << "죽었다..." << std::endl;
		}
	}
};

class AMonsterFSM
{
public:
	ATransition Transition;

	void Transit(ECondition Condition)
	{
		Transition.Transit(Condition);
	}

	void PrintMonterState()
	{
		Transition.PrintState();
	}
};

int main()
{
	AMonsterFSM MonsterFSM;

	MonsterFSM.Transit(적놓침);
	MonsterFSM.PrintMonterState();

	MonsterFSM.Transit(적발견);
	MonsterFSM.PrintMonterState();

	MonsterFSM.Transit(사정거리접근);
	MonsterFSM.PrintMonterState();

	MonsterFSM.Transit(HP없음);
	MonsterFSM.PrintMonterState();
}