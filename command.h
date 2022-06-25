#pragma once
class Command
{
public:
	virtual ~Command() = default;
	Command() = default;
	Command(const Command&) = delete;
	Command& operator=(const Command&) = delete;
	Command& operator=(Command&&) = delete;
	Command(Command&&) = delete;
	virtual void Execute() = 0;
};